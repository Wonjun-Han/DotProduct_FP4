//Not used !
package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_Preprocess_Dep_0_IO extends Bundle {
  val sign     = Input(Vec(256, UInt(1.W)))
  val exponent = Input(Vec(256, UInt(3.W)))
  val mantissa = Input(Vec(256, UInt(4.W)))
  val scale_sum = Input(Vec(8, SInt(9.W)))
  val nan  = Input(Vec(8, UInt(1.W)))

  val out_exp      = Output(Vec(256, SInt(10.W)))  // exponent (real_exp)
  val out_nan      = Output(Vec(8, UInt(1.W)))     // forwarded NaN
  val out_mant     = Output(Vec(256, SInt(9.W)))   // signed mantissa (Q2.2 + sign)
}

class p_Preprocess_Dep_0 extends Module {
  val io = IO(new p_Preprocess_Dep_0_IO)

  val real_exp = Wire(Vec(256, SInt(10.W)))
  val real_man = Wire(Vec(256, SInt(9.W)))

  for (i <- 0 until 256) {
    val sign_bit = io.sign(i)
    val mant = io.mantissa(i)
    val exp = io.exponent(i)

    // Absolute mantissa with padding (for PE)
    val abs_val = Cat(mant, 0.U(4.W)) // 8-bit unsigned
    val PE = PriorityEncoder(Reverse(abs_val))
    val shift_amt = (1.S - PE.asSInt)

    // Real exponent = scale_sum + input exponent + shift_amt
    val group = i / 32
    val exp_base = io.scale_sum(group) + exp.zext + shift_amt
    real_exp(i) := exp_base

    // Signed mantissa (9-bit): sign-extended padded mantissa
    val extended_mantissa = Cat(mant, 0.U(4.W)) // still unsigned
    val signed_mantissa = Mux(sign_bit === 1.U,
                              -extended_mantissa.asSInt,
                               extended_mantissa.asSInt)
    real_man(i) := signed_mantissa
  }

  // Output connect
  io.out_exp := real_exp
  io.out_mant := real_man
  io.out_nan := io.nan
}
