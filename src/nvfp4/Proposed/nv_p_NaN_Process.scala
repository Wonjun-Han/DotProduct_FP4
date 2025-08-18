package nvfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class NVFP4_NaN_Process_BLOCK_IO(depthBitWidth: Int, vecSize: Int) extends Bundle {
  val depth       = Input(UInt(depthBitWidth.W))              // depth에 따라 활성화
  val group_nan   = Input(Vec(vecSize, UInt(1.W)))            // 입력 NaN 플래그 (예: 8개)
  val result_nan  = Output(Vec(vecSize / 2, UInt(1.W)))       // 출력 NaN 플래그 (앞에서부터 매핑)
}

class nv_p_NaN_Process(val d: Int) extends Module {
  val vecSize = 256 >> d          // d=5 → 8, d=6 → 4, ...
  val outSize = vecSize / 2       // d=5 → 4, d=6 → 2, ...

  val io = IO(new NVFP4_NaN_Process_BLOCK_IO(depthBitWidth = 4, vecSize = vecSize))

  // 기본값 0으로 초기화
  io.result_nan := VecInit(Seq.fill(outSize)(0.U(1.W)))

  // depth별 설정
  val enable     = WireDefault(false.B)
  val groupSize  = WireDefault(0.U(4.W))  // 2, 4, 8
  val groupCount = WireDefault(0.U(log2Ceil(outSize + 1).W)) // 4/2/1 표현 가능

  switch(io.depth) {
    is(6.U) { enable := true.B; groupSize := 2.U; groupCount := 4.U } // (0|1),(2|3),(4|5),(6|7)
    is(7.U) { enable := true.B; groupSize := 4.U; groupCount := 2.U } // (0..3),(4..7)
    is(8.U) { enable := true.B; groupSize := 8.U; groupCount := 1.U } // (0..7)
  }
  
  val groupResults = Wire(Vec(outSize, UInt(1.W)))
  groupResults := VecInit(Seq.fill(outSize)(0.U))

  for (g <- 0 until outSize) {
    when(enable && (g.U < groupCount)) {
      val orBits = Wire(Vec(8, UInt(1.W))) // 최대 8개까지 OR
      orBits := VecInit(Seq.fill(8)(0.U))

      for (i <- 0 until 8) {
        val idx     = g.U * groupSize + i.U
        val valid   = (i.U < groupSize) && (idx < vecSize.U)
        val safeIdx = idx(log2Ceil(vecSize) - 1, 0)
        orBits(i) := Mux(valid, io.group_nan(safeIdx), 0.U)
      }

      groupResults(g) := orBits.reduce(_ | _)
    }
  }

  // (앞에서부터) 결과 매핑
  for (i <- 0 until outSize) {
    when(enable && (i.U < groupCount)) {
      io.result_nan(i) := groupResults(i)
    }.otherwise {
      io.result_nan(i) := 0.U
    }
  }
}
