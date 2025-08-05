package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_Adder_CrossBlock_IO (d: Int) extends Bundle {
    val in = Input(Vec(8, SInt((10+d).W)))
    val exp = Input(Vec(8, SInt(10.W)))
    val depth = Input(UInt(3.W))
    val nan = Input(Vec(8, UInt(1.W)))
    val out = Output(Vec(8, new FP32))
}

class 