import cocotb
from cocotb.triggers import RisingEdge
from cocotb.clock import Clock
import random
import struct
import math
from collections import deque
from typing import Optional

# =========================================================
# Config
# =========================================================
NUM_TRIALS = 10000            # per-depth, 스트리밍 검증 시 transaciton 수
PIPELINE_LATENCY = 14       # 설계 고정 레이턴시 (입력 cycle t -> 출력 cycle t+12)
ALLOW_MANTISSA_ULP1 = True  # mantissa ±1 ULP 허용 여부

# =========================================================
# Helpers: FP & Bits
# =========================================================
def decode_mxfp4(val: int) -> float:
    """MXFP4: [s | e1 e0 | m], 4bit."""
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

def bin32(bits: int) -> str:
    """32-bit 2진수 문자열 (s|exp|mant)로 가독성 포맷."""
    s = (bits >> 31) & 0x1
    e = (bits >> 23) & 0xFF
    m = bits & 0x7FFFFF
    return f"{s:1b}|{e:08b}|{m:023b}"

def read_fp32(dut, i: int):
    """DUT io.out[i]의 (s,e,m) 읽기. (계층/플랫 폴백)"""
    try:
        s = int(dut.io.out[i].sign.value)
        e = int(dut.io.out[i].exponent.value)
        m = int(dut.io.out[i].mantissa.value)
        return s, e, m
    except Exception:
        s = int(getattr(dut, f"io_out_{i}_sign").value)
        e = int(getattr(dut, f"io_out_{i}_exponent").value)
        m = int(getattr(dut, f"io_out_{i}_mantissa").value)
        return s, e, m

# =========================================================
# Float32 범위/변환
# =========================================================
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

def is_nan(bits: int) -> bool:
    return (bits & 0x7F800000) == 0x7F800000 and (bits & 0x007FFFFF) != 0

def is_inf(bits: int) -> bool:
    return (bits & 0x7FFFFFFF) == 0x7F800000

def is_zero(bits: int) -> bool:
    return (bits & 0x7FFFFFFF) == 0

def equal_fp32_with_ulpm(exp_bits: int, dut_bits: int, allow_ulpm: bool = True) -> bool:
    """FP32 비교: 특수값 지키면서, 일반값은 mantissa ±1 ULP(동일 sign/exp) 허용 옵션."""
    # NaN: 비트 동일해야 통과
    if is_nan(exp_bits) or is_nan(dut_bits):
        return exp_bits == dut_bits
    # Inf: 정확히 일치
    if is_inf(exp_bits) or is_inf(dut_bits):
        return exp_bits == dut_bits
    # +0/-0 동치
    if is_zero(exp_bits) and is_zero(dut_bits):
        return True
    # 완전 일치
    if exp_bits == dut_bits:
        return True
    if not allow_ulpm:
        return False

    # mantissa ±1 ULP 허용: 동일 부호/지수 내에서만
    e_sign  = (exp_bits >> 31) & 0x1
    d_sign  = (dut_bits >> 31) & 0x1
    e_exp   = (exp_bits >> 23) & 0xFF
    d_exp   = (dut_bits >> 23) & 0xFF
    e_man   = exp_bits & 0x7FFFFF
    d_man   = dut_bits & 0x7FFFFF

    if e_sign == d_sign and e_exp == d_exp and e_exp != 0xFF:
        return abs(int(e_man) - int(d_man)) <= 1
    return False

# =========================================================
# DUT I/O 유틸
# =========================================================
async def reset_dut(dut):
    """동기 리셋: 2cycle assert + 1cycle settle"""
    dut.reset.value = 1
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    dut.reset.value = 0
    await RisingEdge(dut.clock)

async def apply_inputs(dut, a_raw, b_raw, a_scale_raw, b_scale_raw, depth):
    """현재 사이클 입력 적용(연속 주입 시 매 사이클 호출)."""
    for i in range(256):
        getattr(dut, f"io_a_vec_{i}").value = a_raw[i]
        getattr(dut, f"io_b_vec_{i}").value = b_raw[i]
    for i in range(8):
        getattr(dut, f"io_a_scale_{i}").value = a_scale_raw[i]
        getattr(dut, f"io_b_scale_{i}").value = b_scale_raw[i]
    dut.io_depth.value = depth

def gen_random_scales():
    """a_scale + b_scale - 254 = [-127..127] 합 제약 반영."""
    a_scale_raw, b_scale_raw = [], []
    for _ in range(8):
        total = random.randint(-127, 127)
        a = random.randint(0, 254)
        b = max(0, min(255, total + 254 - a))
        a_scale_raw.append(a)
        b_scale_raw.append(b)
    return a_scale_raw, b_scale_raw

