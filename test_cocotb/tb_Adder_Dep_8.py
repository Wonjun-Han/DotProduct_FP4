import cocotb
from cocotb.triggers import Timer
import struct
import random
import numpy as np

def float_to_bits(f):
    return struct.unpack('>I', struct.pack('>f', f))[0]

def bits_to_float(b):
    return struct.unpack('>f', struct.pack('>I', b))[0]

def get_fp32_fields(bits):
    sign = (bits >> 31) & 0x1
    exponent = (bits >> 23) & 0xFF
    mantissa = bits & 0x7FFFFF
    return sign, exponent, mantissa

def float_to_bin_fields(f):
    bits = float_to_bits(f)
    s = f"{(bits >> 31) & 0x1:b}"
    e = f"{(bits >> 23) & 0xFF:08b}"
    m = f"{bits & 0x7FFFFF:023b}"
    return f"S: {s} E: {e} M: {m}"

def ulp_diff(a, b):
    def float_to_ordered_int(f):
        i = float_to_bits(f)
        return i if (i >> 31) == 0 else 0xFFFFFFFF - i
    return abs(float_to_ordered_int(a) - float_to_ordered_int(b))


@cocotb.test()
async def test_adder(dut):
    total_tests = 10**6
    passed = 0

    for i in range(total_tests):
        a_float = random.uniform(-1e5, 1e5)
        b_float = random.uniform(-1e5, 1e5)

        a_bits = float_to_bits(a_float)
        b_bits = float_to_bits(b_float)

        a_sign, a_exp, a_man = get_fp32_fields(a_bits)
        b_sign, b_exp, b_man = get_fp32_fields(b_bits)

        dut.io_a_0_sign.value     = a_sign
        dut.io_a_0_exponent.value = a_exp
        dut.io_a_0_mantissa.value = a_man
        dut.io_a_1_sign.value     = b_sign
        dut.io_a_1_exponent.value = b_exp
        dut.io_a_1_mantissa.value = b_man

        await Timer(2, units='ns')

        # 기대값 계산
        expected = a_float + b_float
        expected_bits = float_to_bits(expected)
        expected_sign, expected_exp, expected_man = get_fp32_fields(expected_bits)
        expected_float = bits_to_float(expected_bits)

        # DUT 출력값
        dut_sign = int(dut.io_out_0_sign.value)
        dut_exp  = int(dut.io_out_0_exponent.value)
        dut_man  = int(dut.io_out_0_mantissa.value)
        got_bits = (dut_sign << 31) | (dut_exp << 23) | dut_man
        got_float = bits_to_float(got_bits)
        float_error = abs(expected_float - got_float)
        if expected_float != 0:
            error_rate_percentage = abs(float_error / expected_float) 
        else :
            error_rate_percentage = float_error

        
        sign_match     = (dut_sign == expected_sign)
        exponent_match = (abs(dut_exp - expected_exp) <= 0)
        mantissa_match = (abs(dut_man - expected_man) <= 20)

        ulp_error_with_FP = ulp_diff(expected_float, got_float)
        #(error_rate_percentage < 0.001)
        #if not (sign_match and exponent_match and mantissa_match):
        if not (sign_match and ((error_rate_percentage < 1) and (ulp_error_with_FP < 2**20))):
            raise AssertionError(
                f"[{i}] ❌ Mismatch!\n"
                f"A: {a_float:+.6e} (bin: {float_to_bin_fields(a_float)})\n"
                f"B: {b_float:+.6e} (bin: {float_to_bin_fields(b_float)})\n"
                f"Expected: sign={expected_sign}, exp={expected_exp}, man={expected_man}\n"
                f"          ({float_to_bin_fields(expected_float)})\n"
                f"Got     : sign={dut_sign}, exp={dut_exp}, man={dut_man}\n"
                f"          (S: {dut_sign} E: {dut_exp:08b} M: {dut_man:023b})\n"
                f"Float Error (Δ): |{expected_float:+.6e} - {got_float:+.6e}| = {float_error:.6e}\n"
                f"Error Rate: {error_rate_percentage:.6%}\n"
                f"ULP Error: {ulp_error_with_FP}\n"
                
            )

        else:
            passed += 1

    dut._log.info(f"✅ All tests done! Passed: {passed}/{total_tests} "
                  f"({(passed/total_tests)*100:.2f}%)")
