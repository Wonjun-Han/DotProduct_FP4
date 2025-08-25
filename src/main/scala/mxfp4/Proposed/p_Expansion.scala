package mxfp4.proposed
import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_GROUP_BLOCK_IO extends Bundle {
  val sign     = Input(Vec(32, UInt(1.W)))
  val exponent = Input(Vec(32, UInt(3.W)))  // 3-bit real exponent (0~4)
  val mantissa = Input(Vec(32, UInt(4.W)))  // 4-bit mantissa
  val depth    = Input(UInt(4.W))           // Depth control (used for gating)
  val out_sign = Output(Vec(32, UInt(1.W)))
  val out_exponent_gmax = Output(Vec(1, UInt(3.W))) // Group max exponent
  val out_mantissa = Output(Vec(32, UInt(8.W)))    // Shifted mantissa (Q(2,2) + 4 bits)
}

class p_Expansion extends Module {
  val io = IO(new MXFP4_GROUP_BLOCK_IO)

  // 그대로 패스
  io.out_sign := io.sign

  // ---------------------------
  // max_exp: Tree-based reduction (O(log N))
  // ---------------------------
  def max2(a: UInt, b: UInt) = Mux(a > b, a, b)

  // 32 -> 16
  val l1 = VecInit.tabulate(16)(i => max2(io.exponent(2*i),   io.exponent(2*i+1)))
  // 16 -> 8
  val l2 = VecInit.tabulate(8 )(i => max2(l1(2*i),            l1(2*i+1)))
  // 8 -> 4
  val l3 = VecInit.tabulate(4 )(i => max2(l2(2*i),            l2(2*i+1)))
  // 4 -> 2
  val l4 = VecInit.tabulate(2 )(i => max2(l3(2*i),            l3(2*i+1)))
  // 2 -> 1
  val max_exp = max2(l4(0), l4(1))           // 네가 쓰던 이름 유지
  io.out_exponent_gmax(0) := max_exp         // Group max exponent 출력


  for (i <- 0 until 32) {
    val shift_amt = (max_exp - io.exponent(i))(2, 0)        // UInt(3.W)
    val extended  = Cat(io.mantissa(i), 0.U(4.W))           // 8bit = 4bit mantissa + 4bit zero padding
    io.out_mantissa(i) := (extended >> shift_amt)(7, 0)     // 동적 시프트(그대로 유지)
  }
}
