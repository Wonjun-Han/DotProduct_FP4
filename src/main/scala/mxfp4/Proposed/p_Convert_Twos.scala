
package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_CONVERT_TWOS_BLOCK_IO (depthBitWidth: Int, mantissaWidth: Int, vecSize: Int) extends Bundle {
  val in       = Input(Vec(vecSize, UInt(mantissaWidth.W))) // from p_Expansion_Groupwise
  val sign     = Input(Vec(vecSize, UInt(1.W)))             // from p_Expansion_Groupwise                 
  val out      = Output(Vec(vecSize, SInt((mantissaWidth+1).W)))
}

class p_Convert_Twos (d: Int, extra: Int) extends Module {
    val depthBitWidth = 4
    val mantissaWidth = 8 + d + extra
    val vecSize = 256 >> d                 // depth 6: 4, depth 7: 2, depth 8: 1
    val io = IO(new p_CONVERT_TWOS_BLOCK_IO(depthBitWidth, mantissaWidth, vecSize))
    for (i <- 0 until vecSize) {
        val inMag = io.in(i)
        val inSign = io.sign(i)
        val inExt = Cat(0.U(1.W), inMag).asSInt
        val out = Mux(inSign === 1.U, -inExt, inExt)
        io.out(i) := out
    }
}
