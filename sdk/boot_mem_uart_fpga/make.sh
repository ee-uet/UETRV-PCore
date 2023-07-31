
dtc -O dtb -o dtpcore.dtb dtpcore.dts

riscv64-unknown-elf-as -c -o build/bmem.o bmem.S -march=rv32im -mabi=ilp32

riscv64-unknown-elf-gcc -c -O -o build/main.o main.c -march=rv32im -mabi=ilp32

riscv64-unknown-elf-gcc -c -O -o build/uart.o Interfaces/uart.c -march=rv32im -mabi=ilp32

riscv64-unknown-elf-gcc -O -o build/main.elf build/bmem.o build/uart.o build/main.o -T linker.ld -nostdlib -march=rv32i -mabi=ilp32

riscv64-unknown-elf-objcopy -O binary --only-section=.data* --only-section=.text* build/main.elf build/main.bin

python3 make_txt.py build/main.bin > build/bmem.txt

python3 make_sv.py build/bmem.txt

riscv64-unknown-elf-objdump -S -s build/main.elf > build/main.dump

# python make_bin.py imem1.bin 

cp build/bmem.sv ../../fpga-shells/AXI_new/AXI_new.srcs/sources_1/imports/rtl/memory/bmem.sv
