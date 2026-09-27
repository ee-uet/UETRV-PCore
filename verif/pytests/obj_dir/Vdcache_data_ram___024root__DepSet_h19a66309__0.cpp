// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdcache_data_ram.h for the primary calling header

#include "Vdcache_data_ram__pch.h"
#include "Vdcache_data_ram___024root.h"

void Vdcache_data_ram___024root___ico_sequent__TOP__0(Vdcache_data_ram___024root* vlSelf);

void Vdcache_data_ram___024root___eval_ico(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval_ico\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vdcache_data_ram___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vdcache_data_ram___024root___ico_sequent__TOP__0(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___ico_sequent__TOP__0\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_kill = 0U;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_next 
        = vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next 
        = vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_clean = 0U;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_wr = 0U;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req = 0U;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req = 0U;
    if ((4U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))) {
        if ((2U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))) {
            if ((1U & (~ (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff)))) {
                if ((1U & (~ (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
                              >> 0x18U)))) {
                    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_next 
                        = ((0x7ffU == (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff))
                            ? 0U : (0x7ffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff))));
                }
                if ((0x1000000U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata)) {
                    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_wr = 1U;
                    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req = 1U;
                    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req = 1U;
                }
            }
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next 
                = ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))
                    ? 0U : ((0x1000000U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata)
                             ? 5U : ((0x7ffU == (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff))
                                      ? 7U : 3U)));
        } else if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))) {
            if ((1U & vlSelfRef.mem2dcache_i[0U])) {
                if (vlSelfRef.dcache_flush_i) {
                    if ((1U & (~ (IData)((0x7ffU == (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff)))))) {
                        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_next 
                            = (0x7ffU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff)));
                    }
                    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next = 3U;
                } else {
                    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next = 4U;
                }
                if ((1U & (~ (IData)(vlSelfRef.dcache_flush_i)))) {
                    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req = 1U;
                }
            } else {
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next = 5U;
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req = 1U;
            }
            if ((1U & (~ vlSelfRef.mem2dcache_i[0U]))) {
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_wr = 1U;
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req = 1U;
            }
        } else {
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next 
                = ((1U & vlSelfRef.mem2dcache_i[0U])
                    ? 1U : 4U);
            if ((1U & (~ vlSelfRef.mem2dcache_i[0U]))) {
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req = 1U;
            }
        }
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_wr = 0U;
        if ((1U & (~ ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))) {
                if ((1U & vlSelfRef.mem2dcache_i[0U])) {
                    if (vlSelfRef.dcache_flush_i) {
                        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_clean = 1U;
                    }
                }
            }
            if ((1U & (~ (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff)))) {
                if ((1U & vlSelfRef.mem2dcache_i[0U])) {
                    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_wr = 1U;
                }
            }
        }
    } else {
        if ((1U & (~ ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff)))) {
                if ((1U & (~ (IData)(vlSelfRef.dcache_flush_i)))) {
                    if ((1U & (~ vlSelfRef.lsummu2dcache_i[0U]))) {
                        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_next = 0U;
                    }
                }
            }
            if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))) {
                if ((1U & (~ (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_hit)))) {
                    if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_miss) {
                        if ((0x1000000U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata)) {
                            vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_wr = 1U;
                            vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req = 1U;
                        }
                        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req = 1U;
                    }
                }
            }
        }
        if ((2U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))) {
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next 
                = ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))
                    ? 6U : 0U);
        } else if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))) {
            if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_hit) {
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next = 0U;
            } else if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_miss) {
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next 
                    = ((0x1000000U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata)
                        ? 5U : 4U);
            }
        } else {
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next 
                = ((IData)(vlSelfRef.dcache_flush_i)
                    ? 6U : ((1U & vlSelfRef.lsummu2dcache_i[0U])
                             ? 1U : 0U));
        }
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_wr = 0U;
    }
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wr = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))) {
                if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_hit) {
                    if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__lsummu2dcache_wr_ff) {
                        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wr = 1U;
                    }
                }
            }
        }
    }
    if ((1U & ((~ (IData)(vlSelfRef.dmem_sel_i)) | (IData)(vlSelfRef.dcache_kill_i)))) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_kill = 1U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_next = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wr = 0U;
    }
    vlSelfRef.dcache2mem_kill_o = vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_kill;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel = 0U;
    if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_wr) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel = 0xffffU;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[0U] 
            = ((vlSelfRef.mem2dcache_i[1U] << 0x1fU) 
               | (vlSelfRef.mem2dcache_i[0U] >> 1U));
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[1U] 
            = ((vlSelfRef.mem2dcache_i[2U] << 0x1fU) 
               | (vlSelfRef.mem2dcache_i[1U] >> 1U));
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[2U] 
            = ((vlSelfRef.mem2dcache_i[3U] << 0x1fU) 
               | (vlSelfRef.mem2dcache_i[2U] >> 1U));
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[3U] 
            = ((vlSelfRef.mem2dcache_i[4U] << 0x1fU) 
               | (vlSelfRef.mem2dcache_i[3U] >> 1U));
    } else if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wr) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[0U] 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[0U];
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[1U] 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[1U];
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[2U] 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[2U];
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[3U] 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[3U];
    } else {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[0U] = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[1U] = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[2U] = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[3U] = 0U;
    }
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write = 0U;
    if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_clean) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel = 8U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write 
            = (0xffffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write);
    } else if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wr) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel = 8U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write 
            = (0x1000000U | (0xffffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write));
    } else if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_wr) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel = 0xfU;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write 
            = (0x800000U | (0x1ffffU & ((vlSelfRef.lsummu2dcache_i[2U] 
                                         << 0xbU) | 
                                        (vlSelfRef.lsummu2dcache_i[1U] 
                                         >> 0x15U))));
    }
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index 
        = (0x7ffU & ((IData)(vlSelfRef.dcache_flush_i)
                      ? (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff)
                      : ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wr)
                          ? (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index_ff)
                          : ((vlSelfRef.lsummu2dcache_i[1U] 
                              << 0x16U) | (vlSelfRef.lsummu2dcache_i[1U] 
                                           >> 0xaU)))));
    vlSelfRef.dcache2mem_o[0U] = ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[0U] 
                                   << 2U) | (((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req) 
                                              << 1U) 
                                             | (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_wr)));
    vlSelfRef.dcache2mem_o[1U] = ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[0U] 
                                   >> 0x1eU) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[1U] 
                                                << 2U));
    vlSelfRef.dcache2mem_o[2U] = ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[1U] 
                                   >> 0x1eU) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[2U] 
                                                << 2U));
    vlSelfRef.dcache2mem_o[3U] = ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[2U] 
                                   >> 0x1eU) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[3U] 
                                                << 2U));
    vlSelfRef.dcache2mem_o[4U] = ((0xfffffffcU & vlSelfRef.dcache2mem_o[4U]) 
                                  | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[3U] 
                                     >> 0x1eU));
    vlSelfRef.dcache2mem_o[4U] = ((3U & vlSelfRef.dcache2mem_o[4U]) 
                                  | (((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req)
                                       ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
                                           << 0xfU) 
                                          | ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index) 
                                             << 4U))
                                       : ((vlSelfRef.lsummu2dcache_i[2U] 
                                           << 0x1aU) 
                                          | (vlSelfRef.lsummu2dcache_i[1U] 
                                             >> 6U))) 
                                     << 2U));
    vlSelfRef.dcache2mem_o[5U] = (((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req)
                                    ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
                                        << 0xfU) | 
                                       ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index) 
                                        << 4U)) : (
                                                   (vlSelfRef.lsummu2dcache_i[2U] 
                                                    << 0x1aU) 
                                                   | (vlSelfRef.lsummu2dcache_i[1U] 
                                                      >> 6U))) 
                                  >> 0x1eU);
}

