package mxfp4.piped

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_Adder_Dep_2 extends Module {
  val io = IO(new Bundle {
    val a   = Input(Vec(128, new FP32))
    val out = Output(Vec(64, new FP32))
  })

  // Stage 1: NaN / Inf / Zero Check
  val a_s1 = RegNext(io.a)

  val is_nan      = Wire(Vec(128, Bool()))
  val is_inf      = Wire(Vec(128, Bool()))
  val is_both_zero = Wire(Vec(128, Bool()))
  val both_neg_zero = Wire(Vec(128, Bool()))
  val a_is_sub = Wire(Vec(128, Bool()))
  val b_is_sub = Wire(Vec(128, Bool()))
  val a_sign = Wire(Vec(128, UInt(1.W)))
  val b_sign = Wire(Vec(128, UInt(1.W)))

  for (i <- 0 until 128) {
    val a = a_s1(2 * i)
    val b = a_s1(2 * i + 1)

    a_is_sub(i) := a.exponent === 0.U
    b_is_sub(i) := b.exponent === 0.U
    val a_zero = a_is_sub(i) && (a.mantissa === 0.U)
    val b_zero = b_is_sub(i) && (b.mantissa === 0.U)
    val a_nan = (a.exponent === 255.U) && (a.mantissa =/= 0.U)
    val b_nan = (b.exponent === 255.U) && (b.mantissa =/= 0.U)
    val a_inf = (a.exponent === 255.U) && (a.mantissa === 0.U)
    val b_inf = (b.exponent === 255.U) && (b.mantissa === 0.U)

    is_nan(i) := a_nan || b_nan || (a_inf && b_inf && (a.sign ^ b.sign).asBool)
    is_inf(i) := (a_inf || b_inf) && !is_nan(i)
    is_both_zero(i) := a_zero && b_zero
    both_neg_zero(i) := is_both_zero(i) && (a.sign === 1.U) && (b.sign === 1.U)

    a_sign(i) := a.sign
    b_sign(i) := b.sign
  }

  // Stage 2: Mantissa align
  val a_s2 = RegNext(a_s1)
  val a_sign_s2 = RegNext(a_sign)
  val b_sign_s2 = RegNext(b_sign)
  val a_is_sub_s2 = RegNext(a_is_sub)
  val b_is_sub_s2 = RegNext(b_is_sub)

  val mant_large = Wire(Vec(128, UInt(24.W)))
  val mant_small_shifted = Wire(Vec(128, UInt(27.W)))
  val exp_large = Wire(Vec(128, UInt(8.W)))
  val sign_large = Wire(Vec(128, UInt(1.W)))
  val sign_small = Wire(Vec(128, UInt(1.W)))

  for (i <- 0 until 128) {
    val a = a_s2(2 * i)
    val b = a_s2(2 * i + 1)

    val a_m = Mux(a_is_sub_s2(i), Cat(0.U(1.W), a.mantissa), Cat(1.U(1.W), a.mantissa))
    val b_m = Mux(b_is_sub_s2(i), Cat(0.U(1.W), b.mantissa), Cat(1.U(1.W), b.mantissa))

    val exp_diff = (a.exponent - b.exponent).asSInt
    val a_exp_gt = exp_diff >= 0.S
    val shift_amt = Mux(a_exp_gt, exp_diff, -exp_diff).asUInt

    val a_man_gt = a.mantissa >= b.mantissa
    val exp_equal = a.exponent === b.exponent
    val a_is_larger = Mux(exp_equal, a_man_gt, a_exp_gt)

    val mant_l = Mux(a_is_larger, a_m, b_m)
    val mant_s = Mux(a_is_larger, b_m, a_m)
    mant_large(i) := mant_l
    mant_small_shifted(i) := (Cat(mant_s, 0.U(3.W)) >> shift_amt).pad(27)

    exp_large(i) := Mux(a_exp_gt, a.exponent, b.exponent)
    sign_large(i) := Mux(a_is_larger, a_sign_s2(i), b_sign_s2(i))
    sign_small(i) := Mux(sign_large(i) === a_sign_s2(i), b_sign_s2(i), a_sign_s2(i))
  }

  // Stage 3: Add/Sub
  val mant_large_s3 = RegNext(mant_large)
  val mant_small_s3 = RegNext(mant_small_shifted)
  val sign_large_s3 = RegNext(sign_large)
  val sign_small_s3 = RegNext(sign_small)
  val exp_large_s3  = RegNext(exp_large)

  val mant_sum_s3 = Wire(Vec(128, UInt(28.W)))
  for (i <- 0 until 128) {
    val l = Cat(mant_large_s3(i), 0.U(3.W))
    val s = mant_small_s3(i)
    mant_sum_s3(i) := Mux(sign_large_s3(i) === sign_small_s3(i), l +& s, l -& s)
  }

  // Stage 4: Normalize (LZC)
  val mant_sum_s4 = RegNext(mant_sum_s3)
  val exp_large_s4 = RegNext(exp_large_s3)
  val sign_large_s4 = RegNext(sign_large_s3)

  val lz_s4 = Wire(Vec(128, UInt(5.W)))
  val mant_norm_s4 = Wire(Vec(128, UInt(23.W)))
  val exp_norm_s4 = Wire(Vec(128, UInt(8.W)))
  val skip_rounding = Wire(Vec(128, Bool()))

  for (i <- 0 until 128) {
    val denorm = mant_sum_s4(i)(27, 0)
    val lz = PriorityEncoder(Reverse(denorm))
    lz_s4(i) := lz
    skip_rounding(i) := lz >= 4.U

    val mant_shifted = MuxCase(denorm(25, 3), Seq(
      (lz === 0.U) -> denorm(26, 4),
      (lz >= 2.U)  -> (denorm << (lz - 1.U))(25, 3)
    ))

    val exp = MuxCase(exp_large_s4(i), Seq(
      (lz === 0.U) -> (exp_large_s4(i) + 1.U),
      (lz >= 2.U)  -> (exp_large_s4(i) - (lz - 1.U))
    ))

    mant_norm_s4(i) := mant_shifted
    exp_norm_s4(i) := exp
  }

  // Stage 5: Rounding
  val mant_norm_s5 = RegNext(mant_norm_s4)
  val exp_norm_s5 = RegNext(exp_norm_s4)
  val sign_s5 = RegNext(sign_large_s4)
  val lz_s5 = RegNext(lz_s4)
  val skip_rounding_s5 = RegNext(skip_rounding)

  val mant_final = Wire(Vec(128, UInt(23.W)))
  val exp_final  = Wire(Vec(128, UInt(8.W)))

  for (i <- 0 until 128) {
    when (skip_rounding_s5(i)) {
      mant_final(i) := mant_norm_s5(i)
      exp_final(i)  := exp_norm_s5(i)
    }.otherwise {
      val grs = MuxCase(mant_norm_s5(i)(2, 0), Seq(
        (lz_s5(i) === 0.U) -> mant_norm_s5(i)(3, 1),
        (lz_s5(i) === 1.U) -> mant_norm_s5(i)(2, 0),
        (lz_s5(i) === 2.U) -> (mant_norm_s5(i)(2, 0) << 1)(2, 0),
        (lz_s5(i) === 3.U) -> (mant_norm_s5(i)(2, 0) << 2)(2, 0)
      ))

      val sticky = grs(0) | grs(1)
      val round  = grs(1)
      val guard  = grs(2)
      val round_up = guard & (round | sticky | mant_norm_s5(i)(0))
      val rounded = mant_norm_s5(i) +& round_up

      mant_final(i) := Mux(rounded(23), rounded(23, 1), rounded(22, 0))
      exp_final(i)  := Mux(rounded(23), exp_norm_s5(i) - 1.U, exp_norm_s5(i))
    }
  }

  // Stage 6: Final output
  val sign_s6     = RegNext(sign_s5)
  val exponent_s6 = RegNext(exp_final)
  val mantissa_s6 = RegNext(mant_final)

  for (i <- 0 until 128) {
    val is_overflow  = exponent_s6(i) > 254.U
    val is_underflow = exponent_s6(i) <= 0.U

    when (is_overflow) {
      io.out(i).sign     := sign_s6(i)
      io.out(i).exponent := 255.U
      io.out(i).mantissa := 0.U
    }.elsewhen (is_underflow) {
      io.out(i).sign     := sign_s6(i)
      io.out(i).exponent := 0.U
      io.out(i).mantissa := mantissa_s6(i) >> 1
    }.otherwise {
      io.out(i).sign     := sign_s6(i)
      io.out(i).exponent := exponent_s6(i)
      io.out(i).mantissa := mantissa_s6(i)
    }
  }
}