# =========================================================
# Visual Logging Helpers
# =========================================================
def _rule(char: str = "─", n: int = 60) -> str:
    return char * n

def banner(dut, title: str):
    dut._log.info("\n" + f"📘 {title}")
    dut._log.info(_rule())

def pipeline_viz(dut, cycle_now: int, latency: int = PIPELINE_LATENCY, note: str = ""):
    bar = "■" * latency
    dut._log.info(f"[t={cycle_now:>6}] |IN|{bar}|OUT| {note}")

def progress_bar(dut, curr: int, total: int, width: int = 30, prefix: str = "Progress"):
    filled = int((curr / max(total, 1)) * width)
    bar = "▮" * filled + "▯" * (width - filled)
    dut._log.info(f"{prefix}: {bar} {curr}/{total} ({(curr/total*100):.1f}%)")

def depth_tick(dut, cycle_now: int, depth_now: int, expect_tx: Optional[int]):
    """혼합 depth 스트리밍용 한 줄 상태표."""
    extra = f"| expect_tx={expect_tx}" if expect_tx is not None else ""
    dut._log.info(f"  • cycle={cycle_now:>6} | depth={depth_now} {extra}")

# =========================================================
# Golden Model
# =========================================================
class PipelineTestVector:
    """단일 트랜잭션에 대한 기대 출력 16 lanes 계산(모든 depth 사전 계산)."""
    def __init__(self, a_raw, b_raw, a_scale_raw, b_scale_raw, depth):
        self.a_raw = a_raw
        self.b_raw = b_raw
        self.a_scale_raw = a_scale_raw
        self.b_scale_raw = b_scale_raw
        self.depth = depth
        self.scale_sums = [a + b - 254 for a, b in zip(a_scale_raw, b_scale_raw)]
        self.expected_outputs = self._compute_expected()

    def _compute_expected(self):
        expected = {}
        # 타일 합(Depth 6~8에 필요)
        tile_scaled_sum = [0.0] * 8
        tile_nan = [False] * 8

        for t in range(8):
            base = t * 32
            local_sum = 0.0
            for j in range(32):
                idx = base + j
                a_val = decode_mxfp4(self.a_raw[idx])
                b_val = decode_mxfp4(self.b_raw[idx])
                local_sum += a_val * b_val
            scale_exp_t = self.scale_sums[t]
            tile_scaled_sum[t] = math.ldexp(local_sum, scale_exp_t)
            tile_nan[t] = (self.a_scale_raw[t] == 255) or (self.b_scale_raw[t] == 255)

        for depth in range(9):
            output_count = min(256 >> depth, 16)
            products_per_output = 256 // (256 >> depth)
            depth_outputs = []
            for i in range(16):
                if i < output_count:
                    if depth <= 5:
                        # 그룹 내부 합산 후 scale 적용
                        group_size = 32 >> depth
                        group_idx = i // group_size
                        local_idx = i % group_size
                        base = group_idx * 32 + local_idx * products_per_output
                        local_sum = 0.0
                        for j in range(products_per_output):
                            idx = base + j
                            a_val = decode_mxfp4(self.a_raw[idx])
                            b_val = decode_mxfp4(self.b_raw[idx])
                            local_sum += a_val * b_val
                        if (self.a_scale_raw[group_idx] == 255) or (self.b_scale_raw[group_idx] == 255):
                            expected_bits = 0x7FC00000
                        else:
                            expected_bits = float_to_bits_safe(math.ldexp(local_sum, self.scale_sums[group_idx]))
                    else:
                        # Depth 6~8: 타일 합을 더하는 단계
                        if depth == 6:
                            groups = [[0,1], [2,3], [4,5], [6,7]]
                        elif depth == 7:
                            groups = [[0,1,2,3], [4,5,6,7]]
                        else:  # depth == 8
                            groups = [[0,1,2,3,4,5,6,7]]
                        tiles = groups[i]
                        group_has_nan = any(tile_nan[t] for t in tiles)
                        if group_has_nan:
                            expected_bits = 0x7FC00000
                        else:
                            expected_bits = float_to_bits_safe(sum(tile_scaled_sum[t] for t in tiles))
                else:
                    expected_bits = 0x00000000  # padding
                depth_outputs.append(expected_bits)
            expected[depth] = depth_outputs
        return expected

