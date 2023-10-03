bmem_dump = bmem.dump
bmem_txt  = bmem.txt 
bmem_sv   = bmem.sv
bmem_elf  = bmem.elf
pcore_dtb = dtpcore.dtb

march   ?= rv32ima
SRCS    ?= bmem.o uart.o main.o
OUTPUTS ?= main.elf main.bin main.txt main.dump

RISCV_GCC?=riscv32-unknown-linux-gnu-gcc
RISCV_OBJCOPY?=riscv32-unknown-linux-gnu-objcopy

PYTHON=python3

build_sv: $(bmem_sv)
%.sv: %.txt
	$(PYTHON) ./make_sv.py $< >> $@
	cp ./build/bmem.sv ../rtl/memory/

build_txt: $(bmem_txt)
%.txt : %.bin
	$(PYTHON) ./make_txt.py $< >> $@
#	python3 ./make_bin.py imem1.bin imem.bin

%.bin: %.elf
	$(RISCV_OBJCOPY) -O binary $< $@

build_dump: $(bmem_dump)
%.dump : %.elf
	riscv32-unknown-linux-gnu-objdump -S -s $< > $@

build_elf: $(bmem_elf)
%.elf: $(SRCS)
	riscv32-unknown-linux-gnu-gcc -O -o $@ $^ -T linker.ld -nostdlib -march=$(march) -mabi=ilp32

%.o : %.c
	riscv32-unknown-linux-gnu-gcc -c -o $@ $< -march=$(march) -mabi=ilp32
%.o : Interfaces/%.c
	riscv32-unknown-linux-gnu-gcc -c -o $@ $< -march=$(march) -mabi=ilp32

%.o : %.S
	riscv32-unknown-linux-gnu-as -c -o $@ $< -march=$(march) -mabi=ilp32

device_tree: $(pcore_dtb)
%.dtb: %.dts
	dtc -I dts $< -O dtb -o $@

clean:
	rm -f $(bmem_sv) $(bmem_txt) $(bmem_elf)

