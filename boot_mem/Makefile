bootrom_out=bmem.txt 
pcore_dtb = dtpcore.dtb

RISCV_GCC?=riscv32-unknown-linux-gnu-gcc
RISCV_OBJCOPY?=riscv32-unknown-linux-gnu-objcopy

PYTHON=python3

build: $(bootrom_out)

%.txt: %.bin
	$(PYTHON) ./make_txt.py $< >> $@

%.bin: %.elf
	$(RISCV_OBJCOPY) -O binary $< $@

%.elf: %.S linker.ld $(pcore_dtb)
	$(RISCV_GCC) -Tlinker.ld -march=rv32i -mabi=ilp32 $< -nostdlib -static -Wl,--no-gc-sections -o $@

device_tree: $(pcore_dtb)
%.dtb: %.dts
	dtc -I dts $< -O dtb -o $@

clean:
	rm -f $(bootrom_out) $(pcore_dtb)
