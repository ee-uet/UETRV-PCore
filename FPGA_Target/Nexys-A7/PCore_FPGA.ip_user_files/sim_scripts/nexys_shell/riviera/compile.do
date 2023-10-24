vlib work
vlib riviera

vlib riviera/xilinx_vip
vlib riviera/xil_defaultlib
vlib riviera/xpm
vlib riviera/xlconstant_v1_1_6
vlib riviera/lib_cdc_v1_0_2
vlib riviera/proc_sys_reset_v5_0_13
vlib riviera/smartconnect_v1_0

vmap xilinx_vip riviera/xilinx_vip
vmap xil_defaultlib riviera/xil_defaultlib
vmap xpm riviera/xpm
vmap xlconstant_v1_1_6 riviera/xlconstant_v1_1_6
vmap lib_cdc_v1_0_2 riviera/lib_cdc_v1_0_2
vmap proc_sys_reset_v5_0_13 riviera/proc_sys_reset_v5_0_13
vmap smartconnect_v1_0 riviera/smartconnect_v1_0

vlog -work xilinx_vip  -sv2k12 "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi_vip_if.sv" \
"/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/clk_vip_if.sv" \
"/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work xil_defaultlib  -sv2k12 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"/home/mtahir/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_fifo/hdl/xpm_fifo.sv" \
"/home/mtahir/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \
"/home/mtahir/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \

vcom -work xpm -93 \
"/home/mtahir/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/nexys_shell/ip/nexys_shell_smartconnect_0_0_1/bd_0/sim/bd_4cab.v" \

vlog -work xlconstant_v1_1_6  -v2k5 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/66e7/hdl/xlconstant_v1_1_vl_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/nexys_shell/ip/nexys_shell_smartconnect_0_0_1/bd_0/ip/ip_0/sim/bd_4cab_one_0.v" \

vcom -work lib_cdc_v1_0_2 -93 \
"../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \

vcom -work proc_sys_reset_v5_0_13 -93 \
"../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \

vcom -work xil_defaultlib -93 \
"../../../bd/nexys_shell/ip/nexys_shell_smartconnect_0_0_1/bd_0/ip/ip_1/sim/bd_4cab_psr0_0.vhd" \
"../../../bd/nexys_shell/ip/nexys_shell_smartconnect_0_0_1/bd_0/ip/ip_2/sim/bd_4cab_psr_aclk_0.vhd" \
"../../../bd/nexys_shell/ip/nexys_shell_smartconnect_0_0_1/bd_0/ip/ip_3/sim/bd_4cab_psr_aclk1_0.vhd" \

vlog -work smartconnect_v1_0  -sv2k12 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/sc_util_v1_0_vl_rfs.sv" \
"../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/f85e/hdl/sc_mmu_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -sv2k12 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/nexys_shell/ip/nexys_shell_smartconnect_0_0_1/bd_0/ip/ip_4/sim/bd_4cab_s00mmu_0.sv" \

vlog -work smartconnect_v1_0  -sv2k12 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/ca72/hdl/sc_transaction_regulator_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -sv2k12 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/nexys_shell/ip/nexys_shell_smartconnect_0_0_1/bd_0/ip/ip_5/sim/bd_4cab_s00tr_0.sv" \

vlog -work smartconnect_v1_0  -sv2k12 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/7de4/hdl/sc_si_converter_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -sv2k12 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/nexys_shell/ip/nexys_shell_smartconnect_0_0_1/bd_0/ip/ip_6/sim/bd_4cab_s00sic_0.sv" \

vlog -work smartconnect_v1_0  -sv2k12 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b89e/hdl/sc_axi2sc_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -sv2k12 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/nexys_shell/ip/nexys_shell_smartconnect_0_0_1/bd_0/ip/ip_7/sim/bd_4cab_s00a2s_0.sv" \

vlog -work smartconnect_v1_0  -sv2k12 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/sc_node_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -sv2k12 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/nexys_shell/ip/nexys_shell_smartconnect_0_0_1/bd_0/ip/ip_8/sim/bd_4cab_sarn_0.sv" \
"../../../bd/nexys_shell/ip/nexys_shell_smartconnect_0_0_1/bd_0/ip/ip_9/sim/bd_4cab_srn_0.sv" \
"../../../bd/nexys_shell/ip/nexys_shell_smartconnect_0_0_1/bd_0/ip/ip_10/sim/bd_4cab_sawn_0.sv" \
"../../../bd/nexys_shell/ip/nexys_shell_smartconnect_0_0_1/bd_0/ip/ip_11/sim/bd_4cab_swn_0.sv" \
"../../../bd/nexys_shell/ip/nexys_shell_smartconnect_0_0_1/bd_0/ip/ip_12/sim/bd_4cab_sbn_0.sv" \

vlog -work smartconnect_v1_0  -sv2k12 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/7005/hdl/sc_sc2axi_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -sv2k12 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/nexys_shell/ip/nexys_shell_smartconnect_0_0_1/bd_0/ip/ip_13/sim/bd_4cab_m00s2a_0.sv" \

