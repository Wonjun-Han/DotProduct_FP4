package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_TOP_Til_Dep_total_PIPED_CT_SYN_CSA_LUT_BLOCK_IO extends Bundle {
  val a_vec   = Input(Vec(256, UInt(4.W)))
  val b_vec   = Input(Vec(256, UInt(4.W)))
  val a_scale = Input(Vec(8, UInt(8.W)))
  val b_scale = Input(Vec(8, UInt(8.W)))
  val depth   = Input(UInt(4.W))
  val out     = Output(Vec(16, new FP32))
}

class p_TOP_Til_Dep_total_piped_CT_syn_CSA_LUT extends Module {
  val io = IO(new p_TOP_Til_Dep_total_PIPED_CT_SYN_CSA_LUT_BLOCK_IO)

  // --------------------------
  // Util: Vec Register Pipe
  // --------------------------
  private def regNextVec[T <: Data](v: Vec[T]): Vec[T] = VecInit(v.map(RegNext(_)))
  private def pipeVecN[T <: Data](v: Vec[T], n: Int): Vec[T] =
    (0 until n).foldLeft(v){ case (acc, _) => regNextVec(acc) }
  private def delayToStage[T <: Data](fromS: Int, toS: Int, v: Vec[T]): Vec[T] = {
    val n = (toS - fromS) max 0
    pipeVecN(v, n)
  }

  // --------------------------
  // Input Register
  // --------------------------
  val in_a_vec   = regNextVec(io.a_vec)
  val in_b_vec   = regNextVec(io.b_vec)
  val in_a_scale = regNextVec(io.a_scale)
  val in_b_scale = regNextVec(io.b_scale)
  val in_depth   = RegNext(io.depth)


  val depth_s1  = RegNext(in_depth)
  val depth_s2  = RegNext(depth_s1)
  val depth_s3  = RegNext(depth_s2)
  val depth_s4  = RegNext(depth_s3)
  val depth_s5  = RegNext(depth_s4)
  val depth_s6  = RegNext(depth_s5)
  val depth_s7  = RegNext(depth_s6)
  val depth_s8  = RegNext(depth_s7)

  // ---------------------------------
  // instance
  // ---------------------------------
  val mult   = Module(new p_Multiplier)
  val scaleSum   = Module(new p_Adder_ScaleSum)

  val LUT_expansion = Module(new p_LUT_2D)

  val csa_groupin = Seq.fill(8)(Module(new p_CSA_Total(9, 32, 14)))
  val csa_groupwise = Module(new p_CSA_Total(44, 8, 47)) // 8-groupwise CSA 1+13+30

  val adder_sumcarry_groupin = Seq.fill(8)(Module(new p_Adder_sumcarry(14)))
  val adder_sumcarry_groupwise = Module(new p_Adder_sumcarry(47))

  val convert0 = Module(new p_MulConvert)

  val convert5 = Module(new p_Convert_CSA(5))

  val expansion_groupwise = Module(new p_Expansion_Groupwise_CSA(5, 30))
  val nan_process         = Module(new p_NaN_Process(5))

  val convert_twos_groupwise = Module(new p_Convert_Twos(5, 30))

  val convert_groupwise_8 = Module(new p_Convert_Groupwise_CSA(8, 30))

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
  // S1: LUT_Expansion for 256 inputs
  // ---------------------------------
  for (i <- 0 until 256) {
    LUT_expansion.io.sign(i)     := s1_sign(i)
    LUT_expansion.io.exponent(i) := s1_exponent(i)
    LUT_expansion.io.mantissa(i) := s1_mantissa(i)
  }

  val s2_out_LUT_expansion = regNextVec(LUT_expansion.io.out)

  // ---------------------------------
  // S2: Convert@Dep0, else CSA_groupin
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

  for (i <- 0 until 256) {
    csa_groupin(i / 32).io.in(i % 32) := s2_out_LUT_expansion(i)
  }

  val s3_csa_groupin_out = (0 until 8).map(i => regNextVec(csa_groupin(i).io.out))

  // ------------------------------
  // S3 : Adder_sumcarry_groupin
  // ------------------------------
  for (i <- 0 until 8) {
    adder_sumcarry_groupin(i).io.in := s3_csa_groupin_out(i)  
  }
  val s4_addsc_groupin_out = (0 until 8).map(i => RegNext(adder_sumcarry_groupin(i).io.sum))

