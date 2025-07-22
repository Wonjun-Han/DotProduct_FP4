package mxfp4

import chisel3._
import _root_.circt.stage.ChiselStage
import chisel3.util._

class FP32 extends Bundle {
  val sign     = UInt(1.W)
  val exponent = UInt(8.W)
  val mantissa = UInt(23.W)
}

class MXFP4_AddConvert_Block_IO () extends Bundle {
  val sign     = Input(Vec(256, UInt(1.W))) 
  val exponent = Input(Vec(256, UInt(8.W))) 
  val mantissa = Input(Vec(256, UInt(25.W)))
  val depth = Input(UInt(3.W)) // Optional
  val out = Output(Vec(256, new FP32))
}

class AddConvert extends Module {
    val io = IO(new MXFP4_AddConvert_Block_IO)
    val exponent = io.exponent
    val mantissa = io.mantissa
    val sign = io.sign
    val depth = io.depth
}