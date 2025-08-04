package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4Field extends Bundle {
  val sign     = UInt(1.W)
  val exponent = UInt(2.W)
  val mantissa = UInt(2.W)
}

class MXFP4 extends Bundle {
  val sign     = UInt(1.W)
  val exponent = UInt(2.W)
  val mantissa = UInt(1.W)
}
// Data structure 미리 정의해두고 사용하기 : 복잡한 패킷, 다룰 때 굉장히 편리함.

class MXFP4FieldExtractorIO extends Bundle {
  val in_vec  = Input(Vec(256, UInt(4.W)))
  val out_vec = Output(Vec(256, new MXFP4Field))
}

class p_FieldExtractor extends Module {
  val io = IO(new MXFP4FieldExtractorIO)

  for (i <- 0 until 256) {
    val input = io.in_vec(i).asTypeOf(new MXFP4)

    io.out_vec(i).sign     := input.sign
    io.out_vec(i).exponent := input.exponent
    io.out_vec(i).mantissa := Mux(
      input.exponent === 0.U,
      Cat(0.U(1.W), input.mantissa), 
      Cat(1.U(1.W), input.mantissa)  
    )
  }
}
