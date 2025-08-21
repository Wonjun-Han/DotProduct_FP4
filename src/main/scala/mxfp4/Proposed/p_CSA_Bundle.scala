package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_CSA_BUNDLE_BLOCK_IO(w: Int, numInputs: Int) extends Bundle {
  val in = Input(Vec(numInputs, UInt(w.W)))
  val sum = Output(Vec(numInputs/3 + numInputs % 3, UInt((w+1).W)))
  val carry = Output(Vec(numInputs/3, UInt((w+1).W)))
}

class p_CSA_Bundle (w: Int, numInputs: Int) extends Module {
  val io = IO(new p_CSA_BUNDLE_BLOCK_IO(w, numInputs))
  val numGroups = numInputs / 3
  val passThrough = numInputs % 3
  val CSA_UNIT = Seq.fill(numGroups)(Module(new p_CSA_Unit(w)))

  val sum = Wire(Vec(numInputs/3 + numInputs % 3, UInt((w+1).W)))
  val carry = Wire(Vec(numInputs/3, UInt((w+1).W)))
  // Process inputs in groups of 3
  for (i <- 0 until numGroups) {
    val groupInputs = io.in.slice(i * 3, (i + 1) * 3)
    CSA_UNIT(i).io.in := groupInputs
    sum(i) := CSA_UNIT(i).io.sum 
    carry(i) := CSA_UNIT(i).io.carry << 1
  }

  // Handle passthrough inputs
  for (j <- 0 until passThrough) {
    sum(numGroups + j) := io.in(numGroups * 3 + j)
  }

  // Connect all outputs
  for (i <- 0 until (numGroups + passThrough)) {
    io.sum(i) := sum(i)
  }
  for (i <- 0 until numGroups) {
    io.carry(i) := carry(i)
  }
}
