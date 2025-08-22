package mxfp4.proposed

import chisel3._
import chisel3.util._

class MUL_LUT_2D_BLOCK_IO extends Bundle {
  val sign     = Input(Vec(256, UInt(1.W))) 
  val mantissa = Input(Vec(256, UInt(4.W))) // 0..9 
  val exponent = Input(Vec(256, UInt(3.W))) // 0..4  
  val out      = Output(Vec(256, UInt(9.W))) // 2's complement, ±144 커버
}

// 2D-ROM LUT: table(e)(m) = (m << e), sign 반영해 2's complement로 출력
class p_LUT_2D extends Module {
  val io = IO(new MUL_LUT_2D_BLOCK_IO)

  val MAX_M = 9
  val MAX_E = 4

  // 5 x 10 테이블 (폭 9비트로 고정)
  private val table2d = VecInit((0 to MAX_E).map { e =>
    VecInit((0 to MAX_M).map { m =>
      (m << e).U(9.W) // 미리 계산된 상수
    })
  })

  for (i <- 0 until 256) {
    val m = io.mantissa(i) // 0..9
    val e = io.exponent(i) // 0..4

    val valid = (m <= MAX_M.U) && (e <= MAX_E.U)
    val mag   = table2d(e)(m) // 9-bit magnitude (0..144)

    // sign==1이면 2의 보수로 부호 반전: (~mag + 1) (9비트 유지)
    val neg   = ((~mag).asUInt + 1.U(9.W))(8, 0)
    val twos  = Mux(io.sign(i).asBool, neg, mag)

    io.out(i) := Mux(valid, twos, 0.U(9.W))
  }
}
