package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_TOP_Til_Dep_ALL_V1_IO extends Bundle {
  val a_vec  = Input(Vec(256, UInt(4.W)))
  val b_vec  = Input(Vec(256, UInt(4.W)))
  val a_scale = Input(Vec(8, UInt(8.W)))
  val b_scale = Input(Vec(8, UInt(8.W)))
  val depth  = Input(UInt(4.W))
  val out = Output(Vec(256, new FP32))     

  // for debugging p_Multiplier
  val debug_mul_exp = Output(Vec(256, UInt(3.W))) 
  // for debugging p_Expansion
  val debug_exp_gmax = Output(Vec(8, UInt(3.W))) 
  //for debugging ScaleSum
  val debug_scale_sum   = Output(Vec(8, SInt(10.W)))
  //for debugging ScaleEmax
  val debug_scale_emax = Output(Vec(8, SInt(10.W)))


  //for debugging p_Adder_Dep_1
  val debug_accum_1      = Output(Vec(128, SInt(10.W)))
  val debug_abs_in_1     = Output(Vec(128, UInt(9.W)))
  //for debugging p_Adder_Dep_2
  val debug_accum_2      = Output(Vec(64, SInt(11.W)))
  val debug_abs_in_2     = Output(Vec(64, UInt(10.W)))
  //for debugging p_Adder_Dep_3
  val debug_accum_3      = Output(Vec(32, SInt(12.W)))
  val debug_abs_in_3     = Output(Vec(32, UInt(11.W)))
  //for debugging p_Adder_Dep_4
  val debug_accum_4      = Output(Vec(16, SInt(13.W)))
  val debug_abs_in_4     = Output(Vec(16, UInt(12.W)))
  //for debugging p_Adder_Dep_5
  val debug_accum_5      = Output(Vec(8, SInt(14.W))) // Accumulator output
  val debug_abs_in_5     = Output(Vec(8, UInt(13.W)))

  // for debugging p_Convert_Dep_1
  val debug_real_exp_1   = Output(Vec(128, SInt(10.W)))
  val debug_biased_exp_1 = Output(Vec(128, SInt(10.W)))
  val debug_shift_amt_1  = Output(Vec(128, SInt(5.W)))
  val debug_PE_1         = Output(Vec(128, UInt(4.W)))


  // for debugging p_Convert_Dep_2
  val debug_real_exp_2   = Output(Vec(64, SInt(10.W)))
  val debug_biased_exp_2 = Output(Vec(64, SInt(10.W)))
  val debug_shift_amt_2  = Output(Vec(64, SInt(5.W)))
  val debug_PE_2         = Output(Vec(64, UInt(4.W)))


  // for debugging p_Convert_Dep_3
  val debug_real_exp_3   = Output(Vec(32, SInt(10.W)))
  val debug_biased_exp_3 = Output(Vec(32, SInt(10.W)))
  val debug_shift_amt_3  = Output(Vec(32, SInt(5.W)))
  val debug_PE_3         = Output(Vec(32, UInt(4.W)))


  // for debugging p_Convert_Dep_4
  val debug_real_exp_4   = Output(Vec(16, SInt(10.W)))
  val debug_biased_exp_4 = Output(Vec(16, SInt(10.W)))
  val debug_shift_amt_4  = Output(Vec(16, SInt(5.W)))
  val debug_PE_4         = Output(Vec(16, UInt(4.W)))


  // for debugging p_Convert_Dep_5
  val debug_real_exp_5   = Output(Vec(8, SInt(10.W)))
  val debug_biased_exp_5 = Output(Vec(8, SInt(10.W)))
  val debug_shift_amt_5  = Output(Vec(8, SInt(5.W)))
  val debug_PE_5         = Output(Vec(8, UInt(4.W)))

}

class p_TOP_Til_Dep_All_V1 extends Module {
  val io = IO(new p_TOP_Til_Dep_ALL_V1_IO)

  val scale_sum = Module(new p_Adder_ScaleSum)
  val mult = Module(new p_Multiplier)
  val conv = Module(new p_MulConvert)

  val expansion = Seq.fill(8)(Module(new p_Expansion))
  val scale_emax = Module(new p_Adder_ScaleEmax)

