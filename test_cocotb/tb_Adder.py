import cocotb
from cocotb.triggers import Timer

@cocotb.test()
async def test_adder(dut):
    dut.io_a.value = 10
    dut.io_b.value = 15
    await Timer(1.0, units="ns")  #float
    assert dut.io_sum.value == 25, f"Adder failed: {dut.io_sum.value}" 
