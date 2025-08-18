package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_TOP_Til_Dep_total_PIPED_BLOCK_IO extends Bundle {
  val a_vec   = Input(Vec(256, UInt(4.W)))
  val b_vec   = Input(Vec(256, UInt(4.W)))
  val a_scale = Input(Vec(8, UInt(8.W)))
  val b_scale = Input(Vec(8, UInt(8.W)))
  val depth   = Input(UInt(4.W))
  val out     = Output(Vec(16, new FP32))

  // Debug ports
  val adder6_out_mantissa = Output(Vec(4, UInt(44.W)))
  val adder6_out_sign     = Output(Vec(4, UInt(1.W)))
  val adder7_out_mantissa = Output(Vec(2, UInt(45.W)))
  val adder7_out_sign     = Output(Vec(2, UInt(1.W)))
  val adder8_out_mantissa = Output(Vec(1, UInt(46.W)))
  val adder8_out_sign     = Output(Vec(1, UInt(1.W)))
}

class p_TOP_Til_Dep_total_piped extends Module {
  val io = IO(new p_TOP_Til_Dep_total_PIPED_BLOCK_IO)

  // --------------------------
  // 유틸: Vec 레지스터 파이프
  // --------------------------
  private def regNextVec[T <: Data](v: Vec[T]): Vec[T] = VecInit(v.map(RegNext(_)))
  private def pipeVecN[T <: Data](v: Vec[T], n: Int): Vec[T] =
    (0 until n).foldLeft(v){ case (acc, _) => regNextVec(acc) }

  // 각 Stage index 기준으로 S2에서 계산된 exp_cand/nan을 목표 스테이지까지 지연시키기 위함
  private def delayToStage[T <: Data](fromS: Int, toS: Int, v: Vec[T]): Vec[T] = {
    val n = (toS - fromS) max 0
    pipeVecN(v, n)
  }

  // ---------------------------------
  // 모듈 인스턴스 (원본 유지)
  // ---------------------------------
  val mult   = Module(new p_Multiplier)
  val scaleSum   = Module(new p_Adder_ScaleSum)
  val scaleEmax  = Module(new p_Adder_ScaleEmax)

  val adder1 = Seq.fill(8)(Module(new p_Adder_Dep_1))
  val adder2 = Seq.fill(8)(Module(new p_Adder_Dep_2))
  val adder3 = Seq.fill(8)(Module(new p_Adder_Dep_3))
  val adder4 = Seq.fill(8)(Module(new p_Adder_Dep_4))
  val adder5 = Seq.fill(8)(Module(new p_Adder_Dep_5))

  val convert0 = Module(new p_MulConvert)
  val convert1 = Module(new p_Convert(1))
  val convert2 = Module(new p_Convert(2))
  val convert3 = Module(new p_Convert(3))
  val convert4 = Module(new p_Convert(4))
  val convert5 = Module(new p_Convert(5))

  val expansion_groupwise = Module(new p_Expansion_Groupwise(5, 30))
  val nan_process         = Module(new p_NaN_Process(5))

  val adder_groupwise_6 = Module(new p_Adder_Groupwise(6, 30))
  val adder_groupwise_7 = Module(new p_Adder_Groupwise(7, 30))
  val adder_groupwise_8 = Module(new p_Adder_Groupwise(8, 30))

  val convert_groupwise_6 = Module(new p_Convert_Groupwise(6, 30))
  val convert_groupwise_7 = Module(new p_Convert_Groupwise(7, 30))
  val convert_groupwise_8 = Module(new p_Convert_Groupwise(8, 30))

  // ---------------------------------
  // Depth 파이프라인 레지스터 (각 스테이지별)
  // ---------------------------------
  val depth_s1  = RegNext(io.depth)
  val depth_s2  = RegNext(depth_s1)
  val depth_s3  = RegNext(depth_s2)
  val depth_s4  = RegNext(depth_s3)
  val depth_s5  = RegNext(depth_s4)
  val depth_s6  = RegNext(depth_s5)
  val depth_s7  = RegNext(depth_s6)
  val depth_s8  = RegNext(depth_s7)
  val depth_s9  = RegNext(depth_s8)
  val depth_s10 = RegNext(depth_s9)
  val depth_s11 = RegNext(depth_s10)
  val depth_s12 = RegNext(depth_s11)

  // ---------------------------------
  // S1: Mult + ScaleSum (Comb) → Reg
  // ---------------------------------
  mult.io.a_vec := io.a_vec
  mult.io.b_vec := io.b_vec
  mult.io.depth := io.depth  // S1: Use input depth

