# UETRV_Pcore
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

![pipeline](../docs/pipeline.png)

The SoC block diagram shows the connectivity of the core with memory sub-system as well as different peripherals using data bus. The boot memory is connected to both instruction and data buses of the core using a bus multiplexer. The instruction and data caches share the main memory using a bus arbiter. Different necessary peripherals are connected using the data bus. 

![soc](../docs/soc.png)

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

- `imem` : This paramerter accepts the file that contain the hexadecimal instructions of compiled program.
- `max_cycles`: This parameter cotrols the maxiumum number of cycles for simulation. Simulation terminates after executing these many cycles.
- `vcd`: This parameters accepts a boolean value. If it is 0, the waveform file `trace.vcd` will not be dumped and vice versa.

An example program to print `HELLO` on UART is compiled and its hex instructions are availabe in [here](/software/example-uart/build/imem.txt). Run the folllowing command to simulate the example program

    make sim-verilate 

This will simulate `imem.txt` and dump UART logs in `uart_logdata.log`. If `vcd=1` is added to the above command, `trace.vcd` will created that can be viewed by running

    gtkwave trace.vcd

The `imem` and `max_cycles` may be overwritten in Makefile using.

    make sim-verilate imem=</path/to/hex/file> max_cycles=<No. of cycles> 

### Verification

UETRV_Pcore uses RISOF framework to run Architecture Compatibility Tests (ACTs). Instructions to run these tests can be followed in [verif](/verif/) directory.