  val dep1 = Seq.fill(8)(Module(new p_Adder_Dep_1))
  val dep2 = Seq.fill(8)(Module(new p_Adder_Dep_2))
  val dep3 = Seq.fill(8)(Module(new p_Adder_Dep_3))
  val dep4 = Seq.fill(8)(Module(new p_Adder_Dep_4))
  val dep5 = Seq.fill(8)(Module(new p_Adder_Dep_5))

  val convert_dep_1 = Module(new p_Convert_Dep_1)
  val convert_dep_2 = Module(new p_Convert_Dep_2)
  val convert_dep_3 = Module(new p_Convert_Dep_3)
  val convert_dep_4 = Module(new p_Convert_Dep_4)
  val convert_dep_5 = Module(new p_Convert_Dep_5)

    // Initialize debug outputs
    io.debug_real_exp_1   := VecInit(Seq.fill(128)(0.S(10.W)))
    io.debug_biased_exp_1 := VecInit(Seq.fill(128)(0.S(10.W)))
    io.debug_shift_amt_1  := VecInit(Seq.fill(128)(0.S(5.W)))
    io.debug_PE_1         := VecInit(Seq.fill(128)(0.U(4.W)))
    io.debug_abs_in_1     := VecInit(Seq.fill(128)(0.U(9.W)))
    io.debug_accum_1      := VecInit(Seq.fill(128)(0.S(10.W))) // Accumulator output


    io.debug_real_exp_2   := VecInit(Seq.fill(64)(0.S(10.W)))
    io.debug_biased_exp_2 := VecInit(Seq.fill(64)(0.S(10.W)))
    io.debug_shift_amt_2  := VecInit(Seq.fill(64)(0.S(5.W)))
    io.debug_PE_2         := VecInit(Seq.fill(64)(0.U(4.W)))
    io.debug_abs_in_2     := VecInit(Seq.fill(64)(0.U(10.W)))
    io.debug_accum_2      := VecInit(Seq.fill(64)(0.S(11.W))) // Accumulator output


    io.debug_real_exp_3   := VecInit(Seq.fill(32)(0.S(10.W)))
    io.debug_biased_exp_3 := VecInit(Seq.fill(32)(0.S(10.W)))
    io.debug_shift_amt_3  := VecInit(Seq.fill(32)(0.S(5.W)))
    io.debug_PE_3         := VecInit(Seq.fill(32)(0.U(4.W)))
    io.debug_abs_in_3     := VecInit(Seq.fill(32)(0.U(11.W)))
    io.debug_accum_3      := VecInit(Seq.fill(32)(0.S(12.W))) // Accumulator output


    io.debug_real_exp_4   := VecInit(Seq.fill(16)(0.S(10.W)))
    io.debug_biased_exp_4 := VecInit(Seq.fill(16)(0.S(10.W)))
    io.debug_shift_amt_4  := VecInit(Seq.fill(16)(0.S(5.W)))
    io.debug_PE_4         := VecInit(Seq.fill(16)(0.U(4.W)))
    io.debug_abs_in_4     := VecInit(Seq.fill(16)(0.U(12.W)))
    io.debug_accum_4      := VecInit(Seq.fill(16)(0.S(13.W))) // Accumulator output

    io.debug_real_exp_5   := VecInit(Seq.fill(8)(0.S(10.W)))
    io.debug_biased_exp_5 := VecInit(Seq.fill(8)(0.S(10.W)))
    io.debug_shift_amt_5  := VecInit(Seq.fill(8)(0.S(5.W)))
    io.debug_PE_5         := VecInit(Seq.fill(8)(0.U(4.W)))
    io.debug_abs_in_5     := VecInit(Seq.fill(8)(0.U(13.W)))
    io.debug_accum_5      := VecInit(Seq.fill(8)(0.S(14.W))) // Accumulator output


    io.debug_scale_sum  := VecInit(Seq.fill(8)(0.S(10.W))) 
    io.debug_scale_emax := VecInit(Seq.fill(8)(0.S(10.W)))
    io.debug_exp_gmax := VecInit(Seq.fill(8)(0.U(3.W))) // Group max exponent
    io.debug_mul_exp := VecInit(Seq.fill(256)(0.U(3.W))) // Multiplier exponent output

