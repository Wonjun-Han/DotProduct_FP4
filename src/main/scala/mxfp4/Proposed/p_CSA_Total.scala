package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage


// Total: (입력 비트폭, 입력 개수, 출력 최대 비트폭)만 받음
// 폭은 스테이지마다 +1 하되 outBitMax에서 포화, 이후 동일 폭 유지
class p_CSA_Total(inBit: Int, inCount: Int, outBitMax: Int) extends Module {
  private def nextCount(c: Int): Int = (c/3)*2 + (c%3)

  val io = IO(new Bundle {
    val in  = Input(Vec(inCount, UInt(inBit.W)))
    val out = Output(Vec(2, UInt(outBitMax.W))) // 최종 2개(sum, carry<<1 동치)
  })

  var curr  = io.in.map(_.asUInt)  // 시작: inBit
  var wcurr = inBit

  // 스테이지 전개: 입력 개수 2가 될 때까지
  while (curr.length > 2) {
    val wnext = math.min(wcurr + 1, outBitMax)           // 포화까지 증가
    val stage = Module(new p_CSA_Bundle(wcurr, curr.length, wnext))
    stage.io.in := VecInit(curr)
    curr  = stage.io.out.map(_.asUInt)                   // 길이는 (2*(n/3)+n%3)
    wcurr = wnext
  }

  // 마지막 2개만 반환 (폭 = min(inBit+stages, outBitMax))
  io.out(0) := curr(0)
  io.out(1) := curr(1)
}
