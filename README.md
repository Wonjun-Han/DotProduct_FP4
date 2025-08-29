# MXFP4/NVFP4 Pipelined Dot-Product Architecture

A high-performance, pipelined hardware implementation of MXFP4/NVFP4-based Multiply-Accumulate (MAC) logic for AI accelerators, designed in Chisel and test with cocotb.

---

## MXFP4

<img width="1516" height="847" alt="스크린샷 2025-08-04 오후 4 19 38" src="https://github.com/user-attachments/assets/a2dba3c7-c750-4037-98be-a12f1fc80aff" />

<img width="2555" height="1417" alt="스크린샷 2025-08-13 오후 8 53 50" src="https://github.com/user-attachments/assets/e09cfe3c-71f9-4ffd-ac38-10e175a91ceb" />


---

## NVFP4

<img width="2556" height="1420" alt="스크린샷 2025-08-13 오후 8 53 34" src="https://github.com/user-attachments/assets/45569ecd-392e-4d57-b15e-38edb4632f6b" />

<img width="2555" height="1420" alt="스크린샷 2025-08-13 오후 8 54 02" src="https://github.com/user-attachments/assets/ab8b63cb-a489-478d-8e29-0b4b12b5cb26" />



---



## 📌 Overview

This project implements a **custom floating-point MAC unit** using the MXFP4 format from the OCP Microscaling (MX) specification. The system consists of the following key pipeline modules

- `FieldExtractor`: Parses 4-bit MXFP4 input into sign, exponent, mantissa
- `Multiplier`: Performs 256-element parallel MXFP4 × MXFP4 multiplication
- `Convert`: Converts the Intermediate Data into IEEE-754 FP32 format (Configurable with Depth of Computation)
- `Adder Tree[SINT Format]`: Performs pipelined FP32 pairwise addition with rounding and normalization

All modules are optimized to run at higher Frequency than **1GHz clock**, with careful pipeline stage balancing.

---

## 💡 MXFP4 Format

- **4-bit FP4 structure**: E2M1 (2-bit exponent, 1-bit mantissa, 1 sign)
- **Shared scale**: 8-bit E8M0 scaling factor is applied across groups of elements
- Supports both normal and subnormal representations

---

## 💡 NVFP4 Format

> Introduced by NVIDIA in 2024, NVFP4 is a 4-bit floating-point format optimized for high-accuracy, low-precision inference.

- **Structure**: `E2M1` (4-bit total)
  - 1-bit sign
  - 2-bit exponent
  - 1-bit mantissa
- **Shared Scale**:
  - **Per-block**: 16-element group shares an FP8 scale (E4M3)
  - **Per-tensor**: Global FP32 (E8M23) normalization applied
- **No subnormal support**: Only normalized values are represented
- **Usage**: Accelerated by NVIDIA's **Blackwell Tensor Cores**
- **Design goal**: Achieve FP8-level accuracy with only 4-bit storage

---

### ✅ NVFP4 vs MXFP4 (Nvidia Developer Blog를 참고.)

| Feature                   | **NVFP4**                                   | **MXFP4**                                |
|---------------------------|----------------------------------------------|-------------------------------------------|
| Format                    | E2M1                                         | E2M1                                      |
| Sign bit                  | 1                                            | 1                                         |
| Exponent bits             | 2                                            | 2                                         |
| Mantissa bits             | 1                                            | 1                                         |
| Subnormal support         | ✅ Yes                                       | ✅ Yes                                    |
| Block size (scale sharing)| 16                                           | 32                                        |
| Shared scale              | FP8 (E4M3)                                   | E8M0 (8-bit exponent, no mantissa)        |
| Per-tensor normalization  | ✅ FP32 (E8M23)                               | ❌ No                                      |
| Accuracy vs FP8           | ✅ Comparable                                | ⚠️ Slightly lower, especially for large models |
| Use cases                 | LLMs, Vision Transformers, Low-precision inference | MatMul, Dot-Product in compute-in-memory |
| Hardware support          | NVIDIA Blackwell Tensor Cores                | Custom / research                          |

---

### 🔍 Design Highlights

