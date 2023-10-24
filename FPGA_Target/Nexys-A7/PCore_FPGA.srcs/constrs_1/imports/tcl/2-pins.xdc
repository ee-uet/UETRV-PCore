## This file is a general .xdc for the Arty A7-100 Rev. D and Rev. E
## To use it in a project:
## - uncomment the lines corresponding to used pins
## - rename the used ports (in each line, after get_ports) according to the top level signal names in the project


###############################################################################################
## main.xdc for NEXYS A7   ArchLab TOKYO TECH
###############################################################################################

## 100MHz system clock
###############################################################################################
set_property -dict { PACKAGE_PIN E3  IOSTANDARD LVCMOS33} [get_ports { CLK100MHZ }];
create_clock -add -name sys_clk -period 10.00 [get_ports { CLK100MHZ }];
#create_clock -add -name sys_clk_pin -period 10.00 -waveform {0 5} [get_ports { CLK100MHZ }];

## CPU Reset
###############################################################################################
set_property -dict { PACKAGE_PIN C12 IOSTANDARD LVCMOS33} [get_ports { ck_rst }];

## UART (Serial Port)
###############################################################################################
set_property -dict { PACKAGE_PIN D4  IOSTANDARD LVCMOS33} [get_ports { uart_txd_out }];
set_property -dict { PACKAGE_PIN C4  IOSTANDARD LVCMOS33} [get_ports { uart_rxd_in }];
#set_property -dict { PACKAGE_PIN C17  IOSTANDARD LVCMOS33} [get_ports { uart_ns_txd_out }];
#set_property -dict { PACKAGE_PIN D18  IOSTANDARD LVCMOS33} [get_ports { uart_ns_rxd_in }];

#set_property -dict { PACKAGE_PIN D4  IOSTANDARD LVCMOS33} [get_ports { uart_ns_txd_out  }];
#set_property -dict { PACKAGE_PIN C4  IOSTANDARD LVCMOS33} [get_ports { uart_ns_rxd_in }];
#set_property -dict { PACKAGE_PIN C17  IOSTANDARD LVCMOS33} [get_ports { uart_txd_out }];
#set_property -dict { PACKAGE_PIN D18  IOSTANDARD LVCMOS33} [get_ports { uart_rxd_in }];

###############################################################################################
#create_generated_clock -name mig_in_clk [get_pins m_clkgen0/inst/mmcm_adv_inst/CLKOUT0]
#set_clock_groups -asynchronous -group {mig_in_clk}

##create_generated_clock -name core_clk [get_pins mem_ctrl/dram_con/dram/dram/dram_con_witout_cache/clkgen1/inst/mmcm_adv_inst/CLKOUT0]
#create_generated_clock -name core_clk [get_pins c/dram_con/dram/dram/dram_con_witout_cache/clkgen1/inst/mmcm_adv_inst/CLKOUT0]
#set_clock_groups -asynchronous -group {core_clk}

###############################################################################################
#set_property -dict { PACKAGE_PIN H17 IOSTANDARD LVCMOS33} [get_ports { w_led[0] }];
#set_property -dict { PACKAGE_PIN K15 IOSTANDARD LVCMOS33} [get_ports { w_led[1] }];
#set_property -dict { PACKAGE_PIN J13 IOSTANDARD LVCMOS33} [get_ports { w_led[2] }];
#set_property -dict { PACKAGE_PIN N14 IOSTANDARD LVCMOS33} [get_ports { w_led[3] }];
#set_property -dict { PACKAGE_PIN R18 IOSTANDARD LVCMOS33} [get_ports { w_led[4] }];
#set_property -dict { PACKAGE_PIN V17 IOSTANDARD LVCMOS33} [get_ports { w_led[5] }];
#set_property -dict { PACKAGE_PIN U17 IOSTANDARD LVCMOS33} [get_ports { w_led[6] }];
#set_property -dict { PACKAGE_PIN U16 IOSTANDARD LVCMOS33} [get_ports { w_led[7] }];
#set_property -dict { PACKAGE_PIN V16 IOSTANDARD LVCMOS33} [get_ports { w_led[8] }];
#set_property -dict { PACKAGE_PIN T15 IOSTANDARD LVCMOS33} [get_ports { w_led[9] }];
#set_property -dict { PACKAGE_PIN U14 IOSTANDARD LVCMOS33} [get_ports { w_led[10] }];
#set_property -dict { PACKAGE_PIN T16 IOSTANDARD LVCMOS33} [get_ports { w_led[11] }];
#set_property -dict { PACKAGE_PIN V15 IOSTANDARD LVCMOS33} [get_ports { w_led[12] }];
#set_property -dict { PACKAGE_PIN V14 IOSTANDARD LVCMOS33} [get_ports { w_led[13] }];
#set_property -dict { PACKAGE_PIN V12 IOSTANDARD LVCMOS33} [get_ports { w_led[14] }];
#set_property -dict { PACKAGE_PIN V11 IOSTANDARD LVCMOS33} [get_ports { w_led[15] }];


###############################################################################################
#set_property -dict { PACKAGE_PIN R12 IOSTANDARD LVCMOS33 } [get_ports { w_led1_B }]; 
#set_property -dict { PACKAGE_PIN M16 IOSTANDARD LVCMOS33 } [get_ports { w_led1_G }]; 
#set_property -dict { PACKAGE_PIN N15 IOSTANDARD LVCMOS33 } [get_ports { w_led1_R }]; 
# set_property -dict { PACKAGE_PIN G14 IOSTANDARD LVCMOS33 } [get_ports { w_led2_B }];
# set_property -dict { PACKAGE_PIN R11 IOSTANDARD LVCMOS33 } [get_ports { w_led2_G }];
# set_property -dict { PACKAGE_PIN N16 IOSTANDARD LVCMOS33 } [get_ports { w_led2_R }];

