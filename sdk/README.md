# Compiling Executeables
Place your C (`.c`) and assembly (`.s` or `.S`) source files in the src directory.

## For Linux Users
Run ```make all``` to build the executeable. This produces a build directory, containing:

 - object files (`.o`) produced from the source code
 - a `main.txt` file which is the memory image for use in the simulator
 - a `main.hex` file which is the memory image to program the FPGA's RAM with
 - a `program.dump` file which is the full disassembled program output.
 - and some intermediate `.bin` and `.elf` files which can be ignored.

## For Windows Users
Run `make.bat` to build the executable. This produces a build directory, containing:

 - object files (`.o`) produced from the source code
 - a `main.txt` file which is the memory image for use in the simulator
 - a `main.hex` file which is the memory image to program the FPGA's RAM with
 - a `program.dump` file which is the full disassembled program output.
 - and some intermediate `.bin` and `.elf` files which can be ignored.

