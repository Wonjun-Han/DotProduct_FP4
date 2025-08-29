// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop_p_FieldExtractor___ico_sequent__TOP__p_TOP_Til_Dep_total_piped_CT_syn_RCA__DOT__mult__DOT__a_extractor__0(Vtop_p_FieldExtractor* vlSelf);
void Vtop___024root___ico_sequent__TOP__2(Vtop___024root* vlSelf);
void Vtop___024root___ico_sequent__TOP__3(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        Vtop___024root___ico_sequent__TOP__1(vlSelf);
        Vtop_p_FieldExtractor___ico_sequent__TOP__p_TOP_Til_Dep_total_piped_CT_syn_RCA__DOT__mult__DOT__a_extractor__0((&vlSymsp->TOP__p_TOP_Til_Dep_total_piped_CT_syn_RCA__DOT__mult__DOT__a_extractor));
        Vtop_p_FieldExtractor___ico_sequent__TOP__p_TOP_Til_Dep_total_piped_CT_syn_RCA__DOT__mult__DOT__a_extractor__0((&vlSymsp->TOP__p_TOP_Til_Dep_total_piped_CT_syn_RCA__DOT__mult__DOT__b_extractor));
        Vtop___024root___ico_sequent__TOP__2(vlSelf);
        Vtop___024root___ico_sequent__TOP__3(vlSelf);
    }
}
