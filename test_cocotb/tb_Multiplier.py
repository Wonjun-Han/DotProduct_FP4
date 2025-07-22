import cocotb
from cocotb.triggers import Timer
import random

# -- Helper functions for MULT --
def decode_mxfp4(encoded):
    sign = (encoded >> 3) & 0x1
    exponent = (encoded >> 1) & 0x3
    mantissa = encoded & 0x1
    return sign, exponent, mantissa

def full_mantissa(exp, man):
    return (1 << 1 | man) if exp != 0 else (0 << 1 | man)


# --- Test for MXFP4 Multiplier ---
@cocotb.test()
async def test_multiplier_random(dut):
    dut._log.info("🔍 Running 256-element random test (flattened ports)")

    random.seed(42)
    a_raw = [random.randint(0, 15) for _ in range(256)]
    b_raw = [random.randint(0, 15) for _ in range(256)]

    for i in range(256):
        getattr(dut, f"io_a_vec_{i}").value = a_raw[i]
        getattr(dut, f"io_b_vec_{i}").value = b_raw[i]

    dut.io_depth.value = 0  # not used

    await Timer(20, units="ns")

    for i in range(256):
        a_sign, a_exp, a_man = decode_mxfp4(a_raw[i])
        b_sign, b_exp, b_man = decode_mxfp4(b_raw[i])

        expected_sign = a_sign ^ b_sign
        expected_exp = (a_exp + b_exp) & 0x7
        expected_mant = (full_mantissa(a_exp, a_man) * full_mantissa(b_exp, b_man)) & 0xF
    

        sign_val     = getattr(dut, f"io_sign_{i}").value.integer
        exponent_val = getattr(dut, f"io_exponent_{i}").value.integer
        mantissa_val = getattr(dut, f"io_mantissa_{i}").value.integer
    

        assert sign_val == expected_sign,   f"sign[{i}] mismatch: got {sign_val}, expected {expected_sign}"
        assert exponent_val == expected_exp, f"exp[{i}] mismatch: got {exponent_val}, expected {expected_exp}"
        assert mantissa_val == expected_mant, f"mant[{i}] mismatch: got {mantissa_val}, expected {expected_mant}"


    dut._log.info("✅ All 256 MXFP4 vector multiplications passed!")