  scaleSum.io.a_scale := io.a_scale
  scaleSum.io.b_scale := io.b_scale

  val s1_sign      = regNextVec(mult.io.sign)
  val s1_exponent  = regNextVec(mult.io.exponent)
  val s1_mantissa  = regNextVec(mult.io.mantissa)
  val s1_scale_sum = regNextVec(scaleSum.io.out)
  val s1_scale_nan = regNextVec(scaleSum.io.nan)

  // ---------------------------------
  // S2: Expansion(in-group) + (Emax+scale_sum) → Reg
  // ---------------------------------
  scaleEmax.io.depth := depth_s1
  for (i <- 0 until 8) {
    val base = i * 32
    val expansion = Module(new p_Expansion)
    expansion.io.depth    := depth_s1
    expansion.io.sign     := s1_sign.slice(base, base + 32)
    expansion.io.exponent := s1_exponent.slice(base, base + 32)
    expansion.io.mantissa := s1_mantissa.slice(base, base + 32)

    scaleEmax.io.nan(i)       := s1_scale_nan(i)
    scaleEmax.io.scale_sum(i) := s1_scale_sum(i)
    scaleEmax.io.emax(i)      := expansion.io.out_exponent_gmax(0) // 그룹 gmax

    // S2 출구 레지스터 → S3(Adder1 입력)
    adder1(i).io.depth    := depth_s2
    adder1(i).io.sign     := RegNext(expansion.io.out_sign)
    adder1(i).io.mantissa := RegNext(expansion.io.out_mantissa)
  }

  // exp_cand / nan
  val s2_exp_cand = regNextVec(scaleEmax.io.out) // (S2 경계에 맞춰 1단 래치)
  val s2_nan_flag = regNextVec(scaleEmax.io.nan)

  // ---------------------------------
  // S3: depth=0 → Convert@Dep0, else → Adder1 → Reg
  // ---------------------------------
  // Convert@Dep0 입력은 S1에서 계산된 값 → S3로 지연 필요
  val toS3_scale_sum = delayToStage(fromS = 2, toS = 3, s1_scale_sum)
  val toS3_scale_nan = delayToStage(fromS = 2, toS = 3, s1_scale_nan)
  val toS3_sign      = delayToStage(fromS = 2, toS = 3, s1_sign)
  val toS3_exp       = delayToStage(fromS = 2, toS = 3, s1_exponent)
  val toS3_man       = delayToStage(fromS = 2, toS = 3, s1_mantissa)

  convert0.io.sign      := toS3_sign
  convert0.io.exponent  := toS3_exp
  convert0.io.mantissa  := toS3_man
  convert0.io.scale_sum := toS3_scale_sum
  convert0.io.nan       := toS3_scale_nan

  val s3_adder1_out = (0 until 8).map(i => regNextVec(adder1(i).io.out))

  // ---------------------------------
  // S4: depth=1 → Convert@Dep1, else → Adder2 → Reg
  // ---------------------------------
  // Convert@Dep1: in = S3(adder1_out), exp_cand/nan = S3에서 S4로 1단 지연
  val toS4_exp_cand = delayToStage(3, 4, s2_exp_cand)
  val toS4_nan      = delayToStage(3, 4, s2_nan_flag)

  // adder1_out(8*16=128)을 평탄화 연결
  for (i <- 0 until convert1.io.in.length) {
    val g = i / 16; val k = i % 16
    convert1.io.in(i) := s3_adder1_out(g)(k)
  }
  convert1.io.depth    := depth_s4
  convert1.io.nan      := toS4_nan
  convert1.io.exponent := toS4_exp_cand

  // Adder2 입력 = S3 레지스터 출력
  for (i <- 0 until 8) {
    adder2(i).io.depth := depth_s4
    adder2(i).io.in    := s3_adder1_out(i)
  }
  val s4_adder2_out = (0 until 8).map(i => regNextVec(adder2(i).io.out))

  // ---------------------------------
  // S5: depth=2 → Convert@Dep2, else → Adder3 → Reg
  // ---------------------------------
  val toS5_exp_cand = delayToStage(3, 5, s2_exp_cand)
  val toS5_nan      = delayToStage(3, 5, s2_nan_flag)

  for (i <- 0 until convert2.io.in.length) { // 8*8=64
    val g = i / 8; val k = i % 8
    convert2.io.in(i) := s4_adder2_out(g)(k)
  }
  convert2.io.depth    := depth_s5
  convert2.io.nan      := toS5_nan
  convert2.io.exponent := toS5_exp_cand

