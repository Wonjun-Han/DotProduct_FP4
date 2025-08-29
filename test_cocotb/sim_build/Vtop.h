// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTOP_H_
#define VERILATED_VTOP_H_  // guard

#include "verilated.h"
#include "svdpi.h"

class Vtop__Syms;
class Vtop___024root;
class Vtop_p_FieldExtractor;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vtop VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vtop__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = false;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clock,0,0);
    VL_IN8(&reset,0,0);
    VL_IN8(&io_a_vec_0,3,0);
    VL_IN8(&io_a_vec_1,3,0);
    VL_IN8(&io_a_vec_2,3,0);
    VL_IN8(&io_a_vec_3,3,0);
    VL_IN8(&io_a_vec_4,3,0);
    VL_IN8(&io_a_vec_5,3,0);
    VL_IN8(&io_a_vec_6,3,0);
    VL_IN8(&io_a_vec_7,3,0);
    VL_IN8(&io_a_vec_8,3,0);
    VL_IN8(&io_a_vec_9,3,0);
    VL_IN8(&io_a_vec_10,3,0);
    VL_IN8(&io_a_vec_11,3,0);
    VL_IN8(&io_a_vec_12,3,0);
    VL_IN8(&io_a_vec_13,3,0);
    VL_IN8(&io_a_vec_14,3,0);
    VL_IN8(&io_a_vec_15,3,0);
    VL_IN8(&io_a_vec_16,3,0);
    VL_IN8(&io_a_vec_17,3,0);
    VL_IN8(&io_a_vec_18,3,0);
    VL_IN8(&io_a_vec_19,3,0);
    VL_IN8(&io_a_vec_20,3,0);
    VL_IN8(&io_a_vec_21,3,0);
    VL_IN8(&io_a_vec_22,3,0);
    VL_IN8(&io_a_vec_23,3,0);
    VL_IN8(&io_a_vec_24,3,0);
    VL_IN8(&io_a_vec_25,3,0);
    VL_IN8(&io_a_vec_26,3,0);
    VL_IN8(&io_a_vec_27,3,0);
    VL_IN8(&io_a_vec_28,3,0);
    VL_IN8(&io_a_vec_29,3,0);
    VL_IN8(&io_a_vec_30,3,0);
    VL_IN8(&io_a_vec_31,3,0);
    VL_IN8(&io_a_vec_32,3,0);
    VL_IN8(&io_a_vec_33,3,0);
    VL_IN8(&io_a_vec_34,3,0);
    VL_IN8(&io_a_vec_35,3,0);
    VL_IN8(&io_a_vec_36,3,0);
    VL_IN8(&io_a_vec_37,3,0);
    VL_IN8(&io_a_vec_38,3,0);
    VL_IN8(&io_a_vec_39,3,0);
    VL_IN8(&io_a_vec_40,3,0);
    VL_IN8(&io_a_vec_41,3,0);
    VL_IN8(&io_a_vec_42,3,0);
    VL_IN8(&io_a_vec_43,3,0);
    VL_IN8(&io_a_vec_44,3,0);
    VL_IN8(&io_a_vec_45,3,0);
    VL_IN8(&io_a_vec_46,3,0);
    VL_IN8(&io_a_vec_47,3,0);
    VL_IN8(&io_a_vec_48,3,0);
    VL_IN8(&io_a_vec_49,3,0);
    VL_IN8(&io_a_vec_50,3,0);
    VL_IN8(&io_a_vec_51,3,0);
    VL_IN8(&io_a_vec_52,3,0);
    VL_IN8(&io_a_vec_53,3,0);
    VL_IN8(&io_a_vec_54,3,0);
    VL_IN8(&io_a_vec_55,3,0);
    VL_IN8(&io_a_vec_56,3,0);
    VL_IN8(&io_a_vec_57,3,0);
    VL_IN8(&io_a_vec_58,3,0);
    VL_IN8(&io_a_vec_59,3,0);
    VL_IN8(&io_a_vec_60,3,0);
    VL_IN8(&io_a_vec_61,3,0);
    VL_IN8(&io_a_vec_62,3,0);
    VL_IN8(&io_a_vec_63,3,0);
    VL_IN8(&io_a_vec_64,3,0);
    VL_IN8(&io_a_vec_65,3,0);
    VL_IN8(&io_a_vec_66,3,0);
    VL_IN8(&io_a_vec_67,3,0);
    VL_IN8(&io_a_vec_68,3,0);
    VL_IN8(&io_a_vec_69,3,0);
    VL_IN8(&io_a_vec_70,3,0);
    VL_IN8(&io_a_vec_71,3,0);
    VL_IN8(&io_a_vec_72,3,0);
    VL_IN8(&io_a_vec_73,3,0);
    VL_IN8(&io_a_vec_74,3,0);
    VL_IN8(&io_a_vec_75,3,0);
    VL_IN8(&io_a_vec_76,3,0);
    VL_IN8(&io_a_vec_77,3,0);
    VL_IN8(&io_a_vec_78,3,0);
    VL_IN8(&io_a_vec_79,3,0);
    VL_IN8(&io_a_vec_80,3,0);
    VL_IN8(&io_a_vec_81,3,0);
    VL_IN8(&io_a_vec_82,3,0);
    VL_IN8(&io_a_vec_83,3,0);
    VL_IN8(&io_a_vec_84,3,0);
    VL_IN8(&io_a_vec_85,3,0);
    VL_IN8(&io_a_vec_86,3,0);
    VL_IN8(&io_a_vec_87,3,0);
    VL_IN8(&io_a_vec_88,3,0);
    VL_IN8(&io_a_vec_89,3,0);
    VL_IN8(&io_a_vec_90,3,0);
    VL_IN8(&io_a_vec_91,3,0);
    VL_IN8(&io_a_vec_92,3,0);
    VL_IN8(&io_a_vec_93,3,0);
    VL_IN8(&io_a_vec_94,3,0);
    VL_IN8(&io_a_vec_95,3,0);
    VL_IN8(&io_a_vec_96,3,0);
    VL_IN8(&io_a_vec_97,3,0);
    VL_IN8(&io_a_vec_98,3,0);
    VL_IN8(&io_a_vec_99,3,0);
    VL_IN8(&io_a_vec_100,3,0);
    VL_IN8(&io_a_vec_101,3,0);
    VL_IN8(&io_a_vec_102,3,0);
    VL_IN8(&io_a_vec_103,3,0);
    VL_IN8(&io_a_vec_104,3,0);
    VL_IN8(&io_a_vec_105,3,0);
    VL_IN8(&io_a_vec_106,3,0);
    VL_IN8(&io_a_vec_107,3,0);
    VL_IN8(&io_a_vec_108,3,0);
    VL_IN8(&io_a_vec_109,3,0);
    VL_IN8(&io_a_vec_110,3,0);
    VL_IN8(&io_a_vec_111,3,0);
    VL_IN8(&io_a_vec_112,3,0);
    VL_IN8(&io_a_vec_113,3,0);
    VL_IN8(&io_a_vec_114,3,0);
    VL_IN8(&io_a_vec_115,3,0);
    VL_IN8(&io_a_vec_116,3,0);
    VL_IN8(&io_a_vec_117,3,0);
    VL_IN8(&io_a_vec_118,3,0);
    VL_IN8(&io_a_vec_119,3,0);
    VL_IN8(&io_a_vec_120,3,0);
    VL_IN8(&io_a_vec_121,3,0);
    VL_IN8(&io_a_vec_122,3,0);
    VL_IN8(&io_a_vec_123,3,0);
    VL_IN8(&io_a_vec_124,3,0);
    VL_IN8(&io_a_vec_125,3,0);
    VL_IN8(&io_a_vec_126,3,0);
    VL_IN8(&io_a_vec_127,3,0);
    VL_IN8(&io_a_vec_128,3,0);
    VL_IN8(&io_a_vec_129,3,0);
    VL_IN8(&io_a_vec_130,3,0);
    VL_IN8(&io_a_vec_131,3,0);
    VL_IN8(&io_a_vec_132,3,0);
    VL_IN8(&io_a_vec_133,3,0);
    VL_IN8(&io_a_vec_134,3,0);
    VL_IN8(&io_a_vec_135,3,0);
    VL_IN8(&io_a_vec_136,3,0);
    VL_IN8(&io_a_vec_137,3,0);
    VL_IN8(&io_a_vec_138,3,0);
    VL_IN8(&io_a_vec_139,3,0);
    VL_IN8(&io_a_vec_140,3,0);
    VL_IN8(&io_a_vec_141,3,0);
    VL_IN8(&io_a_vec_142,3,0);
    VL_IN8(&io_a_vec_143,3,0);
    VL_IN8(&io_a_vec_144,3,0);
    VL_IN8(&io_a_vec_145,3,0);
    VL_IN8(&io_a_vec_146,3,0);
    VL_IN8(&io_a_vec_147,3,0);
    VL_IN8(&io_a_vec_148,3,0);
    VL_IN8(&io_a_vec_149,3,0);
    VL_IN8(&io_a_vec_150,3,0);
    VL_IN8(&io_a_vec_151,3,0);
    VL_IN8(&io_a_vec_152,3,0);
    VL_IN8(&io_a_vec_153,3,0);
    VL_IN8(&io_a_vec_154,3,0);
    VL_IN8(&io_a_vec_155,3,0);
    VL_IN8(&io_a_vec_156,3,0);
    VL_IN8(&io_a_vec_157,3,0);
    VL_IN8(&io_a_vec_158,3,0);
    VL_IN8(&io_a_vec_159,3,0);
    VL_IN8(&io_a_vec_160,3,0);
    VL_IN8(&io_a_vec_161,3,0);
    VL_IN8(&io_a_vec_162,3,0);
    VL_IN8(&io_a_vec_163,3,0);
    VL_IN8(&io_a_vec_164,3,0);
    VL_IN8(&io_a_vec_165,3,0);
    VL_IN8(&io_a_vec_166,3,0);
    VL_IN8(&io_a_vec_167,3,0);
    VL_IN8(&io_a_vec_168,3,0);
    VL_IN8(&io_a_vec_169,3,0);
    VL_IN8(&io_a_vec_170,3,0);
    VL_IN8(&io_a_vec_171,3,0);
    VL_IN8(&io_a_vec_172,3,0);
    VL_IN8(&io_a_vec_173,3,0);
    VL_IN8(&io_a_vec_174,3,0);
    VL_IN8(&io_a_vec_175,3,0);
    VL_IN8(&io_a_vec_176,3,0);
    VL_IN8(&io_a_vec_177,3,0);
    VL_IN8(&io_a_vec_178,3,0);
    VL_IN8(&io_a_vec_179,3,0);
    VL_IN8(&io_a_vec_180,3,0);
    VL_IN8(&io_a_vec_181,3,0);
    VL_IN8(&io_a_vec_182,3,0);
    VL_IN8(&io_a_vec_183,3,0);
    VL_IN8(&io_a_vec_184,3,0);
    VL_IN8(&io_a_vec_185,3,0);
    VL_IN8(&io_a_vec_186,3,0);
    VL_IN8(&io_a_vec_187,3,0);
    VL_IN8(&io_a_vec_188,3,0);
    VL_IN8(&io_a_vec_189,3,0);
    VL_IN8(&io_a_vec_190,3,0);
    VL_IN8(&io_a_vec_191,3,0);
    VL_IN8(&io_a_vec_192,3,0);
    VL_IN8(&io_a_vec_193,3,0);
    VL_IN8(&io_a_vec_194,3,0);
    VL_IN8(&io_a_vec_195,3,0);
    VL_IN8(&io_a_vec_196,3,0);
    VL_IN8(&io_a_vec_197,3,0);
    VL_IN8(&io_a_vec_198,3,0);
    VL_IN8(&io_a_vec_199,3,0);
    VL_IN8(&io_a_vec_200,3,0);
    VL_IN8(&io_a_vec_201,3,0);
    VL_IN8(&io_a_vec_202,3,0);
    VL_IN8(&io_a_vec_203,3,0);
    VL_IN8(&io_a_vec_204,3,0);
    VL_IN8(&io_a_vec_205,3,0);
    VL_IN8(&io_a_vec_206,3,0);
    VL_IN8(&io_a_vec_207,3,0);
    VL_IN8(&io_a_vec_208,3,0);
    VL_IN8(&io_a_vec_209,3,0);
    VL_IN8(&io_a_vec_210,3,0);
    VL_IN8(&io_a_vec_211,3,0);
    VL_IN8(&io_a_vec_212,3,0);
    VL_IN8(&io_a_vec_213,3,0);
    VL_IN8(&io_a_vec_214,3,0);
    VL_IN8(&io_a_vec_215,3,0);
    VL_IN8(&io_a_vec_216,3,0);
    VL_IN8(&io_a_vec_217,3,0);
    VL_IN8(&io_a_vec_218,3,0);
    VL_IN8(&io_a_vec_219,3,0);
    VL_IN8(&io_a_vec_220,3,0);
    VL_IN8(&io_a_vec_221,3,0);
    VL_IN8(&io_a_vec_222,3,0);
    VL_IN8(&io_a_vec_223,3,0);
    VL_IN8(&io_a_vec_224,3,0);
    VL_IN8(&io_a_vec_225,3,0);
    VL_IN8(&io_a_vec_226,3,0);
    VL_IN8(&io_a_vec_227,3,0);
    VL_IN8(&io_a_vec_228,3,0);
    VL_IN8(&io_a_vec_229,3,0);
    VL_IN8(&io_a_vec_230,3,0);
    VL_IN8(&io_a_vec_231,3,0);
    VL_IN8(&io_a_vec_232,3,0);
    VL_IN8(&io_a_vec_233,3,0);
    VL_IN8(&io_a_vec_234,3,0);
    VL_IN8(&io_a_vec_235,3,0);
    VL_IN8(&io_a_vec_236,3,0);
    VL_IN8(&io_a_vec_237,3,0);
    VL_IN8(&io_a_vec_238,3,0);
    VL_IN8(&io_a_vec_239,3,0);
    VL_IN8(&io_a_vec_240,3,0);
    VL_IN8(&io_a_vec_241,3,0);
    VL_IN8(&io_a_vec_242,3,0);
    VL_IN8(&io_a_vec_243,3,0);
    VL_IN8(&io_a_vec_244,3,0);
    VL_IN8(&io_a_vec_245,3,0);
    VL_IN8(&io_a_vec_246,3,0);
    VL_IN8(&io_a_vec_247,3,0);
    VL_IN8(&io_a_vec_248,3,0);
    VL_IN8(&io_a_vec_249,3,0);
    VL_IN8(&io_a_vec_250,3,0);
    VL_IN8(&io_a_vec_251,3,0);
    VL_IN8(&io_a_vec_252,3,0);
    VL_IN8(&io_a_vec_253,3,0);
    VL_IN8(&io_a_vec_254,3,0);
    VL_IN8(&io_a_vec_255,3,0);
    VL_IN8(&io_b_vec_0,3,0);
    VL_IN8(&io_b_vec_1,3,0);
    VL_IN8(&io_b_vec_2,3,0);
    VL_IN8(&io_b_vec_3,3,0);
    VL_IN8(&io_b_vec_4,3,0);
    VL_IN8(&io_b_vec_5,3,0);
    VL_IN8(&io_b_vec_6,3,0);
    VL_IN8(&io_b_vec_7,3,0);
    VL_IN8(&io_b_vec_8,3,0);
    VL_IN8(&io_b_vec_9,3,0);
    VL_IN8(&io_b_vec_10,3,0);
    VL_IN8(&io_b_vec_11,3,0);
    VL_IN8(&io_b_vec_12,3,0);
    VL_IN8(&io_b_vec_13,3,0);
    VL_IN8(&io_b_vec_14,3,0);
    VL_IN8(&io_b_vec_15,3,0);
    VL_IN8(&io_b_vec_16,3,0);
    VL_IN8(&io_b_vec_17,3,0);
    VL_IN8(&io_b_vec_18,3,0);
    VL_IN8(&io_b_vec_19,3,0);
    VL_IN8(&io_b_vec_20,3,0);
    VL_IN8(&io_b_vec_21,3,0);
    VL_IN8(&io_b_vec_22,3,0);
    VL_IN8(&io_b_vec_23,3,0);
    VL_IN8(&io_b_vec_24,3,0);
    VL_IN8(&io_b_vec_25,3,0);
    VL_IN8(&io_b_vec_26,3,0);
    VL_IN8(&io_b_vec_27,3,0);
    VL_IN8(&io_b_vec_28,3,0);
    VL_IN8(&io_b_vec_29,3,0);
    VL_IN8(&io_b_vec_30,3,0);
    VL_IN8(&io_b_vec_31,3,0);
    VL_IN8(&io_b_vec_32,3,0);
    VL_IN8(&io_b_vec_33,3,0);
    VL_IN8(&io_b_vec_34,3,0);
    VL_IN8(&io_b_vec_35,3,0);
    VL_IN8(&io_b_vec_36,3,0);
    VL_IN8(&io_b_vec_37,3,0);
    VL_IN8(&io_b_vec_38,3,0);
    VL_IN8(&io_b_vec_39,3,0);
    VL_IN8(&io_b_vec_40,3,0);
    VL_IN8(&io_b_vec_41,3,0);
    VL_IN8(&io_b_vec_42,3,0);
    VL_IN8(&io_b_vec_43,3,0);
    VL_IN8(&io_b_vec_44,3,0);
    VL_IN8(&io_b_vec_45,3,0);
    VL_IN8(&io_b_vec_46,3,0);
    VL_IN8(&io_b_vec_47,3,0);
    VL_IN8(&io_b_vec_48,3,0);
    VL_IN8(&io_b_vec_49,3,0);
    VL_IN8(&io_b_vec_50,3,0);
    VL_IN8(&io_b_vec_51,3,0);
    VL_IN8(&io_b_vec_52,3,0);
    VL_IN8(&io_b_vec_53,3,0);
    VL_IN8(&io_b_vec_54,3,0);
    VL_IN8(&io_b_vec_55,3,0);
    VL_IN8(&io_b_vec_56,3,0);
    VL_IN8(&io_b_vec_57,3,0);
    VL_IN8(&io_b_vec_58,3,0);
    VL_IN8(&io_b_vec_59,3,0);
    VL_IN8(&io_b_vec_60,3,0);
    VL_IN8(&io_b_vec_61,3,0);
    VL_IN8(&io_b_vec_62,3,0);
    VL_IN8(&io_b_vec_63,3,0);
    VL_IN8(&io_b_vec_64,3,0);
    VL_IN8(&io_b_vec_65,3,0);
    VL_IN8(&io_b_vec_66,3,0);
    VL_IN8(&io_b_vec_67,3,0);
    VL_IN8(&io_b_vec_68,3,0);
    VL_IN8(&io_b_vec_69,3,0);
    VL_IN8(&io_b_vec_70,3,0);
    VL_IN8(&io_b_vec_71,3,0);
    VL_IN8(&io_b_vec_72,3,0);
    VL_IN8(&io_b_vec_73,3,0);
    VL_IN8(&io_b_vec_74,3,0);
    VL_IN8(&io_b_vec_75,3,0);
    VL_IN8(&io_b_vec_76,3,0);
    VL_IN8(&io_b_vec_77,3,0);
    VL_IN8(&io_b_vec_78,3,0);
    VL_IN8(&io_b_vec_79,3,0);
    VL_IN8(&io_b_vec_80,3,0);
    VL_IN8(&io_b_vec_81,3,0);
    VL_IN8(&io_b_vec_82,3,0);
    VL_IN8(&io_b_vec_83,3,0);
    VL_IN8(&io_b_vec_84,3,0);
    VL_IN8(&io_b_vec_85,3,0);
    VL_IN8(&io_b_vec_86,3,0);
    VL_IN8(&io_b_vec_87,3,0);
    VL_IN8(&io_b_vec_88,3,0);
    VL_IN8(&io_b_vec_89,3,0);
    VL_IN8(&io_b_vec_90,3,0);
    VL_IN8(&io_b_vec_91,3,0);
    VL_IN8(&io_b_vec_92,3,0);
    VL_IN8(&io_b_vec_93,3,0);
    VL_IN8(&io_b_vec_94,3,0);
    VL_IN8(&io_b_vec_95,3,0);
    VL_IN8(&io_b_vec_96,3,0);
    VL_IN8(&io_b_vec_97,3,0);
    VL_IN8(&io_b_vec_98,3,0);
    VL_IN8(&io_b_vec_99,3,0);
    VL_IN8(&io_b_vec_100,3,0);
    VL_IN8(&io_b_vec_101,3,0);
    VL_IN8(&io_b_vec_102,3,0);
    VL_IN8(&io_b_vec_103,3,0);
    VL_IN8(&io_b_vec_104,3,0);
    VL_IN8(&io_b_vec_105,3,0);
    VL_IN8(&io_b_vec_106,3,0);
    VL_IN8(&io_b_vec_107,3,0);
    VL_IN8(&io_b_vec_108,3,0);
    VL_IN8(&io_b_vec_109,3,0);
    VL_IN8(&io_b_vec_110,3,0);
    VL_IN8(&io_b_vec_111,3,0);
    VL_IN8(&io_b_vec_112,3,0);
    VL_IN8(&io_b_vec_113,3,0);
    VL_IN8(&io_b_vec_114,3,0);
    VL_IN8(&io_b_vec_115,3,0);
    VL_IN8(&io_b_vec_116,3,0);
    VL_IN8(&io_b_vec_117,3,0);
    VL_IN8(&io_b_vec_118,3,0);
    VL_IN8(&io_b_vec_119,3,0);
    VL_IN8(&io_b_vec_120,3,0);
    VL_IN8(&io_b_vec_121,3,0);
    VL_IN8(&io_b_vec_122,3,0);
    VL_IN8(&io_b_vec_123,3,0);
    VL_IN8(&io_b_vec_124,3,0);
    VL_IN8(&io_b_vec_125,3,0);
    VL_IN8(&io_b_vec_126,3,0);
    VL_IN8(&io_b_vec_127,3,0);
    VL_IN8(&io_b_vec_128,3,0);
    VL_IN8(&io_b_vec_129,3,0);
    VL_IN8(&io_b_vec_130,3,0);
    VL_IN8(&io_b_vec_131,3,0);
    VL_IN8(&io_b_vec_132,3,0);
    VL_IN8(&io_b_vec_133,3,0);
    VL_IN8(&io_b_vec_134,3,0);
    VL_IN8(&io_b_vec_135,3,0);
    VL_IN8(&io_b_vec_136,3,0);
    VL_IN8(&io_b_vec_137,3,0);
    VL_IN8(&io_b_vec_138,3,0);
    VL_IN8(&io_b_vec_139,3,0);
    VL_IN8(&io_b_vec_140,3,0);
    VL_IN8(&io_b_vec_141,3,0);
    VL_IN8(&io_b_vec_142,3,0);
    VL_IN8(&io_b_vec_143,3,0);
    VL_IN8(&io_b_vec_144,3,0);
    VL_IN8(&io_b_vec_145,3,0);
    VL_IN8(&io_b_vec_146,3,0);
    VL_IN8(&io_b_vec_147,3,0);
    VL_IN8(&io_b_vec_148,3,0);
    VL_IN8(&io_b_vec_149,3,0);
    VL_IN8(&io_b_vec_150,3,0);
    VL_IN8(&io_b_vec_151,3,0);
    VL_IN8(&io_b_vec_152,3,0);
    VL_IN8(&io_b_vec_153,3,0);
    VL_IN8(&io_b_vec_154,3,0);
    VL_IN8(&io_b_vec_155,3,0);
    VL_IN8(&io_b_vec_156,3,0);
    VL_IN8(&io_b_vec_157,3,0);
    VL_IN8(&io_b_vec_158,3,0);
    VL_IN8(&io_b_vec_159,3,0);
    VL_IN8(&io_b_vec_160,3,0);
    VL_IN8(&io_b_vec_161,3,0);
    VL_IN8(&io_b_vec_162,3,0);
    VL_IN8(&io_b_vec_163,3,0);
    VL_IN8(&io_b_vec_164,3,0);
    VL_IN8(&io_b_vec_165,3,0);
    VL_IN8(&io_b_vec_166,3,0);
    VL_IN8(&io_b_vec_167,3,0);
    VL_IN8(&io_b_vec_168,3,0);
    VL_IN8(&io_b_vec_169,3,0);
    VL_IN8(&io_b_vec_170,3,0);
    VL_IN8(&io_b_vec_171,3,0);
    VL_IN8(&io_b_vec_172,3,0);
    VL_IN8(&io_b_vec_173,3,0);
    VL_IN8(&io_b_vec_174,3,0);
    VL_IN8(&io_b_vec_175,3,0);
    VL_IN8(&io_b_vec_176,3,0);
    VL_IN8(&io_b_vec_177,3,0);
    VL_IN8(&io_b_vec_178,3,0);
    VL_IN8(&io_b_vec_179,3,0);
    VL_IN8(&io_b_vec_180,3,0);
    VL_IN8(&io_b_vec_181,3,0);
    VL_IN8(&io_b_vec_182,3,0);
    VL_IN8(&io_b_vec_183,3,0);
    VL_IN8(&io_b_vec_184,3,0);
    VL_IN8(&io_b_vec_185,3,0);
    VL_IN8(&io_b_vec_186,3,0);
    VL_IN8(&io_b_vec_187,3,0);
    VL_IN8(&io_b_vec_188,3,0);
    VL_IN8(&io_b_vec_189,3,0);
    VL_IN8(&io_b_vec_190,3,0);
    VL_IN8(&io_b_vec_191,3,0);
    VL_IN8(&io_b_vec_192,3,0);
    VL_IN8(&io_b_vec_193,3,0);
    VL_IN8(&io_b_vec_194,3,0);
    VL_IN8(&io_b_vec_195,3,0);
    VL_IN8(&io_b_vec_196,3,0);
    VL_IN8(&io_b_vec_197,3,0);
    VL_IN8(&io_b_vec_198,3,0);
    VL_IN8(&io_b_vec_199,3,0);
    VL_IN8(&io_b_vec_200,3,0);
    VL_IN8(&io_b_vec_201,3,0);
    VL_IN8(&io_b_vec_202,3,0);
    VL_IN8(&io_b_vec_203,3,0);
    VL_IN8(&io_b_vec_204,3,0);
    VL_IN8(&io_b_vec_205,3,0);
    VL_IN8(&io_b_vec_206,3,0);
    VL_IN8(&io_b_vec_207,3,0);
    VL_IN8(&io_b_vec_208,3,0);
    VL_IN8(&io_b_vec_209,3,0);
    VL_IN8(&io_b_vec_210,3,0);
    VL_IN8(&io_b_vec_211,3,0);
    VL_IN8(&io_b_vec_212,3,0);
    VL_IN8(&io_b_vec_213,3,0);
    VL_IN8(&io_b_vec_214,3,0);
    VL_IN8(&io_b_vec_215,3,0);
    VL_IN8(&io_b_vec_216,3,0);
    VL_IN8(&io_b_vec_217,3,0);
    VL_IN8(&io_b_vec_218,3,0);
    VL_IN8(&io_b_vec_219,3,0);
    VL_IN8(&io_b_vec_220,3,0);
    VL_IN8(&io_b_vec_221,3,0);
    VL_IN8(&io_b_vec_222,3,0);
    VL_IN8(&io_b_vec_223,3,0);
    VL_IN8(&io_b_vec_224,3,0);
    VL_IN8(&io_b_vec_225,3,0);
    VL_IN8(&io_b_vec_226,3,0);
    VL_IN8(&io_b_vec_227,3,0);
    VL_IN8(&io_b_vec_228,3,0);
    VL_IN8(&io_b_vec_229,3,0);
    VL_IN8(&io_b_vec_230,3,0);
    VL_IN8(&io_b_vec_231,3,0);
    VL_IN8(&io_b_vec_232,3,0);
    VL_IN8(&io_b_vec_233,3,0);
    VL_IN8(&io_b_vec_234,3,0);
    VL_IN8(&io_b_vec_235,3,0);
    VL_IN8(&io_b_vec_236,3,0);
    VL_IN8(&io_b_vec_237,3,0);
    VL_IN8(&io_b_vec_238,3,0);
    VL_IN8(&io_b_vec_239,3,0);
    VL_IN8(&io_b_vec_240,3,0);
    VL_IN8(&io_b_vec_241,3,0);
    VL_IN8(&io_b_vec_242,3,0);
    VL_IN8(&io_b_vec_243,3,0);
    VL_IN8(&io_b_vec_244,3,0);
    VL_IN8(&io_b_vec_245,3,0);
    VL_IN8(&io_b_vec_246,3,0);
    VL_IN8(&io_b_vec_247,3,0);
    VL_IN8(&io_b_vec_248,3,0);
    VL_IN8(&io_b_vec_249,3,0);
    VL_IN8(&io_b_vec_250,3,0);
    VL_IN8(&io_b_vec_251,3,0);
    VL_IN8(&io_b_vec_252,3,0);
    VL_IN8(&io_b_vec_253,3,0);
    VL_IN8(&io_b_vec_254,3,0);
    VL_IN8(&io_b_vec_255,3,0);
    VL_IN8(&io_a_scale_0,7,0);
    VL_IN8(&io_a_scale_1,7,0);
    VL_IN8(&io_a_scale_2,7,0);
    VL_IN8(&io_a_scale_3,7,0);
    VL_IN8(&io_a_scale_4,7,0);
    VL_IN8(&io_a_scale_5,7,0);
    VL_IN8(&io_a_scale_6,7,0);
    VL_IN8(&io_a_scale_7,7,0);
    VL_IN8(&io_b_scale_0,7,0);
    VL_IN8(&io_b_scale_1,7,0);
    VL_IN8(&io_b_scale_2,7,0);
    VL_IN8(&io_b_scale_3,7,0);
    VL_IN8(&io_b_scale_4,7,0);
    VL_IN8(&io_b_scale_5,7,0);
    VL_IN8(&io_b_scale_6,7,0);
    VL_IN8(&io_b_scale_7,7,0);
    VL_IN8(&io_depth,3,0);
    VL_OUT8(&io_out_0_sign,0,0);
    VL_OUT8(&io_out_0_exponent,7,0);
    VL_OUT8(&io_out_1_sign,0,0);
    VL_OUT8(&io_out_1_exponent,7,0);
    VL_OUT8(&io_out_2_sign,0,0);
    VL_OUT8(&io_out_2_exponent,7,0);
    VL_OUT8(&io_out_3_sign,0,0);
    VL_OUT8(&io_out_3_exponent,7,0);
    VL_OUT8(&io_out_4_sign,0,0);
    VL_OUT8(&io_out_4_exponent,7,0);
    VL_OUT8(&io_out_5_sign,0,0);
    VL_OUT8(&io_out_5_exponent,7,0);
    VL_OUT8(&io_out_6_sign,0,0);
    VL_OUT8(&io_out_6_exponent,7,0);
    VL_OUT8(&io_out_7_sign,0,0);
    VL_OUT8(&io_out_7_exponent,7,0);
    VL_OUT8(&io_out_8_sign,0,0);
    VL_OUT8(&io_out_8_exponent,7,0);
    VL_OUT8(&io_out_9_sign,0,0);
    VL_OUT8(&io_out_9_exponent,7,0);
    VL_OUT8(&io_out_10_sign,0,0);
    VL_OUT8(&io_out_10_exponent,7,0);
    VL_OUT8(&io_out_11_sign,0,0);
    VL_OUT8(&io_out_11_exponent,7,0);
    VL_OUT8(&io_out_12_sign,0,0);
    VL_OUT8(&io_out_12_exponent,7,0);
    VL_OUT8(&io_out_13_sign,0,0);
    VL_OUT8(&io_out_13_exponent,7,0);
    VL_OUT8(&io_out_14_sign,0,0);
    VL_OUT8(&io_out_14_exponent,7,0);
    VL_OUT8(&io_out_15_sign,0,0);
    VL_OUT8(&io_out_15_exponent,7,0);
    VL_OUT(&io_out_0_mantissa,22,0);
    VL_OUT(&io_out_1_mantissa,22,0);
    VL_OUT(&io_out_2_mantissa,22,0);
    VL_OUT(&io_out_3_mantissa,22,0);
    VL_OUT(&io_out_4_mantissa,22,0);
    VL_OUT(&io_out_5_mantissa,22,0);
    VL_OUT(&io_out_6_mantissa,22,0);
    VL_OUT(&io_out_7_mantissa,22,0);
    VL_OUT(&io_out_8_mantissa,22,0);
    VL_OUT(&io_out_9_mantissa,22,0);
    VL_OUT(&io_out_10_mantissa,22,0);
    VL_OUT(&io_out_11_mantissa,22,0);
    VL_OUT(&io_out_12_mantissa,22,0);
    VL_OUT(&io_out_13_mantissa,22,0);
    VL_OUT(&io_out_14_mantissa,22,0);
    VL_OUT(&io_out_15_mantissa,22,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    Vtop_p_FieldExtractor* const __PVT__p_TOP_Til_Dep_total_piped_CT_syn_RCA__DOT__mult__DOT__a_extractor;
    Vtop_p_FieldExtractor* const __PVT__p_TOP_Til_Dep_total_piped_CT_syn_RCA__DOT__mult__DOT__b_extractor;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vtop___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vtop(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vtop();
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard
