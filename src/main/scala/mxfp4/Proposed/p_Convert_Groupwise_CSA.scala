package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

// ------------- IO ------------------
class MXFP4_CONVERT_GROUPWISE_CSA_BLOCK_IO(depthBitWidth: Int, mantissaWidth: Int, vecSize: Int) extends Bundle {
  val depth    = Input(UInt(depthBitWidth.W))
  val in       = Input(Vec(vecSize, SInt((mantissaWidth + 1).W))) // 2's complement sum (sign + magnitude)
  val nan      = Input(Vec(4, UInt(1.W)))                        // NaN flags per group
  val exponent = Input(Vec(4, SInt(10.W)))                       // shared exponents per group
  val out      = Output(Vec(vecSize, new FP32))                  // IEEE-754 single (sign/exp/frac)
}

class p_Convert_Groupwise_CSA(val d: Int, val extra: Int) extends Module {
  require(d >= 0 && d <= 8, s"d out of range: $d")
  require(extra >= 0,        s"extra must be >= 0")

  // -------- Params --------
  private val mantissaWidth = 8 + d + extra   // internal accumulator magnitude width (no sign)
  private val vecSize       = 256 >> d        // d=6→4, 7→2, 8→1
  private val FRACW         = 6 + extra       // location of 2^0 (integer LSB) in the internal fixed-point

  val io = IO(new MXFP4_CONVERT_GROUPWISE_BLOCK_IO(4, mantissaWidth, vecSize))

  private val enable_depth = io.depth === d.U

  // -------- Utils --------

  // jammed right shift with internal cap; returns (x >> min(shamt,W-1), sticky_or)
  // - If shamt >= W, shifted := 0, sticky := OR(x)
  private def shiftRightJamCapped(x: UInt, shamt: UInt): (UInt, Bool) = {
    val W      = x.getWidth
    val geW    = shamt >= W.U
    val shCap  = Mux(geW, (W-1).U, shamt)
    val shifted= Mux(geW, 0.U(W.W), (x >> shCap).asUInt)
    val mask   = (1.U(W.W) << shCap) - 1.U
    val sticky = Mux(geW, x.orR, (x & mask).orR)
    (shifted, sticky)
  }

  // power-of-two padded tree LZC; counts leading zeros from MSB side of x
  private def lzcTreeSafe(x: UInt, outW: Int): UInt = {
    val w     = x.getWidth
    require(w >= 1, "lzcTreeSafe: x width must be >= 1")
    val pPow  = 1 << log2Ceil(w)        // power-of-two >= w
    val padW  = pPow - w
    val padded= if (padW == 0) x else Cat(x, 0.U(padW.W))  // pad zeros on LSB side
    val levels= log2Ceil(pPow)
    val cntW  = log2Ceil(pPow + 1)      // internal counter width (safe)

    val levelSig = Array.ofDim[UInt](levels + 1)
    val levelCnt = Array.ofDim[UInt](levels + 1)
    levelSig(0) = padded
    levelCnt(0) = 0.U(cntW.W)

    for (s <- 0 until levels) {
      val width = pPow >> s
      val half  = width >> 1
      val hi    = levelSig(s)(width - 1, half)
      val lo    = levelSig(s)(half - 1, 0)
      val hiNZ  = hi.orR
      levelSig(s + 1) = Mux(hiNZ, hi, lo)
      levelCnt(s + 1) = Mux(hiNZ, levelCnt(s), levelCnt(s) + half.U(cntW.W))
    }

    val cntPadded = levelCnt(levels) // 0..pPow
    (Mux(cntPadded > w.U(cntW.W), w.U(cntW.W), cntPadded))(outW - 1, 0)
  }

  // lane -> group index LUT (depth-fixed)
  private val groupIdxLut: Vec[UInt] = vecSize match {
    case 4 => VecInit(0.U(2.W), 1.U(2.W), 2.U(2.W), 3.U(2.W))
    case 2 => VecInit(0.U(2.W), 1.U(2.W))
    case 1 => VecInit(0.U(2.W))
    case _ => throw new IllegalArgumentException(s"vecSize=$vecSize invalid")
  }

