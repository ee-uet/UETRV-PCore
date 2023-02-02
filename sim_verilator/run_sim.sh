verilator -cc $(find ../rtl/ -type f -name "*.sv") -I../rtl/defines/ --top-module core_tb -Wno-WIDTH -Wno-UNOPTFLAT -Wno-IMPLICIT --exe tb_core.cpp
make -C obj_dir -f Vcore_tb.mk Vcore_tb
./obj_dir/Vcore_tb