package mxfp4

import chisel3._
import _root_.circt.stage.ChiselStage
import chisel3.util._

class Adder_Dep_6 extends Module {
  val io = IO(new Bundle {
    val a   = Input(Vec(8, new FP32))
    val out = Output(Vec(4, new FP32))
  })

  for (i <- 0 until 4) {
    val a = io.a(2 * i)
    val b = io.a(2 * i + 1)

    val a_is_sub = a.exponent === 0.U
    val b_is_sub = b.exponent === 0.U
    val a_is_zero = a_is_sub && (a.mantissa === 0.U)
    val b_is_zero = b_is_sub && (b.mantissa === 0.U)
    val a_nan = (a.exponent === 255.U) && (a.mantissa =/= 0.U)
    val b_nan = (b.exponent === 255.U) && (b.mantissa =/= 0.U)
    val a_inf = (a.exponent === 255.U) && (a.mantissa === 0.U)
    val b_inf = (b.exponent === 255.U) && (b.mantissa === 0.U)

    val is_nan = a_nan || b_nan || (a_inf && b_inf && (a.sign ^ b.sign).asBool)
    val is_inf = (a_inf || b_inf) && !is_nan
    val is_both_zero = a_is_zero && b_is_zero
    val both_neg_zero = is_both_zero && (a.sign === 1.U) && (b.sign === 1.U)

    when(is_nan) {
      io.out(i).sign := 0.U
      io.out(i).exponent := 255.U
      io.out(i).mantissa := "b10000000000000000000000".U
    }.elsewhen(is_inf) {
      io.out(i).sign := a.sign
      io.out(i).exponent := 255.U
      io.out(i).mantissa := 0.U
    }.elsewhen(is_both_zero) {
      io.out(i).sign := Mux(both_neg_zero, 1.U, 0.U)
      io.out(i).exponent := 0.U
      io.out(i).mantissa := 0.U
    }.otherwise {
      val a_m = Mux(a_is_sub, Cat(0.U(1.W), a.mantissa), Cat(1.U(1.W), a.mantissa))
      val b_m = Mux(b_is_sub, Cat(0.U(1.W), b.mantissa), Cat(1.U(1.W), b.mantissa))

      val exp_diff = (a.exponent - b.exponent).asSInt
      val a_exp_gt = exp_diff >= 0.S
      val shift_amt = Mux(a_exp_gt, exp_diff, -exp_diff).asUInt

      val a_man_gt = a.mantissa >= b.mantissa
      val exp_equal = a.exponent === b.exponent
      val a_is_larger = Mux(exp_equal, a_man_gt, a_exp_gt)

      val mant_large = Mux(a_is_larger, a_m, b_m)
      val mant_small = Mux(a_is_larger, b_m, a_m)
      val exp_large = Mux(a_exp_gt, a.exponent, b.exponent)

      val sign_large = Mux(a_is_larger, a.sign, b.sign)
      val sign_small = Mux(sign_large === a.sign, b.sign, a.sign)

      val mant_small_shifted = (Cat(mant_small, 0.U(3.W)) >> shift_amt).pad(27)
      val mant_large_ext = Cat(mant_large, 0.U(3.W))

      val sum = Mux(sign_large === sign_small,
        mant_large_ext +& mant_small_shifted,
        mant_large_ext -& mant_small_shifted
      )

      val mantissa_denorm = sum(27, 0) // 28bit
      val lz = PriorityEncoder(Reverse(mantissa_denorm))
      val skip_rounding = lz >= 4.U

      val mantissa_norm = MuxCase(mantissa_denorm(25, 3), Seq(
        (lz === 0.U) -> mantissa_denorm(26, 4),
        (lz >= 2.U)  -> (mantissa_denorm << (lz - 1.U))(25, 3)
      ))

      val exp_norm = MuxCase(exp_large, Seq(
        (lz === 0.U) -> (exp_large + 1.U),
        (lz >= 2.U)  -> (exp_large - (lz - 1.U))
      ))

      val final_mant = Wire(UInt(23.W))
      val final_exp = Wire(UInt(8.W))

      when(skip_rounding) {
        final_mant := mantissa_norm
        final_exp  := exp_norm
      }.otherwise {
        val grs_select = MuxCase(mantissa_norm(2, 0), Seq(
          (lz === 0.U) -> mantissa_norm(3, 1),
          (lz === 1.U) -> mantissa_norm(2, 0),
          (lz === 2.U) -> (mantissa_norm(2, 0) << 1)(2, 0),
          (lz === 3.U) -> (mantissa_norm(2, 0) << 2)(2, 0)
        ))

        val sticky = grs_select(0) | grs_select(1)
        val round  = grs_select(1)
        val guard  = grs_select(2)

        val round_up = guard & (round | sticky | mantissa_norm(0))
        val round_mant = mantissa_norm +& round_up

        final_mant := Mux(round_mant(23), round_mant(23, 1), round_mant(22, 0))
        final_exp  := Mux(round_mant(23), exp_norm - 1.U, exp_norm)
      }

      // Overflow / Underflow
      val is_overflow   = final_exp > 254.U
      val is_underflow  = final_exp <= 0.U

      when(is_overflow) {
        io.out(i).sign := sign_large
        io.out(i).exponent := 255.U
        io.out(i).mantissa := 0.U
      }.elsewhen(is_underflow) {
        io.out(i).sign := sign_large
        io.out(i).exponent := 0.U
        io.out(i).mantissa := final_mant >> 1
      }.otherwise {
        io.out(i).sign := sign_large
        io.out(i).exponent := final_exp
        io.out(i).mantissa := final_mant
      }
    }
  }
}
