#*********************************************************************
#  * Filename :    Makefile
#  * Date     :    02-5-2023
#  * Author   :    @abdulwadoodd
#  *
#  * Description:  Makefile for simulating and testing UETRV_PCORE
#  *********************************************************************

verilator   ?= verilator
ver-library ?= ver_work
defines     ?= 

# default command line arguments
imem_uart  ?= sdk/example-uart/build/hello.hex
imem_linux ?= sdk/example-linux/imem.txt
max_cycles ?= 500000000
vcd        ?= 0

uartbuild_root := sdk/example-uart/build/

src := bench/pcore_tb.sv							\
	   $(wildcard rtl/*.sv)							\
	   $(wildcard rtl/core/*.sv)						\
	   $(wildcard rtl/core/pipeline/*.v)					\
	   $(wildcard rtl/core/*/*.sv)						\
	   $(wildcard rtl/interconnect/*.sv)					\
	   $(wildcard rtl/memory/*.sv)						\
	   $(wildcard rtl/memory/*/*.sv)					\
       	   $(wildcard rtl/peripherals/*/*.sv)

incdir 	:= 	rtl/defines/
list_incdir := $(foreach dir, ${incdir}, +incdir+$(dir))

verilate_command := $(verilator) +define+$(defines) 				\
					--cc $(src) $(list_incdir)		\
					--top-module pcore_tb			\
					-Wno-TIMESCALEMOD 			\
					-Wno-MULTIDRIVEN 			\
					-Wno-CASEOVERLAP 			\
        				-Wno-WIDTH  				\
					-Wno-UNOPTFLAT 				\
					-Wno-IMPLICIT 				\
					-Wno-PINMISSING 			\
					--Mdir $(ver-library)			\
					--exe bench/pcore_tb.cpp		\
					--trace-structs --trace

verilate:
	@echo "Building verilator model"
	$(verilate_command)
	cd $(ver-library) && $(MAKE) -f Vpcore_tb.mk

sim-verilate-uart: verilate
	@echo
	@echo
	@echo "Output is captured in uart_logdata.log"
	@echo
	$(ver-library)/Vpcore_tb +imem=$(imem_uart) +max_cycles=$(max_cycles) +vcd=$(vcd)

sim-verilate-linux: verilate
	@echo
	@echo "Extracting Linux Image..."
	@echo
	rm -f ./sdk/example-linux/imem.txt
	unzip ./sdk/example-linux/imem.zip -d ./sdk/example-linux/
	@echo
	@echo
	@echo "Output is captured in uart_logdata.log"
	@echo "Press ctrl+c to exit to the simulation"
	@echo
	@echo "Initiating Linux Bootup in Verilator Simulation..."
	@echo
	$(ver-library)/Vpcore_tb +imem=$(imem_linux) +max_cycles=300000000 +vcd=$(vcd)

run-freertos:
	@echo
	@echo "===== Starting FreeRTOS Deployment ====="
	@echo
	@echo "Initiating the process for task scheduling and generating the RTOS hex file..."
	cd FreeRTOS/Demo && make
	@echo
	@echo "Completed the process of generating the RTOS hex file..."
	@echo "Copying RTOSDemo.hex to the required directory..."
	cp FreeRTOS/Demo/build/RTOSDemo.hex sdk/example-uart/build/hello.hex
	@echo "RTOSDemo.hex successfully copied to sdk/example-uart/build/hello.hex"
	@echo
	@echo "===== Running Verilator Simulation with FreeRTOS ====="
	@echo "Output is captured in uart_logdata.log"
	$(ver-library)/Vpcore_tb +imem=$(imem_uart) +max_cycles=$(max_cycles) +vcd=$(vcd)
	@echo
	@echo "===== FreeRTOS Deployment and Simulation Completed ====="
	@echo

 
clean-all:
	rm -rf ver_work/ *.log *.vcd \
	verif/*work/

