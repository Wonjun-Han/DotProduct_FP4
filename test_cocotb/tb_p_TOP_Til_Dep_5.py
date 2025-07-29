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
        scale_sums.append(a + b - 254)

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
                f"\n[\u274c DEPTH 0 - {i}]\n"
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

    over_limit_indices = []

    for i in range(256):
        mul_exp_debug = int(getattr(dut, f"io_debug_mul_exp_{i}").value.integer)
        if mul_exp_debug > 4:
            a_val_bin = format(a_raw[i], '#06b')  # 0bXXXX
            b_val_bin = format(b_raw[i], '#06b')
            over_limit_indices.append((i, mul_exp_debug, a_val_bin, b_val_bin))

    if over_limit_indices:
        msg = "[❌ Error] mul_exp_debug exceeded allowed maximum (4)\n"
        for idx, val, a_bin, b_bin in over_limit_indices:
            msg += f" - Index {idx:03d}: mul_exp = {val}, A = {a_bin}, B = {b_bin}\n"
        raise AssertionError(msg)

    dut._log.info("✅ All mul_exp_debug values are within limit (≤ 4)")

    

    for group_idx in range(8):
        group_sum = 0.0
        group_inputs_debug = ""
        for j in range(32):
            idx = group_idx * 32 + j
            a_val = decode_mxfp4(a_raw[idx])
            b_val = decode_mxfp4(b_raw[idx])
            group_inputs_debug += f"  - A[{j:02d}]: {format(a_raw[idx], '#06b')} → {a_val: .4f}\n"
            group_inputs_debug += f"  - B[{j:02d}]: {format(b_raw[idx], '#06b')} → {b_val: .4f}\n"
            group_sum += a_val * b_val

        scale_exp = scale_sums[group_idx]
        scaled_sum = group_sum * (2 ** scale_exp)

        expected_bits = float_to_bits(scaled_sum)
        expected_sign, expected_exp, expected_man = get_fp32_fields(expected_bits)

        dut_sign = int(getattr(dut, f"io_out_{group_idx}_sign").value)
        dut_exp  = int(getattr(dut, f"io_out_{group_idx}_exponent").value)
        dut_man  = int(getattr(dut, f"io_out_{group_idx}_mantissa").value)
        # ---- 디버그용 중간 결과 읽기 ----
        real_exp     = int(getattr(dut, f"io_debug_real_exp_{group_idx}").value.signed_integer)
        biased_exp   = int(getattr(dut, f"io_debug_biased_exp_{group_idx}").value.signed_integer)
        shift_amt    = int(getattr(dut, f"io_debug_shift_amt_{group_idx}").value.signed_integer)
        PE           = int(getattr(dut, f"io_debug_PE_{group_idx}").value)
        abs_in       = int(getattr(dut, f"io_debug_abs_in_{group_idx}").value)

        scale_sum_debug = int(getattr(dut, f"io_debug_scale_sum_{group_idx}").value.signed_integer)
        scale_emax_debug = int(getattr(dut, f"io_debug_scale_emax_{group_idx}").value.signed_integer)
    

        exp_gmax = int(getattr(dut, f"io_debug_exp_gmax_{group_idx}").value)

        print(f"[DEBUG] Group {group_idx}")
        print(f"  • Scale Sum (debug) : {scale_sum_debug}")
        print(f"  • Group Max Exp (debug): {exp_gmax}")
        print(f"  • Scale Emax (debug): {scale_emax_debug}")
        

        print(f"  • Real Exponent     : {real_exp}")
        print(f"  • Biased Exponent   : {biased_exp}")
        print(f"  • Shift Amount      : {shift_amt}")
        print(f"  • Priority Encoder  : {PE}")
        print(f"  • Abs Input (fixed) : 0b{abs_in:013b} ({abs_in})")


        if (scaled_sum != 0.0) and (
            dut_sign != expected_sign or
            abs(dut_exp - expected_exp) > 0 or
            abs(dut_man - expected_man) > 0
        ):
            raise AssertionError(
                f"\n[\u274c DEPTH 5 - Group {group_idx}]\n"
                f"🔸 Group Sum (pre-scale): {group_sum:.6e}\n"
                f"🔸 Scale Sum: {scale_exp} → Scaled Sum: {scaled_sum:.6e}\n\n"
                f"🧪 Expected FP32:\n"
                f"  - Sign     : {expected_sign} (0b{expected_sign:01b})\n"
                f"  - Exponent : {expected_exp} (0b{expected_exp:08b})\n"
                f"  - Mantissa : {expected_man} (0b{expected_man:023b})\n\n"
                f"💥 DUT Output:\n"
                f"  - Sign     : {dut_sign} (0b{dut_sign:01b})\n"
                f"  - Exponent : {dut_exp} (0b{dut_exp:08b})\n"
                f"  - Mantissa : {dut_man} (0b{dut_man:023b})\n\n"
                f"📏 Scale Info:\n"
                f"  - Scale A: {a_scale_raw[group_idx]}\n"
                f"  - Scale B: {b_scale_raw[group_idx]}\n"
                f"  - Scale Sum: {a_scale_raw[group_idx]} + {b_scale_raw[group_idx]} - 254 = {scale_exp}\n\n"
                f"📥 Group Inputs:\n{group_inputs_debug}"
            )

    dut._log.info("✅ Depth 5: All 8 group FP32 outputs passed!")
