package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_CONVERT_BLOCK_IO extends Bundle {
  val depth    = Input(UInt(3.W))
  val in       = Input(Vec(256, SInt(14.W))) // Always max size, Qx.6
  val nan      = Input(Vec(8, UInt(1.W)))    // Per 32-element group
  val exponent = Input(Vec(8, SInt(10.W)))   // Scale sum + group emax
  val out      = Output(Vec(256, new FP32))  // Always max size

  val debug_real_exp   = Output(Vec(256, SInt(10.W)))
  val debug_biased_exp = Output(Vec(256, SInt(10.W)))
  val debug_shift_amt  = Output(Vec(256, SInt(5.W)))
  val debug_PE         = Output(Vec(256, UInt(4.W)))
  val debug_abs_in     = Output(Vec(256, UInt(13.W)))
}

class p_Convert extends Module {
  val io = IO(new MXFP4_CONVERT_BLOCK_IO)

  // Fully initialize all outputs
  for (i <- 0 until 256) {
    io.out(i).sign         := 0.U
    io.out(i).exponent     := 0.U
    io.out(i).mantissa     := 0.U
    io.debug_real_exp(i)   := 0.S
    io.debug_biased_exp(i) := 0.S
    io.debug_shift_amt(i)  := 0.S
    io.debug_PE(i)         := 0.U
    io.debug_abs_in(i)     := 0.U
  }

  def ConvertBlock_Add(idx: Int, groupExp: SInt, isNaN: UInt): Unit = {
    val input        = io.in(idx)
    val sign_bit     = Mux(input < 0.S, 1.U, 0.U)
    val abs_val_full = Mux(input < 0.S, -input, input).asUInt
    val abs_val      = abs_val_full(12, 0)

    val PE         = PriorityEncoder(Reverse(abs_val))
    val shift_amt  = (6.S - PE.asSInt).asSInt
    val extended_mantissa = Cat(abs_val, 0.U(17.W))

    val real_exp   = groupExp + shift_amt
    val biased_exp = real_exp + 127.S

    val exponent_conv = Wire(UInt(8.W))
    val mantissa_conv = Wire(UInt(23.W))

    when(isNaN === 1.U) {
      exponent_conv := 255.U
      mantissa_conv := 4194304.U
    }.elsewhen(real_exp >= 128.S) {
      exponent_conv := 255.U
      mantissa_conv := 0.U
    }.elsewhen(biased_exp <= 0.S) {
      val sub_shift = shift_amt.abs.asUInt - (1.S - biased_exp).asUInt
      exponent_conv := 0.U
      mantissa_conv := (extended_mantissa << sub_shift)(22, 0)
    }.otherwise {
      exponent_conv := biased_exp.asUInt
      mantissa_conv := Mux(shift_amt >= 0.S,
        (extended_mantissa >> shift_amt.asUInt)(22, 0),
        (extended_mantissa << shift_amt.abs.asUInt)(22, 0))
    }

    io.out(idx).sign     := Mux(isNaN === 1.U, 0.U, sign_bit)
    io.out(idx).exponent := exponent_conv
    io.out(idx).mantissa := mantissa_conv

    io.debug_real_exp(idx)   := real_exp
    io.debug_biased_exp(idx) := biased_exp
    io.debug_shift_amt(idx)  := shift_amt
    io.debug_PE(idx)         := PE
    io.debug_abs_in(idx)     := abs_val
  }

  switch(io.depth) {
    is(1.U) { for (i <- 0 until 128) { val g = i / 16; ConvertBlock_Add(i, io.exponent(g), io.nan(g)) } }
    is(2.U) { for (i <- 0 until 64)  { val g = i / 8;  ConvertBlock_Add(i, io.exponent(g), io.nan(g)) } }
    is(3.U) { for (i <- 0 until 32)  { val g = i / 4;  ConvertBlock_Add(i, io.exponent(g), io.nan(g)) } }
    is(4.U) { for (i <- 0 until 16)  { val g = i / 2;  ConvertBlock_Add(i, io.exponent(g), io.nan(g)) } }
    is(5.U) { for (i <- 0 until 8)   { val g = i;       ConvertBlock_Add(i, io.exponent(g), io.nan(g)) } }
  }
}
