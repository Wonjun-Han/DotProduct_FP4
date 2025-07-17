package adder

import chisel3._
import chisel3.experimental.BundleLiterals._
import chisel3.simulator.scalatest.ChiselSim
import org.scalatest.freespec.AnyFreeSpec
import org.scalatest.matchers.must.Matchers

class AdderSpec extends AnyFreeSpec with Matchers with ChiselSim {
  "Adder should correctly add two numbers" in {
    simulate(new Adder(12)) { dut =>
      dut.io.a.poke(5.U)
      dut.io.b.poke(7.U)
      dut.io.sum.expect(12.U)
    }
  }
}
