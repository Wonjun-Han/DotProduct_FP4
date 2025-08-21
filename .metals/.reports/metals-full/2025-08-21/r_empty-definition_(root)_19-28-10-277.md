error id: file://<WORKSPACE>/src/main/scala/mxfp4/Proposed/p_LUT_2D.scala.scala:MUL_LUT_BLOCK_IO
file://<WORKSPACE>/src/main/scala/mxfp4/Proposed/p_LUT_2D.scala.scala
empty definition using pc, found symbol in pc: 
semanticdb not found

found definition using fallback; symbol MUL_LUT_BLOCK_IO
offset: 454
uri: file://<WORKSPACE>/src/main/scala/mxfp4/Proposed/p_LUT_2D.scala.scala
text:
```scala
package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MUL_LUT_2D_BLOCK_IO extends Bundle {
  val mantissa = Input(Vec(256, UInt(4.W))) // 0..9 유효 (10~15 미사용)
  val exponent = Input(Vec(256, UInt(3.W))) // 0..4 유효 (5~7 미사용)
  val out      = Output(Vec(256, UInt(8.W))) // 최대 9<<4=144 → 8bit 충분
}

/** 2D-ROM LUT: table(e)(m) = (m << e) */
class p_LUT_2D extends Module {
  val io = IO(new MUL_LUT_BLOC@@K_IO)

  val MAX_M = 9
  val MAX_E = 4

  // 5×10 테이블을 Scala 상수로 생성 (합성 시 콤비네이셔널 ROM으로 고정)
  private val table2d = VecInit((0 to MAX_E).map { e =>
    VecInit((0 to MAX_M).map { m =>
      (m << e).U(8.W) // 미리 계산된 상수
    })
  })

  for (i <- 0 until 256) {
    val m = io.mantissa(i) // 4비트 인덱스, Vec(10) → log2Ceil(10)=4 OK
    val e = io.exponent(i) // 3비트 인덱스, Vec(5)  → log2Ceil(5)=3  OK

    val valid = (m <= MAX_M.U) && (e <= MAX_E.U)
    val dout  = table2d(e)(m)   // 2단계 선택

    io.out(i) := Mux(valid, dout, 0.U)

    // io.out(i) := RegNext(Mux(valid, dout, 0.U))
  }
}


```


#### Short summary: 

empty definition using pc, found symbol in pc: 