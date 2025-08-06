package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_Adder_CrossBlock_IO (depthBitWidth: Int, accWidth: Int, vecSize: Int, outWidth: Int) extends Bundle {
    val in = Input(Vec(vecSize, SInt(accWidth.W)))
    val depth = Input(UInt(depthBitWidth.W))
    val nan = Input(Vec(vecSize, UInt(1.W)))
    val out = Output(Vec(vecSize/2, SInt(outWidth.W)))
}

class p_Adder_CrossBlock(val d: Int, val extra: Int) extends Module {
    val accWidth = 8 + d + extra
    val vecSize = 8 // for MXFP4
    val outWidth = 9 + d + extra

    val io = IO(new p_Adder_CrossBlock_IO(
        depthBitWidth = 4,
        accWidth = accWidth,
        vecSize = vecSize,
        outWidth = outWidth
    ))

    val enable_depth = io.depth === d.U
    val sum = Wire(Vec(vecSize/2, SInt(outWidth.W)))

    // pairwise addition
    for (i <- 0 until vecSize/2) {
        sum(i) := io.in(2*i) +& io.in(2*i + 1)
    }

    for (i <- 0 until vecSize/2) {
        when(enable_depth) {
            io.out(i) := sum(i)
        }.otherwise {
            io.out(i) := 0.S
        }
    }
}

