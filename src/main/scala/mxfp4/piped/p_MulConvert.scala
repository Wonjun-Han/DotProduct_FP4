package mxfp4.piped
import mxfp4._
import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage


class MXFP4_MulConvert_Block_IO () extends Bundle {
  val sign     = Input(Vec(256, UInt(1.W)))
  val exponent = Input(Vec(256, UInt(3.W)))
  val mantissa = Input(Vec(256, UInt(4.W)))
  val out = Output(Vec(256, new FP32))
}

class p_MulConvert extends Module {
  val io = IO(new MXFP4_MulConvert_Block_IO)

  val pe_s1   = io.mantissa.map(m => PriorityEncoder(Reverse(m)))
  val zero_s1 = io.mantissa.zip(io.exponent).map { case (m, e) => (m === 0.U) && (e === 0.U) }

  val pe_s2       = RegNext(VecInit(pe_s1))
  val zero_s2     = RegNext(VecInit(zero_s1))
  val sign_s2     = RegNext(VecInit(io.sign.toSeq))
  val exponent_s2 = RegNext(VecInit(io.exponent.toSeq))
  val mantissa_s2 = RegNext(VecInit(io.mantissa.toSeq))

  val exponent_Conv = Wire(Vec(256, UInt(8.W)))
  val mantissa_Conv = Wire(Vec(256, UInt(23.W)))

  for (i <- 0 until 256) {
    val mant_shifted = (mantissa_s2(i) << (20.U + pe_s2(i)))(22, 0)
    when ((pe_s2(i) === 0.U) && ~zero_s2(i)) {
      exponent_Conv(i) := exponent_s2(i) +& 126.U
      mantissa_Conv(i) := mant_shifted
    }.elsewhen ((pe_s2(i) =/= 0.U) && ~zero_s2(i)) {
      exponent_Conv(i) := exponent_s2(i) +& 125.U
      mantissa_Conv(i) := mant_shifted
    }.otherwise {
      exponent_Conv(i) := 0.U
      mantissa_Conv(i) := 0.U
    }

    io.out(i).sign     := sign_s2(i)
    io.out(i).exponent := exponent_Conv(i)
    io.out(i).mantissa := mantissa_Conv(i)
  }
}
