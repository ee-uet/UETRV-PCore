#*********************************************************************
#  * Filename :    Makefile
#  * Date     :    02-5-2023
#  * Author   :    @abdulwadoodd
#  *
#  * Description:  Makefile for simulating and testing UETRV_PCORE
#  *********************************************************************

verilator 	?= verilator
ver-library 	?= ver_work
defines 	?= 

# default command line arguments
imem 		?= software/example-uart/build/imem.txt
max_cycles  	?= 1000000
vcd 		?= 0

uartbuild_root := software/example-uart/build/

src := bench/pcore_sim.sv							\
	   rtl/core/core_top.sv							\
	   $(wildcard rtl/core/*/*.sv)						\
	   $(wildcard rtl/interconnect/*.sv)					\
	   $(wildcard rtl/memory/*.sv)						\
	   $(wildcard rtl/memory/*/*.sv)					\
       	   $(wildcard rtl/peripherals/*/*.sv)

incdir 	:= 	rtl/defines/
list_incdir := $(foreach dir, ${incdir}, +incdir+$(dir))

verilate_command := $(verilator) +define+$(defines) 				\
					--cc $(src) $(list_incdir)		\
					--top-module pcore_sim			\
					-Wno-TIMESCALEMOD 			\
					-Wno-MULTIDRIVEN 			\
					-Wno-CASEOVERLAP			\
					-Wno-WIDTH 				\
					-Wno-LATCH				\
					-Wno-UNOPTFLAT				\
					-Wno-LATCH				\
					-Wno-IMPLICIT				\
					-Wno-fatal                       	\
					-Wno-PINMISSING                     \
                    			-Wno-PINCONNECTEMPTY  		        \
                    			-Wno-ASSIGNDLY                      	\
                    			-Wno-DECLFILENAME                	\
                    			-Wno-UNUSED                        	\
                    			-Wno-BLKANDNBLK                   	\
                    			-Wno-style                          	\
					--Mdir $(ver-library)			\
					--exe bench/pcore_tb.cpp		\
					--trace-structs --trace

verilate:
	@echo "Building verilator model"
	$(verilate_command)
	cd $(ver-library) && $(MAKE) -f Vpcore_sim.mk

sim-verilate: verilate
	@echo "Running UART example program"
	$(ver-library)/Vpcore_sim +imem=$(imem) +max_cycles=$(max_cycles) +vcd=$(vcd)

clean-all:
	rm -rf ver_work/ *.log *.vcd 					\
	$(uartbuild_root)*.o  $(uartbuild_root)*.bin 			\
	$(uartbuild_root)*.hex $(uartbuild_root)*.elf 			\
	$(uartbuild_root)*.dump						\
	verif/*work/


