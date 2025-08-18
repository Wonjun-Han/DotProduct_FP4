package nvfp4.proposed
import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class NVFP4_ADD_DEPTH2_BLOCK_IO extends Bundle {
  val in = Input(Vec(16, SInt(10.W)))  // 4-bit mantissa + padding
  val depth = Input(UInt(4.W))            // Optional
  val out = Output(Vec(8, SInt(11.W)))       // SInt로 직접 표현
}

class nv_p_Adder_Dep_2 extends Module {
  val io = IO(new NVFP4_ADD_DEPTH2_BLOCK_IO)

  for (i <- 0 until 8) {
    val a = io.in(2 * i)
    val b = io.in(2 * i + 1)

    io.out(i) := a +& b
  }
}
