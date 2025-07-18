package mxfp4

import chisel3._
import _root_.circt.stage.ChiselStage

class MXFP4_DP_Block_IO extends Bundle {
  val a_vec  = Input(Vec(256, UInt(4.W)))
  val b_vec  = Input(Vec(256, UInt(4.W)))
  val depth  = Input(UInt(3.W))
  val out    = Output(Vec(16, UInt(32.W))) // FP32 encoded bits
}

class DotProduct extends Module {
  val io = IO(new MXFP4_DP_Block_IO)
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

  // near two Vectors Multiplication at Each Vec(i) and Vec(i+1)
  // Assuming a_vec and b_vec are both of 256 elements, then We will Multiply 128 pairs of Vec(i) and Vec(i+1)
  // and Add them as the tree structure (Depth is configurable by io.depth)
  // MXFP4 Format: 1 sign, 2 exponent, 1 mantissa
  val partial_products = Wire(Vec(128, UInt(32.W))) // 128 partial products
  // Resulting in 16 FP32 outputs (Final Output)
  for (i <- 0 until 128) {
    


}

