// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VsvsimTestbench.h for the primary calling header

#ifndef VERILATED_VSVSIMTESTBENCH___024ROOT_H_
#define VERILATED_VSVSIMTESTBENCH___024ROOT_H_  // guard

#include "verilated.h"


class VsvsimTestbench__Syms;

class alignas(VL_CACHE_LINE_BYTES) VsvsimTestbench___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ svsimTestbench__DOT__clock;
    CData/*0:0*/ svsimTestbench__DOT__reset;
    CData/*0:0*/ svsimTestbench__DOT__input_valid;
    CData/*0:0*/ svsimTestbench__DOT__output_ready;
    CData/*0:0*/ svsimTestbench__DOT__dut__DOT__busy;
    CData/*0:0*/ svsimTestbench__DOT__dut__DOT__resultValid;
    CData/*0:0*/ svsimTestbench__DOT__dut__DOT___GEN;
    CData/*0:0*/ svsimTestbench__DOT__dut__DOT__unnamedblk1__DOT___GEN_0;
    CData/*0:0*/ svsimTestbench__DOT__dut__DOT__unnamedblk1__DOT___GEN_1;
    CData/*0:0*/ __Vdpi_export_trigger;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__svsimTestbench__DOT__clock__0;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ svsimTestbench__DOT__input_bits_value2;
    SData/*15:0*/ svsimTestbench__DOT__input_bits_value1;
    SData/*15:0*/ svsimTestbench__DOT__dut__DOT__xInitial;
    SData/*15:0*/ svsimTestbench__DOT__dut__DOT__yInitial;
    SData/*15:0*/ svsimTestbench__DOT__dut__DOT__x;
    SData/*15:0*/ svsimTestbench__DOT__dut__DOT__y;
    IData/*31:0*/ svsimTestbench__DOT__simulationState;
    IData/*31:0*/ __Vtrigprevexpr___TOP__svsimTestbench__DOT__simulationState__0;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 3> svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    VsvsimTestbench__Syms* const vlSymsp;

    // CONSTRUCTORS
    VsvsimTestbench___024root(VsvsimTestbench__Syms* symsp, const char* v__name);
    ~VsvsimTestbench___024root();
    VL_UNCOPYABLE(VsvsimTestbench___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
