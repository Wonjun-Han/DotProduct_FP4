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
    val a = Input(new FP32)
    val b = Input(new FP32)
    val sign = Output(Vec(256, UInt(1.W)))
    val exponent = Output(Vec(256, UInt(8.W)))
    val mantissa = Output(Vec(256, UInt(25.W)))
}

class Adder extends Module {
    val io = IO(new MXFP4_Adder_Block_IO)
    val a = io.a
    val b = io.b
    val sign = Wire(Vec(256, UInt(1.W)))
    val exponent = Wire(Vec(256, UInt(8.W)))
    val mantissa = Wire(Vec(256, UInt(25.W)))

    val mantA = Cat(1.U(1.W), io.a.mantissa) // 24-bit
    val mantB = Cat(1.U(1.W), io.b.mantissa) // 24-bit


    val expDiff = (io.a.exponent - io.b.exponent).asSInt
    val shiftedA = Wire(UInt(25.W))
    val shiftedB = Wire(UInt(25.W))
    val resultExp = Wire(UInt(8.W))

    when (expDiff >= 0.S) {
        shiftedA := mantA
        shiftedB := mantB >> expDiff.asUInt
        resultExp := io.a.exponent
    } .otherwise {
        shiftedA := mantA >> (-expDiff).asUInt
        shiftedB := mantB
        resultExp := io.b.exponent
    }



}

