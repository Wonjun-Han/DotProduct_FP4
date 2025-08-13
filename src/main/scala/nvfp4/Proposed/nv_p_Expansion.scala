package nvfp4.proposed
import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class NVFP4_GROUP_BLOCK_IO extends Bundle {
  val sign     = Input(Vec(32, UInt(1.W)))
  val exponent = Input(Vec(32, UInt(3.W)))  // 3-bit real exponent (0~4)
  val mantissa = Input(Vec(32, UInt(4.W)))  // 4-bit mantissa
  val depth    = Input(UInt(4.W))           // Depth control (used for gating)
  val out_sign = Output(Vec(32, UInt(1.W)))
  val out_exponent_gmax = Output(Vec(1, UInt(3.W))) // Group max exponent
  val out_mantissa = Output(Vec(32, UInt(8.W)))    // Shifted mantissa (Q(2,2) + 4 bits)
}

class nv_p_Expansion extends Module { // 이제 여기서, scale에서 나온 mantissa 끼리의 곱셈도 해줘야 함. exp만은 기존처럼 scaleEmax에서 처리
  val io = IO(new NVFP4_GROUP_BLOCK_IO)
  io.out_sign := io.sign

  val max_exp = Wire(UInt(3.W))
  max_exp := io.exponent.reduce((a, b) => Mux(a > b, a, b))
  //val max_exp_clamped = Mux(max_exp > 4.U, 4.U, max_exp) // Clamp to max 4
  io.out_exponent_gmax(0) := max_exp

  for (i <- 0 until 32) {
  val shift_amt = max_exp - io.exponent(i)  // UInt(3.W)
  val extended = Cat(io.mantissa(i), 0.U(4.W)) // 8bit = 4bit mantissa + 4bit zero padding
  io.out_mantissa(i) := (extended >> shift_amt)
  }
}
