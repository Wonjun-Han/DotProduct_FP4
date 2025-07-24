import cocotb
from cocotb.triggers import Timer
import random
import struct

# --------------------------
# Helper Functions
# --------------------------

def decode_mxfp4(val):
    s = (val >> 3) & 0x1
    e = (val >> 1) & 0x3
    m = val & 0x1
    if e == 0:
        if m == 0:
            return (-1)**s * 0.0
        else:
            return (-1)**s * (m / 2) 
    else:
        return (-1)**s * (1 + m / 2) * (2**(e - 1))

def float_to_bits(f):
    return struct.unpack('>I', struct.pack('>f', f))[0]

def get_fp32_fields(bits):
    sign     = (bits >> 31) & 0x1
    exponent = (bits >> 23) & 0xFF
    mantissa = bits & 0x7FFFFF
    return sign, exponent, mantissa

# --------------------------
# Test
# --------------------------

@cocotb.test()
async def test_mulconvert_block(dut):
    a_raw = [random.randint(0, 15) for _ in range(256)]
    b_raw = [random.randint(0, 15) for _ in range(256)]

    for i in range(256):
        getattr(dut, f"io_a_vec_{i}").value = a_raw[i]
        getattr(dut, f"io_b_vec_{i}").value = b_raw[i]

    dut.io_depth.value = 0
    await Timer(10, units='ns')

    for i in range(256):
        a_val = decode_mxfp4(a_raw[i])
        b_val = decode_mxfp4(b_raw[i])
        expected_result = a_val * b_val

        expected_bits = float_to_bits(expected_result)
        expected_sign, expected_exp, expected_man = get_fp32_fields(expected_bits)

        dut_sign = int(getattr(dut, f"io_out_{i}_sign").value)
        dut_exp  = int(getattr(dut, f"io_out_{i}_exponent").value)
        dut_man  = int(getattr(dut, f"io_out_{i}_mantissa").value)

        sign_match     = dut_sign == expected_sign
        exponent_match = abs(expected_exp - dut_exp) <= 0
        mantissa_match = abs(expected_man - dut_man) <= 0

        if not (sign_match and exponent_match and mantissa_match):
            raise AssertionError(
                f"[{i}] ❌ Mismatch!\n"
                f"A: {a_raw[i]} ({a_val:.4f}), B: {b_raw[i]} ({b_val:.4f})\n"
                f"Expected: sign={expected_sign}, exp={expected_exp}, man={expected_man}\n"
                f"Got     : sign={dut_sign}, exp={dut_exp}, man={dut_man}"
            )
    dut._log.info("All 256 MXFP4 vector multiplications passed!")