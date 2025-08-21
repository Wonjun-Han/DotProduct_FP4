package mxfp4.proposed

import chisel3._
import chisel3.util._
import _root_.circt.stage.ChiselStage

class p_CSA_UNIT_BLOCK_IO(w: Int) extends Bundle {
  val in = Input(Vec(3, UInt(w.W))) // w-bit input
  val sum = Output(UInt(w.W)) // w-bit output sum
  val carry = Output(UInt(w.W)) // w-bit output carry
}

class p_CSA_Unit(w: Int) extends Module {
    val io = IO(new p_CSA_UNIT_BLOCK_IO(w))

    // Carry-Save Adder logic (Bitwise operations)
    // Sum = a + b + c
    // Carry = (a & b) | (b & c) | (c & a)
    val sum = io.in(0) ^ io.in(1) ^ io.in(2) // XOR for sum
    val carry = (io.in(0) & io.in(1)) | (io.in(1) & io.in(2)) | (io.in(2) & io.in(0)) // AND-OR for carry

    // Assign outputs
    io.sum := sum
    io.carry := carry
}
