package mxfp4

import chisel3._
import _root_.circt.stage.ChiselStage
import chisel3.util._

class FP32 extends Bundle {
    val sign     = UInt(1.W)
    val exponent = UInt(8.W)
    val mantissa = UInt(23.W)
}

class MXFP4_Adder_Block_IO () extends Bundle {
    val input = Input(new FP32)
    val sign = Output(Vec(256, UInt(1.W)))
    val exponent = Output(Vec(256, UInt(8.W)))
    val mantissa = Output(Vec(256, UInt(25.W)))
}

class Adder extends Module {
    val io = IO(new MXFP4_Adder_Block_IO)
    val input = io.input
    val sign = Wire(Vec(256, UInt(1.W)))
    val exponent = Wire(Vec(256, UInt(8.W)))
    val mantissa = Wire(Vec(256, UInt(25.W)))
}

