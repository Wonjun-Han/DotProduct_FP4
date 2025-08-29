// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop.h"

// INCLUDE MODULE CLASSES
#include "Vtop___024root.h"
#include "Vtop_p_FieldExtractor.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop___024root                 TOP;
    Vtop_p_FieldExtractor          TOP__p_TOP_Til_Dep_total_piped_CT_syn_RCA__DOT__mult__DOT__a_extractor;
    Vtop_p_FieldExtractor          TOP__p_TOP_Til_Dep_total_piped_CT_syn_RCA__DOT__mult__DOT__b_extractor;

    // SCOPE NAMES
    VerilatedScope __Vscope_TOP;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder1_0;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder1_1;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder1_2;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder1_3;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder1_4;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder1_5;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder1_6;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder1_7;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder2_0;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder2_1;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder2_2;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder2_3;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder2_4;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder2_5;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder2_6;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder2_7;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder3_0;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder3_1;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder3_2;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder3_3;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder3_4;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder3_5;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder3_6;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder3_7;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder4_0;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder4_1;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder4_2;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder4_3;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder4_4;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder4_5;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder4_6;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder4_7;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder5_0;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder5_1;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder5_2;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder5_3;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder5_4;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder5_5;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder5_6;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder5_7;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder_groupwise_6;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder_groupwise_7;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__adder_groupwise_8;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__convert0;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__convert5;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__convert_groupwise_8;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__convert_twos;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__expansion_0;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__expansion_1;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__expansion_2;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__expansion_3;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__expansion_4;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__expansion_5;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__expansion_6;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__expansion_7;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__expansion_groupwise;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__mult;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__mult__a_extractor;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__mult__b_extractor;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__nan_process;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__outff;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__scaleEmax;
    VerilatedScope __Vscope_p_TOP_Til_Dep_total_piped_CT_syn_RCA__scaleSum;

    // SCOPE HIERARCHY
    VerilatedHierarchy __Vhier;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
