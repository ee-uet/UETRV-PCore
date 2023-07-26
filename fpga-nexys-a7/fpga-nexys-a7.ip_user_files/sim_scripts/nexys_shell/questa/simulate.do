onbreak {quit -f}
onerror {quit -f}

vsim -lib xil_defaultlib nexys_shell_opt

set NumericStdNoWarnings 1
set StdArithNoWarnings 1

do {wave.do}

view wave
view structure
view signals

do {nexys_shell.udo}

run -all

quit -force
