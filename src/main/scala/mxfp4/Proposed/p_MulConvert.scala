package mxfp4.proposed

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

class p_MulConvert extends Module {
  val io = IO(new MXFP4_MulConvert_Block_IO)
  val exponent = io.exponent
  val mantissa = io.mantissa
  val PE = Wire(Vec(256, UInt(2.W))) 
  val exponent_Conv = Wire(Vec(256, UInt(8.W)))
  val mantissa_Conv = Wire(Vec(256, UInt(23.W)))
  val zero = Wire(Vec(256, (Bool())))
  val sub = Wire(Vec(256, Bool())) 

  PE := mantissa.map(m => PriorityEncoder(Reverse(m)))
  zero := mantissa.zip(exponent).map { case (m, e) => (m === 0.U) && (e === 0.U) } 
  sub := mantissa.zip(exponent).map { case (m, e) => (m === 1.U) && (e === 0.U) }
  for (i <- 0 until 256) {
    io.out(i).sign := io.sign(i)
    val mant_shifted = (mantissa(i) << (20.U + PE(i)))(22, 0)
    when ((PE(i) === 0.U) && ~zero(i)) {
      exponent_Conv(i) := exponent(i) +& 128.U //both are definitely normal & Overflow
      mantissa_Conv(i) := mant_shifted.asUInt(22,0)
    }.elsewhen ((PE(i) === 1.U) && ~zero(i)) {
      exponent_Conv(i) := exponent(i) +& 127.U //both are definitely normal & Not Overflow
      mantissa_Conv(i) := mant_shifted.asUInt(22,0)
    }.elsewhen ((PE(i) === 2.U) && ~zero(i)){ //one is normal and the other is subnormal
      exponent_Conv(i) := exponent(i) +& 126.U
      mantissa_Conv(i) := mant_shifted.asUInt(22,0)
    }.elsewhen(sub(i)) {
        exponent_Conv(i) := exponent(i) +& 125.U //both are subnormal
        mantissa_Conv(i) := 0.U(23.W)
    }.otherwise {
      exponent_Conv(i) := 0.U(8.W) //both are zero
      mantissa_Conv(i) := 0.U(23.W)
    }
    io.out(i).exponent := exponent_Conv(i)
    io.out(i).mantissa := mantissa_Conv(i)
  }
}