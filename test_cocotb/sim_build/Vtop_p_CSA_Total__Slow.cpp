// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_p_CSA_Total.h"

void Vtop_p_CSA_Total___ctor_var_reset(Vtop_p_CSA_Total* vlSelf);

Vtop_p_CSA_Total::Vtop_p_CSA_Total(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_p_CSA_Total___ctor_var_reset(this);
}

void Vtop_p_CSA_Total::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_p_CSA_Total::~Vtop_p_CSA_Total() {
}
