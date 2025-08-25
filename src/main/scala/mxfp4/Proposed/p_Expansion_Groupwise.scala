package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_Expansion_Groupwise_IO(depthBitWidth: Int, accWidth: Int, vecSize: Int, outWidth: Int) extends Bundle {
  val in        = Input(Vec(vecSize, SInt(accWidth.W)))
  val exponent  = Input(Vec(vecSize, SInt(10.W)))
  val depth     = Input(UInt(depthBitWidth.W)) // depth에 따라 grouping 결정

  val out_mantissa      = Output(Vec(vecSize, UInt(outWidth.W)))
  val out_sign          = Output(Vec(vecSize, UInt(1.W)))
  val out_exponent_gmax = Output(Vec(vecSize / 2, SInt(10.W)))
}

class p_Expansion_Groupwise(val d: Int, val extra: Int) extends Module {
  val accWidth = 9 + d
  val outWidth = 8 + d + extra
  val vecSize  = 256 >> d // d = 5 → vecSize = 8

  val io = IO(new p_Expansion_Groupwise_IO(
    depthBitWidth = 4,
    accWidth      = accWidth,
    vecSize       = vecSize,
    outWidth      = outWidth
  ))

  // ------------------------------
  // (1) depth에 따른 group 구성
  // ------------------------------
  val expansion_size = Wire(UInt(4.W)) // 그룹 크기 (depth 6 : 2, depth 7 : 4, depth 8 : 8)
  val expansion_num  = Wire(UInt(3.W)) // 최대 4개 그룹
  val enable         = Wire(Bool())

  // 기본값(초기화)
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
  def minS10: SInt = (-512).S(10.W)  // 무효 후보 대체값(최솟값)
  def max2S(a:SInt, b:SInt): SInt = Mux(a > b, a, b)

  // 실제 합이 0인 lane 마스킹, 그래야 이후에 Max Exp 뽑을 때 유효한 것만 사용
  val laneZero = Wire(Vec(vecSize, Bool()))
  for (i <- 0 until vecSize) {
    laneZero(i) := (io.in(i) === 0.S(accWidth.W))
  }

  val grouped_max_exp = Wire(Vec(vecSize/2, SInt(10.W)))
  for (g <- 0 until vecSize/2) { grouped_max_exp(g) := 0.S(10.W) }

  for (g <- 0 until vecSize/2) {
    val active      = enable && (g.U < expansion_num)
    val group_start = g.U * expansion_size

    // 그룹 내 후보(최대 8개)만 만들고, 무효는 minS10으로 마스킹
    val cands: Seq[SInt] = (0 until 8).map { k =>
      val i   = group_start + k.U
      val ok  = (k.U < expansion_size) && (i < vecSize.U)
      val idx = i(log2Ceil(vecSize)-1, 0)
      val expEff = Mux(laneZero(idx), minS10, io.exponent(idx))
      Mux(ok, expEff, minS10)
    }

    // 비교 트리(8→4→2→1) 훨씬 좋을듯 ㅇㅇ
    val l1 = (0 until 4).map(j => max2S(cands(2*j),   cands(2*j+1))) // 8 → 4
    val l2 = (0 until 2).map(j => max2S(l1(2*j),      l1(2*j+1)))    // 4 → 2
    val grpMax = max2S(l2(0), l2(1))                                  // 2 → 1

    grouped_max_exp(g) := Mux(active, grpMax, 0.S(10.W))
  }

  // ------------------------------
  // (3) lane→group index LUT (depth별 한 번만 계산)
  // ------------------------------
  val groupIdxBits = log2Ceil(vecSize/2) // = 2 (vecSize=8 → 4그룹)
  val groupIdxLut  = Wire(Vec(vecSize, UInt(groupIdxBits.W)))
  for (i <- 0 until vecSize) { groupIdxLut(i) := 0.U }

  when (io.depth === 6.U) {
    for (i <- 0 until vecSize) { groupIdxLut(i) := (i/2).U(groupIdxBits.W) }  // expansion_size = 2
  } .elsewhen (io.depth === 7.U) {
    for (i <- 0 until vecSize) { groupIdxLut(i) := (i/4).U(groupIdxBits.W) }  // expansion_size = 4
  } .elsewhen (io.depth === 8.U) {
    for (i <- 0 until vecSize) { groupIdxLut(i) := (i/8).U(groupIdxBits.W) }  // expansion_size = 8
  }

  // ------------------------------
  // (3) mantissa shift 및 sign 추출
  // ------------------------------
  val extWidth = accWidth + extra // 

  for (i <- 0 until vecSize) {
    io.out_sign(i)     := 0.U
    io.out_mantissa(i) := 0.U
  }

  for (i <- 0 until vecSize) {
    val max_exp   = grouped_max_exp(groupIdxLut(i))
    val shift_raw = (max_exp - io.exponent(i)).asUInt  
    val shift_max = (extWidth - 1).U                   // 너무 크게 밀면 모두 0이니까 굳이 처리 ㄴㄴ
    val shift_amt = Mux(shift_raw > shift_max, shift_max, shift_raw)

    val in       = io.in(i)
    val sign_bit = in(accWidth - 1)
    val abs_val  = Mux(sign_bit, (0.S(accWidth.W) - in).asUInt, in.asUInt)
    val extended = Cat(abs_val(accWidth - 1, 0), 0.U(extra.W)) // (extWidth)비트

    // enable일 때만 유효 출력, mantissa는 outWidth로 슬라이스(폭 정합)
    io.out_sign(i)     := Mux(enable, sign_bit, 0.U)
    io.out_mantissa(i) := Mux(enable, (extended >> shift_amt)(outWidth-1, 0), 0.U)
  }

  // ------------------------------
  // (4) out_exponent_gmax 앞에서부터 채움
  // ------------------------------
  for (i <- 0 until vecSize / 2) {
    io.out_exponent_gmax(i) := Mux(enable && (i.U < expansion_num), grouped_max_exp(i), 0.S)
  }
}
