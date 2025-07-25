package mxfp4.proposed
import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_ADD_DEPTH3_BLOCK_IO extends Bundle {
  val sign     = Input(Vec(4, UInt(1.W)))
  val mantissa = Input(Vec(4, UInt(8.W)))   // 4-bit mantissa + padding
  val depth    = Input(UInt(3.W))            // Optional
  val out = Output(Vec(2, SInt(9.W)))       // SInt로 직접 표현
}

class p_Adder_Dep_3 extends Module {
  val io = IO(new MXFP4_ADD_DEPTH3_BLOCK_IO)

  for (i <- 0 until 16) {
    val a_sign = io.sign(2 * i)
    val b_sign = io.sign(2 * i + 1)
    val a_mag = io.mantissa(2 * i)
    val b_mag = io.mantissa(2 * i + 1)

    val a_sint = Mux(a_sign === 1.U, (~a_mag).asSInt + 1.S, a_mag.asSInt)
    val b_sint = Mux(b_sign === 1.U, (~b_mag).asSInt + 1.S, b_mag.asSInt)

    io.out(i) := a_sint +& b_sint
  }
}
