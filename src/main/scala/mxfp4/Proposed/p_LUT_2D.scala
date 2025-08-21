package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MUL_LUT_2D_BLOCK_IO extends Bundle {
  val mantissa = Input(Vec(256, UInt(4.W))) // 0..9 
  val exponent = Input(Vec(256, UInt(3.W))) // 0..4  
  val out      = Output(Vec(256, UInt(8.W))) // 최대 9<<4=144, Maximum 8bit 
}

//2D-ROM LUT: table(e)(m) = (m << e)
class p_LUT_2D extends Module {
  val io = IO(new MUL_LUT_2D_BLOCK_IO)

  val MAX_M = 9
  val MAX_E = 4

  // 5*10 테이블
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

