package mxfp4.proposed

import chisel3._
import chisel3.util._

/* 최종 2개 벡터(합, 캐리<<1)로 축약하는 전체 CSA 트리 (스테이지 수 자동 계산) */
class p_CSA_Total(w: Int, numInputs: Int) extends Module {
  require(numInputs >= 1, "numInputs must be >= 1")

  // 스테이지별 (count, width) 계산
  private def nextCount(c: Int): Int = (c / 3) * 2 + (c % 3)

  private val counts = {
    var cs = List(numInputs)
    while (cs.head > 2) cs = nextCount(cs.head) :: cs
    cs.reverse // 작은 것부터 큰 것 순서로 바꾸고 싶다면 조정
  }.reverse // 첫 원소가 처음 스테이지의 입력 개수

  private val numStages   = counts.size - 1            // 마지막 원소는 최종 개수(≤2)
  private val finalWidth  = w + numStages              // 스테이지마다 +1씩 증가

  // IO 정의: 최종 2개를 고정으로 내보냄 (나중에 ripple carry 로 처리)
  val io = IO(new Bundle {
    val in  = Input(Vec(numInputs, UInt(w.W)))
    val out = Output(Vec(2, UInt(finalWidth.W))) 
  })

  // 스테이지 체인 구성
  // stage 0 입력
  var curr = io.in.map(_.asUInt)                      // Seq[UInt] (폭 w)
  var currWidth = w

  for (s <- 0 until numStages) {
    val bundle = Module(new p_CSA_Bundle(currWidth, curr.length))
    bundle.io.in := VecInit(curr)
    curr = bundle.io.out.map(_.asUInt)                // 폭(currWidth+1)
    currWidth += 1
  }

  // 최종 처리: curr.length == 1 또는 2
  val outs = Wire(Vec(2, UInt(finalWidth.W)))
  outs(0) := curr(0)
  outs(1) := curr(1)
  io.out := outs
}
