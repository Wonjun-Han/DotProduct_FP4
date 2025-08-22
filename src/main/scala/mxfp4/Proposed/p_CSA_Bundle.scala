package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

// 한 스테이지: 입력폭 wIn → 출력폭 wOut (포화되면 wOut == wIn)
class p_CSA_BUNDLE_BLOCK_IO(wIn: Int, numInputs: Int, wOut: Int) extends Bundle {
  val in  = Input(Vec(numInputs, UInt(wIn.W)))
  val out = Output(Vec(2*(numInputs/3) + (numInputs % 3), UInt(wOut.W)))
}
class p_CSA_Bundle(wIn: Int, numInputs: Int, wOut: Int) extends Module {
  val io = IO(new p_CSA_BUNDLE_BLOCK_IO(wIn, numInputs, wOut))
  val G = numInputs / 3
  val P = numInputs % 3

  val units = Seq.fill(G)(Module(new p_CSA_Unit(wIn)))

  val sums    = Wire(Vec(G + P, UInt(wOut.W)))
  val carries = Wire(Vec(G,     UInt(wOut.W)))

  // 3개씩 CSA
  for (i <- 0 until G) {
    val a = io.in(3*i+0); val b = io.in(3*i+1); val c = io.in(3*i+2)
    units(i).io.in := VecInit(a, b, c)

    val sumBit   = units(i).io.sum                 // wIn
    val carryBit = units(i).io.carry               // wIn

    // sum
    val sumNext =
      if (wOut > wIn) Cat(sumBit(wIn-1), sumBit)   // wIn+1
      else sumBit                                   // wIn

    // carry
    val carrySh   = Cat(carryBit, 0.U(1.W))        // wIn+1
    val carryNext = carrySh(wOut-1, 0)             // wOut

    sums(i)    := sumNext
    carries(i) := carryNext
  }

  // 패스스루
  for (j <- 0 until P) {
    val x = io.in(3*G + j)
    val xNext =
      if (wOut > wIn) Cat(x(wIn-1), x) else x
    sums(G + j) := xNext
  }

  val total = 2*G + P
  val outVec = Wire(Vec(total, UInt(wOut.W)))
  for (i <- 0 until (G + P)) outVec(i) := sums(i)
  for (i <- 0 until G)       outVec(G + P + i) := carries(i)
  io.out := outVec
}
