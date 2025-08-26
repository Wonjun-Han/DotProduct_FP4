package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_CONVERT_GROUPWISE_BLOCK_IO(depthBitWidth: Int, mantissaWidth: Int, vecSize: Int) extends Bundle {
  val depth    = Input(UInt(depthBitWidth.W))
  val in      = Input(Vec(vecSize, SInt((mantissaWidth + 1).W))) // from p_Adder_Groupwise (with sign bit)
  //val mantissa = Input(Vec(vecSize, UInt(mantissaWidth.W))) // from p_Adder_Groupwise (magnitude only)
  //val sign     = Input(Vec(vecSize, UInt(1.W)))             // from p_Adder_Groupwise
  val nan      = Input(Vec(4, UInt(1.W)))                   // from p_NaN_Process (앞에서부터 매핑)
  val exponent = Input(Vec(4, SInt(10.W)))                  // from p_Expansion_Groupwise (앞에서부터 매핑)
  val out      = Output(Vec(vecSize, new FP32))
}

class p_Convert_Groupwise(val d: Int, val extra: Int) extends Module {
  val mantissaWidth = 8 + d + extra
  val vecSize       = 256 >> d                 // depth 6: 4, 7: 2, 8: 1
  val FRACW         = 6 + extra                // 2^0 위치 인덱스

  val io = IO(new MXFP4_CONVERT_GROUPWISE_BLOCK_IO(
    depthBitWidth = 4, mantissaWidth = mantissaWidth, vecSize = vecSize
  ))

  val enable_depth = io.depth === d.U

  // -------- util: jammed right shift (x >> shamt, 잘려나간 하위 비트 OR → sticky) --------
  private def shiftRightJam(x: UInt, shamt: UInt): (UInt, Bool) = {
    val W       = x.getWidth
    val big     = shamt >= W.U
    val shifted = Mux(big, 0.U(W.W), (x >> shamt).asUInt)
    val mask    = Mux(big, ((BigInt(1) << W) - 1).U(W.W), ((1.U(W.W) << shamt) - 1.U(W.W)))
    val sticky  = (x & mask).orR
    (shifted, sticky)
  }

  // -------- util: 안전한 트리형 LZC (Leading-Zero Count) --------
  // - 입력폭 w를 다음 power-of-two(P)로 LSB 방향 0 패딩 → 단계마다 절반 비교
  // - 최종 카운트는 padded 기준이므로 원폭 w로 clamp
  private def lzcTreeSafe(x: UInt, outW: Int): UInt = {
    val w   = x.getWidth
    require(w >= 1, "lzcTreeSafe: x width must be >= 1")
    val pPow  = 1 << log2Ceil(w)                 // P = power-of-two ≥ w
    val padW  = pPow - w
    val padded: UInt = if (padW == 0) x else Cat(x, 0.U(padW.W)) // LSB 쪽 0패딩
    val levels = log2Ceil(pPow)

    val levelSig = Array.ofDim[UInt](levels + 1)
    val levelCnt = Array.ofDim[UInt](levels + 1)
    levelSig(0) = padded
    levelCnt(0) = 0.U(outW.W)

    for (s <- 0 until levels) {
      val width = pPow >> s
      val half  = width >> 1
      val hi    = levelSig(s)(width-1, half)
      val lo    = levelSig(s)(half-1, 0)
      val hiNZ  = hi.orR
      levelSig(s+1) = Mux(hiNZ, hi, lo)
      levelCnt(s+1) = Mux(hiNZ, levelCnt(s), levelCnt(s) + half.U(outW.W))
    }
    val cntPadded = levelCnt(levels) // 0..P
    Mux(cntPadded > w.U, w.U(outW.W), cntPadded)(outW-1, 0)
  }

  // -------- lane→group 인덱스 LUT (깊이 d 고정 상수 매핑; 1회 생성) --------
  // exponent/nan의 인덱스는 0..3 (2비트면 충분)
  val groupIdxLut  = Wire(Vec(vecSize, UInt(2.W)))
  for (k <- 0 until vecSize) groupIdxLut(k) := 0.U
  if (vecSize == 4) {
    for (k <- 0 until vecSize) groupIdxLut(k) := k.U(2.W) // 0,1,2,3
  } else if (vecSize == 2) {
    for (k <- 0 until vecSize) groupIdxLut(k) := k.U(2.W) // 0,1
  } else { // vecSize == 1
    groupIdxLut(0) := 0.U
  }

