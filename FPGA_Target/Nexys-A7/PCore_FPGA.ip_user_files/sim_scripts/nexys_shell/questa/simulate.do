onbreak {quit -f}
onerror {quit -f}

vsim -t 1ps -lib xil_defaultlib nexys_shell_opt

do {wave.do}

view wave
view structure
view signals

do {nexys_shell.udo}

run -all

quit -force
