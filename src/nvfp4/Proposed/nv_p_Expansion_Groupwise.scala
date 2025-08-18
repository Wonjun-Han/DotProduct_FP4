package nvfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class NVFP4_EXPANSION_GROUPWISE_IO(depthBitWidth: Int, accWidth: Int, vecSize: Int, outWidth: Int) extends Bundle {
  val in        = Input(Vec(vecSize, SInt(accWidth.W)))
  val exponent  = Input(Vec(vecSize, SInt(10.W)))
  val depth     = Input(UInt(depthBitWidth.W)) // depth에 따라 grouping 결정

  val out_mantissa        = Output(Vec(vecSize, UInt(outWidth.W)))
  val out_sign            = Output(Vec(vecSize, UInt(1.W)))
  val out_exponent_gmax   = Output(Vec(vecSize / 2, SInt(10.W)))
}

class nv_p_Expansion_Groupwise(val d: Int, val extra: Int) extends Module {
  val accWidth = 9 + d
  val outWidth = 8 + d + extra
  val vecSize = 256 >> d // d = 5 → vecSize = 8

  val io = IO(new NVFP4_EXPANSION_GROUPWISE_IO(
    depthBitWidth = 4,
    accWidth = accWidth,
    vecSize = vecSize,
    outWidth = outWidth
  ))

  // ------------------------------
  // (1) depth에 따른 group 구성
  // ------------------------------
  val expansion_size = Wire(UInt(4.W)) // 그룹 크기 (depth 6 : 2, depth 7 : 4, depth 8 : 8)
  val expansion_num  = Wire(UInt(3.W)) // 최대 4개 그룹
  val enable         = Wire(Bool())

    // 먼저 기본값 선언 (fallback)
    expansion_size := 2.U
    expansion_num  := 4.U
    enable         := false.B


  switch(io.depth) {
    is(6.U) {
      expansion_size := 2.U
      expansion_num  := 4.U
      enable := true.B
    }
    is(7.U) {
      expansion_size := 4.U
      expansion_num  := 2.U
      enable := true.B
    }
    is(8.U) {
      expansion_size := 8.U
      expansion_num  := 1.U
      enable := true.B
    }
  }

  // ------------------------------
  // (2) 그룹별 max exponent 계산 (최대 4개)
  // ------------------------------
    def minS10: SInt = (-512).S(10.W)  // 무효 후보 대체값(최솟값)

    def reduceMaxTree(xs: Seq[SInt]): SInt = {
    require(xs.nonEmpty)
    if (xs.length == 1) xs.head
    else {
        val pairs = xs.grouped(2).map {
        case Seq(a, b) => Mux(a > b, a, b)
        case Seq(a)    => a
        }.toSeq
        reduceMaxTree(pairs)
    }
    }


    val grouped_max_exp = Wire(Vec(vecSize/2, SInt(10.W)))

    // 실제 합이 0인 lane 마스킹, 그래야 이후에, Max Exp 뽑을 때, 유효한 것만 가져올 수 있음.
    val laneZero = Wire(Vec(vecSize, Bool()))
    for (i <- 0 until vecSize) {
      laneZero(i) := (io.in(i) === 0.S(accWidth.W))
    }

    for (g <- 0 until vecSize/2) {
    val active       = enable && (g.U < expansion_num)
    val group_start  = g.U * expansion_size

    // 그룹 내 후보(최대 8개)만 만들고, 무효는 minS10으로 마스킹, 그리고 만약에 accum=0이면 minS10으로 대체하자
    val cands: Seq[SInt] = (0 until 8).map { k =>
      val i   = group_start + k.U
      val ok  = (k.U < expansion_size) && (i < vecSize.U)
      val idx = i(log2Ceil(vecSize)-1, 0)
      val expEff = Mux(laneZero(idx), minS10, io.exponent(idx))
      Mux(ok, expEff, minS10)
    }

    // 해당 그룹 내부에서만 reduce로 최대 선택하자
    //val grpMax: SInt = cands.reduce( (a, b) => Mux(a > b, a, b) )
    val grpMax: SInt = reduceMaxTree(cands)
    grouped_max_exp(g) := Mux(active, grpMax, 0.S(10.W))

    }

  // ------------------------------
  // (3) mantissa shift 및 sign 추출
  // ------------------------------

  val groupIdxBits = log2Ceil(vecSize/2) // = 2 (vecSize=8 → 4그룹)

  for (i <- 0 until vecSize) {
    val group_idx = Wire(UInt(groupIdxBits.W))
    group_idx := 0.U
    when (enable) {
        group_idx := MuxLookup(io.depth, 0.U(groupIdxBits.W))(
        Seq(
            6.U -> ( (i/2).U(groupIdxBits.W) ),  // expansion_size = 2
            7.U -> ( (i/4).U(groupIdxBits.W) ),  // expansion_size = 4
            8.U -> ( (i/8).U(groupIdxBits.W) )   // expansion_size = 8
        )
        )
    }
    val max_exp = grouped_max_exp(group_idx)
    val shift_amt = (max_exp - io.exponent(i)).asUInt // always

    val in = io.in(i)
    val sign_bit = in(accWidth - 1)
    val abs_val = Mux(sign_bit === 1.U, -in, in).asUInt
    val extended = Cat(abs_val(accWidth - 1, 0), 0.U(extra.W))

    io.out_sign(i)     := Mux(enable, sign_bit, 0.U)
    io.out_mantissa(i) := Mux(enable, (extended >> shift_amt), 0.U)
  }

  // ------------------------------
  // (4) out_exponent_gmax 앞에서부터 채움
  // ------------------------------
    for (i <- 0 until vecSize / 2) {
    io.out_exponent_gmax(i) := Mux(enable && (i.U < expansion_num), grouped_max_exp(i), 0.S)
    }

}