  for (i <- 0 until vecSize) {
    val inMag    = Mux(io.in(i).head(1) === 1.U, (-io.in(i)).asUInt, io.in(i).asUInt)
    val inSign   = io.in(i).head(1).asUInt
    val groupIdx = groupIdxLut(i)
    val grpExp   = io.exponent(groupIdx)
    val nanFlag  = io.nan(groupIdx)

    // ---- Zero/NaN 선제 게이팅(operand isolation) ----
    val isZero        = inMag === 0.U
    val activeHeavy   = enable_depth && (nanFlag =/= 1.U) && !isZero
    val inMagEff      = Mux(activeHeavy, inMag, 0.U(mantissaWidth.W)) // heavy path 입력 최소 토글

    // 1) MSB 탐색: 트리형 LZC (변수명 pe 유지)
    val pe: UInt = lzcTreeSafe(inMagEff, outW = log2Ceil(mantissaWidth + 1))

    // 2) 정렬량 (변수명 shift_amt 유지)
    val shift_amt = (d + 1).S - pe.asSInt

    // 3) 실지수/바이어스 지수
    val real_exp   = grpExp + shift_amt
    val biased_exp = real_exp + 127.S

    // 4) 1차 정렬 (jam) + 상한 클램프
    val alignedMag      = Wire(UInt(mantissaWidth.W)); alignedMag := 0.U
    val stickyFromAlign = Wire(Bool());                stickyFromAlign := false.B
    val shMax = (mantissaWidth - 1).U

    when (shift_amt >= 0.S) {
      val shU   = shift_amt.asUInt
      val shCap = Mux(shU > shMax, shMax, shU)
      val (y, s) = shiftRightJam(inMagEff, shCap)
      alignedMag      := y
      stickyFromAlign := s
    } .otherwise {
      val shL   = (-shift_amt).asUInt
      val shCap = Mux(shL > shMax, shMax, shL)
      alignedMag      := (inMagEff << shCap)(mantissaWidth-1, 0)
      stickyFromAlign := false.B
    }

    // 5) FRACW 기준 25비트 창 추출
    val window25         = Wire(UInt(25.W)); window25 := 0.U
    val stickyBelowGuard = Wire(Bool());     stickyBelowGuard := stickyFromAlign
    if (FRACW >= 24) {
      val hi = FRACW
      val lo = FRACW - 24
      window25 := alignedMag(hi, lo)
      val extraSticky = if (FRACW >= 25) alignedMag(FRACW - 25, 0).orR else false.B
      stickyBelowGuard := stickyFromAlign || extraSticky
    } else {
      val upper = alignedMag(FRACW, 0)
      val pad   = 24 - FRACW
      window25 := Cat(upper, 0.U(pad.W))
      // stickyBelowGuard는 위에서 기본값 유지
    }

    // 6) RNE 반올림(정상 후보)
    val keepSig24  = window25(24, 1)
    val guardBit   = window25(0)
    val lsbBit     = keepSig24(0)
    val roundUp    = guardBit && (stickyBelowGuard || (lsbBit === 1.U))
    val rounded24  = keepSig24 +& roundUp.asUInt
    val carry24Bit = rounded24(24)
    val mant24Norm = Mux(carry24Bit.asBool, rounded24(24,1), rounded24(23,0))
    val biasedExpAfterRound = (biased_exp + Mux(carry24Bit.asBool, 1.S, 0.S)).asSInt

    // 7) 최종 지수/가수
    val exponent_conv = Wire(UInt(8.W));  exponent_conv := 0.U
    val mantissa_conv = Wire(UInt(23.W)); mantissa_conv := 0.U

    when (nanFlag === 1.U) {
      exponent_conv := 255.U
      mantissa_conv := (1.U << 22)            // qNaN
    } .elsewhen (isZero) {
      exponent_conv := 0.U
      mantissa_conv := 0.U
    } .elsewhen (biasedExpAfterRound >= 255.S) {
      exponent_conv := 255.U                  // +Inf
      mantissa_conv := 0.U
    } .elsewhen (biasedExpAfterRound <= 0.S) {
      // Subnormal: k = 1 - E' 만큼 추가 jam 우시프트 후 23비트 RNE
      val k    = (1.S - biasedExpAfterRound).asUInt
      val kCap = Mux(k > 31.U, 31.U, k)      // 소폭 상한
      val (subSig24, subSticky) = shiftRightJam(mant24Norm, kCap)

      val sig24 = if (subSig24.getWidth < 24) Cat(0.U((24 - subSig24.getWidth).W), subSig24) else subSig24
      val keepSig23  = sig24(23,1)
      val guard2     = sig24(0)
      val lsb2       = keepSig23(0)
      val roundUp2   = guard2 && (subSticky || (lsb2 === 1.U))
      val rounded23  = keepSig23 +& roundUp2.asUInt
      val carry23Bit = rounded23(23)

      when (carry23Bit.asBool) {
        exponent_conv := 1.U
        mantissa_conv := 0.U
      } .otherwise {
        exponent_conv := 0.U
        mantissa_conv := rounded23(22, 0)
      }
    } .otherwise {
      exponent_conv := biasedExpAfterRound.asUInt
      mantissa_conv := mant24Norm(22, 0)
    }

    // 8) 출력 (NaN이면 sign=0)
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
