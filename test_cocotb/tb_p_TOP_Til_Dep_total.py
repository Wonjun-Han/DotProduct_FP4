import cocotb
from cocotb.triggers import Timer
import random
import struct
import math

NUM_TRIALS = 30000

# ---------------------------
# Helpers
# ---------------------------

def decode_mxfp4(val: int) -> float:
    """MXFP4 디코더: [s | e1 e0 | m] (총 4비트)"""
    s = (val >> 3) & 0x1
    e = (val >> 1) & 0x3
    m = val & 0x1
    if e == 0:
        return (-1.0 if s else 1.0) * (m / 2.0) if m != 0 else 0.0
    else:
        return (-1.0 if s else 1.0) * (1.0 + m / 2.0) * (2.0 ** (e - 1))

def bits_to_float(b: int) -> float:
    return struct.unpack('>f', struct.pack('>I', b))[0]

def get_fp32_fields(bits: int):
    sign     = (bits >> 31) & 0x1
    exponent = (bits >> 23) & 0xFF
    mantissa = bits & 0x7FFFFF
    return sign, exponent, mantissa

# IEEE-754 float32 최대 유한값
FLT32_MAX = 3.4028234663852886e+38

def float_to_bits_safe(f: float) -> int:
    """Python float -> IEEE754 float32 bits. 범위 초과는 ±Inf, NaN은 qNaN으로."""
    if math.isnan(f):
        return 0x7FC00000  # qNaN
    sign_bit = 0x80000000 if math.copysign(1.0, f) < 0.0 else 0
    if math.isinf(f) or abs(f) > FLT32_MAX:
        return sign_bit | 0x7F800000  # ±Inf
    try:
        return struct.unpack('>I', struct.pack('>f', f))[0]
    except OverflowError:
        return sign_bit | 0x7F800000
    

def _read_vec(dut, base_name: str, n: int, signed: bool = False):
    vals = []
    for i in range(n):
        h = getattr(dut, f"{base_name}_{i}").value
        vals.append(int(h.signed_integer if signed else h.integer))
    return vals

def _read_vec_bin(dut, base_name: str, n: int):
    return [getattr(dut, f"{base_name}_{i}").value.binstr for i in range(n)]

# ---------------------------
# Test
# ---------------------------

