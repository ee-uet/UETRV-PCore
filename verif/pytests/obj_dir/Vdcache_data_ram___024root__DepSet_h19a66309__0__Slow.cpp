// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdcache_data_ram.h for the primary calling header

#include "Vdcache_data_ram__pch.h"
#include "Vdcache_data_ram___024root.h"

VL_ATTR_COLD void Vdcache_data_ram___024root___eval_static(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval_static\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vdcache_data_ram___024root___eval_initial__TOP(Vdcache_data_ram___024root* vlSelf);

VL_ATTR_COLD void Vdcache_data_ram___024root___eval_initial(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval_initial\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vdcache_data_ram___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vdcache_data_ram___024root___eval_final(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval_final\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdcache_data_ram___024root___dump_triggers__stl(Vdcache_data_ram___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vdcache_data_ram___024root___eval_phase__stl(Vdcache_data_ram___024root* vlSelf);

VL_ATTR_COLD void Vdcache_data_ram___024root___eval_settle(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval_settle\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vdcache_data_ram___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/masooma/UETRV-PCore-main/rtl/memory/wb_dcache/wb_dcache_top.sv", 18, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vdcache_data_ram___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdcache_data_ram___024root___dump_triggers__stl(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___dump_triggers__stl\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdcache_data_ram___024root___stl_sequent__TOP__0(Vdcache_data_ram___024root* vlSelf);
VL_ATTR_COLD void Vdcache_data_ram___024root____Vm_traceActivitySetAll(Vdcache_data_ram___024root* vlSelf);

VL_ATTR_COLD void Vdcache_data_ram___024root___eval_stl(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval_stl\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vdcache_data_ram___024root___stl_sequent__TOP__0(vlSelf);
        Vdcache_data_ram___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vdcache_data_ram___024root___stl_sequent__TOP__0(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___stl_sequent__TOP__0\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ wb_dcache_top__DOT__wb_dcache_controller_module__DOT____VdfgRegularize_hbc0d45b6_0_0;
    wb_dcache_top__DOT__wb_dcache_controller_module__DOT____VdfgRegularize_hbc0d45b6_0_0 = 0;
    // Body
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_kill = 0U;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte = 0U;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_next 
        = vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff;
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
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_clean = 0U;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_wr = 0U;
    vlSelfRef.wb_dcache_top__DOT__cache_hit = ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_tag_ff 
                                                == 
                                                (0x1ffffU 
                                                 & vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata)) 
                                               & (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
                                                  >> 0x17U));
    wb_dcache_top__DOT__wb_dcache_controller_module__DOT____VdfgRegularize_hbc0d45b6_0_0 
        = ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dmem_sel_ff) 
           & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__lsummu2dcache_req_ff));
    if ((1U & ((~ (IData)(vlSelfRef.dmem_sel_i)) | (IData)(vlSelfRef.dcache_kill_i)))) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_kill = 1U;
    }
    vlSelfRef.dcache2mem_kill_o = vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_kill;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[0U] = 0U;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[1U] = 0U;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[2U] = 0U;
    vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[3U] = 0U;
    if ((2U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_offset_ff))) {
        if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_offset_ff))) {
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_read 
                = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[3U];
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte 
                = ((0xfffU & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte)) 
                   | ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte) 
                      << 0xcU));
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[3U] 
                = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write;
        } else {
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_read 
                = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[2U];
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte 
                = ((0xf0ffU & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte)) 
                   | ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte) 
                      << 8U));
            vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[2U] 
                = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write;
        }
    } else if ((1U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_offset_ff))) {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_read 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[1U];
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte 
            = ((0xff0fU & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte)) 
               | ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte) 
                  << 4U));
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write[1U] 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write;
    } else {
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_read 
            = vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read[0U];
        vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte 
            = ((0xfff0U & (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte)) 
               | (IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte));
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

VL_ATTR_COLD void Vdcache_data_ram___024root___eval_triggers__stl(Vdcache_data_ram___024root* vlSelf);

VL_ATTR_COLD bool Vdcache_data_ram___024root___eval_phase__stl(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval_phase__stl\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vdcache_data_ram___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vdcache_data_ram___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdcache_data_ram___024root___dump_triggers__ico(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___dump_triggers__ico\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdcache_data_ram___024root___dump_triggers__act(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___dump_triggers__act\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdcache_data_ram___024root___dump_triggers__nba(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___dump_triggers__nba\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdcache_data_ram___024root____Vm_traceActivitySetAll(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root____Vm_traceActivitySetAll\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_ATTR_COLD void Vdcache_data_ram___024root___ctor_var_reset(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___ctor_var_reset\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->dmem_sel_i = VL_RAND_RESET_I(1);
    vlSelf->dcache_flush_i = VL_RAND_RESET_I(1);
    vlSelf->dcache_kill_i = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(70, vlSelf->lsummu2dcache_i);
    vlSelf->dcache2lsummu_o = VL_RAND_RESET_Q(33);
    VL_RAND_RESET_W(129, vlSelf->mem2dcache_i);
    VL_RAND_RESET_W(162, vlSelf->dcache2mem_o);
    vlSelf->dcache2mem_kill_o = VL_RAND_RESET_I(1);
    vlSelf->wb_dcache_top__DOT__cache_hit = VL_RAND_RESET_I(1);
    vlSelf->wb_dcache_top__DOT__collect_info_tag = VL_RAND_RESET_I(1);
    vlSelf->wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff = VL_RAND_RESET_I(3);
    vlSelf->wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next = VL_RAND_RESET_I(3);
    vlSelf->wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_next = VL_RAND_RESET_I(11);
    vlSelf->wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff = VL_RAND_RESET_I(11);
    vlSelf->wb_dcache_top__DOT__wb_dcache_controller_module__DOT__lsummu2dcache_wr_ff = VL_RAND_RESET_I(1);
    vlSelf->wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2lsummu_ack = VL_RAND_RESET_I(1);
    vlSelf->wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_hit = VL_RAND_RESET_I(1);
    vlSelf->wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_miss = VL_RAND_RESET_I(1);
    vlSelf->wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_wr = VL_RAND_RESET_I(1);
    vlSelf->wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req = VL_RAND_RESET_I(1);
    vlSelf->wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req = VL_RAND_RESET_I(1);
    vlSelf->wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wr = VL_RAND_RESET_I(1);
    vlSelf->wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_wr = VL_RAND_RESET_I(1);
    vlSelf->wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_clean = VL_RAND_RESET_I(1);
    vlSelf->wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_kill = VL_RAND_RESET_I(1);
    vlSelf->wb_dcache_top__DOT__wb_dcache_controller_module__DOT__lsummu2dcache_req_ff = VL_RAND_RESET_I(1);
    vlSelf->wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dmem_sel_ff = VL_RAND_RESET_I(1);
    VL_ZERO_RESET_W(128, vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read);
    VL_ZERO_RESET_W(128, vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write);
    VL_ZERO_RESET_W(128, vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata);
    vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write = VL_RAND_RESET_I(32);
    vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_read = VL_RAND_RESET_I(32);
    vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write = VL_RAND_RESET_I(32);
    vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__lsummu2dcache_wdata = VL_RAND_RESET_I(32);
    vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte = VL_RAND_RESET_I(16);
    vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel = VL_RAND_RESET_I(16);
    vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte = VL_RAND_RESET_I(4);
    vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel = VL_RAND_RESET_I(4);
    vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache2lsummu_data_ff = VL_RAND_RESET_I(32);
    vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_tag_ff = VL_RAND_RESET_I(17);
    vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_offset_ff = VL_RAND_RESET_I(2);
    vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index = VL_RAND_RESET_I(11);
    vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index_ff = VL_RAND_RESET_I(11);
    vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 2048; ++__Vi0) {
        VL_RAND_RESET_W(128, vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_data_ram_module__DOT__dcache_dataram[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 2048; ++__Vi0) {
        vlSelf->wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache_tag_ram_module__DOT__dcache_tagram[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