    conv.io.sign     := VecInit(Seq.fill(256)(0.U(1.W)))
    conv.io.exponent := VecInit(Seq.fill(256)(0.U(3.W)))
    conv.io.mantissa := VecInit(Seq.fill(256)(0.U(4.W)))
    conv.io.scale_sum := VecInit(Seq.fill(8)(0.S(9.W)))
    conv.io.nan       := VecInit(Seq.fill(8)(0.U(1.W)))

    convert_dep_1.io.in := VecInit(Seq.fill(128)(0.S(10.W)))
    convert_dep_2.io.in := VecInit(Seq.fill(64)(0.S(11.W)))
    convert_dep_3.io.in := VecInit(Seq.fill(32)(0.S(12.W)))
    convert_dep_4.io.in := VecInit(Seq.fill(16)(0.S(13.W)))
    convert_dep_5.io.in := VecInit(Seq.fill(8)(0.S(14.W)))

    convert_dep_1.io.nan := VecInit(Seq.fill(8)(0.U(1.W)))
    convert_dep_2.io.nan := VecInit(Seq.fill(8)(0.U(1.W)))
    convert_dep_3.io.nan := VecInit(Seq.fill(8)(0.U(1.W)))
    convert_dep_4.io.nan := VecInit(Seq.fill(8)(0.U(1.W)))
    convert_dep_5.io.nan := VecInit(Seq.fill(8)(0.U(1.W)))

    convert_dep_1.io.exponent := VecInit(Seq.fill(8)(0.S(10.W)))
    convert_dep_2.io.exponent := VecInit(Seq.fill(8)(0.S(10.W)))
    convert_dep_3.io.exponent := VecInit(Seq.fill(8)(0.S(10.W)))
    convert_dep_4.io.exponent := VecInit(Seq.fill(8)(0.S(10.W)))
    convert_dep_5.io.exponent := VecInit(Seq.fill(8)(0.S(10.W)))


  // Depth Control for Power Efficiency
  mult.io.depth := io.depth
  scale_emax.io.depth := io.depth

  for (i <- 0 until 8) {
    expansion(i).io.depth := io.depth
    dep1(i).io.depth := io.depth
    dep2(i).io.depth := io.depth
    dep3(i).io.depth := io.depth
    dep4(i).io.depth := io.depth
    dep5(i).io.depth := io.depth
  }
  convert_dep_1.io.depth := io.depth
  convert_dep_2.io.depth := io.depth
  convert_dep_3.io.depth := io.depth
  convert_dep_4.io.depth := io.depth
  convert_dep_5.io.depth := io.depth


  //Hardware Implementation
  mult.io.a_vec := io.a_vec
  mult.io.b_vec := io.b_vec
  scale_sum.io.a_scale := io.a_scale
  scale_sum.io.b_scale := io.b_scale

  for (i <- 0 until 8) {
    val base = i * 32
    expansion(i).io.sign     := mult.io.sign.slice(base, base + 32)
    expansion(i).io.exponent := mult.io.exponent.slice(base, base + 32)
    expansion(i).io.mantissa := mult.io.mantissa.slice(base, base + 32)

      // Scale and Emax calculation
    scale_emax.io.nan_in(i) := scale_sum.io.nan(i)
    scale_emax.io.scale_sum(i) := scale_sum.io.out(i)
    scale_emax.io.emax(i) := expansion(i).io.out_exponent_gmax(0)

    dep1(i).io.sign     := expansion(i).io.out_sign
    dep1(i).io.mantissa := expansion(i).io.out_mantissa
    dep2(i).io.in := dep1(i).io.out
    dep3(i).io.in := dep2(i).io.out
    dep4(i).io.in := dep3(i).io.out
    dep5(i).io.in := dep4(i).io.out
  }

  // Depth 0 → FP32 변환
  when(io.depth === 0.U) {
    conv.io.sign     := mult.io.sign
    conv.io.exponent := mult.io.exponent
    conv.io.mantissa := mult.io.mantissa
    conv.io.scale_sum := scale_sum.io.out
    conv.io.nan       := scale_sum.io.nan

    io.out := conv.io.out
  }

