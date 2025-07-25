package mxfp4.piped

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage
import mxfp4._



class Multiplier_IO extends Bundle {
  val a_vec = Input(Vec(256, UInt(4.W)))
  val b_vec = Input(Vec(256, UInt(4.W)))
  val sign = Output(Vec(256, UInt(1.W)))
  val exponent = Output(Vec(256, UInt(3.W)))
  val mantissa = Output(Vec(256, UInt(4.W)))
}

class p_Multiplier extends Module {
  val io = IO(new Multiplier_IO)

  val a_vec_s1 = RegNext(io.a_vec)
  val b_vec_s1 = RegNext(io.b_vec)

  val a_sign_s1     = a_vec_s1.map(_(3))
  val a_exponent_s1 = a_vec_s1.map(_(2, 1))
  val a_mantissa_s1 = a_vec_s1.map(_(0))

  val b_sign_s1     = b_vec_s1.map(_(3))
  val b_exponent_s1 = b_vec_s1.map(_(2, 1))
  val b_mantissa_s1 = b_vec_s1.map(_(0))

  val sign_s1       = a_sign_s1.zip(b_sign_s1).map { case (a, b) => a ^ b }
  val exponent_s1   = a_exponent_s1.zip(b_exponent_s1).map { case (a, b) => a +& b }
  val mantissa_raw  = a_mantissa_s1.zip(b_mantissa_s1).map { case (a, b) => a * b }

  val a_zero_s1     = a_mantissa_s1.zip(a_exponent_s1).map { case (m, e) => (m === 0.U) && (e === 0.U) }
  val b_zero_s1     = b_mantissa_s1.zip(b_exponent_s1).map { case (m, e) => (m === 0.U) && (e === 0.U) }

  val sign_s2       = RegNext(VecInit(sign_s1))
  val a_zero_s2     = RegNext(VecInit(a_zero_s1))
  val b_zero_s2     = RegNext(VecInit(b_zero_s1))
  val exponent_s2   = RegNext(VecInit(exponent_s1))
  val mantissa_s2   = RegNext(VecInit(mantissa_raw.map(x => x(3, 0))))

  for (i <- 0 until 256) {
    io.sign(i) := Mux(a_zero_s2(i) || b_zero_s2(i), 0.U, sign_s2(i))
    io.exponent(i) := Mux(a_zero_s2(i) || b_zero_s2(i), 0.U, exponent_s2(i))
    io.mantissa(i) := Mux(a_zero_s2(i) || b_zero_s2(i), 0.U, mantissa_s2(i))
  }
}