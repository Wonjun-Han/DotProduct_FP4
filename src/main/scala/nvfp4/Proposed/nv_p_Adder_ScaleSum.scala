package nvfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class NVFP4_ADD_SCALE_SUM extends Bundle {
  val a_scale  = Input(Vec(16, UInt(8.W)))       
  val b_scale  = Input(Vec(16, UInt(8.W)))   
  val sign = Output(Vec(16, UInt(1.W)))          // sign bit    
  val exponent = Output(Vec(16, SInt(6.W)))      // 실제 E4끼리 bias 고려해서 더하고, real exp 내보내기 (이건 마치 p_Multiplier.scala 와 비슷)
  val mantissa = Output(Vec(16, UInt(8.W)))      // 실제 mantissa 곱셈 결과 UInt (with fixed point)
  val nan      = Output(Vec(16, UInt(1.W)))       // 각 scale 합산에 대한 NaN 여부
}

class nv_p_Adder_ScaleSum extends Module {
  val io = IO(new NVFP4_ADD_SCALE_SUM)

  for (i <- 0 until 16) {
    val a = io.a_scale(i)
    val b = io.b_scale(i)
    val isNaN = (a.tail === 127.U || b.tail === 127.U)
    val sign = a.head ^ b.head
    val exponent = Wire(SInt(6.W))
    exponent := (a.tail +& b.tail - 254.S).asSInt  // 명시적으로 254 사용
    val mantissa = Wire(UInt(8.W))
    mantissa := (a.tail * b.tail).asUInt
    io.nan(i) := isNaN
    io.sign(i) := sign
    io.mantissa(i) := mantissa
    io.exponent(i) := exponent
  }
}
