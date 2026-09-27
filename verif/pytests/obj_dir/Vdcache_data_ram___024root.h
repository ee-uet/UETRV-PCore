// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdcache_data_ram.h for the primary calling header

#ifndef VERILATED_VDCACHE_DATA_RAM___024ROOT_H_
#define VERILATED_VDCACHE_DATA_RAM___024ROOT_H_  // guard

#include "verilated.h"


class Vdcache_data_ram__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdcache_data_ram___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(dmem_sel_i,0,0);
    VL_IN8(dcache_flush_i,0,0);
    VL_IN8(dcache_kill_i,0,0);
    VL_OUT8(dcache2mem_kill_o,0,0);
    CData/*0:0*/ wb_dcache_top__DOT__cache_hit;
    CData/*0:0*/ wb_dcache_top__DOT__collect_info_tag;
    CData/*2:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff;
    CData/*2:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next;
    CData/*0:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT__lsummu2dcache_wr_ff;
    CData/*0:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2lsummu_ack;
    CData/*0:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_hit;
    CData/*0:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_miss;
    CData/*0:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_wr;
    CData/*0:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req;
    CData/*0:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req;
    CData/*0:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wr;
    CData/*0:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_wr;
    CData/*0:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_clean;
    CData/*0:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_kill;
    CData/*0:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT__lsummu2dcache_req_ff;
    CData/*0:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dmem_sel_ff;
    CData/*3:0*/ wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte;
    CData/*3:0*/ wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel;
    CData/*1:0*/ wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_offset_ff;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*10:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_next;
    SData/*10:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff;
    SData/*15:0*/ wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte;
    SData/*15:0*/ wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel;
    SData/*10:0*/ wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
    SData/*10:0*/ wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index_ff;
    VlWide<4>/*127:0*/ wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read;
    VlWide<4>/*127:0*/ wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write;
    VlWide<4>/*127:0*/ wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata;
    IData/*31:0*/ wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write;
    IData/*31:0*/ wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_read;
    IData/*31:0*/ wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write;
    IData/*31:0*/ wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__lsummu2dcache_wdata;
    IData/*31:0*/ wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache2lsummu_data_ff;
    IData/*16:0*/ wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_tag_ff;
    IData/*31:0*/ wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata;
    IData/*31:0*/ __VactIterCount;
    VL_INW(lsummu2dcache_i,69,0,3);
    VL_OUT64(dcache2lsummu_o,32,0);
    VL_INW(mem2dcache_i,128,0,5);
    VL_OUTW(dcache2mem_o,161,0,6);
    VlUnpacked<VlWide<4>/*127:0*/, 2048> wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram;
    VlUnpacked<IData/*31:0*/, 2048> wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdcache_data_ram__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdcache_data_ram___024root(Vdcache_data_ram__Syms* symsp, const char* v__name);
    ~Vdcache_data_ram___024root();
    VL_UNCOPYABLE(Vdcache_data_ram___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
