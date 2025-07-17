package adder

import chisel3._
import _root_.circt.stage.ChiselStage

class Adder(val width: Int) extends Module {
  val io = IO(new Bundle {
    val a   = Input(UInt(width.W))
    val b   = Input(UInt(width.W))
    val sum = Output(UInt(width.W))
  })

  io.sum := io.a + io.b
}