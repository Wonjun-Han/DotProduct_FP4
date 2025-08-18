package nvfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class TOP_MulConvert_IO extends Bundle {
  val a_vec  = Input(Vec(256, UInt(4.W)))
  val b_vec  = Input(Vec(256, UInt(4.W)))
  val depth  = Input(UInt(4.W))
  val out = Output(Vec(256, new FP32)) // This will be the RegNext output
}

class nv_p_TOP_MulConvert extends Module {
  val io = IO(new TOP_MulConvert_IO)

  val mult = Module(new nv_p_Multiplier)
  val conv = Module(new nv_p_MulConvert)

  mult.io.a_vec := io.a_vec
  mult.io.b_vec := io.b_vec
  mult.io.depth := io.depth

  conv.io.sign     := mult.io.sign
  conv.io.exponent := mult.io.exponent
  conv.io.mantissa := mult.io.mantissa

  io.out := conv.io.out
}