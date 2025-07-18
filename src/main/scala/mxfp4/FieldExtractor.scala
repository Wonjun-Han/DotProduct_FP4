package mxfp4

import chisel3._
import chisel3.util._

class MXFP4Field extends Bundle {
  val sign     = UInt(1.W)
  val exponent = UInt(2.W)
  val mantissa = UInt(1.W)
}

class MXFP4FieldExtractorIO extends Bundle {
  val in_vec  = Input(Vec(256, UInt(4.W)))
  val out_vec = Output(Vec(256, new MXFP4Field))
}

class FieldExtractor extends Module {
  val io = IO(new MXFP4FieldExtractorIO)
  for (i <- 0 until 256) {
    io.out_vec(i).sign     := io.in_vec(i)(3)
    io.out_vec(i).exponent := io.in_vec(i)(2, 1)
    io.out_vec(i).mantissa := io.in_vec(i)(0)
  }
}
