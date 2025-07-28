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
async def test_p_top_til_dep_5(dut):
    a_raw = [random.randint(0, 15) for _ in range(256)]
    b_raw = [random.randint(0, 15) for _ in range(256)]

    a_scale_raw = []
    b_scale_raw = []

    scale_sums = []

    for _ in range(8):
        combined_exp = random.randint(-127, 127)
        a = random.randint(0, 254)
        b = combined_exp + 254 - a
        b = max(0, min(255, b))
        a_scale_raw.append(a)
        b_scale_raw.append(b)
        scale_sums.append(a + b - 254)  # 실제 합산값

    # Apply inputs
    for i in range(256):
        getattr(dut, f"io_a_vec_{i}").value = a_raw[i]
        getattr(dut, f"io_b_vec_{i}").value = b_raw[i]

    for i in range(8):
        getattr(dut, f"io_a_scale_{i}").value = a_scale_raw[i]
        getattr(dut, f"io_b_scale_{i}").value = b_scale_raw[i]

    # ----------------------------
    # ✅ Depth 0: Mul + FP32
    # ----------------------------
    dut.io_depth.value = 0
    await Timer(10, units='ns')

    for i in range(256):
        a_val = decode_mxfp4(a_raw[i])
        b_val = decode_mxfp4(b_raw[i])
        expected_result = a_val * b_val

        expected_bits = float_to_bits(expected_result)
        expected_sign, expected_exp, expected_man = get_fp32_fields(expected_bits)

        dut_sign = int(getattr(dut, f"io_out_FP32_{i}_sign").value)
        dut_exp  = int(getattr(dut, f"io_out_FP32_{i}_exponent").value)
        dut_man  = int(getattr(dut, f"io_out_FP32_{i}_mantissa").value)

        if (expected_result != 0.0) and (
            dut_sign != expected_sign or
            abs(dut_exp - expected_exp) > 0 or
            abs(dut_man - expected_man) > 0
        ):
            raise AssertionError(
                f"\n[❌ DEPTH 0 - {i}]\n"
                f"A: {a_raw[i]} ({a_val:.4f}), B: {b_raw[i]} ({b_val:.4f})\n"
                f"🧪 Expected FP32:\n"
                f"  - Sign     : {expected_sign} (0b{expected_sign:01b})\n"
                f"  - Exponent : {expected_exp} (0b{expected_exp:08b})\n"
                f"  - Mantissa : {expected_man} (0b{expected_man:023b})\n\n"
                f"💥 DUT Output:\n"
                f"  - Sign     : {dut_sign} (0b{dut_sign:01b})\n"
                f"  - Exponent : {dut_exp} (0b{dut_exp:08b})\n"
                f"  - Mantissa : {dut_man} (0b{dut_man:023b})\n"
            )

    dut._log.info("✅ Depth 0: All 256 MXFP4 × MXFP4 → FP32 conversion passed!")

    # ----------------------------
    # ✅ Depth 5: Adder Tree + ScaleSum
    # ----------------------------
    dut.io_depth.value = 5
    await Timer(10, units='ns')

    for group_idx in range(8):
        group_sum = 0.0
        for j in range(32):
            idx = group_idx * 32 + j
            a_val = decode_mxfp4(a_raw[idx])
            b_val = decode_mxfp4(b_raw[idx])
            product = a_val * b_val
            group_sum += product

        scale_exp = scale_sums[group_idx]
        scaled_sum = group_sum * (2 ** scale_exp)

        expected_bits = float_to_bits(scaled_sum)
        expected_sign, expected_exp, expected_man = get_fp32_fields(expected_bits)

        dut_sign = int(getattr(dut, f"io_out_{group_idx}_sign").value)
        dut_exp  = int(getattr(dut, f"io_out_{group_idx}_exponent").value)
        dut_man  = int(getattr(dut, f"io_out_{group_idx}_mantissa").value)

        if (scaled_sum != 0.0) and (
            dut_sign != expected_sign or
            abs(dut_exp - expected_exp) > 1 or
            abs(dut_man - expected_man) > 5  # allow small rounding delta
        ):
            raise AssertionError(
                f"\n[❌ DEPTH 5 - Group {group_idx}]\n"
                f"🔸 Group Sum (pre-scale): {group_sum:.6e}\n"
                f"🔸 Scale Sum: {scale_exp} → Scaled Sum: {scaled_sum:.6e}\n\n"
                f"🧪 Expected FP32:\n"
                f"  - Sign     : {expected_sign} (0b{expected_sign:01b})\n"
                f"  - Exponent : {expected_exp} (0b{expected_exp:08b})\n"
                f"  - Mantissa : {expected_man} (0b{expected_man:023b})\n\n"
                f"💥 DUT Output:\n"
                f"  - Sign     : {dut_sign} (0b{dut_sign:01b})\n"
                f"  - Exponent : {dut_exp} (0b{dut_exp:08b})\n"
                f"  - Mantissa : {dut_man} (0b{dut_man:023b})\n"
            )

    dut._log.info("✅ Depth 5: All 8 group FP32 outputs passed!")
