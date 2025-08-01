import cocotb
from cocotb.triggers import Timer
import random
import struct
import math


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


# Test

@cocotb.test()
async def test_p_top_dep_0(dut):
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
        group_idx = i // 32
        scale_a = a_scale_raw[group_idx]
        scale_b = b_scale_raw[group_idx]

        if scale_a == 255 or scale_b == 255:
            expected_result = float('nan')
        else:
            expected_result = a_val * b_val * (2 ** scale_sums[group_idx])

        if math.isnan(expected_result):
            expected_bits = 0x7FC00000  # Canonical quiet NaN
            expected_sign = 0
            expected_exp  = 0xFF
            expected_man  = 1 << 22
        else:
            expected_bits = float_to_bits(expected_result)
            expected_sign, expected_exp, expected_man = get_fp32_fields(expected_bits)

        dut_sign = int(getattr(dut, f"io_out_{i}_sign").value)
        dut_exp  = int(getattr(dut, f"io_out_{i}_exponent").value)
        dut_man  = int(getattr(dut, f"io_out_{i}_mantissa").value)
      
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



@cocotb.test()
async def test_mxfp4_mac_all_depths(dut):
    for depth in range(6):
        dut._log.info(f"\n\n================ DEPTH {depth} TEST ================")

        # ---------------------
        # Generate Inputs
        # ---------------------
        a_raw = [random.randint(0, 15) for _ in range(256)]
        b_raw = [random.randint(0, 15) for _ in range(256)]

        a_scales, b_scales, scale_sums = [], [], []
        for _ in range(8):
            total = random.randint(-127, 127)
            a = random.randint(0, 254)
            b = max(0, min(255, total + 254 - a))
            a_scales.append(a)
            b_scales.append(b)
            scale_sums.append(a + b - 254)

        # ---------------------
        # Apply Inputs
        # ---------------------
        for i in range(256):
            getattr(dut, f"io_a_vec_{i}").value = a_raw[i]
            getattr(dut, f"io_b_vec_{i}").value = b_raw[i]

        for i in range(8):
            getattr(dut, f"io_a_scale_{i}").value = a_scales[i]
            getattr(dut, f"io_b_scale_{i}").value = b_scales[i]

        dut.io_depth.value = depth
        await Timer(10, units='ns')

        # ---------------------
        # Verify Outputs
        # ---------------------
        output_count = 256 >> depth
        group_size   = 32 >> depth

        for i in range(output_count):
            group = i // group_size
            base_idx = group * group_size
            group_sum = sum(
                decode_mxfp4(a_raw[base_idx + j]) * decode_mxfp4(b_raw[base_idx + j])
                for j in range(group_size)
            )

            scale_exp = a_scales[group] + b_scales[group] - 254

            # Expected FP32
            if a_scales[group] == 255 or b_scales[group] == 255:
                exp_sign, exp_exp, exp_man = 0, 0xFF, 1 << 22  # NaN
            else:
                try:
                    scaled = group_sum * (2 ** scale_exp)
                    bits = float_to_bits(scaled)
                    exp_sign, exp_exp, exp_man = get_fp32_fields(bits)
                except OverflowError:
                    exp_sign = 0 if group_sum >= 0 else 1
                    exp_exp, exp_man = 0xFF, 0

            # DUT outputs
            dut_sign = int(getattr(dut, f"io_out_{group}_sign").value)
            dut_exp  = int(getattr(dut, f"io_out_{group}_exponent").value)
            dut_man  = int(getattr(dut, f"io_out_{group}_mantissa").value)

            # Debug
            real_exp   = int(getattr(dut, f"io_debug_real_exp_{group}").value.signed_integer)
            biased_exp = int(getattr(dut, f"io_debug_biased_exp_{group}").value.signed_integer)
            shift_amt  = int(getattr(dut, f"io_debug_shift_amt_{group}").value.signed_integer)
            PE         = int(getattr(dut, f"io_debug_PE_{group}").value)
            abs_in     = int(getattr(dut, f"io_debug_abs_in_{group}").value)
            dep1_out   = int(getattr(dut, f"io_debug_dep_1_{group}").value.signed_integer)
            ssum_dbg   = int(getattr(dut, f"io_debug_scale_sum_{group}").value.signed_integer)
            emax_dbg   = int(getattr(dut, f"io_debug_scale_emax_{group}").value.signed_integer)
            gmax_dbg   = int(getattr(dut, f"io_debug_exp_gmax_{group}").value)

            # Print Debug Info
            print(f"  • Scale Sum (debug): {ssum_dbg}")
            print(f"  • Group Max Exp    : {gmax_dbg}")
            print(f"  • Scale Emax       : {emax_dbg}")
            print(f"  • Real Exponent    : {real_exp}")
            print(f"  • Biased Exponent  : {biased_exp}")
            print(f"  • Shift Amount     : {shift_amt}")
            print(f"  • Priority Encoder : {PE}")
            print(f"  • Abs Input        : 0b{abs_in:013b} ({abs_in})")
            print(f"  • Depth 1 Output   : 0b{dep1_out:016b} ({dep1_out})")

            # Check
            if group_sum != 0.0 and (
                dut_sign != exp_sign or dut_exp != exp_exp or dut_man != exp_man
            ):
                raise AssertionError(
                    f"\n[❌ DEPTH {depth} - {i}]\n"
                    f"A × B Group {group} Sum = {group_sum:.4e}, Scale Exp = {scale_exp}\n"
                    f"Expected: sign={exp_sign}, exp={exp_exp}, man={exp_man}\n"
                    f"DUT     : sign={dut_sign}, exp={dut_exp}, man={dut_man}\n"
                    f"[❌ DEPTH {depth} - Group {group}]\n"
                    f"🔸 Group Sum (pre-scale): {group_sum:.6e}\n"
                    f"🔸 Scale Sum: {scale_exp} → Scaled Sum: {scaled:.6e}\n\n"
                    f"🧪 Expected FP32:\n"
                    f"  - Sign     : {exp_sign} (0b{exp_sign:01b})\n"
                    f"  - Exponent : {exp_exp} (0b{exp_exp:08b})\n"
                    f"  - Mantissa : {exp_man} (0b{exp_man:023b})\n\n"
                    f"💥 DUT Output:\n"
                    f"  - Sign     : {dut_sign} (0b{dut_sign:01b})\n"
                    f"  - Exponent : {dut_exp} (0b{dut_exp:08b})\n"
                    f"  - Mantissa : {dut_man} (0b{dut_man:023b})\n\n"
                    f"📏 Scale Info:\n"
                    f"  - Scale A: {a_scales[group]}\n"
                    f"  - Scale B: {b_scales[group]}\n"
                    f"  - Scale Sum: {a_scales[group]} + {b_scales[group]} - 254 = {scale_exp}\n"
                )

        dut._log.info(f"✅ DEPTH {depth}: All {output_count} outputs matched!\n")

