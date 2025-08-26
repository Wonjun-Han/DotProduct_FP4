package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_Adder_Groupwise_IO (depthBitWidth: Int, mantissaWidth: Int, vecSize: Int, outWidth: Int) extends Bundle {
    //val mantissa = Input(Vec(vecSize, UInt(mantissaWidth.W)))
    //val sign = Input(Vec(vecSize, UInt(1.W)))
    val in = Input(Vec(vecSize, SInt((mantissaWidth + 1).W))) // with sign bit
    val depth = Input(UInt(depthBitWidth.W)) // Still not used (for power gating)
    val out = Output(Vec(vecSize/2, SInt((outWidth+1).W)))
    //val out_mantissa = Output(Vec(vecSize/2, UInt(outWidth.W)))
    //val out_sign = Output(Vec(vecSize/2, UInt(1.W)))
}

class p_Adder_Groupwise(val d: Int, val extra: Int) extends Module {
    val mantissaWidth = 7 + d + extra 
    val outWidth = mantissaWidth + 1 // 1 bit for overflow
    val vecSize = 256 >> (d-1)

    val io = IO(new p_Adder_Groupwise_IO(
        depthBitWidth = 4,
        mantissaWidth = mantissaWidth,
        vecSize = vecSize,
        outWidth = outWidth
    ))

    for (i <- 0 until vecSize/2) {
        /*
        val a_sign = io.sign(2 * i)
        val b_sign = io.sign(2 * i + 1)

        val a_mag = io.mantissa(2 * i)
        val b_mag = io.mantissa(2 * i + 1)

        val a_ext = Cat(0.U(1.W), io.mantissa(2 * i)).asSInt  // 9비트로 확장
        val b_ext = Cat(0.U(1.W), io.mantissa(2 * i + 1)).asSInt

        val a_sint = Mux(io.sign(2 * i) === 1.U, -a_ext, a_ext)
        val b_sint = Mux(io.sign(2 * i + 1) === 1.U, -b_ext, b_ext)
        */

        val a_sint = io.in(2 * i)
        val b_sint = io.in(2 * i + 1)
        val sum = a_sint +& b_sint
        io.out(i) := sum
    }
}