@cocotb.test()
async def test_mxfp4_mac_total_depths_new(dut):
    # depth 0 ~ 8 모두 검증
    for depth in range(0, 9):
        output_count = min(256 >> depth, 16)  # Only 16 FP32 outputs exposed
        products_per_output = 256 // (256 >> depth)  # = 2**depth
        

        dut._log.info(f"\n\n================ DEPTH {depth} TEST START ================\n")

        for trial in range(NUM_TRIALS):
            # ----------------------
            # 랜덤 입력 생성
            # ----------------------
            a_raw = [random.randint(0, 15) for _ in range(256)]
            b_raw = [random.randint(0, 15) for _ in range(256)]

            # 스케일 생성 (a+b-254 = scale_exp)
            a_scale_raw, b_scale_raw, scale_sums = [], [], []
            for _ in range(8):
                total = random.randint(-127, 127)
                a = random.randint(0, 254)
                b = max(0, min(255, total + 254 - a))
                a_scale_raw.append(a)
                b_scale_raw.append(b)
                scale_sums.append(a + b - 254)

            # ----------------------
            # DUT 구동
            # ----------------------
            for i in range(256):
                getattr(dut, f"io_a_vec_{i}").value = a_raw[i]
                getattr(dut, f"io_b_vec_{i}").value = b_raw[i]
            for i in range(8):
                getattr(dut, f"io_a_scale_{i}").value = a_scale_raw[i]
                getattr(dut, f"io_b_scale_{i}").value = b_scale_raw[i]

            dut.io_depth.value = depth
            await Timer(10, units='ns')

            # ---- DEPTH 6 디버그: 매 트라이얼 출력 ----
            if depth == 6:
                a6_m = _read_vec(dut, "io_adder6_out_mantissa", 4, signed=False)
                a6_s = _read_vec(dut, "io_adder6_out_sign", 4, signed=False)
                a6_m_bin = _read_vec_bin(dut, "io_adder6_out_mantissa", 4)
                a6_s_bin = _read_vec_bin(dut, "io_adder6_out_sign", 4)

                dut._log.info(
                    "[DBG][DEPTH 6][Trial %d] adder6_out_mantissa=%s (bin=%s), adder6_out_sign=%s (bin=%s)",
                    trial + 1,
                    a6_m,
                    a6_m_bin,
                    a6_s,
                    a6_s_bin,
                )
            # ---- DEPTH 6 디버그 끝 ----

            # ---- DEPTH 7 디버그: 매 트라이얼 출력 ----
            if depth == 7:
                a7_m = _read_vec(dut, "io_adder7_out_mantissa", 2, signed=False)
                a7_s = _read_vec(dut, "io_adder7_out_sign", 2, signed=False)
                a7_m_bin = _read_vec_bin(dut, "io_adder7_out_mantissa", 2)
                a7_s_bin = _read_vec_bin(dut, "io_adder7_out_sign", 2)

                dut._log.info(
                    "[DBG][DEPTH 7][Trial %d] adder7_out_mantissa=%s (bin=%s), adder7_out_sign=%s (bin=%s)",
                    trial + 1,
                    a7_m,
                    a7_m_bin,
                    a7_s,
                    a7_s_bin,
                )
            # ---- DEPTH 7 디버그 끝 ----

            # ---- DEPTH 8 디버그: 매 트라이얼 출력 ----
            if depth == 8:
                a8_m = _read_vec(dut, "io_adder8_out_mantissa", 1, signed=False)
                a8_s = _read_vec(dut, "io_adder8_out_sign", 1, signed=False)
                a8_m_bin = _read_vec_bin(dut, "io_adder8_out_mantissa", 1)
                a8_s_bin = _read_vec_bin(dut, "io_adder8_out_sign", 1)

                dut._log.info(
                    "[DBG][DEPTH 8][Trial %d] adder8_out_mantissa=%s (bin=%s), adder8_out_sign=%s (bin=%s)",
                    trial + 1,
                    a8_m,
                    a8_m_bin,
                    a8_s,
                    a8_s_bin,
                )
            # ---- DEPTH 8 디버그 끝 ----


            # ----------------------
            # Depth 6/7/8용 타일 합/NaN 미리 계산
            # ----------------------
            tile_scaled_sum = [0.0]*8
            tile_nan = [False]*8
            for t in range(8):
                base = t * 32
                local_sum = 0.0
                for j in range(32):
                    idx = base + j
                    a_val = decode_mxfp4(a_raw[idx])
                    b_val = decode_mxfp4(b_raw[idx])
                    local_sum += a_val * b_val

                # 타일 스케일 적용
                scale_exp_t = scale_sums[t]
                tile_scaled_sum[t] = math.ldexp(local_sum, scale_exp_t)  # local_sum * 2**scale_exp_t

                # NaN 전파 조건 (스펙: scale_a==255 or scale_b==255)
                tile_nan[t] = (a_scale_raw[t] == 255) or (b_scale_raw[t] == 255)

            # depth별 그룹 묶음 정의 (앞에서부터 매핑)
            if depth == 6:
                groups = [[0,1], [2,3], [4,5], [6,7]]
            elif depth == 7:
                groups = [[0,1,2,3], [4,5,6,7]]
            elif depth == 8:
                groups = [[0,1,2,3,4,5,6,7]]
            

            # ----------------------
            # Validation
            # ----------------------
            for i in range(16):  # Only validate 16 exposed outputs
                dut_sign = int(getattr(dut, f"io_out_{i}_sign").value)
                dut_exp  = int(getattr(dut, f"io_out_{i}_exponent").value)
                dut_man  = int(getattr(dut, f"io_out_{i}_mantissa").value)
                dut_bits = (dut_sign << 31) | (dut_exp << 23) | dut_man

                if i < output_count:
                    if depth <= 5:
                        # 기존 방식 (한 출력이 products_per_output개를 합산)
                        group_size = 32 >> depth
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
                        if (a_scale_raw[group_idx] == 255) or (b_scale_raw[group_idx] == 255):
                            expected_bits = 0x7FC00000  # qNaN
                            expected_float = float('nan')
                            expected_sign, expected_exp, expected_man = 0, 0xFF, 1 << 22
                        else:
                            expected_float = math.ldexp(local_sum, scale_exp)
                            expected_bits = float_to_bits_safe(expected_float)
                            expected_sign, expected_exp, expected_man = get_fp32_fields(expected_bits)

                    else:
                        # depth 6/7/8: 타일 합을 그룹으로 묶어 누적
                        tiles = groups[i]
                        group_has_nan = any(tile_nan[t] for t in tiles)
                        if group_has_nan:
                            expected_bits = 0x7FC00000  # qNaN
                            expected_float = float('nan')
                            expected_sign, expected_exp, expected_man = 0, 0xFF, 1 << 22
                        else:
                            expected_float = sum(tile_scaled_sum[t] for t in tiles)
                            expected_bits = float_to_bits_safe(expected_float)
                            expected_sign, expected_exp, expected_man = get_fp32_fields(expected_bits)

                    # 비교
                    if (expected_sign != dut_sign or expected_exp != dut_exp or abs(expected_man - dut_man) > 1):
                        # 실패 직전
                        dbg_block = ""
                        if depth == 6:
                            # 1) 전체 8개 타일 합/NaN
                            tile_sums_all = tile_scaled_sum                 # len=8
                            tile_nans_all = tile_nan                        # len=8

                            # 2) 그룹(쌍) 합/NaN: 4개
                            pair_sums  = [sum(tile_scaled_sum[t] for t in g) for g in groups]  # len=4
                            pair_nans  = [any(tile_nan[t] for t in g) for g in groups]         # len=4

                            # 3) 이번 출력 i가 사용하는 타일 쌍(2개)
                            pair_tiles      = groups[i]                     # len=2
                            pair_tiles_sums = [tile_scaled_sum[t] for t in pair_tiles]
                            pair_tiles_nans = [tile_nan[t] for t in pair_tiles]

                            # adder6 출력도 함께
                            a6_m     = _read_vec(dut, "io_adder6_out_mantissa", 4, signed=False)
                            a6_s     = _read_vec(dut, "io_adder6_out_sign", 4, signed=False)
                            a6_m_bin = _read_vec_bin(dut, "io_adder6_out_mantissa", 4)
                            a6_s_bin = _read_vec_bin(dut, "io_adder6_out_sign", 4)

                            dbg_block = (
                                "\n🔎 DBG (Depth 6)\n"
                                f"  • tiles(all idx)       = {list(range(8))}\n"
                                f"  • tile_sums_all(8)     = {tile_sums_all}\n"
                                f"  • tile_nans_all(8)     = {tile_nans_all}\n"
                                f"  • groups(pair idx)     = {groups}\n"
                                f"  • pair_sums(4)         = {pair_sums}\n"
                                f"  • pair_nans(4)         = {pair_nans}\n"
                                f"  • pair_tiles(for out {i}) = {pair_tiles}\n"
                                f"  • pair_tiles_sums(2)   = {pair_tiles_sums}\n"
                                f"  • pair_tiles_nans(2)   = {pair_tiles_nans}\n"
                                f"  • adder6_out_sign(4)   = {a6_s} (bin={a6_s_bin})\n"
                                f"  • adder6_out_mantissa(4)= {a6_m} (bin={a6_m_bin})\n"
                            )

                        elif depth == 7:
                            # 1) 전체 8개 타일 합/NaN
                            tile_sums_all = tile_scaled_sum
                            tile_nans_all = tile_nan
                            
                            # 2) 그룹(쌍) 합/NaN: 2개
                            pair_sums  = [sum(tile_scaled_sum[t] for t in g) for g in groups]  # len=2
                            pair_nans  = [any(tile_nan[t] for t in g) for g in groups]         # len=2

                            # 3) 이번 출력 i가 사용하는 타일 쌍(4개)
                            pair_tiles      = groups[i]                     # len=4
                            pair_tiles_sums = [tile_scaled_sum[t] for t in pair_tiles]
                            pair_tiles_nans = [tile_nan[t] for t in pair_tiles]

                            # adder7 출력도 함께
                            a7_m     = _read_vec(dut, "io_adder7_out_mantissa", 2, signed=False)
                            a7_s     = _read_vec(dut, "io_adder7_out_sign", 2, signed=False)
                            a7_m_bin = _read_vec_bin(dut, "io_adder7_out_mantissa", 2)
                            a7_s_bin = _read_vec_bin(dut, "io_adder7_out_sign", 2)  

                            dbg_block = (
                                "\n🔎 DBG (Depth 7)\n"
                                f"  • tiles(all idx)       = {list(range(8))}\n"
                                f"  • tile_sums_all(8)     = {tile_sums_all}\n"
                                f"  • tile_nans_all(8)     = {tile_nans_all}\n"
                                f"  • groups(pair idx)     = {groups}\n"
                                f"  • pair_sums(2)         = {pair_sums}\n"
                                f"  • pair_nans(2)         = {pair_nans}\n"
                                f"  • pair_tiles(for out {i}) = {pair_tiles}\n"
                                f"  • pair_tiles_sums(4)   = {pair_tiles_sums}\n"
                                f"  • pair_tiles_nans(4)   = {pair_tiles_nans}\n"
                                f"  • adder7_out_sign(2)   = {a7_s} (bin={a7_s_bin})\n"
                                f"  • adder7_out_mantissa(2)= {a7_m} (bin={a7_m_bin})\n"
                            )

                        else:
                            # depth 8은 단순히 타일 합산
                            tile_sums_all = tile_scaled_sum
                            tile_nans_all = tile_nan

                            # NaN 전파 여부
                            group_has_nan = any(tile_nan[t] for t in tiles)

                            # adder8 출력도 함께
                            a8_m     = _read_vec(dut, "io_adder8_out_mantissa", 1, signed=False)
                            a8_s     = _read_vec(dut, "io_adder8_out_sign", 1, signed=False)
                            a8_m_bin = _read_vec_bin(dut, "io_adder8_out_mantissa", 1)
                            a8_s_bin = _read_vec_bin(dut, "io_adder8_out_sign", 1)  

                            dbg_block = (
                                "\n🔎 DBG (Depth 8)\n"
                                f"  • tiles(all idx)       = {list(range(8))}\n"
                                f"  • tile_sums_all(8)     = {tile_sums_all}\n"
                                f"  • tile_nans_all(8)     = {tile_nans_all}\n"
                            )


                        raise AssertionError(
                            f"\n[❌ Trial {trial + 1} | DEPTH {depth} | Output {i}]\n"
                            f"🧮 Expected Float: {expected_float:.6e}\n"
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
                            f"{dbg_block}"

                        )
                else:
                    # 패딩 영역은 0.0f 여야 함
                    if not (dut_sign == 0 and dut_exp == 0 and dut_man == 0):
                        raise AssertionError(
                            f"[❌ Padding Error @ DEPTH {depth} | i={i}]\n"
                            f"Expected 0.0f (FP32 all-zero), got: sign={dut_sign}, exp={dut_exp}, man={dut_man}"
                        )

            dut._log.info(f"✅ Trial {trial + 1}/{NUM_TRIALS} PASSED for Depth {depth}")
        dut._log.info(f"🎉✅ All trials passed for Depth {depth}!\n")
        dut._log.info("────────────────────────────────────────────────────────────")
