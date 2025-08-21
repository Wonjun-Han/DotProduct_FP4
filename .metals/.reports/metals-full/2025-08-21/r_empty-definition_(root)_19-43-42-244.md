file://<WORKSPACE>/src/main/scala/mxfp4/Proposed/p_CSA_bundle.scala.scala
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
offset: 273
uri: file://<WORKSPACE>/src/main/scala/mxfp4/Proposed/p_CSA_bundle.scala.scala
text:
```scala
package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_CSA_BUNDLE_BLOCK_IO extends Bundle {
  val in = Input(Vec(numInputs, UInt(8.W)))
  val sum = Output(Vec(numInputs/3 + 1, UInt(8.W)))
  val carry = Output(Vec(numIn@@puts/3 + 1, UInt(8.W)))
}

```


#### Short summary: 

empty definition using pc, found symbol in pc: 