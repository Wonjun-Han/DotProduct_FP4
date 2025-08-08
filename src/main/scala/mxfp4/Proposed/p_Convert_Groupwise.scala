package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_CONVERT_GROUPWISE_BLOCK_IO(depthBitWidth: Int, mantissaWidth: Int, vecSize: Int) extends Bundle {
  val depth    = Input(UInt(depthBitWidth.W))
  val mantissa = Input(Vec(vecSize, UInt(mantissaWidth.W)))
  val sign     = Input(Vec(vecSize, UInt(1.W)))
  val nan      = Input(Vec(8, UInt(1.W))) // special logic for NaN handling (not ready) - bitwise OR;
  val exponent = Input(Vec(vecSize, SInt(10.W)))

  val out      = Output(Vec(vecSize, new FP32))

  // Debug ports
  val debug_real_exp   = Output(Vec(vecSize, SInt(10.W)))
  val debug_biased_exp = Output(Vec(vecSize, SInt(10.W)))
  val debug_shift_amt  = Output(Vec(vecSize, SInt(7.W)))
  val debug_PE         = Output(Vec(vecSize, UInt(6.W)))
}

class p_Convert_Groupwise(val d: Int, val extra: Int) extends Module {
  val mantissaWidth = 8 + d + extra
  val vecSize = 256 >> d // depth 6 : 4, depth 7 : 2, depth 8 : 1
 
  val io = IO(new MXFP4_CONVERT_GROUPWISE_BLOCK_IO(depthBitWidth = 4, mantissaWidth = mantissaWidth, vecSize = vecSize))

  val enable_depth = io.depth === d.U
  val groupSize = 8 / vecSize // depth 6: 2, depth 7: 4, depth 8: 8

  for (i <- 0 until vecSize) {
    val abs_val = io.mantissa(i)
    val PE = PriorityEncoder(Reverse(abs_val))
    val shift_amt = (d + 1).S - PE.asSInt

    val rounded = Wire(UInt(mantissaWidth.W))
    // Rounding logic
    val guard_bit = abs_val(6+extra-23-1)
    val round_bit = abs_val(6+extra-23-2)
    val sticky_bit = abs_val(6+extra-23-3, 0).orR
    val lsb_bit    = abs_val(6+extra-23)
    when(guard_bit === 1.U && (round_bit === 1.U || sticky_bit === 1.U)) {
      // Rule 1: G=1 and (R or S)=1 → always round up
      rounded := abs_val + 1.U
    }.elsewhen(guard_bit === 1.U && round_bit === 0.U && sticky_bit === 0.U && lsb_bit === 1.U) {
      // Rule 2: tie, LSB is 1 (odd) → round to even (up)
      rounded := abs_val + 1.U
    }.otherwise {
      // Rule 3: all other cases → no rounding (keep as is)
      rounded := abs_val
    }

    // Exponent Calculation from Group Exponent from Output from Expansion Module
    val groupIdx = i / groupSize // depth 6: 4, depth 7: 2, depth 8: 1
    val real_exp  = io.exponent(groupIdx) + shift_amt
    val biased_exp = real_exp + 127.S

    val exponent_conv = Wire(UInt(8.W))
    val mantissa_conv = Wire(UInt(23.W))
    val nan = io.nan(groupIdx)

    when(nan === 1.U) {
      exponent_conv := 255.U
      mantissa_conv := 4194304.U
    }.elsewhen(io.mantissa(i) === 0.U) {
      exponent_conv := 0.U
      mantissa_conv := 0.U
    }.elsewhen(real_exp >= 128.S) {
      exponent_conv := 255.U
      mantissa_conv := 0.U
    }.elsewhen(biased_exp <= 0.S) {
      exponent_conv := 0.U
      val sub_shift = (shift_amt.abs.asUInt - (1.S - biased_exp).asUInt).asSInt
      mantissa_conv := Mux(sub_shift >= 0.S,
        (rounded << sub_shift.asUInt)(22, 0),
        (rounded >> sub_shift.abs.asUInt)(22, 0)
      )
    }.otherwise {
      exponent_conv := biased_exp.asUInt
      mantissa_conv := Mux(shift_amt >= 0.S,
        (rounded >> shift_amt.asUInt)(22, 0),
        (rounded << shift_amt.abs.asUInt)(22, 0)
      )
    }

    when(enable_depth) {
      io.out(i).sign     := Mux(nan === 1.U, 0.U, io.sign(i))
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
  }
}