- 🧮 **Hierarchical scaling**: Combines FP8-level local scaling with global FP32 normalization
- 🔬 **Robust to outliers**: Smaller scale group (16 vs 32) reduces quantization errors from outliers
- ⚡ **Energy-efficient**: Up to **50× energy savings** over FP8 with minimal accuracy loss
- 🧠 **LLM-ready**: Proven to maintain accuracy in large language models like GPT, LLaMA, and Stable Diffusion

> 📄 Reference: [NVIDIA Developer Blog — Introducing NVFP4](https://developer.nvidia.com/blog/introducing-nvfp4-for-efficient-and-accurate-low-precision-inference/)

---


## 🧩 Module Pipeline Strategy

content = """# p_TOP_Til_Dep_total_piped 파이프라인 스테이지 정리

`p_TOP_Til_Dep_total_piped` 모듈의 파이프라인 구조를 **스테이지별(S1→S12)** 로 정리한 것이다.  
핵심은 **최종 출력(`io.out`)은 항상 S12에서 나오며**, 각 depth에서의 변환 결과는 해당 스테이지에서 산출된 뒤 **S12까지 레지스터로 밀어 단일 스위치에서 선택**된다는 점이다.

---

## S1 — Multiply & ScaleSum (→ Reg)
- 연산
  - `p_Multiplier`: 256쌍의 MXFP4 → `(sign, exponent, mantissa)` 벡터
  - `p_Adder_ScaleSum`: 그룹(8개)별 `a_scale + b_scale` 및 `nan` 플래그 계산
- 레지스터링(다음 스테이지에 전달)
  - `s1_sign`, `s1_exponent`, `s1_mantissa`, `s1_scale_sum`, `s1_scale_nan`
- depth 파이프
  - `depth_s1 = RegNext(io.depth)`

---

## S2 — In-group Expansion & (Emax + Scale) (→ Reg)
- 연산
  - 8개의 `p_Expansion` 인스턴스: 각 32요소 그룹 정렬/확장, 그룹별 `out_exponent_gmax(0)` 산출
  - `p_Adder_ScaleEmax`: `emax + scale_sum` → **exp_cand**(그룹별 변환 기준 지수), 그리고 `nan`
- 레지스터링
  - `s2_exp_cand := RegNext(scaleEmax.io.out)`  
  - `s2_nan_flag := RegNext(scaleEmax.io.nan)`
  - `adder1(i)` 입력은 `RegNext(expansion.io.out_*)`를 통해 S3에서 사용
- depth 파이프
  - `depth_s2 = RegNext(depth_s1)`

---

## S3 — (depth=0) Convert0 | else Adder1 (→ Reg)
- 변환 경로(depth=0용)
  - `p_MulConvert` 입력: S1 결과를 `delayToStage(1→3)`로 **두 사이클 지연**하여 정렬  
    (`toS3_sign/exp/man`, `toS3_scale_sum/nan`)
- 누산 경로
  - 8개의 `p_Adder_Dep_1` 결과를 `s3_adder1_out := RegNextVec(...)`
- depth 파이프
  - `depth_s3 = RegNext(depth_s2)`

---

## S4 — (depth=1) Convert1 | else Adder2 (→ Reg)
- 변환 경로(depth=1용)
  - `convert1.io.in`: `s3_adder1_out` (8×16=128요소) 평탄화 매핑
  - `exp_cand/nan`: `delayToStage(3→4)`로 1사이클 정렬
- 누산 경로
  - 8개의 `p_Adder_Dep_2` 입력에 `s3_adder1_out` 연결, 결과 `s4_adder2_out := RegNextVec(...)`
- depth 파이프
  - `depth_s4 = RegNext(depth_s3)`

---

## S5 — (depth=2) Convert2 | else Adder3 (→ Reg)
- 변환 경로(depth=2용)
  - `convert2.io.in`: `s4_adder2_out` (8×8=64요소)
  - `exp_cand/nan`: `delayToStage(3→5)`로 2사이클 정렬
- 누산 경로
  - 8개의 `p_Adder_Dep_3` → `s5_adder3_out := RegNextVec(...)`
- depth 파이프
  - `depth_s5 = RegNext(depth_s4)`

---

## S6 — (depth=3) Convert3 | else Adder4 (→ Reg)
- 변환 경로(depth=3용)
  - `convert3.io.in`: `s5_adder3_out` (8×4=32요소)
  - `exp_cand/nan`: `delayToStage(3→6)`
- 누산 경로
  - 8개의 `p_Adder_Dep_4` → `s6_adder4_out := RegNextVec(...)`
- depth 파이프
  - `depth_s6 = RegNext(depth_s5)`

---

## S7 — (depth=4) Convert4 | else Adder5 (→ Reg)
- 변환 경로(depth=4용)
  - `convert4.io.in`: `s6_adder4_out` (8×2=16요소)
  - `exp_cand/nan`: `delayToStage(3→7)`
- 누산 경로
  - 8개의 `p_Adder_Dep_5` → `s7_adder5_out := VecInit(RegNext(...))`
- depth 파이프
  - `depth_s7 = RegNext(depth_s6)`

---

## S8 — (depth=5) Convert5 | else Groupwise Expansion (→ Reg)
- 변환 경로(depth=5용)
  - `convert5.io.in`: `s7_adder5_out` (8요소)
  - `exp_cand/nan`: `delayToStage(3→8)`
- 그룹와이즈 경로(≥6을 위한 준비)
  - `p_Expansion_Groupwise(5,30)`에 `s7_adder5_out` + `toS8_exp_cand`(그룹 기준 지수) 입력  
  - 결과 레지스터:  
    - `s8_gw_sign := RegNext(out_sign)`  
    - `s8_gw_mantissa := RegNext(out_mantissa)`  
    - `s8_gw_emax := RegNext(out_exponent_gmax)`  
  - `p_NaN_Process(5)`에 `toS8_nan` 입력 → `s8_nan_proc := RegNext(result_nan)`
- depth 파이프
  - `depth_s8 = RegNext(depth_s7)`

---

## S9 — Adder_Groupwise_6 (→ Reg)
- 누산 경로
  - `p_Adder_Groupwise(6,30)`에 `s8_gw_*` 입력 →  
    `s9_ad6_sign := RegNext(out_sign)`, `s9_ad6_mantissa := RegNext(out_mantissa)`
- depth 파이프
  - `depth_s9 = RegNext(depth_s8)`

---

## S10 — (depth=6) Convert_GW_6 | else Adder_Groupwise_7 (→ Reg)
- 변환 경로(depth=6용)
  - `convert_groupwise_6`에 `s9_ad6_*` + `toS10_gw_emax := delayToStage(9→10, s8_gw_emax)` + `toS10_nan := delayToStage(9→10, s8_nan_proc)`
- 누산 경로
  - `p_Adder_Groupwise(7,30)` →  
    `s10_ad7_sign := RegNext(...)`, `s10_ad7_mantissa := RegNext(...)`
- depth 파이프
  - `depth_s10 = RegNext(depth_s9)`

---

## S11 — (depth=7) Convert_GW_7 | else Adder_Groupwise_8 (→ Reg)
- 변환 경로(depth=7용)
  - `convert_groupwise_7`에 `s10_ad7_*` + `toS11_gw_emax := delayToStage(9→11, s8_gw_emax)` + `toS11_nan := delayToStage(9→11, s8_nan_proc)`
- 누산 경로
  - `p_Adder_Groupwise(8,30)` →  
    `s11_ad8_sign := RegNext(...)`, `s11_ad8_mantissa := RegNext(...)`
- depth 파이프
  - `depth_s11 = RegNext(depth_s10)`

---

## S12 — (depth=8) Convert_GW_8 (최종 변환/선택)
- 변환 경로(depth=8용)
  - `convert_groupwise_8`에 `s11_ad8_*` + `toS12_gw_emax := delayToStage(9→12, s8_gw_emax)` + `toS12_nan := delayToStage(9→12, s8_nan_proc)`
- **단일 선택 지점**
  - 모든 depth별 변환 출력을 **S12로 정렬**:
    - `d0_atS12 = pipeVecN(convert0, 9)`  (S3→S12)
    - `d1_atS12 = pipeVecN(convert1, 8)`  (S4→S12)
    - `d2_atS12 = pipeVecN(convert2, 7)`  (S5→S12)
    - `d3_atS12 = pipeVecN(convert3, 6)`  (S6→S12)
    - `d4_atS12 = pipeVecN(convert4, 5)`  (S7→S12)
    - `d5_atS12 = pipeVecN(convert5, 4)`  (S8→S12)
    - `d6_atS12 = pipeVecN(conv_gw6, 2)`  (S10→S12)
    - `d7_atS12 = pipeVecN(conv_gw7, 1)`  (S11→S12)
    - `d8_atS12 = conv_gw8`               (S12)
  - 각 벡터는 `padTo16`으로 16포트에 zero-pad 후, `switch(depth_s12)`로 `io.out` 선택
- depth 파이프
  - `depth_s12 = RegNext(depth_s11)`

---

## 깊이별(Depth) “실제 변환 시점”과 정렬
- 변환이 처음 발생하는 스테이지
  - **D0**: S3, **D1**: S4, **D2**: S5, **D3**: S6, **D4**: S7, **D5**: S8, **D6**: S10, **D7**: S11, **D8**: S12
- 그러나 최종 출력은 항상 **S12**에서 선택 → 모든 변환 결과는 **pipeVecN**으로 S12까지 지연 정렬

---

## exp/nan 정렬 규칙(항상 변환 스테이지에 맞춰 정렬)
- `s2_exp_cand`, `s2_nan_flag`를 기준으로:
  - D0: S1→S3 정렬(`toS3_*`)
  - D1: S3→S4 정렬(`toS4_*`)
  - D2: S3→S5 정렬(`toS5_*`)
  - D3: S3→S6 정렬(`toS6_*`)
  - D4: S3→S7 정렬(`toS7_*`)
  - D5: S3→S8 정렬(`toS8_*`)
- 그룹와이즈(≥6):
  - S8에서 `s8_gw_emax`, `s8_nan_proc`를 만든 뒤,
  - D6:  S8→S10 (`toS10_*`)
  - D7:  S8→S11 (`toS11_*`)
  - D8:  S8→S12 (`toS12_*`)

---

## 요소 수 변화(개략)
- Mul/Exp 이후: 256  
- Adder1: 128 → Adder2: 64 → Adder3: 32 → Adder4: 16 → Adder5: 8  
- Groupwise Adder6: 4 → Adder7: 2 → Adder8: 1  
- Convert 시점의 출력은 항상 **16포트로 패딩**되어 `io.out(16)`에서 통일

---

## 디버그 포트
- `adder6_out_*`: S9 결과(레지스터 후 배선)  
- `adder7_out_*`: S10 결과  
- `adder8_out_*`: S11 결과  
→ Groupwise 단계의 내부 누산 값을 외부에서 관찰 가능

---

## 요약 메모
- **단일 latency 정책**: 어떤 depth든 **S12 고정 출력** → 타이밍 수월, 인터페이스 단순화  
- **정렬 핵심**: `delayToStage(from, to, vec)`/`pipeVecN`으로 **exp/nan/데이터**를 변환 스테이지와 최종 S12에 **정확히 정렬**  
- **≥6에서의 분기**: S8에서 그룹와이즈 도메인으로 전환(부호/가수/그룹 emax/NaN 재편성), 이후 D6~D8 변환기 사용
""" 


---

## 🛠️ How to Build

Run the following command to generate Verilog using `sbt`:

```bash
run build <ModuleName>
```
## 🧪 Test (with cocotb)
Each module is testable using Python-based cocotb. 

Example:
```bash
run cotb <ModuleName>
```

```bash
src/
 └── main/
      └── scala/
           └── mxfp4/
                ├── FieldExtractor.scala
                ├── piped/
                │    ├── p_Multiplier.scala
                │    ├── p_MulConvert.scala
                │    ├── p_Adder.scala
generated/
 └── verilog/
cocotb/
 └── tb_Multiplier.py
```
🧠 Author
Designed by Wonjun Han[AI Chip Arhictect] - Furiosa AI


