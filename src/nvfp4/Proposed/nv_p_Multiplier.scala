package nvfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class NVFP4_MULT_Block_IO extends Bundle {
  val a_vec  = Input(Vec(256, UInt(4.W)))
  val b_vec  = Input(Vec(256, UInt(4.W)))
  val depth  = Input(UInt(4.W))
  val sign    = Output(Vec(256, UInt(1.W))) 
  val exponent = Output(Vec(256, UInt(3.W))) 
  val mantissa = Output(Vec(256, UInt(4.W)))
}

class nv_p_Multiplier extends Module {
  val io = IO(new NVFP4_MULT_Block_IO)
  val a_extractor = Module(new nv_p_FieldExtractor)
  val b_extractor = Module(new nv_p_FieldExtractor)

  a_extractor.io.in_vec := io.a_vec
  b_extractor.io.in_vec := io.b_vec

  val a_sign     = a_extractor.io.out_vec.map(_.sign)
  val a_exp      = a_extractor.io.out_vec.map(_.exponent)
  val a_man      = a_extractor.io.out_vec.map(_.mantissa)
  val b_sign     = b_extractor.io.out_vec.map(_.sign)
  val b_exp      = b_extractor.io.out_vec.map(_.exponent)
  val b_man      = b_extractor.io.out_vec.map(_.mantissa)

  def is_zero(e: UInt, m: UInt): Bool = (e === 0.U) && (m === 0.U)
  def is_sub(e: UInt, m: UInt): Bool = (e === 0.U) && (m =/= 0.U)

  val result = (a_sign zip a_exp zip a_man zip b_sign zip b_exp zip b_man).map {
    case (((((as, ae), am), bs), be), bm) =>
      val zero = is_zero(ae, am) || is_zero(be, bm) 
      val a_sub = is_sub(ae, am)
      val b_sub = is_sub(be, bm)
      val all_sub = a_sub && b_sub
      val a_norm = ae =/= 0.U
      val b_norm = be =/= 0.U

      val sign = as ^ bs
      val mant = Mux(zero, 0.U, am * bm)
      val exp = Mux(zero, 0.U, MuxCase(0.U, Seq(
        (all_sub)                         -> 0.U,
        ((a_sub ^ b_sub) && (~all_sub))   -> ((ae +& be) - 1.U),
        ((a_norm && b_norm))              -> ((ae +& be) - 2.U)
      )))     


      (sign, exp, mant)
  }

  io.sign     := result.map(_._1)
  io.exponent := result.map(_._2)
  io.mantissa := result.map(_._3)
}