  for (i <- 0 until 8) {
    adder3(i).io.depth := depth_s5
    adder3(i).io.in    := s4_adder2_out(i)
  }
  val s5_adder3_out = (0 until 8).map(i => regNextVec(adder3(i).io.out))

  // ---------------------------------
  // S6: depth=3 → Convert@Dep3, else → Adder4 → Reg
  // ---------------------------------
  val toS6_exp_cand = delayToStage(3, 6, s2_exp_cand)
  val toS6_nan      = delayToStage(3, 6, s2_nan_flag)

  for (i <- 0 until convert3.io.in.length) { // 8*4=32
    val g = i / 4; val k = i % 4
    convert3.io.in(i) := s5_adder3_out(g)(k)
  }
  convert3.io.depth    := depth_s6
  convert3.io.nan      := toS6_nan
  convert3.io.exponent := toS6_exp_cand

  for (i <- 0 until 8) {
    adder4(i).io.depth := depth_s6
    adder4(i).io.in    := s5_adder3_out(i)
  }
  val s6_adder4_out = (0 until 8).map(i => regNextVec(adder4(i).io.out))

  // ---------------------------------
  // S7: depth=4 → Convert@Dep4, else → Adder5 → Reg
  // ---------------------------------
  val toS7_exp_cand = delayToStage(3, 7, s2_exp_cand)
  val toS7_nan      = delayToStage(3, 7, s2_nan_flag)

  for (i <- 0 until convert4.io.in.length) { // 8*2=16
    val g = i / 2; val k = i % 2
    convert4.io.in(i) := s6_adder4_out(g)(k)
  }
  convert4.io.depth    := depth_s7
  convert4.io.nan      := toS7_nan
  convert4.io.exponent := toS7_exp_cand

  for (i <- 0 until 8) {
    adder5(i).io.depth := depth_s7
    adder5(i).io.in    := s6_adder4_out(i)
  }

val s7_adder5_out = VecInit((0 until 8).map(i => RegNext(adder5(i).io.out)))

for (i <- 0 until 8) convert5.io.in(i) := s7_adder5_out(i)

  // ---------------------------------
  // S8: depth=5 → Convert@Dep5, else → Expansion_Groupwise → Reg
  // ---------------------------------
  val toS8_exp_cand = delayToStage(3, 8, s2_exp_cand)
  val toS8_nan      = delayToStage(3, 8, s2_nan_flag)

  for (i <- 0 until 8) convert5.io.in(i) := s7_adder5_out(i)
  convert5.io.depth    := depth_s8
  convert5.io.nan      := toS8_nan
  convert5.io.exponent := toS8_exp_cand

  expansion_groupwise.io.depth := depth_s8
  for (i <- 0 until 8) {
    expansion_groupwise.io.in(i)      := s7_adder5_out(i)
    expansion_groupwise.io.exponent(i):= toS8_exp_cand(i)
  }
  val s8_gw_sign     = RegNext(expansion_groupwise.io.out_sign)
  val s8_gw_mantissa = RegNext(expansion_groupwise.io.out_mantissa)
  val s8_gw_emax     = RegNext(expansion_groupwise.io.out_exponent_gmax)
  
  // NaN 경로: S2→S8 (nan_process 입력: scaleEmax.nan)
  nan_process.io.depth := depth_s8
  for (i <- 0 until 8) nan_process.io.group_nan(i) := toS8_nan(i)
  val s8_nan_proc = RegNext(nan_process.io.result_nan)

  // ---------------------------------
  // S9: Adder_Groupwise_6 → Reg
  // ---------------------------------
  adder_groupwise_6.io.depth    := depth_s9
  adder_groupwise_6.io.sign     := s8_gw_sign
  adder_groupwise_6.io.mantissa := s8_gw_mantissa
  val s9_ad6_sign     = RegNext(adder_groupwise_6.io.out_sign)
  val s9_ad6_mantissa = RegNext(adder_groupwise_6.io.out_mantissa)

  // ---------------------------------
  // S10: depth=6 → Convert@Dep6, else → Adder_Groupwise_7 → Reg
  // ---------------------------------
  // 그룹와이즈 exp, nan 정렬: S8→S10
  val toS10_gw_emax = delayToStage(9, 10, s8_gw_emax)
  val toS10_nan     = delayToStage(9, 10, s8_nan_proc)

  convert_groupwise_6.io.depth    := depth_s10
  convert_groupwise_6.io.sign     := s9_ad6_sign
  convert_groupwise_6.io.mantissa := s9_ad6_mantissa
  convert_groupwise_6.io.exponent := toS10_gw_emax  // For depth 6: uses indices 0,1,2,3
  convert_groupwise_6.io.nan      := toS10_nan      // For depth 6: uses indices 0,1,2,3

