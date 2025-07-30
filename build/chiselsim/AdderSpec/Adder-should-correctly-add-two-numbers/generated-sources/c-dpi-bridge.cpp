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
void getBitWidth_io_sum(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_sum(result);
           svSetScope(prev);
        }
void getBits_io_sum(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_sum(result);
           svSetScope(prev);
        }
void getBitWidth_io_b(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_b(result);
           svSetScope(prev);
        }
void getBits_io_b(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_b(result);
           svSetScope(prev);
        }
void setBits_io_b(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_b(data);
           svSetScope(prev);
        }
void getBitWidth_io_a(int* result) {
           svScope prev = setScopeToTestBench();
           getBitWidthImpl_io_a(result);
           svSetScope(prev);
        }
void getBits_io_a(svBitVecVal* result) {
           svScope prev = setScopeToTestBench();
           getBitsImpl_io_a(result);
           svSetScope(prev);
        }
void setBits_io_a(const svBitVecVal* data) {
           svScope prev = setScopeToTestBench();
           setBitsImpl_io_a(data);
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
    case 2: // io_sum
      getBitWidth_io_sum(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_sum;
      return 0;
    case 3: // io_b
      getBitWidth_io_b(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_b;
      return 0;
    case 4: // io_a
      getBitWidth_io_a(bitWidth);
      *getter = (void(*)(uint8_t*))getBits_io_a;
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
    case 3: // io_b
      getBitWidth_io_b(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_b;
      return 0;
    case 4: // io_a
      getBitWidth_io_a(bitWidth);
      *setter = (void(*)(const uint8_t*))setBits_io_a;
      return 0;
    default:
      return -1;
  }
}

} // extern "C"

