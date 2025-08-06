package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_Expansion_Groupwise_IO (depthBitWidth: Int, accWidth: Int, vecSize: Int, outWidth: Int) extends Bundle {
    val in = Input(Vec(vecSize, SInt(accWidth.W)))
    val exponent = Input(Vec(vecSize, SInt(10.W))) 
    val depth = Input(UInt(depthBitWidth.W))
    val nan = Input(Vec(vecSize, UInt(1.W)))

    val out_mantissa = Output(Vec(vecSize, UInt(outWidth.W)))
    val out_sign = Output(Vec(vecSize, UInt(1.W)))
    val out_exponent_gmax = Output(SInt(10.W))
}

class p_Expansion_Groupwise (val d: Int, val vecSize: Int, val extra: Int) extends Module {
    val accWidth = 8 + d
    val outWidth = 8 + d + extra - 1

    val io = IO(new p_Expansion_Groupwise_IO(
        depthBitWidth = 4,
        accWidth = accWidth,
        vecSize = vecSize,
        outWidth = outWidth
    ))

    val enable_depth = io.depth === d.U
    val max_exp = Wire(SInt(10.W))
    max_exp := io.exponent.reduce((a, b) => Mux(a > b, a, b))
    io.out_exponent_gmax := max_exp
    for (i <- 0 until vecSize) {
        val in = io.in(i)
        val exp = io.exponent(i)
        val shift_amt = (max_exp - exp).asUInt
        val sign_bit = in.head(0).asUInt
        val abs_val_full = Mux(sign_bit===1.U, -in, in).asUInt
        val abs_val = abs_val_full(accWidth - 1, 0)
        val extended = Cat(abs_val, 0.U(extra.W))
        io.out_sign(i) := Mux(io.nan(i) === 1.U, 0.U, sign_bit)
        io.out_mantissa(i) := extended >> shift_amt
    }
}
