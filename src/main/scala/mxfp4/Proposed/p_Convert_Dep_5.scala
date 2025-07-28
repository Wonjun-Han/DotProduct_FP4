package mxfp4.proposed
import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class MXFP4_CONVERT_DEPTH5_BLOCK_IO extends Bundle {
  val depth = Input(UInt(3.W))
  val in = Input(Vec(8, SInt(14.W)))
  val exponent = Input(Vec(8, UInt(9.W)))
  val out = Output(Vec(8, new FP32))
}

class p_Convert_Dep_5 extends Module {
  val io = IO(new MXFP4_CONVERT_DEPTH5_BLOCK_IO)

  val enable = io.depth === 5.U
  val sign = Wire(Vec(8, UInt(1.W)))
  val exponent = Wire(Vec(8, UInt(9.W)))
  val mantissa = Wire(Vec(8, UInt(13.W)))
  val PE = Wire(Vec(8, UInt(4.W)))
  val zero = Wire(Vec(8, (Bool())))
  val sub = Wire(Vec(8, Bool())) 

  val exponent_Conv = Wire(Vec(8, UInt(8.W)))
  val mantissa_Conv = Wire(Vec(8, UInt(23.W)))

  for (i <- 0 until 8) {
      sign(i) := Mux(io.in(i) < 0.S, 1.U, 0.U)
      exponent(i) := io.exponent(i)
      val abs_in = Mux(io.in(i) < 0.S, -io.in(i), io.in(i))
      mantissa(i) := abs_in.asUInt
      

      PE(i) := PriorityEncoder(Reverse(mantissa(i)))
      sub(i) := (mantissa(i) =/= 0.U)&&(exponent(i) === 0.U)
      zero(i) := (mantissa(i) === 0.U) && (exponent(i) === 0.U)

      when (exponent(i) > (PE(i) + 248.U) ) { //254 - 6
        exponent_Conv(i) := 255.U
        mantissa_Conv(i) := 0.U(23.W)
      }.elsewhen ((exponent(i) + 6.U) < PE(i)){
        exponent_Conv(i) := 0.U(8.W)
        mantissa_Conv(i) := Cat((mantissa(i) << (exponent(i) - 1.U))(5, 0), 0.U(17.W))
      }.otherwise {
        exponent_Conv(i) := exponent(i) - 6.U + PE(i)
        val shifted = Wire(UInt(23.W))
        when(PE(i) < 6.U) {
            shifted := (mantissa(i) >> (6.U - PE(i))) << (23.U - 13.U)  // 상위 13bit로 이동
        }.otherwise {
            val extended = (mantissa(i) << (PE(i) - 6.U)) // 13bit 유지
            shifted := extended << (23.U - 13.U)
        }
        mantissa_Conv(i) := shifted
      }

      when (enable) {
        io.out(i).sign := sign(i)
        io.out(i).exponent := exponent_Conv(i)
        io.out(i).mantissa := mantissa_Conv(i)
      }.otherwise {
        io.out(i).sign := 0.U
        io.out(i).exponent := 0.U
        io.out(i).mantissa := 0.U
      }
    }

 
}