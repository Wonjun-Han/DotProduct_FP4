package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_TOP_Til_Dep_total_PIPED_CT_SYN_BLOCK_IO extends Bundle {
  val a_vec   = Input(Vec(256, UInt(4.W)))
  val b_vec   = Input(Vec(256, UInt(4.W)))
  val a_scale = Input(Vec(8, UInt(8.W)))
  val b_scale = Input(Vec(8, UInt(8.W)))
  val depth   = Input(UInt(4.W))
  val out     = Output(Vec(16, new FP32))
}

class p_TOP_Til_Dep_total_piped_CT_syn extends Module {
  val io = IO(new p_TOP_Til_Dep_total_PIPED_CT_SYN_BLOCK_IO)

  // --------------------------
  // Util: Vec 레지스터 파이프
  // --------------------------
  private def regNextVec[T <: Data](v: Vec[T]): Vec[T] = VecInit(v.map(RegNext(_)))
  private def pipeVecN[T <: Data](v: Vec[T], n: Int): Vec[T] =
    (0 until n).foldLeft(v){ case (acc, _) => regNextVec(acc) }
  private def delayToStage[T <: Data](fromS: Int, toS: Int, v: Vec[T]): Vec[T] = {
    val n = (toS - fromS) max 0
    pipeVecN(v, n)
  }

  val in_a_vec   = regNextVec(io.a_vec)
  val in_b_vec   = regNextVec(io.b_vec)
  val in_a_scale = regNextVec(io.a_scale)
  val in_b_scale = regNextVec(io.b_scale)
  val in_depth   = RegNext(io.depth)

  // ---------------------------------
  // instance
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
  // NEW: depth 파이프라인의 시점을 io.depth → in_depth로 변경
  val depth_s1  = RegNext(in_depth)
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


  // ---------------------------------
  // S0: Mult and ScaleSum 
  // ---------------------------------
  // NEW: 모든 연산 입력을 in_* 레지스터에서 취함
  mult.io.a_vec := in_a_vec
  mult.io.b_vec := in_b_vec
  mult.io.depth := in_depth

  scaleSum.io.a_scale := in_a_scale
  scaleSum.io.b_scale := in_b_scale

  val s1_sign      = regNextVec(mult.io.sign)
  val s1_exponent  = regNextVec(mult.io.exponent)
  val s1_mantissa  = regNextVec(mult.io.mantissa)
  val s1_scale_sum = regNextVec(scaleSum.io.out)
  val s1_scale_nan = regNextVec(scaleSum.io.nan)

  // ---------------------------------
  // S1: Expansion(in-group) then (Emax+scale_sum) 
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
    scaleEmax.io.emax(i)      := expansion.io.out_exponent_gmax(0)

