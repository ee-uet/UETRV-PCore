verilator -cc $(find ../rtl/ -type f -name "*.sv") -I../rtl/defines/ --top-module core_tb -Wno-TIMESCALEMOD -Wno-MULTIDRIVEN -Wno-CASEOVERLAP -Wno-WIDTH -Wno-LATCH -Wno-UNOPTFLAT -Wno-LATCH -Wno-IMPLICIT --exe tb_core.cpp
make -C obj_dir -f Vcore_tb.mk Vcore_tb
./obj_dir/Vcore_tb