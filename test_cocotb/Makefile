SIM ?= icarus
TOPLEVEL_LANG ?= verilog

# 🔧 Verilog 소스는 'TOPLEVEL' 변수 기준으로 지정
VERILOG_SOURCES += $(PWD)/../generated/verilog/$(TOPLEVEL).sv

TOPLEVEL = $(MODULE_NAME)
MODULE = tb_$(MODULE_NAME)

include $(shell cocotb-config --makefiles)/Makefile.sim

