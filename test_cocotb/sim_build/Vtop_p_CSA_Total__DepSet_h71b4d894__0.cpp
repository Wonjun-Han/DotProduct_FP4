// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_p_CSA_Total.h"

VL_INLINE_OPT void Vtop_p_CSA_Total___ico_sequent__TOP__p_TOP_Til_Dep_total_piped_CT_syn_CSA_LUT__DOT__csa_groupin_0__0(Vtop_p_CSA_Total* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_p_CSA_Total___ico_sequent__TOP__p_TOP_Til_Dep_total_piped_CT_syn_CSA_LUT__DOT__csa_groupin_0__0\n"); );
    // Body
    vlSelf->stage__DOT__io_in_31 = vlSelf->io_in_31;
    vlSelf->_stage_io_out_11 = ((0x200U & ((IData)(vlSelf->io_in_31) 
                                           << 1U)) 
                                | (IData)(vlSelf->io_in_31));
    vlSelf->stage__DOT__io_in_30 = vlSelf->io_in_30;
    vlSelf->_stage_io_out_10 = ((0x200U & ((IData)(vlSelf->io_in_30) 
                                           << 1U)) 
                                | (IData)(vlSelf->io_in_30));
    vlSelf->stage__DOT__io_in_26 = vlSelf->io_in_26;
    vlSelf->stage__DOT__io_in_25 = vlSelf->io_in_25;
    vlSelf->stage__DOT__io_in_24 = vlSelf->io_in_24;
    vlSelf->stage__DOT__units_8__DOT__io_carry = (((IData)(vlSelf->io_in_24) 
                                                   & (IData)(vlSelf->io_in_25)) 
                                                  | (((IData)(vlSelf->io_in_25) 
                                                      | (IData)(vlSelf->io_in_24)) 
                                                     & (IData)(vlSelf->io_in_26)));
    vlSelf->stage__DOT__units_8__DOT__io_sum = ((IData)(vlSelf->io_in_24) 
                                                ^ ((IData)(vlSelf->io_in_25) 
                                                   ^ (IData)(vlSelf->io_in_26)));
    vlSelf->stage__DOT__io_in_23 = vlSelf->io_in_23;
    vlSelf->stage__DOT__io_in_22 = vlSelf->io_in_22;
    vlSelf->stage__DOT__io_in_21 = vlSelf->io_in_21;
    vlSelf->stage__DOT__units_7__DOT__io_carry = (((IData)(vlSelf->io_in_21) 
                                                   & (IData)(vlSelf->io_in_22)) 
                                                  | (((IData)(vlSelf->io_in_22) 
                                                      | (IData)(vlSelf->io_in_21)) 
                                                     & (IData)(vlSelf->io_in_23)));
    vlSelf->stage__DOT__units_7__DOT__io_sum = ((IData)(vlSelf->io_in_21) 
                                                ^ ((IData)(vlSelf->io_in_22) 
                                                   ^ (IData)(vlSelf->io_in_23)));
    vlSelf->stage__DOT__io_in_20 = vlSelf->io_in_20;
    vlSelf->stage__DOT__io_in_19 = vlSelf->io_in_19;
    vlSelf->stage__DOT__io_in_18 = vlSelf->io_in_18;
    vlSelf->stage__DOT__units_6__DOT__io_carry = (((IData)(vlSelf->io_in_18) 
                                                   & (IData)(vlSelf->io_in_19)) 
                                                  | (((IData)(vlSelf->io_in_19) 
                                                      | (IData)(vlSelf->io_in_18)) 
                                                     & (IData)(vlSelf->io_in_20)));
    vlSelf->stage__DOT__units_6__DOT__io_sum = ((IData)(vlSelf->io_in_18) 
                                                ^ ((IData)(vlSelf->io_in_19) 
                                                   ^ (IData)(vlSelf->io_in_20)));
    vlSelf->stage__DOT__io_in_17 = vlSelf->io_in_17;
    vlSelf->stage__DOT__io_in_16 = vlSelf->io_in_16;
    vlSelf->stage__DOT__io_in_15 = vlSelf->io_in_15;
    vlSelf->stage__DOT__units_5__DOT__io_carry = (((IData)(vlSelf->io_in_15) 
                                                   & (IData)(vlSelf->io_in_16)) 
                                                  | (((IData)(vlSelf->io_in_16) 
                                                      | (IData)(vlSelf->io_in_15)) 
                                                     & (IData)(vlSelf->io_in_17)));
    vlSelf->stage__DOT__units_5__DOT__io_sum = ((IData)(vlSelf->io_in_15) 
                                                ^ ((IData)(vlSelf->io_in_16) 
                                                   ^ (IData)(vlSelf->io_in_17)));
    vlSelf->stage__DOT__io_in_14 = vlSelf->io_in_14;
    vlSelf->stage__DOT__io_in_13 = vlSelf->io_in_13;
    vlSelf->stage__DOT__io_in_12 = vlSelf->io_in_12;
    vlSelf->stage__DOT__units_4__DOT__io_carry = (((IData)(vlSelf->io_in_12) 
                                                   & (IData)(vlSelf->io_in_13)) 
                                                  | (((IData)(vlSelf->io_in_13) 
                                                      | (IData)(vlSelf->io_in_12)) 
                                                     & (IData)(vlSelf->io_in_14)));
    vlSelf->stage__DOT__units_4__DOT__io_sum = ((IData)(vlSelf->io_in_12) 
                                                ^ ((IData)(vlSelf->io_in_13) 
                                                   ^ (IData)(vlSelf->io_in_14)));
    vlSelf->stage__DOT__io_in_11 = vlSelf->io_in_11;
    vlSelf->stage__DOT__io_in_10 = vlSelf->io_in_10;
    vlSelf->stage__DOT__io_in_9 = vlSelf->io_in_9;
    vlSelf->stage__DOT__units_3__DOT__io_carry = (((IData)(vlSelf->io_in_10) 
                                                   & (IData)(vlSelf->io_in_9)) 
                                                  | (((IData)(vlSelf->io_in_10) 
                                                      & (IData)(vlSelf->io_in_11)) 
                                                     | ((IData)(vlSelf->io_in_11) 
                                                        & (IData)(vlSelf->io_in_9))));
    vlSelf->stage__DOT__units_3__DOT__io_sum = ((IData)(vlSelf->io_in_9) 
                                                ^ ((IData)(vlSelf->io_in_10) 
                                                   ^ (IData)(vlSelf->io_in_11)));
    vlSelf->stage__DOT__io_in_8 = vlSelf->io_in_8;
    vlSelf->stage__DOT__io_in_7 = vlSelf->io_in_7;
    vlSelf->stage__DOT__io_in_6 = vlSelf->io_in_6;
    vlSelf->stage__DOT__units_2__DOT__io_carry = (((IData)(vlSelf->io_in_6) 
                                                   & (IData)(vlSelf->io_in_7)) 
                                                  | (((IData)(vlSelf->io_in_7) 
                                                      | (IData)(vlSelf->io_in_6)) 
                                                     & (IData)(vlSelf->io_in_8)));
    vlSelf->stage__DOT__units_2__DOT__io_sum = ((IData)(vlSelf->io_in_6) 
                                                ^ ((IData)(vlSelf->io_in_7) 
                                                   ^ (IData)(vlSelf->io_in_8)));
    vlSelf->stage__DOT__io_in_5 = vlSelf->io_in_5;
    vlSelf->stage__DOT__io_in_4 = vlSelf->io_in_4;
    vlSelf->stage__DOT__io_in_3 = vlSelf->io_in_3;
    vlSelf->stage__DOT__units_1__DOT__io_carry = (((IData)(vlSelf->io_in_3) 
                                                   & (IData)(vlSelf->io_in_4)) 
                                                  | (((IData)(vlSelf->io_in_4) 
                                                      | (IData)(vlSelf->io_in_3)) 
                                                     & (IData)(vlSelf->io_in_5)));
    vlSelf->stage__DOT__units_1__DOT__io_sum = ((IData)(vlSelf->io_in_3) 
                                                ^ ((IData)(vlSelf->io_in_4) 
                                                   ^ (IData)(vlSelf->io_in_5)));
    vlSelf->stage__DOT__io_in_2 = vlSelf->io_in_2;
    vlSelf->stage__DOT__io_in_1 = vlSelf->io_in_1;
    vlSelf->stage__DOT__io_in_0 = vlSelf->io_in_0;
    vlSelf->stage__DOT__units_0__DOT__io_carry = (((IData)(vlSelf->io_in_0) 
                                                   & (IData)(vlSelf->io_in_1)) 
                                                  | (((IData)(vlSelf->io_in_1) 
                                                      | (IData)(vlSelf->io_in_0)) 
                                                     & (IData)(vlSelf->io_in_2)));
    vlSelf->stage__DOT__units_0__DOT__io_sum = ((IData)(vlSelf->io_in_0) 
                                                ^ ((IData)(vlSelf->io_in_1) 
                                                   ^ (IData)(vlSelf->io_in_2)));
    vlSelf->stage__DOT__io_in_29 = vlSelf->io_in_29;
    vlSelf->stage__DOT__io_in_28 = vlSelf->io_in_28;
    vlSelf->stage__DOT__io_in_27 = vlSelf->io_in_27;
    vlSelf->stage__DOT__units_9__DOT__io_carry = (((IData)(vlSelf->io_in_27) 
                                                   & (IData)(vlSelf->io_in_28)) 
                                                  | (((IData)(vlSelf->io_in_28) 
                                                      | (IData)(vlSelf->io_in_27)) 
                                                     & (IData)(vlSelf->io_in_29)));
    vlSelf->stage__DOT__units_9__DOT__io_sum = ((IData)(vlSelf->io_in_27) 
                                                ^ ((IData)(vlSelf->io_in_28) 
                                                   ^ (IData)(vlSelf->io_in_29)));
    vlSelf->stage__DOT__io_out_11 = vlSelf->_stage_io_out_11;
    vlSelf->stage_1__DOT__io_in_11 = vlSelf->_stage_io_out_11;
    vlSelf->stage__DOT__io_out_10 = vlSelf->_stage_io_out_10;
    vlSelf->stage_1__DOT__io_in_10 = vlSelf->_stage_io_out_10;
    vlSelf->stage__DOT__units_8__DOT__io_in_2 = vlSelf->stage__DOT__io_in_26;
    vlSelf->stage__DOT__units_8__DOT__io_in_1 = vlSelf->stage__DOT__io_in_25;
    vlSelf->stage__DOT__units_8__DOT__io_in_0 = vlSelf->stage__DOT__io_in_24;
    vlSelf->stage__DOT___units_8_io_carry = vlSelf->stage__DOT__units_8__DOT__io_carry;
    vlSelf->_stage_io_out_20 = ((IData)(vlSelf->stage__DOT__units_8__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_8_io_sum = vlSelf->stage__DOT__units_8__DOT__io_sum;
    vlSelf->_stage_io_out_8 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_8__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_8__DOT__io_sum));
    vlSelf->stage__DOT__units_7__DOT__io_in_2 = vlSelf->stage__DOT__io_in_23;
    vlSelf->stage__DOT__units_7__DOT__io_in_1 = vlSelf->stage__DOT__io_in_22;
    vlSelf->stage__DOT__units_7__DOT__io_in_0 = vlSelf->stage__DOT__io_in_21;
    vlSelf->stage__DOT___units_7_io_carry = vlSelf->stage__DOT__units_7__DOT__io_carry;
    vlSelf->_stage_io_out_19 = ((IData)(vlSelf->stage__DOT__units_7__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_7_io_sum = vlSelf->stage__DOT__units_7__DOT__io_sum;
    vlSelf->_stage_io_out_7 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_7__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_7__DOT__io_sum));
    vlSelf->stage__DOT__units_6__DOT__io_in_2 = vlSelf->stage__DOT__io_in_20;
    vlSelf->stage__DOT__units_6__DOT__io_in_1 = vlSelf->stage__DOT__io_in_19;
    vlSelf->stage__DOT__units_6__DOT__io_in_0 = vlSelf->stage__DOT__io_in_18;
    vlSelf->stage__DOT___units_6_io_carry = vlSelf->stage__DOT__units_6__DOT__io_carry;
    vlSelf->_stage_io_out_18 = ((IData)(vlSelf->stage__DOT__units_6__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_6_io_sum = vlSelf->stage__DOT__units_6__DOT__io_sum;
    vlSelf->_stage_io_out_6 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_6__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_6__DOT__io_sum));
    vlSelf->stage__DOT__units_5__DOT__io_in_2 = vlSelf->stage__DOT__io_in_17;
    vlSelf->stage__DOT__units_5__DOT__io_in_1 = vlSelf->stage__DOT__io_in_16;
    vlSelf->stage__DOT__units_5__DOT__io_in_0 = vlSelf->stage__DOT__io_in_15;
    vlSelf->stage__DOT___units_5_io_carry = vlSelf->stage__DOT__units_5__DOT__io_carry;
    vlSelf->_stage_io_out_17 = ((IData)(vlSelf->stage__DOT__units_5__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_5_io_sum = vlSelf->stage__DOT__units_5__DOT__io_sum;
    vlSelf->_stage_io_out_5 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_5__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_5__DOT__io_sum));
    vlSelf->stage__DOT__units_4__DOT__io_in_2 = vlSelf->stage__DOT__io_in_14;
    vlSelf->stage__DOT__units_4__DOT__io_in_1 = vlSelf->stage__DOT__io_in_13;
    vlSelf->stage__DOT__units_4__DOT__io_in_0 = vlSelf->stage__DOT__io_in_12;
    vlSelf->stage__DOT___units_4_io_carry = vlSelf->stage__DOT__units_4__DOT__io_carry;
    vlSelf->_stage_io_out_16 = ((IData)(vlSelf->stage__DOT__units_4__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_4_io_sum = vlSelf->stage__DOT__units_4__DOT__io_sum;
    vlSelf->_stage_io_out_4 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_4__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_4__DOT__io_sum));
    vlSelf->stage__DOT__units_3__DOT__io_in_2 = vlSelf->stage__DOT__io_in_11;
    vlSelf->stage__DOT__units_3__DOT__io_in_1 = vlSelf->stage__DOT__io_in_10;
    vlSelf->stage__DOT__units_3__DOT__io_in_0 = vlSelf->stage__DOT__io_in_9;
    vlSelf->stage__DOT___units_3_io_carry = vlSelf->stage__DOT__units_3__DOT__io_carry;
    vlSelf->_stage_io_out_15 = ((IData)(vlSelf->stage__DOT__units_3__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_3_io_sum = vlSelf->stage__DOT__units_3__DOT__io_sum;
    vlSelf->_stage_io_out_3 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_3__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_3__DOT__io_sum));
    vlSelf->stage__DOT__units_2__DOT__io_in_2 = vlSelf->stage__DOT__io_in_8;
    vlSelf->stage__DOT__units_2__DOT__io_in_1 = vlSelf->stage__DOT__io_in_7;
    vlSelf->stage__DOT__units_2__DOT__io_in_0 = vlSelf->stage__DOT__io_in_6;
    vlSelf->stage__DOT___units_2_io_carry = vlSelf->stage__DOT__units_2__DOT__io_carry;
    vlSelf->_stage_io_out_14 = ((IData)(vlSelf->stage__DOT__units_2__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_2_io_sum = vlSelf->stage__DOT__units_2__DOT__io_sum;
    vlSelf->_stage_io_out_2 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_2__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_2__DOT__io_sum));
    vlSelf->stage__DOT__units_1__DOT__io_in_2 = vlSelf->stage__DOT__io_in_5;
    vlSelf->stage__DOT__units_1__DOT__io_in_1 = vlSelf->stage__DOT__io_in_4;
    vlSelf->stage__DOT__units_1__DOT__io_in_0 = vlSelf->stage__DOT__io_in_3;
    vlSelf->stage__DOT___units_1_io_carry = vlSelf->stage__DOT__units_1__DOT__io_carry;
    vlSelf->_stage_io_out_13 = ((IData)(vlSelf->stage__DOT__units_1__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_1_io_sum = vlSelf->stage__DOT__units_1__DOT__io_sum;
    vlSelf->_stage_io_out_1 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_1__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_1__DOT__io_sum));
    vlSelf->stage__DOT__units_0__DOT__io_in_2 = vlSelf->stage__DOT__io_in_2;
    vlSelf->stage__DOT__units_0__DOT__io_in_1 = vlSelf->stage__DOT__io_in_1;
    vlSelf->stage__DOT__units_0__DOT__io_in_0 = vlSelf->stage__DOT__io_in_0;
    vlSelf->stage__DOT___units_0_io_carry = vlSelf->stage__DOT__units_0__DOT__io_carry;
    vlSelf->_stage_io_out_12 = ((IData)(vlSelf->stage__DOT__units_0__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_0_io_sum = vlSelf->stage__DOT__units_0__DOT__io_sum;
    vlSelf->_stage_io_out_0 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_0__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_0__DOT__io_sum));
    vlSelf->stage__DOT__units_9__DOT__io_in_2 = vlSelf->stage__DOT__io_in_29;
    vlSelf->stage__DOT__units_9__DOT__io_in_1 = vlSelf->stage__DOT__io_in_28;
    vlSelf->stage__DOT__units_9__DOT__io_in_0 = vlSelf->stage__DOT__io_in_27;
    vlSelf->stage__DOT___units_9_io_carry = vlSelf->stage__DOT__units_9__DOT__io_carry;
    vlSelf->_stage_io_out_21 = ((IData)(vlSelf->stage__DOT__units_9__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_9_io_sum = vlSelf->stage__DOT__units_9__DOT__io_sum;
    vlSelf->_stage_io_out_9 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_9__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_9__DOT__io_sum));
    vlSelf->stage_1__DOT__units_3__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_11;
    vlSelf->stage_1__DOT__units_3__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_10;
    vlSelf->stage__DOT__io_out_20 = vlSelf->_stage_io_out_20;
    vlSelf->stage_1__DOT__io_in_20 = vlSelf->_stage_io_out_20;
    vlSelf->stage__DOT__io_out_8 = vlSelf->_stage_io_out_8;
    vlSelf->stage_1__DOT__io_in_8 = vlSelf->_stage_io_out_8;
    vlSelf->stage__DOT__io_out_19 = vlSelf->_stage_io_out_19;
    vlSelf->stage_1__DOT__io_in_19 = vlSelf->_stage_io_out_19;
    vlSelf->stage__DOT__io_out_7 = vlSelf->_stage_io_out_7;
    vlSelf->stage_1__DOT__io_in_7 = vlSelf->_stage_io_out_7;
    vlSelf->stage__DOT__io_out_18 = vlSelf->_stage_io_out_18;
    vlSelf->stage_1__DOT__io_in_18 = vlSelf->_stage_io_out_18;
    vlSelf->stage_1__DOT__units_6__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_18) & (IData)(vlSelf->_stage_io_out_19)) 
         | (((IData)(vlSelf->_stage_io_out_19) | (IData)(vlSelf->_stage_io_out_18)) 
            & (IData)(vlSelf->_stage_io_out_20)));
    vlSelf->stage_1__DOT__units_6__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_18) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_19) 
                                                   ^ (IData)(vlSelf->_stage_io_out_20)));
    vlSelf->stage__DOT__io_out_6 = vlSelf->_stage_io_out_6;
    vlSelf->stage_1__DOT__io_in_6 = vlSelf->_stage_io_out_6;
    vlSelf->stage_1__DOT__units_2__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_6) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_7) 
                                                   ^ (IData)(vlSelf->_stage_io_out_8)));
    vlSelf->stage_1__DOT__units_2__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_6) & (IData)(vlSelf->_stage_io_out_7)) 
         | (((IData)(vlSelf->_stage_io_out_7) | (IData)(vlSelf->_stage_io_out_6)) 
            & (IData)(vlSelf->_stage_io_out_8)));
    vlSelf->stage__DOT__io_out_17 = vlSelf->_stage_io_out_17;
    vlSelf->stage_1__DOT__io_in_17 = vlSelf->_stage_io_out_17;
    vlSelf->stage__DOT__io_out_5 = vlSelf->_stage_io_out_5;
    vlSelf->stage_1__DOT__io_in_5 = vlSelf->_stage_io_out_5;
    vlSelf->stage__DOT__io_out_16 = vlSelf->_stage_io_out_16;
    vlSelf->stage_1__DOT__io_in_16 = vlSelf->_stage_io_out_16;
    vlSelf->stage__DOT__io_out_4 = vlSelf->_stage_io_out_4;
    vlSelf->stage_1__DOT__io_in_4 = vlSelf->_stage_io_out_4;
    vlSelf->stage__DOT__io_out_15 = vlSelf->_stage_io_out_15;
    vlSelf->stage_1__DOT__io_in_15 = vlSelf->_stage_io_out_15;
    vlSelf->stage_1__DOT__units_5__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_15) & (IData)(vlSelf->_stage_io_out_16)) 
         | (((IData)(vlSelf->_stage_io_out_16) | (IData)(vlSelf->_stage_io_out_15)) 
            & (IData)(vlSelf->_stage_io_out_17)));
    vlSelf->stage_1__DOT__units_5__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_15) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_16) 
                                                   ^ (IData)(vlSelf->_stage_io_out_17)));
    vlSelf->stage__DOT__io_out_3 = vlSelf->_stage_io_out_3;
    vlSelf->stage_1__DOT__io_in_3 = vlSelf->_stage_io_out_3;
    vlSelf->stage_1__DOT__units_1__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_3) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_4) 
                                                   ^ (IData)(vlSelf->_stage_io_out_5)));
    vlSelf->stage_1__DOT__units_1__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_3) & (IData)(vlSelf->_stage_io_out_4)) 
         | (((IData)(vlSelf->_stage_io_out_4) | (IData)(vlSelf->_stage_io_out_3)) 
            & (IData)(vlSelf->_stage_io_out_5)));
    vlSelf->stage__DOT__io_out_14 = vlSelf->_stage_io_out_14;
    vlSelf->stage_1__DOT__io_in_14 = vlSelf->_stage_io_out_14;
    vlSelf->stage__DOT__io_out_2 = vlSelf->_stage_io_out_2;
    vlSelf->stage_1__DOT__io_in_2 = vlSelf->_stage_io_out_2;
    vlSelf->stage__DOT__io_out_13 = vlSelf->_stage_io_out_13;
    vlSelf->stage_1__DOT__io_in_13 = vlSelf->_stage_io_out_13;
    vlSelf->stage__DOT__io_out_1 = vlSelf->_stage_io_out_1;
    vlSelf->stage_1__DOT__io_in_1 = vlSelf->_stage_io_out_1;
    vlSelf->stage__DOT__io_out_12 = vlSelf->_stage_io_out_12;
    vlSelf->stage_1__DOT__io_in_12 = vlSelf->_stage_io_out_12;
    vlSelf->stage_1__DOT__units_4__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_12) & (IData)(vlSelf->_stage_io_out_13)) 
         | (((IData)(vlSelf->_stage_io_out_13) | (IData)(vlSelf->_stage_io_out_12)) 
            & (IData)(vlSelf->_stage_io_out_14)));
    vlSelf->stage_1__DOT__units_4__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_12) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_13) 
                                                   ^ (IData)(vlSelf->_stage_io_out_14)));
    vlSelf->stage__DOT__io_out_0 = vlSelf->_stage_io_out_0;
    vlSelf->stage_1__DOT__io_in_0 = vlSelf->_stage_io_out_0;
    vlSelf->stage_1__DOT__units_0__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_0) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_1) 
                                                   ^ (IData)(vlSelf->_stage_io_out_2)));
    vlSelf->stage_1__DOT__units_0__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_0) & (IData)(vlSelf->_stage_io_out_1)) 
         | (((IData)(vlSelf->_stage_io_out_1) | (IData)(vlSelf->_stage_io_out_0)) 
            & (IData)(vlSelf->_stage_io_out_2)));
    vlSelf->stage_1__DOT__io_in_21 = vlSelf->_stage_io_out_21;
    vlSelf->stage__DOT__io_out_21 = vlSelf->_stage_io_out_21;
    vlSelf->_stage_1_io_out_7 = ((0x400U & ((IData)(vlSelf->stage__DOT__units_9__DOT__io_carry) 
                                            << 2U)) 
                                 | (IData)(vlSelf->_stage_io_out_21));
    vlSelf->stage__DOT__io_out_9 = vlSelf->_stage_io_out_9;
    vlSelf->stage_1__DOT__io_in_9 = vlSelf->_stage_io_out_9;
    vlSelf->stage_1__DOT__units_3__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_9) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_10) 
                                                   ^ (IData)(vlSelf->_stage_io_out_11)));
    vlSelf->stage_1__DOT__units_3__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_9) & (IData)(vlSelf->_stage_io_out_10)) 
         | (((IData)(vlSelf->_stage_io_out_10) | (IData)(vlSelf->_stage_io_out_9)) 
            & (IData)(vlSelf->_stage_io_out_11)));
    vlSelf->stage_1__DOT__units_6__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_20;
    vlSelf->stage_1__DOT__units_2__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_8;
    vlSelf->stage_1__DOT__units_6__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_19;
    vlSelf->stage_1__DOT__units_2__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_7;
    vlSelf->stage_1__DOT__units_6__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_18;
    vlSelf->stage_1__DOT___units_6_io_carry = vlSelf->stage_1__DOT__units_6__DOT__io_carry;
    vlSelf->_stage_1_io_out_14 = ((IData)(vlSelf->stage_1__DOT__units_6__DOT__io_carry) 
                                  << 1U);
    vlSelf->stage_1__DOT___units_6_io_sum = vlSelf->stage_1__DOT__units_6__DOT__io_sum;
    vlSelf->_stage_1_io_out_6 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_6__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_6__DOT__io_sum));
    vlSelf->stage_1__DOT__units_2__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_6;
    vlSelf->stage_1__DOT___units_2_io_sum = vlSelf->stage_1__DOT__units_2__DOT__io_sum;
    vlSelf->_stage_1_io_out_2 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_2__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_2__DOT__io_sum));
    vlSelf->stage_1__DOT___units_2_io_carry = vlSelf->stage_1__DOT__units_2__DOT__io_carry;
    vlSelf->_stage_1_io_out_10 = ((IData)(vlSelf->stage_1__DOT__units_2__DOT__io_carry) 
                                  << 1U);
    vlSelf->stage_1__DOT__units_5__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_17;
    vlSelf->stage_1__DOT__units_1__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_5;
    vlSelf->stage_1__DOT__units_5__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_16;
    vlSelf->stage_1__DOT__units_1__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_4;
    vlSelf->stage_1__DOT__units_5__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_15;
    vlSelf->stage_1__DOT___units_5_io_carry = vlSelf->stage_1__DOT__units_5__DOT__io_carry;
    vlSelf->_stage_1_io_out_13 = ((IData)(vlSelf->stage_1__DOT__units_5__DOT__io_carry) 
                                  << 1U);
    vlSelf->stage_1__DOT___units_5_io_sum = vlSelf->stage_1__DOT__units_5__DOT__io_sum;
    vlSelf->_stage_1_io_out_5 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_5__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_5__DOT__io_sum));
    vlSelf->stage_1__DOT__units_1__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_3;
    vlSelf->stage_1__DOT___units_1_io_sum = vlSelf->stage_1__DOT__units_1__DOT__io_sum;
    vlSelf->_stage_1_io_out_1 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_1__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_1__DOT__io_sum));
    vlSelf->stage_1__DOT___units_1_io_carry = vlSelf->stage_1__DOT__units_1__DOT__io_carry;
    vlSelf->_stage_1_io_out_9 = ((IData)(vlSelf->stage_1__DOT__units_1__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_1__DOT__units_4__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_14;
    vlSelf->stage_1__DOT__units_0__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_2;
    vlSelf->stage_1__DOT__units_4__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_13;
    vlSelf->stage_1__DOT__units_0__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_1;
    vlSelf->stage_1__DOT__units_4__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_12;
    vlSelf->stage_1__DOT___units_4_io_carry = vlSelf->stage_1__DOT__units_4__DOT__io_carry;
    vlSelf->_stage_1_io_out_12 = ((IData)(vlSelf->stage_1__DOT__units_4__DOT__io_carry) 
                                  << 1U);
    vlSelf->stage_1__DOT___units_4_io_sum = vlSelf->stage_1__DOT__units_4__DOT__io_sum;
    vlSelf->_stage_1_io_out_4 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_4__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_4__DOT__io_sum));
    vlSelf->stage_1__DOT__units_0__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_0;
    vlSelf->stage_1__DOT___units_0_io_sum = vlSelf->stage_1__DOT__units_0__DOT__io_sum;
    vlSelf->_stage_1_io_out_0 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_0__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_0__DOT__io_sum));
    vlSelf->stage_1__DOT___units_0_io_carry = vlSelf->stage_1__DOT__units_0__DOT__io_carry;
    vlSelf->_stage_1_io_out_8 = ((IData)(vlSelf->stage_1__DOT__units_0__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_1__DOT__io_out_7 = vlSelf->_stage_1_io_out_7;
    vlSelf->stage_2__DOT__io_in_7 = vlSelf->_stage_1_io_out_7;
    vlSelf->stage_1__DOT__units_3__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_9;
    vlSelf->stage_1__DOT___units_3_io_sum = vlSelf->stage_1__DOT__units_3__DOT__io_sum;
    vlSelf->_stage_1_io_out_3 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_3__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_3__DOT__io_sum));
    vlSelf->stage_1__DOT___units_3_io_carry = vlSelf->stage_1__DOT__units_3__DOT__io_carry;
    vlSelf->_stage_1_io_out_11 = ((IData)(vlSelf->stage_1__DOT__units_3__DOT__io_carry) 
                                  << 1U);
    vlSelf->stage_1__DOT__io_out_14 = vlSelf->_stage_1_io_out_14;
    vlSelf->stage_2__DOT__io_in_14 = vlSelf->_stage_1_io_out_14;
    vlSelf->stage_1__DOT__io_out_6 = vlSelf->_stage_1_io_out_6;
    vlSelf->stage_2__DOT__io_in_6 = vlSelf->_stage_1_io_out_6;
    vlSelf->stage_1__DOT__io_out_2 = vlSelf->_stage_1_io_out_2;
    vlSelf->stage_2__DOT__io_in_2 = vlSelf->_stage_1_io_out_2;
    vlSelf->stage_1__DOT__io_out_10 = vlSelf->_stage_1_io_out_10;
    vlSelf->stage_2__DOT__io_in_10 = vlSelf->_stage_1_io_out_10;
    vlSelf->stage_1__DOT__io_out_13 = vlSelf->_stage_1_io_out_13;
    vlSelf->stage_2__DOT__io_in_13 = vlSelf->_stage_1_io_out_13;
    vlSelf->stage_1__DOT__io_out_5 = vlSelf->_stage_1_io_out_5;
    vlSelf->stage_2__DOT__io_in_5 = vlSelf->_stage_1_io_out_5;
    vlSelf->stage_1__DOT__io_out_1 = vlSelf->_stage_1_io_out_1;
    vlSelf->stage_2__DOT__io_in_1 = vlSelf->_stage_1_io_out_1;
    vlSelf->stage_1__DOT__io_out_9 = vlSelf->_stage_1_io_out_9;
    vlSelf->stage_2__DOT__io_in_9 = vlSelf->_stage_1_io_out_9;
    vlSelf->stage_1__DOT__io_out_12 = vlSelf->_stage_1_io_out_12;
    vlSelf->stage_2__DOT__io_in_12 = vlSelf->_stage_1_io_out_12;
    vlSelf->stage_2__DOT__units_4__DOT__io_carry = 
        (((IData)(vlSelf->_stage_1_io_out_12) & (IData)(vlSelf->_stage_1_io_out_13)) 
         | (((IData)(vlSelf->_stage_1_io_out_13) | (IData)(vlSelf->_stage_1_io_out_12)) 
            & (IData)(vlSelf->_stage_1_io_out_14)));
    vlSelf->stage_2__DOT__units_4__DOT__io_sum = ((IData)(vlSelf->_stage_1_io_out_12) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_1_io_out_13) 
                                                   ^ (IData)(vlSelf->_stage_1_io_out_14)));
    vlSelf->stage_1__DOT__io_out_4 = vlSelf->_stage_1_io_out_4;
    vlSelf->stage_2__DOT__io_in_4 = vlSelf->_stage_1_io_out_4;
    vlSelf->stage_1__DOT__io_out_0 = vlSelf->_stage_1_io_out_0;
    vlSelf->stage_2__DOT__io_in_0 = vlSelf->_stage_1_io_out_0;
    vlSelf->stage_2__DOT__units_0__DOT__io_sum = ((IData)(vlSelf->_stage_1_io_out_0) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_1_io_out_1) 
                                                   ^ (IData)(vlSelf->_stage_1_io_out_2)));
    vlSelf->stage_2__DOT__units_0__DOT__io_carry = 
        (((IData)(vlSelf->_stage_1_io_out_0) & (IData)(vlSelf->_stage_1_io_out_1)) 
         | (((IData)(vlSelf->_stage_1_io_out_1) | (IData)(vlSelf->_stage_1_io_out_0)) 
            & (IData)(vlSelf->_stage_1_io_out_2)));
    vlSelf->stage_1__DOT__io_out_8 = vlSelf->_stage_1_io_out_8;
    vlSelf->stage_2__DOT__io_in_8 = vlSelf->_stage_1_io_out_8;
    vlSelf->stage_2__DOT__units_2__DOT__io_sum = ((IData)(vlSelf->_stage_1_io_out_6) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_1_io_out_7) 
                                                   ^ (IData)(vlSelf->_stage_1_io_out_8)));
    vlSelf->stage_2__DOT__units_2__DOT__io_carry = 
        (((IData)(vlSelf->_stage_1_io_out_6) & (IData)(vlSelf->_stage_1_io_out_7)) 
         | (((IData)(vlSelf->_stage_1_io_out_7) | (IData)(vlSelf->_stage_1_io_out_6)) 
            & (IData)(vlSelf->_stage_1_io_out_8)));
    vlSelf->stage_2__DOT__units_2__DOT__io_in_1 = vlSelf->stage_2__DOT__io_in_7;
    vlSelf->stage_1__DOT__io_out_3 = vlSelf->_stage_1_io_out_3;
    vlSelf->stage_2__DOT__io_in_3 = vlSelf->_stage_1_io_out_3;
    vlSelf->stage_2__DOT__units_1__DOT__io_sum = ((IData)(vlSelf->_stage_1_io_out_3) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_1_io_out_4) 
                                                   ^ (IData)(vlSelf->_stage_1_io_out_5)));
    vlSelf->stage_2__DOT__units_1__DOT__io_carry = 
        (((IData)(vlSelf->_stage_1_io_out_3) & (IData)(vlSelf->_stage_1_io_out_4)) 
         | (((IData)(vlSelf->_stage_1_io_out_4) | (IData)(vlSelf->_stage_1_io_out_3)) 
            & (IData)(vlSelf->_stage_1_io_out_5)));
    vlSelf->stage_1__DOT__io_out_11 = vlSelf->_stage_1_io_out_11;
    vlSelf->stage_2__DOT__io_in_11 = vlSelf->_stage_1_io_out_11;
    vlSelf->stage_2__DOT__units_3__DOT__io_sum = ((IData)(vlSelf->_stage_1_io_out_9) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_1_io_out_10) 
                                                   ^ (IData)(vlSelf->_stage_1_io_out_11)));
    vlSelf->stage_2__DOT__units_3__DOT__io_carry = 
        (((IData)(vlSelf->_stage_1_io_out_9) & (IData)(vlSelf->_stage_1_io_out_10)) 
         | (((IData)(vlSelf->_stage_1_io_out_10) | (IData)(vlSelf->_stage_1_io_out_9)) 
            & (IData)(vlSelf->_stage_1_io_out_11)));
    vlSelf->stage_2__DOT__units_4__DOT__io_in_2 = vlSelf->stage_2__DOT__io_in_14;
    vlSelf->stage_2__DOT__units_2__DOT__io_in_0 = vlSelf->stage_2__DOT__io_in_6;
    vlSelf->stage_2__DOT__units_0__DOT__io_in_2 = vlSelf->stage_2__DOT__io_in_2;
    vlSelf->stage_2__DOT__units_3__DOT__io_in_1 = vlSelf->stage_2__DOT__io_in_10;
    vlSelf->stage_2__DOT__units_4__DOT__io_in_1 = vlSelf->stage_2__DOT__io_in_13;
    vlSelf->stage_2__DOT__units_1__DOT__io_in_2 = vlSelf->stage_2__DOT__io_in_5;
    vlSelf->stage_2__DOT__units_0__DOT__io_in_1 = vlSelf->stage_2__DOT__io_in_1;
    vlSelf->stage_2__DOT__units_3__DOT__io_in_0 = vlSelf->stage_2__DOT__io_in_9;
    vlSelf->stage_2__DOT__units_4__DOT__io_in_0 = vlSelf->stage_2__DOT__io_in_12;
    vlSelf->stage_2__DOT___units_4_io_carry = vlSelf->stage_2__DOT__units_4__DOT__io_carry;
    vlSelf->_stage_2_io_out_9 = ((IData)(vlSelf->stage_2__DOT__units_4__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_2__DOT___units_4_io_sum = vlSelf->stage_2__DOT__units_4__DOT__io_sum;
    vlSelf->_stage_2_io_out_4 = ((0x800U & ((IData)(vlSelf->stage_2__DOT__units_4__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_2__DOT__units_4__DOT__io_sum));
    vlSelf->stage_2__DOT__units_1__DOT__io_in_1 = vlSelf->stage_2__DOT__io_in_4;
    vlSelf->stage_2__DOT__units_0__DOT__io_in_0 = vlSelf->stage_2__DOT__io_in_0;
    vlSelf->stage_2__DOT___units_0_io_sum = vlSelf->stage_2__DOT__units_0__DOT__io_sum;
    vlSelf->_stage_2_io_out_0 = ((0x800U & ((IData)(vlSelf->stage_2__DOT__units_0__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_2__DOT__units_0__DOT__io_sum));
    vlSelf->stage_2__DOT___units_0_io_carry = vlSelf->stage_2__DOT__units_0__DOT__io_carry;
    vlSelf->_stage_2_io_out_5 = ((IData)(vlSelf->stage_2__DOT__units_0__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_2__DOT__units_2__DOT__io_in_2 = vlSelf->stage_2__DOT__io_in_8;
    vlSelf->stage_2__DOT___units_2_io_sum = vlSelf->stage_2__DOT__units_2__DOT__io_sum;
    vlSelf->_stage_2_io_out_2 = ((0x800U & ((IData)(vlSelf->stage_2__DOT__units_2__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_2__DOT__units_2__DOT__io_sum));
    vlSelf->stage_2__DOT___units_2_io_carry = vlSelf->stage_2__DOT__units_2__DOT__io_carry;
    vlSelf->_stage_2_io_out_7 = ((IData)(vlSelf->stage_2__DOT__units_2__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_2__DOT__units_1__DOT__io_in_0 = vlSelf->stage_2__DOT__io_in_3;
    vlSelf->stage_2__DOT___units_1_io_sum = vlSelf->stage_2__DOT__units_1__DOT__io_sum;
    vlSelf->_stage_2_io_out_1 = ((0x800U & ((IData)(vlSelf->stage_2__DOT__units_1__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_2__DOT__units_1__DOT__io_sum));
    vlSelf->stage_2__DOT___units_1_io_carry = vlSelf->stage_2__DOT__units_1__DOT__io_carry;
    vlSelf->_stage_2_io_out_6 = ((IData)(vlSelf->stage_2__DOT__units_1__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_2__DOT__units_3__DOT__io_in_2 = vlSelf->stage_2__DOT__io_in_11;
    vlSelf->stage_2__DOT___units_3_io_sum = vlSelf->stage_2__DOT__units_3__DOT__io_sum;
    vlSelf->_stage_2_io_out_3 = ((0x800U & ((IData)(vlSelf->stage_2__DOT__units_3__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_2__DOT__units_3__DOT__io_sum));
    vlSelf->stage_2__DOT___units_3_io_carry = vlSelf->stage_2__DOT__units_3__DOT__io_carry;
    vlSelf->_stage_2_io_out_8 = ((IData)(vlSelf->stage_2__DOT__units_3__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_3__DOT__io_in_9 = vlSelf->_stage_2_io_out_9;
    vlSelf->stage_2__DOT__io_out_9 = vlSelf->_stage_2_io_out_9;
    vlSelf->_stage_3_io_out_3 = ((0x1000U & ((IData)(vlSelf->stage_2__DOT__units_4__DOT__io_carry) 
                                             << 2U)) 
                                 | (IData)(vlSelf->_stage_2_io_out_9));
    vlSelf->stage_2__DOT__io_out_4 = vlSelf->_stage_2_io_out_4;
    vlSelf->stage_3__DOT__io_in_4 = vlSelf->_stage_2_io_out_4;
    vlSelf->stage_2__DOT__io_out_0 = vlSelf->_stage_2_io_out_0;
    vlSelf->stage_3__DOT__io_in_0 = vlSelf->_stage_2_io_out_0;
    vlSelf->stage_2__DOT__io_out_5 = vlSelf->_stage_2_io_out_5;
    vlSelf->stage_3__DOT__io_in_5 = vlSelf->_stage_2_io_out_5;
    vlSelf->stage_2__DOT__io_out_2 = vlSelf->_stage_2_io_out_2;
    vlSelf->stage_3__DOT__io_in_2 = vlSelf->_stage_2_io_out_2;
    vlSelf->stage_2__DOT__io_out_7 = vlSelf->_stage_2_io_out_7;
    vlSelf->stage_3__DOT__io_in_7 = vlSelf->_stage_2_io_out_7;
    vlSelf->stage_2__DOT__io_out_1 = vlSelf->_stage_2_io_out_1;
    vlSelf->stage_3__DOT__io_in_1 = vlSelf->_stage_2_io_out_1;
    vlSelf->stage_3__DOT___units_0_io_sum = ((IData)(vlSelf->_stage_2_io_out_0) 
                                             ^ ((IData)(vlSelf->_stage_2_io_out_1) 
                                                ^ (IData)(vlSelf->_stage_2_io_out_2)));
    vlSelf->stage_3__DOT___units_0_io_carry = (((IData)(vlSelf->_stage_2_io_out_0) 
                                                & (IData)(vlSelf->_stage_2_io_out_1)) 
                                               | (((IData)(vlSelf->_stage_2_io_out_1) 
                                                   | (IData)(vlSelf->_stage_2_io_out_0)) 
                                                  & (IData)(vlSelf->_stage_2_io_out_2)));
    vlSelf->stage_2__DOT__io_out_6 = vlSelf->_stage_2_io_out_6;
    vlSelf->stage_3__DOT__io_in_6 = vlSelf->_stage_2_io_out_6;
    vlSelf->stage_2__DOT__io_out_3 = vlSelf->_stage_2_io_out_3;
    vlSelf->stage_3__DOT__io_in_3 = vlSelf->_stage_2_io_out_3;
    vlSelf->stage_3__DOT___units_1_io_sum = ((IData)(vlSelf->_stage_2_io_out_3) 
                                             ^ ((IData)(vlSelf->_stage_2_io_out_4) 
                                                ^ (IData)(vlSelf->_stage_2_io_out_5)));
    vlSelf->stage_3__DOT___units_1_io_carry = (((IData)(vlSelf->_stage_2_io_out_3) 
                                                & (IData)(vlSelf->_stage_2_io_out_4)) 
                                               | (((IData)(vlSelf->_stage_2_io_out_4) 
                                                   | (IData)(vlSelf->_stage_2_io_out_3)) 
                                                  & (IData)(vlSelf->_stage_2_io_out_5)));
    vlSelf->stage_2__DOT__io_out_8 = vlSelf->_stage_2_io_out_8;
    vlSelf->stage_3__DOT__io_in_8 = vlSelf->_stage_2_io_out_8;
    vlSelf->stage_3__DOT___units_2_io_sum = ((IData)(vlSelf->_stage_2_io_out_6) 
                                             ^ ((IData)(vlSelf->_stage_2_io_out_7) 
                                                ^ (IData)(vlSelf->_stage_2_io_out_8)));
    vlSelf->stage_3__DOT___units_2_io_carry = (((IData)(vlSelf->_stage_2_io_out_6) 
                                                & (IData)(vlSelf->_stage_2_io_out_7)) 
                                               | (((IData)(vlSelf->_stage_2_io_out_7) 
                                                   | (IData)(vlSelf->_stage_2_io_out_6)) 
                                                  & (IData)(vlSelf->_stage_2_io_out_8)));
    vlSelf->stage_3__DOT__io_out_3 = vlSelf->_stage_3_io_out_3;
    vlSelf->stage_4__DOT__io_in_3 = vlSelf->_stage_3_io_out_3;
    vlSelf->stage_3__DOT__units_1__DOT__io_in_1 = vlSelf->stage_3__DOT__io_in_4;
    vlSelf->stage_3__DOT__units_0__DOT__io_in_0 = vlSelf->stage_3__DOT__io_in_0;
    vlSelf->stage_3__DOT__units_1__DOT__io_in_2 = vlSelf->stage_3__DOT__io_in_5;
    vlSelf->stage_3__DOT__units_0__DOT__io_in_2 = vlSelf->stage_3__DOT__io_in_2;
    vlSelf->stage_3__DOT__units_2__DOT__io_in_1 = vlSelf->stage_3__DOT__io_in_7;
    vlSelf->stage_3__DOT__units_0__DOT__io_in_1 = vlSelf->stage_3__DOT__io_in_1;
    vlSelf->stage_3__DOT__units_0__DOT__io_sum = vlSelf->stage_3__DOT___units_0_io_sum;
    vlSelf->_stage_3_io_out_0 = ((0x1000U & ((IData)(vlSelf->stage_3__DOT___units_0_io_sum) 
                                             << 1U)) 
                                 | (IData)(vlSelf->stage_3__DOT___units_0_io_sum));
    vlSelf->stage_3__DOT__units_0__DOT__io_carry = vlSelf->stage_3__DOT___units_0_io_carry;
    vlSelf->_stage_3_io_out_4 = ((IData)(vlSelf->stage_3__DOT___units_0_io_carry) 
                                 << 1U);
    vlSelf->stage_3__DOT__units_2__DOT__io_in_0 = vlSelf->stage_3__DOT__io_in_6;
    vlSelf->stage_3__DOT__units_1__DOT__io_in_0 = vlSelf->stage_3__DOT__io_in_3;
    vlSelf->stage_3__DOT__units_1__DOT__io_sum = vlSelf->stage_3__DOT___units_1_io_sum;
    vlSelf->_stage_3_io_out_1 = ((0x1000U & ((IData)(vlSelf->stage_3__DOT___units_1_io_sum) 
                                             << 1U)) 
                                 | (IData)(vlSelf->stage_3__DOT___units_1_io_sum));
    vlSelf->stage_3__DOT__units_1__DOT__io_carry = vlSelf->stage_3__DOT___units_1_io_carry;
    vlSelf->_stage_3_io_out_5 = ((IData)(vlSelf->stage_3__DOT___units_1_io_carry) 
                                 << 1U);
    vlSelf->stage_3__DOT__units_2__DOT__io_in_2 = vlSelf->stage_3__DOT__io_in_8;
    vlSelf->stage_3__DOT__units_2__DOT__io_sum = vlSelf->stage_3__DOT___units_2_io_sum;
    vlSelf->_stage_3_io_out_2 = ((0x1000U & ((IData)(vlSelf->stage_3__DOT___units_2_io_sum) 
                                             << 1U)) 
                                 | (IData)(vlSelf->stage_3__DOT___units_2_io_sum));
    vlSelf->stage_3__DOT__units_2__DOT__io_carry = vlSelf->stage_3__DOT___units_2_io_carry;
    vlSelf->_stage_3_io_out_6 = ((IData)(vlSelf->stage_3__DOT___units_2_io_carry) 
                                 << 1U);
    vlSelf->stage_4__DOT__units_1__DOT__io_in_0 = vlSelf->stage_4__DOT__io_in_3;
    vlSelf->stage_3__DOT__io_out_0 = vlSelf->_stage_3_io_out_0;
    vlSelf->stage_4__DOT__io_in_0 = vlSelf->_stage_3_io_out_0;
    vlSelf->stage_3__DOT__io_out_4 = vlSelf->_stage_3_io_out_4;
    vlSelf->stage_4__DOT__io_in_4 = vlSelf->_stage_3_io_out_4;
    vlSelf->stage_3__DOT__io_out_1 = vlSelf->_stage_3_io_out_1;
    vlSelf->stage_4__DOT__io_in_1 = vlSelf->_stage_3_io_out_1;
    vlSelf->stage_3__DOT__io_out_5 = vlSelf->_stage_3_io_out_5;
    vlSelf->stage_4__DOT__io_in_5 = vlSelf->_stage_3_io_out_5;
    vlSelf->stage_4__DOT__units_1__DOT__io_carry = 
        (((IData)(vlSelf->_stage_3_io_out_3) & (IData)(vlSelf->_stage_3_io_out_4)) 
         | (((IData)(vlSelf->_stage_3_io_out_4) | (IData)(vlSelf->_stage_3_io_out_3)) 
            & (IData)(vlSelf->_stage_3_io_out_5)));
    vlSelf->stage_4__DOT__units_1__DOT__io_sum = ((IData)(vlSelf->_stage_3_io_out_3) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_3_io_out_4) 
                                                   ^ (IData)(vlSelf->_stage_3_io_out_5)));
    vlSelf->stage_3__DOT__io_out_2 = vlSelf->_stage_3_io_out_2;
    vlSelf->stage_4__DOT__io_in_2 = vlSelf->_stage_3_io_out_2;
    vlSelf->stage_4__DOT__units_0__DOT__io_carry = 
        (((IData)(vlSelf->_stage_3_io_out_0) & (IData)(vlSelf->_stage_3_io_out_1)) 
         | (((IData)(vlSelf->_stage_3_io_out_1) | (IData)(vlSelf->_stage_3_io_out_0)) 
            & (IData)(vlSelf->_stage_3_io_out_2)));
    vlSelf->stage_4__DOT__units_0__DOT__io_sum = ((IData)(vlSelf->_stage_3_io_out_0) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_3_io_out_1) 
                                                   ^ (IData)(vlSelf->_stage_3_io_out_2)));
    vlSelf->stage_4__DOT__io_in_6 = vlSelf->_stage_3_io_out_6;
    vlSelf->stage_3__DOT__io_out_6 = vlSelf->_stage_3_io_out_6;
    vlSelf->_stage_4_io_out_2 = ((0x2000U & ((IData)(vlSelf->stage_3__DOT___units_2_io_carry) 
                                             << 2U)) 
                                 | (IData)(vlSelf->_stage_3_io_out_6));
    vlSelf->stage_4__DOT__units_0__DOT__io_in_0 = vlSelf->stage_4__DOT__io_in_0;
    vlSelf->stage_4__DOT__units_1__DOT__io_in_1 = vlSelf->stage_4__DOT__io_in_4;
    vlSelf->stage_4__DOT__units_0__DOT__io_in_1 = vlSelf->stage_4__DOT__io_in_1;
    vlSelf->stage_4__DOT__units_1__DOT__io_in_2 = vlSelf->stage_4__DOT__io_in_5;
    vlSelf->stage_4__DOT___units_1_io_carry = vlSelf->stage_4__DOT__units_1__DOT__io_carry;
    vlSelf->_stage_5_io_out_2 = ((IData)(vlSelf->stage_4__DOT__units_1__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_4__DOT___units_1_io_sum = vlSelf->stage_4__DOT__units_1__DOT__io_sum;
    vlSelf->_stage_4_io_out_1 = ((0x2000U & ((IData)(vlSelf->stage_4__DOT__units_1__DOT__io_sum) 
                                             << 1U)) 
                                 | (IData)(vlSelf->stage_4__DOT__units_1__DOT__io_sum));
    vlSelf->stage_4__DOT__units_0__DOT__io_in_2 = vlSelf->stage_4__DOT__io_in_2;
    vlSelf->stage_4__DOT___units_0_io_carry = vlSelf->stage_4__DOT__units_0__DOT__io_carry;
    vlSelf->_stage_5_io_out_1 = ((IData)(vlSelf->stage_4__DOT__units_0__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_4__DOT___units_0_io_sum = vlSelf->stage_4__DOT__units_0__DOT__io_sum;
    vlSelf->_stage_4_io_out_0 = ((0x2000U & ((IData)(vlSelf->stage_4__DOT__units_0__DOT__io_sum) 
                                             << 1U)) 
                                 | (IData)(vlSelf->stage_4__DOT__units_0__DOT__io_sum));
    vlSelf->stage_4__DOT__io_out_2 = vlSelf->_stage_4_io_out_2;
    vlSelf->stage_5__DOT__io_in_2 = vlSelf->_stage_4_io_out_2;
    vlSelf->stage_4__DOT__io_out_4 = vlSelf->_stage_5_io_out_2;
    vlSelf->stage_5__DOT__io_out_2 = vlSelf->_stage_5_io_out_2;
    vlSelf->stage_6__DOT__io_in_2 = vlSelf->_stage_5_io_out_2;
    vlSelf->_stage_4_io_out_4 = vlSelf->_stage_5_io_out_2;
    vlSelf->stage_4__DOT__io_out_1 = vlSelf->_stage_4_io_out_1;
    vlSelf->stage_5__DOT__io_in_1 = vlSelf->_stage_4_io_out_1;
    vlSelf->stage_4__DOT__io_out_3 = vlSelf->_stage_5_io_out_1;
    vlSelf->stage_5__DOT__io_out_1 = vlSelf->_stage_5_io_out_1;
    vlSelf->stage_6__DOT__io_in_1 = vlSelf->_stage_5_io_out_1;
    vlSelf->_stage_4_io_out_3 = vlSelf->_stage_5_io_out_1;
    vlSelf->stage_4__DOT__io_out_0 = vlSelf->_stage_4_io_out_0;
    vlSelf->stage_5__DOT__io_in_0 = vlSelf->_stage_4_io_out_0;
    vlSelf->stage_5__DOT___units_0_io_carry = (((IData)(vlSelf->_stage_4_io_out_0) 
                                                & (IData)(vlSelf->_stage_4_io_out_1)) 
                                               | (((IData)(vlSelf->_stage_4_io_out_1) 
                                                   | (IData)(vlSelf->_stage_4_io_out_0)) 
                                                  & (IData)(vlSelf->_stage_4_io_out_2)));
    vlSelf->_stage_5_io_out_0 = ((IData)(vlSelf->_stage_4_io_out_0) 
                                 ^ ((IData)(vlSelf->_stage_4_io_out_1) 
                                    ^ (IData)(vlSelf->_stage_4_io_out_2)));
    vlSelf->stage_5__DOT__units_0__DOT__io_in_2 = vlSelf->stage_5__DOT__io_in_2;
    vlSelf->stage_6__DOT__units_0__DOT__io_in_2 = vlSelf->stage_6__DOT__io_in_2;
    vlSelf->stage_5__DOT__io_in_4 = vlSelf->_stage_4_io_out_4;
    vlSelf->stage_5__DOT__units_0__DOT__io_in_1 = vlSelf->stage_5__DOT__io_in_1;
    vlSelf->stage_6__DOT__units_0__DOT__io_in_1 = vlSelf->stage_6__DOT__io_in_1;
    vlSelf->stage_5__DOT__io_in_3 = vlSelf->_stage_4_io_out_3;
    vlSelf->stage_5__DOT__units_0__DOT__io_in_0 = vlSelf->stage_5__DOT__io_in_0;
    vlSelf->stage_5__DOT__units_0__DOT__io_carry = vlSelf->stage_5__DOT___units_0_io_carry;
    vlSelf->_stage_6_io_out_1 = (0x3fffU & VL_SHIFTL_III(14,14,32, (IData)(vlSelf->stage_5__DOT___units_0_io_carry), 1U));
    vlSelf->stage_5__DOT__io_out_0 = vlSelf->_stage_5_io_out_0;
    vlSelf->stage_5__DOT__units_0__DOT__io_sum = vlSelf->_stage_5_io_out_0;
    vlSelf->stage_6__DOT__io_in_0 = vlSelf->_stage_5_io_out_0;
    vlSelf->_stage_6_io_out_0 = ((IData)(vlSelf->_stage_5_io_out_0) 
                                 ^ ((IData)(vlSelf->_stage_5_io_out_1) 
                                    ^ (IData)(vlSelf->_stage_5_io_out_2)));
    vlSelf->stage_6__DOT__units_0__DOT__io_carry = 
        (((IData)(vlSelf->_stage_5_io_out_0) & (IData)(vlSelf->_stage_5_io_out_1)) 
         | (((IData)(vlSelf->_stage_5_io_out_1) | (IData)(vlSelf->_stage_5_io_out_0)) 
            & (IData)(vlSelf->_stage_5_io_out_2)));
    vlSelf->stage_5__DOT__io_out_3 = vlSelf->_stage_6_io_out_1;
    vlSelf->stage_6__DOT__io_out_1 = vlSelf->_stage_6_io_out_1;
    vlSelf->stage_7__DOT__io_in_1 = vlSelf->_stage_6_io_out_1;
    vlSelf->_stage_5_io_out_3 = vlSelf->_stage_6_io_out_1;
    vlSelf->stage_6__DOT__units_0__DOT__io_in_0 = vlSelf->stage_6__DOT__io_in_0;
    vlSelf->stage_6__DOT__io_out_0 = vlSelf->_stage_6_io_out_0;
    vlSelf->stage_6__DOT__units_0__DOT__io_sum = vlSelf->_stage_6_io_out_0;
    vlSelf->stage_7__DOT__io_in_0 = vlSelf->_stage_6_io_out_0;
    vlSelf->stage_6__DOT___units_0_io_carry = vlSelf->stage_6__DOT__units_0__DOT__io_carry;
    vlSelf->_stage_6_io_out_2 = (0x3fffU & VL_SHIFTL_III(14,14,32, (IData)(vlSelf->stage_6__DOT__units_0__DOT__io_carry), 1U));
    vlSelf->stage_7__DOT__units_0__DOT__io_in_1 = vlSelf->stage_7__DOT__io_in_1;
    vlSelf->stage_6__DOT__io_in_3 = vlSelf->_stage_5_io_out_3;
    vlSelf->stage_7__DOT__units_0__DOT__io_in_0 = vlSelf->stage_7__DOT__io_in_0;
    vlSelf->stage_6__DOT__io_out_2 = vlSelf->_stage_6_io_out_2;
    vlSelf->stage_7__DOT__io_in_2 = vlSelf->_stage_6_io_out_2;
    vlSelf->io_out_0 = ((IData)(vlSelf->_stage_6_io_out_0) 
                        ^ ((IData)(vlSelf->_stage_6_io_out_1) 
                           ^ (IData)(vlSelf->_stage_6_io_out_2)));
    vlSelf->stage_7__DOT__units_0__DOT__io_carry = 
        (((IData)(vlSelf->_stage_6_io_out_0) & (IData)(vlSelf->_stage_6_io_out_1)) 
         | (((IData)(vlSelf->_stage_6_io_out_1) | (IData)(vlSelf->_stage_6_io_out_0)) 
            & (IData)(vlSelf->_stage_6_io_out_2)));
    vlSelf->stage_7__DOT__units_0__DOT__io_in_2 = vlSelf->stage_7__DOT__io_in_2;
    vlSelf->stage_7__DOT__io_out_0 = vlSelf->io_out_0;
    vlSelf->stage_7__DOT__units_0__DOT__io_sum = vlSelf->io_out_0;
    vlSelf->stage_7__DOT___units_0_io_carry = vlSelf->stage_7__DOT__units_0__DOT__io_carry;
    vlSelf->io_out_1 = (0x3fffU & VL_SHIFTL_III(14,14,32, (IData)(vlSelf->stage_7__DOT__units_0__DOT__io_carry), 1U));
    vlSelf->stage_7__DOT__io_out_1 = vlSelf->io_out_1;
}

VL_INLINE_OPT void Vtop_p_CSA_Total___nba_sequent__TOP__p_TOP_Til_Dep_total_piped_CT_syn_CSA_LUT__DOT__csa_groupin_0__0(Vtop_p_CSA_Total* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_p_CSA_Total___nba_sequent__TOP__p_TOP_Til_Dep_total_piped_CT_syn_CSA_LUT__DOT__csa_groupin_0__0\n"); );
    // Body
    vlSelf->stage__DOT__io_in_30 = vlSelf->io_in_30;
    vlSelf->_stage_io_out_10 = ((0x200U & ((IData)(vlSelf->io_in_30) 
                                           << 1U)) 
                                | (IData)(vlSelf->io_in_30));
    vlSelf->stage__DOT__io_in_31 = vlSelf->io_in_31;
    vlSelf->_stage_io_out_11 = ((0x200U & ((IData)(vlSelf->io_in_31) 
                                           << 1U)) 
                                | (IData)(vlSelf->io_in_31));
    vlSelf->stage__DOT__io_in_0 = vlSelf->io_in_0;
    vlSelf->stage__DOT__io_in_1 = vlSelf->io_in_1;
    vlSelf->stage__DOT__io_in_2 = vlSelf->io_in_2;
    vlSelf->stage__DOT__units_0__DOT__io_carry = (((IData)(vlSelf->io_in_0) 
                                                   & (IData)(vlSelf->io_in_1)) 
                                                  | (((IData)(vlSelf->io_in_1) 
                                                      | (IData)(vlSelf->io_in_0)) 
                                                     & (IData)(vlSelf->io_in_2)));
    vlSelf->stage__DOT__units_0__DOT__io_sum = ((IData)(vlSelf->io_in_0) 
                                                ^ ((IData)(vlSelf->io_in_1) 
                                                   ^ (IData)(vlSelf->io_in_2)));
    vlSelf->stage__DOT__io_in_3 = vlSelf->io_in_3;
    vlSelf->stage__DOT__io_in_4 = vlSelf->io_in_4;
    vlSelf->stage__DOT__io_in_5 = vlSelf->io_in_5;
    vlSelf->stage__DOT__units_1__DOT__io_carry = (((IData)(vlSelf->io_in_3) 
                                                   & (IData)(vlSelf->io_in_4)) 
                                                  | (((IData)(vlSelf->io_in_4) 
                                                      | (IData)(vlSelf->io_in_3)) 
                                                     & (IData)(vlSelf->io_in_5)));
    vlSelf->stage__DOT__units_1__DOT__io_sum = ((IData)(vlSelf->io_in_3) 
                                                ^ ((IData)(vlSelf->io_in_4) 
                                                   ^ (IData)(vlSelf->io_in_5)));
    vlSelf->stage__DOT__io_in_6 = vlSelf->io_in_6;
    vlSelf->stage__DOT__io_in_7 = vlSelf->io_in_7;
    vlSelf->stage__DOT__io_in_8 = vlSelf->io_in_8;
    vlSelf->stage__DOT__units_2__DOT__io_carry = (((IData)(vlSelf->io_in_6) 
                                                   & (IData)(vlSelf->io_in_7)) 
                                                  | (((IData)(vlSelf->io_in_7) 
                                                      | (IData)(vlSelf->io_in_6)) 
                                                     & (IData)(vlSelf->io_in_8)));
    vlSelf->stage__DOT__units_2__DOT__io_sum = ((IData)(vlSelf->io_in_6) 
                                                ^ ((IData)(vlSelf->io_in_7) 
                                                   ^ (IData)(vlSelf->io_in_8)));
    vlSelf->stage__DOT__io_in_9 = vlSelf->io_in_9;
    vlSelf->stage__DOT__io_in_10 = vlSelf->io_in_10;
    vlSelf->stage__DOT__io_in_11 = vlSelf->io_in_11;
    vlSelf->stage__DOT__units_3__DOT__io_carry = (((IData)(vlSelf->io_in_10) 
                                                   & (IData)(vlSelf->io_in_9)) 
                                                  | (((IData)(vlSelf->io_in_10) 
                                                      & (IData)(vlSelf->io_in_11)) 
                                                     | ((IData)(vlSelf->io_in_11) 
                                                        & (IData)(vlSelf->io_in_9))));
    vlSelf->stage__DOT__units_3__DOT__io_sum = ((IData)(vlSelf->io_in_9) 
                                                ^ ((IData)(vlSelf->io_in_10) 
                                                   ^ (IData)(vlSelf->io_in_11)));
    vlSelf->stage__DOT__io_in_12 = vlSelf->io_in_12;
    vlSelf->stage__DOT__io_in_13 = vlSelf->io_in_13;
    vlSelf->stage__DOT__io_in_14 = vlSelf->io_in_14;
    vlSelf->stage__DOT__units_4__DOT__io_carry = (((IData)(vlSelf->io_in_12) 
                                                   & (IData)(vlSelf->io_in_13)) 
                                                  | (((IData)(vlSelf->io_in_13) 
                                                      | (IData)(vlSelf->io_in_12)) 
                                                     & (IData)(vlSelf->io_in_14)));
    vlSelf->stage__DOT__units_4__DOT__io_sum = ((IData)(vlSelf->io_in_12) 
                                                ^ ((IData)(vlSelf->io_in_13) 
                                                   ^ (IData)(vlSelf->io_in_14)));
    vlSelf->stage__DOT__io_in_15 = vlSelf->io_in_15;
    vlSelf->stage__DOT__io_in_16 = vlSelf->io_in_16;
    vlSelf->stage__DOT__io_in_17 = vlSelf->io_in_17;
    vlSelf->stage__DOT__units_5__DOT__io_carry = (((IData)(vlSelf->io_in_15) 
                                                   & (IData)(vlSelf->io_in_16)) 
                                                  | (((IData)(vlSelf->io_in_16) 
                                                      | (IData)(vlSelf->io_in_15)) 
                                                     & (IData)(vlSelf->io_in_17)));
    vlSelf->stage__DOT__units_5__DOT__io_sum = ((IData)(vlSelf->io_in_15) 
                                                ^ ((IData)(vlSelf->io_in_16) 
                                                   ^ (IData)(vlSelf->io_in_17)));
    vlSelf->stage__DOT__io_in_18 = vlSelf->io_in_18;
    vlSelf->stage__DOT__io_in_19 = vlSelf->io_in_19;
    vlSelf->stage__DOT__io_in_20 = vlSelf->io_in_20;
    vlSelf->stage__DOT__units_6__DOT__io_carry = (((IData)(vlSelf->io_in_18) 
                                                   & (IData)(vlSelf->io_in_19)) 
                                                  | (((IData)(vlSelf->io_in_19) 
                                                      | (IData)(vlSelf->io_in_18)) 
                                                     & (IData)(vlSelf->io_in_20)));
    vlSelf->stage__DOT__units_6__DOT__io_sum = ((IData)(vlSelf->io_in_18) 
                                                ^ ((IData)(vlSelf->io_in_19) 
                                                   ^ (IData)(vlSelf->io_in_20)));
    vlSelf->stage__DOT__io_in_21 = vlSelf->io_in_21;
    vlSelf->stage__DOT__io_in_22 = vlSelf->io_in_22;
    vlSelf->stage__DOT__io_in_23 = vlSelf->io_in_23;
    vlSelf->stage__DOT__units_7__DOT__io_carry = (((IData)(vlSelf->io_in_21) 
                                                   & (IData)(vlSelf->io_in_22)) 
                                                  | (((IData)(vlSelf->io_in_22) 
                                                      | (IData)(vlSelf->io_in_21)) 
                                                     & (IData)(vlSelf->io_in_23)));
    vlSelf->stage__DOT__units_7__DOT__io_sum = ((IData)(vlSelf->io_in_21) 
                                                ^ ((IData)(vlSelf->io_in_22) 
                                                   ^ (IData)(vlSelf->io_in_23)));
    vlSelf->stage__DOT__io_in_24 = vlSelf->io_in_24;
    vlSelf->stage__DOT__io_in_25 = vlSelf->io_in_25;
    vlSelf->stage__DOT__io_in_26 = vlSelf->io_in_26;
    vlSelf->stage__DOT__units_8__DOT__io_carry = (((IData)(vlSelf->io_in_24) 
                                                   & (IData)(vlSelf->io_in_25)) 
                                                  | (((IData)(vlSelf->io_in_25) 
                                                      | (IData)(vlSelf->io_in_24)) 
                                                     & (IData)(vlSelf->io_in_26)));
    vlSelf->stage__DOT__units_8__DOT__io_sum = ((IData)(vlSelf->io_in_24) 
                                                ^ ((IData)(vlSelf->io_in_25) 
                                                   ^ (IData)(vlSelf->io_in_26)));
    vlSelf->stage__DOT__io_in_27 = vlSelf->io_in_27;
    vlSelf->stage__DOT__io_in_28 = vlSelf->io_in_28;
    vlSelf->stage__DOT__io_in_29 = vlSelf->io_in_29;
    vlSelf->stage__DOT__units_9__DOT__io_carry = (((IData)(vlSelf->io_in_27) 
                                                   & (IData)(vlSelf->io_in_28)) 
                                                  | (((IData)(vlSelf->io_in_28) 
                                                      | (IData)(vlSelf->io_in_27)) 
                                                     & (IData)(vlSelf->io_in_29)));
    vlSelf->stage__DOT__units_9__DOT__io_sum = ((IData)(vlSelf->io_in_27) 
                                                ^ ((IData)(vlSelf->io_in_28) 
                                                   ^ (IData)(vlSelf->io_in_29)));
    vlSelf->stage__DOT__io_out_10 = vlSelf->_stage_io_out_10;
    vlSelf->stage_1__DOT__io_in_10 = vlSelf->_stage_io_out_10;
    vlSelf->stage__DOT__io_out_11 = vlSelf->_stage_io_out_11;
    vlSelf->stage_1__DOT__io_in_11 = vlSelf->_stage_io_out_11;
    vlSelf->stage__DOT__units_0__DOT__io_in_0 = vlSelf->stage__DOT__io_in_0;
    vlSelf->stage__DOT__units_0__DOT__io_in_1 = vlSelf->stage__DOT__io_in_1;
    vlSelf->stage__DOT__units_0__DOT__io_in_2 = vlSelf->stage__DOT__io_in_2;
    vlSelf->stage__DOT___units_0_io_carry = vlSelf->stage__DOT__units_0__DOT__io_carry;
    vlSelf->_stage_io_out_12 = ((IData)(vlSelf->stage__DOT__units_0__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_0_io_sum = vlSelf->stage__DOT__units_0__DOT__io_sum;
    vlSelf->_stage_io_out_0 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_0__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_0__DOT__io_sum));
    vlSelf->stage__DOT__units_1__DOT__io_in_0 = vlSelf->stage__DOT__io_in_3;
    vlSelf->stage__DOT__units_1__DOT__io_in_1 = vlSelf->stage__DOT__io_in_4;
    vlSelf->stage__DOT__units_1__DOT__io_in_2 = vlSelf->stage__DOT__io_in_5;
    vlSelf->stage__DOT___units_1_io_carry = vlSelf->stage__DOT__units_1__DOT__io_carry;
    vlSelf->_stage_io_out_13 = ((IData)(vlSelf->stage__DOT__units_1__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_1_io_sum = vlSelf->stage__DOT__units_1__DOT__io_sum;
    vlSelf->_stage_io_out_1 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_1__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_1__DOT__io_sum));
    vlSelf->stage__DOT__units_2__DOT__io_in_0 = vlSelf->stage__DOT__io_in_6;
    vlSelf->stage__DOT__units_2__DOT__io_in_1 = vlSelf->stage__DOT__io_in_7;
    vlSelf->stage__DOT__units_2__DOT__io_in_2 = vlSelf->stage__DOT__io_in_8;
    vlSelf->stage__DOT___units_2_io_carry = vlSelf->stage__DOT__units_2__DOT__io_carry;
    vlSelf->_stage_io_out_14 = ((IData)(vlSelf->stage__DOT__units_2__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_2_io_sum = vlSelf->stage__DOT__units_2__DOT__io_sum;
    vlSelf->_stage_io_out_2 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_2__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_2__DOT__io_sum));
    vlSelf->stage__DOT__units_3__DOT__io_in_0 = vlSelf->stage__DOT__io_in_9;
    vlSelf->stage__DOT__units_3__DOT__io_in_1 = vlSelf->stage__DOT__io_in_10;
    vlSelf->stage__DOT__units_3__DOT__io_in_2 = vlSelf->stage__DOT__io_in_11;
    vlSelf->stage__DOT___units_3_io_carry = vlSelf->stage__DOT__units_3__DOT__io_carry;
    vlSelf->_stage_io_out_15 = ((IData)(vlSelf->stage__DOT__units_3__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_3_io_sum = vlSelf->stage__DOT__units_3__DOT__io_sum;
    vlSelf->_stage_io_out_3 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_3__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_3__DOT__io_sum));
    vlSelf->stage__DOT__units_4__DOT__io_in_0 = vlSelf->stage__DOT__io_in_12;
    vlSelf->stage__DOT__units_4__DOT__io_in_1 = vlSelf->stage__DOT__io_in_13;
    vlSelf->stage__DOT__units_4__DOT__io_in_2 = vlSelf->stage__DOT__io_in_14;
    vlSelf->stage__DOT___units_4_io_carry = vlSelf->stage__DOT__units_4__DOT__io_carry;
    vlSelf->_stage_io_out_16 = ((IData)(vlSelf->stage__DOT__units_4__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_4_io_sum = vlSelf->stage__DOT__units_4__DOT__io_sum;
    vlSelf->_stage_io_out_4 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_4__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_4__DOT__io_sum));
    vlSelf->stage__DOT__units_5__DOT__io_in_0 = vlSelf->stage__DOT__io_in_15;
    vlSelf->stage__DOT__units_5__DOT__io_in_1 = vlSelf->stage__DOT__io_in_16;
    vlSelf->stage__DOT__units_5__DOT__io_in_2 = vlSelf->stage__DOT__io_in_17;
    vlSelf->stage__DOT___units_5_io_carry = vlSelf->stage__DOT__units_5__DOT__io_carry;
    vlSelf->_stage_io_out_17 = ((IData)(vlSelf->stage__DOT__units_5__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_5_io_sum = vlSelf->stage__DOT__units_5__DOT__io_sum;
    vlSelf->_stage_io_out_5 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_5__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_5__DOT__io_sum));
    vlSelf->stage__DOT__units_6__DOT__io_in_0 = vlSelf->stage__DOT__io_in_18;
    vlSelf->stage__DOT__units_6__DOT__io_in_1 = vlSelf->stage__DOT__io_in_19;
    vlSelf->stage__DOT__units_6__DOT__io_in_2 = vlSelf->stage__DOT__io_in_20;
    vlSelf->stage__DOT___units_6_io_carry = vlSelf->stage__DOT__units_6__DOT__io_carry;
    vlSelf->_stage_io_out_18 = ((IData)(vlSelf->stage__DOT__units_6__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_6_io_sum = vlSelf->stage__DOT__units_6__DOT__io_sum;
    vlSelf->_stage_io_out_6 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_6__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_6__DOT__io_sum));
    vlSelf->stage__DOT__units_7__DOT__io_in_0 = vlSelf->stage__DOT__io_in_21;
    vlSelf->stage__DOT__units_7__DOT__io_in_1 = vlSelf->stage__DOT__io_in_22;
    vlSelf->stage__DOT__units_7__DOT__io_in_2 = vlSelf->stage__DOT__io_in_23;
    vlSelf->stage__DOT___units_7_io_carry = vlSelf->stage__DOT__units_7__DOT__io_carry;
    vlSelf->_stage_io_out_19 = ((IData)(vlSelf->stage__DOT__units_7__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_7_io_sum = vlSelf->stage__DOT__units_7__DOT__io_sum;
    vlSelf->_stage_io_out_7 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_7__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_7__DOT__io_sum));
    vlSelf->stage__DOT__units_8__DOT__io_in_0 = vlSelf->stage__DOT__io_in_24;
    vlSelf->stage__DOT__units_8__DOT__io_in_1 = vlSelf->stage__DOT__io_in_25;
    vlSelf->stage__DOT__units_8__DOT__io_in_2 = vlSelf->stage__DOT__io_in_26;
    vlSelf->stage__DOT___units_8_io_carry = vlSelf->stage__DOT__units_8__DOT__io_carry;
    vlSelf->_stage_io_out_20 = ((IData)(vlSelf->stage__DOT__units_8__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_8_io_sum = vlSelf->stage__DOT__units_8__DOT__io_sum;
    vlSelf->_stage_io_out_8 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_8__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_8__DOT__io_sum));
    vlSelf->stage__DOT__units_9__DOT__io_in_0 = vlSelf->stage__DOT__io_in_27;
    vlSelf->stage__DOT__units_9__DOT__io_in_1 = vlSelf->stage__DOT__io_in_28;
    vlSelf->stage__DOT__units_9__DOT__io_in_2 = vlSelf->stage__DOT__io_in_29;
    vlSelf->stage__DOT___units_9_io_carry = vlSelf->stage__DOT__units_9__DOT__io_carry;
    vlSelf->_stage_io_out_21 = ((IData)(vlSelf->stage__DOT__units_9__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_9_io_sum = vlSelf->stage__DOT__units_9__DOT__io_sum;
    vlSelf->_stage_io_out_9 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_9__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_9__DOT__io_sum));
    vlSelf->stage_1__DOT__units_3__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_10;
    vlSelf->stage_1__DOT__units_3__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_11;
    vlSelf->stage__DOT__io_out_12 = vlSelf->_stage_io_out_12;
    vlSelf->stage_1__DOT__io_in_12 = vlSelf->_stage_io_out_12;
    vlSelf->stage__DOT__io_out_0 = vlSelf->_stage_io_out_0;
    vlSelf->stage_1__DOT__io_in_0 = vlSelf->_stage_io_out_0;
    vlSelf->stage__DOT__io_out_13 = vlSelf->_stage_io_out_13;
    vlSelf->stage_1__DOT__io_in_13 = vlSelf->_stage_io_out_13;
    vlSelf->stage__DOT__io_out_1 = vlSelf->_stage_io_out_1;
    vlSelf->stage_1__DOT__io_in_1 = vlSelf->_stage_io_out_1;
    vlSelf->stage__DOT__io_out_14 = vlSelf->_stage_io_out_14;
    vlSelf->stage_1__DOT__io_in_14 = vlSelf->_stage_io_out_14;
    vlSelf->stage_1__DOT__units_4__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_12) & (IData)(vlSelf->_stage_io_out_13)) 
         | (((IData)(vlSelf->_stage_io_out_13) | (IData)(vlSelf->_stage_io_out_12)) 
            & (IData)(vlSelf->_stage_io_out_14)));
    vlSelf->stage_1__DOT__units_4__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_12) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_13) 
                                                   ^ (IData)(vlSelf->_stage_io_out_14)));
    vlSelf->stage__DOT__io_out_2 = vlSelf->_stage_io_out_2;
    vlSelf->stage_1__DOT__io_in_2 = vlSelf->_stage_io_out_2;
    vlSelf->stage_1__DOT__units_0__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_0) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_1) 
                                                   ^ (IData)(vlSelf->_stage_io_out_2)));
    vlSelf->stage_1__DOT__units_0__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_0) & (IData)(vlSelf->_stage_io_out_1)) 
         | (((IData)(vlSelf->_stage_io_out_1) | (IData)(vlSelf->_stage_io_out_0)) 
            & (IData)(vlSelf->_stage_io_out_2)));
    vlSelf->stage__DOT__io_out_15 = vlSelf->_stage_io_out_15;
    vlSelf->stage_1__DOT__io_in_15 = vlSelf->_stage_io_out_15;
    vlSelf->stage__DOT__io_out_3 = vlSelf->_stage_io_out_3;
    vlSelf->stage_1__DOT__io_in_3 = vlSelf->_stage_io_out_3;
    vlSelf->stage__DOT__io_out_16 = vlSelf->_stage_io_out_16;
    vlSelf->stage_1__DOT__io_in_16 = vlSelf->_stage_io_out_16;
    vlSelf->stage__DOT__io_out_4 = vlSelf->_stage_io_out_4;
    vlSelf->stage_1__DOT__io_in_4 = vlSelf->_stage_io_out_4;
    vlSelf->stage__DOT__io_out_17 = vlSelf->_stage_io_out_17;
    vlSelf->stage_1__DOT__io_in_17 = vlSelf->_stage_io_out_17;
    vlSelf->stage_1__DOT__units_5__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_15) & (IData)(vlSelf->_stage_io_out_16)) 
         | (((IData)(vlSelf->_stage_io_out_16) | (IData)(vlSelf->_stage_io_out_15)) 
            & (IData)(vlSelf->_stage_io_out_17)));
    vlSelf->stage_1__DOT__units_5__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_15) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_16) 
                                                   ^ (IData)(vlSelf->_stage_io_out_17)));
    vlSelf->stage__DOT__io_out_5 = vlSelf->_stage_io_out_5;
    vlSelf->stage_1__DOT__io_in_5 = vlSelf->_stage_io_out_5;
    vlSelf->stage_1__DOT__units_1__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_3) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_4) 
                                                   ^ (IData)(vlSelf->_stage_io_out_5)));
    vlSelf->stage_1__DOT__units_1__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_3) & (IData)(vlSelf->_stage_io_out_4)) 
         | (((IData)(vlSelf->_stage_io_out_4) | (IData)(vlSelf->_stage_io_out_3)) 
            & (IData)(vlSelf->_stage_io_out_5)));
    vlSelf->stage__DOT__io_out_18 = vlSelf->_stage_io_out_18;
    vlSelf->stage_1__DOT__io_in_18 = vlSelf->_stage_io_out_18;
    vlSelf->stage__DOT__io_out_6 = vlSelf->_stage_io_out_6;
    vlSelf->stage_1__DOT__io_in_6 = vlSelf->_stage_io_out_6;
    vlSelf->stage__DOT__io_out_19 = vlSelf->_stage_io_out_19;
    vlSelf->stage_1__DOT__io_in_19 = vlSelf->_stage_io_out_19;
    vlSelf->stage__DOT__io_out_7 = vlSelf->_stage_io_out_7;
    vlSelf->stage_1__DOT__io_in_7 = vlSelf->_stage_io_out_7;
    vlSelf->stage__DOT__io_out_20 = vlSelf->_stage_io_out_20;
    vlSelf->stage_1__DOT__io_in_20 = vlSelf->_stage_io_out_20;
    vlSelf->stage_1__DOT__units_6__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_18) & (IData)(vlSelf->_stage_io_out_19)) 
         | (((IData)(vlSelf->_stage_io_out_19) | (IData)(vlSelf->_stage_io_out_18)) 
            & (IData)(vlSelf->_stage_io_out_20)));
    vlSelf->stage_1__DOT__units_6__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_18) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_19) 
                                                   ^ (IData)(vlSelf->_stage_io_out_20)));
    vlSelf->stage__DOT__io_out_8 = vlSelf->_stage_io_out_8;
    vlSelf->stage_1__DOT__io_in_8 = vlSelf->_stage_io_out_8;
    vlSelf->stage_1__DOT__units_2__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_6) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_7) 
                                                   ^ (IData)(vlSelf->_stage_io_out_8)));
    vlSelf->stage_1__DOT__units_2__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_6) & (IData)(vlSelf->_stage_io_out_7)) 
         | (((IData)(vlSelf->_stage_io_out_7) | (IData)(vlSelf->_stage_io_out_6)) 
            & (IData)(vlSelf->_stage_io_out_8)));
    vlSelf->stage_1__DOT__io_in_21 = vlSelf->_stage_io_out_21;
    vlSelf->stage__DOT__io_out_21 = vlSelf->_stage_io_out_21;
    vlSelf->_stage_1_io_out_7 = ((0x400U & ((IData)(vlSelf->stage__DOT__units_9__DOT__io_carry) 
                                            << 2U)) 
                                 | (IData)(vlSelf->_stage_io_out_21));
    vlSelf->stage__DOT__io_out_9 = vlSelf->_stage_io_out_9;
    vlSelf->stage_1__DOT__io_in_9 = vlSelf->_stage_io_out_9;
    vlSelf->stage_1__DOT__units_3__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_9) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_10) 
                                                   ^ (IData)(vlSelf->_stage_io_out_11)));
    vlSelf->stage_1__DOT__units_3__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_9) & (IData)(vlSelf->_stage_io_out_10)) 
         | (((IData)(vlSelf->_stage_io_out_10) | (IData)(vlSelf->_stage_io_out_9)) 
            & (IData)(vlSelf->_stage_io_out_11)));
    vlSelf->stage_1__DOT__units_4__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_12;
    vlSelf->stage_1__DOT__units_0__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_0;
    vlSelf->stage_1__DOT__units_4__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_13;
    vlSelf->stage_1__DOT__units_0__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_1;
    vlSelf->stage_1__DOT__units_4__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_14;
    vlSelf->stage_1__DOT___units_4_io_carry = vlSelf->stage_1__DOT__units_4__DOT__io_carry;
    vlSelf->_stage_1_io_out_12 = ((IData)(vlSelf->stage_1__DOT__units_4__DOT__io_carry) 
                                  << 1U);
    vlSelf->stage_1__DOT___units_4_io_sum = vlSelf->stage_1__DOT__units_4__DOT__io_sum;
    vlSelf->_stage_1_io_out_4 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_4__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_4__DOT__io_sum));
    vlSelf->stage_1__DOT__units_0__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_2;
    vlSelf->stage_1__DOT___units_0_io_sum = vlSelf->stage_1__DOT__units_0__DOT__io_sum;
    vlSelf->_stage_1_io_out_0 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_0__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_0__DOT__io_sum));
    vlSelf->stage_1__DOT___units_0_io_carry = vlSelf->stage_1__DOT__units_0__DOT__io_carry;
    vlSelf->_stage_1_io_out_8 = ((IData)(vlSelf->stage_1__DOT__units_0__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_1__DOT__units_5__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_15;
    vlSelf->stage_1__DOT__units_1__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_3;
    vlSelf->stage_1__DOT__units_5__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_16;
    vlSelf->stage_1__DOT__units_1__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_4;
    vlSelf->stage_1__DOT__units_5__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_17;
    vlSelf->stage_1__DOT___units_5_io_carry = vlSelf->stage_1__DOT__units_5__DOT__io_carry;
    vlSelf->_stage_1_io_out_13 = ((IData)(vlSelf->stage_1__DOT__units_5__DOT__io_carry) 
                                  << 1U);
    vlSelf->stage_1__DOT___units_5_io_sum = vlSelf->stage_1__DOT__units_5__DOT__io_sum;
    vlSelf->_stage_1_io_out_5 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_5__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_5__DOT__io_sum));
    vlSelf->stage_1__DOT__units_1__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_5;
    vlSelf->stage_1__DOT___units_1_io_sum = vlSelf->stage_1__DOT__units_1__DOT__io_sum;
    vlSelf->_stage_1_io_out_1 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_1__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_1__DOT__io_sum));
    vlSelf->stage_1__DOT___units_1_io_carry = vlSelf->stage_1__DOT__units_1__DOT__io_carry;
    vlSelf->_stage_1_io_out_9 = ((IData)(vlSelf->stage_1__DOT__units_1__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_1__DOT__units_6__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_18;
    vlSelf->stage_1__DOT__units_2__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_6;
    vlSelf->stage_1__DOT__units_6__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_19;
    vlSelf->stage_1__DOT__units_2__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_7;
    vlSelf->stage_1__DOT__units_6__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_20;
    vlSelf->stage_1__DOT___units_6_io_carry = vlSelf->stage_1__DOT__units_6__DOT__io_carry;
    vlSelf->_stage_1_io_out_14 = ((IData)(vlSelf->stage_1__DOT__units_6__DOT__io_carry) 
                                  << 1U);
    vlSelf->stage_1__DOT___units_6_io_sum = vlSelf->stage_1__DOT__units_6__DOT__io_sum;
    vlSelf->_stage_1_io_out_6 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_6__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_6__DOT__io_sum));
    vlSelf->stage_1__DOT__units_2__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_8;
    vlSelf->stage_1__DOT___units_2_io_sum = vlSelf->stage_1__DOT__units_2__DOT__io_sum;
    vlSelf->_stage_1_io_out_2 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_2__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_2__DOT__io_sum));
    vlSelf->stage_1__DOT___units_2_io_carry = vlSelf->stage_1__DOT__units_2__DOT__io_carry;
    vlSelf->_stage_1_io_out_10 = ((IData)(vlSelf->stage_1__DOT__units_2__DOT__io_carry) 
                                  << 1U);
    vlSelf->stage_1__DOT__io_out_7 = vlSelf->_stage_1_io_out_7;
    vlSelf->stage_2__DOT__io_in_7 = vlSelf->_stage_1_io_out_7;
    vlSelf->stage_1__DOT__units_3__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_9;
    vlSelf->stage_1__DOT___units_3_io_sum = vlSelf->stage_1__DOT__units_3__DOT__io_sum;
    vlSelf->_stage_1_io_out_3 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_3__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_3__DOT__io_sum));
    vlSelf->stage_1__DOT___units_3_io_carry = vlSelf->stage_1__DOT__units_3__DOT__io_carry;
    vlSelf->_stage_1_io_out_11 = ((IData)(vlSelf->stage_1__DOT__units_3__DOT__io_carry) 
                                  << 1U);
    vlSelf->stage_1__DOT__io_out_12 = vlSelf->_stage_1_io_out_12;
    vlSelf->stage_2__DOT__io_in_12 = vlSelf->_stage_1_io_out_12;
    vlSelf->stage_1__DOT__io_out_4 = vlSelf->_stage_1_io_out_4;
    vlSelf->stage_2__DOT__io_in_4 = vlSelf->_stage_1_io_out_4;
    vlSelf->stage_1__DOT__io_out_0 = vlSelf->_stage_1_io_out_0;
    vlSelf->stage_2__DOT__io_in_0 = vlSelf->_stage_1_io_out_0;
    vlSelf->stage_1__DOT__io_out_8 = vlSelf->_stage_1_io_out_8;
    vlSelf->stage_2__DOT__io_in_8 = vlSelf->_stage_1_io_out_8;
    vlSelf->stage_1__DOT__io_out_13 = vlSelf->_stage_1_io_out_13;
    vlSelf->stage_2__DOT__io_in_13 = vlSelf->_stage_1_io_out_13;
    vlSelf->stage_1__DOT__io_out_5 = vlSelf->_stage_1_io_out_5;
    vlSelf->stage_2__DOT__io_in_5 = vlSelf->_stage_1_io_out_5;
    vlSelf->stage_1__DOT__io_out_1 = vlSelf->_stage_1_io_out_1;
    vlSelf->stage_2__DOT__io_in_1 = vlSelf->_stage_1_io_out_1;
    vlSelf->stage_1__DOT__io_out_9 = vlSelf->_stage_1_io_out_9;
    vlSelf->stage_2__DOT__io_in_9 = vlSelf->_stage_1_io_out_9;
    vlSelf->stage_1__DOT__io_out_14 = vlSelf->_stage_1_io_out_14;
    vlSelf->stage_2__DOT__io_in_14 = vlSelf->_stage_1_io_out_14;
    vlSelf->stage_2__DOT__units_4__DOT__io_carry = 
        (((IData)(vlSelf->_stage_1_io_out_12) & (IData)(vlSelf->_stage_1_io_out_13)) 
         | (((IData)(vlSelf->_stage_1_io_out_13) | (IData)(vlSelf->_stage_1_io_out_12)) 
            & (IData)(vlSelf->_stage_1_io_out_14)));
    vlSelf->stage_2__DOT__units_4__DOT__io_sum = ((IData)(vlSelf->_stage_1_io_out_12) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_1_io_out_13) 
                                                   ^ (IData)(vlSelf->_stage_1_io_out_14)));
    vlSelf->stage_1__DOT__io_out_6 = vlSelf->_stage_1_io_out_6;
    vlSelf->stage_2__DOT__io_in_6 = vlSelf->_stage_1_io_out_6;
    vlSelf->stage_2__DOT__units_2__DOT__io_sum = ((IData)(vlSelf->_stage_1_io_out_6) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_1_io_out_7) 
                                                   ^ (IData)(vlSelf->_stage_1_io_out_8)));
    vlSelf->stage_2__DOT__units_2__DOT__io_carry = 
        (((IData)(vlSelf->_stage_1_io_out_6) & (IData)(vlSelf->_stage_1_io_out_7)) 
         | (((IData)(vlSelf->_stage_1_io_out_7) | (IData)(vlSelf->_stage_1_io_out_6)) 
            & (IData)(vlSelf->_stage_1_io_out_8)));
    vlSelf->stage_1__DOT__io_out_2 = vlSelf->_stage_1_io_out_2;
    vlSelf->stage_2__DOT__io_in_2 = vlSelf->_stage_1_io_out_2;
    vlSelf->stage_2__DOT__units_0__DOT__io_sum = ((IData)(vlSelf->_stage_1_io_out_0) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_1_io_out_1) 
                                                   ^ (IData)(vlSelf->_stage_1_io_out_2)));
    vlSelf->stage_2__DOT__units_0__DOT__io_carry = 
        (((IData)(vlSelf->_stage_1_io_out_0) & (IData)(vlSelf->_stage_1_io_out_1)) 
         | (((IData)(vlSelf->_stage_1_io_out_1) | (IData)(vlSelf->_stage_1_io_out_0)) 
            & (IData)(vlSelf->_stage_1_io_out_2)));
    vlSelf->stage_1__DOT__io_out_10 = vlSelf->_stage_1_io_out_10;
    vlSelf->stage_2__DOT__io_in_10 = vlSelf->_stage_1_io_out_10;
    vlSelf->stage_2__DOT__units_2__DOT__io_in_1 = vlSelf->stage_2__DOT__io_in_7;
    vlSelf->stage_1__DOT__io_out_3 = vlSelf->_stage_1_io_out_3;
    vlSelf->stage_2__DOT__io_in_3 = vlSelf->_stage_1_io_out_3;
    vlSelf->stage_2__DOT__units_1__DOT__io_sum = ((IData)(vlSelf->_stage_1_io_out_3) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_1_io_out_4) 
                                                   ^ (IData)(vlSelf->_stage_1_io_out_5)));
    vlSelf->stage_2__DOT__units_1__DOT__io_carry = 
        (((IData)(vlSelf->_stage_1_io_out_3) & (IData)(vlSelf->_stage_1_io_out_4)) 
         | (((IData)(vlSelf->_stage_1_io_out_4) | (IData)(vlSelf->_stage_1_io_out_3)) 
            & (IData)(vlSelf->_stage_1_io_out_5)));
    vlSelf->stage_1__DOT__io_out_11 = vlSelf->_stage_1_io_out_11;
    vlSelf->stage_2__DOT__io_in_11 = vlSelf->_stage_1_io_out_11;
    vlSelf->stage_2__DOT__units_3__DOT__io_sum = ((IData)(vlSelf->_stage_1_io_out_9) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_1_io_out_10) 
                                                   ^ (IData)(vlSelf->_stage_1_io_out_11)));
    vlSelf->stage_2__DOT__units_3__DOT__io_carry = 
        (((IData)(vlSelf->_stage_1_io_out_9) & (IData)(vlSelf->_stage_1_io_out_10)) 
         | (((IData)(vlSelf->_stage_1_io_out_10) | (IData)(vlSelf->_stage_1_io_out_9)) 
            & (IData)(vlSelf->_stage_1_io_out_11)));
    vlSelf->stage_2__DOT__units_4__DOT__io_in_0 = vlSelf->stage_2__DOT__io_in_12;
    vlSelf->stage_2__DOT__units_1__DOT__io_in_1 = vlSelf->stage_2__DOT__io_in_4;
    vlSelf->stage_2__DOT__units_0__DOT__io_in_0 = vlSelf->stage_2__DOT__io_in_0;
    vlSelf->stage_2__DOT__units_2__DOT__io_in_2 = vlSelf->stage_2__DOT__io_in_8;
    vlSelf->stage_2__DOT__units_4__DOT__io_in_1 = vlSelf->stage_2__DOT__io_in_13;
    vlSelf->stage_2__DOT__units_1__DOT__io_in_2 = vlSelf->stage_2__DOT__io_in_5;
    vlSelf->stage_2__DOT__units_0__DOT__io_in_1 = vlSelf->stage_2__DOT__io_in_1;
    vlSelf->stage_2__DOT__units_3__DOT__io_in_0 = vlSelf->stage_2__DOT__io_in_9;
    vlSelf->stage_2__DOT__units_4__DOT__io_in_2 = vlSelf->stage_2__DOT__io_in_14;
    vlSelf->stage_2__DOT___units_4_io_carry = vlSelf->stage_2__DOT__units_4__DOT__io_carry;
    vlSelf->_stage_2_io_out_9 = ((IData)(vlSelf->stage_2__DOT__units_4__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_2__DOT___units_4_io_sum = vlSelf->stage_2__DOT__units_4__DOT__io_sum;
    vlSelf->_stage_2_io_out_4 = ((0x800U & ((IData)(vlSelf->stage_2__DOT__units_4__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_2__DOT__units_4__DOT__io_sum));
    vlSelf->stage_2__DOT__units_2__DOT__io_in_0 = vlSelf->stage_2__DOT__io_in_6;
    vlSelf->stage_2__DOT___units_2_io_sum = vlSelf->stage_2__DOT__units_2__DOT__io_sum;
    vlSelf->_stage_2_io_out_2 = ((0x800U & ((IData)(vlSelf->stage_2__DOT__units_2__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_2__DOT__units_2__DOT__io_sum));
    vlSelf->stage_2__DOT___units_2_io_carry = vlSelf->stage_2__DOT__units_2__DOT__io_carry;
    vlSelf->_stage_2_io_out_7 = ((IData)(vlSelf->stage_2__DOT__units_2__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_2__DOT__units_0__DOT__io_in_2 = vlSelf->stage_2__DOT__io_in_2;
    vlSelf->stage_2__DOT___units_0_io_sum = vlSelf->stage_2__DOT__units_0__DOT__io_sum;
    vlSelf->_stage_2_io_out_0 = ((0x800U & ((IData)(vlSelf->stage_2__DOT__units_0__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_2__DOT__units_0__DOT__io_sum));
    vlSelf->stage_2__DOT___units_0_io_carry = vlSelf->stage_2__DOT__units_0__DOT__io_carry;
    vlSelf->_stage_2_io_out_5 = ((IData)(vlSelf->stage_2__DOT__units_0__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_2__DOT__units_3__DOT__io_in_1 = vlSelf->stage_2__DOT__io_in_10;
    vlSelf->stage_2__DOT__units_1__DOT__io_in_0 = vlSelf->stage_2__DOT__io_in_3;
    vlSelf->stage_2__DOT___units_1_io_sum = vlSelf->stage_2__DOT__units_1__DOT__io_sum;
    vlSelf->_stage_2_io_out_1 = ((0x800U & ((IData)(vlSelf->stage_2__DOT__units_1__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_2__DOT__units_1__DOT__io_sum));
    vlSelf->stage_2__DOT___units_1_io_carry = vlSelf->stage_2__DOT__units_1__DOT__io_carry;
    vlSelf->_stage_2_io_out_6 = ((IData)(vlSelf->stage_2__DOT__units_1__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_2__DOT__units_3__DOT__io_in_2 = vlSelf->stage_2__DOT__io_in_11;
    vlSelf->stage_2__DOT___units_3_io_sum = vlSelf->stage_2__DOT__units_3__DOT__io_sum;
    vlSelf->_stage_2_io_out_3 = ((0x800U & ((IData)(vlSelf->stage_2__DOT__units_3__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_2__DOT__units_3__DOT__io_sum));
    vlSelf->stage_2__DOT___units_3_io_carry = vlSelf->stage_2__DOT__units_3__DOT__io_carry;
    vlSelf->_stage_2_io_out_8 = ((IData)(vlSelf->stage_2__DOT__units_3__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_3__DOT__io_in_9 = vlSelf->_stage_2_io_out_9;
    vlSelf->stage_2__DOT__io_out_9 = vlSelf->_stage_2_io_out_9;
    vlSelf->_stage_3_io_out_3 = ((0x1000U & ((IData)(vlSelf->stage_2__DOT__units_4__DOT__io_carry) 
                                             << 2U)) 
                                 | (IData)(vlSelf->_stage_2_io_out_9));
    vlSelf->stage_2__DOT__io_out_4 = vlSelf->_stage_2_io_out_4;
    vlSelf->stage_3__DOT__io_in_4 = vlSelf->_stage_2_io_out_4;
    vlSelf->stage_2__DOT__io_out_2 = vlSelf->_stage_2_io_out_2;
    vlSelf->stage_3__DOT__io_in_2 = vlSelf->_stage_2_io_out_2;
    vlSelf->stage_2__DOT__io_out_7 = vlSelf->_stage_2_io_out_7;
    vlSelf->stage_3__DOT__io_in_7 = vlSelf->_stage_2_io_out_7;
    vlSelf->stage_2__DOT__io_out_0 = vlSelf->_stage_2_io_out_0;
    vlSelf->stage_3__DOT__io_in_0 = vlSelf->_stage_2_io_out_0;
    vlSelf->stage_2__DOT__io_out_5 = vlSelf->_stage_2_io_out_5;
    vlSelf->stage_3__DOT__io_in_5 = vlSelf->_stage_2_io_out_5;
    vlSelf->stage_2__DOT__io_out_1 = vlSelf->_stage_2_io_out_1;
    vlSelf->stage_3__DOT__io_in_1 = vlSelf->_stage_2_io_out_1;
    vlSelf->stage_3__DOT___units_0_io_sum = ((IData)(vlSelf->_stage_2_io_out_0) 
                                             ^ ((IData)(vlSelf->_stage_2_io_out_1) 
                                                ^ (IData)(vlSelf->_stage_2_io_out_2)));
    vlSelf->stage_3__DOT___units_0_io_carry = (((IData)(vlSelf->_stage_2_io_out_0) 
                                                & (IData)(vlSelf->_stage_2_io_out_1)) 
                                               | (((IData)(vlSelf->_stage_2_io_out_1) 
                                                   | (IData)(vlSelf->_stage_2_io_out_0)) 
                                                  & (IData)(vlSelf->_stage_2_io_out_2)));
    vlSelf->stage_2__DOT__io_out_6 = vlSelf->_stage_2_io_out_6;
    vlSelf->stage_3__DOT__io_in_6 = vlSelf->_stage_2_io_out_6;
    vlSelf->stage_2__DOT__io_out_3 = vlSelf->_stage_2_io_out_3;
    vlSelf->stage_3__DOT__io_in_3 = vlSelf->_stage_2_io_out_3;
    vlSelf->stage_3__DOT___units_1_io_sum = ((IData)(vlSelf->_stage_2_io_out_3) 
                                             ^ ((IData)(vlSelf->_stage_2_io_out_4) 
                                                ^ (IData)(vlSelf->_stage_2_io_out_5)));
    vlSelf->stage_3__DOT___units_1_io_carry = (((IData)(vlSelf->_stage_2_io_out_3) 
                                                & (IData)(vlSelf->_stage_2_io_out_4)) 
                                               | (((IData)(vlSelf->_stage_2_io_out_4) 
                                                   | (IData)(vlSelf->_stage_2_io_out_3)) 
                                                  & (IData)(vlSelf->_stage_2_io_out_5)));
    vlSelf->stage_2__DOT__io_out_8 = vlSelf->_stage_2_io_out_8;
    vlSelf->stage_3__DOT__io_in_8 = vlSelf->_stage_2_io_out_8;
    vlSelf->stage_3__DOT___units_2_io_sum = ((IData)(vlSelf->_stage_2_io_out_6) 
                                             ^ ((IData)(vlSelf->_stage_2_io_out_7) 
                                                ^ (IData)(vlSelf->_stage_2_io_out_8)));
    vlSelf->stage_3__DOT___units_2_io_carry = (((IData)(vlSelf->_stage_2_io_out_6) 
                                                & (IData)(vlSelf->_stage_2_io_out_7)) 
                                               | (((IData)(vlSelf->_stage_2_io_out_7) 
                                                   | (IData)(vlSelf->_stage_2_io_out_6)) 
                                                  & (IData)(vlSelf->_stage_2_io_out_8)));
    vlSelf->stage_3__DOT__io_out_3 = vlSelf->_stage_3_io_out_3;
    vlSelf->stage_4__DOT__io_in_3 = vlSelf->_stage_3_io_out_3;
    vlSelf->stage_3__DOT__units_1__DOT__io_in_1 = vlSelf->stage_3__DOT__io_in_4;
    vlSelf->stage_3__DOT__units_0__DOT__io_in_2 = vlSelf->stage_3__DOT__io_in_2;
    vlSelf->stage_3__DOT__units_2__DOT__io_in_1 = vlSelf->stage_3__DOT__io_in_7;
    vlSelf->stage_3__DOT__units_0__DOT__io_in_0 = vlSelf->stage_3__DOT__io_in_0;
    vlSelf->stage_3__DOT__units_1__DOT__io_in_2 = vlSelf->stage_3__DOT__io_in_5;
    vlSelf->stage_3__DOT__units_0__DOT__io_in_1 = vlSelf->stage_3__DOT__io_in_1;
    vlSelf->stage_3__DOT__units_0__DOT__io_sum = vlSelf->stage_3__DOT___units_0_io_sum;
    vlSelf->_stage_3_io_out_0 = ((0x1000U & ((IData)(vlSelf->stage_3__DOT___units_0_io_sum) 
                                             << 1U)) 
                                 | (IData)(vlSelf->stage_3__DOT___units_0_io_sum));
    vlSelf->stage_3__DOT__units_0__DOT__io_carry = vlSelf->stage_3__DOT___units_0_io_carry;
    vlSelf->_stage_3_io_out_4 = ((IData)(vlSelf->stage_3__DOT___units_0_io_carry) 
                                 << 1U);
    vlSelf->stage_3__DOT__units_2__DOT__io_in_0 = vlSelf->stage_3__DOT__io_in_6;
    vlSelf->stage_3__DOT__units_1__DOT__io_in_0 = vlSelf->stage_3__DOT__io_in_3;
    vlSelf->stage_3__DOT__units_1__DOT__io_sum = vlSelf->stage_3__DOT___units_1_io_sum;
    vlSelf->_stage_3_io_out_1 = ((0x1000U & ((IData)(vlSelf->stage_3__DOT___units_1_io_sum) 
                                             << 1U)) 
                                 | (IData)(vlSelf->stage_3__DOT___units_1_io_sum));
    vlSelf->stage_3__DOT__units_1__DOT__io_carry = vlSelf->stage_3__DOT___units_1_io_carry;
    vlSelf->_stage_3_io_out_5 = ((IData)(vlSelf->stage_3__DOT___units_1_io_carry) 
                                 << 1U);
    vlSelf->stage_3__DOT__units_2__DOT__io_in_2 = vlSelf->stage_3__DOT__io_in_8;
    vlSelf->stage_3__DOT__units_2__DOT__io_sum = vlSelf->stage_3__DOT___units_2_io_sum;
    vlSelf->_stage_3_io_out_2 = ((0x1000U & ((IData)(vlSelf->stage_3__DOT___units_2_io_sum) 
                                             << 1U)) 
                                 | (IData)(vlSelf->stage_3__DOT___units_2_io_sum));
    vlSelf->stage_3__DOT__units_2__DOT__io_carry = vlSelf->stage_3__DOT___units_2_io_carry;
    vlSelf->_stage_3_io_out_6 = ((IData)(vlSelf->stage_3__DOT___units_2_io_carry) 
                                 << 1U);
    vlSelf->stage_4__DOT__units_1__DOT__io_in_0 = vlSelf->stage_4__DOT__io_in_3;
    vlSelf->stage_3__DOT__io_out_0 = vlSelf->_stage_3_io_out_0;
    vlSelf->stage_4__DOT__io_in_0 = vlSelf->_stage_3_io_out_0;
    vlSelf->stage_3__DOT__io_out_4 = vlSelf->_stage_3_io_out_4;
    vlSelf->stage_4__DOT__io_in_4 = vlSelf->_stage_3_io_out_4;
    vlSelf->stage_3__DOT__io_out_1 = vlSelf->_stage_3_io_out_1;
    vlSelf->stage_4__DOT__io_in_1 = vlSelf->_stage_3_io_out_1;
    vlSelf->stage_3__DOT__io_out_5 = vlSelf->_stage_3_io_out_5;
    vlSelf->stage_4__DOT__io_in_5 = vlSelf->_stage_3_io_out_5;
    vlSelf->stage_4__DOT__units_1__DOT__io_carry = 
        (((IData)(vlSelf->_stage_3_io_out_3) & (IData)(vlSelf->_stage_3_io_out_4)) 
         | (((IData)(vlSelf->_stage_3_io_out_4) | (IData)(vlSelf->_stage_3_io_out_3)) 
            & (IData)(vlSelf->_stage_3_io_out_5)));
    vlSelf->stage_4__DOT__units_1__DOT__io_sum = ((IData)(vlSelf->_stage_3_io_out_3) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_3_io_out_4) 
                                                   ^ (IData)(vlSelf->_stage_3_io_out_5)));
    vlSelf->stage_3__DOT__io_out_2 = vlSelf->_stage_3_io_out_2;
    vlSelf->stage_4__DOT__io_in_2 = vlSelf->_stage_3_io_out_2;
    vlSelf->stage_4__DOT__units_0__DOT__io_carry = 
        (((IData)(vlSelf->_stage_3_io_out_0) & (IData)(vlSelf->_stage_3_io_out_1)) 
         | (((IData)(vlSelf->_stage_3_io_out_1) | (IData)(vlSelf->_stage_3_io_out_0)) 
            & (IData)(vlSelf->_stage_3_io_out_2)));
    vlSelf->stage_4__DOT__units_0__DOT__io_sum = ((IData)(vlSelf->_stage_3_io_out_0) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_3_io_out_1) 
                                                   ^ (IData)(vlSelf->_stage_3_io_out_2)));
    vlSelf->stage_4__DOT__io_in_6 = vlSelf->_stage_3_io_out_6;
    vlSelf->stage_3__DOT__io_out_6 = vlSelf->_stage_3_io_out_6;
    vlSelf->_stage_4_io_out_2 = ((0x2000U & ((IData)(vlSelf->stage_3__DOT___units_2_io_carry) 
                                             << 2U)) 
                                 | (IData)(vlSelf->_stage_3_io_out_6));
    vlSelf->stage_4__DOT__units_0__DOT__io_in_0 = vlSelf->stage_4__DOT__io_in_0;
    vlSelf->stage_4__DOT__units_1__DOT__io_in_1 = vlSelf->stage_4__DOT__io_in_4;
    vlSelf->stage_4__DOT__units_0__DOT__io_in_1 = vlSelf->stage_4__DOT__io_in_1;
    vlSelf->stage_4__DOT__units_1__DOT__io_in_2 = vlSelf->stage_4__DOT__io_in_5;
    vlSelf->stage_4__DOT___units_1_io_carry = vlSelf->stage_4__DOT__units_1__DOT__io_carry;
    vlSelf->_stage_5_io_out_2 = ((IData)(vlSelf->stage_4__DOT__units_1__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_4__DOT___units_1_io_sum = vlSelf->stage_4__DOT__units_1__DOT__io_sum;
    vlSelf->_stage_4_io_out_1 = ((0x2000U & ((IData)(vlSelf->stage_4__DOT__units_1__DOT__io_sum) 
                                             << 1U)) 
                                 | (IData)(vlSelf->stage_4__DOT__units_1__DOT__io_sum));
    vlSelf->stage_4__DOT__units_0__DOT__io_in_2 = vlSelf->stage_4__DOT__io_in_2;
    vlSelf->stage_4__DOT___units_0_io_carry = vlSelf->stage_4__DOT__units_0__DOT__io_carry;
    vlSelf->_stage_5_io_out_1 = ((IData)(vlSelf->stage_4__DOT__units_0__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_4__DOT___units_0_io_sum = vlSelf->stage_4__DOT__units_0__DOT__io_sum;
    vlSelf->_stage_4_io_out_0 = ((0x2000U & ((IData)(vlSelf->stage_4__DOT__units_0__DOT__io_sum) 
                                             << 1U)) 
                                 | (IData)(vlSelf->stage_4__DOT__units_0__DOT__io_sum));
    vlSelf->stage_4__DOT__io_out_2 = vlSelf->_stage_4_io_out_2;
    vlSelf->stage_5__DOT__io_in_2 = vlSelf->_stage_4_io_out_2;
    vlSelf->stage_4__DOT__io_out_4 = vlSelf->_stage_5_io_out_2;
    vlSelf->stage_5__DOT__io_out_2 = vlSelf->_stage_5_io_out_2;
    vlSelf->stage_6__DOT__io_in_2 = vlSelf->_stage_5_io_out_2;
    vlSelf->_stage_4_io_out_4 = vlSelf->_stage_5_io_out_2;
    vlSelf->stage_4__DOT__io_out_1 = vlSelf->_stage_4_io_out_1;
    vlSelf->stage_5__DOT__io_in_1 = vlSelf->_stage_4_io_out_1;
    vlSelf->stage_4__DOT__io_out_3 = vlSelf->_stage_5_io_out_1;
    vlSelf->stage_5__DOT__io_out_1 = vlSelf->_stage_5_io_out_1;
    vlSelf->stage_6__DOT__io_in_1 = vlSelf->_stage_5_io_out_1;
    vlSelf->_stage_4_io_out_3 = vlSelf->_stage_5_io_out_1;
    vlSelf->stage_4__DOT__io_out_0 = vlSelf->_stage_4_io_out_0;
    vlSelf->stage_5__DOT__io_in_0 = vlSelf->_stage_4_io_out_0;
    vlSelf->stage_5__DOT___units_0_io_carry = (((IData)(vlSelf->_stage_4_io_out_0) 
                                                & (IData)(vlSelf->_stage_4_io_out_1)) 
                                               | (((IData)(vlSelf->_stage_4_io_out_1) 
                                                   | (IData)(vlSelf->_stage_4_io_out_0)) 
                                                  & (IData)(vlSelf->_stage_4_io_out_2)));
    vlSelf->_stage_5_io_out_0 = ((IData)(vlSelf->_stage_4_io_out_0) 
                                 ^ ((IData)(vlSelf->_stage_4_io_out_1) 
                                    ^ (IData)(vlSelf->_stage_4_io_out_2)));
    vlSelf->stage_5__DOT__units_0__DOT__io_in_2 = vlSelf->stage_5__DOT__io_in_2;
    vlSelf->stage_6__DOT__units_0__DOT__io_in_2 = vlSelf->stage_6__DOT__io_in_2;
    vlSelf->stage_5__DOT__io_in_4 = vlSelf->_stage_4_io_out_4;
    vlSelf->stage_5__DOT__units_0__DOT__io_in_1 = vlSelf->stage_5__DOT__io_in_1;
    vlSelf->stage_6__DOT__units_0__DOT__io_in_1 = vlSelf->stage_6__DOT__io_in_1;
    vlSelf->stage_5__DOT__io_in_3 = vlSelf->_stage_4_io_out_3;
    vlSelf->stage_5__DOT__units_0__DOT__io_in_0 = vlSelf->stage_5__DOT__io_in_0;
    vlSelf->stage_5__DOT__units_0__DOT__io_carry = vlSelf->stage_5__DOT___units_0_io_carry;
    vlSelf->_stage_6_io_out_1 = (0x3fffU & VL_SHIFTL_III(14,14,32, (IData)(vlSelf->stage_5__DOT___units_0_io_carry), 1U));
    vlSelf->stage_5__DOT__io_out_0 = vlSelf->_stage_5_io_out_0;
    vlSelf->stage_5__DOT__units_0__DOT__io_sum = vlSelf->_stage_5_io_out_0;
    vlSelf->stage_6__DOT__io_in_0 = vlSelf->_stage_5_io_out_0;
    vlSelf->_stage_6_io_out_0 = ((IData)(vlSelf->_stage_5_io_out_0) 
                                 ^ ((IData)(vlSelf->_stage_5_io_out_1) 
                                    ^ (IData)(vlSelf->_stage_5_io_out_2)));
    vlSelf->stage_6__DOT__units_0__DOT__io_carry = 
        (((IData)(vlSelf->_stage_5_io_out_0) & (IData)(vlSelf->_stage_5_io_out_1)) 
         | (((IData)(vlSelf->_stage_5_io_out_1) | (IData)(vlSelf->_stage_5_io_out_0)) 
            & (IData)(vlSelf->_stage_5_io_out_2)));
    vlSelf->stage_5__DOT__io_out_3 = vlSelf->_stage_6_io_out_1;
    vlSelf->stage_6__DOT__io_out_1 = vlSelf->_stage_6_io_out_1;
    vlSelf->stage_7__DOT__io_in_1 = vlSelf->_stage_6_io_out_1;
    vlSelf->_stage_5_io_out_3 = vlSelf->_stage_6_io_out_1;
    vlSelf->stage_6__DOT__units_0__DOT__io_in_0 = vlSelf->stage_6__DOT__io_in_0;
    vlSelf->stage_6__DOT__io_out_0 = vlSelf->_stage_6_io_out_0;
    vlSelf->stage_6__DOT__units_0__DOT__io_sum = vlSelf->_stage_6_io_out_0;
    vlSelf->stage_7__DOT__io_in_0 = vlSelf->_stage_6_io_out_0;
    vlSelf->stage_6__DOT___units_0_io_carry = vlSelf->stage_6__DOT__units_0__DOT__io_carry;
    vlSelf->_stage_6_io_out_2 = (0x3fffU & VL_SHIFTL_III(14,14,32, (IData)(vlSelf->stage_6__DOT__units_0__DOT__io_carry), 1U));
    vlSelf->stage_7__DOT__units_0__DOT__io_in_1 = vlSelf->stage_7__DOT__io_in_1;
    vlSelf->stage_6__DOT__io_in_3 = vlSelf->_stage_5_io_out_3;
    vlSelf->stage_7__DOT__units_0__DOT__io_in_0 = vlSelf->stage_7__DOT__io_in_0;
    vlSelf->stage_6__DOT__io_out_2 = vlSelf->_stage_6_io_out_2;
    vlSelf->stage_7__DOT__io_in_2 = vlSelf->_stage_6_io_out_2;
    vlSelf->io_out_0 = ((IData)(vlSelf->_stage_6_io_out_0) 
                        ^ ((IData)(vlSelf->_stage_6_io_out_1) 
                           ^ (IData)(vlSelf->_stage_6_io_out_2)));
    vlSelf->stage_7__DOT__units_0__DOT__io_carry = 
        (((IData)(vlSelf->_stage_6_io_out_0) & (IData)(vlSelf->_stage_6_io_out_1)) 
         | (((IData)(vlSelf->_stage_6_io_out_1) | (IData)(vlSelf->_stage_6_io_out_0)) 
            & (IData)(vlSelf->_stage_6_io_out_2)));
    vlSelf->stage_7__DOT__units_0__DOT__io_in_2 = vlSelf->stage_7__DOT__io_in_2;
    vlSelf->stage_7__DOT__io_out_0 = vlSelf->io_out_0;
    vlSelf->stage_7__DOT__units_0__DOT__io_sum = vlSelf->io_out_0;
    vlSelf->stage_7__DOT___units_0_io_carry = vlSelf->stage_7__DOT__units_0__DOT__io_carry;
    vlSelf->io_out_1 = (0x3fffU & VL_SHIFTL_III(14,14,32, (IData)(vlSelf->stage_7__DOT__units_0__DOT__io_carry), 1U));
    vlSelf->stage_7__DOT__io_out_1 = vlSelf->io_out_1;
}

VL_INLINE_OPT void Vtop_p_CSA_Total___nba_sequent__TOP__p_TOP_Til_Dep_total_piped_CT_syn_CSA_LUT__DOT__csa_groupin_5__0(Vtop_p_CSA_Total* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_p_CSA_Total___nba_sequent__TOP__p_TOP_Til_Dep_total_piped_CT_syn_CSA_LUT__DOT__csa_groupin_5__0\n"); );
    // Body
    vlSelf->stage__DOT__io_in_31 = vlSelf->io_in_31;
    vlSelf->_stage_io_out_11 = ((0x200U & ((IData)(vlSelf->io_in_31) 
                                           << 1U)) 
                                | (IData)(vlSelf->io_in_31));
    vlSelf->stage__DOT__io_in_30 = vlSelf->io_in_30;
    vlSelf->_stage_io_out_10 = ((0x200U & ((IData)(vlSelf->io_in_30) 
                                           << 1U)) 
                                | (IData)(vlSelf->io_in_30));
    vlSelf->stage__DOT__io_in_26 = vlSelf->io_in_26;
    vlSelf->stage__DOT__io_in_25 = vlSelf->io_in_25;
    vlSelf->stage__DOT__io_in_24 = vlSelf->io_in_24;
    vlSelf->stage__DOT__units_8__DOT__io_carry = (((IData)(vlSelf->io_in_24) 
                                                   & (IData)(vlSelf->io_in_25)) 
                                                  | (((IData)(vlSelf->io_in_25) 
                                                      | (IData)(vlSelf->io_in_24)) 
                                                     & (IData)(vlSelf->io_in_26)));
    vlSelf->stage__DOT__units_8__DOT__io_sum = ((IData)(vlSelf->io_in_24) 
                                                ^ ((IData)(vlSelf->io_in_25) 
                                                   ^ (IData)(vlSelf->io_in_26)));
    vlSelf->stage__DOT__io_in_23 = vlSelf->io_in_23;
    vlSelf->stage__DOT__io_in_22 = vlSelf->io_in_22;
    vlSelf->stage__DOT__io_in_21 = vlSelf->io_in_21;
    vlSelf->stage__DOT__units_7__DOT__io_carry = (((IData)(vlSelf->io_in_21) 
                                                   & (IData)(vlSelf->io_in_22)) 
                                                  | (((IData)(vlSelf->io_in_22) 
                                                      | (IData)(vlSelf->io_in_21)) 
                                                     & (IData)(vlSelf->io_in_23)));
    vlSelf->stage__DOT__units_7__DOT__io_sum = ((IData)(vlSelf->io_in_21) 
                                                ^ ((IData)(vlSelf->io_in_22) 
                                                   ^ (IData)(vlSelf->io_in_23)));
    vlSelf->stage__DOT__io_in_20 = vlSelf->io_in_20;
    vlSelf->stage__DOT__io_in_19 = vlSelf->io_in_19;
    vlSelf->stage__DOT__io_in_18 = vlSelf->io_in_18;
    vlSelf->stage__DOT__units_6__DOT__io_carry = (((IData)(vlSelf->io_in_18) 
                                                   & (IData)(vlSelf->io_in_19)) 
                                                  | (((IData)(vlSelf->io_in_19) 
                                                      | (IData)(vlSelf->io_in_18)) 
                                                     & (IData)(vlSelf->io_in_20)));
    vlSelf->stage__DOT__units_6__DOT__io_sum = ((IData)(vlSelf->io_in_18) 
                                                ^ ((IData)(vlSelf->io_in_19) 
                                                   ^ (IData)(vlSelf->io_in_20)));
    vlSelf->stage__DOT__io_in_17 = vlSelf->io_in_17;
    vlSelf->stage__DOT__io_in_16 = vlSelf->io_in_16;
    vlSelf->stage__DOT__io_in_15 = vlSelf->io_in_15;
    vlSelf->stage__DOT__units_5__DOT__io_carry = (((IData)(vlSelf->io_in_15) 
                                                   & (IData)(vlSelf->io_in_16)) 
                                                  | (((IData)(vlSelf->io_in_16) 
                                                      | (IData)(vlSelf->io_in_15)) 
                                                     & (IData)(vlSelf->io_in_17)));
    vlSelf->stage__DOT__units_5__DOT__io_sum = ((IData)(vlSelf->io_in_15) 
                                                ^ ((IData)(vlSelf->io_in_16) 
                                                   ^ (IData)(vlSelf->io_in_17)));
    vlSelf->stage__DOT__io_in_14 = vlSelf->io_in_14;
    vlSelf->stage__DOT__io_in_13 = vlSelf->io_in_13;
    vlSelf->stage__DOT__io_in_12 = vlSelf->io_in_12;
    vlSelf->stage__DOT__units_4__DOT__io_carry = (((IData)(vlSelf->io_in_12) 
                                                   & (IData)(vlSelf->io_in_13)) 
                                                  | (((IData)(vlSelf->io_in_13) 
                                                      | (IData)(vlSelf->io_in_12)) 
                                                     & (IData)(vlSelf->io_in_14)));
    vlSelf->stage__DOT__units_4__DOT__io_sum = ((IData)(vlSelf->io_in_12) 
                                                ^ ((IData)(vlSelf->io_in_13) 
                                                   ^ (IData)(vlSelf->io_in_14)));
    vlSelf->stage__DOT__io_in_0 = vlSelf->io_in_0;
    vlSelf->stage__DOT__io_in_1 = vlSelf->io_in_1;
    vlSelf->stage__DOT__io_in_2 = vlSelf->io_in_2;
    vlSelf->stage__DOT__units_0__DOT__io_carry = (((IData)(vlSelf->io_in_0) 
                                                   & (IData)(vlSelf->io_in_1)) 
                                                  | (((IData)(vlSelf->io_in_1) 
                                                      | (IData)(vlSelf->io_in_0)) 
                                                     & (IData)(vlSelf->io_in_2)));
    vlSelf->stage__DOT__units_0__DOT__io_sum = ((IData)(vlSelf->io_in_0) 
                                                ^ ((IData)(vlSelf->io_in_1) 
                                                   ^ (IData)(vlSelf->io_in_2)));
    vlSelf->stage__DOT__io_in_3 = vlSelf->io_in_3;
    vlSelf->stage__DOT__io_in_4 = vlSelf->io_in_4;
    vlSelf->stage__DOT__io_in_5 = vlSelf->io_in_5;
    vlSelf->stage__DOT__units_1__DOT__io_carry = (((IData)(vlSelf->io_in_3) 
                                                   & (IData)(vlSelf->io_in_4)) 
                                                  | (((IData)(vlSelf->io_in_4) 
                                                      | (IData)(vlSelf->io_in_3)) 
                                                     & (IData)(vlSelf->io_in_5)));
    vlSelf->stage__DOT__units_1__DOT__io_sum = ((IData)(vlSelf->io_in_3) 
                                                ^ ((IData)(vlSelf->io_in_4) 
                                                   ^ (IData)(vlSelf->io_in_5)));
    vlSelf->stage__DOT__io_in_6 = vlSelf->io_in_6;
    vlSelf->stage__DOT__io_in_7 = vlSelf->io_in_7;
    vlSelf->stage__DOT__io_in_8 = vlSelf->io_in_8;
    vlSelf->stage__DOT__units_2__DOT__io_carry = (((IData)(vlSelf->io_in_6) 
                                                   & (IData)(vlSelf->io_in_7)) 
                                                  | (((IData)(vlSelf->io_in_7) 
                                                      | (IData)(vlSelf->io_in_6)) 
                                                     & (IData)(vlSelf->io_in_8)));
    vlSelf->stage__DOT__units_2__DOT__io_sum = ((IData)(vlSelf->io_in_6) 
                                                ^ ((IData)(vlSelf->io_in_7) 
                                                   ^ (IData)(vlSelf->io_in_8)));
    vlSelf->stage__DOT__io_in_9 = vlSelf->io_in_9;
    vlSelf->stage__DOT__io_in_10 = vlSelf->io_in_10;
    vlSelf->stage__DOT__io_in_11 = vlSelf->io_in_11;
    vlSelf->stage__DOT__units_3__DOT__io_carry = (((IData)(vlSelf->io_in_10) 
                                                   & (IData)(vlSelf->io_in_9)) 
                                                  | (((IData)(vlSelf->io_in_10) 
                                                      & (IData)(vlSelf->io_in_11)) 
                                                     | ((IData)(vlSelf->io_in_11) 
                                                        & (IData)(vlSelf->io_in_9))));
    vlSelf->stage__DOT__units_3__DOT__io_sum = ((IData)(vlSelf->io_in_9) 
                                                ^ ((IData)(vlSelf->io_in_10) 
                                                   ^ (IData)(vlSelf->io_in_11)));
    vlSelf->stage__DOT__io_in_29 = vlSelf->io_in_29;
    vlSelf->stage__DOT__io_in_28 = vlSelf->io_in_28;
    vlSelf->stage__DOT__io_in_27 = vlSelf->io_in_27;
    vlSelf->stage__DOT__units_9__DOT__io_carry = (((IData)(vlSelf->io_in_27) 
                                                   & (IData)(vlSelf->io_in_28)) 
                                                  | (((IData)(vlSelf->io_in_28) 
                                                      | (IData)(vlSelf->io_in_27)) 
                                                     & (IData)(vlSelf->io_in_29)));
    vlSelf->stage__DOT__units_9__DOT__io_sum = ((IData)(vlSelf->io_in_27) 
                                                ^ ((IData)(vlSelf->io_in_28) 
                                                   ^ (IData)(vlSelf->io_in_29)));
    vlSelf->stage__DOT__io_out_11 = vlSelf->_stage_io_out_11;
    vlSelf->stage_1__DOT__io_in_11 = vlSelf->_stage_io_out_11;
    vlSelf->stage__DOT__io_out_10 = vlSelf->_stage_io_out_10;
    vlSelf->stage_1__DOT__io_in_10 = vlSelf->_stage_io_out_10;
    vlSelf->stage__DOT__units_8__DOT__io_in_2 = vlSelf->stage__DOT__io_in_26;
    vlSelf->stage__DOT__units_8__DOT__io_in_1 = vlSelf->stage__DOT__io_in_25;
    vlSelf->stage__DOT__units_8__DOT__io_in_0 = vlSelf->stage__DOT__io_in_24;
    vlSelf->stage__DOT___units_8_io_carry = vlSelf->stage__DOT__units_8__DOT__io_carry;
    vlSelf->_stage_io_out_20 = ((IData)(vlSelf->stage__DOT__units_8__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_8_io_sum = vlSelf->stage__DOT__units_8__DOT__io_sum;
    vlSelf->_stage_io_out_8 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_8__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_8__DOT__io_sum));
    vlSelf->stage__DOT__units_7__DOT__io_in_2 = vlSelf->stage__DOT__io_in_23;
    vlSelf->stage__DOT__units_7__DOT__io_in_1 = vlSelf->stage__DOT__io_in_22;
    vlSelf->stage__DOT__units_7__DOT__io_in_0 = vlSelf->stage__DOT__io_in_21;
    vlSelf->stage__DOT___units_7_io_carry = vlSelf->stage__DOT__units_7__DOT__io_carry;
    vlSelf->_stage_io_out_19 = ((IData)(vlSelf->stage__DOT__units_7__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_7_io_sum = vlSelf->stage__DOT__units_7__DOT__io_sum;
    vlSelf->_stage_io_out_7 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_7__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_7__DOT__io_sum));
    vlSelf->stage__DOT__units_6__DOT__io_in_2 = vlSelf->stage__DOT__io_in_20;
    vlSelf->stage__DOT__units_6__DOT__io_in_1 = vlSelf->stage__DOT__io_in_19;
    vlSelf->stage__DOT__units_6__DOT__io_in_0 = vlSelf->stage__DOT__io_in_18;
    vlSelf->stage__DOT___units_6_io_carry = vlSelf->stage__DOT__units_6__DOT__io_carry;
    vlSelf->_stage_io_out_18 = ((IData)(vlSelf->stage__DOT__units_6__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_6_io_sum = vlSelf->stage__DOT__units_6__DOT__io_sum;
    vlSelf->_stage_io_out_6 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_6__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_6__DOT__io_sum));
    vlSelf->stage__DOT__units_5__DOT__io_in_2 = vlSelf->stage__DOT__io_in_17;
    vlSelf->stage__DOT__units_5__DOT__io_in_1 = vlSelf->stage__DOT__io_in_16;
    vlSelf->stage__DOT__units_5__DOT__io_in_0 = vlSelf->stage__DOT__io_in_15;
    vlSelf->stage__DOT___units_5_io_carry = vlSelf->stage__DOT__units_5__DOT__io_carry;
    vlSelf->_stage_io_out_17 = ((IData)(vlSelf->stage__DOT__units_5__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_5_io_sum = vlSelf->stage__DOT__units_5__DOT__io_sum;
    vlSelf->_stage_io_out_5 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_5__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_5__DOT__io_sum));
    vlSelf->stage__DOT__units_4__DOT__io_in_2 = vlSelf->stage__DOT__io_in_14;
    vlSelf->stage__DOT__units_4__DOT__io_in_1 = vlSelf->stage__DOT__io_in_13;
    vlSelf->stage__DOT__units_4__DOT__io_in_0 = vlSelf->stage__DOT__io_in_12;
    vlSelf->stage__DOT___units_4_io_carry = vlSelf->stage__DOT__units_4__DOT__io_carry;
    vlSelf->_stage_io_out_16 = ((IData)(vlSelf->stage__DOT__units_4__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_4_io_sum = vlSelf->stage__DOT__units_4__DOT__io_sum;
    vlSelf->_stage_io_out_4 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_4__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_4__DOT__io_sum));
    vlSelf->stage__DOT__units_0__DOT__io_in_0 = vlSelf->stage__DOT__io_in_0;
    vlSelf->stage__DOT__units_0__DOT__io_in_1 = vlSelf->stage__DOT__io_in_1;
    vlSelf->stage__DOT__units_0__DOT__io_in_2 = vlSelf->stage__DOT__io_in_2;
    vlSelf->stage__DOT___units_0_io_carry = vlSelf->stage__DOT__units_0__DOT__io_carry;
    vlSelf->_stage_io_out_12 = ((IData)(vlSelf->stage__DOT__units_0__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_0_io_sum = vlSelf->stage__DOT__units_0__DOT__io_sum;
    vlSelf->_stage_io_out_0 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_0__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_0__DOT__io_sum));
    vlSelf->stage__DOT__units_1__DOT__io_in_0 = vlSelf->stage__DOT__io_in_3;
    vlSelf->stage__DOT__units_1__DOT__io_in_1 = vlSelf->stage__DOT__io_in_4;
    vlSelf->stage__DOT__units_1__DOT__io_in_2 = vlSelf->stage__DOT__io_in_5;
    vlSelf->stage__DOT___units_1_io_carry = vlSelf->stage__DOT__units_1__DOT__io_carry;
    vlSelf->_stage_io_out_13 = ((IData)(vlSelf->stage__DOT__units_1__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_1_io_sum = vlSelf->stage__DOT__units_1__DOT__io_sum;
    vlSelf->_stage_io_out_1 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_1__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_1__DOT__io_sum));
    vlSelf->stage__DOT__units_2__DOT__io_in_0 = vlSelf->stage__DOT__io_in_6;
    vlSelf->stage__DOT__units_2__DOT__io_in_1 = vlSelf->stage__DOT__io_in_7;
    vlSelf->stage__DOT__units_2__DOT__io_in_2 = vlSelf->stage__DOT__io_in_8;
    vlSelf->stage__DOT___units_2_io_carry = vlSelf->stage__DOT__units_2__DOT__io_carry;
    vlSelf->_stage_io_out_14 = ((IData)(vlSelf->stage__DOT__units_2__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_2_io_sum = vlSelf->stage__DOT__units_2__DOT__io_sum;
    vlSelf->_stage_io_out_2 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_2__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_2__DOT__io_sum));
    vlSelf->stage__DOT__units_3__DOT__io_in_0 = vlSelf->stage__DOT__io_in_9;
    vlSelf->stage__DOT__units_3__DOT__io_in_1 = vlSelf->stage__DOT__io_in_10;
    vlSelf->stage__DOT__units_3__DOT__io_in_2 = vlSelf->stage__DOT__io_in_11;
    vlSelf->stage__DOT___units_3_io_carry = vlSelf->stage__DOT__units_3__DOT__io_carry;
    vlSelf->_stage_io_out_15 = ((IData)(vlSelf->stage__DOT__units_3__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_3_io_sum = vlSelf->stage__DOT__units_3__DOT__io_sum;
    vlSelf->_stage_io_out_3 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_3__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_3__DOT__io_sum));
    vlSelf->stage__DOT__units_9__DOT__io_in_2 = vlSelf->stage__DOT__io_in_29;
    vlSelf->stage__DOT__units_9__DOT__io_in_1 = vlSelf->stage__DOT__io_in_28;
    vlSelf->stage__DOT__units_9__DOT__io_in_0 = vlSelf->stage__DOT__io_in_27;
    vlSelf->stage__DOT___units_9_io_carry = vlSelf->stage__DOT__units_9__DOT__io_carry;
    vlSelf->_stage_io_out_21 = ((IData)(vlSelf->stage__DOT__units_9__DOT__io_carry) 
                                << 1U);
    vlSelf->stage__DOT___units_9_io_sum = vlSelf->stage__DOT__units_9__DOT__io_sum;
    vlSelf->_stage_io_out_9 = ((0x200U & ((IData)(vlSelf->stage__DOT__units_9__DOT__io_sum) 
                                          << 1U)) | (IData)(vlSelf->stage__DOT__units_9__DOT__io_sum));
    vlSelf->stage_1__DOT__units_3__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_11;
    vlSelf->stage_1__DOT__units_3__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_10;
    vlSelf->stage__DOT__io_out_20 = vlSelf->_stage_io_out_20;
    vlSelf->stage_1__DOT__io_in_20 = vlSelf->_stage_io_out_20;
    vlSelf->stage__DOT__io_out_8 = vlSelf->_stage_io_out_8;
    vlSelf->stage_1__DOT__io_in_8 = vlSelf->_stage_io_out_8;
    vlSelf->stage__DOT__io_out_19 = vlSelf->_stage_io_out_19;
    vlSelf->stage_1__DOT__io_in_19 = vlSelf->_stage_io_out_19;
    vlSelf->stage__DOT__io_out_7 = vlSelf->_stage_io_out_7;
    vlSelf->stage_1__DOT__io_in_7 = vlSelf->_stage_io_out_7;
    vlSelf->stage__DOT__io_out_18 = vlSelf->_stage_io_out_18;
    vlSelf->stage_1__DOT__io_in_18 = vlSelf->_stage_io_out_18;
    vlSelf->stage_1__DOT__units_6__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_18) & (IData)(vlSelf->_stage_io_out_19)) 
         | (((IData)(vlSelf->_stage_io_out_19) | (IData)(vlSelf->_stage_io_out_18)) 
            & (IData)(vlSelf->_stage_io_out_20)));
    vlSelf->stage_1__DOT__units_6__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_18) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_19) 
                                                   ^ (IData)(vlSelf->_stage_io_out_20)));
    vlSelf->stage__DOT__io_out_6 = vlSelf->_stage_io_out_6;
    vlSelf->stage_1__DOT__io_in_6 = vlSelf->_stage_io_out_6;
    vlSelf->stage_1__DOT__units_2__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_6) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_7) 
                                                   ^ (IData)(vlSelf->_stage_io_out_8)));
    vlSelf->stage_1__DOT__units_2__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_6) & (IData)(vlSelf->_stage_io_out_7)) 
         | (((IData)(vlSelf->_stage_io_out_7) | (IData)(vlSelf->_stage_io_out_6)) 
            & (IData)(vlSelf->_stage_io_out_8)));
    vlSelf->stage__DOT__io_out_17 = vlSelf->_stage_io_out_17;
    vlSelf->stage_1__DOT__io_in_17 = vlSelf->_stage_io_out_17;
    vlSelf->stage__DOT__io_out_5 = vlSelf->_stage_io_out_5;
    vlSelf->stage_1__DOT__io_in_5 = vlSelf->_stage_io_out_5;
    vlSelf->stage__DOT__io_out_16 = vlSelf->_stage_io_out_16;
    vlSelf->stage_1__DOT__io_in_16 = vlSelf->_stage_io_out_16;
    vlSelf->stage__DOT__io_out_4 = vlSelf->_stage_io_out_4;
    vlSelf->stage_1__DOT__io_in_4 = vlSelf->_stage_io_out_4;
    vlSelf->stage__DOT__io_out_12 = vlSelf->_stage_io_out_12;
    vlSelf->stage_1__DOT__io_in_12 = vlSelf->_stage_io_out_12;
    vlSelf->stage__DOT__io_out_0 = vlSelf->_stage_io_out_0;
    vlSelf->stage_1__DOT__io_in_0 = vlSelf->_stage_io_out_0;
    vlSelf->stage__DOT__io_out_13 = vlSelf->_stage_io_out_13;
    vlSelf->stage_1__DOT__io_in_13 = vlSelf->_stage_io_out_13;
    vlSelf->stage__DOT__io_out_1 = vlSelf->_stage_io_out_1;
    vlSelf->stage_1__DOT__io_in_1 = vlSelf->_stage_io_out_1;
    vlSelf->stage__DOT__io_out_14 = vlSelf->_stage_io_out_14;
    vlSelf->stage_1__DOT__io_in_14 = vlSelf->_stage_io_out_14;
    vlSelf->stage_1__DOT__units_4__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_12) & (IData)(vlSelf->_stage_io_out_13)) 
         | (((IData)(vlSelf->_stage_io_out_13) | (IData)(vlSelf->_stage_io_out_12)) 
            & (IData)(vlSelf->_stage_io_out_14)));
    vlSelf->stage_1__DOT__units_4__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_12) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_13) 
                                                   ^ (IData)(vlSelf->_stage_io_out_14)));
    vlSelf->stage__DOT__io_out_2 = vlSelf->_stage_io_out_2;
    vlSelf->stage_1__DOT__io_in_2 = vlSelf->_stage_io_out_2;
    vlSelf->stage_1__DOT__units_0__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_0) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_1) 
                                                   ^ (IData)(vlSelf->_stage_io_out_2)));
    vlSelf->stage_1__DOT__units_0__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_0) & (IData)(vlSelf->_stage_io_out_1)) 
         | (((IData)(vlSelf->_stage_io_out_1) | (IData)(vlSelf->_stage_io_out_0)) 
            & (IData)(vlSelf->_stage_io_out_2)));
    vlSelf->stage__DOT__io_out_15 = vlSelf->_stage_io_out_15;
    vlSelf->stage_1__DOT__io_in_15 = vlSelf->_stage_io_out_15;
    vlSelf->stage_1__DOT__units_5__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_15) & (IData)(vlSelf->_stage_io_out_16)) 
         | (((IData)(vlSelf->_stage_io_out_16) | (IData)(vlSelf->_stage_io_out_15)) 
            & (IData)(vlSelf->_stage_io_out_17)));
    vlSelf->stage_1__DOT__units_5__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_15) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_16) 
                                                   ^ (IData)(vlSelf->_stage_io_out_17)));
    vlSelf->stage__DOT__io_out_3 = vlSelf->_stage_io_out_3;
    vlSelf->stage_1__DOT__io_in_3 = vlSelf->_stage_io_out_3;
    vlSelf->stage_1__DOT__units_1__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_3) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_4) 
                                                   ^ (IData)(vlSelf->_stage_io_out_5)));
    vlSelf->stage_1__DOT__units_1__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_3) & (IData)(vlSelf->_stage_io_out_4)) 
         | (((IData)(vlSelf->_stage_io_out_4) | (IData)(vlSelf->_stage_io_out_3)) 
            & (IData)(vlSelf->_stage_io_out_5)));
    vlSelf->stage_1__DOT__io_in_21 = vlSelf->_stage_io_out_21;
    vlSelf->stage__DOT__io_out_21 = vlSelf->_stage_io_out_21;
    vlSelf->_stage_1_io_out_7 = ((0x400U & ((IData)(vlSelf->stage__DOT__units_9__DOT__io_carry) 
                                            << 2U)) 
                                 | (IData)(vlSelf->_stage_io_out_21));
    vlSelf->stage__DOT__io_out_9 = vlSelf->_stage_io_out_9;
    vlSelf->stage_1__DOT__io_in_9 = vlSelf->_stage_io_out_9;
    vlSelf->stage_1__DOT__units_3__DOT__io_sum = ((IData)(vlSelf->_stage_io_out_9) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_io_out_10) 
                                                   ^ (IData)(vlSelf->_stage_io_out_11)));
    vlSelf->stage_1__DOT__units_3__DOT__io_carry = 
        (((IData)(vlSelf->_stage_io_out_9) & (IData)(vlSelf->_stage_io_out_10)) 
         | (((IData)(vlSelf->_stage_io_out_10) | (IData)(vlSelf->_stage_io_out_9)) 
            & (IData)(vlSelf->_stage_io_out_11)));
    vlSelf->stage_1__DOT__units_6__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_20;
    vlSelf->stage_1__DOT__units_2__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_8;
    vlSelf->stage_1__DOT__units_6__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_19;
    vlSelf->stage_1__DOT__units_2__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_7;
    vlSelf->stage_1__DOT__units_6__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_18;
    vlSelf->stage_1__DOT___units_6_io_carry = vlSelf->stage_1__DOT__units_6__DOT__io_carry;
    vlSelf->_stage_1_io_out_14 = ((IData)(vlSelf->stage_1__DOT__units_6__DOT__io_carry) 
                                  << 1U);
    vlSelf->stage_1__DOT___units_6_io_sum = vlSelf->stage_1__DOT__units_6__DOT__io_sum;
    vlSelf->_stage_1_io_out_6 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_6__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_6__DOT__io_sum));
    vlSelf->stage_1__DOT__units_2__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_6;
    vlSelf->stage_1__DOT___units_2_io_sum = vlSelf->stage_1__DOT__units_2__DOT__io_sum;
    vlSelf->_stage_1_io_out_2 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_2__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_2__DOT__io_sum));
    vlSelf->stage_1__DOT___units_2_io_carry = vlSelf->stage_1__DOT__units_2__DOT__io_carry;
    vlSelf->_stage_1_io_out_10 = ((IData)(vlSelf->stage_1__DOT__units_2__DOT__io_carry) 
                                  << 1U);
    vlSelf->stage_1__DOT__units_5__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_17;
    vlSelf->stage_1__DOT__units_1__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_5;
    vlSelf->stage_1__DOT__units_5__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_16;
    vlSelf->stage_1__DOT__units_1__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_4;
    vlSelf->stage_1__DOT__units_4__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_12;
    vlSelf->stage_1__DOT__units_0__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_0;
    vlSelf->stage_1__DOT__units_4__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_13;
    vlSelf->stage_1__DOT__units_0__DOT__io_in_1 = vlSelf->stage_1__DOT__io_in_1;
    vlSelf->stage_1__DOT__units_4__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_14;
    vlSelf->stage_1__DOT___units_4_io_carry = vlSelf->stage_1__DOT__units_4__DOT__io_carry;
    vlSelf->_stage_1_io_out_12 = ((IData)(vlSelf->stage_1__DOT__units_4__DOT__io_carry) 
                                  << 1U);
    vlSelf->stage_1__DOT___units_4_io_sum = vlSelf->stage_1__DOT__units_4__DOT__io_sum;
    vlSelf->_stage_1_io_out_4 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_4__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_4__DOT__io_sum));
    vlSelf->stage_1__DOT__units_0__DOT__io_in_2 = vlSelf->stage_1__DOT__io_in_2;
    vlSelf->stage_1__DOT___units_0_io_sum = vlSelf->stage_1__DOT__units_0__DOT__io_sum;
    vlSelf->_stage_1_io_out_0 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_0__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_0__DOT__io_sum));
    vlSelf->stage_1__DOT___units_0_io_carry = vlSelf->stage_1__DOT__units_0__DOT__io_carry;
    vlSelf->_stage_1_io_out_8 = ((IData)(vlSelf->stage_1__DOT__units_0__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_1__DOT__units_5__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_15;
    vlSelf->stage_1__DOT___units_5_io_carry = vlSelf->stage_1__DOT__units_5__DOT__io_carry;
    vlSelf->_stage_1_io_out_13 = ((IData)(vlSelf->stage_1__DOT__units_5__DOT__io_carry) 
                                  << 1U);
    vlSelf->stage_1__DOT___units_5_io_sum = vlSelf->stage_1__DOT__units_5__DOT__io_sum;
    vlSelf->_stage_1_io_out_5 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_5__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_5__DOT__io_sum));
    vlSelf->stage_1__DOT__units_1__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_3;
    vlSelf->stage_1__DOT___units_1_io_sum = vlSelf->stage_1__DOT__units_1__DOT__io_sum;
    vlSelf->_stage_1_io_out_1 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_1__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_1__DOT__io_sum));
    vlSelf->stage_1__DOT___units_1_io_carry = vlSelf->stage_1__DOT__units_1__DOT__io_carry;
    vlSelf->_stage_1_io_out_9 = ((IData)(vlSelf->stage_1__DOT__units_1__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_1__DOT__io_out_7 = vlSelf->_stage_1_io_out_7;
    vlSelf->stage_2__DOT__io_in_7 = vlSelf->_stage_1_io_out_7;
    vlSelf->stage_1__DOT__units_3__DOT__io_in_0 = vlSelf->stage_1__DOT__io_in_9;
    vlSelf->stage_1__DOT___units_3_io_sum = vlSelf->stage_1__DOT__units_3__DOT__io_sum;
    vlSelf->_stage_1_io_out_3 = ((0x400U & ((IData)(vlSelf->stage_1__DOT__units_3__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_1__DOT__units_3__DOT__io_sum));
    vlSelf->stage_1__DOT___units_3_io_carry = vlSelf->stage_1__DOT__units_3__DOT__io_carry;
    vlSelf->_stage_1_io_out_11 = ((IData)(vlSelf->stage_1__DOT__units_3__DOT__io_carry) 
                                  << 1U);
    vlSelf->stage_1__DOT__io_out_14 = vlSelf->_stage_1_io_out_14;
    vlSelf->stage_2__DOT__io_in_14 = vlSelf->_stage_1_io_out_14;
    vlSelf->stage_1__DOT__io_out_6 = vlSelf->_stage_1_io_out_6;
    vlSelf->stage_2__DOT__io_in_6 = vlSelf->_stage_1_io_out_6;
    vlSelf->stage_1__DOT__io_out_2 = vlSelf->_stage_1_io_out_2;
    vlSelf->stage_2__DOT__io_in_2 = vlSelf->_stage_1_io_out_2;
    vlSelf->stage_1__DOT__io_out_10 = vlSelf->_stage_1_io_out_10;
    vlSelf->stage_2__DOT__io_in_10 = vlSelf->_stage_1_io_out_10;
    vlSelf->stage_1__DOT__io_out_12 = vlSelf->_stage_1_io_out_12;
    vlSelf->stage_2__DOT__io_in_12 = vlSelf->_stage_1_io_out_12;
    vlSelf->stage_1__DOT__io_out_4 = vlSelf->_stage_1_io_out_4;
    vlSelf->stage_2__DOT__io_in_4 = vlSelf->_stage_1_io_out_4;
    vlSelf->stage_1__DOT__io_out_0 = vlSelf->_stage_1_io_out_0;
    vlSelf->stage_2__DOT__io_in_0 = vlSelf->_stage_1_io_out_0;
    vlSelf->stage_1__DOT__io_out_8 = vlSelf->_stage_1_io_out_8;
    vlSelf->stage_2__DOT__io_in_8 = vlSelf->_stage_1_io_out_8;
    vlSelf->stage_2__DOT__units_2__DOT__io_sum = ((IData)(vlSelf->_stage_1_io_out_6) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_1_io_out_7) 
                                                   ^ (IData)(vlSelf->_stage_1_io_out_8)));
    vlSelf->stage_2__DOT__units_2__DOT__io_carry = 
        (((IData)(vlSelf->_stage_1_io_out_6) & (IData)(vlSelf->_stage_1_io_out_7)) 
         | (((IData)(vlSelf->_stage_1_io_out_7) | (IData)(vlSelf->_stage_1_io_out_6)) 
            & (IData)(vlSelf->_stage_1_io_out_8)));
    vlSelf->stage_1__DOT__io_out_13 = vlSelf->_stage_1_io_out_13;
    vlSelf->stage_2__DOT__io_in_13 = vlSelf->_stage_1_io_out_13;
    vlSelf->stage_2__DOT__units_4__DOT__io_carry = 
        (((IData)(vlSelf->_stage_1_io_out_12) & (IData)(vlSelf->_stage_1_io_out_13)) 
         | (((IData)(vlSelf->_stage_1_io_out_13) | (IData)(vlSelf->_stage_1_io_out_12)) 
            & (IData)(vlSelf->_stage_1_io_out_14)));
    vlSelf->stage_2__DOT__units_4__DOT__io_sum = ((IData)(vlSelf->_stage_1_io_out_12) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_1_io_out_13) 
                                                   ^ (IData)(vlSelf->_stage_1_io_out_14)));
    vlSelf->stage_1__DOT__io_out_5 = vlSelf->_stage_1_io_out_5;
    vlSelf->stage_2__DOT__io_in_5 = vlSelf->_stage_1_io_out_5;
    vlSelf->stage_1__DOT__io_out_1 = vlSelf->_stage_1_io_out_1;
    vlSelf->stage_2__DOT__io_in_1 = vlSelf->_stage_1_io_out_1;
    vlSelf->stage_2__DOT__units_0__DOT__io_sum = ((IData)(vlSelf->_stage_1_io_out_0) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_1_io_out_1) 
                                                   ^ (IData)(vlSelf->_stage_1_io_out_2)));
    vlSelf->stage_2__DOT__units_0__DOT__io_carry = 
        (((IData)(vlSelf->_stage_1_io_out_0) & (IData)(vlSelf->_stage_1_io_out_1)) 
         | (((IData)(vlSelf->_stage_1_io_out_1) | (IData)(vlSelf->_stage_1_io_out_0)) 
            & (IData)(vlSelf->_stage_1_io_out_2)));
    vlSelf->stage_1__DOT__io_out_9 = vlSelf->_stage_1_io_out_9;
    vlSelf->stage_2__DOT__io_in_9 = vlSelf->_stage_1_io_out_9;
    vlSelf->stage_2__DOT__units_2__DOT__io_in_1 = vlSelf->stage_2__DOT__io_in_7;
    vlSelf->stage_1__DOT__io_out_3 = vlSelf->_stage_1_io_out_3;
    vlSelf->stage_2__DOT__io_in_3 = vlSelf->_stage_1_io_out_3;
    vlSelf->stage_2__DOT__units_1__DOT__io_sum = ((IData)(vlSelf->_stage_1_io_out_3) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_1_io_out_4) 
                                                   ^ (IData)(vlSelf->_stage_1_io_out_5)));
    vlSelf->stage_2__DOT__units_1__DOT__io_carry = 
        (((IData)(vlSelf->_stage_1_io_out_3) & (IData)(vlSelf->_stage_1_io_out_4)) 
         | (((IData)(vlSelf->_stage_1_io_out_4) | (IData)(vlSelf->_stage_1_io_out_3)) 
            & (IData)(vlSelf->_stage_1_io_out_5)));
    vlSelf->stage_1__DOT__io_out_11 = vlSelf->_stage_1_io_out_11;
    vlSelf->stage_2__DOT__io_in_11 = vlSelf->_stage_1_io_out_11;
    vlSelf->stage_2__DOT__units_3__DOT__io_sum = ((IData)(vlSelf->_stage_1_io_out_9) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_1_io_out_10) 
                                                   ^ (IData)(vlSelf->_stage_1_io_out_11)));
    vlSelf->stage_2__DOT__units_3__DOT__io_carry = 
        (((IData)(vlSelf->_stage_1_io_out_9) & (IData)(vlSelf->_stage_1_io_out_10)) 
         | (((IData)(vlSelf->_stage_1_io_out_10) | (IData)(vlSelf->_stage_1_io_out_9)) 
            & (IData)(vlSelf->_stage_1_io_out_11)));
    vlSelf->stage_2__DOT__units_4__DOT__io_in_2 = vlSelf->stage_2__DOT__io_in_14;
    vlSelf->stage_2__DOT__units_2__DOT__io_in_0 = vlSelf->stage_2__DOT__io_in_6;
    vlSelf->stage_2__DOT__units_0__DOT__io_in_2 = vlSelf->stage_2__DOT__io_in_2;
    vlSelf->stage_2__DOT__units_3__DOT__io_in_1 = vlSelf->stage_2__DOT__io_in_10;
    vlSelf->stage_2__DOT__units_4__DOT__io_in_0 = vlSelf->stage_2__DOT__io_in_12;
    vlSelf->stage_2__DOT__units_1__DOT__io_in_1 = vlSelf->stage_2__DOT__io_in_4;
    vlSelf->stage_2__DOT__units_0__DOT__io_in_0 = vlSelf->stage_2__DOT__io_in_0;
    vlSelf->stage_2__DOT__units_2__DOT__io_in_2 = vlSelf->stage_2__DOT__io_in_8;
    vlSelf->stage_2__DOT___units_2_io_sum = vlSelf->stage_2__DOT__units_2__DOT__io_sum;
    vlSelf->_stage_2_io_out_2 = ((0x800U & ((IData)(vlSelf->stage_2__DOT__units_2__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_2__DOT__units_2__DOT__io_sum));
    vlSelf->stage_2__DOT___units_2_io_carry = vlSelf->stage_2__DOT__units_2__DOT__io_carry;
    vlSelf->_stage_2_io_out_7 = ((IData)(vlSelf->stage_2__DOT__units_2__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_2__DOT__units_4__DOT__io_in_1 = vlSelf->stage_2__DOT__io_in_13;
    vlSelf->stage_2__DOT___units_4_io_carry = vlSelf->stage_2__DOT__units_4__DOT__io_carry;
    vlSelf->_stage_2_io_out_9 = ((IData)(vlSelf->stage_2__DOT__units_4__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_2__DOT___units_4_io_sum = vlSelf->stage_2__DOT__units_4__DOT__io_sum;
    vlSelf->_stage_2_io_out_4 = ((0x800U & ((IData)(vlSelf->stage_2__DOT__units_4__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_2__DOT__units_4__DOT__io_sum));
    vlSelf->stage_2__DOT__units_1__DOT__io_in_2 = vlSelf->stage_2__DOT__io_in_5;
    vlSelf->stage_2__DOT__units_0__DOT__io_in_1 = vlSelf->stage_2__DOT__io_in_1;
    vlSelf->stage_2__DOT___units_0_io_sum = vlSelf->stage_2__DOT__units_0__DOT__io_sum;
    vlSelf->_stage_2_io_out_0 = ((0x800U & ((IData)(vlSelf->stage_2__DOT__units_0__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_2__DOT__units_0__DOT__io_sum));
    vlSelf->stage_2__DOT___units_0_io_carry = vlSelf->stage_2__DOT__units_0__DOT__io_carry;
    vlSelf->_stage_2_io_out_5 = ((IData)(vlSelf->stage_2__DOT__units_0__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_2__DOT__units_3__DOT__io_in_0 = vlSelf->stage_2__DOT__io_in_9;
    vlSelf->stage_2__DOT__units_1__DOT__io_in_0 = vlSelf->stage_2__DOT__io_in_3;
    vlSelf->stage_2__DOT___units_1_io_sum = vlSelf->stage_2__DOT__units_1__DOT__io_sum;
    vlSelf->_stage_2_io_out_1 = ((0x800U & ((IData)(vlSelf->stage_2__DOT__units_1__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_2__DOT__units_1__DOT__io_sum));
    vlSelf->stage_2__DOT___units_1_io_carry = vlSelf->stage_2__DOT__units_1__DOT__io_carry;
    vlSelf->_stage_2_io_out_6 = ((IData)(vlSelf->stage_2__DOT__units_1__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_2__DOT__units_3__DOT__io_in_2 = vlSelf->stage_2__DOT__io_in_11;
    vlSelf->stage_2__DOT___units_3_io_sum = vlSelf->stage_2__DOT__units_3__DOT__io_sum;
    vlSelf->_stage_2_io_out_3 = ((0x800U & ((IData)(vlSelf->stage_2__DOT__units_3__DOT__io_sum) 
                                            << 1U)) 
                                 | (IData)(vlSelf->stage_2__DOT__units_3__DOT__io_sum));
    vlSelf->stage_2__DOT___units_3_io_carry = vlSelf->stage_2__DOT__units_3__DOT__io_carry;
    vlSelf->_stage_2_io_out_8 = ((IData)(vlSelf->stage_2__DOT__units_3__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_2__DOT__io_out_2 = vlSelf->_stage_2_io_out_2;
    vlSelf->stage_3__DOT__io_in_2 = vlSelf->_stage_2_io_out_2;
    vlSelf->stage_2__DOT__io_out_7 = vlSelf->_stage_2_io_out_7;
    vlSelf->stage_3__DOT__io_in_7 = vlSelf->_stage_2_io_out_7;
    vlSelf->stage_3__DOT__io_in_9 = vlSelf->_stage_2_io_out_9;
    vlSelf->stage_2__DOT__io_out_9 = vlSelf->_stage_2_io_out_9;
    vlSelf->_stage_3_io_out_3 = ((0x1000U & ((IData)(vlSelf->stage_2__DOT__units_4__DOT__io_carry) 
                                             << 2U)) 
                                 | (IData)(vlSelf->_stage_2_io_out_9));
    vlSelf->stage_2__DOT__io_out_4 = vlSelf->_stage_2_io_out_4;
    vlSelf->stage_3__DOT__io_in_4 = vlSelf->_stage_2_io_out_4;
    vlSelf->stage_2__DOT__io_out_0 = vlSelf->_stage_2_io_out_0;
    vlSelf->stage_3__DOT__io_in_0 = vlSelf->_stage_2_io_out_0;
    vlSelf->stage_2__DOT__io_out_5 = vlSelf->_stage_2_io_out_5;
    vlSelf->stage_3__DOT__io_in_5 = vlSelf->_stage_2_io_out_5;
    vlSelf->stage_2__DOT__io_out_1 = vlSelf->_stage_2_io_out_1;
    vlSelf->stage_3__DOT__io_in_1 = vlSelf->_stage_2_io_out_1;
    vlSelf->stage_3__DOT___units_0_io_sum = ((IData)(vlSelf->_stage_2_io_out_0) 
                                             ^ ((IData)(vlSelf->_stage_2_io_out_1) 
                                                ^ (IData)(vlSelf->_stage_2_io_out_2)));
    vlSelf->stage_3__DOT___units_0_io_carry = (((IData)(vlSelf->_stage_2_io_out_0) 
                                                & (IData)(vlSelf->_stage_2_io_out_1)) 
                                               | (((IData)(vlSelf->_stage_2_io_out_1) 
                                                   | (IData)(vlSelf->_stage_2_io_out_0)) 
                                                  & (IData)(vlSelf->_stage_2_io_out_2)));
    vlSelf->stage_2__DOT__io_out_6 = vlSelf->_stage_2_io_out_6;
    vlSelf->stage_3__DOT__io_in_6 = vlSelf->_stage_2_io_out_6;
    vlSelf->stage_2__DOT__io_out_3 = vlSelf->_stage_2_io_out_3;
    vlSelf->stage_3__DOT__io_in_3 = vlSelf->_stage_2_io_out_3;
    vlSelf->stage_3__DOT___units_1_io_sum = ((IData)(vlSelf->_stage_2_io_out_3) 
                                             ^ ((IData)(vlSelf->_stage_2_io_out_4) 
                                                ^ (IData)(vlSelf->_stage_2_io_out_5)));
    vlSelf->stage_3__DOT___units_1_io_carry = (((IData)(vlSelf->_stage_2_io_out_3) 
                                                & (IData)(vlSelf->_stage_2_io_out_4)) 
                                               | (((IData)(vlSelf->_stage_2_io_out_4) 
                                                   | (IData)(vlSelf->_stage_2_io_out_3)) 
                                                  & (IData)(vlSelf->_stage_2_io_out_5)));
    vlSelf->stage_2__DOT__io_out_8 = vlSelf->_stage_2_io_out_8;
    vlSelf->stage_3__DOT__io_in_8 = vlSelf->_stage_2_io_out_8;
    vlSelf->stage_3__DOT___units_2_io_sum = ((IData)(vlSelf->_stage_2_io_out_6) 
                                             ^ ((IData)(vlSelf->_stage_2_io_out_7) 
                                                ^ (IData)(vlSelf->_stage_2_io_out_8)));
    vlSelf->stage_3__DOT___units_2_io_carry = (((IData)(vlSelf->_stage_2_io_out_6) 
                                                & (IData)(vlSelf->_stage_2_io_out_7)) 
                                               | (((IData)(vlSelf->_stage_2_io_out_7) 
                                                   | (IData)(vlSelf->_stage_2_io_out_6)) 
                                                  & (IData)(vlSelf->_stage_2_io_out_8)));
    vlSelf->stage_3__DOT__units_0__DOT__io_in_2 = vlSelf->stage_3__DOT__io_in_2;
    vlSelf->stage_3__DOT__units_2__DOT__io_in_1 = vlSelf->stage_3__DOT__io_in_7;
    vlSelf->stage_3__DOT__io_out_3 = vlSelf->_stage_3_io_out_3;
    vlSelf->stage_4__DOT__io_in_3 = vlSelf->_stage_3_io_out_3;
    vlSelf->stage_3__DOT__units_1__DOT__io_in_1 = vlSelf->stage_3__DOT__io_in_4;
    vlSelf->stage_3__DOT__units_0__DOT__io_in_0 = vlSelf->stage_3__DOT__io_in_0;
    vlSelf->stage_3__DOT__units_1__DOT__io_in_2 = vlSelf->stage_3__DOT__io_in_5;
    vlSelf->stage_3__DOT__units_0__DOT__io_in_1 = vlSelf->stage_3__DOT__io_in_1;
    vlSelf->stage_3__DOT__units_0__DOT__io_sum = vlSelf->stage_3__DOT___units_0_io_sum;
    vlSelf->_stage_3_io_out_0 = ((0x1000U & ((IData)(vlSelf->stage_3__DOT___units_0_io_sum) 
                                             << 1U)) 
                                 | (IData)(vlSelf->stage_3__DOT___units_0_io_sum));
    vlSelf->stage_3__DOT__units_0__DOT__io_carry = vlSelf->stage_3__DOT___units_0_io_carry;
    vlSelf->_stage_3_io_out_4 = ((IData)(vlSelf->stage_3__DOT___units_0_io_carry) 
                                 << 1U);
    vlSelf->stage_3__DOT__units_2__DOT__io_in_0 = vlSelf->stage_3__DOT__io_in_6;
    vlSelf->stage_3__DOT__units_1__DOT__io_in_0 = vlSelf->stage_3__DOT__io_in_3;
    vlSelf->stage_3__DOT__units_1__DOT__io_sum = vlSelf->stage_3__DOT___units_1_io_sum;
    vlSelf->_stage_3_io_out_1 = ((0x1000U & ((IData)(vlSelf->stage_3__DOT___units_1_io_sum) 
                                             << 1U)) 
                                 | (IData)(vlSelf->stage_3__DOT___units_1_io_sum));
    vlSelf->stage_3__DOT__units_1__DOT__io_carry = vlSelf->stage_3__DOT___units_1_io_carry;
    vlSelf->_stage_3_io_out_5 = ((IData)(vlSelf->stage_3__DOT___units_1_io_carry) 
                                 << 1U);
    vlSelf->stage_3__DOT__units_2__DOT__io_in_2 = vlSelf->stage_3__DOT__io_in_8;
    vlSelf->stage_3__DOT__units_2__DOT__io_sum = vlSelf->stage_3__DOT___units_2_io_sum;
    vlSelf->_stage_3_io_out_2 = ((0x1000U & ((IData)(vlSelf->stage_3__DOT___units_2_io_sum) 
                                             << 1U)) 
                                 | (IData)(vlSelf->stage_3__DOT___units_2_io_sum));
    vlSelf->stage_3__DOT__units_2__DOT__io_carry = vlSelf->stage_3__DOT___units_2_io_carry;
    vlSelf->_stage_3_io_out_6 = ((IData)(vlSelf->stage_3__DOT___units_2_io_carry) 
                                 << 1U);
    vlSelf->stage_4__DOT__units_1__DOT__io_in_0 = vlSelf->stage_4__DOT__io_in_3;
    vlSelf->stage_3__DOT__io_out_0 = vlSelf->_stage_3_io_out_0;
    vlSelf->stage_4__DOT__io_in_0 = vlSelf->_stage_3_io_out_0;
    vlSelf->stage_3__DOT__io_out_4 = vlSelf->_stage_3_io_out_4;
    vlSelf->stage_4__DOT__io_in_4 = vlSelf->_stage_3_io_out_4;
    vlSelf->stage_3__DOT__io_out_1 = vlSelf->_stage_3_io_out_1;
    vlSelf->stage_4__DOT__io_in_1 = vlSelf->_stage_3_io_out_1;
    vlSelf->stage_3__DOT__io_out_5 = vlSelf->_stage_3_io_out_5;
    vlSelf->stage_4__DOT__io_in_5 = vlSelf->_stage_3_io_out_5;
    vlSelf->stage_4__DOT__units_1__DOT__io_carry = 
        (((IData)(vlSelf->_stage_3_io_out_3) & (IData)(vlSelf->_stage_3_io_out_4)) 
         | (((IData)(vlSelf->_stage_3_io_out_4) | (IData)(vlSelf->_stage_3_io_out_3)) 
            & (IData)(vlSelf->_stage_3_io_out_5)));
    vlSelf->stage_4__DOT__units_1__DOT__io_sum = ((IData)(vlSelf->_stage_3_io_out_3) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_3_io_out_4) 
                                                   ^ (IData)(vlSelf->_stage_3_io_out_5)));
    vlSelf->stage_3__DOT__io_out_2 = vlSelf->_stage_3_io_out_2;
    vlSelf->stage_4__DOT__io_in_2 = vlSelf->_stage_3_io_out_2;
    vlSelf->stage_4__DOT__units_0__DOT__io_carry = 
        (((IData)(vlSelf->_stage_3_io_out_0) & (IData)(vlSelf->_stage_3_io_out_1)) 
         | (((IData)(vlSelf->_stage_3_io_out_1) | (IData)(vlSelf->_stage_3_io_out_0)) 
            & (IData)(vlSelf->_stage_3_io_out_2)));
    vlSelf->stage_4__DOT__units_0__DOT__io_sum = ((IData)(vlSelf->_stage_3_io_out_0) 
                                                  ^ 
                                                  ((IData)(vlSelf->_stage_3_io_out_1) 
                                                   ^ (IData)(vlSelf->_stage_3_io_out_2)));
    vlSelf->stage_4__DOT__io_in_6 = vlSelf->_stage_3_io_out_6;
    vlSelf->stage_3__DOT__io_out_6 = vlSelf->_stage_3_io_out_6;
    vlSelf->_stage_4_io_out_2 = ((0x2000U & ((IData)(vlSelf->stage_3__DOT___units_2_io_carry) 
                                             << 2U)) 
                                 | (IData)(vlSelf->_stage_3_io_out_6));
    vlSelf->stage_4__DOT__units_0__DOT__io_in_0 = vlSelf->stage_4__DOT__io_in_0;
    vlSelf->stage_4__DOT__units_1__DOT__io_in_1 = vlSelf->stage_4__DOT__io_in_4;
    vlSelf->stage_4__DOT__units_0__DOT__io_in_1 = vlSelf->stage_4__DOT__io_in_1;
    vlSelf->stage_4__DOT__units_1__DOT__io_in_2 = vlSelf->stage_4__DOT__io_in_5;
    vlSelf->stage_4__DOT___units_1_io_carry = vlSelf->stage_4__DOT__units_1__DOT__io_carry;
    vlSelf->_stage_5_io_out_2 = ((IData)(vlSelf->stage_4__DOT__units_1__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_4__DOT___units_1_io_sum = vlSelf->stage_4__DOT__units_1__DOT__io_sum;
    vlSelf->_stage_4_io_out_1 = ((0x2000U & ((IData)(vlSelf->stage_4__DOT__units_1__DOT__io_sum) 
                                             << 1U)) 
                                 | (IData)(vlSelf->stage_4__DOT__units_1__DOT__io_sum));
    vlSelf->stage_4__DOT__units_0__DOT__io_in_2 = vlSelf->stage_4__DOT__io_in_2;
    vlSelf->stage_4__DOT___units_0_io_carry = vlSelf->stage_4__DOT__units_0__DOT__io_carry;
    vlSelf->_stage_5_io_out_1 = ((IData)(vlSelf->stage_4__DOT__units_0__DOT__io_carry) 
                                 << 1U);
    vlSelf->stage_4__DOT___units_0_io_sum = vlSelf->stage_4__DOT__units_0__DOT__io_sum;
    vlSelf->_stage_4_io_out_0 = ((0x2000U & ((IData)(vlSelf->stage_4__DOT__units_0__DOT__io_sum) 
                                             << 1U)) 
                                 | (IData)(vlSelf->stage_4__DOT__units_0__DOT__io_sum));
    vlSelf->stage_4__DOT__io_out_2 = vlSelf->_stage_4_io_out_2;
    vlSelf->stage_5__DOT__io_in_2 = vlSelf->_stage_4_io_out_2;
    vlSelf->stage_4__DOT__io_out_4 = vlSelf->_stage_5_io_out_2;
    vlSelf->stage_5__DOT__io_out_2 = vlSelf->_stage_5_io_out_2;
    vlSelf->stage_6__DOT__io_in_2 = vlSelf->_stage_5_io_out_2;
    vlSelf->_stage_4_io_out_4 = vlSelf->_stage_5_io_out_2;
    vlSelf->stage_4__DOT__io_out_1 = vlSelf->_stage_4_io_out_1;
    vlSelf->stage_5__DOT__io_in_1 = vlSelf->_stage_4_io_out_1;
    vlSelf->stage_4__DOT__io_out_3 = vlSelf->_stage_5_io_out_1;
    vlSelf->stage_5__DOT__io_out_1 = vlSelf->_stage_5_io_out_1;
    vlSelf->stage_6__DOT__io_in_1 = vlSelf->_stage_5_io_out_1;
    vlSelf->_stage_4_io_out_3 = vlSelf->_stage_5_io_out_1;
    vlSelf->stage_4__DOT__io_out_0 = vlSelf->_stage_4_io_out_0;
    vlSelf->stage_5__DOT__io_in_0 = vlSelf->_stage_4_io_out_0;
    vlSelf->stage_5__DOT___units_0_io_carry = (((IData)(vlSelf->_stage_4_io_out_0) 
                                                & (IData)(vlSelf->_stage_4_io_out_1)) 
                                               | (((IData)(vlSelf->_stage_4_io_out_1) 
                                                   | (IData)(vlSelf->_stage_4_io_out_0)) 
                                                  & (IData)(vlSelf->_stage_4_io_out_2)));
    vlSelf->_stage_5_io_out_0 = ((IData)(vlSelf->_stage_4_io_out_0) 
                                 ^ ((IData)(vlSelf->_stage_4_io_out_1) 
                                    ^ (IData)(vlSelf->_stage_4_io_out_2)));
    vlSelf->stage_5__DOT__units_0__DOT__io_in_2 = vlSelf->stage_5__DOT__io_in_2;
    vlSelf->stage_6__DOT__units_0__DOT__io_in_2 = vlSelf->stage_6__DOT__io_in_2;
    vlSelf->stage_5__DOT__io_in_4 = vlSelf->_stage_4_io_out_4;
    vlSelf->stage_5__DOT__units_0__DOT__io_in_1 = vlSelf->stage_5__DOT__io_in_1;
    vlSelf->stage_6__DOT__units_0__DOT__io_in_1 = vlSelf->stage_6__DOT__io_in_1;
    vlSelf->stage_5__DOT__io_in_3 = vlSelf->_stage_4_io_out_3;
    vlSelf->stage_5__DOT__units_0__DOT__io_in_0 = vlSelf->stage_5__DOT__io_in_0;
    vlSelf->stage_5__DOT__units_0__DOT__io_carry = vlSelf->stage_5__DOT___units_0_io_carry;
    vlSelf->_stage_6_io_out_1 = (0x3fffU & VL_SHIFTL_III(14,14,32, (IData)(vlSelf->stage_5__DOT___units_0_io_carry), 1U));
    vlSelf->stage_5__DOT__io_out_0 = vlSelf->_stage_5_io_out_0;
    vlSelf->stage_5__DOT__units_0__DOT__io_sum = vlSelf->_stage_5_io_out_0;
    vlSelf->stage_6__DOT__io_in_0 = vlSelf->_stage_5_io_out_0;
    vlSelf->_stage_6_io_out_0 = ((IData)(vlSelf->_stage_5_io_out_0) 
                                 ^ ((IData)(vlSelf->_stage_5_io_out_1) 
                                    ^ (IData)(vlSelf->_stage_5_io_out_2)));
    vlSelf->stage_6__DOT__units_0__DOT__io_carry = 
        (((IData)(vlSelf->_stage_5_io_out_0) & (IData)(vlSelf->_stage_5_io_out_1)) 
         | (((IData)(vlSelf->_stage_5_io_out_1) | (IData)(vlSelf->_stage_5_io_out_0)) 
            & (IData)(vlSelf->_stage_5_io_out_2)));
    vlSelf->stage_5__DOT__io_out_3 = vlSelf->_stage_6_io_out_1;
    vlSelf->stage_6__DOT__io_out_1 = vlSelf->_stage_6_io_out_1;
    vlSelf->stage_7__DOT__io_in_1 = vlSelf->_stage_6_io_out_1;
    vlSelf->_stage_5_io_out_3 = vlSelf->_stage_6_io_out_1;
    vlSelf->stage_6__DOT__units_0__DOT__io_in_0 = vlSelf->stage_6__DOT__io_in_0;
    vlSelf->stage_6__DOT__io_out_0 = vlSelf->_stage_6_io_out_0;
    vlSelf->stage_6__DOT__units_0__DOT__io_sum = vlSelf->_stage_6_io_out_0;
    vlSelf->stage_7__DOT__io_in_0 = vlSelf->_stage_6_io_out_0;
    vlSelf->stage_6__DOT___units_0_io_carry = vlSelf->stage_6__DOT__units_0__DOT__io_carry;
    vlSelf->_stage_6_io_out_2 = (0x3fffU & VL_SHIFTL_III(14,14,32, (IData)(vlSelf->stage_6__DOT__units_0__DOT__io_carry), 1U));
    vlSelf->stage_7__DOT__units_0__DOT__io_in_1 = vlSelf->stage_7__DOT__io_in_1;
    vlSelf->stage_6__DOT__io_in_3 = vlSelf->_stage_5_io_out_3;
    vlSelf->stage_7__DOT__units_0__DOT__io_in_0 = vlSelf->stage_7__DOT__io_in_0;
    vlSelf->stage_6__DOT__io_out_2 = vlSelf->_stage_6_io_out_2;
    vlSelf->stage_7__DOT__io_in_2 = vlSelf->_stage_6_io_out_2;
    vlSelf->io_out_0 = ((IData)(vlSelf->_stage_6_io_out_0) 
                        ^ ((IData)(vlSelf->_stage_6_io_out_1) 
                           ^ (IData)(vlSelf->_stage_6_io_out_2)));
    vlSelf->stage_7__DOT__units_0__DOT__io_carry = 
        (((IData)(vlSelf->_stage_6_io_out_0) & (IData)(vlSelf->_stage_6_io_out_1)) 
         | (((IData)(vlSelf->_stage_6_io_out_1) | (IData)(vlSelf->_stage_6_io_out_0)) 
            & (IData)(vlSelf->_stage_6_io_out_2)));
    vlSelf->stage_7__DOT__units_0__DOT__io_in_2 = vlSelf->stage_7__DOT__io_in_2;
    vlSelf->stage_7__DOT__io_out_0 = vlSelf->io_out_0;
    vlSelf->stage_7__DOT__units_0__DOT__io_sum = vlSelf->io_out_0;
    vlSelf->stage_7__DOT___units_0_io_carry = vlSelf->stage_7__DOT__units_0__DOT__io_carry;
    vlSelf->io_out_1 = (0x3fffU & VL_SHIFTL_III(14,14,32, (IData)(vlSelf->stage_7__DOT__units_0__DOT__io_carry), 1U));
    vlSelf->stage_7__DOT__io_out_1 = vlSelf->io_out_1;
}
