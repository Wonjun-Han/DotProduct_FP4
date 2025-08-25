package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_TOP_Til_Dep_total_COMB_CT_SYN_BLOCK_IO extends Bundle {
  val a_vec   = Input(Vec(256, UInt(4.W)))
  val b_vec   = Input(Vec(256, UInt(4.W)))
  val a_scale = Input(Vec(8, UInt(8.W)))
  val b_scale = Input(Vec(8, UInt(8.W)))
  val depth   = Input(UInt(4.W))
  val out     = Output(Vec(16, new FP32))
}

class p_TOP_Til_Dep_total_comb_CT_syn extends Module {
  val io = IO(new p_TOP_Til_Dep_total_COMB_CT_SYN_BLOCK_IO)

  // --------------------------
  // 맨 앞 입력 레지스터만 사용
  // --------------------------
  private def regNextVec[T <: Data](v: Vec[T]): Vec[T] = VecInit(v.map(RegNext(_)))

  val in_a_vec   = regNextVec(io.a_vec)
  val in_b_vec   = regNextVec(io.b_vec)
  val in_a_scale = regNextVec(io.a_scale)
  val in_b_scale = regNextVec(io.b_scale)
  val in_depth   = RegNext(io.depth) // depth도 앞단에서만 래치

  // ---------------------------------
  // 인스턴스 생성 (내부는 조합 경로로 연결)
  // ---------------------------------
  val mult        = Module(new p_Multiplier)
  val scaleSum    = Module(new p_Adder_ScaleSum)
  val scaleEmax   = Module(new p_Adder_ScaleEmax)

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
  // S0: Mult & ScaleSum (조합)
  // ---------------------------------
  mult.io.a_vec := in_a_vec
  mult.io.b_vec := in_b_vec
  mult.io.depth := in_depth

  scaleSum.io.a_scale := in_a_scale
  scaleSum.io.b_scale := in_b_scale

  val w1_sign      = mult.io.sign
  val w1_exponent  = mult.io.exponent
  val w1_mantissa  = mult.io.mantissa
  val w1_scale_sum = scaleSum.io.out
  val w1_scale_nan = scaleSum.io.nan

  // ---------------------------------
  // S1: Expansion(in-group) & (Emax + scale_sum) (조합)
  // ---------------------------------
  scaleEmax.io.depth := in_depth
  for (i <- 0 until 8) {
    val base = i * 32
    val expansion = Module(new p_Expansion)
    expansion.io.depth    := in_depth
    expansion.io.sign     := w1_sign.slice(base, base + 32)
    expansion.io.exponent := w1_exponent.slice(base, base + 32)
    expansion.io.mantissa := w1_mantissa.slice(base, base + 32)

    scaleEmax.io.nan_in(i)       := w1_scale_nan(i)
    scaleEmax.io.scale_sum(i) := w1_scale_sum(i)
    scaleEmax.io.emax(i)      := expansion.io.out_exponent_gmax(0)

    adder1(i).io.depth    := in_depth
    adder1(i).io.sign     := expansion.io.out_sign
    adder1(i).io.mantissa := expansion.io.out_mantissa
  }

  val w2_exp_cand = scaleEmax.io.out
  val w2_nan_flag = scaleEmax.io.nan_out  

  // ---------------------------------
  // Convert@Dep0 (조합)
  // ---------------------------------
  convert0.io.sign      := w1_sign
  convert0.io.exponent  := w1_exponent
  convert0.io.mantissa  := w1_mantissa
  convert0.io.scale_sum := w1_scale_sum
  convert0.io.nan       := w1_scale_nan

  // ---------------------------------
  // S3: Convert@Dep1 / Adder2 (조합)
  // ---------------------------------
  for (i <- 0 until convert1.io.in.length) {
    val g = i / 16; val k = i % 16
    convert1.io.in(i) := adder1(g).io.out(k)
  }
  convert1.io.depth    := in_depth
  convert1.io.nan      := w2_nan_flag
  convert1.io.exponent := w2_exp_cand

  for (i <- 0 until 8) {
    adder2(i).io.depth := in_depth
    adder2(i).io.in    := adder1(i).io.out
  }

  // ---------------------------------
  // S4: Convert@Dep2 / Adder3 (조합)
  // ---------------------------------
  for (i <- 0 until convert2.io.in.length) {
    val g = i / 8; val k = i % 8
    convert2.io.in(i) := adder2(g).io.out(k)
  }
  convert2.io.depth    := in_depth
  convert2.io.nan      := w2_nan_flag
  convert2.io.exponent := w2_exp_cand

  for (i <- 0 until 8) {
    adder3(i).io.depth := in_depth
    adder3(i).io.in    := adder2(i).io.out
  }

  // ---------------------------------
  // S5: Convert@Dep3 / Adder4 (조합)
  // ---------------------------------
  for (i <- 0 until convert3.io.in.length) {
    val g = i / 4; val k = i % 4
    convert3.io.in(i) := adder3(g).io.out(k)
  }
  convert3.io.depth    := in_depth
  convert3.io.nan      := w2_nan_flag
  convert3.io.exponent := w2_exp_cand

  for (i <- 0 until 8) {
    adder4(i).io.depth := in_depth
    adder4(i).io.in    := adder3(i).io.out
  }

  // ---------------------------------
  // S6: Convert@Dep4 / Adder5 (조합)
  // ---------------------------------
  for (i <- 0 until convert4.io.in.length) {
    val g = i / 2; val k = i % 2
    convert4.io.in(i) := adder4(g).io.out(k)
  }
  convert4.io.depth    := in_depth
  convert4.io.nan      := w2_nan_flag
  convert4.io.exponent := w2_exp_cand

