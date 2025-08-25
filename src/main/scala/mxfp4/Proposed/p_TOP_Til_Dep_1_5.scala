package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage


class p_TOP_Til_Dep_1_5_BLOCK_IO extends Bundle {
  val a_vec  = Input(Vec(256, UInt(4.W)))
  val b_vec  = Input(Vec(256, UInt(4.W)))
  val a_scale = Input(Vec(8, UInt(8.W)))
  val b_scale = Input(Vec(8, UInt(8.W)))
  val depth  = Input(UInt(4.W))
  val out = Output(Vec(16, new FP32))
}

class p_TOP_Til_Dep_1_5 extends Module {
  val io = IO(new p_TOP_Til_Dep_1_5_BLOCK_IO)

  val mult = Module(new p_Multiplier)
  val scaleSum = Module(new p_Adder_ScaleSum)
  val scaleEmax = Module(new p_Adder_ScaleEmax)

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


  // --- Multiplier + Shared Scale Sum ---
  mult.io.a_vec := io.a_vec
  mult.io.b_vec := io.b_vec
  mult.io.depth := io.depth

  scaleSum.io.a_scale := io.a_scale
  scaleSum.io.b_scale := io.b_scale

  scaleEmax.io.depth := io.depth

  // --- Depth 0 전용: MulConvert ---
  convert0.io.sign     := mult.io.sign
  convert0.io.exponent := mult.io.exponent
  convert0.io.mantissa := mult.io.mantissa
  convert0.io.scale_sum := scaleSum.io.out
  convert0.io.nan      := scaleSum.io.nan

  // --- Depth 1–5 처리: Expansion → Adders → Convert ---
  for (i <- 0 until 8) {
    val base = i * 32
    val exp = Module(new p_Expansion)
    exp.io.depth := io.depth
    exp.io.sign := mult.io.sign.slice(base, base + 32)
    exp.io.exponent := mult.io.exponent.slice(base, base + 32)
    exp.io.mantissa := mult.io.mantissa.slice(base, base + 32)

    scaleEmax.io.nan_in(i) := scaleSum.io.nan(i)
    scaleEmax.io.scale_sum(i) := scaleSum.io.out(i)
    scaleEmax.io.emax(i) := exp.io.out_exponent_gmax(0)

    adder1(i).io.depth := io.depth
    adder1(i).io.sign := exp.io.out_sign
    adder1(i).io.mantissa := exp.io.out_mantissa

    adder2(i).io.depth := io.depth
    adder2(i).io.in := adder1(i).io.out

    adder3(i).io.depth := io.depth
    adder3(i).io.in := adder2(i).io.out

    adder4(i).io.depth := io.depth
    adder4(i).io.in := adder3(i).io.out

    adder5(i).io.depth := io.depth
    adder5(i).io.in := adder4(i).io.out



  }

  def connectConvertInput[T <: Module { val io: { val out: Vec[SInt] } }](adder: Seq[T], convertIn: Vec[SInt], outPerAdder: Int) = {
    for (i <- 0 until convertIn.length) {
      convertIn(i) := adder(i / outPerAdder).io.out(i % outPerAdder)
    }
  }
  connectConvertInput(adder1, convert1.io.in, 16)
  connectConvertInput(adder2, convert2.io.in, 8)
  connectConvertInput(adder3, convert3.io.in, 4)
  connectConvertInput(adder4, convert4.io.in, 2)
  for (i <- 0 until 8) convert5.io.in(i) := adder5(i).io.out

  for (c <- Seq(convert1, convert2, convert3, convert4, convert5)) {
    c.io.depth := io.depth
    c.io.nan := scaleEmax.io.nan_out
    c.io.exponent := scaleEmax.io.out
  }

  def padTo16(vec: Vec[FP32]): Vec[FP32] = {
    VecInit((0 until 16).map(i => if (i < vec.length) vec(i) else 0.U.asTypeOf(new FP32)))
  }

  val selected_out = Wire(Vec(16, new FP32))
  selected_out := 0.U.asTypeOf(Vec(16, new FP32))
  switch(io.depth) {
    is(0.U) { selected_out := padTo16(convert0.io.out) }
    is(1.U) { selected_out := padTo16(convert1.io.out) }
    is(2.U) { selected_out := padTo16(convert2.io.out) }
    is(3.U) { selected_out := padTo16(convert3.io.out) }
    is(4.U) { selected_out := padTo16(convert4.io.out) }
    is(5.U) { selected_out := padTo16(convert5.io.out) }
  }

  io.out := selected_out
}
