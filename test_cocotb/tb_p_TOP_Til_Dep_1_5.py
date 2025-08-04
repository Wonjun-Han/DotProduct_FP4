import cocotb
from cocotb.triggers import Timer
import random
import struct
import math

NUM_TRIALS = 2000

def decode_mxfp4(val):
    s = (val >> 3) & 0x1
    e = (val >> 1) & 0x3
    m = val & 0x1
    if e == 0:
        return (-1)**s * (m / 2) if m != 0 else 0.0
    else:
        return (-1)**s * (1 + m / 2) * (2**(e - 1))

def float_to_bits(f):
    return struct.unpack('>I', struct.pack('>f', f))[0]

def bits_to_float(b):
    return struct.unpack('>f', struct.pack('>I', b))[0]

def get_fp32_fields(bits):
    sign     = (bits >> 31) & 0x1
    exponent = (bits >> 23) & 0xFF
    mantissa = bits & 0x7FFFFF
    return sign, exponent, mantissa


@cocotb.test()
async def test_mxfp4_mac_all_depths_new(dut):
    for depth in range(0, 6):
        output_count = min(256 >> depth, 16)  # Only 16 FP32 outputs exposed
        group_size = 32 >> depth
        products_per_output = 256 // (256 >> depth)

        dut._log.info(f"\n\n================ DEPTH {depth} TEST START ================\n")

        for trial in range(NUM_TRIALS):
            a_raw = [random.randint(0, 15) for _ in range(256)]
            b_raw = [random.randint(0, 15) for _ in range(256)]

            a_scale_raw, b_scale_raw, scale_sums = [], [], []
            for _ in range(8):
                total = random.randint(-127, 127)
                a = random.randint(0, 254)
                b = max(0, min(255, total + 254 - a))
                a_scale_raw.append(a)
                b_scale_raw.append(b)
                scale_sums.append(a + b - 254)

            for i in range(256):
                getattr(dut, f"io_a_vec_{i}").value = a_raw[i]
                getattr(dut, f"io_b_vec_{i}").value = b_raw[i]
            for i in range(8):
                getattr(dut, f"io_a_scale_{i}").value = a_scale_raw[i]
                getattr(dut, f"io_b_scale_{i}").value = b_scale_raw[i]

            dut.io_depth.value = depth
            await Timer(10, units='ns')

            for i in range(16):  # Only validate 16 exposed outputs
                dut_sign = int(getattr(dut, f"io_out_{i}_sign").value)
                dut_exp  = int(getattr(dut, f"io_out_{i}_exponent").value)
                dut_man  = int(getattr(dut, f"io_out_{i}_mantissa").value)

                if i < (256 >> depth):
                    group_idx = i // group_size
                    local_idx = i % group_size
                    base = group_idx * 32 + local_idx * products_per_output
                    local_sum = 0.0
                    for j in range(products_per_output):
                        idx = base + j
                        a_val = decode_mxfp4(a_raw[idx])
                        b_val = decode_mxfp4(b_raw[idx])
                        local_sum += a_val * b_val

                    scale_exp = scale_sums[group_idx]
                    scale_a = a_scale_raw[group_idx]
                    scale_b = b_scale_raw[group_idx]

                    if scale_a == 255 or scale_b == 255:
                        expected_bits = 0x7FC00000
                        expected_sign, expected_exp, expected_man = 0, 0xFF, 1 << 22
                    else:
                        try:
                            expected_float = local_sum * (2 ** scale_exp)
                            expected_bits = float_to_bits(expected_float)
                            expected_sign, expected_exp, expected_man = get_fp32_fields(expected_bits)
                        except OverflowError:
                            expected_float = float('inf') if local_sum > 0 else float('-inf')
                            expected_bits = float_to_bits(expected_float)
                            expected_sign, expected_exp, expected_man = get_fp32_fields(expected_bits)

                    dut_bits = (dut_sign << 31) | (dut_exp << 23) | dut_man

                    if dut_bits != expected_bits:
                        raise AssertionError(
                            f"\n[❌ Trial {trial + 1} | DEPTH {depth} | Output {i}]\n"
                            f"🔸 Local Sum (pre-scale): {local_sum:.6e}\n"
                            f"🔸 Scale Exp: {scale_exp} → Scaled Sum: {expected_float:.6e}\n"
                            f"🧪 Expected FP32:\n"
                            f"  - Sign     : {expected_sign} (0b{expected_sign:01b})\n"
                            f"  - Exponent : {expected_exp} (0b{expected_exp:08b})\n"
                            f"  - Mantissa : {expected_man} (0b{expected_man:023b})\n"
                            f"  - FP32 Bits: 0x{expected_bits:08X}\n\n"
                            f"💥 DUT Output:\n"
                            f"  - Sign     : {dut_sign} (0b{dut_sign:01b})\n"
                            f"  - Exponent : {dut_exp} (0b{dut_exp:08b})\n"
                            f"  - Mantissa : {dut_man} (0b{dut_man:023b})\n"
                            f"  - FP32 Bits: 0x{dut_bits:08X}\n"
                        )
                else:
                    if not (dut_sign == 0 and dut_exp == 0 and dut_man == 0):
                        raise AssertionError(
                            f"[❌ Padding Error @ DEPTH {depth} | i={i}]\n"
                            f"Expected 0.0f (FP32 all-zero), got: sign={dut_sign}, exp={dut_exp}, man={dut_man}"
                        )

            dut._log.info(f"✅ Trial {trial + 1}/{NUM_TRIALS} PASSED for Depth {depth}")
        dut._log.info(f"🎉✅ All trials passed for Depth {depth}!\n")
        dut._log.info("────────────────────────────────────────────────────────────")