  .elsewhen(io.depth === 1.U) {

    for (i <- 0 until 8) {
      // Depth 1 Convert
      for (j <- 0 until 16) {
        convert_dep_1.io.in(i * 16 + j) := dep1(i).io.out(j)
      }
      convert_dep_1.io.nan(i) := scale_emax.io.nan_out(i)
      convert_dep_1.io.exponent(i) := scale_emax.io.out(i)
      io.out(i) := convert_dep_1.io.out(i)

      //for debugging 
      io.debug_exp_gmax(i) := expansion(i).io.out_exponent_gmax(0)
      io.debug_scale_sum(i) := scale_sum.io.out(i)
      io.debug_scale_emax(i) := scale_emax.io.out(i)
      for (j <- 0 until 16) {
        io.debug_accum_1(i * 16 + j) := dep1(i).io.out(j)
      }
    }

    for (i <- 0 until 256) {
      io.out(i) := Mux(i.U < 128.U, convert_dep_1.io.out(i % 128), 0.U.asTypeOf(new FP32))
    }

    // Debug signals
    for (i <- 0 until 128) {
      io.debug_real_exp_1(i)   := convert_dep_1.io.debug_real_exp(i)
      io.debug_biased_exp_1(i) := convert_dep_1.io.debug_biased_exp(i)
      io.debug_shift_amt_1(i)  := convert_dep_1.io.debug_shift_amt(i)
      io.debug_PE_1(i)         := convert_dep_1.io.debug_PE(i)
      io.debug_abs_in_1(i)     := convert_dep_1.io.debug_abs_in(i)
    }


    //for debugging p_Multiplier
    for (i <- 0 until 256) {
      io.debug_mul_exp(i) := mult.io.exponent(i)
    }
    
  }

  .elsewhen(io.depth === 2.U) {

    for (i <- 0 until 8) {
      // Depth 2 Convert
      for (j <- 0 until 8) {
        convert_dep_2.io.in(i * 8 + j) := dep2(i).io.out(j)
      }
      convert_dep_2.io.nan(i) := scale_emax.io.nan_out(i)
      convert_dep_2.io.exponent(i) := scale_emax.io.out(i)
      io.out(i) := convert_dep_2.io.out(i)

      //for debugging
      io.debug_exp_gmax(i) := expansion(i).io.out_exponent_gmax(0)
      io.debug_scale_sum(i) := scale_sum.io.out(i)
      io.debug_scale_emax(i) := scale_emax.io.out(i)

      for (j <- 0 until 8) {
        io.debug_accum_2(i * 8 + j) := dep2(i).io.out(j)
      }
    }

    for (i <- 0 until 256) {
      io.out(i) := Mux(i.U < 64.U, convert_dep_2.io.out(i % 64), 0.U.asTypeOf(new FP32))
    }

    for (i <- 0 until 64) {
      io.debug_real_exp_2(i)   := convert_dep_2.io.debug_real_exp(i)
      io.debug_biased_exp_2(i) := convert_dep_2.io.debug_biased_exp(i)
      io.debug_shift_amt_2(i)  := convert_dep_2.io.debug_shift_amt(i)
      io.debug_PE_2(i)         := convert_dep_2.io.debug_PE(i)
      io.debug_abs_in_2(i)     := convert_dep_2.io.debug_abs_in(i)
    }

    //for debugging p_Multiplier
    for (i <- 0 until 256) {
      io.debug_mul_exp(i) := mult.io.exponent(i)
    }
  }
  .elsewhen(io.depth === 3.U) {

    for (i <- 0 until 8) {
      // Depth 3 Convert
      for (j <- 0 until 4) { 
        convert_dep_3.io.in(i * 4 + j) := dep3(i).io.out(j)
      }
      convert_dep_3.io.nan(i) := scale_emax.io.nan_out(i)
      convert_dep_3.io.exponent(i) := scale_emax.io.out(i)
      io.out(i) := convert_dep_3.io.out(i)

      //for debugging
      io.debug_exp_gmax(i) := expansion(i).io.out_exponent_gmax(0)
      io.debug_scale_sum(i) := scale_sum.io.out(i)
      io.debug_scale_emax(i) := scale_emax.io.out(i)

      for (j <- 0 until 4) {
        io.debug_accum_3(i * 4 + j) := dep3(i).io.out(j)
      }
    }

      for (i <- 0 until 256) {
        io.out(i) := Mux(i.U < 32.U, convert_dep_3.io.out(i % 32), 0.U.asTypeOf(new FP32))
      }
      for (i <- 0 until 32) {
        io.debug_real_exp_3(i)   := Mux(i.U < 32.U, convert_dep_3.io.debug_real_exp(i), 0.S(10.W))
        io.debug_biased_exp_3(i) := Mux(i.U < 32.U, convert_dep_3.io.debug_biased_exp(i), 0.S(10.W))
        io.debug_shift_amt_3(i)  := Mux(i.U < 32.U, convert_dep_3.io.debug_shift_amt(i), 0.S(5.W))
        io.debug_PE_3(i)         := Mux(i.U < 32.U, convert_dep_3.io.debug_PE(i), 0.U(4.W))
        io.debug_abs_in_3(i)     := Mux(i.U < 32.U, convert_dep_3.io.debug_abs_in(i), 0.U(11.W))
      }
      //for debugging p_Multiplier
      for (i <- 0 until 256) {
      io.debug_mul_exp(i) := mult.io.exponent(i)
      } 
      
  }

