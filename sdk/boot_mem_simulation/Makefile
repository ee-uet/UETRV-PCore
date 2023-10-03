bmem_txt  = bmem.txt 
bmem_sv   = bmem.sv
pcore_dtb = dtpcore.dtb

RISCV_GCC?=riscv32-unknown-linux-gnu-gcc
RISCV_OBJCOPY?=riscv32-unknown-linux-gnu-objcopy

PYTHON=python3

build_sv: $(bmem_sv)
%.sv: %.txt
	$(PYTHON) ./make_sv.py $< >> $@
	cp bmem.sv ../rtl/memory/

build_txt: $(bmem_txt)
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
	rm -f $(bmem_sv) $(bmem_txt) $(pcore_dtb)