  for (i <- 0 until vecSize) {
    val inS   = io.in(i)

    // 0) Sign / absolute value (2's complement) with MIN_NEG saturation and sticky
    val isNeg        = inS < 0.S
    val inAbsFull    = Mux(isNeg, (-inS).asUInt, inS.asUInt)          // width = mantissaWidth+1
    val minNeg       = inAbsFull(mantissaWidth)                       // |x| == 2^mantissaWidth ?
    val inMag        = Mux(minNeg,
      ((BigInt(1) << mantissaWidth) - 1).U(mantissaWidth.W),          // saturate to (2^W-1)
      inAbsFull(mantissaWidth - 1, 0)
    )
    val stickyFromAbs = minNeg                                         // we lost 1 LSB of info by saturating

    val inSign  = isNeg.asUInt
    val gid     = groupIdxLut(i)
    val grpExp  = io.exponent(gid)
    val nanFlag = io.nan(gid)

    // Operand isolation for heavy path
    val isZero      = inMag === 0.U
    val activeHeavy = enable_depth && (nanFlag =/= 1.U) && !isZero
    val inMagEff    = Mux(activeHeavy, inMag, 0.U(mantissaWidth.W))

    // 1) LZC
    val peW = log2Ceil(mantissaWidth + 1)
    val pe  = lzcTreeSafe(inMagEff, peW) // UInt(peW)

    // 2) Align shift amount (no dead branches: all caps done by construction)
    val shiftW    = (log2Ceil(mantissaWidth + d + 3) max 3)
    val shiftBase = (d + 1).S(shiftW.W)
    val peExt     = pe.pad(shiftW)
    val shift_amt = shiftBase - peExt.asSInt // SInt(shiftW)

    // 3) Exponent math
    val real_exp   = (grpExp.asSInt +& shift_amt).asSInt
    val biased_exp = real_exp + 131.S

    // 4) First alignment (jammed right if shift_amt>=0, capped)
    val shMax            = (mantissaWidth - 1).U
    val alignedMag       = Wire(UInt(mantissaWidth.W))
    val stickyFromAlign  = Wire(Bool())

    when (shift_amt >= 0.S) {
      val shU   = shift_amt.asUInt
      val shCap = Mux(shU > shMax, shMax, shU)
      val (y, s) = shiftRightJamCapped(inMagEff, shCap)
      alignedMag      := y
      stickyFromAlign := s
    } .otherwise {
      val shL   = (-shift_amt).asUInt
      val shCap = Mux(shL > shMax, shMax, shL)
      alignedMag      := (inMagEff << shCap)(mantissaWidth - 1, 0)
      stickyFromAlign := false.B
    }

    // 5) Move FRACW to 24 (right: jam; left: lossless) + propagate stickyFromAbs
    val move = FRACW - 24
    val (afterMove, stickyMove0) =
      if (move >= 0) {
        val (y, s) = shiftRightJamCapped(alignedMag, move.U)
        (y, stickyFromAlign || s)
      } else {
        ((alignedMag << (-move)).asUInt(mantissaWidth - 1, 0), stickyFromAlign)
      }
    val stickyMove = stickyMove0 || stickyFromAbs

    // 6) RNE for normal candidate (keep up to 24+guard = 25 bits window)
    val availW      = (afterMove.getWidth min 25)           // compile-time Int
    val sliceDyn    = if (availW > 0) afterMove(availW - 1, 0) else 0.U(1.W)
    val hasGuard    = availW >= 1
    val keepW       = (availW - 1) max 0
    val keepDynW    = (keepW max 1)
    val guardBit    = if (hasGuard) sliceDyn(0).asBool else false.B
    val keepDyn     = if (keepW > 0) sliceDyn(availW - 1, 1) else 0.U(keepDynW.W)
    val lsbDynB     = if (keepW > 0) keepDyn(0).asBool else false.B
    val roundUp     = guardBit && (stickyMove || lsbDynB)

    val roundedDyn  = keepDyn +& roundUp.asUInt
    val carryDyn    = roundedDyn(roundedDyn.getWidth - 1).asBool

    // Normalize to 24 bits
    def toWidth24(x: UInt): UInt = {
      val w = x.getWidth
      if (w >= 24) x(23, 0) else Cat(0.U((24 - w).W), x)
    }
    val mant24NoCarry       = toWidth24(roundedDyn)
    val mant24IfCarry       = toWidth24((roundedDyn >> 1).asUInt)
    val mant24Norm          = Mux(carryDyn, mant24IfCarry, mant24NoCarry)
    val biasedExpAfterRound = (biased_exp + Mux(carryDyn, 1.S, 0.S)).asSInt

    // 7) Final exp/mant (NaN/Zero/Inf/Subnormal/Normal)
    val exponent_conv = Wire(UInt(8.W));  exponent_conv := 0.U
    val mantissa_conv = Wire(UInt(23.W)); mantissa_conv := 0.U

    when (nanFlag === 1.U) {
      exponent_conv := 255.U; mantissa_conv := 4194304.U             // qNaN
    } .elsewhen (isZero) {
      exponent_conv := 0.U;   mantissa_conv := 0.U
    } .elsewhen (biasedExpAfterRound >= 255.S) {
      exponent_conv := 255.U; mantissa_conv := 0.U                      // +Inf
    } .elsewhen (biasedExpAfterRound <= 0.S) {
      // Subnormal: k = 1 - E' (jammed right), then 23-bit RNE
      val k    = (1.S - biasedExpAfterRound).asUInt
      val kCap = Mux(k > 31.U, 31.U, k)
      val (subSig24, subSticky) = shiftRightJamCapped(mant24Norm, kCap) // width=24

      val keep23    = subSig24(23, 1)
      val guard2    = subSig24(0)
      val lsb2      = keep23(0)
      val roundUp2  = guard2.asBool && (subSticky || lsb2.asBool)
      val rounded23 = keep23 +& roundUp2.asUInt
      val carry23   = rounded23(23)

      when (carry23.asBool) { exponent_conv := 1.U; mantissa_conv := 0.U }
        .otherwise         { exponent_conv := 0.U; mantissa_conv := rounded23(22, 0) }
    } .otherwise {
      exponent_conv := biasedExpAfterRound.asUInt
      mantissa_conv := mant24Norm(22, 0)
    }

    // 8) Outputs (NaN -> sign=0)
    when (enable_depth) {
      io.out(i).sign     := Mux(nanFlag === 1.U, 0.U, inSign)
      io.out(i).exponent := exponent_conv
      io.out(i).mantissa := mantissa_conv
    } .otherwise {
      io.out(i).sign     := 0.U
      io.out(i).exponent := 0.U
      io.out(i).mantissa := 0.U
    }
  }
}


