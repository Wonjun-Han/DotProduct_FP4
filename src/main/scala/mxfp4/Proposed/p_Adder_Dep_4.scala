package mxfp4.proposed
import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_ADD_DEPTH4_BLOCK_IO extends Bundle {
  val in = Input(Vec(4, SInt(12.W)))  
  val depth = Input(UInt(3.W))            
  val out = Output(Vec(2, SInt(13.W)))      
}

class p_Adder_Dep_4 extends Module {
  val io = IO(new MXFP4_ADD_DEPTH4_BLOCK_IO)

  for (i <- 0 until 2) {
    val a = io.in(2 * i)
    val b = io.in(2 * i + 1)

    io.out(i) := a +& b
  }
}
