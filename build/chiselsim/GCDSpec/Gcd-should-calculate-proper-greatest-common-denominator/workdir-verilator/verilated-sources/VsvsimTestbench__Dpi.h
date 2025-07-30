// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VSVSIMTESTBENCH__DPI_H_
#define VERILATED_VSVSIMTESTBENCH__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI EXPORTS
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:33:17
    extern void getBitWidthImpl_clock(int* value);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:84:17
    extern void getBitWidthImpl_input_bits_value1(int* value);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:67:17
    extern void getBitWidthImpl_input_bits_value2(int* value);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:118:17
    extern void getBitWidthImpl_input_ready(int* value);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:101:17
    extern void getBitWidthImpl_input_valid(int* value);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:130:17
    extern void getBitWidthImpl_output_bits_gcd(int* value);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:154:17
    extern void getBitWidthImpl_output_bits_value1(int* value);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:142:17
    extern void getBitWidthImpl_output_bits_value2(int* value);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:178:17
    extern void getBitWidthImpl_output_ready(int* value);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:166:17
    extern void getBitWidthImpl_output_valid(int* value);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:50:17
    extern void getBitWidthImpl_reset(int* value);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:43:17
    extern void getBitsImpl_clock(svBitVecVal* value_clock);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:94:17
    extern void getBitsImpl_input_bits_value1(svBitVecVal* value_input_bits_value1);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:77:17
    extern void getBitsImpl_input_bits_value2(svBitVecVal* value_input_bits_value2);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:123:17
    extern void getBitsImpl_input_ready(svBitVecVal* value_input_ready);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:111:17
    extern void getBitsImpl_input_valid(svBitVecVal* value_input_valid);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:135:17
    extern void getBitsImpl_output_bits_gcd(svBitVecVal* value_output_bits_gcd);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:159:17
    extern void getBitsImpl_output_bits_value1(svBitVecVal* value_output_bits_value1);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:147:17
    extern void getBitsImpl_output_bits_value2(svBitVecVal* value_output_bits_value2);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:188:17
    extern void getBitsImpl_output_ready(svBitVecVal* value_output_ready);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:171:17
    extern void getBitsImpl_output_valid(svBitVecVal* value_output_valid);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:60:17
    extern void getBitsImpl_reset(svBitVecVal* value_reset);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:38:17
    extern void setBitsImpl_clock(const svBitVecVal* value_clock);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:89:17
    extern void setBitsImpl_input_bits_value1(const svBitVecVal* value_input_bits_value1);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:72:17
    extern void setBitsImpl_input_bits_value2(const svBitVecVal* value_input_bits_value2);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:106:17
    extern void setBitsImpl_input_valid(const svBitVecVal* value_input_valid);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:183:17
    extern void setBitsImpl_output_ready(const svBitVecVal* value_output_ready);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:55:17
    extern void setBitsImpl_reset(const svBitVecVal* value_reset);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:255:17
    extern void simulation_disableTrace(int* success);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:242:17
    extern void simulation_enableTrace(int* success);
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:222:17
    extern void simulation_initializeTrace(const char* traceFilePath);

    // DPI IMPORTS
    // DPI import at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:28:40
    extern void initTestBenchScope();
    // DPI import at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:216:32
    extern void run_simulation(int timesteps, int* done);
    // DPI import at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:194:31
    extern int simulation_body();
    // DPI import at /Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv:204:31
    extern int simulation_final();

#ifdef __cplusplus
}
#endif

#endif  // guard
