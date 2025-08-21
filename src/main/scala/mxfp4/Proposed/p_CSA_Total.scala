package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_CSA_TOTAL_BLOCK_IO(w: Int, numInputs: Int, depth: Int) extends Bundle {
  val in = Input(Vec(numInputs, UInt(w.W)))
  val out = Output(Vec(2, UInt((w+depth+1).W))) // final output sum and carry
}

class p_CSA_Total(w:Int, numInputs: Int, depth: Int) extends Module {
  val io = IO(new p_CSA_TOTAL_BLOCK_IO(w, numInputs, depth))
  
  // 2*(numInputs / 3) + numInputs % 3 after one CSA_BUNDLE, it must be 2 at the final stage. then the number of CSA_BUNDLE is needed to be calculated
   //recursion times = num of CSA_BUNDLE. that means we need to calculate the recursion times to satisfy the last output size must be 2
  val numGroups = numInputs / 3
  val passThrough = numInputs % 3
  def calculateNumBundle(depth: Int, numInputs: Int): Int = {
    if (depth == numGroups + passThrough)
      return numGroups + passThrough
    val newNumInputs = (numInputs / 3) + (numInputs % 3)
    calculateNumBundle(depth - 1, newNumInputs)
  }
  val num_BUNDLE = calculateNumBundle(depth, numInputs)
  for (i <- 0 until num_BUNDLE) {
    val CSA_BUNDLE(i) = Module(new p_CSA_Bundle(w+num_BUNDLE, numInputs))
  }
  
  for (i <- 0 until depth) {
    val CSA_BUNDLE = Vec()
  }


}
