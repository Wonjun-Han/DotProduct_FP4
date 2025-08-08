package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_NaN_Process_BLOCK_IO(depthBitWidth: Int, vecSize: Int) extends Bundle {
  val depth       = Input(UInt(depthBitWidth.W))              // depth에 따라 활성화 결정
  val group_nan   = Input(Vec(vecSize, UInt(1.W)))            // 입력 NaN 플래그
  val result_nan  = Output(Vec(vecSize / 2, UInt(1.W)))       // 출력 NaN 플래그 (상위 포트부터 사용)
}

class p_NaN_Process(val d: Int) extends Module {
  val vecSize = 256 >> d // e.g., Depth 5 → 8, Depth 6 → 4, ...

  val io = IO(new p_NaN_Process_BLOCK_IO(depthBitWidth = 4, vecSize = vecSize))


  io.result_nan := VecInit(Seq.fill(vecSize / 2)(0.U(1.W)))

  val enable       = WireDefault(false.B)
  val groupSize  = WireDefault(0.U(4.W))
  val groupCount = WireDefault(0.U(2.W))

  // depth에 따라 설정
  switch(io.depth) {
    is(6.U) { enable := true.B; groupSize := 2.U; groupCount := 4.U }
    is(7.U) { enable := true.B; groupSize := 4.U; groupCount := 2.U }
    is(8.U) { enable := true.B; groupSize := 8.U; groupCount := 1.U }
  }

  // 그룹별 OR 결과
  val groupResults = Wire(Vec(vecSize / 2, UInt(1.W)))
  groupResults := VecInit(Seq.fill(vecSize / 2)(0.U))

  for (g <- 0 until vecSize / 2) {
    when(enable && g.U < groupCount) {
      val orBits = Wire(Vec(4, UInt(1.W))) // 최대 그룹 크기: 8 → 최대 4비트 OR
      orBits := VecInit(Seq.fill(4)(0.U))

      for (i <- 0 until 4) {
        val idx = g.U * groupSize + i.U
        val valid = i.U < groupSize && idx < vecSize.U
        val safeIdx = idx(log2Ceil(vecSize) - 1, 0)
        orBits(i) := Mux(valid, io.group_nan(safeIdx), 0.U)
      }

      groupResults(g) := orBits.reduce(_ | _)
    }
  }

  // 상위 포트부터 출력에 매핑
  for (i <- 0 until vecSize / 2) {
    val base = (vecSize / 2).U
    val groupStart = base - groupCount
    when(enable && i.U >= groupStart) {
      val gidx = i.U - groupStart
      io.result_nan(i) := groupResults(gidx)
    }.otherwise {
      io.result_nan(i) := 0.U
    }
  }
}
