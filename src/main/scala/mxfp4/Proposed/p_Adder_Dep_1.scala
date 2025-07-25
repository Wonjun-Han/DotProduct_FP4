package mxfp4.proposed
import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_ADD_DEPTH1_BLOCK_IO extends Bundle {
  val in = Input(Vec(16, SInt(10.W)))  // 4-bit mantissa + padding
  val depth = Input(UInt(3.W))            // Optional
  val out = Output(Vec(8, SInt(11.W)))       // SInt로 직접 표현
}

class p_Adder_Dep_1 extends Module {
  val io = IO(new MXFP4_ADD_DEPTH1_BLOCK_IO)

  for (i <- 0 until 8) {
    val a = io.in(2 * i)
    val b = io.in(2 * i + 1)

    io.out(i) := a +& b
  }
}
