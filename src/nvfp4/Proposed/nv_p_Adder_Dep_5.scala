package nvfp4.proposed
import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class NVFP4_ADD_DEPTH5_BLOCK_IO extends Bundle {
  val in = Input(Vec(2, SInt(13.W)))  
  val depth = Input(UInt(4.W))            
  val out = Output(SInt(14.W))    
}

class nv_p_Adder_Dep_5 extends Module {
  val io = IO(new NVFP4_ADD_DEPTH5_BLOCK_IO)

  for (i <- 0 until 1) {
    val a = io.in(2 * i)
    val b = io.in(2 * i + 1)

    io.out := a +& b
  }
}
