package mxfp4

import chisel3._
import _root_.circt.stage.ChiselStage
import chisel3.util._

class FP32 extends Bundle {
  val sign = UInt(1.W)
  val exponent = UInt(8.W)
  val mantissa = UInt(23.W)
}
class TOP extends Module {
  val io = IO(new Bundle {
    val a   = Input(Vec(256, new MXFP4))
    val b   = Input(Vec(256, new MXFP4))
    val out = Output(Vec(1, new FP32))
  })

  for (i <- 0 until 1) {
    val a = io.a(2 * i)
    val b = io.a(2 * i + 1)

    // The rest of the code remains unchanged
    // ...
  }
}