void Vdcache_data_ram___024root___eval_triggers__ico(Vdcache_data_ram___024root* vlSelf);

bool Vdcache_data_ram___024root___eval_phase__ico(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval_phase__ico\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vdcache_data_ram___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vdcache_data_ram___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vdcache_data_ram___024root___eval_act(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval_act\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vdcache_data_ram___024root___nba_sequent__TOP__0(Vdcache_data_ram___024root* vlSelf);

void Vdcache_data_ram___024root___eval_nba(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval_nba\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdcache_data_ram___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
}

VL_INLINE_OPT void Vdcache_data_ram___024root___nba_sequent__TOP__0(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___nba_sequent__TOP__0\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT____VdfgRegularize_hbc0d45b6_0_0;
    wb_dcache_top__DOT__wb_dcache_controller_module__DOT____VdfgRegularize_hbc0d45b6_0_0 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v0;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v0 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v0;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v0 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v0;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v0 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v1;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v1 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v1;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v1 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v1;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v1 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v2;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v2 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v2;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v2 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v2;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v2 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v3;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v3 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v3;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v3 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v3;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v3 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v4;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v4 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v4;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v4 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v4;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v4 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v5;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v5 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v5;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v5 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v5;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v5 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v6;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v6 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v6;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v6 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v6;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v6 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v7;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v7 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v7;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v7 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v7;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v7 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v8;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v8 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v8;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v8 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v8;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v8 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v9;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v9 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v9;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v9 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v9;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v9 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v10;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v10 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v10;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v10 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v10;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v10 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v11;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v11 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v11;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v11 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v11;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v11 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v12;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v12 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v12;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v12 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v12;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v12 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v13;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v13 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v13;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v13 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v13;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v13 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v14;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v14 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v14;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v14 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v14;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v14 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v15;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v15 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v15;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v15 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v15;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v15 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v0;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v0 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v0;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v0 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v0;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v0 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v1;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v1 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v1;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v1 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v2;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v2 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v2;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v2 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v2;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v2 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v3;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v3 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v3;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v3 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v4;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v4 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v4;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v4 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v4;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v4 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v5;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v5 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v5;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v5 = 0;
    CData/*7:0*/ __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v6;
    __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v6 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v6;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v6 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v6;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v6 = 0;
    SData/*10:0*/ __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v7;
    __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v7 = 0;
    CData/*0:0*/ __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v7;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v7 = 0;
    // Body
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v0 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v1 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v2 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v3 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v4 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v5 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v6 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v7 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v0 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v1 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v2 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v3 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v4 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v5 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v6 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v7 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v8 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v9 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v10 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v11 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v12 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v13 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v14 = 0U;
    __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v15 = 0U;
    if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v0 
            = (0xffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write);
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v0 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v0 = 1U;
    }
    if ((2U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v2 
            = (0xffU & (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write 
                        >> 8U));
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v2 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v2 = 1U;
    }
    if ((4U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v4 
            = (0xffU & (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write 
                        >> 0x10U));
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v4 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v4 = 1U;
    }
    if ((8U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v6 
            = (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write 
               >> 0x18U);
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v6 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v6 = 1U;
    }
    if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v0 
            = (0xffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[0U]);
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v0 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v0 = 1U;
    }
    if ((2U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v1 
            = (0xffU & (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[0U] 
                        >> 8U));
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v1 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v1 = 1U;
    }
    if ((4U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v2 
            = (0xffU & (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[0U] 
                        >> 0x10U));
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v2 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v2 = 1U;
    }
    if ((8U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v3 
            = (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[0U] 
               >> 0x18U);
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v3 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v3 = 1U;
    }
    if ((0x10U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v4 
            = (0xffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[1U]);
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v4 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v4 = 1U;
    }
    if ((0x20U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v5 
            = (0xffU & (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[1U] 
                        >> 8U));
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v5 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v5 = 1U;
    }
    if ((0x40U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v6 
            = (0xffU & (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[1U] 
                        >> 0x10U));
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v6 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v6 = 1U;
    }
    if ((0x80U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v7 
            = (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[1U] 
               >> 0x18U);
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v7 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v7 = 1U;
    }
    if ((0x100U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v8 
            = (0xffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[2U]);
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v8 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v8 = 1U;
    }
    if ((0x200U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v9 
            = (0xffU & (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[2U] 
                        >> 8U));
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v9 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v9 = 1U;
    }
    if ((0x400U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v10 
            = (0xffU & (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[2U] 
                        >> 0x10U));
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v10 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v10 = 1U;
    }
    if ((0x800U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v11 
            = (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[2U] 
               >> 0x18U);
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v11 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v11 = 1U;
    }
    if ((0x1000U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v12 
            = (0xffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[3U]);
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v12 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v12 = 1U;
    }
    if ((0x2000U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v13 
            = (0xffU & (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[3U] 
                        >> 8U));
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v13 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v13 = 1U;
    }
    if ((0x4000U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v14 
            = (0xffU & (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[3U] 
                        >> 0x10U));
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v14 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v14 = 1U;
    }
    if ((0x8000U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))) {
        __VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v15 
            = (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[3U] 
               >> 0x18U);
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v15 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v15 = 1U;
    }
    if (vlSelfRef.rst_n) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache2lsummu_data_ff 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_read;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__lsummu2dcache_wdata 
            = ((vlSelfRef.lsummu2dcache_i[1U] << 0x1aU) 
               | (vlSelfRef.lsummu2dcache_i[0U] >> 6U));
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index_ff 
            = (0x7ffU & (vlSelfRef.lsummu2dcache_i[1U] 
                         >> 0xaU));
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte 
            = (0xfU & (vlSelfRef.lsummu2dcache_i[0U] 
                       >> 2U));
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_offset_ff 
            = (3U & (vlSelfRef.lsummu2dcache_i[1U] 
                     >> 8U));
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_next;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_tag_ff 
            = (0x1ffffU & ((vlSelfRef.lsummu2dcache_i[2U] 
                            << 0xbU) | (vlSelfRef.lsummu2dcache_i[1U] 
                                        >> 0x15U)));
    } else {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache2lsummu_data_ff = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__lsummu2dcache_wdata = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index_ff = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_offset_ff = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_tag_ff = 0U;
    }
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__lsummu2dcache_wr_ff 
        = ((IData)(vlSelfRef.rst_n) && (1U & (vlSelfRef.lsummu2dcache_i[0U] 
                                              >> 1U)));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dmem_sel_ff 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.dmem_sel_i));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__lsummu2dcache_req_ff 
        = ((IData)(vlSelfRef.rst_n) && (1U & vlSelfRef.lsummu2dcache_i[0U]));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
        = ((0xffffff00U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata) 
           | (0xffU & ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel))
                        ? vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write
                        : vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram
                       [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index])));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
        = ((0xffff00ffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata) 
           | (0xff00U & (((2U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel))
                           ? (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write 
                              >> 8U) : (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram
                                        [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index] 
                                        >> 8U)) << 8U)));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
        = ((0xff00ffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata) 
           | (0xff0000U & (((4U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel))
                             ? (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write 
                                >> 0x10U) : (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram
                                             [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index] 
                                             >> 0x10U)) 
                           << 0x10U)));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
        = ((0xffffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata) 
           | (((8U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel))
                ? (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write 
                   >> 0x18U) : (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram
                                [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index] 
                                >> 0x18U)) << 0x18U));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[0U] 
        = ((0xffffff00U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[0U]) 
           | (0xffU & ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))
                        ? vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[0U]
                        : vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                       [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][0U])));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[0U] 
        = ((0xffff00ffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[0U]) 
           | (0xff00U & (((2U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))
                           ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[0U] 
                               << 0x18U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[0U] 
                                            >> 8U))
                           : ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                               [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][0U] 
                               << 0x18U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                            [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][0U] 
                                            >> 8U))) 
                         << 8U)));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[0U] 
        = ((0xff00ffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[0U]) 
           | (0xff0000U & (((4U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))
                             ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[0U] 
                                 << 0x10U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[0U] 
                                              >> 0x10U))
                             : ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                 [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][0U] 
                                 << 0x10U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                              [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][0U] 
                                              >> 0x10U))) 
                           << 0x10U)));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[0U] 
        = ((0xffffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[0U]) 
           | (((8U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))
                ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[0U] 
                    << 8U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[0U] 
                              >> 0x18U)) : ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                             [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][0U] 
                                             << 8U) 
                                            | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                               [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][0U] 
                                               >> 0x18U))) 
              << 0x18U));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[1U] 
        = ((0xffffff00U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[1U]) 
           | (0xffU & ((0x10U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))
                        ? vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[1U]
                        : vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                       [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][1U])));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[1U] 
        = ((0xffff00ffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[1U]) 
           | (0xff00U & (((0x20U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))
                           ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[1U] 
                               << 0x18U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[1U] 
                                            >> 8U))
                           : ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                               [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][1U] 
                               << 0x18U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                            [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][1U] 
                                            >> 8U))) 
                         << 8U)));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[1U] 
        = ((0xff00ffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[1U]) 
           | (0xff0000U & (((0x40U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))
                             ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[1U] 
                                 << 0x10U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[1U] 
                                              >> 0x10U))
                             : ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                 [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][1U] 
                                 << 0x10U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                              [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][1U] 
                                              >> 0x10U))) 
                           << 0x10U)));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[1U] 
        = ((0xffffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[1U]) 
           | (((0x80U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))
                ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[1U] 
                    << 8U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[1U] 
                              >> 0x18U)) : ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                             [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][1U] 
                                             << 8U) 
                                            | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                               [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][1U] 
                                               >> 0x18U))) 
              << 0x18U));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[2U] 
        = ((0xffffff00U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[2U]) 
           | (0xffU & ((0x100U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))
                        ? vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[2U]
                        : vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                       [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][2U])));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[2U] 
        = ((0xffff00ffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[2U]) 
           | (0xff00U & (((0x200U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))
                           ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[2U] 
                               << 0x18U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[2U] 
                                            >> 8U))
                           : ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                               [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][2U] 
                               << 0x18U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                            [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][2U] 
                                            >> 8U))) 
                         << 8U)));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[2U] 
        = ((0xff00ffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[2U]) 
           | (0xff0000U & (((0x400U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))
                             ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[2U] 
                                 << 0x10U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[2U] 
                                              >> 0x10U))
                             : ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                 [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][2U] 
                                 << 0x10U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                              [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][2U] 
                                              >> 0x10U))) 
                           << 0x10U)));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[2U] 
        = ((0xffffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[2U]) 
           | (((0x800U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))
                ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[2U] 
                    << 8U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[2U] 
                              >> 0x18U)) : ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                             [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][2U] 
                                             << 8U) 
                                            | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                               [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][2U] 
                                               >> 0x18U))) 
              << 0x18U));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[3U] 
        = ((0xffffff00U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[3U]) 
           | (0xffU & ((0x1000U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))
                        ? vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[3U]
                        : vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                       [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][3U])));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[3U] 
        = ((0xffff00ffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[3U]) 
           | (0xff00U & (((0x2000U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))
                           ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[3U] 
                               << 0x18U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[3U] 
                                            >> 8U))
                           : ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                               [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][3U] 
                               << 0x18U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                            [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][3U] 
                                            >> 8U))) 
                         << 8U)));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[3U] 
        = ((0xff00ffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[3U]) 
           | (0xff0000U & (((0x4000U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))
                             ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[3U] 
                                 << 0x10U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[3U] 
                                              >> 0x10U))
                             : ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                 [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][3U] 
                                 << 0x10U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                              [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][3U] 
                                              >> 0x10U))) 
                           << 0x10U)));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[3U] 
        = ((0xffffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[3U]) 
           | (((0x8000U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel))
                ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[3U] 
                    << 8U) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[3U] 
                              >> 0x18U)) : ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                             [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][3U] 
                                             << 8U) 
                                            | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                                               [vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index][3U] 
                                               >> 0x18U))) 
              << 0x18U));
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v0) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v0] 
            = ((0xffffff00U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v0]) 
               | (IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v0));
    }
    if (vlSelfRef.dcache_flush_i) {
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v1 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v1 = 1U;
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v1) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v1] 
            = (0xff7fffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram
               [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v1]);
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v2) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v2] 
            = ((0xffff00ffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v2]) 
               | ((IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v2) 
                  << 8U));
    }
    if (vlSelfRef.dcache_flush_i) {
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v3 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v3 = 1U;
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v3) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v3] 
            = (0xff7fffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram
               [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v3]);
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v4) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v4] 
            = ((0xff00ffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v4]) 
               | ((IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v4) 
                  << 0x10U));
    }
    if (vlSelfRef.dcache_flush_i) {
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v5 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v5 = 1U;
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v5) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v5] 
            = (0xff7fffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram
               [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v5]);
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v6) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v6] 
            = ((0xffffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v6]) 
               | ((IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v6) 
                  << 0x18U));
    }
    if (vlSelfRef.dcache_flush_i) {
        __VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v7 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index;
        __VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v7 = 1U;
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v7) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v7] 
            = (0xff7fffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram
               [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram__v7]);
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v0) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v0][0U] 
            = ((0xffffff00U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v0][0U]) 
               | (IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v0));
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v1) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v1][0U] 
            = ((0xffff00ffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v1][0U]) 
               | ((IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v1) 
                  << 8U));
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v2) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v2][0U] 
            = ((0xff00ffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v2][0U]) 
               | ((IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v2) 
                  << 0x10U));
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v3) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v3][0U] 
            = ((0xffffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v3][0U]) 
               | ((IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v3) 
                  << 0x18U));
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v4) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v4][1U] 
            = ((0xffffff00U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v4][1U]) 
               | (IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v4));
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v5) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v5][1U] 
            = ((0xffff00ffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v5][1U]) 
               | ((IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v5) 
                  << 8U));
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v6) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v6][1U] 
            = ((0xff00ffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v6][1U]) 
               | ((IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v6) 
                  << 0x10U));
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v7) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v7][1U] 
            = ((0xffffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v7][1U]) 
               | ((IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v7) 
                  << 0x18U));
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v8) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v8][2U] 
            = ((0xffffff00U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v8][2U]) 
               | (IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v8));
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v9) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v9][2U] 
            = ((0xffff00ffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v9][2U]) 
               | ((IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v9) 
                  << 8U));
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v10) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v10][2U] 
            = ((0xff00ffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v10][2U]) 
               | ((IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v10) 
                  << 0x10U));
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v11) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v11][2U] 
            = ((0xffffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v11][2U]) 
               | ((IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v11) 
                  << 0x18U));
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v12) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v12][3U] 
            = ((0xffffff00U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v12][3U]) 
               | (IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v12));
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v13) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v13][3U] 
            = ((0xffff00ffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v13][3U]) 
               | ((IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v13) 
                  << 8U));
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v14) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v14][3U] 
            = ((0xff00ffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v14][3U]) 
               | ((IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v14) 
                  << 0x10U));
    }
    if (__VdlySet__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v15) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram[__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v15][3U] 
            = ((0xffffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram
                [__VdlyDim0__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v15][3U]) 
               | ((IData)(__VdlyVal__wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram__v15) 
                  << 0x18U));
    }
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write = 0U;
    if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte))) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write 
            = ((0xffffff00U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write) 
               | (0xffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__lsummu2dcache_wdata));
    }
    if ((2U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte))) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write 
            = ((0xffff00ffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write) 
               | (0xff00U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__lsummu2dcache_wdata));
    }
    if ((4U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte))) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write 
            = ((0xff00ffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write) 
               | (0xff0000U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__lsummu2dcache_wdata));
    }
    if ((8U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte))) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write 
            = ((0xffffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write) 
               | (0xff000000U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__lsummu2dcache_wdata));
    }
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte = 0U;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_clean = 0U;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_wr = 0U;
    wb_dcache_top__DOT__wb_dcache_controller_module__DOT____VdfgRegularize_hbc0d45b6_0_0 
        = ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dmem_sel_ff) 
           & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__lsummu2dcache_req_ff));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_next 
        = vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff;
    vlSelfRef.wb_dcache_top__DOT__cache_hit = ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_tag_ff 
                                                == 
                                                (0x1ffffU 
                                                 & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata)) 
                                               & (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
                                                  >> 0x17U));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[0U] = 0U;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[1U] = 0U;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[2U] = 0U;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[3U] = 0U;
    if ((2U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_offset_ff))) {
        if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_offset_ff))) {
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte 
                = ((0xfffU & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte)) 
                   | ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte) 
                      << 0xcU));
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_read 
                = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[3U];
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[3U] 
                = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write;
        } else {
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte 
                = ((0xf0ffU & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte)) 
                   | ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte) 
                      << 8U));
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_read 
                = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[2U];
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[2U] 
                = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write;
        }
    } else if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_offset_ff))) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte 
            = ((0xff0fU & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte)) 
               | ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte) 
                  << 4U));
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_read 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[1U];
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[1U] 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write;
    } else {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte 
            = ((0xfff0U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte)) 
               | (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte));
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_read 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[0U];
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[0U] 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write;
    }
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_miss 
        = ((~ (IData)(vlSelfRef.wb_dcache_top__DOT__cache_hit)) 
           & (IData)(wb_dcache_top__DOT__wb_dcache_controller_module__DOT____VdfgRegularize_hbc0d45b6_0_0));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_hit 
        = ((IData)(wb_dcache_top__DOT__wb_dcache_controller_module__DOT____VdfgRegularize_hbc0d45b6_0_0) 
           & (IData)(vlSelfRef.wb_dcache_top__DOT__cache_hit));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2lsummu_ack = 0U;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next 
        = vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff;
    if ((4U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))) {
        if ((1U & (~ ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))) {
                if ((1U & vlSelfRef.mem2dcache_i[0U])) {
                    if (vlSelfRef.dcache_flush_i) {
                        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_clean = 1U;
                    }
                }
            }
            if ((1U & (~ (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff)))) {
                if ((1U & vlSelfRef.mem2dcache_i[0U])) {
                    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_wr = 1U;
                }
            }
        }
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_wr = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req = 0U;
        if ((2U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))) {
            if ((1U & (~ (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff)))) {
                if ((1U & (~ (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
                              >> 0x18U)))) {
                    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_next 
                        = ((0x7ffU == (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff))
                            ? 0U : (0x7ffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff))));
                }
                if ((0x1000000U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata)) {
                    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_wr = 1U;
                    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req = 1U;
                    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req = 1U;
                }
            }
            if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))) {
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2lsummu_ack = 1U;
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next = 0U;
            } else {
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next 
                    = ((0x1000000U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata)
                        ? 5U : ((0x7ffU == (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff))
                                 ? 7U : 3U));
            }
        } else if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))) {
            if ((1U & vlSelfRef.mem2dcache_i[0U])) {
                if (vlSelfRef.dcache_flush_i) {
                    if ((1U & (~ (IData)((0x7ffU == (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff)))))) {
                        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_next 
                            = (0x7ffU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff)));
                    }
                    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next = 3U;
                } else {
                    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next = 4U;
                }
                if ((1U & (~ (IData)(vlSelfRef.dcache_flush_i)))) {
                    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req = 1U;
                }
            } else {
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next = 5U;
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req = 1U;
            }
            if ((1U & (~ vlSelfRef.mem2dcache_i[0U]))) {
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_wr = 1U;
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req = 1U;
            }
        } else {
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next 
                = ((1U & vlSelfRef.mem2dcache_i[0U])
                    ? 1U : 4U);
            if ((1U & (~ vlSelfRef.mem2dcache_i[0U]))) {
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req = 1U;
            }
        }
    } else {
        if ((2U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))) {
            if ((1U & (~ (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff)))) {
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2lsummu_ack = 1U;
            }
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next 
                = ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))
                    ? 6U : 0U);
        } else if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))) {
            if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_hit) {
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2lsummu_ack = 1U;
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next = 0U;
            } else if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_miss) {
                vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next 
                    = ((0x1000000U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata)
                        ? 5U : 4U);
            }
        } else {
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next 
                = ((IData)(vlSelfRef.dcache_flush_i)
                    ? 6U : ((1U & vlSelfRef.lsummu2dcache_i[0U])
                             ? 1U : 0U));
        }
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_wr = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req = 0U;
        if ((1U & (~ ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff)))) {
                if ((1U & (~ (IData)(vlSelfRef.dcache_flush_i)))) {
                    if ((1U & (~ vlSelfRef.lsummu2dcache_i[0U]))) {
                        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_next = 0U;
                    }
                }
            }
            if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))) {
                if ((1U & (~ (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_hit)))) {
                    if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_miss) {
                        if ((0x1000000U & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata)) {
                            vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_wr = 1U;
                            vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req = 1U;
                        }
                        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req = 1U;
                    }
                }
            }
        }
    }
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wr = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff))) {
                if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_hit) {
                    if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__lsummu2dcache_wr_ff) {
                        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wr = 1U;
                    }
                }
            }
        }
    }
    if ((1U & ((~ (IData)(vlSelfRef.dmem_sel_i)) | (IData)(vlSelfRef.dcache_kill_i)))) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_next = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wr = 0U;
    }
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index 
        = (0x7ffU & ((IData)(vlSelfRef.dcache_flush_i)
                      ? (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff)
                      : ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wr)
                          ? (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index_ff)
                          : ((vlSelfRef.lsummu2dcache_i[1U] 
                              << 0x16U) | (vlSelfRef.lsummu2dcache_i[1U] 
                                           >> 0xaU)))));
    vlSelfRef.dcache2lsummu_o = (((QData)((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_read)) 
                                  << 1U) | (QData)((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2lsummu_ack)));
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel = 0U;
    if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_wr) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel = 0xffffU;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[0U] 
            = ((vlSelfRef.mem2dcache_i[1U] << 0x1fU) 
               | (vlSelfRef.mem2dcache_i[0U] >> 1U));
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[1U] 
            = ((vlSelfRef.mem2dcache_i[2U] << 0x1fU) 
               | (vlSelfRef.mem2dcache_i[1U] >> 1U));
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[2U] 
            = ((vlSelfRef.mem2dcache_i[3U] << 0x1fU) 
               | (vlSelfRef.mem2dcache_i[2U] >> 1U));
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[3U] 
            = ((vlSelfRef.mem2dcache_i[4U] << 0x1fU) 
               | (vlSelfRef.mem2dcache_i[3U] >> 1U));
    } else if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wr) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[0U] 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[0U];
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[1U] 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[1U];
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[2U] 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[2U];
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[3U] 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[3U];
    } else {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[0U] = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[1U] = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[2U] = 0U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata[3U] = 0U;
    }
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write = 0U;
    if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_clean) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel = 8U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write 
            = (0xffffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write);
    } else if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wr) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel = 8U;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write 
            = (0x1000000U | (0xffffffU & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write));
    } else if (vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_wr) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel = 0xfU;
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write 
            = (0x800000U | (0x1ffffU & ((vlSelfRef.lsummu2dcache_i[2U] 
                                         << 0xbU) | 
                                        (vlSelfRef.lsummu2dcache_i[1U] 
                                         >> 0x15U))));
    }
    vlSelfRef.dcache2mem_o[0U] = ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[0U] 
                                   << 2U) | (((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req) 
                                              << 1U) 
                                             | (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_wr)));
    vlSelfRef.dcache2mem_o[1U] = ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[0U] 
                                   >> 0x1eU) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[1U] 
                                                << 2U));
    vlSelfRef.dcache2mem_o[2U] = ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[1U] 
                                   >> 0x1eU) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[2U] 
                                                << 2U));
    vlSelfRef.dcache2mem_o[3U] = ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[2U] 
                                   >> 0x1eU) | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[3U] 
                                                << 2U));
    vlSelfRef.dcache2mem_o[4U] = ((0xfffffffcU & vlSelfRef.dcache2mem_o[4U]) 
                                  | (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[3U] 
                                     >> 0x1eU));
    vlSelfRef.dcache2mem_o[4U] = ((3U & vlSelfRef.dcache2mem_o[4U]) 
                                  | (((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req)
                                       ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
                                           << 0xfU) 
                                          | ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index) 
                                             << 4U))
                                       : ((vlSelfRef.lsummu2dcache_i[2U] 
                                           << 0x1aU) 
                                          | (vlSelfRef.lsummu2dcache_i[1U] 
                                             >> 6U))) 
                                     << 2U));
    vlSelfRef.dcache2mem_o[5U] = (((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req)
                                    ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
                                        << 0xfU) | 
                                       ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index) 
                                        << 4U)) : (
                                                   (vlSelfRef.lsummu2dcache_i[2U] 
                                                    << 0x1aU) 
                                                   | (vlSelfRef.lsummu2dcache_i[1U] 
                                                      >> 6U))) 
                                  >> 0x1eU);
}