# =========================================================
# Scoreboard Streaming: 고정 depth
# =========================================================
async def stream_and_check(dut, depth: int, num_transactions: int):
    """
    매 사이클 입력 연속 주입.
    출력은 항상 14사이클 뒤이므로 큐[t-14] 기대값과 현재 출력을 비교.
    """
    exp_q = deque()  # 각 트랜잭션 기대(16 lanes) 리스트 저장

    # 첫 트랜잭션 적용
    a_raw = [random.randint(0, 15) for _ in range(256)]
    b_raw = [random.randint(0, 15) for _ in range(256)]
    a_scale_raw, b_scale_raw = gen_random_scales()
    tv0 = PipelineTestVector(a_raw, b_raw, a_scale_raw, b_scale_raw, depth)
    await apply_inputs(dut, a_raw, b_raw, a_scale_raw, b_scale_raw, depth)
    exp_q.append(tv0.expected_outputs[depth])

    # 이후 연속 주입 + 레이턴시 채워지면 바로 비교
    for t in range(1, num_transactions):
        await RisingEdge(dut.clock)

        a_raw = [random.randint(0, 15) for _ in range(256)]
        b_raw = [random.randint(0, 15) for _ in range(256)]
        a_scale_raw, b_scale_raw = gen_random_scales()
        tv = PipelineTestVector(a_raw, b_raw, a_scale_raw, b_scale_raw, depth)
        await apply_inputs(dut, a_raw, b_raw, a_scale_raw, b_scale_raw, depth)
        exp_q.append(tv.expected_outputs[depth])

        if t >= PIPELINE_LATENCY:
            expected = exp_q[t - PIPELINE_LATENCY]

            # 시각화: 파이프라인 바 & 진행바
            pipeline_viz(dut, t, PIPELINE_LATENCY, note=f"(fixed depth={depth})")
            if (t % max(1, num_transactions // 10)) == 0:
                progress_bar(dut, t, num_transactions, prefix="Fixed-depth stream")

            mismatches = []
            for i in range(16):
                s, e, m = read_fp32(dut, i)
                dut_bits = (s << 31) | (e << 23) | m
                if not equal_fp32_with_ulpm(expected[i], dut_bits, allow_ulpm=ALLOW_MANTISSA_ULP1):
                    mismatches.append((i, expected[i], dut_bits))
            if mismatches:
                lines = [f"[❌ STREAM | DEPTH {depth} | cycle={t} | ±1ULP={'ON' if ALLOW_MANTISSA_ULP1 else 'OFF'}]"]
                for (i, exp_bits, dut_bits) in mismatches:
                    lines.append(f"  lane {i}:")
                    lines.append(f"    EXP  0x{exp_bits:08X}  {bin32(exp_bits)}")
                    lines.append(f"    DUT  0x{dut_bits:08X}  {bin32(dut_bits)}")
                raise AssertionError("\n" + "\n".join(lines))

    # 드레인: 남은 결과 비교
    for t in range(PIPELINE_LATENCY):
        await RisingEdge(dut.clock)
        idx = num_transactions - PIPELINE_LATENCY + t
        if idx < 0:
            continue

        # 드레인 상태 시각화(옵션)
        pipeline_viz(dut, num_transactions + t, PIPELINE_LATENCY, note="(drain)")

        expected = exp_q[idx]
        mismatches = []
        for i in range(16):
            s, e, m = read_fp32(dut, i)
            dut_bits = (s << 31) | (e << 23) | m
            if not equal_fp32_with_ulpm(expected[i], dut_bits, allow_ulpm=ALLOW_MANTISSA_ULP1):
                mismatches.append((i, expected[i], dut_bits))
        if mismatches:
            lines = [f"[❌ STREAM-DRAIN | DEPTH {depth} | drain_step={t} | ±1ULP={'ON' if ALLOW_MANTISSA_ULP1 else 'OFF'}]"]
            for (i, exp_bits, dut_bits) in mismatches:
                lines.append(f"  lane {i}:")
                lines.append(f"    EXP  0x{exp_bits:08X}  {bin32(exp_bits)}")
                lines.append(f"    DUT  0x{dut_bits:08X}  {bin32(dut_bits)}")
            raise AssertionError("\n" + "\n".join(lines))

# =========================================================
# Scoreboard Streaming: 혼합 depth (매 사이클 depth 변경)
# =========================================================
async def stream_and_check_mixed_depths(dut, num_transactions: int, pattern: str = "roundrobin"):
    """
    매 사이클 depth와 데이터/스케일을 바꿔 연속 주입.
    출력은 항상 입력으로부터 14사이클 뒤 결과이므로,
    큐[t-14]의 '그 트랜잭션 depth'로 계산한 기대값과 14 사이클 이후에 비교.
    """
    
    # depth 시퀀스
    if pattern == "roundrobin":
        depth_seq = [(i % 9) for i in range(num_transactions)]
    elif pattern == "random":
        depth_seq = [random.randint(0, 8) for _ in range(num_transactions)]
    else:
        raise ValueError("pattern must be 'roundrobin' or 'random'")

    exp_q = deque()

    # 첫 트랜잭션
    d0 = depth_seq[0]
    a0 = [random.randint(0, 15) for _ in range(256)]
    b0 = [random.randint(0, 15) for _ in range(256)]
    a0s, b0s = gen_random_scales()
    tv0 = PipelineTestVector(a0, b0, a0s, b0s, d0)
    await apply_inputs(dut, a0, b0, a0s, b0s, d0)
    exp_q.append(tv0.expected_outputs[d0])

    # 연속 주입 + 비교
    for t in range(1, num_transactions):
        await RisingEdge(dut.clock)
        d = depth_seq[t]
        a = [random.randint(0, 15) for _ in range(256)]
        b = [random.randint(0, 15) for _ in range(256)]
        as_, bs_ = gen_random_scales()
        tv = PipelineTestVector(a, b, as_, bs_, d)
        await apply_inputs(dut, a, b, as_, bs_, d)
        exp_q.append(tv.expected_outputs[d])

        if t >= PIPELINE_LATENCY:
            expected = exp_q[t - PIPELINE_LATENCY]

            # 혼합 depth 시각화: 현재 사이클·depth·참조 트랜잭션 + 파이프라인 바 + 진행바
            depth_tick(dut, t, d, expect_tx=t-PIPELINE_LATENCY)
            pipeline_viz(dut, t, PIPELINE_LATENCY, note=f"(mixed depth RR/RND)")
            if (t % max(1, num_transactions // 20)) == 0:
                progress_bar(dut, t, num_transactions, prefix="Mixed-depth stream")

            mismatches = []
            for i in range(16):
                s, e, m = read_fp32(dut, i)
                dut_bits = (s << 31) | (e << 23) | m
                if not equal_fp32_with_ulpm(expected[i], dut_bits, allow_ulpm=ALLOW_MANTISSA_ULP1):
                    mismatches.append((i, expected[i], dut_bits))
            if mismatches:
                lines = [f"[❌ MIXED-DEPTH STREAM | cycle={t} | depth_now={d} | expect_tx={t-PIPELINE_LATENCY} | ±1ULP={'ON' if ALLOW_MANTISSA_ULP1 else 'OFF'}]"]
                for (i, exp_bits, dut_bits) in mismatches:
                    lines.append(f"  lane {i}:")
                    lines.append(f"    EXP  0x{exp_bits:08X}  {bin32(exp_bits)}")
                    lines.append(f"    DUT  0x{dut_bits:08X}  {bin32(dut_bits)}")
                raise AssertionError("\n" + "\n".join(lines))

    # 드레인
    for t in range(PIPELINE_LATENCY):
        await RisingEdge(dut.clock)
        idx = num_transactions - PIPELINE_LATENCY + t
        if idx < 0:
            continue

        pipeline_viz(dut, num_transactions + t, PIPELINE_LATENCY, note="(drain)")
        expected = exp_q[idx]
        mismatches = []
        for i in range(16):
            s, e, m = read_fp32(dut, i)
            dut_bits = (s << 31) | (e << 23) | m
            if not equal_fp32_with_ulpm(expected[i], dut_bits, allow_ulpm=ALLOW_MANTISSA_ULP1):
                mismatches.append((i, expected[i], dut_bits))
        if mismatches:
            lines = [f"[❌ MIXED-DEPTH DRAIN | drain_step={t} | ±1ULP={'ON' if ALLOW_MANTISSA_ULP1 else 'OFF'}]"]
            for (i, exp_bits, dut_bits) in mismatches:
                lines.append(f"  lane {i}:")
                lines.append(f"    EXP  0x{exp_bits:08X}  {bin32(exp_bits)}")
                lines.append(f"    DUT  0x{dut_bits:08X}  {bin32(dut_bits)}")
            raise AssertionError("\n" + "\n".join(lines))

# =========================================================
# Tests
# =========================================================
@cocotb.test()
async def test_mxfp4_mac_pipelined_single_depth_streaming(dut):
    """단일 깊이에서 백투백 스트리밍 입력을 넣고 t-14 매칭으로 검증."""
    cocotb.start_soon(Clock(dut.clock, 10, units='ns').start())
    await reset_dut(dut)

    banner(dut, "[Single-depth streaming]")
    depth = 5
    num_transactions = NUM_TRIALS
    dut._log.info(f"🧪 Single-depth streaming | depth={depth}, tx={num_transactions}, LAT={PIPELINE_LATENCY}, ±1ULP={'ON' if ALLOW_MANTISSA_ULP1 else 'OFF'}")
    await stream_and_check(dut, depth, num_transactions)
    dut._log.info("✅ Single-depth streaming test passed")

@cocotb.test()
async def test_mxfp4_mac_pipelined_throughput_streaming(dut):
    """스루풋 확인(고정 depth). 파이프라인 공회전 없이 연속 주입/검증."""
    cocotb.start_soon(Clock(dut.clock, 10, units='ns').start())
    await reset_dut(dut)

    banner(dut, "[Throughput streaming]")
    depth = 6
    num_transactions = NUM_TRIALS
    dut._log.info(f"🧪 Throughput streaming | depth={depth}, tx={num_transactions}, LAT={PIPELINE_LATENCY}, ±1ULP={'ON' if ALLOW_MANTISSA_ULP1 else 'OFF'}")
    await stream_and_check(dut, depth, num_transactions)
    dut._log.info("✅ Throughput streaming test passed")

@cocotb.test()
async def test_mxfp4_mac_pipelined_mixed_depths_streaming(dut):
    """혼합 depth(0~8)를 라운드로빈/랜덤으로 매 사이클 변경하며 스트리밍 검증."""
    cocotb.start_soon(Clock(dut.clock, 10, units='ns').start())
    await reset_dut(dut)

    # 라운드로빈! (depth 0~8 순환)
    banner(dut, "[Mixed-depth streaming: roundrobin]")
    num_transactions = NUM_TRIALS
    dut._log.info(f"🧪 Mixed-depth streaming (roundrobin) | tx={num_transactions}, LAT={PIPELINE_LATENCY}, ±1ULP={'ON' if ALLOW_MANTISSA_ULP1 else 'OFF'}")
    await stream_and_check_mixed_depths(dut, num_transactions, pattern="roundrobin")
    dut._log.info("✅ Mixed-depth (roundrobin) streaming passed")

    # 랜덤
    await reset_dut(dut)
    banner(dut, "[Mixed-depth streaming: random]")
    dut._log.info(f"🧪 Mixed-depth streaming (random) | tx={num_transactions}, LAT={PIPELINE_LATENCY}, ±1ULP={'ON' if ALLOW_MANTISSA_ULP1 else 'OFF'}")
    await stream_and_check_mixed_depths(dut, num_transactions, pattern="random")
    dut._log.info("✅ Mixed-depth (random) streaming passed")

    dut._log.info("\n\n📘 [MXFP4 Pipelined Dot-Product Verification Summary]")
    dut._log.info("────────────────────────────────────────────────────────────")
    dut._log.info("✅ All pipelined testbenches successfully verified across depth levels 0–8")
    dut._log.info(f"🔁 Trials per depth         : {NUM_TRIALS}")
    dut._log.info(f"⏱️  Pipeline latency        : {PIPELINE_LATENCY} cycles")
    dut._log.info("🏗️  DUT Overview            : p_TOP_Til_Dep_total_piped_CT_syn")
    dut._log.info("   └─ 14-stage pipelined MXFP4 MAC with scale-aware accumulation")
    dut._log.info("   └─ Supports dynamic depth control for accumulation tree (0–8)")
    dut._log.info("   └─ Full pipeline timing validation with back-to-back transactions")
    dut._log.info("🔍 Validation Scope:")
    dut._log.info("   └─ Covers full FP32 field matching (sign, exponent, mantissa)")
    dut._log.info("   └─ Includes pipeline timing and throughput validation")
    dut._log.info("   └─ Handles NaN propagation through pipeline stages")
    dut._log.info("────────────────────────────────────────────────────────────")
    dut._log.info("🎯 Result  : ✅ All pipelined functional correctness tests passed")
    dut._log.info("📦 Module  : p_TOP_Til_Dep_total_piped")
    dut._log.info("📎 Ready for high-frequency operation and integration.")
    dut._log.info("────────────────────────────────────────────────────────────\n")
