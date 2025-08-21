file://<WORKSPACE>/src/main/scala/mxfp4/Proposed/p_CSA_total.scala
empty definition using pc, found symbol in pc: 
semanticdb not found
empty definition using fallback
non-local guesses:
	 -chisel3/numInputs.
	 -chisel3/numInputs#
	 -chisel3/numInputs().
	 -chisel3/util/numInputs.
	 -chisel3/util/numInputs#
	 -chisel3/util/numInputs().
	 -numInputs.
	 -numInputs#
	 -numInputs().
	 -scala/Predef.numInputs.
	 -scala/Predef.numInputs#
	 -scala/Predef.numInputs().
offset: 325
uri: file://<WORKSPACE>/src/main/scala/mxfp4/Proposed/p_CSA_total.scala
text:
```scala
package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_CSA_TOTAL_BLOCK_IO(w: Int, numInputs: Int, depth: Int) extends Bundle {
  val in = Input(Vec(numInputs, UInt(w.W)))
  val sum = Output(UInt(w.W))
  val carry = Output(UInt(w.W))
}

class p_CSA_total(w:Int, numInputs@@: Int, depth: Int) extends Module {
  val io = IO(new p_CSA_TOTAL_BLOCK_IO(numInputs, depth))

  val CSA_BUNDLE = Vec(depth, Module(new p_CSA_bundle(numInputs)))



}

```


#### Short summary: 

empty definition using pc, found symbol in pc: 