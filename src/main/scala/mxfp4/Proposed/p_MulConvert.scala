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
  val scale_sum = Input(Vec(8, SInt(9.W))) // Scale 합산 결과
  val nan      = Input(Vec(8, UInt(1.W))) // NaN 여부 flag
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
  val zero = Wire(Vec(256, (Bool())))
  val sub = Wire(Vec(256, Bool())) 
  val scale_sum = io.scale_sum

  PE := mantissa.map(m => PriorityEncoder(Reverse(m)))
  zero := mantissa.zip(exponent).map { case (m, e) => (m === 0.U) && (e === 0.U) } 
  sub := mantissa.zip(exponent).map { case (m, e) => (m === 1.U) && (e === 0.U) }
  for (i <- 0 until 256) {
    // ---------------------
    val extended_mantissa = Cat(mantissa(i), 0.U(21.W))
    val shift_amt = (1.S - PE(i).asSInt).asSInt
    val real_exp = scale_sum(i/32) + shift_amt + exponent(i).zext.asSInt 
    val biased_exp = real_exp + 127.S
    val exponent_conv = Wire(UInt(8.W))
    val mantissa_conv = Wire(UInt(23.W))
    when (io.nan(i/32) === 1.U) {
      exponent_conv := 255.U(8.W) // NaN 처리
      mantissa_conv := 4194304.U(23.W) // NaN mantissa
    }.elsewhen(real_exp >= 128.S){ //overflow after considering scale_sum
      exponent_conv := 255.U(8.W)
      mantissa_conv := 0.U(23.W) // overflow mantissa
    }.elsewhen(biased_exp <= 0.S){ //underflow after considering scale_sum
      exponent_conv := 0.U(8.W)
      val sub_shift = (1.S - biased_exp).asUInt
      mantissa_conv := (extended_mantissa >> sub_shift)(22, 0)
    }.otherwise {
      exponent_conv := biased_exp.asUInt
      mantissa_conv := Mux(shift_amt >= 0.S,
        (extended_mantissa >> shift_amt.asUInt)(22, 0),
        (extended_mantissa << shift_amt.abs.asUInt)(22, 0)
      )
    }
    io.out(i).sign := Mux(io.nan(i/32) === 1.U, 0.U, io.sign(i))
    io.out(i).exponent := exponent_conv
    io.out(i).mantissa := mantissa_conv
  }
}