    adder1(i).io.depth    := depth_s2
    adder1(i).io.sign     := RegNext(expansion.io.out_sign)
    adder1(i).io.mantissa := RegNext(expansion.io.out_mantissa)
  }

  val s2_exp_cand = regNextVec(scaleEmax.io.out)
  val s2_nan_flag = regNextVec(scaleEmax.io.nan)

  // ---------------------------------
  // S2: Convert@Dep0, else Adder1
  // ---------------------------------
  val toS2_scale_sum = delayToStage(fromS = 1, toS = 2, s1_scale_sum)
  val toS2_scale_nan = delayToStage(fromS = 1, toS = 2, s1_scale_nan)
  val toS2_sign      = delayToStage(fromS = 1, toS = 2, s1_sign)
  val toS2_exp       = delayToStage(fromS = 1, toS = 2, s1_exponent)
  val toS2_man       = delayToStage(fromS = 1, toS = 2, s1_mantissa)

  convert0.io.sign      := toS2_sign
  convert0.io.exponent  := toS2_exp
  convert0.io.mantissa  := toS2_man
  convert0.io.scale_sum := toS2_scale_sum
  convert0.io.nan       := toS2_scale_nan

  val s3_adder1_out = (0 until 8).map(i => regNextVec(adder1(i).io.out))

  val toS3_exp_cand = delayToStage(2, 3, s2_exp_cand)
  val toS3_nan      = delayToStage(2, 3, s2_nan_flag)

  // ------------------------------
  // S3 : Convert@Dep1, else Adder2
  // ------------------------------
  for (i <- 0 until convert1.io.in.length) {
    val g = i / 16; val k = i % 16
    convert1.io.in(i) := s3_adder1_out(g)(k)
  }
  convert1.io.depth    := depth_s3
  convert1.io.nan      := toS3_nan
  convert1.io.exponent := toS3_exp_cand

  for (i <- 0 until 8) {
    adder2(i).io.depth := depth_s3
    adder2(i).io.in    := s3_adder1_out(i)
  }
  val s4_adder2_out = (0 until 8).map(i => regNextVec(adder2(i).io.out))

  // ---------------------------------
  // S4: Convert@Dep2, else Adder3
  // ---------------------------------
  val toS4_exp_cand = delayToStage(2, 4, s2_exp_cand)
  val toS4_nan      = delayToStage(2, 4, s2_nan_flag)

  for (i <- 0 until convert2.io.in.length) {
    val g = i / 8; val k = i % 8
    convert2.io.in(i) := s4_adder2_out(g)(k)
  }
  convert2.io.depth    := depth_s4
  convert2.io.nan      := toS4_nan
  convert2.io.exponent := toS4_exp_cand

  for (i <- 0 until 8) {
    adder3(i).io.depth := depth_s4
    adder3(i).io.in    := s4_adder2_out(i)
  }
  val s5_adder3_out = (0 until 8).map(i => regNextVec(adder3(i).io.out))

  // ---------------------------------
  // S5: Convert@Dep3, else Adder4
  // ---------------------------------
  val toS5_exp_cand = delayToStage(2, 5, s2_exp_cand)
  val toS5_nan      = delayToStage(2, 5, s2_nan_flag)

  for (i <- 0 until convert3.io.in.length) {
    val g = i / 4; val k = i % 4
    convert3.io.in(i) := s5_adder3_out(g)(k)
  }
  convert3.io.depth    := depth_s5
  convert3.io.nan      := toS5_nan
  convert3.io.exponent := toS5_exp_cand

  for (i <- 0 until 8) {
    adder4(i).io.depth := depth_s5
    adder4(i).io.in    := s5_adder3_out(i)
  }
  val s6_adder4_out = (0 until 8).map(i => regNextVec(adder4(i).io.out))

  // ---------------------------------
  // S6: Convert@Dep4, else Adder5
  // ---------------------------------
  val toS6_exp_cand = delayToStage(2, 6, s2_exp_cand)
  val toS6_nan      = delayToStage(2, 6, s2_nan_flag)

  for (i <- 0 until convert4.io.in.length) {
    val g = i / 2; val k = i % 2
    convert4.io.in(i) := s6_adder4_out(g)(k)
  }
  convert4.io.depth    := depth_s6
  convert4.io.nan      := toS6_nan
  convert4.io.exponent := toS6_exp_cand

  for (i <- 0 until 8) {
    adder5(i).io.depth := depth_s6
    adder5(i).io.in    := s6_adder4_out(i)
  }

  val s7_adder5_out = VecInit((0 until 8).map(i => RegNext(adder5(i).io.out)))
  for (i <- 0 until 8) convert5.io.in(i) := s7_adder5_out(i)

  // ---------------------------------
  // S7: Convert@Dep5, else Expansion_Groupwise & NaN_Process
  // ---------------------------------
  val toS7_exp_cand = delayToStage(2, 7, s2_exp_cand)
  val toS7_nan      = delayToStage(2, 7, s2_nan_flag)

  convert5.io.depth    := depth_s7
  convert5.io.nan      := toS7_nan
  convert5.io.exponent := toS7_exp_cand

  expansion_groupwise.io.depth := depth_s7
  for (i <- 0 until 8) {
    expansion_groupwise.io.in(i)       := s7_adder5_out(i)
    expansion_groupwise.io.exponent(i) := toS7_exp_cand(i)
  }
  val s8_gw_sign     = RegNext(expansion_groupwise.io.out_sign)
  val s8_gw_mantissa = RegNext(expansion_groupwise.io.out_mantissa)
  val s8_gw_emax     = RegNext(expansion_groupwise.io.out_exponent_gmax)
  val s8_nan_proc    = RegNext({ nan_process.io.depth := depth_s7; (0 until 8).foreach(i => nan_process.io.group_nan(i) := toS7_nan(i)); nan_process.io.result_nan })

  // ---------------------------------
  // S8: Adder_Groupwise_6
  // ---------------------------------
  adder_groupwise_6.io.depth    := depth_s8
  adder_groupwise_6.io.sign     := s8_gw_sign
  adder_groupwise_6.io.mantissa := s8_gw_mantissa
  val s9_ad6_sign     = RegNext(adder_groupwise_6.io.out_sign)
  val s9_ad6_mantissa = RegNext(adder_groupwise_6.io.out_mantissa)

  // ---------------------------------
  // S9: Convert@Dep6, else Adder_Groupwise_7
  // ---------------------------------
  val toS9_gw_emax = delayToStage(8, 9, s8_gw_emax)
  val toS9_nan     = delayToStage(8, 9, s8_nan_proc)

  convert_groupwise_6.io.depth    := depth_s9
  convert_groupwise_6.io.sign     := s9_ad6_sign
  convert_groupwise_6.io.mantissa := s9_ad6_mantissa
  convert_groupwise_6.io.exponent := toS9_gw_emax
  convert_groupwise_6.io.nan      := toS9_nan

  adder_groupwise_7.io.depth    := depth_s9
  adder_groupwise_7.io.sign     := s9_ad6_sign
  adder_groupwise_7.io.mantissa := s9_ad6_mantissa
  val s10_ad7_sign     = RegNext(adder_groupwise_7.io.out_sign)
  val s10_ad7_mantissa = RegNext(adder_groupwise_7.io.out_mantissa)

  // ---------------------------------
  // S10: Convert@Dep7, else Adder_Groupwise_8
  // ---------------------------------
  val toS10_gw_emax = delayToStage(8, 10, s8_gw_emax)
  val toS10_nan     = delayToStage(8, 10, s8_nan_proc)

  convert_groupwise_7.io.depth    := depth_s10
  convert_groupwise_7.io.sign     := s10_ad7_sign
  convert_groupwise_7.io.mantissa := s10_ad7_mantissa
  convert_groupwise_7.io.exponent := toS10_gw_emax
  convert_groupwise_7.io.nan      := toS10_nan

  adder_groupwise_8.io.depth    := depth_s10
  adder_groupwise_8.io.sign     := s10_ad7_sign
  adder_groupwise_8.io.mantissa := s10_ad7_mantissa
  val s11_ad8_sign     = RegNext(adder_groupwise_8.io.out_sign)
  val s11_ad8_mantissa = RegNext(adder_groupwise_8.io.out_mantissa)

  // ---------------------------------
  // S11: Convert@Dep8
  // ---------------------------------
  val toS11_gw_emax = delayToStage(8, 11, s8_gw_emax)
  val toS11_nan     = delayToStage(8, 11, s8_nan_proc)

  convert_groupwise_8.io.depth    := depth_s11
  convert_groupwise_8.io.sign     := s11_ad8_sign
  convert_groupwise_8.io.mantissa := s11_ad8_mantissa
  convert_groupwise_8.io.exponent := toS11_gw_emax
  convert_groupwise_8.io.nan      := toS11_nan

  // ---------------------------------
  // 변환 결과를 S11까지 지연 → depth 스위치 일원화
  // ---------------------------------
  def padTo16(vec: Vec[FP32]): Vec[FP32] =
    VecInit((0 until 16).map(i => if (i < vec.length) vec(i) else 0.U.asTypeOf(new FP32)))

  val d0_atS11 = pipeVecN(padTo16(convert0.io.out),            9) // S2→S11
  val d1_atS11 = pipeVecN(padTo16(convert1.io.out),            8) // S3→S11
  val d2_atS11 = pipeVecN(padTo16(convert2.io.out),            7) // S4→S11
  val d3_atS11 = pipeVecN(padTo16(convert3.io.out),            6) // S5→S11
  val d4_atS11 = pipeVecN(padTo16(convert4.io.out),            5) // S6→S11
  val d5_atS11 = pipeVecN(padTo16(convert5.io.out),            4) // S7→S11
  val d6_atS11 = pipeVecN(padTo16(convert_groupwise_6.io.out), 2) // S9→S11
  val d7_atS11 = pipeVecN(padTo16(convert_groupwise_7.io.out), 1) // S10→S11
  val d8_atS11 = padTo16(convert_groupwise_8.io.out)                 // S11


  val selected_out = Wire(Vec(16, new FP32))
  selected_out := 0.U.asTypeOf(Vec(16, new FP32))
  switch(depth_s11) {
    is(0.U) { selected_out := d0_atS11 }
    is(1.U) { selected_out := d1_atS11 }
    is(2.U) { selected_out := d2_atS11 }
    is(3.U) { selected_out := d3_atS11 }
    is(4.U) { selected_out := d4_atS11 }
    is(5.U) { selected_out := d5_atS11 }
    is(6.U) { selected_out := d6_atS11 }
    is(7.U) { selected_out := d7_atS11 }
    is(8.U) { selected_out := d8_atS11 }
  }
  io.out := selected_out
}
