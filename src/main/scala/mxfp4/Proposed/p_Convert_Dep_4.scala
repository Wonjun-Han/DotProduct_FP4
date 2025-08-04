package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_CONVERT_DEPTH4_BLOCK_IO extends Bundle {
  val depth    = Input(UInt(3.W))
  val in       = Input(Vec(16, SInt(13.W)))     // Q8.6 고정소수점 누적합
  val nan      = Input(Vec(8, UInt(1.W)))      // NaN 여부 flag
  val exponent = Input(Vec(8, SInt(10.W)))     // ScaleEmax 결과
  val out      = Output(Vec(16, new FP32))      // FP32 결과

  // for debugging
  val debug_real_exp   = Output(Vec(16, SInt(10.W)))
  val debug_biased_exp = Output(Vec(16, SInt(10.W)))
  val debug_shift_amt  = Output(Vec(16, SInt(5.W)))
  val debug_PE         = Output(Vec(16, UInt(4.W)))
  val debug_abs_in     = Output(Vec(16, UInt(12.W)))
}

class p_Convert_Dep_4 extends Module {
  val io = IO(new MXFP4_CONVERT_DEPTH4_BLOCK_IO)
  val enable_depth_4 = io.depth === 4.U

  for (i <- 0 until 16) {
    // ---------------------
    // Step 1: Sign 및 절댓값
    // ---------------------
    val input        = io.in(i)
    val sign_bit     = Mux(input < 0.S, 1.U, 0.U)
    val abs_val_full = Mux(input < 0.S, -input, input).asUInt // UInt(12.W)

    // ✅ 절댓값의 MSB는 항상 0 (Q8.6 최대값 8191)
    val abs_val = abs_val_full(11, 0) // MSB 제거 → UInt(12.W)

    // ---------------------
    // Step 2: PriorityEncoder + shift
    // ---------------------
    val PE = PriorityEncoder(Reverse(abs_val))    // 최상위 1bit 위치
    val shift_amt = (5.S - PE.asSInt).asSInt      // 고정소수점 기준 정규화 shift (소수점 기준)

    // mantissa 확장: 13bit → 30bit
    val extended_mantissa = Cat(abs_val, 0.U(17.W)) 

    // ---------------------
    // Step 3: Exponent 계산
    // ---------------------
    val real_exp   = io.exponent(i/2) + shift_amt    // scale_sum + emax + 정규화 shift
    val biased_exp = real_exp + 127.S              // IEEE 754 bias 추가

    val exponent_conv = Wire(UInt(8.W))
    val mantissa_conv = Wire(UInt(23.W))
    val nan = io.nan(i/2)

    when(nan===1.U){
        exponent_conv := 255.U // NaN 
        mantissa_conv := 4194304.U // NaN mantissa
    }.elsewhen(io.in(i)===0.S){
        exponent_conv := 0.U
        mantissa_conv := 0.U
    }.elsewhen (real_exp >= 128.S) {
      // Overflow → Inf
      exponent_conv := 255.U
      mantissa_conv := 0.U
    }.elsewhen (biased_exp <= 0.S) {
      // Underflow → Subnormal
      exponent_conv := 0.U
      val sub_shift = (shift_amt.abs.asUInt - (1.S - biased_exp).asUInt).asSInt
      mantissa_conv := Mux(sub_shift >= 0.S, 
        (extended_mantissa << sub_shift.asUInt)(22, 0), 
        (extended_mantissa >> sub_shift.abs.asUInt)(22, 0)
      )
    }.otherwise {
      // Normal
      exponent_conv := biased_exp.asUInt
      mantissa_conv := Mux(shift_amt >= 0.S,
        (extended_mantissa >> shift_amt.asUInt)(22, 0),
        (extended_mantissa << shift_amt.abs.asUInt)(22, 0)
      )
    }

    // ---------------------
    // Step 4: 출력
    // ---------------------
    when (enable_depth_4) {
      io.out(i).sign     := Mux(nan===1.U, 0.U, sign_bit)
      io.out(i).exponent := exponent_conv
      io.out(i).mantissa := mantissa_conv
    }.otherwise {
      io.out(i).sign     := 0.U
      io.out(i).exponent := 0.U
      io.out(i).mantissa := 0.U
    }

    // Debugging outputs
    io.debug_real_exp(i)   := real_exp
    io.debug_biased_exp(i) := biased_exp
    io.debug_shift_amt(i)  := shift_amt
    io.debug_PE(i)         := PE
    io.debug_abs_in(i)     := abs_val

  }
}
