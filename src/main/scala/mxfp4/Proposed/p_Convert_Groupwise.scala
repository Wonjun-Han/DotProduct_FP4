package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_CONVERT_GROUPWISE_BLOCK_IO(depthBitWidth: Int, accWidth: Int, vecSize: Int, absWidth: Int) extends Bundle {
  val depth    = Input(UInt(depthBitWidth.W))
  val in       = Input(Vec(vecSize, SInt(accWidth.W)))
  val nan      = Input(Vec(8, UInt(1.W)))
  val exponent = Input(Vec(8, SInt(10.W)))
  val out      = Output(Vec(vecSize, new FP32))

  // Debug ports
  val debug_real_exp   = Output(Vec(vecSize, SInt(10.W)))
  val debug_biased_exp = Output(Vec(vecSize, SInt(10.W)))
  val debug_shift_amt  = Output(Vec(vecSize, SInt(5.W)))
  val debug_PE         = Output(Vec(vecSize, UInt(4.W)))
  val debug_abs_in     = Output(Vec(vecSize, UInt(absWidth.W)))
}

class p_Convert_Groupwise(val d: Int, val extra: Int) extends Module {
  val accWidth = 9 + d + extra
  val vecSize = 256 >> d
  val absWidth = 8 + d + extra
 
  val io = IO(new MXFP4_CONVERT_GROUPWISE_BLOCK_IO(depthBitWidth = 3, accWidth = accWidth, vecSize = vecSize, absWidth = absWidth))

  val enable_depth = io.depth === d.U
  val groupSize = vecSize / 8

  for (i <- 0 until vecSize) {
    val input = io.in(i)
    val sign_bit     = Mux(input < 0.S, 1.U, 0.U)
    val abs_val_full = Mux(input < 0.S, -input, input).asUInt
    val abs_val      = abs_val_full(absWidth - 1, 0)

    val PE = PriorityEncoder(Reverse(abs_val))
    val shift_amt = (d + 1).S - PE.asSInt
    val extended_mantissa = Cat(abs_val, 0.U(17.W))

    val groupIdx = i / groupSize
    val real_exp   = io.exponent(groupIdx) + shift_amt
    val biased_exp = real_exp + 127.S

    val exponent_conv = Wire(UInt(8.W))
    val mantissa_conv = Wire(UInt(23.W))
    val nan = io.nan(groupIdx)

    when(nan === 1.U) {
      exponent_conv := 255.U
      mantissa_conv := 4194304.U
    }.elsewhen(io.in(i) === 0.S) {
      exponent_conv := 0.U
      mantissa_conv := 0.U
    }.elsewhen(real_exp >= 128.S) {
      exponent_conv := 255.U
      mantissa_conv := 0.U
    }.elsewhen(biased_exp <= 0.S) {
      exponent_conv := 0.U
      val sub_shift = (shift_amt.abs.asUInt - (1.S - biased_exp).asUInt).asSInt
      mantissa_conv := Mux(sub_shift >= 0.S,
        (extended_mantissa << sub_shift.asUInt)(22, 0),
        (extended_mantissa >> sub_shift.abs.asUInt)(22, 0)
      )
    }.otherwise {
      exponent_conv := biased_exp.asUInt
      mantissa_conv := Mux(shift_amt >= 0.S,
        (extended_mantissa >> shift_amt.asUInt)(22, 0),
        (extended_mantissa << shift_amt.abs.asUInt)(22, 0)
      )
    }

    when(enable_depth) {
      io.out(i).sign     := Mux(nan === 1.U, 0.U, sign_bit)
      io.out(i).exponent := exponent_conv
      io.out(i).mantissa := mantissa_conv
    }.otherwise {
      io.out(i).sign     := 0.U
      io.out(i).exponent := 0.U
      io.out(i).mantissa := 0.U
    }

    io.debug_real_exp(i)   := real_exp
    io.debug_biased_exp(i) := biased_exp
    io.debug_shift_amt(i)  := shift_amt
    io.debug_PE(i)         := PE
    io.debug_abs_in(i)     := abs_val
  }
}