  for (i <- 0 until 8) {
    adder5(i).io.depth := in_depth
    adder5(i).io.in    := adder4(i).io.out
  }

  // Convert@Dep5 (조합)
  for (i <- 0 until 8) { convert5.io.in(i) := adder5(i).io.out }
  convert5.io.depth    := in_depth
  convert5.io.nan      := w2_nan_flag
  convert5.io.exponent := w2_exp_cand

  // ---------------------------------
  // Groupwise Expansion & NaN 처리 (조합)
  // ---------------------------------
  expansion_groupwise.io.depth := in_depth
  for (i <- 0 until 8) {
    expansion_groupwise.io.in(i)       := adder5(i).io.out
    expansion_groupwise.io.exponent(i) := w2_exp_cand(i) // 동일 지수 후보 사용
  }

  nan_process.io.depth := in_depth
  for (i <- 0 until 8) { nan_process.io.group_nan(i) := w2_nan_flag(i) }

  val w_gw_sign     = expansion_groupwise.io.out_sign
  val w_gw_mantissa = expansion_groupwise.io.out_mantissa
  val w_gw_emax     = expansion_groupwise.io.out_exponent_gmax
  val w_nan_proc    = nan_process.io.result_nan

  // ---------------------------------
  // Groupwise Adders (조합)
  // ---------------------------------
  adder_groupwise_6.io.depth    := in_depth
  adder_groupwise_6.io.sign     := w_gw_sign
  adder_groupwise_6.io.mantissa := w_gw_mantissa

  adder_groupwise_7.io.depth    := in_depth
  adder_groupwise_7.io.sign     := adder_groupwise_6.io.out_sign
  adder_groupwise_7.io.mantissa := adder_groupwise_6.io.out_mantissa

  adder_groupwise_8.io.depth    := in_depth
  adder_groupwise_8.io.sign     := adder_groupwise_7.io.out_sign
  adder_groupwise_8.io.mantissa := adder_groupwise_7.io.out_mantissa

  // ---------------------------------
  // Groupwise Converts (조합)
  // (w_gw_emax / w_nan_proc는 동일한 값을 공유)
  // ---------------------------------
  convert_groupwise_6.io.depth    := in_depth
  convert_groupwise_6.io.sign     := adder_groupwise_6.io.out_sign
  convert_groupwise_6.io.mantissa := adder_groupwise_6.io.out_mantissa
  convert_groupwise_6.io.exponent := w_gw_emax
  convert_groupwise_6.io.nan      := w_nan_proc

  convert_groupwise_7.io.depth    := in_depth
  convert_groupwise_7.io.sign     := adder_groupwise_7.io.out_sign
  convert_groupwise_7.io.mantissa := adder_groupwise_7.io.out_mantissa
  convert_groupwise_7.io.exponent := w_gw_emax
  convert_groupwise_7.io.nan      := w_nan_proc

  convert_groupwise_8.io.depth    := in_depth
  convert_groupwise_8.io.sign     := adder_groupwise_8.io.out_sign
  convert_groupwise_8.io.mantissa := adder_groupwise_8.io.out_mantissa
  convert_groupwise_8.io.exponent := w_gw_emax
  convert_groupwise_8.io.nan      := w_nan_proc

  // ---------------------------------
  // Depth 스위치: 모두 조합 선택
  // ---------------------------------
  def padTo16(vec: Vec[FP32]): Vec[FP32] =
    VecInit((0 until 16).map(i => if (i < vec.length) vec(i) else 0.U.asTypeOf(new FP32)))

  val d0 = padTo16(convert0.io.out)
  val d1 = padTo16(convert1.io.out)
  val d2 = padTo16(convert2.io.out)
  val d3 = padTo16(convert3.io.out)
  val d4 = padTo16(convert4.io.out)
  val d5 = padTo16(convert5.io.out)
  val d6 = padTo16(convert_groupwise_6.io.out)
  val d7 = padTo16(convert_groupwise_7.io.out)
  val d8 = padTo16(convert_groupwise_8.io.out)

  val selected_out = WireDefault(VecInit(Seq.fill(16)(0.U.asTypeOf(new FP32))))
  when(in_depth === 0.U)      { selected_out := d0 }
  .elsewhen(in_depth === 1.U) { selected_out := d1 }
  .elsewhen(in_depth === 2.U) { selected_out := d2 }
  .elsewhen(in_depth === 3.U) { selected_out := d3 }
  .elsewhen(in_depth === 4.U) { selected_out := d4 }
  .elsewhen(in_depth === 5.U) { selected_out := d5 }
  .elsewhen(in_depth === 6.U) { selected_out := d6 }
  .elsewhen(in_depth === 7.U) { selected_out := d7 }
  .elsewhen(in_depth === 8.U) { selected_out := d8 }

  // ---------------------------------
  // (유지) 맨 끝 출력 FF만 사용
  // ---------------------------------
  class FF16_FP32 extends Module {
    val io = IO(new Bundle {
      val in  = Input (Vec(16, new FP32))
      val out = Output(Vec(16, new FP32))
    })
    val r = Reg(Vec(16, new FP32))
    r := io.in
    io.out := r
  }

  val outff = Module(new FF16_FP32)
  outff.io.in := selected_out
  io.out      := outff.io.out
}
