// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VsvsimTestbench.h for the primary calling header

#include "VsvsimTestbench__pch.h"
#include "VsvsimTestbench__Syms.h"
#include "VsvsimTestbench___024root.h"

void VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__initTestBenchScope_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno);

VL_ATTR_COLD void VsvsimTestbench___024root___eval_initial__TOP(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_initial__TOP\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ svsimTestbench__DOT__dut__DOT____Vlvbound_h8fde9af5__0;
    svsimTestbench__DOT__dut__DOT____Vlvbound_h8fde9af5__0 = 0;
    // Body
    VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__initTestBenchScope_TOP(
                                                                                (&(vlSymsp->__Vscope_svsimTestbench)), 
                                                                                "/Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv", 0x1eU);
    vlSelfRef.svsimTestbench__DOT__simulationState = 1U;
    svsimTestbench__DOT__dut__DOT____Vlvbound_h8fde9af5__0 
        = VL_RANDOM_I();
    vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM[0U] 
        = svsimTestbench__DOT__dut__DOT____Vlvbound_h8fde9af5__0;
    svsimTestbench__DOT__dut__DOT____Vlvbound_h8fde9af5__0 
        = VL_RANDOM_I();
    vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM[1U] 
        = svsimTestbench__DOT__dut__DOT____Vlvbound_h8fde9af5__0;
    svsimTestbench__DOT__dut__DOT____Vlvbound_h8fde9af5__0 
        = VL_RANDOM_I();
    vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM[2U] 
        = svsimTestbench__DOT__dut__DOT____Vlvbound_h8fde9af5__0;
    vlSelfRef.svsimTestbench__DOT__dut__DOT__xInitial 
        = (0xffffU & vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM
           [0U]);
    vlSelfRef.svsimTestbench__DOT__dut__DOT__yInitial 
        = (vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM
           [0U] >> 0x10U);
    vlSelfRef.svsimTestbench__DOT__dut__DOT__x = (0xffffU 
                                                  & vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM
                                                  [1U]);
    vlSelfRef.svsimTestbench__DOT__dut__DOT__y = (vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM
                                                  [1U] 
                                                  >> 0x10U);
    vlSelfRef.svsimTestbench__DOT__dut__DOT__busy = 
        (1U & vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM
         [2U]);
    vlSelfRef.svsimTestbench__DOT__dut__DOT__resultValid 
        = (1U & (vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM
                 [2U] >> 1U));
}

void VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_final_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno);

VL_ATTR_COLD void VsvsimTestbench___024root___eval_final__TOP(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_final__TOP\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_final_TOP(
                                                                                (&(vlSymsp->__Vscope_svsimTestbench)), 
                                                                                "/Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv", 0xceU);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__stl(VsvsimTestbench___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VsvsimTestbench___024root___eval_triggers__stl(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_triggers__stl\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VsvsimTestbench___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
