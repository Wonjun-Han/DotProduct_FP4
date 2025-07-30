// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VsvsimTestbench__pch.h"

//============================================================
// Constructors

VsvsimTestbench::VsvsimTestbench(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VsvsimTestbench__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VsvsimTestbench::VsvsimTestbench(const char* _vcname__)
    : VsvsimTestbench(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VsvsimTestbench::~VsvsimTestbench() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VsvsimTestbench___024root___eval_debug_assertions(VsvsimTestbench___024root* vlSelf);
#endif  // VL_DEBUG
void VsvsimTestbench___024root___eval_static(VsvsimTestbench___024root* vlSelf);
void VsvsimTestbench___024root___eval_initial(VsvsimTestbench___024root* vlSelf);
void VsvsimTestbench___024root___eval_settle(VsvsimTestbench___024root* vlSelf);
void VsvsimTestbench___024root___eval(VsvsimTestbench___024root* vlSelf);

void VsvsimTestbench::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VsvsimTestbench::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VsvsimTestbench___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VsvsimTestbench___024root___eval_static(&(vlSymsp->TOP));
        VsvsimTestbench___024root___eval_initial(&(vlSymsp->TOP));
        VsvsimTestbench___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VsvsimTestbench___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VsvsimTestbench::eventsPending() { return false; }

uint64_t VsvsimTestbench::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VsvsimTestbench::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VsvsimTestbench___024root___eval_final(VsvsimTestbench___024root* vlSelf);

VL_ATTR_COLD void VsvsimTestbench::final() {
    VsvsimTestbench___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VsvsimTestbench::hierName() const { return vlSymsp->name(); }
const char* VsvsimTestbench::modelName() const { return "VsvsimTestbench"; }
unsigned VsvsimTestbench::threads() const { return 1; }
void VsvsimTestbench::prepareClone() const { contextp()->prepareClone(); }
void VsvsimTestbench::atClone() const {
    contextp()->threadPoolpOnClone();
}
