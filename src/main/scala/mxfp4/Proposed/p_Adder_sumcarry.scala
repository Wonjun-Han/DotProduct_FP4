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
  // 선택: 포화 설계면 다음이 항상 참일거임. 그 이유는, 음.. CSA를 all reduce 한다고 보면, bit가 더 늘어나게 되고, 이를 굳이 늘릴 필요가 없음. 수학적으로 bound 되어 있음.
}

