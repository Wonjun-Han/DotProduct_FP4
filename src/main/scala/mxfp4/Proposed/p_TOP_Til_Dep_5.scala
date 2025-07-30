package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_TOP_Til_Dep_5_IO extends Bundle {
  val a_vec  = Input(Vec(256, UInt(4.W)))
  val b_vec  = Input(Vec(256, UInt(4.W)))
  val a_scale = Input(Vec(8, UInt(8.W)))
  val b_scale = Input(Vec(8, UInt(8.W)))
  val depth  = Input(UInt(3.W))
  val out = Output(Vec(8, new FP32))     
  val out_FP32 = Output(Vec(256, new FP32))

  // for debugging p_Multiplier
  val debug_mul_exp = Output(Vec(256, UInt(3.W))) // Multiplier exponent output

  // for debugging p_Expansion
  val debug_exp_gmax = Output(Vec(8, UInt(3.W))) // Group max exponent

  //for debugging ScaleSum
  val debug_scale_sum   = Output(Vec(8, SInt(10.W)))

  //for debugging ScaleEmax
  val debug_scale_emax = Output(Vec(8, SInt(10.W)))

  //for debugging p_Adder_Dep_5
  val debug_accum = Output(Vec(8, SInt(14.W))) // Accumulator output

  //for debugging p_Convert_Dep_5
  val debug_real_exp   = Output(Vec(8, SInt(10.W)))
  val debug_biased_exp = Output(Vec(8, SInt(10.W)))
  val debug_shift_amt  = Output(Vec(8, SInt(5.W)))
  val debug_PE         = Output(Vec(8, UInt(4.W)))
  val debug_abs_in     = Output(Vec(8, UInt(13.W)))

}

class p_TOP_Til_Dep_5 extends Module {
  val io = IO(new p_TOP_Til_Dep_5_IO)
  val scale_sum = Module(new p_Adder_ScaleSum)
  val mult = Module(new p_Multiplier)
  val conv = Module(new p_MulConvert)
  mult.io.a_vec := io.a_vec
  mult.io.b_vec := io.b_vec
  mult.io.depth := io.depth
  scale_sum.io.a_scale := io.a_scale
  scale_sum.io.b_scale := io.b_scale

  // Depth 0 → FP32 변환
  when(io.depth === 0.U) {
    conv.io.sign     := mult.io.sign
    conv.io.exponent := mult.io.exponent
    conv.io.mantissa := mult.io.mantissa
    conv.io.scale_sum := scale_sum.io.out
    conv.io.nan       := scale_sum.io.nan

    io.out_FP32 := conv.io.out
    io.out := VecInit(Seq.fill(8)(0.U.asTypeOf(new FP32))) // dummy

    // Initialize debug outputs
    io.debug_real_exp   := VecInit(Seq.fill(8)(0.S(10.W)))
    io.debug_biased_exp := VecInit(Seq.fill(8)(0.S(10.W)))
    io.debug_shift_amt  := VecInit(Seq.fill(8)(0.S(5.W)))
    io.debug_PE         := VecInit(Seq.fill(8)(0.U(4.W)))
    io.debug_abs_in     := VecInit(Seq.fill(8)(0.U(13.W)))
    io.debug_scale_sum  := VecInit(Seq.fill(8)(0.S(10.W))) 
    io.debug_scale_emax := VecInit(Seq.fill(8)(0.S(10.W)))
    io.debug_exp_gmax := VecInit(Seq.fill(8)(0.U(3.W))) // Group max exponent
    io.debug_mul_exp := VecInit(Seq.fill(256)(0.U(3.W))) // Multiplier exponent output
    io.debug_accum := VecInit(Seq.fill(8)(0.S(14.W))) // Accumulator output
  }.otherwise {
    // Initialization
    conv.io.sign     := VecInit(Seq.fill(256)(0.U(1.W)))
    conv.io.exponent := VecInit(Seq.fill(256)(0.U(3.W)))
    conv.io.mantissa := VecInit(Seq.fill(256)(0.U(4.W)))
    conv.io.scale_sum := VecInit(Seq.fill(8)(0.S(9.W)))
    conv.io.nan       := VecInit(Seq.fill(8)(0.U(1.W)))
    // Expansion & Adders
    val expansion = Seq.fill(8)(Module(new p_Expansion))
    val dep1 = Seq.fill(8)(Module(new p_Adder_Dep_1))
    val dep2 = Seq.fill(8)(Module(new p_Adder_Dep_2))
    val dep3 = Seq.fill(8)(Module(new p_Adder_Dep_3))
    val dep4 = Seq.fill(8)(Module(new p_Adder_Dep_4))
    val dep5 = Seq.fill(8)(Module(new p_Adder_Dep_5))

    val scale_emax = Module(new p_Adder_ScaleEmax)
    scale_emax.io.depth := io.depth

    val convert_dep_5 = Module(new p_Convert_Dep_5)
    convert_dep_5.io.depth := io.depth
    for (i <- 0 until 8) {
      val base = i * 32
      expansion(i).io.sign     := mult.io.sign.slice(base, base + 32)
      expansion(i).io.exponent := mult.io.exponent.slice(base, base + 32)
      expansion(i).io.mantissa := mult.io.mantissa.slice(base, base + 32)
      expansion(i).io.depth    := io.depth

      // Scale and Emax calculation
      scale_emax.io.nan(i) := scale_sum.io.nan(i)
      scale_emax.io.scale_sum(i) := scale_sum.io.out(i)
      scale_emax.io.emax(i) := expansion(i).io.out_exponent_gmax(0)

      dep1(i).io.sign     := expansion(i).io.out_sign
      dep1(i).io.mantissa := expansion(i).io.out_mantissa
      dep1(i).io.depth    := io.depth

      dep2(i).io.in := dep1(i).io.out
      dep2(i).io.depth := io.depth

      dep3(i).io.in := dep2(i).io.out
      dep3(i).io.depth := io.depth

      dep4(i).io.in := dep3(i).io.out
      dep4(i).io.depth := io.depth

      dep5(i).io.in := dep4(i).io.out
      dep5(i).io.depth := io.depth
      
      convert_dep_5.io.in(i) := dep5(i).io.out
      convert_dep_5.io.nan(i) := scale_emax.io.nan(i)
      convert_dep_5.io.exponent(i) := scale_emax.io.out(i)
      io.out(i) := convert_dep_5.io.out(i)

      //for debugging p_Convert_Dep_5
      io.debug_real_exp(i)   := convert_dep_5.io.debug_real_exp(i)
      io.debug_biased_exp(i) := convert_dep_5.io.debug_biased_exp(i)
      io.debug_shift_amt(i)  := convert_dep_5.io.debug_shift_amt(i)
      io.debug_PE(i)         := convert_dep_5.io.debug_PE(i)
      io.debug_abs_in(i)     := convert_dep_5.io.debug_abs_in(i)

      //for debugging p_Expansion
      io.debug_exp_gmax(i) := expansion(i).io.out_exponent_gmax(0)

      //for debugging ScaleSum
      io.debug_scale_sum(i) := scale_sum.io.out(i)

      //for debugging ScaleEmax
      io.debug_scale_emax(i) := scale_emax.io.out(i)

      //for debugging p_Adder_Dep_5
      io.debug_accum(i) := dep5(i).io.out

    }
    //for debugging p_Multiplier
    for (i <- 0 until 256) {
      io.debug_mul_exp(i) := mult.io.exponent(i)
    }

    io.out_FP32 := VecInit(Seq.fill(256)(0.U.asTypeOf(new FP32))) // dummy
  }
}
