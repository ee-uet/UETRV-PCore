TOPLEVEL_LANG = verilog
SIM = verilator
TOPLEVEL = mmu.mmu
MODULE = mmu  # Your testbench Python file (without .py)

VERILOG_SOURCES = /home/masooma/UETRV-PCore-main/rtl/core/mmu/*.sv
EXTRA_ARGS = -I/home/masooma/UETRV-PCore-main/rtl/defines
EXTRA_ARGS += --trace --trace-structs
# Additional Verilator arguments
VERILATOR_ARGS = --cc --exe --trace --vcd

# Export EXTRA_ARGS so Verilator picks up the include path
export EXTRA_ARGS

# Enable VCD dumping
WAVES = 1

# Include the cocotb makefile
include $(shell cocotb-config --makefiles)/Makefile.sim
