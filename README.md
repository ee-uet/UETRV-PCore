# UETRV_Pcore
[![pcore-riscof](https://github.com/ee-uet/UETRV-PCore/actions/workflows/main.yml/badge.svg)](https://github.com/ee-uet/UETRV-PCore/actions/workflows/main.yml)
[![Documentation status](https://img.shields.io/badge/Docs-Passing-brightgreen)](https://uetrv-pcore-doc.readthedocs.io/en/main/index.html)

UETRV_Pcore is a RISC-V based application class SoC integrating a 5-stage pipelined processor with memory and peripherals. Currently, the core implements RV32IMAZicsr ISA based on User-level ISA Version 2.0 and Privileged Architecture Version 1.11 supporting M/S/U modes. Following are the key features of the SoC:

## Key Features
- 32-bit RISC-V ISA core that supports base integer (I) and multiplication and division (M), atomic (A) and Zicsr (Z) extensions (RV32IMAZicsr).
- Supports user, supervisor and machine mode privilege levels.
- Support for instruction / data (writeback) caches.
- Sv32 based MMU support and is capable of running Linux.
- Cache size, TLB entries etc., are configurable.
- Intergated PLIC, CLINT, uart, spi peripherals. 
- Uses RISOF framework to run architecture compatibility tests.

### System Design Overview
The UETRV_Pcore is an applicaion class processor capable of running Linux. A simplified 5-stage pipelined block diagram is shown below. The M-extension is implemented as a coprocessor while memory-management-unit (MMU) module is shared by instruction and data memory (alternatively called load-store-unit (LSU)) interfaces of the pipeline. Specifically, the page-table-walker (PTW) of the MMU is shared and there are separate TLBs (translation look aside buffers) for instruction and data memory interfaces. The A-extension is implemented as part of the LSU module.

![pipeline](./docs/images/pipeline.png)

The SoC block diagram shows the connectivity of the core with memory sub-system as well as different peripherals using data bus. The boot memory is connected to both instruction and data buses of the core using a bus multiplexer. The instruction and data caches share the main memory using a bus arbiter. Different necessary peripherals are connected using the data bus. Further details related to the SoC design are available at <https://uetrv-pcore-doc.readthedocs.io/en/main/>.

![soc](./docs/images/soc.png)

### SoC Memory Map
The memory map for the SOC is provided in the following table.
| Base Address        |    Description            |   Attributes    |
|:-------------------:|:-------------------------:|:---------------:|
| 0x8000_0000         |      Memory               |      R-X-W      |
| 0x9000_0000         |      UART                 |      R-W        |
| 0x9400_0000         |      PLIC                 |      R-W        |
| 0x9C00_0000         |      SPI                  |      R-W        |
| 0x0200_0000         |      CLINT                |      R-W        |
| 0x0000_1000         |      Boot Memory          |      R-X        |

- `R: Read access`
- `W: Write access`
- `X: Execute access`


## Getting Started

Install RISC-V [toolchain](https://github.com/riscv-collab/riscv-gnu-toolchain) and [verilator](https://verilator.org/guide/latest/install.html). These tools can be built by following the instructions in the corresponding links, or can be installed directly by running the following command

    sudo apt-get install -y gcc-riscv64-unknown-elf verilator gtkwave

Check that these tools are installed correctly, by running `verilator --version` and `riscv64-unknown-elf-gcc -v`.

### Build Model and Run Simulation

Verilator model of Pcore can be built using Makefile:

    make verilate

The verilator model is build under `ver_work/Vpcore_sim`. The executeable can accept the following three parameters:

- `imem`: This paramerter accepts the file that contain the hexadecimal instructions of compiled program.
- `max_cycles`: This parameter cotrols the maxiumum number of cycles for simulation. Simulation terminates after executing these many cycles.
- `vcd`: This parameters accepts a boolean value. If it is 0, the waveform file `trace.vcd` will not be dumped and vice versa.

An example program to print `HELLO` on terminal via UART is compiled and its hex instructions are availabe in [here](/sdk/example-uart/hello.hex). Run the following command to simulate the example program

    make sim-verilate-uart 

This will simulate `hello.hex` and dump UART logs in `uart_logdata.log` file. If `vcd=1` is added to the above command, `trace.vcd` will be created that can be viewed by running

    gtkwave trace.vcd

The `imem` and `max_cycles` may be overwritten in Makefile using.

    make sim-verilate-uart imem=</path/to/hex/file> max_cycles=<No. of cycles> 

### Verification

UETRV_Pcore uses RISOF framework to run Architecture Compatibility Tests (ACTs). Instructions to run these tests can be followed in [verif](/verif/) directory.

## Booting Linux

Using the same procedure as outlined above, we can simulate the Linux bootup using a prebuilt image (`imem.zip`) available in `./sdk/example-linux/` folder. The pre-built Linux image is prepared using `initramfs` based root file system (`rootfs`) and is directly linked into the kernel. Furthermore, the Linux/kernel image is linked as a `payload` to the `OpenSBI` that acts as a first-level bootloader. The `imem.zip` image contains:

- Root file system (`rootfs.cpio`) based on `initramfs` using Busybox 1.33
- The Linux (version 6.1.0) with rootfs.cpio linked into the kernel
- OpenSBI (ver. 0.9) based first order bootloader with Linux kernel as payload

During booting process, the processor starts executing zero-level bootloader from `bmem` and then jumps to first-level bootloader (OpenSBI), which after necessary initializations, hands the control over to the kernel.    

Now run the following command to extract the `imem.txt` to `./sdk/example-linux/` and simulate the Linux booting process using this pre-built image. 

    make sim-verilate-linux

The output is logged to the `uart_logdata.log` file (a copy of this log is available in `./sdk/`), with selected logs listed below. 

```
OpenSBI v0.9
   ____                    _____ ____ _____
  / __ \                  / ____|  _ \_   _|
 | |  | |_ __   ___ _ __ | (___ | |_) || |
 | |  | | '_ \ / _ \ '_ \ \___ \|  _ < | |
 | |__| | |_) |  __/ | | |____) | |_) || |_
  \____/| .__/ \___|_| |_|_____/|____/_____|
        | |
        |_|

Platform Name             : uet_pcore,v0
Platform Features         : medeleg
Platform HART Count       : 1
Platform IPI Device       : aclint-mswi
Platform Timer Device     : aclint-mtimer @ 10000000Hz
Platform Console Device   : sifive_uart
Platform HSM Device       : ---

...

Boot HART ISA             : rv32imasu
Boot HART Features        : scounteren,mcounteren,mcountinhibit,time
Boot HART PMP Count       : 0
Boot HART PMP Granularity : 0
Boot HART PMP Address Bits: 0
Boot HART MHPM Count      : 0
Boot HART MIDELEG         : 0x00000222
Boot HART MEDELEG         : 0x0000b109
[    0.000000] Linux version 6.1.0 (mtahir@mtahir-Inspiron-7520) (riscv32-unknown-linux-gnu-gcc (GCC) 8.1.0, GNU ld (GNU Binutils) 2.30) #8 Fri Jun 23 15:26:45 PKT 2023

[    0.000000] OF: fdt: Ignoring memory range 0x80000000 - 0x80400000

[    0.000000] Machine model: uet_pcore,v0

[    0.000000] earlycon: sbi0 at I/O port 0x0 (options '')

[    0.000000] printk: bootconsole [sbi0] enabled

...

[    0.004219] clocksource: Switched to clocksource riscv_clocksource

[    0.010208] workingset: timestamp_bits=30 max_order=15 bucket_order=0

[    0.079288] 90000000.serial: ttySIF0 at MMIO 0x90000000 (irq = 1, base_baud = 619200) is a SiFive UART v0

[    0.089824] debug_vm_pgtable: [debug_vm_pgtable         ]: Validating architecture page table helpers

[    0.096405] Freeing unused kernel image (initmem) memory: 8176K

[    0.096473] Run /init as init process

init started: BusyBox v1.33.0 (2023-06-23 15:18:29 PKT)

#
``` 
