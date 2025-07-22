import cocotb
from cocotb.triggers import Timer
import random

# -- Helper functions --
def decode_mxfp4(val):
    sign     = (val >> 3) & 0x1
    exponent = (val >> 1) & 0x3
    mantissa = val & 0x1

    # MXFP4: if exp == 0 → 0b0M, else → 0b1M
    if exponent == 0:
        mantissa_2b = (0 << 1) | mantissa
    else:
        mantissa_2b = (1 << 1) | mantissa
    return sign, exponent, mantissa_2b

@cocotb.test()
async def test_mxfp4_multiplier_simple(dut):
    """
    Verifies the exact logic of the Multiplier module as implemented:
    - Sign: a^b
    - Exponent: if a or b zero → 0, else a_exp + b_exp
    - Mantissa: if a or b zero → 0, else a_mant * b_mant
    """
    dut._log.info("Starting test for simple MXFP4 multiplier logic")

    # --- generate inputs
    a_vec = [random.randint(0, 15) for _ in range(256)]
    b_vec = [random.randint(0, 15) for _ in range(256)]

    for i in range(256):
        getattr(dut, f"io_a_vec_{i}").value = a_vec[i]
        getattr(dut, f"io_b_vec_{i}").value = b_vec[i]

    dut.io_depth.value = 0  # ignored

    await Timer(20, units="ns")

    # --- verify each output
    for i in range(256):
        a_raw = a_vec[i]
        b_raw = b_vec[i]

        a_sign, a_exp, a_man = decode_mxfp4(a_raw)
        b_sign, b_exp, b_man = decode_mxfp4(b_raw)

        is_zero = (a_exp == 0 and a_man == 0) or (b_exp == 0 and b_man == 0)

        expected_sign = a_sign ^ b_sign
        expected_exp  = 0 if is_zero else (a_exp + b_exp)
        expected_mant = 0 if is_zero else (a_man * b_man)

        dut_sign = int(getattr(dut, f"io_sign_{i}").value)
        dut_exp  = int(getattr(dut, f"io_exponent_{i}").value)
        dut_mant = int(getattr(dut, f"io_mantissa_{i}").value)

        assert dut_sign == expected_sign, \
            f"[{i}] ❌ Sign mismatch: got {dut_sign}, expected {expected_sign}"
        assert dut_exp == expected_exp, \
            f"[{i}] ❌ Exponent mismatch: got {dut_exp}, expected {expected_exp}"
        assert dut_mant == expected_mant, \
            f"[{i}] ❌ Mantissa mismatch: got {dut_mant}, expected {expected_mant}"

    dut._log.info("✅ All 256 MXFP4 multiplication tests passed")
