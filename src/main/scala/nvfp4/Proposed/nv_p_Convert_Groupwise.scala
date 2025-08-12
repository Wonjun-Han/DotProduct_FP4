package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_CONVERT_GROUPWISE_BLOCK_IO(depthBitWidth: Int, mantissaWidth: Int, vecSize: Int) extends Bundle {
  val depth    = Input(UInt(depthBitWidth.W))
  val mantissa = Input(Vec(vecSize, UInt(mantissaWidth.W))) // from p_Adder_Groupwise (magnitude only)
  val sign     = Input(Vec(vecSize, UInt(1.W)))             // from p_Adder_Groupwise
  val nan      = Input(Vec(4, UInt(1.W)))             // from p_NaN_Process (앞에서부터 매핑)
  val exponent = Input(Vec(4, SInt(10.W)))            // from p_Expansion_Groupwise (앞에서부터 매핑)

  val out      = Output(Vec(vecSize, new FP32))

  // Debug ports
  val debug_real_exp   = Output(Vec(vecSize, SInt(10.W)))
  val debug_biased_exp = Output(Vec(vecSize, SInt(10.W)))
  val debug_shift_amt  = Output(Vec(vecSize, SInt(7.W)))
  val debug_PE         = Output(Vec(vecSize, UInt(6.W)))
}

class p_Convert_Groupwise(val d: Int, val extra: Int) extends Module {
  // 내부 고정소수점 폭: 정수부(8+d-?가 아니라 설계상 합산 결과 폭) + 소수부(6) + extra
  val mantissaWidth = 8 + d + extra
  val vecSize       = 256 >> d                 // depth 6: 4, 7: 2, 8: 1
  val FRACW         = 6 + extra                // 이진 소수점(2^0, 정수 LSB) 비트 인덱스 (설계상 고정)

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

  for (i <- 0 until vecSize) {
    // 0) 입력 magnitude/부호
    val inMag    = io.mantissa(i)
    val inSign   = io.sign(i)

    // 1) PE 기반 정렬량 계산: 유효 '1'을 FRACW(2^0 위치)에 놓도록
    val pe        = PriorityEncoder(Reverse(inMag))
    val shift_amt = (d + 1).S - pe.asSInt

    // 2) 그룹 인덱스/지수/NaN (앞에서부터 매핑 가정)
    val groupIdx = i.U(2.W)
    val grpExp   = io.exponent(groupIdx)
    val nanFlag  = io.nan(groupIdx)

    // 3) 실지수/바이어스 지수
    val real_exp   = grpExp + shift_amt
    val biased_exp = real_exp + 127.S

    // 4) 1차 정렬: 오른쪽 시프트는 jam으로 → stickyAlign에 손실정보 누적
    val alignedMag      = Wire(UInt(mantissaWidth.W)) // 소수점 정렬 후 magnitude
    val stickyFromAlign = Wire(Bool())                // 1차 정렬에서 잃은 하위비트 OR

    when (shift_amt >= 0.S) {
      val (y, s) = shiftRightJam(inMag, shift_amt.asUInt)
      alignedMag      := y
      stickyFromAlign := s
    } .otherwise {
      alignedMag      := inMag << (-shift_amt).asUInt
      stickyFromAlign := false.B
    }

    // 5) FRACW 기준 25비트 창(keep24=1+23 + guard) 추출 (두 번째 우시프트 없이 슬라이스/패딩)
    //    window25 = [keep24(24..1), guard(0)]
    val window25        = Wire(UInt(25.W))
    val stickyBelowGuard= Wire(Bool()) // guard 아래 남아있는 모든 비트 OR (R∨S 역할)

    if (FRACW >= 24) {
      val hi = FRACW                // FRACW..FRACW-24 → 정확히 25비트
      val lo = FRACW - 24
      window25 := alignedMag(hi, lo)

      // guard 아래에 물리적으로 남는 비트들을 sticky로 더한다.
      val extraSticky =
        if (FRACW >= 25) alignedMag(FRACW - 25, 0).orR else false.B
      stickyBelowGuard := stickyFromAlign || extraSticky
    } else {
      // FRACW < 24: guard/아래 비트가 벡터를 벗어나므로 0으로 패딩
      val upper = alignedMag(FRACW, 0)         // (FRACW+1)비트
      val pad   = 24 - FRACW                   // 0 패딩 개수
      window25 := Cat(upper, 0.U(pad.W))       // (FRACW+1)+pad = 25비트
      stickyBelowGuard := stickyFromAlign      // 추가 하위비트 없음
    }

    // 6) RNE 반올림(정상 후보)
    val keepSig24  = window25(24, 1)      // 1(리딩) + 23(가수)
    val guardBit   = window25(0)
    val lsbBit     = keepSig24(0)
    val roundUp    = guardBit && (stickyBelowGuard || (lsbBit === 1.U)) // Rule1/Rule2/Rule3

    val rounded24  = keepSig24 +& roundUp.asUInt // 24+1 비트 결과
    val carry24Bit = rounded24(24)               // 캐리 발생 시 1
    val mant24Norm = Mux(carry24Bit.asBool, rounded24(24,1), rounded24(23,0)) // 캐리 시 정규화

    // 캐리 반영한 바이어스 지수
    val biasedExpAfterRound = (biased_exp + Mux(carry24Bit.asBool, 1.S, 0.S)).asSInt

    // 7) 최종 지수/가수 선택 (NaN/Zero/Overflow/Subnormal/Normal)
    val exponent_conv = Wire(UInt(8.W))
    val mantissa_conv = Wire(UInt(23.W))

    val isZero = inMag === 0.U

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
      // Subnormal: k = 1 - E' 만큼 추가 jam 우시프트 후 23비트로 다시 RNE
      val k    = (1.S - biasedExpAfterRound).asUInt
      val kCap = Mux(k > 31.U, 31.U, k)      // 안전 캡
      val (subSig24, subSticky) = shiftRightJam(mant24Norm, kCap) // 24비트 유지

      // 23비트 RNE
      val keepSig23  = (if (subSig24.getWidth < 24) Cat(0.U((24 - subSig24.getWidth).W), subSig24) else subSig24)(23,1)
      val guard2     = (if (subSig24.getWidth < 24) Cat(0.U((24 - subSig24.getWidth).W), subSig24) else subSig24)(0)
      val lsb2       = keepSig23(0)
      val roundUp2   = guard2 && (subSticky || (lsb2 === 1.U))
      val rounded23  = keepSig23 +& roundUp2.asUInt      // 23+1 비트
      val carry23Bit = rounded23(23)

      when (carry23Bit.asBool) {
        // 라운딩으로 정상 승격 → 1.000.. (숨은 1 제외하면 가수 23비트는 0)
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

    // 8) 출력 게이팅 및 부호 처리(NaN이면 sign=0)
    when (enable_depth) {
      io.out(i).sign     := Mux(nanFlag === 1.U, 0.U, inSign)
      io.out(i).exponent := exponent_conv
      io.out(i).mantissa := mantissa_conv
    } .otherwise {
      io.out(i).sign     := 0.U
      io.out(i).exponent := 0.U
      io.out(i).mantissa := 0.U
    }

    // Debug
    io.debug_real_exp(i)   := real_exp
    io.debug_biased_exp(i) := biased_exp
    io.debug_shift_amt(i)  := shift_amt
    io.debug_PE(i)         := pe
  }
}
