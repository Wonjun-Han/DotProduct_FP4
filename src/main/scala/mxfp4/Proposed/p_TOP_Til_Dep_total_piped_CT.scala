package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_TOP_Til_Dep_total_PIPED_CT_BLOCK_IO extends Bundle {
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

  // Token debug (TB에서 io_dbg_*로 flatten되니까 주의하자 ㅇㅇ)
  val dbg_token_in  = Input(UInt(8.W))           // 매 트랜잭션 주입 토큰
  val dbg_token_sel = Output(UInt(8.W))          // S12에서 depth 선택된 경로의 토큰
  val dbg_token_d   = Output(Vec(9, UInt(8.W)))  // d0..d8 경로별 S12 시점 토큰
}

class p_TOP_Til_Dep_total_piped_CT extends Module {
  val io = IO(new p_TOP_Til_Dep_total_PIPED_CT_BLOCK_IO)

  // --------------------------
  // 유틸: Vec 레지스터 파이프
  // --------------------------
  private def regNextVec[T <: Data](v: Vec[T]): Vec[T] = VecInit(v.map(RegNext(_)))
  private def pipeVecN[T <: Data](v: Vec[T], n: Int): Vec[T] =
    (0 until n).foldLeft(v){ case (acc, _) => regNextVec(acc) }

  private def delayToStage[T <: Data](fromS: Int, toS: Int, v: Vec[T]): Vec[T] = {
    val n = (toS - fromS) max 0
    pipeVecN(v, n)
  }

  // UInt 파이프 유틸
  private def pipeUIntN(u: UInt, n: Int): UInt =
    (0 until (n max 0)).foldLeft(u){ case (acc, _) => RegNext(acc) }

  // ---------------------------------
  // 모듈 인스턴스
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
  // Depth 파이프라인 (S1..S12)
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
  // Token 파이프라인 (S1..S12) — 데이터 파이프와 동일 단계
  // ---------------------------------
  val tok_s1  = RegNext(io.dbg_token_in)
  val tok_s2  = RegNext(tok_s1)
  val tok_s3  = RegNext(tok_s2)
  val tok_s4  = RegNext(tok_s3)
  val tok_s5  = RegNext(tok_s4)
  val tok_s6  = RegNext(tok_s5)
  val tok_s7  = RegNext(tok_s6)
  val tok_s8  = RegNext(tok_s7)
  val tok_s9  = RegNext(tok_s8)
  val tok_s10 = RegNext(tok_s9)
  val tok_s11 = RegNext(tok_s10)
  val tok_s12 = RegNext(tok_s11)

  private def tokenAt(stage: Int): UInt = stage match {
    case 1  => tok_s1
    case 2  => tok_s2
    case 3  => tok_s3
    case 4  => tok_s4
    case 5  => tok_s5
    case 6  => tok_s6
    case 7  => tok_s7
    case 8  => tok_s8
    case 9  => tok_s9
    case 10 => tok_s10
    case 11 => tok_s11
    case _  => tok_s12
  }

  // ---------------------------------
  // S1: Mult + ScaleSum (Comb) → Reg
  // ---------------------------------
  mult.io.a_vec := io.a_vec
  mult.io.b_vec := io.b_vec
  mult.io.depth := io.depth

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
    scaleEmax.io.emax(i)      := expansion.io.out_exponent_gmax(0)

