# MXFP4/NVFP4 Pipelined Dot-Product Architecture

A high-performance, pipelined hardware implementation of MXFP4/NVFP4-based Multiply-Accumulate (MAC) logic for AI accelerators, designed in Chisel and test with cocotb.

<img width="2558" height="1416" alt="스크린샷 2025-08-06 오후 12 57 34" src="https://github.com/user-attachments/assets/f579ae4d-7c7e-4a58-af1c-206fe221338e" />

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

| Module         | Pipeline Stages | Description                                    |
|----------------|------------------|------------------------------------------------|
| FieldExtractor | 0                | No pipelining required                         |
| Multiplier     | TBD              | Mantissa mult & zero check split               |
| Convert        | TBD              | PE calc → Shift → Exp adjust                   |
| Adder Tree     | TBD              | Align → Add/Sub → Normalize → Round            |

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


