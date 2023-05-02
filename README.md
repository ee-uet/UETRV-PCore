# Getting Started

Install RISC-V [toolchain](https://github.com/riscv-collab/riscv-gnu-toolchain) and [verilator](https://verilator.org/guide/latest/install.html). These tools can be built by following the instructions in the corresponding links, or can be installed directly by running the following command

    sudo apt-get install -y gcc-riscv64-unknown-elf verilator gtkwave

Check that these tools are installed correctly, by running `verilator --version` and `riscv64-unknown-elf-gcc -v`.

### Build Model and Run Simulation

Verilator model of Pcore can be built using Makefil:

    make verilate

The verilator model is build under `ver_work/Vpcore_sim`. The executeable can accept the following three parameters:

- `imem` : This paramerter accepts the file that contain the hexadecimal instructions of compiled program.
- `max_cycles`: This parameter the maxiumum number of cycles for simulation. Simulation terminates after executing these number of cycles.
- `vcd`: This parameters accepts a boolean value. If it is 0, the waveform file `trace.vcd` will not be dumped and vice versa.

An example program to print `HELLO` on UART is compiled and its hex instructions are availabe in [here](/software/example-uart/build/imem.txt). Run the folllowing command to simulate the example program

    make sim-verilate 

This will simulate `imem.txt` and dump UART logs in `uart_logdata.log`. If `vcd=1` is added to the above command, `trace.vcd` will created that can be viewed by running

    gtkwave trace.vcd

The `imem` and `max_cycles` by be overwritten in Makefile using.

    make sim-verilate imem=</path/to/hex/file> max_cycles=<No. of cycles> 

### Verification

Pcore uses RISOF framework to run Architecture Compatibility Tests (ACTs). Instructions to run these tests can be followed in [verif](/verif/) directory.