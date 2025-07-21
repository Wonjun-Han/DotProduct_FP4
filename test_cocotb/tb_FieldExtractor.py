import cocotb
from cocotb.triggers import Timer

@cocotb.test()
async def test_fieldextractor(dut):
    dut.io_in_vec_0.value = 0b0111  # TODO: Set proper test value
    dut.io_in_vec_1.value = 0b1001  # TODO: Set proper test value
    dut.io_in_vec_2.value = 0b1101  # TODO: Set proper test value
    dut.io_in_vec_3.value = 0b1010  # TODO: Set proper test value
    dut.io_in_vec_4.value = 0  # TODO: Set proper test value
    dut.io_in_vec_5.value = 0  # TODO: Set proper test value
    dut.io_in_vec_6.value = 0  # TODO: Set proper test value
    dut.io_in_vec_7.value = 0  # TODO: Set proper test value
    dut.io_in_vec_8.value = 0  # TODO: Set proper test value
    dut.io_in_vec_9.value = 0  # TODO: Set proper test value
    dut.io_in_vec_10.value = 0  # TODO: Set proper test value
    dut.io_in_vec_11.value = 0  # TODO: Set proper test value
    dut.io_in_vec_12.value = 0  # TODO: Set proper test value
    dut.io_in_vec_13.value = 0  # TODO: Set proper test value
    dut.io_in_vec_14.value = 0  # TODO: Set proper test value
    dut.io_in_vec_15.value = 0  # TODO: Set proper test value
    dut.io_in_vec_16.value = 0  # TODO: Set proper test value
    dut.io_in_vec_17.value = 0  # TODO: Set proper test value
    dut.io_in_vec_18.value = 0  # TODO: Set proper test value
    dut.io_in_vec_19.value = 0  # TODO: Set proper test value
    dut.io_in_vec_20.value = 0  # TODO: Set proper test value
    dut.io_in_vec_21.value = 0  # TODO: Set proper test value
    dut.io_in_vec_22.value = 0  # TODO: Set proper test value
    dut.io_in_vec_23.value = 0  # TODO: Set proper test value
    dut.io_in_vec_24.value = 0  # TODO: Set proper test value
    dut.io_in_vec_25.value = 0  # TODO: Set proper test value
    dut.io_in_vec_26.value = 0  # TODO: Set proper test value
    dut.io_in_vec_27.value = 0  # TODO: Set proper test value
    dut.io_in_vec_28.value = 0  # TODO: Set proper test value
    dut.io_in_vec_29.value = 0  # TODO: Set proper test value
    dut.io_in_vec_30.value = 0  # TODO: Set proper test value
    dut.io_in_vec_31.value = 0  # TODO: Set proper test value
    dut.io_in_vec_32.value = 0  # TODO: Set proper test value
    dut.io_in_vec_33.value = 0  # TODO: Set proper test value
    dut.io_in_vec_34.value = 0  # TODO: Set proper test value
    dut.io_in_vec_35.value = 0  # TODO: Set proper test value
    dut.io_in_vec_36.value = 0  # TODO: Set proper test value
    dut.io_in_vec_37.value = 0  # TODO: Set proper test value
    dut.io_in_vec_38.value = 0  # TODO: Set proper test value
    dut.io_in_vec_39.value = 0  # TODO: Set proper test value
    dut.io_in_vec_40.value = 0  # TODO: Set proper test value
    dut.io_in_vec_41.value = 0  # TODO: Set proper test value
    dut.io_in_vec_42.value = 0  # TODO: Set proper test value
    dut.io_in_vec_43.value = 0  # TODO: Set proper test value
    dut.io_in_vec_44.value = 0  # TODO: Set proper test value
    dut.io_in_vec_45.value = 0  # TODO: Set proper test value
    dut.io_in_vec_46.value = 0  # TODO: Set proper test value
    dut.io_in_vec_47.value = 0  # TODO: Set proper test value
    dut.io_in_vec_48.value = 0  # TODO: Set proper test value
    dut.io_in_vec_49.value = 0  # TODO: Set proper test value
    dut.io_in_vec_50.value = 0  # TODO: Set proper test value
    dut.io_in_vec_51.value = 0  # TODO: Set proper test value
    dut.io_in_vec_52.value = 0  # TODO: Set proper test value
    dut.io_in_vec_53.value = 0  # TODO: Set proper test value
    dut.io_in_vec_54.value = 0  # TODO: Set proper test value
    dut.io_in_vec_55.value = 0  # TODO: Set proper test value
    dut.io_in_vec_56.value = 0  # TODO: Set proper test value
    dut.io_in_vec_57.value = 0  # TODO: Set proper test value
    dut.io_in_vec_58.value = 0  # TODO: Set proper test value
    dut.io_in_vec_59.value = 0  # TODO: Set proper test value
    dut.io_in_vec_60.value = 0  # TODO: Set proper test value
    dut.io_in_vec_61.value = 0  # TODO: Set proper test value
    dut.io_in_vec_62.value = 0  # TODO: Set proper test value
    dut.io_in_vec_63.value = 0  # TODO: Set proper test value
    dut.io_in_vec_64.value = 0  # TODO: Set proper test value
    dut.io_in_vec_65.value = 0  # TODO: Set proper test value
    dut.io_in_vec_66.value = 0  # TODO: Set proper test value
    dut.io_in_vec_67.value = 0  # TODO: Set proper test value
    dut.io_in_vec_68.value = 0  # TODO: Set proper test value
    dut.io_in_vec_69.value = 0  # TODO: Set proper test value
    dut.io_in_vec_70.value = 0  # TODO: Set proper test value
    dut.io_in_vec_71.value = 0  # TODO: Set proper test value
    dut.io_in_vec_72.value = 0  # TODO: Set proper test value
    dut.io_in_vec_73.value = 0  # TODO: Set proper test value
    dut.io_in_vec_74.value = 0  # TODO: Set proper test value
    dut.io_in_vec_75.value = 0  # TODO: Set proper test value
    dut.io_in_vec_76.value = 0  # TODO: Set proper test value
    dut.io_in_vec_77.value = 0  # TODO: Set proper test value
    dut.io_in_vec_78.value = 0  # TODO: Set proper test value
    dut.io_in_vec_79.value = 0  # TODO: Set proper test value
    dut.io_in_vec_80.value = 0  # TODO: Set proper test value
    dut.io_in_vec_81.value = 0  # TODO: Set proper test value
    dut.io_in_vec_82.value = 0  # TODO: Set proper test value
    dut.io_in_vec_83.value = 0  # TODO: Set proper test value
    dut.io_in_vec_84.value = 0  # TODO: Set proper test value
    dut.io_in_vec_85.value = 0  # TODO: Set proper test value
    dut.io_in_vec_86.value = 0  # TODO: Set proper test value
    dut.io_in_vec_87.value = 0  # TODO: Set proper test value
    dut.io_in_vec_88.value = 0  # TODO: Set proper test value
    dut.io_in_vec_89.value = 0  # TODO: Set proper test value
    dut.io_in_vec_90.value = 0  # TODO: Set proper test value
    dut.io_in_vec_91.value = 0  # TODO: Set proper test value
    dut.io_in_vec_92.value = 0  # TODO: Set proper test value
    dut.io_in_vec_93.value = 0  # TODO: Set proper test value
    dut.io_in_vec_94.value = 0  # TODO: Set proper test value
    dut.io_in_vec_95.value = 0  # TODO: Set proper test value
    dut.io_in_vec_96.value = 0  # TODO: Set proper test value
    dut.io_in_vec_97.value = 0  # TODO: Set proper test value
    dut.io_in_vec_98.value = 0  # TODO: Set proper test value
    dut.io_in_vec_99.value = 0  # TODO: Set proper test value
    dut.io_in_vec_100.value = 0  # TODO: Set proper test value
    dut.io_in_vec_101.value = 0  # TODO: Set proper test value
    dut.io_in_vec_102.value = 0  # TODO: Set proper test value
    dut.io_in_vec_103.value = 0  # TODO: Set proper test value
    dut.io_in_vec_104.value = 0  # TODO: Set proper test value
    dut.io_in_vec_105.value = 0  # TODO: Set proper test value
    dut.io_in_vec_106.value = 0  # TODO: Set proper test value
    dut.io_in_vec_107.value = 0  # TODO: Set proper test value
    dut.io_in_vec_108.value = 0  # TODO: Set proper test value
    dut.io_in_vec_109.value = 0  # TODO: Set proper test value
    dut.io_in_vec_110.value = 0  # TODO: Set proper test value
    dut.io_in_vec_111.value = 0  # TODO: Set proper test value
    dut.io_in_vec_112.value = 0  # TODO: Set proper test value
    dut.io_in_vec_113.value = 0  # TODO: Set proper test value
    dut.io_in_vec_114.value = 0  # TODO: Set proper test value
    dut.io_in_vec_115.value = 0  # TODO: Set proper test value
    dut.io_in_vec_116.value = 0  # TODO: Set proper test value
    dut.io_in_vec_117.value = 0  # TODO: Set proper test value
    dut.io_in_vec_118.value = 0  # TODO: Set proper test value
    dut.io_in_vec_119.value = 0  # TODO: Set proper test value
    dut.io_in_vec_120.value = 0  # TODO: Set proper test value
    dut.io_in_vec_121.value = 0  # TODO: Set proper test value
    dut.io_in_vec_122.value = 0  # TODO: Set proper test value
    dut.io_in_vec_123.value = 0  # TODO: Set proper test value
    dut.io_in_vec_124.value = 0  # TODO: Set proper test value
    dut.io_in_vec_125.value = 0  # TODO: Set proper test value
    dut.io_in_vec_126.value = 0  # TODO: Set proper test value
    dut.io_in_vec_127.value = 0  # TODO: Set proper test value
    dut.io_in_vec_128.value = 0  # TODO: Set proper test value
    dut.io_in_vec_129.value = 0  # TODO: Set proper test value
    dut.io_in_vec_130.value = 0  # TODO: Set proper test value
    dut.io_in_vec_131.value = 0  # TODO: Set proper test value
    dut.io_in_vec_132.value = 0  # TODO: Set proper test value
    dut.io_in_vec_133.value = 0  # TODO: Set proper test value
    dut.io_in_vec_134.value = 0  # TODO: Set proper test value
    dut.io_in_vec_135.value = 0  # TODO: Set proper test value
    dut.io_in_vec_136.value = 0  # TODO: Set proper test value
    dut.io_in_vec_137.value = 0  # TODO: Set proper test value
    dut.io_in_vec_138.value = 0  # TODO: Set proper test value
    dut.io_in_vec_139.value = 0  # TODO: Set proper test value
    dut.io_in_vec_140.value = 0  # TODO: Set proper test value
    dut.io_in_vec_141.value = 0  # TODO: Set proper test value
    dut.io_in_vec_142.value = 0  # TODO: Set proper test value
    dut.io_in_vec_143.value = 0  # TODO: Set proper test value
    dut.io_in_vec_144.value = 0  # TODO: Set proper test value
    dut.io_in_vec_145.value = 0  # TODO: Set proper test value
    dut.io_in_vec_146.value = 0  # TODO: Set proper test value
    dut.io_in_vec_147.value = 0  # TODO: Set proper test value
    dut.io_in_vec_148.value = 0  # TODO: Set proper test value
    dut.io_in_vec_149.value = 0  # TODO: Set proper test value
    dut.io_in_vec_150.value = 0  # TODO: Set proper test value
    dut.io_in_vec_151.value = 0  # TODO: Set proper test value
    dut.io_in_vec_152.value = 0  # TODO: Set proper test value
    dut.io_in_vec_153.value = 0  # TODO: Set proper test value
    dut.io_in_vec_154.value = 0  # TODO: Set proper test value
    dut.io_in_vec_155.value = 0  # TODO: Set proper test value
    dut.io_in_vec_156.value = 0  # TODO: Set proper test value
    dut.io_in_vec_157.value = 0  # TODO: Set proper test value
    dut.io_in_vec_158.value = 0  # TODO: Set proper test value
    dut.io_in_vec_159.value = 0  # TODO: Set proper test value
    dut.io_in_vec_160.value = 0  # TODO: Set proper test value
    dut.io_in_vec_161.value = 0  # TODO: Set proper test value
    dut.io_in_vec_162.value = 0  # TODO: Set proper test value
    dut.io_in_vec_163.value = 0  # TODO: Set proper test value
    dut.io_in_vec_164.value = 0  # TODO: Set proper test value
    dut.io_in_vec_165.value = 0  # TODO: Set proper test value
    dut.io_in_vec_166.value = 0  # TODO: Set proper test value
    dut.io_in_vec_167.value = 0  # TODO: Set proper test value
    dut.io_in_vec_168.value = 0  # TODO: Set proper test value
    dut.io_in_vec_169.value = 0  # TODO: Set proper test value
    dut.io_in_vec_170.value = 0  # TODO: Set proper test value
    dut.io_in_vec_171.value = 0  # TODO: Set proper test value
    dut.io_in_vec_172.value = 0  # TODO: Set proper test value
    dut.io_in_vec_173.value = 0  # TODO: Set proper test value
    dut.io_in_vec_174.value = 0  # TODO: Set proper test value
    dut.io_in_vec_175.value = 0  # TODO: Set proper test value
    dut.io_in_vec_176.value = 0  # TODO: Set proper test value
    dut.io_in_vec_177.value = 0  # TODO: Set proper test value
    dut.io_in_vec_178.value = 0  # TODO: Set proper test value
    dut.io_in_vec_179.value = 0  # TODO: Set proper test value
    dut.io_in_vec_180.value = 0  # TODO: Set proper test value
    dut.io_in_vec_181.value = 0  # TODO: Set proper test value
    dut.io_in_vec_182.value = 0  # TODO: Set proper test value
    dut.io_in_vec_183.value = 0  # TODO: Set proper test value
    dut.io_in_vec_184.value = 0  # TODO: Set proper test value
    dut.io_in_vec_185.value = 0  # TODO: Set proper test value
    dut.io_in_vec_186.value = 0  # TODO: Set proper test value
    dut.io_in_vec_187.value = 0  # TODO: Set proper test value
    dut.io_in_vec_188.value = 0  # TODO: Set proper test value
    dut.io_in_vec_189.value = 0  # TODO: Set proper test value
    dut.io_in_vec_190.value = 0  # TODO: Set proper test value
    dut.io_in_vec_191.value = 0  # TODO: Set proper test value
    dut.io_in_vec_192.value = 0  # TODO: Set proper test value
    dut.io_in_vec_193.value = 0  # TODO: Set proper test value
    dut.io_in_vec_194.value = 0  # TODO: Set proper test value
    dut.io_in_vec_195.value = 0  # TODO: Set proper test value
    dut.io_in_vec_196.value = 0  # TODO: Set proper test value
    dut.io_in_vec_197.value = 0  # TODO: Set proper test value
    dut.io_in_vec_198.value = 0  # TODO: Set proper test value
    dut.io_in_vec_199.value = 0  # TODO: Set proper test value
    dut.io_in_vec_200.value = 0  # TODO: Set proper test value
    dut.io_in_vec_201.value = 0  # TODO: Set proper test value
    dut.io_in_vec_202.value = 0  # TODO: Set proper test value
    dut.io_in_vec_203.value = 0  # TODO: Set proper test value
    dut.io_in_vec_204.value = 0  # TODO: Set proper test value
    dut.io_in_vec_205.value = 0  # TODO: Set proper test value
    dut.io_in_vec_206.value = 0  # TODO: Set proper test value
    dut.io_in_vec_207.value = 0  # TODO: Set proper test value
    dut.io_in_vec_208.value = 0  # TODO: Set proper test value
    dut.io_in_vec_209.value = 0  # TODO: Set proper test value
    dut.io_in_vec_210.value = 0  # TODO: Set proper test value
    dut.io_in_vec_211.value = 0  # TODO: Set proper test value
    dut.io_in_vec_212.value = 0  # TODO: Set proper test value
    dut.io_in_vec_213.value = 0  # TODO: Set proper test value
    dut.io_in_vec_214.value = 0  # TODO: Set proper test value
    dut.io_in_vec_215.value = 0  # TODO: Set proper test value
    dut.io_in_vec_216.value = 0  # TODO: Set proper test value
    dut.io_in_vec_217.value = 0  # TODO: Set proper test value
    dut.io_in_vec_218.value = 0  # TODO: Set proper test value
    dut.io_in_vec_219.value = 0  # TODO: Set proper test value
    dut.io_in_vec_220.value = 0  # TODO: Set proper test value
    dut.io_in_vec_221.value = 0  # TODO: Set proper test value
    dut.io_in_vec_222.value = 0  # TODO: Set proper test value
    dut.io_in_vec_223.value = 0  # TODO: Set proper test value
    dut.io_in_vec_224.value = 0  # TODO: Set proper test value
    dut.io_in_vec_225.value = 0  # TODO: Set proper test value
    dut.io_in_vec_226.value = 0  # TODO: Set proper test value
    dut.io_in_vec_227.value = 0  # TODO: Set proper test value
    dut.io_in_vec_228.value = 0  # TODO: Set proper test value
    dut.io_in_vec_229.value = 0  # TODO: Set proper test value
    dut.io_in_vec_230.value = 0  # TODO: Set proper test value
    dut.io_in_vec_231.value = 0  # TODO: Set proper test value
    dut.io_in_vec_232.value = 0  # TODO: Set proper test value
    dut.io_in_vec_233.value = 0  # TODO: Set proper test value
    dut.io_in_vec_234.value = 0  # TODO: Set proper test value
    dut.io_in_vec_235.value = 0  # TODO: Set proper test value
    dut.io_in_vec_236.value = 0  # TODO: Set proper test value
    dut.io_in_vec_237.value = 0  # TODO: Set proper test value
    dut.io_in_vec_238.value = 0  # TODO: Set proper test value
    dut.io_in_vec_239.value = 0  # TODO: Set proper test value
    dut.io_in_vec_240.value = 0  # TODO: Set proper test value
    dut.io_in_vec_241.value = 0  # TODO: Set proper test value
    dut.io_in_vec_242.value = 0  # TODO: Set proper test value
    dut.io_in_vec_243.value = 0  # TODO: Set proper test value
    dut.io_in_vec_244.value = 0  # TODO: Set proper test value
    dut.io_in_vec_245.value = 0  # TODO: Set proper test value
    dut.io_in_vec_246.value = 0  # TODO: Set proper test value
    dut.io_in_vec_247.value = 0  # TODO: Set proper test value
    dut.io_in_vec_248.value = 0  # TODO: Set proper test value
    dut.io_in_vec_249.value = 0  # TODO: Set proper test value
    dut.io_in_vec_250.value = 0  # TODO: Set proper test value
    dut.io_in_vec_251.value = 0  # TODO: Set proper test value
    dut.io_in_vec_252.value = 0  # TODO: Set proper test value
    dut.io_in_vec_253.value = 0  # TODO: Set proper test value
    dut.io_in_vec_254.value = 0  # TODO: Set proper test value
    dut.io_in_vec_255.value = 0  # TODO: Set proper test value
    await Timer(1.0, units="ns")

    assert dut.io_out_vec_0_sign.value == "0", f"FieldExtractor failed: {dut.io_out_vec_0_sign.value}"
    assert dut.io_out_vec_0_exponent.value == "11", f"FieldExtractor failed: {dut.io_out_vec_0_exponent.value}"
    assert dut.io_out_vec_0_mantissa.value == "11", f"FieldExtractor failed: {dut.io_out_vec_0_mantissa.value}"
    assert dut.io_out_vec_1_sign.value == "1", f"FieldExtractor failed: {dut.io_out_vec_1_sign.value}"
    assert dut.io_out_vec_1_exponent.value == "00", f"FieldExtractor failed: {dut.io_out_vec_1_exponent.value}"
    assert dut.io_out_vec_1_mantissa.value == "01", f"FieldExtractor failed: {dut.io_out_vec_1_mantissa.value}"
    assert dut.io_out_vec_2_sign.value == "1", f"FieldExtractor failed: {dut.io_out_vec_2_sign.value}"
    assert dut.io_out_vec_2_exponent.value == "10", f"FieldExtractor failed: {dut.io_out_vec_2_exponent.value}"
    assert dut.io_out_vec_2_mantissa.value == "11", f"FieldExtractor failed: {dut.io_out_vec_2_mantissa.value}"
    assert dut.io_out_vec_3_sign.value == "1", f"FieldExtractor failed: {dut.io_out_vec_3_sign.value}"
    assert dut.io_out_vec_3_exponent.value == "01", f"FieldExtractor failed: {dut.io_out_vec_3_exponent.value}"
    assert dut.io_out_vec_3_mantissa.value == "10", f"FieldExtractor failed: {dut.io_out_vec_3_mantissa.value}"
    assert dut.io_out_vec_4_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_4_sign.value}"
    assert dut.io_out_vec_4_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_4_exponent.value}"
    assert dut.io_out_vec_4_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_4_mantissa.value}"
    assert dut.io_out_vec_5_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_5_sign.value}"
    assert dut.io_out_vec_5_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_5_exponent.value}"
    assert dut.io_out_vec_5_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_5_mantissa.value}"
    assert dut.io_out_vec_6_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_6_sign.value}"
    assert dut.io_out_vec_6_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_6_exponent.value}"
    assert dut.io_out_vec_6_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_6_mantissa.value}"
    assert dut.io_out_vec_7_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_7_sign.value}"
    assert dut.io_out_vec_7_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_7_exponent.value}"
    assert dut.io_out_vec_7_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_7_mantissa.value}"
    assert dut.io_out_vec_8_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_8_sign.value}"
    assert dut.io_out_vec_8_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_8_exponent.value}"
    assert dut.io_out_vec_8_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_8_mantissa.value}"
    assert dut.io_out_vec_9_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_9_sign.value}"
    assert dut.io_out_vec_9_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_9_exponent.value}"
    assert dut.io_out_vec_9_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_9_mantissa.value}"
    assert dut.io_out_vec_10_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_10_sign.value}"
    assert dut.io_out_vec_10_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_10_exponent.value}"
    assert dut.io_out_vec_10_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_10_mantissa.value}"
    assert dut.io_out_vec_11_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_11_sign.value}"
    assert dut.io_out_vec_11_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_11_exponent.value}"
    assert dut.io_out_vec_11_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_11_mantissa.value}"
    assert dut.io_out_vec_12_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_12_sign.value}"
    assert dut.io_out_vec_12_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_12_exponent.value}"
    assert dut.io_out_vec_12_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_12_mantissa.value}"
    assert dut.io_out_vec_13_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_13_sign.value}"
    assert dut.io_out_vec_13_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_13_exponent.value}"
    assert dut.io_out_vec_13_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_13_mantissa.value}"
    assert dut.io_out_vec_14_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_14_sign.value}"
    assert dut.io_out_vec_14_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_14_exponent.value}"
    assert dut.io_out_vec_14_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_14_mantissa.value}"
    assert dut.io_out_vec_15_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_15_sign.value}"
    assert dut.io_out_vec_15_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_15_exponent.value}"
    assert dut.io_out_vec_15_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_15_mantissa.value}"
    assert dut.io_out_vec_16_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_16_sign.value}"
    assert dut.io_out_vec_16_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_16_exponent.value}"
    assert dut.io_out_vec_16_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_16_mantissa.value}"
    assert dut.io_out_vec_17_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_17_sign.value}"
    assert dut.io_out_vec_17_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_17_exponent.value}"
    assert dut.io_out_vec_17_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_17_mantissa.value}"
    assert dut.io_out_vec_18_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_18_sign.value}"
    assert dut.io_out_vec_18_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_18_exponent.value}"
    assert dut.io_out_vec_18_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_18_mantissa.value}"
    assert dut.io_out_vec_19_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_19_sign.value}"
    assert dut.io_out_vec_19_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_19_exponent.value}"
    assert dut.io_out_vec_19_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_19_mantissa.value}"
    assert dut.io_out_vec_20_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_20_sign.value}"
    assert dut.io_out_vec_20_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_20_exponent.value}"
    assert dut.io_out_vec_20_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_20_mantissa.value}"
    assert dut.io_out_vec_21_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_21_sign.value}"
    assert dut.io_out_vec_21_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_21_exponent.value}"
    assert dut.io_out_vec_21_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_21_mantissa.value}"
    assert dut.io_out_vec_22_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_22_sign.value}"
    assert dut.io_out_vec_22_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_22_exponent.value}"
    assert dut.io_out_vec_22_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_22_mantissa.value}"
    assert dut.io_out_vec_23_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_23_sign.value}"
    assert dut.io_out_vec_23_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_23_exponent.value}"
    assert dut.io_out_vec_23_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_23_mantissa.value}"
    assert dut.io_out_vec_24_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_24_sign.value}"
    assert dut.io_out_vec_24_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_24_exponent.value}"
    assert dut.io_out_vec_24_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_24_mantissa.value}"
    assert dut.io_out_vec_25_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_25_sign.value}"
    assert dut.io_out_vec_25_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_25_exponent.value}"
    assert dut.io_out_vec_25_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_25_mantissa.value}"
    assert dut.io_out_vec_26_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_26_sign.value}"
    assert dut.io_out_vec_26_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_26_exponent.value}"
    assert dut.io_out_vec_26_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_26_mantissa.value}"
    assert dut.io_out_vec_27_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_27_sign.value}"
    assert dut.io_out_vec_27_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_27_exponent.value}"
    assert dut.io_out_vec_27_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_27_mantissa.value}"
    assert dut.io_out_vec_28_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_28_sign.value}"
    assert dut.io_out_vec_28_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_28_exponent.value}"
    assert dut.io_out_vec_28_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_28_mantissa.value}"
    assert dut.io_out_vec_29_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_29_sign.value}"
    assert dut.io_out_vec_29_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_29_exponent.value}"
    assert dut.io_out_vec_29_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_29_mantissa.value}"
    assert dut.io_out_vec_30_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_30_sign.value}"
    assert dut.io_out_vec_30_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_30_exponent.value}"
    assert dut.io_out_vec_30_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_30_mantissa.value}"
    assert dut.io_out_vec_31_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_31_sign.value}"
    assert dut.io_out_vec_31_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_31_exponent.value}"
    assert dut.io_out_vec_31_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_31_mantissa.value}"
    assert dut.io_out_vec_32_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_32_sign.value}"
    assert dut.io_out_vec_32_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_32_exponent.value}"
    assert dut.io_out_vec_32_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_32_mantissa.value}"
    assert dut.io_out_vec_33_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_33_sign.value}"
    assert dut.io_out_vec_33_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_33_exponent.value}"
    assert dut.io_out_vec_33_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_33_mantissa.value}"
    assert dut.io_out_vec_34_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_34_sign.value}"
    assert dut.io_out_vec_34_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_34_exponent.value}"
    assert dut.io_out_vec_34_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_34_mantissa.value}"
    assert dut.io_out_vec_35_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_35_sign.value}"
    assert dut.io_out_vec_35_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_35_exponent.value}"
    assert dut.io_out_vec_35_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_35_mantissa.value}"
    assert dut.io_out_vec_36_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_36_sign.value}"
    assert dut.io_out_vec_36_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_36_exponent.value}"
    assert dut.io_out_vec_36_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_36_mantissa.value}"
    assert dut.io_out_vec_37_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_37_sign.value}"
    assert dut.io_out_vec_37_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_37_exponent.value}"
    assert dut.io_out_vec_37_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_37_mantissa.value}"
    assert dut.io_out_vec_38_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_38_sign.value}"
    assert dut.io_out_vec_38_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_38_exponent.value}"
    assert dut.io_out_vec_38_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_38_mantissa.value}"
    assert dut.io_out_vec_39_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_39_sign.value}"
    assert dut.io_out_vec_39_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_39_exponent.value}"
    assert dut.io_out_vec_39_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_39_mantissa.value}"
    assert dut.io_out_vec_40_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_40_sign.value}"
    assert dut.io_out_vec_40_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_40_exponent.value}"
    assert dut.io_out_vec_40_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_40_mantissa.value}"
    assert dut.io_out_vec_41_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_41_sign.value}"
    assert dut.io_out_vec_41_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_41_exponent.value}"
    assert dut.io_out_vec_41_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_41_mantissa.value}"
    assert dut.io_out_vec_42_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_42_sign.value}"
    assert dut.io_out_vec_42_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_42_exponent.value}"
    assert dut.io_out_vec_42_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_42_mantissa.value}"
    assert dut.io_out_vec_43_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_43_sign.value}"
    assert dut.io_out_vec_43_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_43_exponent.value}"
    assert dut.io_out_vec_43_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_43_mantissa.value}"
    assert dut.io_out_vec_44_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_44_sign.value}"
    assert dut.io_out_vec_44_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_44_exponent.value}"
    assert dut.io_out_vec_44_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_44_mantissa.value}"
    assert dut.io_out_vec_45_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_45_sign.value}"
    assert dut.io_out_vec_45_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_45_exponent.value}"
    assert dut.io_out_vec_45_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_45_mantissa.value}"
    assert dut.io_out_vec_46_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_46_sign.value}"
    assert dut.io_out_vec_46_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_46_exponent.value}"
    assert dut.io_out_vec_46_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_46_mantissa.value}"
    assert dut.io_out_vec_47_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_47_sign.value}"
    assert dut.io_out_vec_47_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_47_exponent.value}"
    assert dut.io_out_vec_47_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_47_mantissa.value}"
    assert dut.io_out_vec_48_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_48_sign.value}"
    assert dut.io_out_vec_48_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_48_exponent.value}"
    assert dut.io_out_vec_48_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_48_mantissa.value}"
    assert dut.io_out_vec_49_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_49_sign.value}"
    assert dut.io_out_vec_49_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_49_exponent.value}"
    assert dut.io_out_vec_49_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_49_mantissa.value}"
    assert dut.io_out_vec_50_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_50_sign.value}"
    assert dut.io_out_vec_50_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_50_exponent.value}"
    assert dut.io_out_vec_50_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_50_mantissa.value}"
    assert dut.io_out_vec_51_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_51_sign.value}"
    assert dut.io_out_vec_51_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_51_exponent.value}"
    assert dut.io_out_vec_51_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_51_mantissa.value}"
    assert dut.io_out_vec_52_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_52_sign.value}"
    assert dut.io_out_vec_52_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_52_exponent.value}"
    assert dut.io_out_vec_52_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_52_mantissa.value}"
    assert dut.io_out_vec_53_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_53_sign.value}"
    assert dut.io_out_vec_53_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_53_exponent.value}"
    assert dut.io_out_vec_53_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_53_mantissa.value}"
    assert dut.io_out_vec_54_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_54_sign.value}"
    assert dut.io_out_vec_54_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_54_exponent.value}"
    assert dut.io_out_vec_54_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_54_mantissa.value}"
    assert dut.io_out_vec_55_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_55_sign.value}"
    assert dut.io_out_vec_55_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_55_exponent.value}"
    assert dut.io_out_vec_55_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_55_mantissa.value}"
    assert dut.io_out_vec_56_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_56_sign.value}"
    assert dut.io_out_vec_56_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_56_exponent.value}"
    assert dut.io_out_vec_56_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_56_mantissa.value}"
    assert dut.io_out_vec_57_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_57_sign.value}"
    assert dut.io_out_vec_57_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_57_exponent.value}"
    assert dut.io_out_vec_57_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_57_mantissa.value}"
    assert dut.io_out_vec_58_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_58_sign.value}"
    assert dut.io_out_vec_58_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_58_exponent.value}"
    assert dut.io_out_vec_58_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_58_mantissa.value}"
    assert dut.io_out_vec_59_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_59_sign.value}"
    assert dut.io_out_vec_59_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_59_exponent.value}"
    assert dut.io_out_vec_59_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_59_mantissa.value}"
    assert dut.io_out_vec_60_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_60_sign.value}"
    assert dut.io_out_vec_60_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_60_exponent.value}"
    assert dut.io_out_vec_60_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_60_mantissa.value}"
    assert dut.io_out_vec_61_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_61_sign.value}"
    assert dut.io_out_vec_61_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_61_exponent.value}"
    assert dut.io_out_vec_61_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_61_mantissa.value}"
    assert dut.io_out_vec_62_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_62_sign.value}"
    assert dut.io_out_vec_62_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_62_exponent.value}"
    assert dut.io_out_vec_62_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_62_mantissa.value}"
    assert dut.io_out_vec_63_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_63_sign.value}"
    assert dut.io_out_vec_63_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_63_exponent.value}"
    assert dut.io_out_vec_63_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_63_mantissa.value}"
    assert dut.io_out_vec_64_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_64_sign.value}"
    assert dut.io_out_vec_64_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_64_exponent.value}"
    assert dut.io_out_vec_64_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_64_mantissa.value}"
    assert dut.io_out_vec_65_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_65_sign.value}"
    assert dut.io_out_vec_65_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_65_exponent.value}"
    assert dut.io_out_vec_65_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_65_mantissa.value}"
    assert dut.io_out_vec_66_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_66_sign.value}"
    assert dut.io_out_vec_66_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_66_exponent.value}"
    assert dut.io_out_vec_66_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_66_mantissa.value}"
    assert dut.io_out_vec_67_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_67_sign.value}"
    assert dut.io_out_vec_67_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_67_exponent.value}"
    assert dut.io_out_vec_67_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_67_mantissa.value}"
    assert dut.io_out_vec_68_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_68_sign.value}"
    assert dut.io_out_vec_68_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_68_exponent.value}"
    assert dut.io_out_vec_68_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_68_mantissa.value}"
    assert dut.io_out_vec_69_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_69_sign.value}"
    assert dut.io_out_vec_69_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_69_exponent.value}"
    assert dut.io_out_vec_69_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_69_mantissa.value}"
    assert dut.io_out_vec_70_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_70_sign.value}"
    assert dut.io_out_vec_70_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_70_exponent.value}"
    assert dut.io_out_vec_70_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_70_mantissa.value}"
    assert dut.io_out_vec_71_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_71_sign.value}"
    assert dut.io_out_vec_71_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_71_exponent.value}"
    assert dut.io_out_vec_71_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_71_mantissa.value}"
    assert dut.io_out_vec_72_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_72_sign.value}"
    assert dut.io_out_vec_72_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_72_exponent.value}"
    assert dut.io_out_vec_72_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_72_mantissa.value}"
    assert dut.io_out_vec_73_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_73_sign.value}"
    assert dut.io_out_vec_73_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_73_exponent.value}"
    assert dut.io_out_vec_73_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_73_mantissa.value}"
    assert dut.io_out_vec_74_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_74_sign.value}"
    assert dut.io_out_vec_74_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_74_exponent.value}"
    assert dut.io_out_vec_74_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_74_mantissa.value}"
    assert dut.io_out_vec_75_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_75_sign.value}"
    assert dut.io_out_vec_75_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_75_exponent.value}"
    assert dut.io_out_vec_75_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_75_mantissa.value}"
    assert dut.io_out_vec_76_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_76_sign.value}"
    assert dut.io_out_vec_76_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_76_exponent.value}"
    assert dut.io_out_vec_76_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_76_mantissa.value}"
    assert dut.io_out_vec_77_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_77_sign.value}"
    assert dut.io_out_vec_77_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_77_exponent.value}"
    assert dut.io_out_vec_77_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_77_mantissa.value}"
    assert dut.io_out_vec_78_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_78_sign.value}"
    assert dut.io_out_vec_78_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_78_exponent.value}"
    assert dut.io_out_vec_78_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_78_mantissa.value}"
    assert dut.io_out_vec_79_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_79_sign.value}"
    assert dut.io_out_vec_79_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_79_exponent.value}"
    assert dut.io_out_vec_79_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_79_mantissa.value}"
    assert dut.io_out_vec_80_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_80_sign.value}"
    assert dut.io_out_vec_80_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_80_exponent.value}"
    assert dut.io_out_vec_80_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_80_mantissa.value}"
    assert dut.io_out_vec_81_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_81_sign.value}"
    assert dut.io_out_vec_81_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_81_exponent.value}"
    assert dut.io_out_vec_81_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_81_mantissa.value}"
    assert dut.io_out_vec_82_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_82_sign.value}"
    assert dut.io_out_vec_82_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_82_exponent.value}"
    assert dut.io_out_vec_82_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_82_mantissa.value}"
    assert dut.io_out_vec_83_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_83_sign.value}"
    assert dut.io_out_vec_83_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_83_exponent.value}"
    assert dut.io_out_vec_83_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_83_mantissa.value}"
    assert dut.io_out_vec_84_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_84_sign.value}"
    assert dut.io_out_vec_84_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_84_exponent.value}"
    assert dut.io_out_vec_84_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_84_mantissa.value}"
    assert dut.io_out_vec_85_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_85_sign.value}"
    assert dut.io_out_vec_85_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_85_exponent.value}"
    assert dut.io_out_vec_85_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_85_mantissa.value}"
    assert dut.io_out_vec_86_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_86_sign.value}"
    assert dut.io_out_vec_86_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_86_exponent.value}"
    assert dut.io_out_vec_86_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_86_mantissa.value}"
    assert dut.io_out_vec_87_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_87_sign.value}"
    assert dut.io_out_vec_87_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_87_exponent.value}"
    assert dut.io_out_vec_87_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_87_mantissa.value}"
    assert dut.io_out_vec_88_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_88_sign.value}"
    assert dut.io_out_vec_88_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_88_exponent.value}"
    assert dut.io_out_vec_88_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_88_mantissa.value}"
    assert dut.io_out_vec_89_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_89_sign.value}"
    assert dut.io_out_vec_89_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_89_exponent.value}"
    assert dut.io_out_vec_89_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_89_mantissa.value}"
    assert dut.io_out_vec_90_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_90_sign.value}"
    assert dut.io_out_vec_90_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_90_exponent.value}"
    assert dut.io_out_vec_90_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_90_mantissa.value}"
    assert dut.io_out_vec_91_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_91_sign.value}"
    assert dut.io_out_vec_91_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_91_exponent.value}"
    assert dut.io_out_vec_91_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_91_mantissa.value}"
    assert dut.io_out_vec_92_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_92_sign.value}"
    assert dut.io_out_vec_92_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_92_exponent.value}"
    assert dut.io_out_vec_92_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_92_mantissa.value}"
    assert dut.io_out_vec_93_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_93_sign.value}"
    assert dut.io_out_vec_93_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_93_exponent.value}"
    assert dut.io_out_vec_93_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_93_mantissa.value}"
    assert dut.io_out_vec_94_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_94_sign.value}"
    assert dut.io_out_vec_94_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_94_exponent.value}"
    assert dut.io_out_vec_94_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_94_mantissa.value}"
    assert dut.io_out_vec_95_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_95_sign.value}"
    assert dut.io_out_vec_95_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_95_exponent.value}"
    assert dut.io_out_vec_95_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_95_mantissa.value}"
    assert dut.io_out_vec_96_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_96_sign.value}"
    assert dut.io_out_vec_96_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_96_exponent.value}"
    assert dut.io_out_vec_96_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_96_mantissa.value}"
    assert dut.io_out_vec_97_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_97_sign.value}"
    assert dut.io_out_vec_97_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_97_exponent.value}"
    assert dut.io_out_vec_97_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_97_mantissa.value}"
    assert dut.io_out_vec_98_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_98_sign.value}"
    assert dut.io_out_vec_98_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_98_exponent.value}"
    assert dut.io_out_vec_98_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_98_mantissa.value}"
    assert dut.io_out_vec_99_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_99_sign.value}"
    assert dut.io_out_vec_99_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_99_exponent.value}"
    assert dut.io_out_vec_99_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_99_mantissa.value}"
    assert dut.io_out_vec_100_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_100_sign.value}"
    assert dut.io_out_vec_100_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_100_exponent.value}"
    assert dut.io_out_vec_100_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_100_mantissa.value}"
    assert dut.io_out_vec_101_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_101_sign.value}"
    assert dut.io_out_vec_101_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_101_exponent.value}"
    assert dut.io_out_vec_101_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_101_mantissa.value}"
    assert dut.io_out_vec_102_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_102_sign.value}"
    assert dut.io_out_vec_102_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_102_exponent.value}"
    assert dut.io_out_vec_102_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_102_mantissa.value}"
    assert dut.io_out_vec_103_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_103_sign.value}"
    assert dut.io_out_vec_103_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_103_exponent.value}"
    assert dut.io_out_vec_103_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_103_mantissa.value}"
    assert dut.io_out_vec_104_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_104_sign.value}"
    assert dut.io_out_vec_104_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_104_exponent.value}"
    assert dut.io_out_vec_104_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_104_mantissa.value}"
    assert dut.io_out_vec_105_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_105_sign.value}"
    assert dut.io_out_vec_105_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_105_exponent.value}"
    assert dut.io_out_vec_105_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_105_mantissa.value}"
    assert dut.io_out_vec_106_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_106_sign.value}"
    assert dut.io_out_vec_106_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_106_exponent.value}"
    assert dut.io_out_vec_106_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_106_mantissa.value}"
    assert dut.io_out_vec_107_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_107_sign.value}"
    assert dut.io_out_vec_107_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_107_exponent.value}"
    assert dut.io_out_vec_107_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_107_mantissa.value}"
    assert dut.io_out_vec_108_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_108_sign.value}"
    assert dut.io_out_vec_108_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_108_exponent.value}"
    assert dut.io_out_vec_108_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_108_mantissa.value}"
    assert dut.io_out_vec_109_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_109_sign.value}"
    assert dut.io_out_vec_109_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_109_exponent.value}"
    assert dut.io_out_vec_109_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_109_mantissa.value}"
    assert dut.io_out_vec_110_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_110_sign.value}"
    assert dut.io_out_vec_110_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_110_exponent.value}"
    assert dut.io_out_vec_110_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_110_mantissa.value}"
    assert dut.io_out_vec_111_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_111_sign.value}"
    assert dut.io_out_vec_111_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_111_exponent.value}"
    assert dut.io_out_vec_111_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_111_mantissa.value}"
    assert dut.io_out_vec_112_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_112_sign.value}"
    assert dut.io_out_vec_112_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_112_exponent.value}"
    assert dut.io_out_vec_112_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_112_mantissa.value}"
    assert dut.io_out_vec_113_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_113_sign.value}"
    assert dut.io_out_vec_113_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_113_exponent.value}"
    assert dut.io_out_vec_113_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_113_mantissa.value}"
    assert dut.io_out_vec_114_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_114_sign.value}"
    assert dut.io_out_vec_114_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_114_exponent.value}"
    assert dut.io_out_vec_114_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_114_mantissa.value}"
    assert dut.io_out_vec_115_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_115_sign.value}"
    assert dut.io_out_vec_115_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_115_exponent.value}"
    assert dut.io_out_vec_115_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_115_mantissa.value}"
    assert dut.io_out_vec_116_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_116_sign.value}"
    assert dut.io_out_vec_116_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_116_exponent.value}"
    assert dut.io_out_vec_116_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_116_mantissa.value}"
    assert dut.io_out_vec_117_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_117_sign.value}"
    assert dut.io_out_vec_117_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_117_exponent.value}"
    assert dut.io_out_vec_117_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_117_mantissa.value}"
    assert dut.io_out_vec_118_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_118_sign.value}"
    assert dut.io_out_vec_118_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_118_exponent.value}"
    assert dut.io_out_vec_118_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_118_mantissa.value}"
    assert dut.io_out_vec_119_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_119_sign.value}"
    assert dut.io_out_vec_119_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_119_exponent.value}"
    assert dut.io_out_vec_119_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_119_mantissa.value}"
    assert dut.io_out_vec_120_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_120_sign.value}"
    assert dut.io_out_vec_120_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_120_exponent.value}"
    assert dut.io_out_vec_120_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_120_mantissa.value}"
    assert dut.io_out_vec_121_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_121_sign.value}"
    assert dut.io_out_vec_121_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_121_exponent.value}"
    assert dut.io_out_vec_121_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_121_mantissa.value}"
    assert dut.io_out_vec_122_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_122_sign.value}"
    assert dut.io_out_vec_122_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_122_exponent.value}"
    assert dut.io_out_vec_122_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_122_mantissa.value}"
    assert dut.io_out_vec_123_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_123_sign.value}"
    assert dut.io_out_vec_123_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_123_exponent.value}"
    assert dut.io_out_vec_123_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_123_mantissa.value}"
    assert dut.io_out_vec_124_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_124_sign.value}"
    assert dut.io_out_vec_124_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_124_exponent.value}"
    assert dut.io_out_vec_124_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_124_mantissa.value}"
    assert dut.io_out_vec_125_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_125_sign.value}"
    assert dut.io_out_vec_125_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_125_exponent.value}"
    assert dut.io_out_vec_125_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_125_mantissa.value}"
    assert dut.io_out_vec_126_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_126_sign.value}"
    assert dut.io_out_vec_126_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_126_exponent.value}"
    assert dut.io_out_vec_126_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_126_mantissa.value}"
    assert dut.io_out_vec_127_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_127_sign.value}"
    assert dut.io_out_vec_127_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_127_exponent.value}"
    assert dut.io_out_vec_127_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_127_mantissa.value}"
    assert dut.io_out_vec_128_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_128_sign.value}"
    assert dut.io_out_vec_128_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_128_exponent.value}"
    assert dut.io_out_vec_128_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_128_mantissa.value}"
    assert dut.io_out_vec_129_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_129_sign.value}"
    assert dut.io_out_vec_129_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_129_exponent.value}"
    assert dut.io_out_vec_129_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_129_mantissa.value}"
    assert dut.io_out_vec_130_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_130_sign.value}"
    assert dut.io_out_vec_130_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_130_exponent.value}"
    assert dut.io_out_vec_130_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_130_mantissa.value}"
    assert dut.io_out_vec_131_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_131_sign.value}"
    assert dut.io_out_vec_131_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_131_exponent.value}"
    assert dut.io_out_vec_131_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_131_mantissa.value}"
    assert dut.io_out_vec_132_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_132_sign.value}"
    assert dut.io_out_vec_132_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_132_exponent.value}"
    assert dut.io_out_vec_132_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_132_mantissa.value}"
    assert dut.io_out_vec_133_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_133_sign.value}"
    assert dut.io_out_vec_133_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_133_exponent.value}"
    assert dut.io_out_vec_133_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_133_mantissa.value}"
    assert dut.io_out_vec_134_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_134_sign.value}"
    assert dut.io_out_vec_134_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_134_exponent.value}"
    assert dut.io_out_vec_134_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_134_mantissa.value}"
    assert dut.io_out_vec_135_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_135_sign.value}"
    assert dut.io_out_vec_135_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_135_exponent.value}"
    assert dut.io_out_vec_135_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_135_mantissa.value}"
    assert dut.io_out_vec_136_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_136_sign.value}"
    assert dut.io_out_vec_136_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_136_exponent.value}"
    assert dut.io_out_vec_136_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_136_mantissa.value}"
    assert dut.io_out_vec_137_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_137_sign.value}"
    assert dut.io_out_vec_137_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_137_exponent.value}"
    assert dut.io_out_vec_137_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_137_mantissa.value}"
    assert dut.io_out_vec_138_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_138_sign.value}"
    assert dut.io_out_vec_138_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_138_exponent.value}"
    assert dut.io_out_vec_138_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_138_mantissa.value}"
    assert dut.io_out_vec_139_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_139_sign.value}"
    assert dut.io_out_vec_139_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_139_exponent.value}"
    assert dut.io_out_vec_139_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_139_mantissa.value}"
    assert dut.io_out_vec_140_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_140_sign.value}"
    assert dut.io_out_vec_140_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_140_exponent.value}"
    assert dut.io_out_vec_140_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_140_mantissa.value}"
    assert dut.io_out_vec_141_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_141_sign.value}"
    assert dut.io_out_vec_141_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_141_exponent.value}"
    assert dut.io_out_vec_141_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_141_mantissa.value}"
    assert dut.io_out_vec_142_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_142_sign.value}"
    assert dut.io_out_vec_142_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_142_exponent.value}"
    assert dut.io_out_vec_142_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_142_mantissa.value}"
    assert dut.io_out_vec_143_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_143_sign.value}"
    assert dut.io_out_vec_143_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_143_exponent.value}"
    assert dut.io_out_vec_143_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_143_mantissa.value}"
    assert dut.io_out_vec_144_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_144_sign.value}"
    assert dut.io_out_vec_144_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_144_exponent.value}"
    assert dut.io_out_vec_144_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_144_mantissa.value}"
    assert dut.io_out_vec_145_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_145_sign.value}"
    assert dut.io_out_vec_145_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_145_exponent.value}"
    assert dut.io_out_vec_145_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_145_mantissa.value}"
    assert dut.io_out_vec_146_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_146_sign.value}"
    assert dut.io_out_vec_146_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_146_exponent.value}"
    assert dut.io_out_vec_146_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_146_mantissa.value}"
    assert dut.io_out_vec_147_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_147_sign.value}"
    assert dut.io_out_vec_147_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_147_exponent.value}"
    assert dut.io_out_vec_147_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_147_mantissa.value}"
    assert dut.io_out_vec_148_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_148_sign.value}"
    assert dut.io_out_vec_148_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_148_exponent.value}"
    assert dut.io_out_vec_148_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_148_mantissa.value}"
    assert dut.io_out_vec_149_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_149_sign.value}"
    assert dut.io_out_vec_149_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_149_exponent.value}"
    assert dut.io_out_vec_149_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_149_mantissa.value}"
    assert dut.io_out_vec_150_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_150_sign.value}"
    assert dut.io_out_vec_150_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_150_exponent.value}"
    assert dut.io_out_vec_150_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_150_mantissa.value}"
    assert dut.io_out_vec_151_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_151_sign.value}"
    assert dut.io_out_vec_151_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_151_exponent.value}"
    assert dut.io_out_vec_151_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_151_mantissa.value}"
    assert dut.io_out_vec_152_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_152_sign.value}"
    assert dut.io_out_vec_152_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_152_exponent.value}"
    assert dut.io_out_vec_152_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_152_mantissa.value}"
    assert dut.io_out_vec_153_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_153_sign.value}"
    assert dut.io_out_vec_153_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_153_exponent.value}"
    assert dut.io_out_vec_153_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_153_mantissa.value}"
    assert dut.io_out_vec_154_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_154_sign.value}"
    assert dut.io_out_vec_154_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_154_exponent.value}"
    assert dut.io_out_vec_154_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_154_mantissa.value}"
    assert dut.io_out_vec_155_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_155_sign.value}"
    assert dut.io_out_vec_155_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_155_exponent.value}"
    assert dut.io_out_vec_155_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_155_mantissa.value}"
    assert dut.io_out_vec_156_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_156_sign.value}"
    assert dut.io_out_vec_156_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_156_exponent.value}"
    assert dut.io_out_vec_156_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_156_mantissa.value}"
    assert dut.io_out_vec_157_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_157_sign.value}"
    assert dut.io_out_vec_157_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_157_exponent.value}"
    assert dut.io_out_vec_157_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_157_mantissa.value}"
    assert dut.io_out_vec_158_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_158_sign.value}"
    assert dut.io_out_vec_158_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_158_exponent.value}"
    assert dut.io_out_vec_158_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_158_mantissa.value}"
    assert dut.io_out_vec_159_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_159_sign.value}"
    assert dut.io_out_vec_159_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_159_exponent.value}"
    assert dut.io_out_vec_159_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_159_mantissa.value}"
    assert dut.io_out_vec_160_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_160_sign.value}"
    assert dut.io_out_vec_160_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_160_exponent.value}"
    assert dut.io_out_vec_160_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_160_mantissa.value}"
    assert dut.io_out_vec_161_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_161_sign.value}"
    assert dut.io_out_vec_161_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_161_exponent.value}"
    assert dut.io_out_vec_161_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_161_mantissa.value}"
    assert dut.io_out_vec_162_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_162_sign.value}"
    assert dut.io_out_vec_162_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_162_exponent.value}"
    assert dut.io_out_vec_162_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_162_mantissa.value}"
    assert dut.io_out_vec_163_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_163_sign.value}"
    assert dut.io_out_vec_163_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_163_exponent.value}"
    assert dut.io_out_vec_163_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_163_mantissa.value}"
    assert dut.io_out_vec_164_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_164_sign.value}"
    assert dut.io_out_vec_164_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_164_exponent.value}"
    assert dut.io_out_vec_164_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_164_mantissa.value}"
    assert dut.io_out_vec_165_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_165_sign.value}"
    assert dut.io_out_vec_165_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_165_exponent.value}"
    assert dut.io_out_vec_165_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_165_mantissa.value}"
    assert dut.io_out_vec_166_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_166_sign.value}"
    assert dut.io_out_vec_166_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_166_exponent.value}"
    assert dut.io_out_vec_166_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_166_mantissa.value}"
    assert dut.io_out_vec_167_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_167_sign.value}"
    assert dut.io_out_vec_167_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_167_exponent.value}"
    assert dut.io_out_vec_167_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_167_mantissa.value}"
    assert dut.io_out_vec_168_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_168_sign.value}"
    assert dut.io_out_vec_168_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_168_exponent.value}"
    assert dut.io_out_vec_168_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_168_mantissa.value}"
    assert dut.io_out_vec_169_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_169_sign.value}"
    assert dut.io_out_vec_169_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_169_exponent.value}"
    assert dut.io_out_vec_169_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_169_mantissa.value}"
    assert dut.io_out_vec_170_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_170_sign.value}"
    assert dut.io_out_vec_170_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_170_exponent.value}"
    assert dut.io_out_vec_170_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_170_mantissa.value}"
    assert dut.io_out_vec_171_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_171_sign.value}"
    assert dut.io_out_vec_171_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_171_exponent.value}"
    assert dut.io_out_vec_171_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_171_mantissa.value}"
    assert dut.io_out_vec_172_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_172_sign.value}"
    assert dut.io_out_vec_172_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_172_exponent.value}"
    assert dut.io_out_vec_172_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_172_mantissa.value}"
    assert dut.io_out_vec_173_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_173_sign.value}"
    assert dut.io_out_vec_173_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_173_exponent.value}"
    assert dut.io_out_vec_173_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_173_mantissa.value}"
    assert dut.io_out_vec_174_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_174_sign.value}"
    assert dut.io_out_vec_174_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_174_exponent.value}"
    assert dut.io_out_vec_174_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_174_mantissa.value}"
    assert dut.io_out_vec_175_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_175_sign.value}"
    assert dut.io_out_vec_175_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_175_exponent.value}"
    assert dut.io_out_vec_175_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_175_mantissa.value}"
    assert dut.io_out_vec_176_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_176_sign.value}"
    assert dut.io_out_vec_176_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_176_exponent.value}"
    assert dut.io_out_vec_176_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_176_mantissa.value}"
    assert dut.io_out_vec_177_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_177_sign.value}"
    assert dut.io_out_vec_177_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_177_exponent.value}"
    assert dut.io_out_vec_177_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_177_mantissa.value}"
    assert dut.io_out_vec_178_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_178_sign.value}"
    assert dut.io_out_vec_178_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_178_exponent.value}"
    assert dut.io_out_vec_178_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_178_mantissa.value}"
    assert dut.io_out_vec_179_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_179_sign.value}"
    assert dut.io_out_vec_179_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_179_exponent.value}"
    assert dut.io_out_vec_179_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_179_mantissa.value}"
    assert dut.io_out_vec_180_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_180_sign.value}"
    assert dut.io_out_vec_180_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_180_exponent.value}"
    assert dut.io_out_vec_180_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_180_mantissa.value}"
    assert dut.io_out_vec_181_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_181_sign.value}"
    assert dut.io_out_vec_181_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_181_exponent.value}"
    assert dut.io_out_vec_181_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_181_mantissa.value}"
    assert dut.io_out_vec_182_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_182_sign.value}"
    assert dut.io_out_vec_182_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_182_exponent.value}"
    assert dut.io_out_vec_182_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_182_mantissa.value}"
    assert dut.io_out_vec_183_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_183_sign.value}"
    assert dut.io_out_vec_183_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_183_exponent.value}"
    assert dut.io_out_vec_183_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_183_mantissa.value}"
    assert dut.io_out_vec_184_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_184_sign.value}"
    assert dut.io_out_vec_184_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_184_exponent.value}"
    assert dut.io_out_vec_184_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_184_mantissa.value}"
    assert dut.io_out_vec_185_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_185_sign.value}"
    assert dut.io_out_vec_185_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_185_exponent.value}"
    assert dut.io_out_vec_185_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_185_mantissa.value}"
    assert dut.io_out_vec_186_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_186_sign.value}"
    assert dut.io_out_vec_186_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_186_exponent.value}"
    assert dut.io_out_vec_186_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_186_mantissa.value}"
    assert dut.io_out_vec_187_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_187_sign.value}"
    assert dut.io_out_vec_187_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_187_exponent.value}"
    assert dut.io_out_vec_187_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_187_mantissa.value}"
    assert dut.io_out_vec_188_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_188_sign.value}"
    assert dut.io_out_vec_188_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_188_exponent.value}"
    assert dut.io_out_vec_188_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_188_mantissa.value}"
    assert dut.io_out_vec_189_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_189_sign.value}"
    assert dut.io_out_vec_189_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_189_exponent.value}"
    assert dut.io_out_vec_189_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_189_mantissa.value}"
    assert dut.io_out_vec_190_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_190_sign.value}"
    assert dut.io_out_vec_190_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_190_exponent.value}"
    assert dut.io_out_vec_190_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_190_mantissa.value}"
    assert dut.io_out_vec_191_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_191_sign.value}"
    assert dut.io_out_vec_191_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_191_exponent.value}"
    assert dut.io_out_vec_191_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_191_mantissa.value}"
    assert dut.io_out_vec_192_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_192_sign.value}"
    assert dut.io_out_vec_192_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_192_exponent.value}"
    assert dut.io_out_vec_192_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_192_mantissa.value}"
    assert dut.io_out_vec_193_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_193_sign.value}"
    assert dut.io_out_vec_193_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_193_exponent.value}"
    assert dut.io_out_vec_193_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_193_mantissa.value}"
    assert dut.io_out_vec_194_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_194_sign.value}"
    assert dut.io_out_vec_194_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_194_exponent.value}"
    assert dut.io_out_vec_194_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_194_mantissa.value}"
    assert dut.io_out_vec_195_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_195_sign.value}"
    assert dut.io_out_vec_195_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_195_exponent.value}"
    assert dut.io_out_vec_195_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_195_mantissa.value}"
    assert dut.io_out_vec_196_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_196_sign.value}"
    assert dut.io_out_vec_196_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_196_exponent.value}"
    assert dut.io_out_vec_196_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_196_mantissa.value}"
    assert dut.io_out_vec_197_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_197_sign.value}"
    assert dut.io_out_vec_197_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_197_exponent.value}"
    assert dut.io_out_vec_197_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_197_mantissa.value}"
    assert dut.io_out_vec_198_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_198_sign.value}"
    assert dut.io_out_vec_198_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_198_exponent.value}"
    assert dut.io_out_vec_198_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_198_mantissa.value}"
    assert dut.io_out_vec_199_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_199_sign.value}"
    assert dut.io_out_vec_199_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_199_exponent.value}"
    assert dut.io_out_vec_199_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_199_mantissa.value}"
    assert dut.io_out_vec_200_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_200_sign.value}"
    assert dut.io_out_vec_200_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_200_exponent.value}"
    assert dut.io_out_vec_200_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_200_mantissa.value}"
    assert dut.io_out_vec_201_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_201_sign.value}"
    assert dut.io_out_vec_201_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_201_exponent.value}"
    assert dut.io_out_vec_201_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_201_mantissa.value}"
    assert dut.io_out_vec_202_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_202_sign.value}"
    assert dut.io_out_vec_202_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_202_exponent.value}"
    assert dut.io_out_vec_202_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_202_mantissa.value}"
    assert dut.io_out_vec_203_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_203_sign.value}"
    assert dut.io_out_vec_203_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_203_exponent.value}"
    assert dut.io_out_vec_203_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_203_mantissa.value}"
    assert dut.io_out_vec_204_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_204_sign.value}"
    assert dut.io_out_vec_204_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_204_exponent.value}"
    assert dut.io_out_vec_204_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_204_mantissa.value}"
    assert dut.io_out_vec_205_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_205_sign.value}"
    assert dut.io_out_vec_205_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_205_exponent.value}"
    assert dut.io_out_vec_205_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_205_mantissa.value}"
    assert dut.io_out_vec_206_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_206_sign.value}"
    assert dut.io_out_vec_206_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_206_exponent.value}"
    assert dut.io_out_vec_206_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_206_mantissa.value}"
    assert dut.io_out_vec_207_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_207_sign.value}"
    assert dut.io_out_vec_207_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_207_exponent.value}"
    assert dut.io_out_vec_207_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_207_mantissa.value}"
    assert dut.io_out_vec_208_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_208_sign.value}"
    assert dut.io_out_vec_208_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_208_exponent.value}"
    assert dut.io_out_vec_208_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_208_mantissa.value}"
    assert dut.io_out_vec_209_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_209_sign.value}"
    assert dut.io_out_vec_209_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_209_exponent.value}"
    assert dut.io_out_vec_209_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_209_mantissa.value}"
    assert dut.io_out_vec_210_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_210_sign.value}"
    assert dut.io_out_vec_210_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_210_exponent.value}"
    assert dut.io_out_vec_210_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_210_mantissa.value}"
    assert dut.io_out_vec_211_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_211_sign.value}"
    assert dut.io_out_vec_211_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_211_exponent.value}"
    assert dut.io_out_vec_211_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_211_mantissa.value}"
    assert dut.io_out_vec_212_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_212_sign.value}"
    assert dut.io_out_vec_212_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_212_exponent.value}"
    assert dut.io_out_vec_212_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_212_mantissa.value}"
    assert dut.io_out_vec_213_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_213_sign.value}"
    assert dut.io_out_vec_213_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_213_exponent.value}"
    assert dut.io_out_vec_213_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_213_mantissa.value}"
    assert dut.io_out_vec_214_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_214_sign.value}"
    assert dut.io_out_vec_214_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_214_exponent.value}"
    assert dut.io_out_vec_214_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_214_mantissa.value}"
    assert dut.io_out_vec_215_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_215_sign.value}"
    assert dut.io_out_vec_215_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_215_exponent.value}"
    assert dut.io_out_vec_215_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_215_mantissa.value}"
    assert dut.io_out_vec_216_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_216_sign.value}"
    assert dut.io_out_vec_216_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_216_exponent.value}"
    assert dut.io_out_vec_216_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_216_mantissa.value}"
    assert dut.io_out_vec_217_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_217_sign.value}"
    assert dut.io_out_vec_217_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_217_exponent.value}"
    assert dut.io_out_vec_217_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_217_mantissa.value}"
    assert dut.io_out_vec_218_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_218_sign.value}"
    assert dut.io_out_vec_218_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_218_exponent.value}"
    assert dut.io_out_vec_218_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_218_mantissa.value}"
    assert dut.io_out_vec_219_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_219_sign.value}"
    assert dut.io_out_vec_219_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_219_exponent.value}"
    assert dut.io_out_vec_219_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_219_mantissa.value}"
    assert dut.io_out_vec_220_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_220_sign.value}"
    assert dut.io_out_vec_220_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_220_exponent.value}"
    assert dut.io_out_vec_220_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_220_mantissa.value}"
    assert dut.io_out_vec_221_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_221_sign.value}"
    assert dut.io_out_vec_221_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_221_exponent.value}"
    assert dut.io_out_vec_221_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_221_mantissa.value}"
    assert dut.io_out_vec_222_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_222_sign.value}"
    assert dut.io_out_vec_222_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_222_exponent.value}"
    assert dut.io_out_vec_222_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_222_mantissa.value}"
    assert dut.io_out_vec_223_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_223_sign.value}"
    assert dut.io_out_vec_223_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_223_exponent.value}"
    assert dut.io_out_vec_223_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_223_mantissa.value}"
    assert dut.io_out_vec_224_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_224_sign.value}"
    assert dut.io_out_vec_224_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_224_exponent.value}"
    assert dut.io_out_vec_224_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_224_mantissa.value}"
    assert dut.io_out_vec_225_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_225_sign.value}"
    assert dut.io_out_vec_225_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_225_exponent.value}"
    assert dut.io_out_vec_225_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_225_mantissa.value}"
    assert dut.io_out_vec_226_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_226_sign.value}"
    assert dut.io_out_vec_226_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_226_exponent.value}"
    assert dut.io_out_vec_226_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_226_mantissa.value}"
    assert dut.io_out_vec_227_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_227_sign.value}"
    assert dut.io_out_vec_227_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_227_exponent.value}"
    assert dut.io_out_vec_227_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_227_mantissa.value}"
    assert dut.io_out_vec_228_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_228_sign.value}"
    assert dut.io_out_vec_228_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_228_exponent.value}"
    assert dut.io_out_vec_228_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_228_mantissa.value}"
    assert dut.io_out_vec_229_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_229_sign.value}"
    assert dut.io_out_vec_229_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_229_exponent.value}"
    assert dut.io_out_vec_229_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_229_mantissa.value}"
    assert dut.io_out_vec_230_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_230_sign.value}"
    assert dut.io_out_vec_230_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_230_exponent.value}"
    assert dut.io_out_vec_230_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_230_mantissa.value}"
    assert dut.io_out_vec_231_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_231_sign.value}"
    assert dut.io_out_vec_231_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_231_exponent.value}"
    assert dut.io_out_vec_231_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_231_mantissa.value}"
    assert dut.io_out_vec_232_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_232_sign.value}"
    assert dut.io_out_vec_232_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_232_exponent.value}"
    assert dut.io_out_vec_232_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_232_mantissa.value}"
    assert dut.io_out_vec_233_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_233_sign.value}"
    assert dut.io_out_vec_233_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_233_exponent.value}"
    assert dut.io_out_vec_233_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_233_mantissa.value}"
    assert dut.io_out_vec_234_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_234_sign.value}"
    assert dut.io_out_vec_234_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_234_exponent.value}"
    assert dut.io_out_vec_234_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_234_mantissa.value}"
    assert dut.io_out_vec_235_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_235_sign.value}"
    assert dut.io_out_vec_235_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_235_exponent.value}"
    assert dut.io_out_vec_235_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_235_mantissa.value}"
    assert dut.io_out_vec_236_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_236_sign.value}"
    assert dut.io_out_vec_236_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_236_exponent.value}"
    assert dut.io_out_vec_236_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_236_mantissa.value}"
    assert dut.io_out_vec_237_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_237_sign.value}"
    assert dut.io_out_vec_237_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_237_exponent.value}"
    assert dut.io_out_vec_237_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_237_mantissa.value}"
    assert dut.io_out_vec_238_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_238_sign.value}"
    assert dut.io_out_vec_238_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_238_exponent.value}"
    assert dut.io_out_vec_238_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_238_mantissa.value}"
    assert dut.io_out_vec_239_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_239_sign.value}"
    assert dut.io_out_vec_239_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_239_exponent.value}"
    assert dut.io_out_vec_239_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_239_mantissa.value}"
    assert dut.io_out_vec_240_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_240_sign.value}"
    assert dut.io_out_vec_240_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_240_exponent.value}"
    assert dut.io_out_vec_240_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_240_mantissa.value}"
    assert dut.io_out_vec_241_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_241_sign.value}"
    assert dut.io_out_vec_241_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_241_exponent.value}"
    assert dut.io_out_vec_241_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_241_mantissa.value}"
    assert dut.io_out_vec_242_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_242_sign.value}"
    assert dut.io_out_vec_242_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_242_exponent.value}"
    assert dut.io_out_vec_242_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_242_mantissa.value}"
    assert dut.io_out_vec_243_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_243_sign.value}"
    assert dut.io_out_vec_243_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_243_exponent.value}"
    assert dut.io_out_vec_243_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_243_mantissa.value}"
    assert dut.io_out_vec_244_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_244_sign.value}"
    assert dut.io_out_vec_244_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_244_exponent.value}"
    assert dut.io_out_vec_244_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_244_mantissa.value}"
    assert dut.io_out_vec_245_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_245_sign.value}"
    assert dut.io_out_vec_245_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_245_exponent.value}"
    assert dut.io_out_vec_245_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_245_mantissa.value}"
    assert dut.io_out_vec_246_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_246_sign.value}"
    assert dut.io_out_vec_246_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_246_exponent.value}"
    assert dut.io_out_vec_246_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_246_mantissa.value}"
    assert dut.io_out_vec_247_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_247_sign.value}"
    assert dut.io_out_vec_247_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_247_exponent.value}"
    assert dut.io_out_vec_247_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_247_mantissa.value}"
    assert dut.io_out_vec_248_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_248_sign.value}"
    assert dut.io_out_vec_248_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_248_exponent.value}"
    assert dut.io_out_vec_248_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_248_mantissa.value}"
    assert dut.io_out_vec_249_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_249_sign.value}"
    assert dut.io_out_vec_249_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_249_exponent.value}"
    assert dut.io_out_vec_249_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_249_mantissa.value}"
    assert dut.io_out_vec_250_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_250_sign.value}"
    assert dut.io_out_vec_250_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_250_exponent.value}"
    assert dut.io_out_vec_250_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_250_mantissa.value}"
    assert dut.io_out_vec_251_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_251_sign.value}"
    assert dut.io_out_vec_251_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_251_exponent.value}"
    assert dut.io_out_vec_251_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_251_mantissa.value}"
    assert dut.io_out_vec_252_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_252_sign.value}"
    assert dut.io_out_vec_252_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_252_exponent.value}"
    assert dut.io_out_vec_252_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_252_mantissa.value}"
    assert dut.io_out_vec_253_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_253_sign.value}"
    assert dut.io_out_vec_253_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_253_exponent.value}"
    assert dut.io_out_vec_253_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_253_mantissa.value}"
    assert dut.io_out_vec_254_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_254_sign.value}"
    assert dut.io_out_vec_254_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_254_exponent.value}"
    assert dut.io_out_vec_254_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_254_mantissa.value}"
    assert dut.io_out_vec_255_sign.value == 0, f"FieldExtractor failed: {dut.io_out_vec_255_sign.value}"
    assert dut.io_out_vec_255_exponent.value == 0, f"FieldExtractor failed: {dut.io_out_vec_255_exponent.value}"
    assert dut.io_out_vec_255_mantissa.value == 0, f"FieldExtractor failed: {dut.io_out_vec_255_mantissa.value}"
