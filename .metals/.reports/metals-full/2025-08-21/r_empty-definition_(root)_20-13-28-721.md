file://<WORKSPACE>/src/main/scala/mxfp4/Proposed/p_CSA_bundle.scala
empty definition using pc, found symbol in pc: 
semanticdb not found
empty definition using fallback
non-local guesses:
	 -chisel3/CSA_UNIT.
	 -chisel3/CSA_UNIT#
	 -chisel3/CSA_UNIT().
	 -chisel3/util/CSA_UNIT.
	 -chisel3/util/CSA_UNIT#
	 -chisel3/util/CSA_UNIT().
	 -CSA_UNIT.
	 -CSA_UNIT#
	 -CSA_UNIT().
	 -scala/Predef.CSA_UNIT.
	 -scala/Predef.CSA_UNIT#
	 -scala/Predef.CSA_UNIT().
offset: 544
uri: file://<WORKSPACE>/src/main/scala/mxfp4/Proposed/p_CSA_bundle.scala
text:
```scala
package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_CSA_BUNDLE_BLOCK_IO(w: Int, numInputs: Int) extends Bundle {
  val in = Input(Vec(numInputs, UInt(w.W)))
  val sum = Output(Vec(numInputs/3 + numInputs % 3, UInt(w.W)))
  val carry = Output(Vec(numInputs/3 + numInputs % 3, UInt(w.W)))
}

class p_CSA_bundle (w: Int, numInputs: Int) extends Module {
  val io = IO(new p_CSA_BUNDLE_BLOCK_IO(w, numInputs))
  val numGroups = numInputs / 3
  val passThrough = numInputs % 3
  val CSA_UNIT@@ = Seq.fill(numGroups)(Module(new p_CSA_unit(w)))

  val sum = Wire(Vec(numInputs/3 + numInputs % 3, UInt(w.W)))
  val carry = Wire(Vec(numInputs/3 + numInputs % 3, UInt(w.W)))
  // Process inputs in groups of 3
  for (i <- 0 until numGroups) {
    val groupInputs = io.in.slice(i * 3, (i + 1) * 3)
    CSA_UNIT(i).io.in := groupInputs
    sum(i) := CSA_UNIT(i).io.sum
    carry(i) := CSA_UNIT(i).io.carry
  }

  // Handle passthrough inputs
  for (j <- 0 until passThrough) {
    sum(numGroups + j) := io.in(numGroups * 3 + j)
    carry(numGroups + j) := 0.U
  }

  // Connect all outputs
  for (i <- 0 until (numGroups + passThrough)) {
    io.sum(i) := sum(i)
    io.carry(i) := carry(i)
  }
}

```


#### Short summary: 

empty definition using pc, found symbol in pc: 