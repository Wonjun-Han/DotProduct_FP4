error id: file://<WORKSPACE>/src/main/scala/mxfp4/Proposed/p_CSA_total.scala:p_CSA_bundle
file://<WORKSPACE>/src/main/scala/mxfp4/Proposed/p_CSA_total.scala
empty definition using pc, found symbol in pc: 
semanticdb not found

found definition using fallback; symbol p_CSA_bundle
offset: 455
uri: file://<WORKSPACE>/src/main/scala/mxfp4/Proposed/p_CSA_total.scala
text:
```scala
package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_CSA_TOTAL_BLOCK_IO(numInputs: Int, depth: Int) extends Bundle {
  val in = Input(Vec(numInputs, UInt(8.W)))
  val sum = Output(UInt(8.W))
  val carry = Output(UInt(8.W))
}

class p_CSA_total(numInputs: Int, depth: Int) extends Module {
  val io = IO(new p_CSA_TOTAL_BLOCK_IO(numInputs, depth))

  val CSA_BUNDLE = Vec(depth, Module(new p_CSA_bun@@dle(numInputs)))
}

```


#### Short summary: 

empty definition using pc, found symbol in pc: 