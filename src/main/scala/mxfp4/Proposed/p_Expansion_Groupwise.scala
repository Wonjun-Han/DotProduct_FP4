package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_Expansion_Groupwise_IO (depthBitWidth: Int, accWidth: Int, vecSize: Int, outWidth: Int) extends Bundle {
    val in = Input(Vec(vecSize, SInt(accWidth.W)))
    val exponent = Input(Vec(vecSize, SInt(10.W))) 
    val depth = Input(UInt(depthBitWidth.W)) //still not used

    val out_mantissa = Output(Vec(vecSize, UInt(outWidth.W)))
    val out_sign = Output(Vec(vecSize, UInt(1.W)))
    val out_exponent_gmax = Output(SInt(10.W))
}

class p_Expansion_Groupwise (val d: Int, val extra: Int) extends Module {
    val accWidth = 8 + d
    val outWidth = 7 + d + extra
    val vecSize = 256 >> d

    val io = IO(new p_Expansion_Groupwise_IO(
        depthBitWidth = 4,
        accWidth = accWidth,
        vecSize = vecSize,
        outWidth = outWidth
    ))

    val max_exp = Wire(SInt(10.W))
    max_exp := io.exponent.reduce((a, b) => Mux(a > b, a, b))
    io.out_exponent_gmax := max_exp
    for (i <- 0 until vecSize) {
        val in = io.in(i)
        val exp = io.exponent(i)
        val shift_amt = (max_exp - exp).asUInt //always positive.
        val sign_bit = in.head(1).asUInt
        val abs_val_full = Mux(sign_bit===1.U, -in, in).asUInt
        val abs_val = abs_val_full(accWidth - 1, 0)
        val extended = Cat(abs_val, 0.U(extra.W)) /// Q(7,6) + extra bits for mantissa
        io.out_sign(i) := sign_bit
        io.out_mantissa(i) := extended >> shift_amt
    }
}

//expansion : depth 마다 비교해야 하는 exponent 그룹 사이즈가 다르므로, 이걸 고려하기
//NaN 로직은 그냥 새롭게 하나 짜서, 넣어주거나, def 로 정의해서 넣어주기 
//inf 는 conversion 시에 처리하고, NaN은 special logic 으로 구현
//합성 환경 연구실에서 끌어오기.
