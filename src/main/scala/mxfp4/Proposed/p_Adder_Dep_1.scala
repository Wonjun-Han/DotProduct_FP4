package mxfp4.proposed
import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_ADD_DEPTH1_BLOCK_IO extends Bundle {
  val sign     = Input(Vec(32, UInt(1.W)))
  val mantissa = Input(Vec(32, UInt(8.W)))   // 4-bit mantissa + 4-bit padding
  val depth    = Input(UInt(3.W))            // Optional
  val out      = Output(Vec(16, SInt(10.W))) // Depth 1 → max bit width = 10
}

class p_Adder_Dep_1 extends Module {
  val io = IO(new MXFP4_ADD_DEPTH1_BLOCK_IO)

  for (i <- 0 until 16) {
    val a_sign = io.sign(2 * i)
    val b_sign = io.sign(2 * i + 1)

    val a_mag = io.mantissa(2 * i)
    val b_mag = io.mantissa(2 * i + 1)

    val a_ext = Cat(0.U(1.W), io.mantissa(2 * i)).asSInt  // 9비트로 확장
    val b_ext = Cat(0.U(1.W), io.mantissa(2 * i + 1)).asSInt

    val a_sint = Mux(io.sign(2 * i) === 1.U, -a_ext, a_ext)
    val b_sint = Mux(io.sign(2 * i + 1) === 1.U, -b_ext, b_ext)

    val sum = a_sint +& b_sint
    io.out(i) := sum

  }
}


