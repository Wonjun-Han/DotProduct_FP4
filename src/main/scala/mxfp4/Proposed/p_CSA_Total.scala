package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_CSA_TOTAL_BLOCK_IO(w: Int, numInputs: Int, depth: Int) extends Bundle {
  val in = Input(Vec(numInputs, UInt(w.W)))
  val sum = Output(UInt(w.W))
  val carry = Output(UInt(w.W))
}

class p_CSA_Total(w:Int, numInputs: Int, depth: Int) extends Module {
  val io = IO(new p_CSA_TOTAL_BLOCK_IO(w, numInputs, depth))

}
