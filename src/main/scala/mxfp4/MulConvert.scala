package mxfp4

import chisel3._
import _root_.circt.stage.ChiselStage

class MXFP4_MulConvert_Block_IO () extends Bundle {
  val sign     = Input(Vec(256, UInt(1.W))) 
  val exponent = Input(Vec(256, UInt(3.W))) 
  val mantissa = Input(Vec(256, UInt(4.W)))
  val bias = Input (Vec(256, UInt(2.W))) // Bias for exponent correction
  val sign_FP32 = Output(Vec(256, UInt(1.W))) 
  val exponent_FP32 = Output(Vec(256, UInt(8.W))) 
  val mantissa_FP32 = Output(Vec(256, UInt(23.W)))
}
class MultConvert extends Module {
  val io = IO(new MXFP4_MulConvert_Block_IO)

  // Convert MXFP4 format to IEEE 754 single-precision floating-point format
  io.sign := io.sign

  io.exponent := io.exponent.map(e => e.asUInt +& 127.U) // Bias exponent by 127
  //io.mantissa := io.mantissa.map(m => Cat(0.U(19.W), m)) // Convert mantissa to 23 bits
}