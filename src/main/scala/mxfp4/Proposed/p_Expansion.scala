package mxfp4.proposed
import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_GROUP_BLOCK_IO extends Bundle {
  val sign     = Input(Vec(32, UInt(1.W)))
  val exponent = Input(Vec(32, UInt(3.W)))  // 3-bit real exponent (0~4)
  val mantissa = Input(Vec(32, UInt(4.W)))  // 4-bit mantissa
  val depth    = Input(UInt(3.W))           // Depth control (used for gating)
  val out_sign = Output(Vec(32, UInt(1.W)))
  val out_exponent_gmax = Output(Vec(1, UInt(3.W))) // Group max exponent
  val out_mantissa = Output(Vec(32, UInt(8.W)))    // Shifted mantissa (Q(2,2) + 4 bits)
}

class p_Expansion extends Module {
  val io = IO(new MXFP4_GROUP_BLOCK_IO)
  io.out_sign := io.sign

  val max_exp = io.exponent.reduce((a, b) => Mux(a > b, a, b))
  io.out_exponent_gmax(0) := max_exp

  for (i <- 0 until 32) {
  val shift_amt = max_exp - io.exponent(i)  // UInt(3.W)
  val extended = Cat(io.mantissa(i), 0.U(4.W)) // 8bit = 4bit mantissa + 4bit zero padding
  io.out_mantissa(i) := (extended >> shift_amt)
  }
}
