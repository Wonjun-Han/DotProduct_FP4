// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
// Verilator compiles this file in when DPI functions are used.
// If you have multiple Verilated designs with the same DPI exported
// function names, you will get multiple definition link errors from here.
// This is an unfortunate result of the DPI specification.
// To solve this, either
//    1. Call VsvsimTestbench::{export_function} instead,
//       and do not even bother to compile this file
// or 2. Compile all __Dpi.cpp files in the same compiler run,
//       and #ifdefs already inserted here will sort everything out.

#include "VsvsimTestbench__Dpi.h"
#include "VsvsimTestbench.h"

#ifndef VL_DPIDECL_getBitWidthImpl_clock_
#define VL_DPIDECL_getBitWidthImpl_clock_
void getBitWidthImpl_clock(int* value) {
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/AdderSpec/Adder-should-correctly-add-two-numbers/primary-sources/../generated-sources/testbench.sv:21:17
    return VsvsimTestbench::getBitWidthImpl_clock(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidthImpl_io_a_
#define VL_DPIDECL_getBitWidthImpl_io_a_
void getBitWidthImpl_io_a(int* value) {
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/AdderSpec/Adder-should-correctly-add-two-numbers/primary-sources/../generated-sources/testbench.sv:84:17
    return VsvsimTestbench::getBitWidthImpl_io_a(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidthImpl_io_b_
#define VL_DPIDECL_getBitWidthImpl_io_b_
void getBitWidthImpl_io_b(int* value) {
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/AdderSpec/Adder-should-correctly-add-two-numbers/primary-sources/../generated-sources/testbench.sv:67:17
    return VsvsimTestbench::getBitWidthImpl_io_b(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidthImpl_io_sum_
#define VL_DPIDECL_getBitWidthImpl_io_sum_
void getBitWidthImpl_io_sum(int* value) {
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/AdderSpec/Adder-should-correctly-add-two-numbers/primary-sources/../generated-sources/testbench.sv:55:17
    return VsvsimTestbench::getBitWidthImpl_io_sum(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidthImpl_reset_
#define VL_DPIDECL_getBitWidthImpl_reset_
void getBitWidthImpl_reset(int* value) {
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/AdderSpec/Adder-should-correctly-add-two-numbers/primary-sources/../generated-sources/testbench.sv:38:17
    return VsvsimTestbench::getBitWidthImpl_reset(value);
}
#endif

#ifndef VL_DPIDECL_getBitsImpl_clock_
#define VL_DPIDECL_getBitsImpl_clock_
void getBitsImpl_clock(svBitVecVal* value_clock) {
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/AdderSpec/Adder-should-correctly-add-two-numbers/primary-sources/../generated-sources/testbench.sv:31:17
    return VsvsimTestbench::getBitsImpl_clock(value_clock);
}
#endif

#ifndef VL_DPIDECL_getBitsImpl_io_a_
#define VL_DPIDECL_getBitsImpl_io_a_
void getBitsImpl_io_a(svBitVecVal* value_io_a) {
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/AdderSpec/Adder-should-correctly-add-two-numbers/primary-sources/../generated-sources/testbench.sv:94:17
    return VsvsimTestbench::getBitsImpl_io_a(value_io_a);
}
#endif

#ifndef VL_DPIDECL_getBitsImpl_io_b_
#define VL_DPIDECL_getBitsImpl_io_b_
void getBitsImpl_io_b(svBitVecVal* value_io_b) {
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/AdderSpec/Adder-should-correctly-add-two-numbers/primary-sources/../generated-sources/testbench.sv:77:17
    return VsvsimTestbench::getBitsImpl_io_b(value_io_b);
}
#endif

#ifndef VL_DPIDECL_getBitsImpl_io_sum_
#define VL_DPIDECL_getBitsImpl_io_sum_
void getBitsImpl_io_sum(svBitVecVal* value_io_sum) {
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/AdderSpec/Adder-should-correctly-add-two-numbers/primary-sources/../generated-sources/testbench.sv:60:17
    return VsvsimTestbench::getBitsImpl_io_sum(value_io_sum);
}
#endif

#ifndef VL_DPIDECL_getBitsImpl_reset_
#define VL_DPIDECL_getBitsImpl_reset_
void getBitsImpl_reset(svBitVecVal* value_reset) {
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/AdderSpec/Adder-should-correctly-add-two-numbers/primary-sources/../generated-sources/testbench.sv:48:17
    return VsvsimTestbench::getBitsImpl_reset(value_reset);
}
#endif

#ifndef VL_DPIDECL_setBitsImpl_clock_
#define VL_DPIDECL_setBitsImpl_clock_
void setBitsImpl_clock(const svBitVecVal* value_clock) {
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/AdderSpec/Adder-should-correctly-add-two-numbers/primary-sources/../generated-sources/testbench.sv:26:17
    return VsvsimTestbench::setBitsImpl_clock(value_clock);
}
#endif

#ifndef VL_DPIDECL_setBitsImpl_io_a_
#define VL_DPIDECL_setBitsImpl_io_a_
void setBitsImpl_io_a(const svBitVecVal* value_io_a) {
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/AdderSpec/Adder-should-correctly-add-two-numbers/primary-sources/../generated-sources/testbench.sv:89:17
    return VsvsimTestbench::setBitsImpl_io_a(value_io_a);
}
#endif

#ifndef VL_DPIDECL_setBitsImpl_io_b_
#define VL_DPIDECL_setBitsImpl_io_b_
void setBitsImpl_io_b(const svBitVecVal* value_io_b) {
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/AdderSpec/Adder-should-correctly-add-two-numbers/primary-sources/../generated-sources/testbench.sv:72:17
    return VsvsimTestbench::setBitsImpl_io_b(value_io_b);
}
#endif

#ifndef VL_DPIDECL_setBitsImpl_reset_
#define VL_DPIDECL_setBitsImpl_reset_
void setBitsImpl_reset(const svBitVecVal* value_reset) {
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/AdderSpec/Adder-should-correctly-add-two-numbers/primary-sources/../generated-sources/testbench.sv:43:17
    return VsvsimTestbench::setBitsImpl_reset(value_reset);
}
#endif

#ifndef VL_DPIDECL_simulation_disableTrace_
#define VL_DPIDECL_simulation_disableTrace_
void simulation_disableTrace(int* success) {
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/AdderSpec/Adder-should-correctly-add-two-numbers/primary-sources/../generated-sources/testbench.sv:161:17
    return VsvsimTestbench::simulation_disableTrace(success);
}
#endif

#ifndef VL_DPIDECL_simulation_enableTrace_
#define VL_DPIDECL_simulation_enableTrace_
void simulation_enableTrace(int* success) {
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/AdderSpec/Adder-should-correctly-add-two-numbers/primary-sources/../generated-sources/testbench.sv:148:17
    return VsvsimTestbench::simulation_enableTrace(success);
}
#endif

#ifndef VL_DPIDECL_simulation_initializeTrace_
#define VL_DPIDECL_simulation_initializeTrace_
void simulation_initializeTrace(const char* traceFilePath) {
    // DPI export at /Users/wonjun/chisel-template/build/chiselsim/AdderSpec/Adder-should-correctly-add-two-numbers/primary-sources/../generated-sources/testbench.sv:128:17
    return VsvsimTestbench::simulation_initializeTrace(traceFilePath);
}
#endif

