package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_Adder_SUMCARRY_BLOCK_IO(w: Int) extends Bundle {
  val in  = Input(Vec(2, UInt(w.W)))  
  val sum = Output(SInt(w.W))    
}
class p_Adder_sumcarry(w: Int) extends Module {
  val io = IO(new p_Adder_SUMCARRY_BLOCK_IO(w))
  val in_SInt = io.in.map(_.asSInt)
  val s  = in_SInt(0) +& in_SInt(1)
  io.sum := s(w-1, 0).asSInt
}

