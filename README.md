# MXFP4 Pipelined Dot-Product Architecture

A high-performance, pipelined hardware implementation of MXFP4-based Multiply-Accumulate (MAC) logic for AI accelerators, designed in Chisel.

---

## 📌 Overview

This project implements a **custom floating-point MAC unit** using the MXFP4 format from the OCP Microscaling (MX) specification. The system consists of the following key pipeline modules

- `FieldExtractor`: Parses 4-bit MXFP4 input into sign, exponent, mantissa
- `Multiplier`: Performs 256-element parallel MXFP4 × MXFP4 multiplication
- `MulConvert`: Converts partial products into IEEE-754 FP32 format
- `Adder`: Performs pipelined FP32 pairwise addition with rounding and normalization

All modules are optimized to run at **1GHz clock frequency**, with careful pipeline stage balancing.

---

## 💡 MXFP4 Format

- **4-bit FP4 structure**: E2M1 (2-bit exponent, 1-bit mantissa, 1 sign)
- **Shared scale**: 8-bit E8M0 scaling factor is applied across groups of elements
- Supports both normal and subnormal representations

---

## 🧩 Module Pipeline Strategy

| Module         | Pipeline Stages | Description                                    |
|----------------|------------------|------------------------------------------------|
| FieldExtractor | 0                | No pipelining required                         |
| Multiplier     | TBD              | Mantissa mult & zero check split               |
| MulConvert     | TBD              | PE calc → Shift → Exp adjust                   |
| Adder          | TBD              | Align → Add/Sub → Normalize → Round            |

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
Designed by Wonjun Han
Chip Architect Candidate - Furiosa AI


