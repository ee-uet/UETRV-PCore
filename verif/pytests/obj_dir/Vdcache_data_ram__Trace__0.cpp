// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdcache_data_ram__Syms.h"


void Vdcache_data_ram___024root__trace_chg_0_sub_0(Vdcache_data_ram___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdcache_data_ram___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root__trace_chg_0\n"); );
    // Init
    Vdcache_data_ram___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdcache_data_ram___024root*>(voidSelf);
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdcache_data_ram___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vdcache_data_ram___024root__trace_chg_0_sub_0(Vdcache_data_ram___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root__trace_chg_0_sub_0\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wr));
        bufp->chgBit(oldp+1,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_wr));
        bufp->chgBit(oldp+2,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_clean));
        bufp->chgBit(oldp+3,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req));
        bufp->chgBit(oldp+4,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req));
        bufp->chgBit(oldp+5,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_wr));
        bufp->chgCData(oldp+6,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next),3);
        bufp->chgSData(oldp+7,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_next),11);
        bufp->chgWData(oldp+8,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata),128);
        bufp->chgIData(oldp+12,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write),32);
        bufp->chgSData(oldp+13,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel),16);
        bufp->chgCData(oldp+14,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel),4);
        bufp->chgSData(oldp+15,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index),11);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+16,(vlSelfRef.wb_dcache_top__DOT__cache_hit));
        bufp->chgBit(oldp+17,((1U & (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
                                     >> 0x18U))));
        bufp->chgSData(oldp+18,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff),11);
        bufp->chgBit(oldp+19,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2lsummu_ack));
        bufp->chgCData(oldp+20,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff),3);
        bufp->chgBit(oldp+21,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__lsummu2dcache_wr_ff));
        bufp->chgBit(oldp+22,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_hit));
        bufp->chgBit(oldp+23,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_miss));
        bufp->chgBit(oldp+24,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__lsummu2dcache_req_ff));
        bufp->chgBit(oldp+25,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dmem_sel_ff));
        bufp->chgIData(oldp+26,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_read),32);
        bufp->chgWData(oldp+27,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read),128);
        bufp->chgWData(oldp+31,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write),128);
        bufp->chgIData(oldp+35,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata),32);
        bufp->chgIData(oldp+36,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write),32);
        bufp->chgIData(oldp+37,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__lsummu2dcache_wdata),32);
        bufp->chgSData(oldp+38,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte),16);
        bufp->chgCData(oldp+39,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte),4);
        bufp->chgIData(oldp+40,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache2lsummu_data_ff),32);
        bufp->chgIData(oldp+41,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_tag_ff),17);
        bufp->chgCData(oldp+42,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_offset_ff),2);
        bufp->chgSData(oldp+43,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index_ff),11);
        bufp->chgBit(oldp+44,((1U & (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
                                     >> 0x17U))));
    }
    bufp->chgBit(oldp+45,(vlSelfRef.clk));
    bufp->chgBit(oldp+46,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+47,(vlSelfRef.dmem_sel_i));
    bufp->chgBit(oldp+48,(vlSelfRef.dcache_flush_i));
    bufp->chgBit(oldp+49,(vlSelfRef.dcache_kill_i));
    bufp->chgWData(oldp+50,(vlSelfRef.lsummu2dcache_i),70);
    bufp->chgQData(oldp+53,(vlSelfRef.dcache2lsummu_o),33);
    bufp->chgWData(oldp+55,(vlSelfRef.mem2dcache_i),129);
    bufp->chgWData(oldp+60,(vlSelfRef.dcache2mem_o),162);
    bufp->chgBit(oldp+66,(vlSelfRef.dcache2mem_kill_o));
    bufp->chgBit(oldp+67,((1U & vlSelfRef.lsummu2dcache_i[0U])));
    bufp->chgBit(oldp+68,((1U & (vlSelfRef.lsummu2dcache_i[0U] 
                                 >> 1U))));
    bufp->chgBit(oldp+69,((1U & vlSelfRef.mem2dcache_i[0U])));
    bufp->chgBit(oldp+70,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_kill));
    bufp->chgIData(oldp+71,(((vlSelfRef.lsummu2dcache_i[2U] 
                              << 0x1aU) | (vlSelfRef.lsummu2dcache_i[1U] 
                                           >> 6U))),32);
    bufp->chgIData(oldp+72,(((vlSelfRef.lsummu2dcache_i[1U] 
                              << 0x1aU) | (vlSelfRef.lsummu2dcache_i[0U] 
                                           >> 6U))),32);
    bufp->chgCData(oldp+73,((0xfU & (vlSelfRef.lsummu2dcache_i[0U] 
                                     >> 2U))),4);
    __Vtemp_1[0U] = ((vlSelfRef.mem2dcache_i[1U] << 0x1fU) 
                     | (vlSelfRef.mem2dcache_i[0U] 
                        >> 1U));
    __Vtemp_1[1U] = ((vlSelfRef.mem2dcache_i[2U] << 0x1fU) 
                     | (vlSelfRef.mem2dcache_i[1U] 
                        >> 1U));
    __Vtemp_1[2U] = ((vlSelfRef.mem2dcache_i[3U] << 0x1fU) 
                     | (vlSelfRef.mem2dcache_i[2U] 
                        >> 1U));
    __Vtemp_1[3U] = ((vlSelfRef.mem2dcache_i[4U] << 0x1fU) 
                     | (vlSelfRef.mem2dcache_i[3U] 
                        >> 1U));
    bufp->chgWData(oldp+74,(__Vtemp_1),128);
    bufp->chgIData(oldp+78,(((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req)
                              ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
                                  << 0xfU) | ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index) 
                                              << 4U))
                              : ((vlSelfRef.lsummu2dcache_i[2U] 
                                  << 0x1aU) | (vlSelfRef.lsummu2dcache_i[1U] 
                                               >> 6U)))),32);
    bufp->chgIData(oldp+79,((0x1ffffU & ((vlSelfRef.lsummu2dcache_i[2U] 
                                          << 0xbU) 
                                         | (vlSelfRef.lsummu2dcache_i[1U] 
                                            >> 0x15U)))),17);
    bufp->chgCData(oldp+80,((3U & (vlSelfRef.lsummu2dcache_i[1U] 
                                   >> 8U))),2);
}

void Vdcache_data_ram___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root__trace_cleanup\n"); );
    // Init
    Vdcache_data_ram___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdcache_data_ram___024root*>(voidSelf);
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
