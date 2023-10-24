onbreak {quit -force}
onerror {quit -force}

asim -t 1ps +access +r +m+nexys_shell -L xilinx_vip -L xil_defaultlib -L xpm -L xlconstant_v1_1_6 -L lib_cdc_v1_0_2 -L proc_sys_reset_v5_0_13 -L smartconnect_v1_0 -L unisims_ver -L unimacro_ver -L secureip -O5 xil_defaultlib.nexys_shell xil_defaultlib.glbl

do {wave.do}

view wave
view structure

do {nexys_shell.udo}

run -all

endsim

quit -force
