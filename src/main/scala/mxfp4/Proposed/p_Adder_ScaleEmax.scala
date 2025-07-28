package mxfp4.proposed
import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_ADD_SCALE_EMAX extends Bundle {
  val depth = Input(UInt(3.W))
  val scale_sum = Input(Vec(8, UInt(9.W)))
  val nan = Input(Vec(8, UInt(1.W))) // NaN flag for each scale sum
  val emax = Input(Vec(8, UInt(3.W)))
  val out = Output(Vec(8, UInt(9.W)))
}

class p_Adder_ScaleEmax extends Module {
  val io = IO(new MXFP4_ADD_SCALE_EMAX)
  val enable = io.depth <= 5.U && io.depth >= 1.U 
  when (enable) {
    for (i <- 0 until 8) {
        io.out(i) := Mux(io.nan(i) === 0.U, io.scale_sum(i) + io.emax(i), 255.U)
    }
  }.otherwise {
    // For depth > 5, just pass through the scale_sum
    io.out := io.scale_sum
  }
}
