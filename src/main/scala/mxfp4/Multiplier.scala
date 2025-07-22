
package mxfp4

import chisel3._
import _root_.circt.stage.ChiselStage

class MXFP4_MULT_Block_IO extends Bundle {
  val a_vec  = Input(Vec(256, UInt(4.W)))
  val b_vec  = Input(Vec(256, UInt(4.W)))
  val depth  = Input(UInt(3.W))
  val sign    = Output(Vec(256, UInt(1.W))) 
  val exponent = Output(Vec(256, UInt(3.W))) 
  val mantissa = Output(Vec(256, UInt(4.W)))
}

class Multiplier extends Module {
  val io = IO(new MXFP4_MULT_Block_IO)
  val a_extractor = Module(new FieldExtractor)
  val b_extractor = Module(new FieldExtractor)

  a_extractor.io.in_vec := io.a_vec
  val a_sign     = a_extractor.io.out_vec.map(_.sign)
  val a_exponent = a_extractor.io.out_vec.map(_.exponent)
  val a_mantissa = a_extractor.io.out_vec.map(_.mantissa)
  
  b_extractor.io.in_vec := io.b_vec
  val b_sign     = b_extractor.io.out_vec.map(_.sign)
  val b_exponent = b_extractor.io.out_vec.map(_.exponent)
  val b_mantissa = b_extractor.io.out_vec.map(_.mantissa)
  val a_zero = a_exponent.zip(a_mantissa).map { case (e, m) => (e === 0.U) && (m === 0.U) }
  val b_zero = b_exponent.zip(b_mantissa).map { case (e, m) => (e === 0.U) && (m === 0.U) }
  val a_norm = a_exponent.zip(a_mantissa).map { case (e, m) => (e =/= 0.U) }
  val b_norm = b_exponent.zip(b_mantissa).map { case (e, m) => (e =/= 0.U) }

  val sign_mul = Wire(Vec(256, UInt(1.W))) 
  val exponent_mul = Wire(Vec(256, UInt(3.W))) 
  val mantissa_mul = Wire(Vec(256, UInt(4.W))) 
  sign_mul := (a_sign.zip(b_sign)).map { case (a, b) => a ^ b }
  exponent_mul := (a_zero zip b_zero zip a_exponent zip b_exponent).map {
    case (((az, bz), ae), be) =>
      Mux(az || bz, 0.U, ae +& be)
  }
  mantissa_mul := (a_zero zip b_zero zip a_mantissa zip b_mantissa).map {
    case (((az, bz), am), bm) =>
      Mux(az || bz, 0.U, am * bm)
  } 
  io.sign := sign_mul
  io.exponent := exponent_mul
  io.mantissa := mantissa_mul
}