void Vdcache_data_ram___024root___eval_triggers__act(Vdcache_data_ram___024root* vlSelf);

bool Vdcache_data_ram___024root___eval_phase__act(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval_phase__act\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vdcache_data_ram___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vdcache_data_ram___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vdcache_data_ram___024root___eval_phase__nba(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval_phase__nba\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vdcache_data_ram___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdcache_data_ram___024root___dump_triggers__ico(Vdcache_data_ram___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdcache_data_ram___024root___dump_triggers__nba(Vdcache_data_ram___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdcache_data_ram___024root___dump_triggers__act(Vdcache_data_ram___024root* vlSelf);
#endif  // VL_DEBUG

void Vdcache_data_ram___024root___eval(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vdcache_data_ram___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/masooma/UETRV-PCore-main/rtl/memory/wb_dcache/wb_dcache_top.sv", 18, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vdcache_data_ram___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vdcache_data_ram___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/masooma/UETRV-PCore-main/rtl/memory/wb_dcache/wb_dcache_top.sv", 18, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vdcache_data_ram___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/masooma/UETRV-PCore-main/rtl/memory/wb_dcache/wb_dcache_top.sv", 18, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vdcache_data_ram___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vdcache_data_ram___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vdcache_data_ram___024root___eval_debug_assertions(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval_debug_assertions\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.dmem_sel_i & 0xfeU)))) {
        Verilated::overWidthError("dmem_sel_i");}
    if (VL_UNLIKELY(((vlSelfRef.dcache_flush_i & 0xfeU)))) {
        Verilated::overWidthError("dcache_flush_i");}
    if (VL_UNLIKELY(((vlSelfRef.dcache_kill_i & 0xfeU)))) {
        Verilated::overWidthError("dcache_kill_i");}
}
#endif  // VL_DEBUG
