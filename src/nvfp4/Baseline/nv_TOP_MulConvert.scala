package nvfp4

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class NVFP4_TOP_MulConvert_IO extends Bundle {
  val a_vec  = Input(Vec(256, UInt(4.W)))
  val b_vec  = Input(Vec(256, UInt(4.W)))
  val depth  = Input(UInt(3.W))
  val out = Output(Vec(256, new FP32)) // This will be the RegNext output
}

class nv_TOP_MulConvert extends Module {
  val io = IO(new NVFP4_TOP_MulConvert_IO)

  val mult = Module(new nv_Multiplier)
  val conv = Module(new nv_MulConvert)

  mult.io.a_vec := io.a_vec
  mult.io.b_vec := io.b_vec
  mult.io.depth := io.depth

  conv.io.sign     := mult.io.sign
  conv.io.exponent := mult.io.exponent
  conv.io.mantissa := mult.io.mantissa

  io.out := conv.io.out
}