    adder1(i).io.depth    := depth_s2
    adder1(i).io.sign     := RegNext(expansion.io.out_sign)
    adder1(i).io.mantissa := RegNext(expansion.io.out_mantissa)
  }

  val s2_exp_cand = regNextVec(scaleEmax.io.out)
  val s2_nan_flag = regNextVec(scaleEmax.io.nan)

  // ---------------------------------
  // S3: depth=0 → Convert@Dep0, else → Adder1 → Reg
  // ---------------------------------
  val toS3_scale_sum = delayToStage(2, 3, s1_scale_sum)
  val toS3_scale_nan = delayToStage(2, 3, s1_scale_nan)
  val toS3_sign      = delayToStage(2, 3, s1_sign)
  val toS3_exp       = delayToStage(2, 3, s1_exponent)
  val toS3_man       = delayToStage(2, 3, s1_mantissa)

  convert0.io.sign      := toS3_sign
  convert0.io.exponent  := toS3_exp
  convert0.io.mantissa  := toS3_man
  convert0.io.scale_sum := toS3_scale_sum
  convert0.io.nan       := toS3_scale_nan

  val s3_adder1_out = (0 until 8).map(i => regNextVec(adder1(i).io.out))

  // ---------------------------------
  // S4: depth=1 → Convert@Dep1, else → Adder2 → Reg
  // ---------------------------------
  val toS4_exp_cand = delayToStage(3, 4, s2_exp_cand)
  val toS4_nan      = delayToStage(3, 4, s2_nan_flag)

  for (i <- 0 until convert1.io.in.length) {
    val g = i / 16; val k = i % 16
    convert1.io.in(i) := s3_adder1_out(g)(k)
  }
  convert1.io.depth    := depth_s4
  convert1.io.nan      := toS4_nan
  convert1.io.exponent := toS4_exp_cand

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

  for (i <- 0 until convert2.io.in.length) {
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

  for (i <- 0 until convert3.io.in.length) {
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

  for (i <- 0 until convert4.io.in.length) {
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
    expansion_groupwise.io.in(i)       := s7_adder5_out(i)
    expansion_groupwise.io.exponent(i) := toS8_exp_cand(i)
  }
  val s8_gw_sign     = RegNext(expansion_groupwise.io.out_sign)
  val s8_gw_mantissa = RegNext(expansion_groupwise.io.out_mantissa)
  val s8_gw_emax     = RegNext(expansion_groupwise.io.out_exponent_gmax)

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
  val toS10_gw_emax = delayToStage(9, 10, s8_gw_emax)
  val toS10_nan     = delayToStage(9, 10, s8_nan_proc)

  convert_groupwise_6.io.depth    := depth_s10
  convert_groupwise_6.io.sign     := s9_ad6_sign
  convert_groupwise_6.io.mantissa := s9_ad6_mantissa
  convert_groupwise_6.io.exponent := toS10_gw_emax
  convert_groupwise_6.io.nan      := toS10_nan

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
  // 결과를 S12까지 정렬 (데이터)
  // ---------------------------------
  def padTo16(vec: Vec[FP32]): Vec[FP32] =
    VecInit((0 until 16).map(i => if (i < vec.length) vec(i) else 0.U.asTypeOf(new FP32)))

  def pipeToS12(producedAtStage: Int, internalLatency: Int, v: Vec[FP32]): Vec[FP32] = {
    val validAt = producedAtStage + internalLatency
    val regs    = (12 - validAt) max 0
    pipeVecN(padTo16(v), regs)
  }

  // 각 depth 경로의 입력 스테이지
  val S_of = Map(
    0 -> 3,   // convert0 inputs @ S3
    1 -> 4,   // convert1 inputs @ S4
    2 -> 5,   // convert2 inputs @ S5
    3 -> 6,   // convert3 inputs @ S6
    4 -> 7,   // convert4 inputs @ S7
    5 -> 8,   // convert5 inputs @ S8
    6 -> 10,  // convert_groupwise_6 inputs @ S10
    7 -> 11,  // convert_groupwise_7 inputs @ S11
    8 -> 12   // convert_groupwise_8 inputs @ S12
  )

  // Convert/Groupwise 내부 레이턴시(데이터 정렬용). 필요 시 조정.
  val L_mulconv = 0
  val L_conv = Map(1 -> 0, 2 -> 0, 3 -> 0, 4 -> 0, 5 -> 0)
  val L_gw   = Map(6 -> 0, 7 -> 0, 8 -> 0)

  // 데이터 경로 S12 정렬
  val d0_atS12 = pipeToS12(S_of(0), L_mulconv,          convert0.io.out)
  val d1_atS12 = pipeToS12(S_of(1), L_conv(1),          convert1.io.out)
  val d2_atS12 = pipeToS12(S_of(2), L_conv(2),          convert2.io.out)
  val d3_atS12 = pipeToS12(S_of(3), L_conv(3),          convert3.io.out)
  val d4_atS12 = pipeToS12(S_of(4), L_conv(4),          convert4.io.out)
  val d5_atS12 = pipeToS12(S_of(5), L_conv(5),          convert5.io.out)
  val d6_atS12 = pipeToS12(S_of(6), L_gw(6),            convert_groupwise_6.io.out)
  val d7_atS12 = pipeToS12(S_of(7), L_gw(7),            convert_groupwise_7.io.out)
  val d8_atS12 = pipeToS12(S_of(8), L_gw(8),            convert_groupwise_8.io.out)

  // ---------------------------------
  // 토큰 경로 S12 정렬 (중요 포인트)
  //  - 토큰은 해당 경로의 입력 스테이지 S_of에서의 토큰을 기준으로
  //    S12까지 (12 - S_of)단 지연하면 데이터와 정확히 일치
  //  - 내부 레이턴시는 데이터 쪽 pipeToS12에서 이미 처리됨... 왜 안되노...
  // ---------------------------------
  def tokToS12(startStage: Int): UInt = {
    val tokAtStart = tokenAt(startStage)
    pipeUIntN(tokAtStart, 12 - startStage)
  }

  val t0_atS12 = tokToS12(S_of(0))
  val t1_atS12 = tokToS12(S_of(1))
  val t2_atS12 = tokToS12(S_of(2))
  val t3_atS12 = tokToS12(S_of(3))
  val t4_atS12 = tokToS12(S_of(4))
  val t5_atS12 = tokToS12(S_of(5))
  val t6_atS12 = tokToS12(S_of(6))
  val t7_atS12 = tokToS12(S_of(7))
  val t8_atS12 = tokToS12(S_of(8))

  // 디버그 출력 (TB에서 io_dbg_token_d_0..8로 읽힘)
  io.dbg_token_d := VecInit(Seq(
    t0_atS12, t1_atS12, t2_atS12, t3_atS12, t4_atS12, t5_atS12, t6_atS12, t7_atS12, t8_atS12
  ))

  // depth_s12 선택과 동일한 방식으로 토큰도 선택
  val dbgTokSel = WireDefault(0.U(8.W))
  switch(depth_s12) {
    is(0.U) { dbgTokSel := t0_atS12 }
    is(1.U) { dbgTokSel := t1_atS12 }
    is(2.U) { dbgTokSel := t2_atS12 }
    is(3.U) { dbgTokSel := t3_atS12 }
    is(4.U) { dbgTokSel := t4_atS12 }
    is(5.U) { dbgTokSel := t5_atS12 }
    is(6.U) { dbgTokSel := t6_atS12 }
    is(7.U) { dbgTokSel := t7_atS12 }
    is(8.U) { dbgTokSel := t8_atS12 }
  }
  io.dbg_token_sel := dbgTokSel

  // ---------------------------------
  // 최종 출력 선택 (데이터)
  // ---------------------------------
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
