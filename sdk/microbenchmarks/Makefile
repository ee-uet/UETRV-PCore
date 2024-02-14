#*********************************************************************
#  * Filename :    Makefile
#  * Date     :    02-5-2023
#  * Author   :    Ali Imran @ALI11-2000
#  *
#  * Description:  Makefile for compiling Code
#  *********************************************************************

march   ?= rv32ima_zicsr
build   ?= build
SRCS    ?= $(build)/startup.o $(build)/isr.o $(build)/uart.o $(build)/plic.o $(build)/main.o
OUTPUTS ?= $(build)/main.elf $(build)/main.bin $(build)/main.txt $(build)/main.dump

$(build)/%.o : src/%.s
	mkdir -p $(build)
	riscv64-unknown-elf-as -c -o $@ $< -march=$(march) -mabi=ilp32

$(build)/%.o : src/%.c
	mkdir -p $(build)
	riscv64-unknown-elf-gcc -c -o $@ $< -march=$(march) -mabi=ilp32

$(build)/%.o : Interfaces/%.c
	mkdir -p $(build)
	riscv64-unknown-elf-gcc -c -o $@ $< -march=$(march) -mabi=ilp32

$(build)/%.elf: $(SRCS)
	riscv64-unknown-elf-gcc -O -o $@ $^ -T linker.ld -nostdlib -march=$(march) -mabi=ilp32

$(build)/%.bin: $(build)/%.elf
	riscv64-unknown-elf-objcopy -O binary --only-section=.data* --only-section=.text* $< $@

$(build)/%.txt : $(build)/%.bin
	python3 maketxt.py $< > $@
	cp -a $(build)/main.txt $(build)/hello.hex

$(build)/%.dump: $(build)/%.elf
	riscv64-unknown-elf-objdump -S -s $< > $@

all: $(OUTPUTS)
	@echo "Done"

.NOTINTERMEDIATE: $(SRCS)

clean:
	rm -rf build