  // ---------------------------------
  // S4: Convert@Dep5, else Expansion_Groupwise & NaN_Process
  // ---------------------------------

  val toS4_scale_nan      = delayToStage(2, 4, toS2_scale_nan)
  val toS4_scale_sum      = delayToStage(2, 4, toS2_scale_sum)

  for (i <- 0 until 8) convert5.io.in(i) := s4_addsc_groupin_out(i)
  convert5.io.depth    := depth_s4
  convert5.io.nan      := toS4_scale_nan
  convert5.io.exponent := toS4_scale_sum

  expansion_groupwise.io.depth := depth_s4
  for (i <- 0 until 8) {
    expansion_groupwise.io.in(i)       := s4_addsc_groupin_out(i)
    expansion_groupwise.io.exponent(i) := toS4_scale_sum(i)
  }
  val s5_gw_sign     = RegNext(expansion_groupwise.io.out_sign)
  val s5_gw_mantissa = RegNext(expansion_groupwise.io.out_mantissa)
  val s5_gw_emax     = RegNext(expansion_groupwise.io.out_exponent_gmax)
  val s5_nan_proc    = RegNext({ nan_process.io.depth := depth_s4; (0 until 8).foreach(i => nan_process.io.group_nan(i) := toS4_scale_nan(i)); nan_process.io.result_nan })

  // ---------------------------------
  // S5: CSA_groupwise
  // ---------------------------------
  convert_twos_groupwise.io.in := s5_gw_mantissa
  convert_twos_groupwise.io.sign := s5_gw_sign
  // Convert each SInt element to UInt individually
  for (i <- 0 until 8) {
    csa_groupwise.io.in(i) := convert_twos_groupwise.io.out(i).asUInt
  }

  val s6_csa_groupwise_out = RegNext(csa_groupwise.io.out)

  // ---------------------------------
  // S6: Adder_sumcarry_groupwise
  // ---------------------------------

  adder_sumcarry_groupwise.io.in := s6_csa_groupwise_out
  val s7_addsc_groupwise_out = RegNext(adder_sumcarry_groupwise.io.sum)

  // ---------------------------------
  // S7: Convert@Dep8
  // ---------------------------------

  val toS7_gw_emax = delayToStage(5, 7, s5_gw_emax)
  val toS7_nan     = delayToStage(5, 7, s5_nan_proc)

  convert_groupwise_8.io.depth    := depth_s7
  convert_groupwise_8.io.in(0)    := s7_addsc_groupwise_out
  convert_groupwise_8.io.exponent := toS7_gw_emax
  convert_groupwise_8.io.nan      := toS7_nan

  // ---------------------------------
  // 변환 결과를 S7까지 지연 → depth 스위치 일원화
  // ---------------------------------
  def padTo16(vec: Vec[FP32]): Vec[FP32] =
    VecInit((0 until 16).map(i => if (i < vec.length) vec(i) else 0.U.asTypeOf(new FP32)))

  val d0_atS7 = pipeVecN(padTo16(convert0.io.out),            5) // S2→S7
  val d5_atS7 = pipeVecN(padTo16(convert5.io.out),            3) // S4→S7
  val d8_atS7 = padTo16(convert_groupwise_8.io.out)              // S7

  val selected_out = WireDefault(VecInit(Seq.fill(16)(0.U.asTypeOf(new FP32))))

  // ---------------------------------
  // Output register
  // ---------------------------------
  class FF16_FP32 extends Module {
    val io = IO(new Bundle {
      val in  = Input (Vec(16, new FP32))
      val out = Output(Vec(16, new FP32))
    })
    val r = Reg(Vec(16, new FP32))  // 순수 FF
    r := io.in                      // D <= in (조합 입력만 받음)
    io.out := r
  }

  when(depth_s7 === 0.U) { selected_out := d0_atS7 }
  .elsewhen(depth_s7 === 5.U) { selected_out := d5_atS7 }
  .elsewhen(depth_s7 === 8.U) { selected_out := d8_atS7 }

  val outff = Module(new FF16_FP32)
  outff.io.in := selected_out      
  io.out      := outff.io.out       
}
