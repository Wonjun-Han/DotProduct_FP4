package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_Expansion_Groupwise_IO(depthBitWidth: Int, accWidth: Int, vecSize: Int, outWidth: Int) extends Bundle {
  val in        = Input(Vec(vecSize, SInt(accWidth.W)))
  val exponent  = Input(Vec(vecSize, SInt(10.W)))
  val depth     = Input(UInt(depthBitWidth.W)) // depth에 따라 grouping 결정

  val out_mantissa        = Output(Vec(vecSize, UInt(outWidth.W)))
  val out_sign            = Output(Vec(vecSize, UInt(1.W)))
  val out_exponent_gmax   = Output(Vec(vecSize / 2, SInt(10.W)))
}

class p_Expansion_Groupwise(val d: Int, val extra: Int) extends Module {
  val accWidth = 9 + d
  val outWidth = 8 + d + extra
  val vecSize = 256 >> d // d = 5 → vecSize = 8

  val io = IO(new p_Expansion_Groupwise_IO(
    depthBitWidth = 4,
    accWidth = accWidth,
    vecSize = vecSize,
    outWidth = outWidth
  ))

  // ------------------------------
  // (1) depth에 따른 group 구성
  // ------------------------------
  val expansion_size = Wire(UInt(4.W))
  val expansion_num  = Wire(UInt(4.W))
  val enable         = Wire(Bool())

    // 먼저 기본값 선언 (fallback)
    expansion_size := 2.U
    expansion_num  := 4.U
    enable         := false.B


  switch(io.depth) {
    is(6.U) {
      expansion_size := 2.U
      expansion_num  := 4.U
      enable := true.B
    }
    is(7.U) {
      expansion_size := 4.U
      expansion_num  := 2.U
      enable := true.B
    }
    is(8.U) {
      expansion_size := 8.U
      expansion_num  := 1.U
      enable := true.B
    }
  }

  // ------------------------------
  // (2) 그룹별 max exponent 계산 (최대 4개)
  // ------------------------------
  val grouped_max_exp = Wire(Vec(4, SInt(10.W)))

  for (g <- 0 until 4) {
    val maxval = WireDefault(0.S(10.W))

    when(enable && g.U < expansion_num) {
      val group_start = g.U * expansion_size

      val candidates = Wire(Vec(vecSize, SInt(10.W)))
      for (j <- 0 until vecSize) {
        val idx = group_start + j.U
        candidates(j) := Mux(j.U < expansion_size && idx < vecSize.U, io.exponent(idx), 0.S)
      }

      maxval := candidates.reduce((a, b) => Mux(a > b, a, b))
    }

    grouped_max_exp(g) := maxval
  }

  // ------------------------------
  // (3) mantissa shift 및 sign 추출
  // ------------------------------
  for (i <- 0 until vecSize) {
    val group_idx = i.U / expansion_size
    val max_exp = grouped_max_exp(group_idx)
    val shift_amt = (max_exp - io.exponent(i)).asUInt

    val in = io.in(i)
    val sign_bit = in(accWidth - 1)
    val abs_val = Mux(sign_bit === 1.U, -in, in).asUInt
    val extended = Cat(abs_val(accWidth - 1, 0), 0.U(extra.W))

    io.out_sign(i)     := Mux(enable, sign_bit, 0.U)
    io.out_mantissa(i) := Mux(enable, (extended >> shift_amt), 0.U)
  }

  // ------------------------------
  // (4) out_exponent_gmax 상위 포트부터 채움
  // ------------------------------
  for (i <- 0 until vecSize / 2) {
    val gidx = i + (4 - vecSize / 2) // 상위 포트부터 매핑
    when(enable && i.U >= (vecSize / 2).U - expansion_num) {
      io.out_exponent_gmax(i) := grouped_max_exp(gidx)
    } .otherwise {
      io.out_exponent_gmax(i) := 0.S
    }
  }
}
