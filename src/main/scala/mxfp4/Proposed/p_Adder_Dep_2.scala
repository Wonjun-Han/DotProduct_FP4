package mxfp4.proposed
import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_ADD_DEPTH2_BLOCK_IO extends Bundle {
  val in = Input(Vec(8, SInt(11.W)))  // 4-bit mantissa + padding
  val depth = Input(UInt(3.W))            // Optional
  val out = Output(Vec(4, SInt(12.W)))       // SInt로 직접 표현
}

class p_Adder_Dep_2 extends Module {
  val io = IO(new MXFP4_ADD_DEPTH2_BLOCK_IO)

  for (i <- 0 until 4) {
    val a = io.in(2 * i)
    val b = io.in(2 * i + 1)

    io.out(i) := a +& b
  }
}
