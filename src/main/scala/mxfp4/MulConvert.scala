package mxfp4

import chisel3._
import _root_.circt.stage.ChiselStage
import chisel3.util._

class FP32 extends Bundle {
  val sign     = UInt(1.W)
  val exponent = UInt(8.W)
  val mantissa = UInt(23.W)
}

class MXFP4_MulConvert_Block_IO () extends Bundle {
  val sign     = Input(Vec(256, UInt(1.W))) 
  val exponent = Input(Vec(256, UInt(3.W))) 
  val mantissa = Input(Vec(256, UInt(4.W)))
  val out = Output(Vec(256, new FP32))
}

class MulConvert extends Module {
  val io = IO(new MXFP4_MulConvert_Block_IO)
  val exponent = io.exponent
  val mantissa_four = io.mantissa
  val PE = Wire(Vec(256, UInt(2.W))) 
  val exponent_Conv = Wire(Vec(256, UInt(8.W)))
  val mantissa_Conv = Wire(Vec(256, UInt(23.W)))
  val zero = Wire(Vec(256, (Bool())))

  PE := mantissa_four.map(m => PriorityEncoder(Reverse(m)))
  zero := mantissa_four.zip(exponent).map { case (m, e) => (m === 0.U) && (e === 0.U) } 

  for (i <- 0 until 256) {
    io.out(i).sign := io.sign(i)
    val mant_shifted = (mantissa_four(i) << (20.U + PE(i)))(22, 0)
    when ((PE(i) === 0.U) && ~zero(i)) {
      exponent_Conv(i) := exponent(i) +& 126.U
      mantissa_Conv(i) := mant_shifted.asUInt(22,0)
    }.elsewhen ((PE(i) =/= 0.U) && ~zero(i)) {
      exponent_Conv(i) := exponent(i) +& 125.U
      mantissa_Conv(i) := mant_shifted.asUInt(22,0)
    }.otherwise {
      exponent_Conv(i) := 0.U(8.W)
      mantissa_Conv(i) := 0.U(23.W)
    }
    io.out(i).exponent := exponent_Conv(i)
    io.out(i).mantissa := mantissa_Conv(i)
  }
}