###############################################################################################
set_property -dict { PACKAGE_PIN T10 IOSTANDARD LVCMOS33} [get_ports { r_sg[6] }]; # segment a
set_property -dict { PACKAGE_PIN R10 IOSTANDARD LVCMOS33} [get_ports { r_sg[5] }]; # segment b
set_property -dict { PACKAGE_PIN K16 IOSTANDARD LVCMOS33} [get_ports { r_sg[4] }]; # segment c
set_property -dict { PACKAGE_PIN K13 IOSTANDARD LVCMOS33} [get_ports { r_sg[3] }]; # segment d
set_property -dict { PACKAGE_PIN P15 IOSTANDARD LVCMOS33} [get_ports { r_sg[2] }]; # segment e
set_property -dict { PACKAGE_PIN T11 IOSTANDARD LVCMOS33} [get_ports { r_sg[1] }]; # segment f
set_property -dict { PACKAGE_PIN L18 IOSTANDARD LVCMOS33} [get_ports { r_sg[0] }]; # segment g
set_property -dict { PACKAGE_PIN H15 IOSTANDARD LVCMOS33} [get_ports { r_sg[7] }]; # segment .

set_property -dict { PACKAGE_PIN J17 IOSTANDARD LVCMOS33} [get_ports { r_an[0] }];
set_property -dict { PACKAGE_PIN J18 IOSTANDARD LVCMOS33} [get_ports { r_an[1] }];
set_property -dict { PACKAGE_PIN T9  IOSTANDARD LVCMOS33} [get_ports { r_an[2] }];
set_property -dict { PACKAGE_PIN J14 IOSTANDARD LVCMOS33} [get_ports { r_an[3] }];
set_property -dict { PACKAGE_PIN P14 IOSTANDARD LVCMOS33} [get_ports { r_an[4] }];
set_property -dict { PACKAGE_PIN T14 IOSTANDARD LVCMOS33} [get_ports { r_an[5] }];
set_property -dict { PACKAGE_PIN K2  IOSTANDARD LVCMOS33} [get_ports { r_an[6] }];
set_property -dict { PACKAGE_PIN U13 IOSTANDARD LVCMOS33} [get_ports { r_an[7] }];

###############################################################################################
#set_property -dict { PACKAGE_PIN M18 IOSTANDARD LVCMOS33} [get_ports { w_btnu }];
# set_property -dict { PACKAGE_PIN P18 IOSTANDARD LVCMOS33} [get_ports { w_btnd }];
# set_property -dict { PACKAGE_PIN P17 IOSTANDARD LVCMOS33} [get_ports { w_btnl }];
# set_property -dict { PACKAGE_PIN M17 IOSTANDARD LVCMOS33} [get_ports { w_btnr }];
#set_property -dict { PACKAGE_PIN N17 IOSTANDARD LVCMOS33} [get_ports { w_btnc }];
###############################################################################################
# set_property -dict { PACKAGE_PIN J15 IOSTANDARD LVCMOS33 } [get_ports { w_sw[0] }]; 
# set_property -dict { PACKAGE_PIN L16 IOSTANDARD LVCMOS33 } [get_ports { w_sw[1] }]; 
# set_property -dict { PACKAGE_PIN M13 IOSTANDARD LVCMOS33 } [get_ports { w_sw[2] }]; 
# set_property -dict { PACKAGE_PIN R15 IOSTANDARD LVCMOS33 } [get_ports { w_sw[3] }]; 
# set_property -dict { PACKAGE_PIN R17 IOSTANDARD LVCMOS33 } [get_ports { w_sw[4] }]; 
# set_property -dict { PACKAGE_PIN T18 IOSTANDARD LVCMOS33 } [get_ports { w_sw[5] }]; 
# set_property -dict { PACKAGE_PIN U18 IOSTANDARD LVCMOS33 } [get_ports { w_sw[6] }]; 
# set_property -dict { PACKAGE_PIN R13 IOSTANDARD LVCMOS33 } [get_ports { w_sw[7] }]; 
# set_property -dict { PACKAGE_PIN T8  IOSTANDARD LVCMOS18 } [get_ports { w_sw[8] }]; 
# set_property -dict { PACKAGE_PIN U8  IOSTANDARD LVCMOS18 } [get_ports { w_sw[9] }]; 
# set_property -dict { PACKAGE_PIN R16 IOSTANDARD LVCMOS33 } [get_ports { w_sw[10] }];
# set_property -dict { PACKAGE_PIN T13 IOSTANDARD LVCMOS33 } [get_ports { w_sw[11] }];
# set_property -dict { PACKAGE_PIN H6  IOSTANDARD LVCMOS33 } [get_ports { w_sw[12] }];
# set_property -dict { PACKAGE_PIN U12 IOSTANDARD LVCMOS33 } [get_ports { w_sw[13] }];
# set_property -dict { PACKAGE_PIN U11 IOSTANDARD LVCMOS33 } [get_ports { w_sw[14] }];
# set_property -dict { PACKAGE_PIN V10 IOSTANDARD LVCMOS33 } [get_ports { w_sw[15] }];
###############################################################################################
