package nvfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class NVFP4_ADD_SCALE_SUM extends Bundle {
  val a_scale = Input(Vec(8, UInt(8.W)))       
  val b_scale = Input(Vec(8, UInt(8.W)))       
  val out     = Output(Vec(8, SInt(9.W)))      // 실제 scale 합산 결과 (signed)
  val nan     = Output(Vec(8, UInt(1.W)))       // 각 scale 합산에 대한 NaN 여부
}

class nv_p_Adder_ScaleSum extends Module {
  val io = IO(new NVFP4_ADD_SCALE_SUM)

  for (i <- 0 until 8) {
    val a = io.a_scale(i)
    val b = io.b_scale(i)
    val isNaN = (a === 255.U || b === 255.U)

    val sum = (a.zext +& b.zext - 254.S).asSInt  // 명시적으로 254 사용

    io.nan(i) := isNaN
    io.out(i) := Mux(isNaN, 255.S, sum)
  }
}
