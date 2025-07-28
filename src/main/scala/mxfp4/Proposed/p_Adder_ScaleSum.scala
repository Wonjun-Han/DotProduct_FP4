package mxfp4.proposed
import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_ADD_SCALE_SUM extends Bundle {
  val a_scale = Input(Vec(8, UInt(8.W)))
  val b_scale = Input(Vec(8, UInt(8.W)))
  val out = Output(Vec(8, UInt(9.W)))
  val nan = Output(Vec(8, UInt(1.W))) // NaN flag for each scale sum
}

class p_Adder_ScaleSum extends Module {
  val io = IO(new MXFP4_ADD_SCALE_SUM)

  for (i <- 0 until 8) {
    when (io.a_scale(i) === 255.U || io.b_scale(i) === 255.U) {
      // NaN
      io.out(i) := 255.U
      io.nan(i) := 1.U
    }.otherwise {
      // Scale A and Scale B addition
      io.out(i) := io.a_scale(i) +& io.b_scale(i) -& 127.U
      io.nan(i) := 0.U
    }
  }
}