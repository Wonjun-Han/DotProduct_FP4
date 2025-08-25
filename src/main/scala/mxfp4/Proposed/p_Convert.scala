package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_CONVERT_BLOCK_IO(depthBitWidth: Int, accWidth: Int, vecSize: Int, absWidth: Int) extends Bundle {
  val depth    = Input(UInt(depthBitWidth.W))
  val in       = Input(Vec(vecSize, SInt(accWidth.W)))
  val nan      = Input(Vec(8, UInt(1.W)))
  val exponent = Input(Vec(8, SInt(10.W)))
  val out      = Output(Vec(vecSize, new FP32))
}

class p_Convert(val d: Int) extends Module {
  val accWidth = 9 + d
  val vecSize  = 256 >> d          // d = 1..5 사용 가정 (vecSize >= 8)
  val absWidth = 8 + d

  val io = IO(new MXFP4_CONVERT_BLOCK_IO(
    depthBitWidth = 4, accWidth = accWidth, vecSize = vecSize, absWidth = absWidth
  ))

  val enable_depth = io.depth === d.U
  val groupSize    = vecSize / 8   // d=1..5이면 16,8,4,2,1

  // --- 트리형 LZC: PriorityEncoder(Reverse(x))와 동치, 폭0 재귀 없음 ---
  private def PE_lzcTreeSafe(x: UInt, outW: Int): UInt = {
    val w     = x.getWidth
    val pPow  = 1 << log2Ceil(w)
    val padW  = pPow - w
    val x_pad = if (padW == 0) x else Cat(x, 0.U(padW.W))  // LSB 쪽 0패딩
    val levels = log2Ceil(pPow)

    var sig = x_pad
    var cnt = 0.U(outW.W)
    for (_ <- 0 until levels) {
      val width = sig.getWidth
      val half  = width >> 1
      val hi    = sig(width-1, half)
      val lo    = sig(half-1, 0)
      val hiNZ  = hi.orR
      sig = Mux(hiNZ, hi, lo)
      cnt = Mux(hiNZ, cnt, cnt + half.U(outW.W))
    }
    val wU = w.U(outW.W)
    Mux(cnt > wU, wU, cnt) // padded 기준 결과를 원폭으로 clamp
  }

  // 시프트 상한 클램프 유틸 (네 변수명에서 확장)
  private def shift_amt_r_cap_fn(s: SInt, maxU: UInt): UInt = {
    val u = s.asUInt; Mux(u > maxU, maxU, u)
  }
  private def shift_amt_l_cap_fn(s: SInt, maxU: UInt): UInt = {
    val u = s.asUInt; Mux(u > maxU, maxU, u)
  }

  for (i <- 0 until vecSize) {
    val input         = io.in(i)
    val sign_bit      = Mux(input < 0.S, 1.U, 0.U)
    val abs_val_full  = Mux(input < 0.S, -input, input).asUInt
    val abs_val       = abs_val_full(absWidth - 1, 0)

    val groupIdx      = i / groupSize
    val nan           = io.nan(groupIdx)
    val isZero        = input === 0.S

    // --- Zero/NaN 선제 게이팅: 헤비 경로 토글 억제 (원 변수명 확장) ---
    val abs_val_eff   = Mux(enable_depth && (nan =/= 1.U) && !isZero, abs_val, 0.U(absWidth.W))

    // --- MSB 탐색: 트리형으로 (변수명 PE 유지) ---
    val PE            = PE_lzcTreeSafe(abs_val_eff, outW = log2Ceil(absWidth + 1))
    val shift_amt     = (d + 1).S - PE.asSInt

    // --- mantissa 생성 (원 변수명 유지, eff 사용) ---
    val extended_mantissa = Cat(abs_val_eff, 0.U(17.W))
    val extW_U            = (extended_mantissa.getWidth - 1).U

    val real_exp    = io.exponent(groupIdx) + shift_amt
    val biased_exp  = real_exp + 127.S

    val exponent_conv = Wire(UInt(8.W))
    val mantissa_conv = Wire(UInt(23.W))

    when (nan === 1.U) {
      exponent_conv := 255.U
      mantissa_conv := 4194304.U  // qNaN
    }.elsewhen (isZero) {
      exponent_conv := 0.U
      mantissa_conv := 0.U
    }.elsewhen (real_exp >= 128.S) {
      exponent_conv := 255.U
      mantissa_conv := 0.U
    }.elsewhen (biased_exp <= 0.S) {
      exponent_conv := 0.U
      // 원식 유지: sub_shift = |shift_amt| - (1 - biased_exp)
      val sub_shift = (shift_amt.abs.asUInt - (1.S - biased_exp).asUInt).asSInt
      val mant_sub  = Wire(UInt(23.W))
      when (sub_shift >= 0.S) {
        val sub_shift_l_cap = shift_amt_l_cap_fn(sub_shift, extW_U)
        mant_sub := ( (extended_mantissa << sub_shift_l_cap).asUInt )(22, 0)
      } .otherwise {
        val sub_shift_r_cap = shift_amt_r_cap_fn(-sub_shift, extW_U)
        mant_sub := ( (extended_mantissa >> sub_shift_r_cap).asUInt )(22, 0)
      }
      mantissa_conv := mant_sub
    }.otherwise {
      exponent_conv := biased_exp.asUInt
      val mant_norm  = Wire(UInt(23.W))
      when (shift_amt >= 0.S) {
        val shift_amt_r_cap = shift_amt_r_cap_fn(shift_amt, extW_U)
        mant_norm := ( (extended_mantissa >> shift_amt_r_cap).asUInt )(22, 0)
      } .otherwise {
        val shift_amt_l_cap = shift_amt_l_cap_fn(-shift_amt, extW_U)
        mant_norm := ( (extended_mantissa << shift_amt_l_cap).asUInt )(22, 0)
      }
      mantissa_conv := mant_norm
    }

    when (enable_depth) {
      io.out(i).sign     := Mux(nan === 1.U, 0.U, sign_bit)
      io.out(i).exponent := exponent_conv
      io.out(i).mantissa := mantissa_conv
    } .otherwise {
      io.out(i).sign     := 0.U
      io.out(i).exponent := 0.U
      io.out(i).mantissa := 0.U
    }
  }
}
