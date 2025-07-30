// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VsvsimTestbench__pch.h"
#include "VsvsimTestbench.h"
#include "VsvsimTestbench___024root.h"

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_clock_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_a_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_b_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_sum_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_reset_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &value);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_clock_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_clock);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_a_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, SData/*11:0*/ &value_io_a);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_b_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, SData/*11:0*/ &value_io_b);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_sum_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, SData/*11:0*/ &value_io_sum);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_reset_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ &value_reset);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_clock_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_clock);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_a_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, SData/*11:0*/ value_io_a);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_b_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, SData/*11:0*/ value_io_b);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_reset_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, CData/*0:0*/ value_reset);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_disableTrace_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &success);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_enableTrace_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, IData/*31:0*/ &success);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_initializeTrace_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, std::string traceFilePath);

// FUNCTIONS
VsvsimTestbench__Syms::~VsvsimTestbench__Syms()
{
}

VsvsimTestbench__Syms::VsvsimTestbench__Syms(VerilatedContext* contextp, const char* namep, VsvsimTestbench* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(185);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_svsimTestbench.configure(this, name(), "svsimTestbench", "svsimTestbench", "<null>", -12, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_svsimTestbench.exportInsert(__Vfinal, "getBitWidthImpl_clock", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_clock_TOP));
        __Vscope_svsimTestbench.exportInsert(__Vfinal, "getBitWidthImpl_io_a", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_a_TOP));
        __Vscope_svsimTestbench.exportInsert(__Vfinal, "getBitWidthImpl_io_b", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_b_TOP));
        __Vscope_svsimTestbench.exportInsert(__Vfinal, "getBitWidthImpl_io_sum", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_sum_TOP));
        __Vscope_svsimTestbench.exportInsert(__Vfinal, "getBitWidthImpl_reset", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_reset_TOP));
        __Vscope_svsimTestbench.exportInsert(__Vfinal, "getBitsImpl_clock", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_clock_TOP));
        __Vscope_svsimTestbench.exportInsert(__Vfinal, "getBitsImpl_io_a", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_a_TOP));
        __Vscope_svsimTestbench.exportInsert(__Vfinal, "getBitsImpl_io_b", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_b_TOP));
        __Vscope_svsimTestbench.exportInsert(__Vfinal, "getBitsImpl_io_sum", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_sum_TOP));
        __Vscope_svsimTestbench.exportInsert(__Vfinal, "getBitsImpl_reset", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_reset_TOP));
        __Vscope_svsimTestbench.exportInsert(__Vfinal, "setBitsImpl_clock", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_clock_TOP));
        __Vscope_svsimTestbench.exportInsert(__Vfinal, "setBitsImpl_io_a", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_a_TOP));
        __Vscope_svsimTestbench.exportInsert(__Vfinal, "setBitsImpl_io_b", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_io_b_TOP));
        __Vscope_svsimTestbench.exportInsert(__Vfinal, "setBitsImpl_reset", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_reset_TOP));
        __Vscope_svsimTestbench.exportInsert(__Vfinal, "simulation_disableTrace", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_disableTrace_TOP));
        __Vscope_svsimTestbench.exportInsert(__Vfinal, "simulation_enableTrace", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_enableTrace_TOP));
        __Vscope_svsimTestbench.exportInsert(__Vfinal, "simulation_initializeTrace", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_initializeTrace_TOP));
    }
}
