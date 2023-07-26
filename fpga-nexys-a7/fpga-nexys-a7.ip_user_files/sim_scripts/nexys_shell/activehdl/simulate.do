onbreak {quit -force}
onerror {quit -force}

asim +access +r +m+nexys_shell -L xpm -L unisims_ver -L unimacro_ver -L secureip -O5 xil_defaultlib.nexys_shell xil_defaultlib.glbl

set NumericStdNoWarnings 1
set StdArithNoWarnings 1

do {wave.do}

view wave
view structure

do {nexys_shell.udo}

run -all

endsim

quit -force
