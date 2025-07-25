package mxfp4.piped

import chisel3._
import _root_.circt.stage.ChiselStage
import chisel3.util._

class TOP extends Module {
  val io = IO(new Bundle {
    val a   = Input(Vec(256, new MXFP4Field))
    val b   = Input(Vec(256, new MXFP4Field))
    val out = Output(Vec(1, new FP32))
  })

  for (i <- 0 until 1) {
    val a = io.a(2 * i)
    val b = io.a(2 * i + 1)

    // The rest of the code remains unchanged
    // ...
  }
}