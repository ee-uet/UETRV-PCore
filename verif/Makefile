compile:
	vlog +define+COMPLIANCE_TEST=1 -work work ../rtl/defines/*.svh ../rtl/core/*.sv ../rtl/interconnect/*.sv ../rtl/memory/dualport_mem.sv ../rtl/peripherals/clint/*.sv ../rtl/peripherals/uart/*.sv ../rtl/tb/core_tb.sv ../rtl/core/pipeline/*.sv 

run:
	vsim -c -do "run -all" core_tb -Gtimeout=18000 +signature=pcore.signature +memfile=pcore-add-01.hex -quiet

clean:
	rm -rf vsim.wlf pcore.log transcript pcore.signature work/ core_tb.vcd
