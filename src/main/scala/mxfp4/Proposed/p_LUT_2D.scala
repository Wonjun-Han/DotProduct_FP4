package mxfp4.proposed

import chisel3._
import chisel3.util._

class MUL_LUT_2D_BLOCK_IO extends Bundle {
  val sign     = Input(Vec(256, UInt(1.W))) 
  val mantissa = Input(Vec(256, UInt(4.W))) // 0..9 
  val exponent = Input(Vec(256, UInt(3.W))) // 0..4  
  val out      = Output(Vec(256, UInt(9.W))) // 2's complement, ±144 커버
}

// 2D-ROM LUT: table(e)(m) = (m << e), sign 반영해 2's complement로 출력
class p_LUT_2D extends Module {
  val io = IO(new MUL_LUT_2D_BLOCK_IO)

  val MAX_M = 9
  val MAX_E = 4

  // Use Mem instead of VecInit to avoid SystemVerilog assignment patterns
  private val preCalcTable = Mem(256, UInt(9.W))
  
  // Initialize ROM values using when/elsewhen statements
  for (addr <- 0 until 256) {
    val s = (addr >> 7) & 1        
    val e = (addr >> 4) & 7        
    val m = addr & 15              
    
    val romValue = if (e <= MAX_E && m <= MAX_M) {
      val value = m << e
      if (s == 1 && value != 0) {
        512 - value
      } else {
        value
      }
    } else {
      0
    }
    
    preCalcTable.write(addr.U, romValue.U(9.W))
  }

  for (i <- 0 until 256) {
    val m = io.mantissa(i) // 0..9 (4-bit)
    val e = io.exponent(i) // 0..4 (3-bit)  
    val s = io.sign(i)     // 0..1 (1-bit)

    // Direct wire concatenation - no arithmetic delay!
    // Address = sign(1) + exp(3) + man(4) = 8-bit direct mapping
    val addr = Cat(s, e, m) 
    
    // Mem-based ROM lookup - generates standard Verilog
    io.out(i) := preCalcTable.read(addr)
  }
}
