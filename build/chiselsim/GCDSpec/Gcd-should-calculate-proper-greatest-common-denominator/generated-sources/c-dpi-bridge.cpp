#include <stdint.h>

#ifdef SVSIM_ENABLE_VERILATOR_SUPPORT
#include "verilated-sources/VsvsimTestbench__Dpi.h"
#endif
#ifdef SVSIM_ENABLE_VCS_SUPPORT
#include "vc_hdrs.h"
#endif

extern "C" {
 svScope setScopeToTestBench();
void getBitWidth_clock(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_clock(result);
           svSetScope(prev);
        }
void getBits_clock(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_clock(result);
           svSetScope(prev);
        }
void setBits_clock(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_clock(data);
           svSetScope(prev);
        }
void getBitWidth_reset(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_reset(result);
           svSetScope(prev);
        }
void getBits_reset(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_reset(result);
           svSetScope(prev);
        }
void setBits_reset(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_reset(data);
           svSetScope(prev);
        }
void getBitWidth_input_bits_value2(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_input_bits_value2(result);
           svSetScope(prev);
        }
void getBits_input_bits_value2(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_input_bits_value2(result);
           svSetScope(prev);
        }
void setBits_input_bits_value2(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_input_bits_value2(data);
           svSetScope(prev);
        }
void getBitWidth_input_bits_value1(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_input_bits_value1(result);
           svSetScope(prev);
        }
void getBits_input_bits_value1(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_input_bits_value1(result);
           svSetScope(prev);
        }
void setBits_input_bits_value1(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_input_bits_value1(data);
           svSetScope(prev);
        }
void getBitWidth_input_valid(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_input_valid(result);
           svSetScope(prev);
        }
void getBits_input_valid(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_input_valid(result);
           svSetScope(prev);
        }
void setBits_input_valid(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_input_valid(data);
           svSetScope(prev);
        }
void getBitWidth_input_ready(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_input_ready(result);
           svSetScope(prev);
        }
void getBits_input_ready(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_input_ready(result);
           svSetScope(prev);
        }
void getBitWidth_output_bits_gcd(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_output_bits_gcd(result);
           svSetScope(prev);
        }
void getBits_output_bits_gcd(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_output_bits_gcd(result);
           svSetScope(prev);
        }
void getBitWidth_output_bits_value2(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_output_bits_value2(result);
           svSetScope(prev);
        }
void getBits_output_bits_value2(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_output_bits_value2(result);
           svSetScope(prev);
        }
void getBitWidth_output_bits_value1(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_output_bits_value1(result);
           svSetScope(prev);
        }
void getBits_output_bits_value1(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_output_bits_value1(result);
           svSetScope(prev);
        }
void getBitWidth_output_valid(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_output_valid(result);
           svSetScope(prev);
        }
void getBits_output_valid(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_output_valid(result);
           svSetScope(prev);
        }
void getBitWidth_output_ready(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_output_ready(result);
           svSetScope(prev);
        }
void getBits_output_ready(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_output_ready(result);
           svSetScope(prev);
        }
void setBits_output_ready(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_output_ready(data);
           svSetScope(prev);
        }

int port_getter(int id, int *bitWidth, void (**getter)(uint8_t*)) {
  switch (id) {
    case 0: // clock
      getBitWidth_clock(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_clock;
      return 0;
    case 1: // reset
      getBitWidth_reset(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_reset;
      return 0;
    case 2: // input_bits_value2
      getBitWidth_input_bits_value2(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_input_bits_value2;
      return 0;
    case 3: // input_bits_value1
      getBitWidth_input_bits_value1(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_input_bits_value1;
      return 0;
    case 4: // input_valid
      getBitWidth_input_valid(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_input_valid;
      return 0;
    case 5: // input_ready
      getBitWidth_input_ready(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_input_ready;
      return 0;
    case 6: // output_bits_gcd
      getBitWidth_output_bits_gcd(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_output_bits_gcd;
      return 0;
    case 7: // output_bits_value2
      getBitWidth_output_bits_value2(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_output_bits_value2;
      return 0;
    case 8: // output_bits_value1
      getBitWidth_output_bits_value1(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_output_bits_value1;
      return 0;
    case 9: // output_valid
      getBitWidth_output_valid(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_output_valid;
      return 0;
    case 10: // output_ready
      getBitWidth_output_ready(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_output_ready;
      return 0;
    default:
      return -1;
  }
}

int port_setter(int id, int *bitWidth, void (**setter)(const uint8_t*)) {
  switch (id) {
    case 0: // clock
      getBitWidth_clock(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_clock;
      return 0;
    case 1: // reset
      getBitWidth_reset(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_reset;
      return 0;
    case 2: // input_bits_value2
      getBitWidth_input_bits_value2(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_input_bits_value2;
      return 0;
    case 3: // input_bits_value1
      getBitWidth_input_bits_value1(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_input_bits_value1;
      return 0;
    case 4: // input_valid
      getBitWidth_input_valid(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_input_valid;
      return 0;
    case 10: // output_ready
      getBitWidth_output_ready(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_output_ready;
      return 0;
    default:
      return -1;
  }
}

} // extern "C"

