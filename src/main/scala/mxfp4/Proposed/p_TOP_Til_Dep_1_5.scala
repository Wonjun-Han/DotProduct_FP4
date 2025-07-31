package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_TOP_Til_Dep_1_5_IO extends Bundle {
  val a_vec  = Input(Vec(256, UInt(4.W)))
  val b_vec  = Input(Vec(256, UInt(4.W)))
  val a_scale = Input(Vec(8, UInt(8.W)))
  val b_scale = Input(Vec(8, UInt(8.W)))
  val depth  = Input(UInt(3.W))
  val out = Output(Vec(256, new FP32))     // always full size

  val debug_exp_gmax = Output(Vec(8, UInt(3.W)))
  val debug_scale_sum = Output(Vec(8, SInt(10.W)))
  val debug_scale_emax = Output(Vec(8, SInt(10.W)))
  val debug_real_exp   = Output(Vec(256, SInt(10.W)))
  val debug_biased_exp = Output(Vec(256, SInt(10.W)))
  val debug_shift_amt  = Output(Vec(256, SInt(5.W)))
  val debug_PE         = Output(Vec(256, UInt(4.W)))
  val debug_abs_in     = Output(Vec(256, UInt(13.W)))
}

class p_TOP_Til_Dep_1_5 extends Module {
  val io = IO(new p_TOP_Til_Dep_1_5_IO)
  val scale_sum = Module(new p_Adder_ScaleSum)
  val mult = Module(new p_Multiplier)
  val conv = Module(new p_MulConvert)
  val convert = Module(new p_Convert)

  mult.io.a_vec := io.a_vec
  mult.io.b_vec := io.b_vec
  mult.io.depth := io.depth
  scale_sum.io.a_scale := io.a_scale
  scale_sum.io.b_scale := io.b_scale

  when(io.depth === 0.U) {
    conv.io.sign     := mult.io.sign
    conv.io.exponent := mult.io.exponent
    conv.io.mantissa := mult.io.mantissa
    conv.io.scale_sum := scale_sum.io.out
    conv.io.nan       := scale_sum.io.nan
    io.out := conv.io.out

    io.debug_real_exp   := VecInit(Seq.fill(256)(0.S))
    io.debug_biased_exp := VecInit(Seq.fill(256)(0.S))
    io.debug_shift_amt  := VecInit(Seq.fill(256)(0.S))
    io.debug_PE         := VecInit(Seq.fill(256)(0.U))
    io.debug_abs_in     := VecInit(Seq.fill(256)(0.U))
    io.debug_scale_sum  := scale_sum.io.out
    io.debug_scale_emax := VecInit(Seq.fill(8)(0.S))
    io.debug_exp_gmax   := VecInit(Seq.fill(8)(0.U))

    convert.io.depth := 0.U
    convert.io.in := VecInit(Seq.fill(256)(0.S)) // default off
    convert.io.nan := VecInit(Seq.fill(8)(0.U))
    convert.io.exponent := VecInit(Seq.fill(8)(0.S))
  } .otherwise {
    val expansion = Seq.fill(8)(Module(new p_Expansion))
    val dep1 = Seq.fill(8)(Module(new p_Adder_Dep_1))
    val dep2 = Seq.fill(8)(Module(new p_Adder_Dep_2))
    val dep3 = Seq.fill(8)(Module(new p_Adder_Dep_3))
    val dep4 = Seq.fill(8)(Module(new p_Adder_Dep_4))
    val dep5 = Seq.fill(8)(Module(new p_Adder_Dep_5))
    val scale_emax = Module(new p_Adder_ScaleEmax)
    scale_emax.io.depth := io.depth
    convert.io.depth := io.depth

    //initialize outputs
    conv.io.sign     := VecInit(Seq.fill(256)(0.U(1.W)))
    conv.io.exponent := VecInit(Seq.fill(256)(0.U(3.W)))
    conv.io.mantissa := VecInit(Seq.fill(256)(0.U(4.W)))
    conv.io.scale_sum := VecInit(Seq.fill(8)(0.S(10.W)))
    conv.io.nan       := VecInit(Seq.fill(8)(0.U(1.W)))

    for (i <- 0 until 8) {
      val base = i * 32
      expansion(i).io.sign     := mult.io.sign.slice(base, base + 32)
      expansion(i).io.exponent := mult.io.exponent.slice(base, base + 32)
      expansion(i).io.mantissa := mult.io.mantissa.slice(base, base + 32)
      expansion(i).io.depth    := io.depth

      scale_emax.io.nan(i) := scale_sum.io.nan(i)
      scale_emax.io.scale_sum(i) := scale_sum.io.out(i)
      scale_emax.io.emax(i) := expansion(i).io.out_exponent_gmax(0)

      dep1(i).io.sign := expansion(i).io.out_sign
      dep1(i).io.mantissa := expansion(i).io.out_mantissa
      dep1(i).io.depth := io.depth
      dep2(i).io.in := dep1(i).io.out; dep2(i).io.depth := io.depth
      dep3(i).io.in := dep2(i).io.out; dep3(i).io.depth := io.depth
      dep4(i).io.in := dep3(i).io.out; dep4(i).io.depth := io.depth
      dep5(i).io.in := dep4(i).io.out; dep5(i).io.depth := io.depth

      io.debug_exp_gmax(i) := expansion(i).io.out_exponent_gmax(0)
      io.debug_scale_sum(i) := scale_sum.io.out(i)
      io.debug_scale_emax(i) := scale_emax.io.out(i)
    }

    for (i <- 0 until 256) { convert.io.in(i) := 0.S } // default off

    switch(io.depth) {
      is(1.U) {
        for (i <- 0 until 128) {
          val g = i / 16
          val o = i % 16
          convert.io.in(i) := dep1(g).io.out(o).asSInt.pad(14)
        }
      }
      is(2.U) {
        for (i <- 0 until 64) {
          val g = i / 8
          val o = i % 8
          convert.io.in(i) := dep2(g).io.out(o).asSInt.pad(14)
        }
      }
      is(3.U) {
        for (i <- 0 until 32) {
          val g = i / 4
          val o = i % 4
          convert.io.in(i) := dep3(g).io.out(o).asSInt.pad(14)
        }
      }
      is(4.U) {
        for (i <- 0 until 16) {
          val g = i / 2
          val o = i % 2
          convert.io.in(i) := dep4(g).io.out(o).asSInt.pad(14)
        }
      }
      is(5.U) {
        for (i <- 0 until 8) {
          convert.io.in(i) := dep5(i).io.out.asSInt.pad(14)
        }
      }
    }

    for (i <- 0 until 8) {
      convert.io.nan(i) := scale_emax.io.nan(i)
      convert.io.exponent(i) := scale_emax.io.out(i)
    }

    io.out := convert.io.out
    for (i <- 0 until 256) {
      io.debug_real_exp(i)    := convert.io.debug_real_exp(i)
      io.debug_biased_exp(i)  := convert.io.debug_biased_exp(i)
      io.debug_shift_amt(i)   := convert.io.debug_shift_amt(i)
      io.debug_PE(i)          := convert.io.debug_PE(i)
      io.debug_abs_in(i)      := convert.io.debug_abs_in(i)
    }
  }
}
