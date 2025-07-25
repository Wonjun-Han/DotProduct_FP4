package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_TOP_Til_Dep_4_IO extends Bundle {
  val a_vec  = Input(Vec(256, UInt(4.W)))
  val b_vec  = Input(Vec(256, UInt(4.W)))
  val depth  = Input(UInt(3.W))
  val out = Output(Vec(8, SInt(14.W)))         // 최종 dot-product 결과
  val out_FP32 = Output(Vec(256, new FP32))    // depth=0일 경우 FP32 출력
}

class p_TOP_Til_Dep_4 extends Module {
  val io = IO(new p_TOP_Til_Dep_4_IO)

  val mult = Module(new p_Multiplier)
  val conv = Module(new p_MulConvert)

  mult.io.a_vec := io.a_vec
  mult.io.b_vec := io.b_vec
  mult.io.depth := io.depth

  // Depth 0 → FP32 변환
  when(io.depth === 0.U) {
    conv.io.sign     := mult.io.sign
    conv.io.exponent := mult.io.exponent
    conv.io.mantissa := mult.io.mantissa

    io.out_FP32 := conv.io.out
    io.out := VecInit(Seq.fill(8)(0.S(14.W)))
  }.otherwise {
    // Expansion & Adders
    val expansion = Seq.fill(8)(Module(new p_Expansion))
    val dep0 = Seq.fill(8)(Module(new p_Adder_Dep_0))
    val dep1 = Seq.fill(8)(Module(new p_Adder_Dep_1))
    val dep2 = Seq.fill(8)(Module(new p_Adder_Dep_2))
    val dep3 = Seq.fill(8)(Module(new p_Adder_Dep_3))
    val dep4 = Seq.fill(8)(Module(new p_Adder_Dep_4))

    for (i <- 0 until 8) {
      val base = i * 32
      expansion(i).io.sign     := mult.io.sign.slice(base, base + 32)
      expansion(i).io.exponent := mult.io.exponent.slice(base, base + 32)
      expansion(i).io.mantissa := mult.io.mantissa.slice(base, base + 32)
      expansion(i).io.depth    := io.depth

      dep0(i).io.sign     := expansion(i).io.out_sign
      dep0(i).io.mantissa := expansion(i).io.out_mantissa
      dep1(i).io.in := dep0(i).io.out
      dep2(i).io.in := dep1(i).io.out
      dep3(i).io.in := dep2(i).io.out
      dep4(i).io.in := dep3(i).io.out

      io.out(i) := dep4(i).io.out
    }

    io.out_FP32 := VecInit(Seq.fill(256)(0.U.asTypeOf(new FP32))) // dummy
  }
}