  adder_groupwise_7.io.depth    := depth_s10
  adder_groupwise_7.io.sign     := s9_ad6_sign
  adder_groupwise_7.io.mantissa := s9_ad6_mantissa
  val s10_ad7_sign     = RegNext(adder_groupwise_7.io.out_sign)
  val s10_ad7_mantissa = RegNext(adder_groupwise_7.io.out_mantissa)

  // ---------------------------------
  // S11: depth=7 → Convert@Dep7, else → Adder_Groupwise_8 → Reg
  // ---------------------------------
  val toS11_gw_emax = delayToStage(9, 11, s8_gw_emax)
  val toS11_nan     = delayToStage(9, 11, s8_nan_proc)

  convert_groupwise_7.io.depth    := depth_s11
  convert_groupwise_7.io.sign     := s10_ad7_sign
  convert_groupwise_7.io.mantissa := s10_ad7_mantissa
  convert_groupwise_7.io.exponent := toS11_gw_emax
  convert_groupwise_7.io.nan      := toS11_nan

  adder_groupwise_8.io.depth    := depth_s11
  adder_groupwise_8.io.sign     := s10_ad7_sign
  adder_groupwise_8.io.mantissa := s10_ad7_mantissa
  val s11_ad8_sign     = RegNext(adder_groupwise_8.io.out_sign)
  val s11_ad8_mantissa = RegNext(adder_groupwise_8.io.out_mantissa)

  // ---------------------------------
  // S12: Convert@Dep8 (무조건)
  // ---------------------------------
  val toS12_gw_emax = delayToStage(9, 12, s8_gw_emax)
  val toS12_nan     = delayToStage(9, 12, s8_nan_proc)

  convert_groupwise_8.io.depth    := depth_s12
  convert_groupwise_8.io.sign     := s11_ad8_sign
  convert_groupwise_8.io.mantissa := s11_ad8_mantissa
  convert_groupwise_8.io.exponent := toS12_gw_emax
  convert_groupwise_8.io.nan      := toS12_nan

  // ---------------------------------
  // 변환 결과를 S12까지 지연 → depth 스위치 일원화
  // ---------------------------------
  def padTo16(vec: Vec[FP32]): Vec[FP32] =
    VecInit((0 until 16).map(i => if (i < vec.length) vec(i) else 0.U.asTypeOf(new FP32)))

  val d0_atS12 = pipeVecN(padTo16(convert0.io.out),            9) // S3→S12
  val d1_atS12 = pipeVecN(padTo16(convert1.io.out),            8) // S4→S12
  val d2_atS12 = pipeVecN(padTo16(convert2.io.out),            7) // S5→S12
  val d3_atS12 = pipeVecN(padTo16(convert3.io.out),            6) // S6→S12
  val d4_atS12 = pipeVecN(padTo16(convert4.io.out),            5) // S7→S12
  val d5_atS12 = pipeVecN(padTo16(convert5.io.out),            4) // S8→S12
  val d6_atS12 = pipeVecN(padTo16(convert_groupwise_6.io.out), 2) // S10→S12
  val d7_atS12 = pipeVecN(padTo16(convert_groupwise_7.io.out), 1) // S11→S12
  val d8_atS12 = padTo16(convert_groupwise_8.io.out) // S12

  val selected_out = Wire(Vec(16, new FP32))
  selected_out := 0.U.asTypeOf(Vec(16, new FP32))
  switch(depth_s12) {
    is(0.U) { selected_out := d0_atS12 }
    is(1.U) { selected_out := d1_atS12 }
    is(2.U) { selected_out := d2_atS12 }
    is(3.U) { selected_out := d3_atS12 }
    is(4.U) { selected_out := d4_atS12 }
    is(5.U) { selected_out := d5_atS12 }
    is(6.U) { selected_out := d6_atS12 }
    is(7.U) { selected_out := d7_atS12 }
    is(8.U) { selected_out := d8_atS12 }
  }
  io.out := selected_out

  // ---------------------------------
  // Debug ports (원래 연결 유지)
  // ---------------------------------
  io.adder6_out_mantissa := adder_groupwise_6.io.out_mantissa
  io.adder6_out_sign     := adder_groupwise_6.io.out_sign
  io.adder7_out_mantissa := adder_groupwise_7.io.out_mantissa
  io.adder7_out_sign     := adder_groupwise_7.io.out_sign
  io.adder8_out_mantissa := adder_groupwise_8.io.out_mantissa
  io.adder8_out_sign     := adder_groupwise_8.io.out_sign
}