vlog -work smartconnect_v1_0  -sv2k12 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b387/hdl/sc_exit_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -sv2k12 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/nexys_shell/ip/nexys_shell_smartconnect_0_0_1/bd_0/ip/ip_14/sim/bd_4cab_m00e_0.sv" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/nexys_shell/ip/nexys_shell_smartconnect_0_0_1/sim/nexys_shell_smartconnect_0_0.v" \

vcom -work xil_defaultlib -93 \
"../../../bd/nexys_shell/ip/nexys_shell_proc_sys_reset_0_0_1/sim/nexys_shell_proc_sys_reset_0_0.vhd" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/1ddd/hdl/verilog" "+incdir+../../../../PCore_FPGA.srcs/sources_1/bd/nexys_shell/ipshared/b2d0/hdl/verilog" "+incdir+/home/mtahir/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../bd/nexys_shell/sim/nexys_shell.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/ecc/mig_7series_v4_2_ecc_dec_fix.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/ecc/mig_7series_v4_2_ecc_merge_enc.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/ecc/mig_7series_v4_2_ecc_gen.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/ecc/mig_7series_v4_2_ecc_buf.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/ecc/mig_7series_v4_2_fi_xor.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/clocking/mig_7series_v4_2_tempmon.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/clocking/mig_7series_v4_2_infrastructure.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/clocking/mig_7series_v4_2_iodelay_ctrl.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/clocking/mig_7series_v4_2_clk_ibuf.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/ip_top/mig_7series_v4_2_mem_intfc.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/ip_top/mig_7series_v4_2_memc_ui_top_axi.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_ddr_axi_upsizer.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_ddr_command_fifo.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_mc_wrap_cmd.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_mc_cmd_translator.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_ctrl_addr_decode.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_ddr_carry_latch_and.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_mc_r_channel.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_ddr_carry_and.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_mc_aw_channel.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_mc_cmd_arbiter.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_ddr_carry_or.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_ddr_comparator.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_ddr_carry_latch_or.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_mc.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_ctrl_reg.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_ctrl_reg_bank.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_ctrl_read.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_ddr_a_upsizer.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_mc_cmd_fsm.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_mc_ar_channel.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_mc_b_channel.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_mc_incr_cmd.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_mc_fifo.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_mc_wr_cmd_fsm.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_mc_simple_fifo.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_ctrl_write.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_ddr_comparator_sel_static.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_ddr_r_upsizer.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_mc_w_channel.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_axi_ctrl_top.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_ddr_axic_register_slice.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_ddr_w_upsizer.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_ddr_comparator_sel.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/axi/mig_7series_v4_2_ddr_axi_register_slice.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_byte_group_io.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_oclkdelay_cal.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_ocd_data.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_poc_tap_base.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_ocd_lim.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_init.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_poc_top.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_byte_lane.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_poc_cc.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_top.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_4lanes.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_ocd_po_cntlr.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_prbs_rdlvl.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_mc_phy_wrapper.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_if_post_fifo.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_mc_phy.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_wrcal.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_poc_edge_store.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_ocd_edge.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_poc_pd.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_dqs_found_cal.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_of_pre_fifo.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_rdlvl.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_tempmon.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_prbs_gen.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_wrlvl_off_delay.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_ocd_mux.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_ck_addr_cmd_delay.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_poc_meta.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_calib_top.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_dqs_found_cal_hr.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_ocd_samp.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_wrlvl.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/phy/mig_7series_v4_2_ddr_phy_ocd_cntlr.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/ui/mig_7series_v4_2_ui_rd_data.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/ui/mig_7series_v4_2_ui_wr_data.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/ui/mig_7series_v4_2_ui_top.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/ui/mig_7series_v4_2_ui_cmd.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/controller/mig_7series_v4_2_bank_state.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/controller/mig_7series_v4_2_rank_cntrl.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/controller/mig_7series_v4_2_col_mach.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/controller/mig_7series_v4_2_bank_common.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/controller/mig_7series_v4_2_rank_common.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/controller/mig_7series_v4_2_bank_cntrl.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/controller/mig_7series_v4_2_arb_mux.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/controller/mig_7series_v4_2_arb_select.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/controller/mig_7series_v4_2_bank_compare.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/controller/mig_7series_v4_2_bank_mach.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/controller/mig_7series_v4_2_arb_row_col.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/controller/mig_7series_v4_2_round_robin_arb.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/controller/mig_7series_v4_2_mc.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/controller/mig_7series_v4_2_bank_queue.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/controller/mig_7series_v4_2_rank_mach.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/nexys_shell_mig_7series_0_0_mig_sim.v" \
"../../../bd/nexys_shell/ip/nexys_shell_mig_7series_0_0_1/nexys_shell_mig_7series_0_0/user_design/rtl/nexys_shell_mig_7series_0_0.v" \

vlog -work xil_defaultlib \
"glbl.v"

