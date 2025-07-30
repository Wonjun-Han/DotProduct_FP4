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
  val exponent_Conv = Wire(Vec(256, UInt(8.W)))
  val mantissa_Conv = Wire(Vec(256, UInt(23.W)))
  val zero = Wire(Vec(256, (Bool())))
  val sub = Wire(Vec(256, Bool())) 
  val scale_sum = io.scale_sum

  PE := mantissa.map(m => PriorityEncoder(Reverse(m)))
  zero := mantissa.zip(exponent).map { case (m, e) => (m === 0.U) && (e === 0.U) } 
  sub := mantissa.zip(exponent).map { case (m, e) => (m === 1.U) && (e === 0.U) }
  for (i <- 0 until 256) {
    io.out(i).sign := Mux(io.nan(i/32) === 1.U, 0.U, io.sign(i))
    //val mant_shifted = (mantissa(i) << (20.U + PE(i)))(22, 0)
    val extended_mantissa = Cat(mantissa(i), 0.U(21.W))
    val shift_amt = (1.S - PE(i).asSInt).asSInt
    val real_exp = scale_sum(i/32) + shift_amt + exponent(i).zext.asSInt 
    val biased_exp = real_exp + 127.S

    when (io.nan(i/32) === 1.U) {
      exponent_Conv(i) := 255.U(8.W) // NaN 처리
      mantissa_Conv(i) := 4194304.U(23.W) // NaN mantissa
    }.elsewhen(real_exp >= 128.S){ //overflow after considering scale_sum
      exponent_Conv(i) := 255.U(8.W)
      mantissa_Conv(i) := 0.U(23.W) // overflow mantissa
    }.elsewhen(biased_exp <= 0.S){ //underflow after considering scale_sum
      exponent_Conv(i) := 0.U(8.W)
      val sub_shift = (1.S - biased_exp).asUInt
      mantissa_Conv(i) := (extended_mantissa >> sub_shift)(22, 0)
    }.otherwise {
      exponent_Conv(i) := biased_exp.asUInt
      mantissa_Conv(i) := Mux(shift_amt >= 0.S,
        (extended_mantissa >> shift_amt.asUInt)(22, 0),
        (extended_mantissa << shift_amt.abs.asUInt)(22, 0)
      )
    }
    //0 처리에 신경 써야 함. (이건 이제 해야 할 일)
    /*
    .elsewhen ((PE(i) === 0.U) && ~zero(i)) {
      exponent_Conv(i) := exponent(i) +& 128.U //both are definitely normal
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
    */
    io.out(i).exponent := exponent_Conv(i)
    io.out(i).mantissa := mantissa_Conv(i)
  }
}