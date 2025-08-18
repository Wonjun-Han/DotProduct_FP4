package nvfp4

import chisel3._
import chisel3.util._

class NVFP4Field extends Bundle {
  val sign     = UInt(1.W)
  val exponent = UInt(2.W)
  val mantissa = UInt(2.W)
}

class NVFP4FieldExtractorIO extends Bundle {
  val in_vec  = Input(Vec(256, UInt(4.W)))
  val out_vec = Output(Vec(256, new MXFP4Field))
}

class nv_FieldExtractor extends Module {
  val io = IO(new NVFP4FieldExtractorIO)

  for (i <- 0 until 256) {
    val input = io.in_vec(i)
    val sign = input(3)
    val exp  = input(2, 1)
    val man  = input(0)

    io.out_vec(i).sign     := sign
    io.out_vec(i).exponent := exp
    io.out_vec(i).mantissa := Mux(
      exp === 0.U,
      Cat(0.U(1.W), man), 
      Cat(1.U(1.W), man)  
    )
  }
}