  .elsewhen(io.depth === 4.U) {

    for (i <- 0 until 8) {
      // Depth 4 Convert
      for (j <- 0 until 2) {
        convert_dep_4.io.in(i * 2 + j) := dep4(i).io.out(j)
      }
      convert_dep_4.io.nan(i) := scale_emax.io.nan_out(i)
      convert_dep_4.io.exponent(i) := scale_emax.io.out(i)
      io.out(i) := convert_dep_4.io.out(i)

      //for debugging
      io.debug_exp_gmax(i) := expansion(i).io.out_exponent_gmax(0)
      io.debug_scale_sum(i) := scale_sum.io.out(i)
      io.debug_scale_emax(i) := scale_emax.io.out(i)
      
      for (j <- 0 until 2) {
        io.debug_accum_4(i * 2 + j) := dep4(i).io.out(j)
      }
    }

    for (i <- 0 until 256) {
      io.out(i) := Mux(i.U < 16.U, convert_dep_4.io.out(i % 16), 0.U.asTypeOf(new FP32))
    }

    for (i <- 0 until 16) {
      io.debug_real_exp_4(i)   := Mux(i.U < 16.U, convert_dep_4.io.debug_real_exp(i), 0.S(10.W))
      io.debug_biased_exp_4(i) := Mux(i.U < 16.U, convert_dep_4.io.debug_biased_exp(i), 0.S(10.W))
      io.debug_shift_amt_4(i)  := Mux(i.U < 16.U, convert_dep_4.io.debug_shift_amt(i), 0.S(5.W))
      io.debug_PE_4(i)         := Mux(i.U < 16.U, convert_dep_4.io.debug_PE(i), 0.U(4.W))
      io.debug_abs_in_4(i)     := Mux(i.U < 16.U, convert_dep_4.io.debug_abs_in(i), 0.U(12.W))
    }

    //for debugging p_Multiplier
    for (i <- 0 until 256) {
      io.debug_mul_exp(i) := mult.io.exponent(i)
    }       
    
  }
  .otherwise {

    for (i <- 0 until 8) {
      // Depth 5 Convert
      convert_dep_5.io.in(i) := dep5(i).io.out
      convert_dep_5.io.nan(i) := scale_emax.io.nan_out(i)
      convert_dep_5.io.exponent(i) := scale_emax.io.out(i)
      io.out(i) := convert_dep_5.io.out(i)

      //for debugging
      io.debug_exp_gmax(i) := expansion(i).io.out_exponent_gmax(0)
      io.debug_scale_sum(i) := scale_sum.io.out(i)
      io.debug_scale_emax(i) := scale_emax.io.out(i)
      io.debug_accum_5(i) := dep5(i).io.out

      //for debugging p_Convert_Dep_5
      io.debug_real_exp_5(i)   := convert_dep_5.io.debug_real_exp(i)
      io.debug_biased_exp_5(i) := convert_dep_5.io.debug_biased_exp(i)
      io.debug_shift_amt_5(i)  := convert_dep_5.io.debug_shift_amt(i)
      io.debug_PE_5(i)      := convert_dep_5.io.debug_PE(i)
      io.debug_abs_in_5(i)     := convert_dep_5.io.debug_abs_in(i)

    }

    for (i <- 0 until 256) {
      io.out(i) := Mux(i.U < 8.U, convert_dep_5.io.out(i % 8), 0.U.asTypeOf(new FP32))
    }

    //for debugging p_Multiplier
    for (i <- 0 until 256) {
      io.debug_mul_exp(i) := mult.io.exponent(i)
    }
    
  }
}
