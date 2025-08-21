error id: file://<WORKSPACE>/src/main/scala/mxfp4/Proposed/p_CSA_bundle.scala.scala:W
file://<WORKSPACE>/src/main/scala/mxfp4/Proposed/p_CSA_bundle.scala.scala
empty definition using pc, found symbol in pc: 
semanticdb not found

found definition using fallback; symbol W
offset: 286
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
  val carry = Output(Vec(numInputs, UInt(8.@@W)))
}

```


#### Short summary: 

empty definition using pc, found symbol in pc: 