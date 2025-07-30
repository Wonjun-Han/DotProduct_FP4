// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VsvsimTestbench.h for the primary calling header

#include "VsvsimTestbench__pch.h"
#include "VsvsimTestbench___024root.h"

void VsvsimTestbench___024root___act_sequent__TOP__0(VsvsimTestbench___024root* vlSelf);

void VsvsimTestbench___024root___eval_act(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_act\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VsvsimTestbench___024root___act_sequent__TOP__0(vlSelf);
    }
}

void VsvsimTestbench___024root___nba_sequent__TOP__0(VsvsimTestbench___024root* vlSelf);

void VsvsimTestbench___024root___eval_nba(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_nba\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VsvsimTestbench___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VsvsimTestbench___024root___nba_sequent__TOP__0(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___nba_sequent__TOP__0\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __Vdly__svsimTestbench__DOT__dut__DOT__x;
    __Vdly__svsimTestbench__DOT__dut__DOT__x = 0;
    SData/*15:0*/ __Vdly__svsimTestbench__DOT__dut__DOT__y;
    __Vdly__svsimTestbench__DOT__dut__DOT__y = 0;
    CData/*0:0*/ __Vdly__svsimTestbench__DOT__dut__DOT__busy;
    __Vdly__svsimTestbench__DOT__dut__DOT__busy = 0;
    CData/*0:0*/ __Vdly__svsimTestbench__DOT__dut__DOT__resultValid;
    __Vdly__svsimTestbench__DOT__dut__DOT__resultValid = 0;
    // Body
    __Vdly__svsimTestbench__DOT__dut__DOT__y = vlSelfRef.svsimTestbench__DOT__dut__DOT__y;
    __Vdly__svsimTestbench__DOT__dut__DOT__busy = vlSelfRef.svsimTestbench__DOT__dut__DOT__busy;
    __Vdly__svsimTestbench__DOT__dut__DOT__resultValid 
        = vlSelfRef.svsimTestbench__DOT__dut__DOT__resultValid;
    __Vdly__svsimTestbench__DOT__dut__DOT__x = vlSelfRef.svsimTestbench__DOT__dut__DOT__x;
    if ((1U & (~ ((IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__busy) 
                  | (~ (IData)(vlSelfRef.svsimTestbench__DOT__input_valid)))))) {
        vlSelfRef.svsimTestbench__DOT__dut__DOT__xInitial 
            = vlSelfRef.svsimTestbench__DOT__input_bits_value1;
        vlSelfRef.svsimTestbench__DOT__dut__DOT__yInitial 
            = vlSelfRef.svsimTestbench__DOT__input_bits_value2;
    }
    if (vlSelfRef.svsimTestbench__DOT__dut__DOT__busy) {
        if (((IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__x) 
             > (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__y))) {
            __Vdly__svsimTestbench__DOT__dut__DOT__x 
                = (0xffffU & ((IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__x) 
                              - (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__y)));
        } else {
            __Vdly__svsimTestbench__DOT__dut__DOT__y 
                = (0xffffU & ((IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__y) 
                              - (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__x)));
        }
    } else if (vlSelfRef.svsimTestbench__DOT__input_valid) {
        __Vdly__svsimTestbench__DOT__dut__DOT__x = vlSelfRef.svsimTestbench__DOT__input_bits_value1;
        __Vdly__svsimTestbench__DOT__dut__DOT__y = vlSelfRef.svsimTestbench__DOT__input_bits_value2;
    }
    if (vlSelfRef.svsimTestbench__DOT__reset) {
        __Vdly__svsimTestbench__DOT__dut__DOT__busy = 0U;
        __Vdly__svsimTestbench__DOT__dut__DOT__resultValid = 0U;
    } else {
        vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk1__DOT___GEN_0 
            = ((IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN) 
               | (0U == (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__y)));
        vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk1__DOT___GEN_1 
            = ((IData)(vlSelfRef.svsimTestbench__DOT__output_ready) 
               & (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__resultValid));
        __Vdly__svsimTestbench__DOT__dut__DOT__busy 
            = ((IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__busy)
                ? ((~ ((IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk1__DOT___GEN_0) 
                       & (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk1__DOT___GEN_1))) 
                   & (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__busy))
                : ((IData)(vlSelfRef.svsimTestbench__DOT__input_valid) 
                   | (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__busy)));
        if (((IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__busy) 
             & (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk1__DOT___GEN_0))) {
            __Vdly__svsimTestbench__DOT__dut__DOT__resultValid 
                = (1U & (~ (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk1__DOT___GEN_1)));
        }
    }
    vlSelfRef.svsimTestbench__DOT__dut__DOT__y = __Vdly__svsimTestbench__DOT__dut__DOT__y;
    vlSelfRef.svsimTestbench__DOT__dut__DOT__busy = __Vdly__svsimTestbench__DOT__dut__DOT__busy;
    vlSelfRef.svsimTestbench__DOT__dut__DOT__resultValid 
        = __Vdly__svsimTestbench__DOT__dut__DOT__resultValid;
    vlSelfRef.svsimTestbench__DOT__dut__DOT__x = __Vdly__svsimTestbench__DOT__dut__DOT__x;
    vlSelfRef.svsimTestbench__DOT__dut__DOT___GEN = 
        (0U == (IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__x));
}

void VsvsimTestbench___024root___eval_triggers__act(VsvsimTestbench___024root* vlSelf);

bool VsvsimTestbench___024root___eval_phase__act(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_phase__act\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VsvsimTestbench___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VsvsimTestbench___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VsvsimTestbench___024root___eval_phase__nba(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_phase__nba\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VsvsimTestbench___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__nba(VsvsimTestbench___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__act(VsvsimTestbench___024root* vlSelf);
#endif  // VL_DEBUG

void VsvsimTestbench___024root___eval(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VsvsimTestbench___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VsvsimTestbench___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/Users/wonjun/chisel-template/build/chiselsim/GCDSpec/Gcd-should-calculate-proper-greatest-common-denominator/primary-sources/../generated-sources/testbench.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VsvsimTestbench___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VsvsimTestbench___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VsvsimTestbench___024root___eval_debug_assertions(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_debug_assertions\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
