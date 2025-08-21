package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_CSA_BUNDLE_BLOCK_IO(w: Int, numInputs: Int) extends Bundle {
  val in    = Input(Vec(numInputs, UInt(w.W)))
  // sum과 (pass through는 sum에 마지막에 붙음) + carry를 이어붙인 단일 출력
  val out   = Output(Vec(2*(numInputs/3) + (numInputs % 3), UInt((w+1).W)))
}

class p_CSA_Bundle (w: Int, numInputs: Int) extends Module {
  val io = IO(new p_CSA_BUNDLE_BLOCK_IO(w, numInputs))

  val numGroups   = numInputs / 3
  val passThrough = numInputs % 3

  val CSA_UNIT = Seq.fill(numGroups)(Module(new p_CSA_Unit(w)))

  val sum   = Wire(Vec(numGroups + passThrough, UInt((w+1).W)))
  val carry = Wire(Vec(numGroups,               UInt((w+1).W)))

  for (i <- 0 until numGroups) {
    val groupInputs = io.in.slice(i * 3, (i + 1) * 3)
    CSA_UNIT(i).io.in := groupInputs
    sum(i)   := CSA_UNIT(i).io.sum           // zero-extend는 상위에서 (w+1)로 맞았으니 OK
    carry(i) := (CSA_UNIT(i).io.carry << 1)  // carry는 1비트 시프트
  }

  for (j <- 0 until passThrough) {
    sum(numGroups + j) := io.in(numGroups * 3 + j) 
  }

  val total = 2 * numGroups + passThrough
  val outVec = Wire(Vec(total, UInt((w+1).W)))
  // 앞쪽: sum + pass through
  for (i <- 0 until (numGroups + passThrough)) {
    outVec(i) := sum(i)
  }
  // 뒤쪽: carry
  for (i <- 0 until numGroups) {
    outVec(numGroups + passThrough + i) := carry(i)
  }
  io.out := outVec
}
