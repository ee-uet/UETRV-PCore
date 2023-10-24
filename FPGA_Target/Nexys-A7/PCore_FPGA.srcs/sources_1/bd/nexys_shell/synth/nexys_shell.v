//Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2019.1 (lin64) Build 2552052 Fri May 24 14:47:09 MDT 2019
//Date        : Sat Oct 21 22:05:55 2023
//Host        : mtahir-Inspiron-7520 running 64-bit Ubuntu 18.04.6 LTS
//Command     : generate_target nexys_shell.bd
//Design      : nexys_shell
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "nexys_shell,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=nexys_shell,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=3,numReposBlks=3,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=USER,synth_mode=Global}" *) (* HW_HANDOFF = "nexys_shell.hwdef" *) 
module nexys_shell
   (clk,
    ddr2_sdram_addr,
    ddr2_sdram_ba,
    ddr2_sdram_cas_n,
    ddr2_sdram_ck_n,
    ddr2_sdram_ck_p,
    ddr2_sdram_cke,
    ddr2_sdram_cs_n,
    ddr2_sdram_dm,
    ddr2_sdram_dq,
    ddr2_sdram_dqs_n,
    ddr2_sdram_dqs_p,
    ddr2_sdram_odt,
    ddr2_sdram_ras_n,
    ddr2_sdram_we_n,
    m_axi_araddr,
    m_axi_arburst,
    m_axi_arcache,
    m_axi_arlen,
    m_axi_arlock,
    m_axi_arprot,
    m_axi_arqos,
    m_axi_arready,
    m_axi_arsize,
    m_axi_arvalid,
    m_axi_awaddr,
    m_axi_awburst,
    m_axi_awcache,
    m_axi_awlen,
    m_axi_awlock,
    m_axi_awprot,
    m_axi_awqos,
    m_axi_awready,
    m_axi_awsize,
    m_axi_awvalid,
    m_axi_bready,
    m_axi_bresp,
    m_axi_bvalid,
    m_axi_rdata,
    m_axi_rlast,
    m_axi_rready,
    m_axi_rresp,
    m_axi_rvalid,
    m_axi_wdata,
    m_axi_wlast,
    m_axi_wready,
    m_axi_wstrb,
    m_axi_wvalid,
    rst_n,
    sys_clk_i);
  (* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.CLK CLK" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.CLK, ASSOCIATED_BUSIF m_axi, ASSOCIATED_RESET rst_n, CLK_DOMAIN nexys_shell_clk, FREQ_HZ 20000000, INSERT_VIP 0, PHASE 0.0" *) input clk;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 ddr2_sdram ADDR" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME ddr2_sdram, AXI_ARBITRATION_SCHEME TDM, BURST_LENGTH 8, CAN_DEBUG false, CAS_LATENCY 11, CAS_WRITE_LATENCY 11, CS_ENABLED true, DATA_MASK_ENABLED true, DATA_WIDTH 8, MEMORY_TYPE COMPONENTS, MEM_ADDR_MAP ROW_COLUMN_BANK, SLOT Single, TIMEPERIOD_PS 1250" *) output [12:0]ddr2_sdram_addr;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 ddr2_sdram BA" *) output [2:0]ddr2_sdram_ba;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 ddr2_sdram CAS_N" *) output ddr2_sdram_cas_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 ddr2_sdram CK_N" *) output [0:0]ddr2_sdram_ck_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 ddr2_sdram CK_P" *) output [0:0]ddr2_sdram_ck_p;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 ddr2_sdram CKE" *) output [0:0]ddr2_sdram_cke;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 ddr2_sdram CS_N" *) output [0:0]ddr2_sdram_cs_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 ddr2_sdram DM" *) output [1:0]ddr2_sdram_dm;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 ddr2_sdram DQ" *) inout [15:0]ddr2_sdram_dq;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 ddr2_sdram DQS_N" *) inout [1:0]ddr2_sdram_dqs_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 ddr2_sdram DQS_P" *) inout [1:0]ddr2_sdram_dqs_p;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 ddr2_sdram ODT" *) output [0:0]ddr2_sdram_odt;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 ddr2_sdram RAS_N" *) output ddr2_sdram_ras_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 ddr2_sdram WE_N" *) output ddr2_sdram_we_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi ARADDR" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME m_axi, ADDR_WIDTH 32, ARUSER_WIDTH 0, AWUSER_WIDTH 0, BUSER_WIDTH 0, CLK_DOMAIN nexys_shell_clk, DATA_WIDTH 128, FREQ_HZ 20000000, HAS_BRESP 0, HAS_BURST 0, HAS_CACHE 0, HAS_LOCK 0, HAS_PROT 0, HAS_QOS 0, HAS_REGION 0, HAS_RRESP 0, HAS_WSTRB 0, ID_WIDTH 0, INSERT_VIP 0, MAX_BURST_LENGTH 256, NUM_READ_OUTSTANDING 1, NUM_READ_THREADS 1, NUM_WRITE_OUTSTANDING 1, NUM_WRITE_THREADS 1, PHASE 0.0, PROTOCOL AXI4, READ_WRITE_MODE READ_WRITE, RUSER_BITS_PER_BYTE 0, RUSER_WIDTH 0, SUPPORTS_NARROW_BURST 1, WUSER_BITS_PER_BYTE 0, WUSER_WIDTH 0" *) input [31:0]m_axi_araddr;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi ARBURST" *) input [1:0]m_axi_arburst;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi ARCACHE" *) input [3:0]m_axi_arcache;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi ARLEN" *) input [7:0]m_axi_arlen;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi ARLOCK" *) input [0:0]m_axi_arlock;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi ARPROT" *) input [2:0]m_axi_arprot;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi ARQOS" *) input [3:0]m_axi_arqos;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi ARREADY" *) output m_axi_arready;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi ARSIZE" *) input [2:0]m_axi_arsize;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi ARVALID" *) input m_axi_arvalid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi AWADDR" *) input [31:0]m_axi_awaddr;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi AWBURST" *) input [1:0]m_axi_awburst;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi AWCACHE" *) input [3:0]m_axi_awcache;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi AWLEN" *) input [7:0]m_axi_awlen;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi AWLOCK" *) input [0:0]m_axi_awlock;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi AWPROT" *) input [2:0]m_axi_awprot;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi AWQOS" *) input [3:0]m_axi_awqos;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi AWREADY" *) output m_axi_awready;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi AWSIZE" *) input [2:0]m_axi_awsize;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi AWVALID" *) input m_axi_awvalid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi BREADY" *) input m_axi_bready;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi BRESP" *) output [1:0]m_axi_bresp;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi BVALID" *) output m_axi_bvalid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi RDATA" *) output [127:0]m_axi_rdata;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi RLAST" *) output m_axi_rlast;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi RREADY" *) input m_axi_rready;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi RRESP" *) output [1:0]m_axi_rresp;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi RVALID" *) output m_axi_rvalid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi WDATA" *) input [127:0]m_axi_wdata;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi WLAST" *) input m_axi_wlast;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi WREADY" *) output m_axi_wready;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi WSTRB" *) input [15:0]m_axi_wstrb;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 m_axi WVALID" *) input m_axi_wvalid;
  (* X_INTERFACE_INFO = "xilinx.com:signal:reset:1.0 RST.RST_N RST" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME RST.RST_N, INSERT_VIP 0, POLARITY ACTIVE_LOW" *) input rst_n;
  (* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.SYS_CLK_I CLK" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.SYS_CLK_I, CLK_DOMAIN nexys_shell_sys_clk_i, FREQ_HZ 200000000, INSERT_VIP 0, PHASE 0.0" *) input sys_clk_i;

  wire clk_1;
  wire [31:0]m_axi_1_ARADDR;
  wire [1:0]m_axi_1_ARBURST;
  wire [3:0]m_axi_1_ARCACHE;
  wire [7:0]m_axi_1_ARLEN;
  wire [0:0]m_axi_1_ARLOCK;
  wire [2:0]m_axi_1_ARPROT;
  wire [3:0]m_axi_1_ARQOS;
  wire m_axi_1_ARREADY;
  wire [2:0]m_axi_1_ARSIZE;
  wire m_axi_1_ARVALID;
  wire [31:0]m_axi_1_AWADDR;
  wire [1:0]m_axi_1_AWBURST;
  wire [3:0]m_axi_1_AWCACHE;
  wire [7:0]m_axi_1_AWLEN;
  wire [0:0]m_axi_1_AWLOCK;
  wire [2:0]m_axi_1_AWPROT;
  wire [3:0]m_axi_1_AWQOS;
  wire m_axi_1_AWREADY;
  wire [2:0]m_axi_1_AWSIZE;
  wire m_axi_1_AWVALID;
  wire m_axi_1_BREADY;
  wire [1:0]m_axi_1_BRESP;
  wire m_axi_1_BVALID;
  wire [127:0]m_axi_1_RDATA;
  wire m_axi_1_RLAST;
  wire m_axi_1_RREADY;
  wire [1:0]m_axi_1_RRESP;
  wire m_axi_1_RVALID;
  wire [127:0]m_axi_1_WDATA;
  wire m_axi_1_WLAST;
  wire m_axi_1_WREADY;
  wire [15:0]m_axi_1_WSTRB;
  wire m_axi_1_WVALID;
  wire [12:0]mig_7series_0_DDR2_ADDR;
  wire [2:0]mig_7series_0_DDR2_BA;
  wire mig_7series_0_DDR2_CAS_N;
  wire [0:0]mig_7series_0_DDR2_CKE;
  wire [0:0]mig_7series_0_DDR2_CK_N;
  wire [0:0]mig_7series_0_DDR2_CK_P;
  wire [0:0]mig_7series_0_DDR2_CS_N;
  wire [1:0]mig_7series_0_DDR2_DM;
  wire [15:0]mig_7series_0_DDR2_DQ;
  wire [1:0]mig_7series_0_DDR2_DQS_N;
  wire [1:0]mig_7series_0_DDR2_DQS_P;
  wire [0:0]mig_7series_0_DDR2_ODT;
  wire mig_7series_0_DDR2_RAS_N;
  wire mig_7series_0_DDR2_WE_N;
  wire mig_7series_0_mmcm_locked;
  wire mig_7series_0_ui_clk;
  wire [0:0]proc_sys_reset_0_peripheral_aresetn;
  wire rst_n_1;
  wire [26:0]smartconnect_0_M00_AXI_ARADDR;
  wire [1:0]smartconnect_0_M00_AXI_ARBURST;
  wire [3:0]smartconnect_0_M00_AXI_ARCACHE;
  wire [7:0]smartconnect_0_M00_AXI_ARLEN;
  wire [0:0]smartconnect_0_M00_AXI_ARLOCK;
  wire [2:0]smartconnect_0_M00_AXI_ARPROT;
  wire [3:0]smartconnect_0_M00_AXI_ARQOS;
  wire smartconnect_0_M00_AXI_ARREADY;
  wire [2:0]smartconnect_0_M00_AXI_ARSIZE;
  wire smartconnect_0_M00_AXI_ARVALID;
  wire [26:0]smartconnect_0_M00_AXI_AWADDR;
  wire [1:0]smartconnect_0_M00_AXI_AWBURST;
  wire [3:0]smartconnect_0_M00_AXI_AWCACHE;
  wire [7:0]smartconnect_0_M00_AXI_AWLEN;
  wire [0:0]smartconnect_0_M00_AXI_AWLOCK;
  wire [2:0]smartconnect_0_M00_AXI_AWPROT;
  wire [3:0]smartconnect_0_M00_AXI_AWQOS;
  wire smartconnect_0_M00_AXI_AWREADY;
  wire [2:0]smartconnect_0_M00_AXI_AWSIZE;
  wire smartconnect_0_M00_AXI_AWVALID;
  wire smartconnect_0_M00_AXI_BREADY;
  wire [1:0]smartconnect_0_M00_AXI_BRESP;
  wire smartconnect_0_M00_AXI_BVALID;
  wire [127:0]smartconnect_0_M00_AXI_RDATA;
  wire smartconnect_0_M00_AXI_RLAST;
  wire smartconnect_0_M00_AXI_RREADY;
  wire [1:0]smartconnect_0_M00_AXI_RRESP;
  wire smartconnect_0_M00_AXI_RVALID;
  wire [127:0]smartconnect_0_M00_AXI_WDATA;
  wire smartconnect_0_M00_AXI_WLAST;
  wire smartconnect_0_M00_AXI_WREADY;
  wire [15:0]smartconnect_0_M00_AXI_WSTRB;
  wire smartconnect_0_M00_AXI_WVALID;
  wire sys_clk_i_1;

  assign clk_1 = clk;
  assign ddr2_sdram_addr[12:0] = mig_7series_0_DDR2_ADDR;
  assign ddr2_sdram_ba[2:0] = mig_7series_0_DDR2_BA;
  assign ddr2_sdram_cas_n = mig_7series_0_DDR2_CAS_N;
  assign ddr2_sdram_ck_n[0] = mig_7series_0_DDR2_CK_N;
  assign ddr2_sdram_ck_p[0] = mig_7series_0_DDR2_CK_P;
  assign ddr2_sdram_cke[0] = mig_7series_0_DDR2_CKE;
  assign ddr2_sdram_cs_n[0] = mig_7series_0_DDR2_CS_N;
  assign ddr2_sdram_dm[1:0] = mig_7series_0_DDR2_DM;
  assign ddr2_sdram_odt[0] = mig_7series_0_DDR2_ODT;
  assign ddr2_sdram_ras_n = mig_7series_0_DDR2_RAS_N;
  assign ddr2_sdram_we_n = mig_7series_0_DDR2_WE_N;
  assign m_axi_1_ARADDR = m_axi_araddr[31:0];
  assign m_axi_1_ARBURST = m_axi_arburst[1:0];
  assign m_axi_1_ARCACHE = m_axi_arcache[3:0];
  assign m_axi_1_ARLEN = m_axi_arlen[7:0];
  assign m_axi_1_ARLOCK = m_axi_arlock[0];
  assign m_axi_1_ARPROT = m_axi_arprot[2:0];
  assign m_axi_1_ARQOS = m_axi_arqos[3:0];
  assign m_axi_1_ARSIZE = m_axi_arsize[2:0];
  assign m_axi_1_ARVALID = m_axi_arvalid;
  assign m_axi_1_AWADDR = m_axi_awaddr[31:0];
  assign m_axi_1_AWBURST = m_axi_awburst[1:0];
  assign m_axi_1_AWCACHE = m_axi_awcache[3:0];
  assign m_axi_1_AWLEN = m_axi_awlen[7:0];
  assign m_axi_1_AWLOCK = m_axi_awlock[0];
  assign m_axi_1_AWPROT = m_axi_awprot[2:0];
  assign m_axi_1_AWQOS = m_axi_awqos[3:0];
  assign m_axi_1_AWSIZE = m_axi_awsize[2:0];
  assign m_axi_1_AWVALID = m_axi_awvalid;
  assign m_axi_1_BREADY = m_axi_bready;
  assign m_axi_1_RREADY = m_axi_rready;
  assign m_axi_1_WDATA = m_axi_wdata[127:0];
  assign m_axi_1_WLAST = m_axi_wlast;
  assign m_axi_1_WSTRB = m_axi_wstrb[15:0];
  assign m_axi_1_WVALID = m_axi_wvalid;
  assign m_axi_arready = m_axi_1_ARREADY;
  assign m_axi_awready = m_axi_1_AWREADY;
  assign m_axi_bresp[1:0] = m_axi_1_BRESP;
  assign m_axi_bvalid = m_axi_1_BVALID;
  assign m_axi_rdata[127:0] = m_axi_1_RDATA;
  assign m_axi_rlast = m_axi_1_RLAST;
  assign m_axi_rresp[1:0] = m_axi_1_RRESP;
  assign m_axi_rvalid = m_axi_1_RVALID;
  assign m_axi_wready = m_axi_1_WREADY;
  assign rst_n_1 = rst_n;
  assign sys_clk_i_1 = sys_clk_i;
  nexys_shell_mig_7series_0_0 mig_7series_0
       (.aresetn(proc_sys_reset_0_peripheral_aresetn),
        .ddr2_addr(mig_7series_0_DDR2_ADDR),
        .ddr2_ba(mig_7series_0_DDR2_BA),
        .ddr2_cas_n(mig_7series_0_DDR2_CAS_N),
        .ddr2_ck_n(mig_7series_0_DDR2_CK_N),
        .ddr2_ck_p(mig_7series_0_DDR2_CK_P),
        .ddr2_cke(mig_7series_0_DDR2_CKE),
        .ddr2_cs_n(mig_7series_0_DDR2_CS_N),
        .ddr2_dm(mig_7series_0_DDR2_DM),
        .ddr2_dq(ddr2_sdram_dq[15:0]),
        .ddr2_dqs_n(ddr2_sdram_dqs_n[1:0]),
        .ddr2_dqs_p(ddr2_sdram_dqs_p[1:0]),
        .ddr2_odt(mig_7series_0_DDR2_ODT),
        .ddr2_ras_n(mig_7series_0_DDR2_RAS_N),
        .ddr2_we_n(mig_7series_0_DDR2_WE_N),
        .mmcm_locked(mig_7series_0_mmcm_locked),
        .s_axi_araddr(smartconnect_0_M00_AXI_ARADDR),
        .s_axi_arburst(smartconnect_0_M00_AXI_ARBURST),
        .s_axi_arcache(smartconnect_0_M00_AXI_ARCACHE),
        .s_axi_arid({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arlen(smartconnect_0_M00_AXI_ARLEN),
        .s_axi_arlock(smartconnect_0_M00_AXI_ARLOCK),
        .s_axi_arprot(smartconnect_0_M00_AXI_ARPROT),
        .s_axi_arqos(smartconnect_0_M00_AXI_ARQOS),
        .s_axi_arready(smartconnect_0_M00_AXI_ARREADY),
        .s_axi_arsize(smartconnect_0_M00_AXI_ARSIZE),
        .s_axi_arvalid(smartconnect_0_M00_AXI_ARVALID),
        .s_axi_awaddr(smartconnect_0_M00_AXI_AWADDR),
        .s_axi_awburst(smartconnect_0_M00_AXI_AWBURST),
        .s_axi_awcache(smartconnect_0_M00_AXI_AWCACHE),
        .s_axi_awid({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awlen(smartconnect_0_M00_AXI_AWLEN),
        .s_axi_awlock(smartconnect_0_M00_AXI_AWLOCK),
        .s_axi_awprot(smartconnect_0_M00_AXI_AWPROT),
        .s_axi_awqos(smartconnect_0_M00_AXI_AWQOS),
        .s_axi_awready(smartconnect_0_M00_AXI_AWREADY),
        .s_axi_awsize(smartconnect_0_M00_AXI_AWSIZE),
        .s_axi_awvalid(smartconnect_0_M00_AXI_AWVALID),
        .s_axi_bready(smartconnect_0_M00_AXI_BREADY),
        .s_axi_bresp(smartconnect_0_M00_AXI_BRESP),
        .s_axi_bvalid(smartconnect_0_M00_AXI_BVALID),
        .s_axi_rdata(smartconnect_0_M00_AXI_RDATA),
        .s_axi_rlast(smartconnect_0_M00_AXI_RLAST),
        .s_axi_rready(smartconnect_0_M00_AXI_RREADY),
        .s_axi_rresp(smartconnect_0_M00_AXI_RRESP),
        .s_axi_rvalid(smartconnect_0_M00_AXI_RVALID),
        .s_axi_wdata(smartconnect_0_M00_AXI_WDATA),
        .s_axi_wlast(smartconnect_0_M00_AXI_WLAST),
        .s_axi_wready(smartconnect_0_M00_AXI_WREADY),
        .s_axi_wstrb(smartconnect_0_M00_AXI_WSTRB),
        .s_axi_wvalid(smartconnect_0_M00_AXI_WVALID),
        .sys_clk_i(sys_clk_i_1),
        .sys_rst(rst_n_1),
        .ui_clk(mig_7series_0_ui_clk));
  nexys_shell_proc_sys_reset_0_0 proc_sys_reset_0
       (.aux_reset_in(1'b1),
        .dcm_locked(mig_7series_0_mmcm_locked),
        .ext_reset_in(rst_n_1),
        .mb_debug_sys_rst(1'b0),
        .peripheral_aresetn(proc_sys_reset_0_peripheral_aresetn),
        .slowest_sync_clk(mig_7series_0_ui_clk));
  nexys_shell_smartconnect_0_0 smartconnect_0
       (.M00_AXI_araddr(smartconnect_0_M00_AXI_ARADDR),
        .M00_AXI_arburst(smartconnect_0_M00_AXI_ARBURST),
        .M00_AXI_arcache(smartconnect_0_M00_AXI_ARCACHE),
        .M00_AXI_arlen(smartconnect_0_M00_AXI_ARLEN),
        .M00_AXI_arlock(smartconnect_0_M00_AXI_ARLOCK),
        .M00_AXI_arprot(smartconnect_0_M00_AXI_ARPROT),
        .M00_AXI_arqos(smartconnect_0_M00_AXI_ARQOS),
        .M00_AXI_arready(smartconnect_0_M00_AXI_ARREADY),
        .M00_AXI_arsize(smartconnect_0_M00_AXI_ARSIZE),
        .M00_AXI_arvalid(smartconnect_0_M00_AXI_ARVALID),
        .M00_AXI_awaddr(smartconnect_0_M00_AXI_AWADDR),
        .M00_AXI_awburst(smartconnect_0_M00_AXI_AWBURST),
        .M00_AXI_awcache(smartconnect_0_M00_AXI_AWCACHE),
        .M00_AXI_awlen(smartconnect_0_M00_AXI_AWLEN),
        .M00_AXI_awlock(smartconnect_0_M00_AXI_AWLOCK),
        .M00_AXI_awprot(smartconnect_0_M00_AXI_AWPROT),
        .M00_AXI_awqos(smartconnect_0_M00_AXI_AWQOS),
        .M00_AXI_awready(smartconnect_0_M00_AXI_AWREADY),
        .M00_AXI_awsize(smartconnect_0_M00_AXI_AWSIZE),
        .M00_AXI_awvalid(smartconnect_0_M00_AXI_AWVALID),
        .M00_AXI_bready(smartconnect_0_M00_AXI_BREADY),
        .M00_AXI_bresp(smartconnect_0_M00_AXI_BRESP),
        .M00_AXI_bvalid(smartconnect_0_M00_AXI_BVALID),
        .M00_AXI_rdata(smartconnect_0_M00_AXI_RDATA),
        .M00_AXI_rlast(smartconnect_0_M00_AXI_RLAST),
        .M00_AXI_rready(smartconnect_0_M00_AXI_RREADY),
        .M00_AXI_rresp(smartconnect_0_M00_AXI_RRESP),
        .M00_AXI_rvalid(smartconnect_0_M00_AXI_RVALID),
        .M00_AXI_wdata(smartconnect_0_M00_AXI_WDATA),
        .M00_AXI_wlast(smartconnect_0_M00_AXI_WLAST),
        .M00_AXI_wready(smartconnect_0_M00_AXI_WREADY),
        .M00_AXI_wstrb(smartconnect_0_M00_AXI_WSTRB),
        .M00_AXI_wvalid(smartconnect_0_M00_AXI_WVALID),
        .S00_AXI_araddr(m_axi_1_ARADDR),
        .S00_AXI_arburst(m_axi_1_ARBURST),
        .S00_AXI_arcache(m_axi_1_ARCACHE),
        .S00_AXI_arlen(m_axi_1_ARLEN),
        .S00_AXI_arlock(m_axi_1_ARLOCK),
        .S00_AXI_arprot(m_axi_1_ARPROT),
        .S00_AXI_arqos(m_axi_1_ARQOS),
        .S00_AXI_arready(m_axi_1_ARREADY),
        .S00_AXI_arsize(m_axi_1_ARSIZE),
        .S00_AXI_arvalid(m_axi_1_ARVALID),
        .S00_AXI_awaddr(m_axi_1_AWADDR),
        .S00_AXI_awburst(m_axi_1_AWBURST),
        .S00_AXI_awcache(m_axi_1_AWCACHE),
        .S00_AXI_awlen(m_axi_1_AWLEN),
        .S00_AXI_awlock(m_axi_1_AWLOCK),
        .S00_AXI_awprot(m_axi_1_AWPROT),
        .S00_AXI_awqos(m_axi_1_AWQOS),
        .S00_AXI_awready(m_axi_1_AWREADY),
        .S00_AXI_awsize(m_axi_1_AWSIZE),
        .S00_AXI_awvalid(m_axi_1_AWVALID),
        .S00_AXI_bready(m_axi_1_BREADY),
        .S00_AXI_bresp(m_axi_1_BRESP),
        .S00_AXI_bvalid(m_axi_1_BVALID),
        .S00_AXI_rdata(m_axi_1_RDATA),
        .S00_AXI_rlast(m_axi_1_RLAST),
        .S00_AXI_rready(m_axi_1_RREADY),
        .S00_AXI_rresp(m_axi_1_RRESP),
        .S00_AXI_rvalid(m_axi_1_RVALID),
        .S00_AXI_wdata(m_axi_1_WDATA),
        .S00_AXI_wlast(m_axi_1_WLAST),
        .S00_AXI_wready(m_axi_1_WREADY),
        .S00_AXI_wstrb(m_axi_1_WSTRB),
        .S00_AXI_wvalid(m_axi_1_WVALID),
        .aclk(clk_1),
        .aclk1(mig_7series_0_ui_clk),
        .aresetn(rst_n_1));
endmodule
