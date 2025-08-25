package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_ADD_SCALE_EMAX extends Bundle {
  val depth      = Input(UInt(4.W))              // 현재 누산 트리의 depth
  val scale_sum  = Input(Vec(8, SInt(9.W)))      // 이전에서 계산된 scale 합산 값
  val nan_in        = Input(Vec(8, UInt(1.W)))      // NaN 여부 flag
  val emax       = Input(Vec(8, UInt(3.W)))      // 각 그룹의 Emax
  val out        = Output(Vec(8, SInt(10.W)))    // 최종 exponent 후보값
  val nan_out    = Output(Vec(8, UInt(1.W)))      // NaN 여부 flag (pass-through)

}

class p_Adder_ScaleEmax extends Module {
  val io = IO(new MXFP4_ADD_SCALE_EMAX)

  io.out := VecInit(Seq.tabulate(8) { i => io.scale_sum(i) + io.emax(i).zext })
  io.nan_out := io.nan_in // pass-through
}