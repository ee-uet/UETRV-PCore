// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcore_tb.h for the primary calling header

#include "verilated.h"

#include "Vcore_tb___024root.h"

VL_INLINE_OPT void Vcore_tb___024root___act_sequent__TOP__0(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___act_sequent__TOP__0\n"); );
    // Body
    vlSelf->core_tb__DOT__reset = (9ULL < vlSelf->core_tb__DOT__loop_count);
}

VL_INLINE_OPT void Vcore_tb___024root___act_sequent__TOP__1(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___act_sequent__TOP__1\n"); );
    // Body
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
        = ((0xfU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U]) 
           | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U] 
              << 4U));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U] 
        = ((0xfffffff0U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U]) 
           | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U] 
              >> 0x1cU));
    if ((4U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))) {
        if ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                = ((0xfU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U]) 
                   | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U] 
                      << 4U));
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U] 
                = ((0xfffffff0U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U]) 
                   | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U] 
                      >> 0x1cU));
        } else if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                = ((0xfU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U]) 
                   | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U] 
                      << 4U));
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U] 
                = ((0xfffffff0U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U]) 
                   | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U] 
                      >> 0x1cU));
        }
    } else if ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))) {
        if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                = ((0xfU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U]) 
                   | (((2U == (0xfU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                       >> 3U))) ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U]
                        : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_result_o) 
                      << 4U));
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U] 
                = ((0xfffffff0U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U]) 
                   | (((2U == (0xfU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                       >> 3U))) ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U]
                        : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_result_o) 
                      >> 0x1cU));
        }
    } else if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state)))) {
        if ((1U & (~ (IData)((0U != (0xfU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                             >> 3U))))))) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                = ((0xfU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U]) 
                   | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U] 
                      << 4U));
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U] 
                = ((0xfffffff0U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U]) 
                   | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U] 
                      >> 0x1cU));
        }
    }
}

VL_INLINE_OPT void Vcore_tb___024root___act_sequent__TOP__2(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___act_sequent__TOP__2\n"); );
    // Body
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT____VdfgTmp_h21021b6f__0 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_exc_req) 
           | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_irq_req));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sret_pc_req 
        = ((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT____VdfgTmp_h21021b6f__0)) 
           & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sret_req));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_pc_req 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sret_pc_req) 
           | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT____VdfgTmp_h21021b6f__0));
}

VL_INLINE_OPT void Vcore_tb___024root___act_sequent__TOP__3(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___act_sequent__TOP__3\n"); );
    // Body
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT____VdfgTmp_he5991c42__0 
        = (1U & ((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_exc_req)) 
                 & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_irq_req))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mret_pc_req 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mret_req) 
           & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT____VdfgTmp_he5991c42__0));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_pc_req 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mret_pc_req) 
           | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_exc_req) 
              | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_irq_req)));
}

VL_INLINE_OPT void Vcore_tb___024root___act_comb__TOP__0(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___act_comb__TOP__0\n"); );
    // Body
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__trap_priv_mode = 3U;
    if ((((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_delegated_req) 
          | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_delegated_req)) 
         & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT____VdfgTmp_he5991c42__0))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__trap_priv_mode 
            = ((3U == (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff))
                ? 3U : 1U);
    }
}

VL_INLINE_OPT void Vcore_tb___024root___act_comb__TOP__1(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___act_comb__TOP__1\n"); );
    // Body
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgTmp_h4675c004__0 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_pc_req) 
           | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_pc_req));
    vlSelf->__VdfgTmp_h7bbdf8ad__0 = ((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgTmp_h4675c004__0)) 
                                      & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_next));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2lsu 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgTmp_h4675c004__0) 
           | (IData)(vlSelf->__VdfgTmp_h7bbdf8ad__0));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr2fwd 
        = (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgTmp_h4675c004__0) 
            << 2U) | (((IData)(vlSelf->__VdfgTmp_h7bbdf8ad__0) 
                       << 1U) | (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                       >> 1U))));
}

VL_INLINE_OPT void Vcore_tb___024root___act_comb__TOP__2(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___act_comb__TOP__2\n"); );
    // Body
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff;
    if (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_exc_req) 
         | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_irq_req))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_next 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__trap_priv_mode;
    } else if (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_exc_req) 
                | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_irq_req))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_next 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__trap_priv_mode;
    } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sret_req) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_next 
            = (1U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff 
                     >> 8U));
    } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mret_req) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_next 
            = (3U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff 
                     >> 0xbU));
    } else if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_wr_flag)))) {
        if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sstatus_wr_flag)))) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_next 
                = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff;
        }
    }
}

VL_INLINE_OPT void Vcore_tb___024root___act_comb__TOP__3(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___act_comb__TOP__3\n"); );
    // Init
    CData/*3:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_code;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_code = 0;
    IData/*31:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_new_pc;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_new_pc = 0;
    IData/*31:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_new_pc;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_new_pc = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__ms_mode_ecall_req;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__ms_mode_ecall_req = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__pf_exc_req;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__pf_exc_req = 0;
    CData/*1:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index = 0;
    CData/*3:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__dtlb_update;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__dtlb_update = 0;
    // Body
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr2lsu_data 
        = ((0x7ffffe0U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_next 
                          << 5U)) | ((0x10U & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_next 
                                                >> 0x1bU) 
                                               & ((3U 
                                                   != (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_next)) 
                                                  << 4U))) 
                                     | (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__en_ld_st_vaddr_next) 
                                         << 3U) | (
                                                   (4U 
                                                    & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff 
                                                       >> 0x11U)) 
                                                   | (((IData)(
                                                               (0U 
                                                                != 
                                                                (6U 
                                                                 & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr2fwd)))) 
                                                       << 1U) 
                                                      | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sfence_vma_req))))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__en_ld_st_vaddr_next 
        = (1U & ((((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff 
                    >> 0x11U) & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_ff 
                                 >> 0x1fU)) & (3U != 
                                               (3U 
                                                & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff 
                                                   >> 0xbU)))) 
                 | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr2lsu_data 
                    >> 4U)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[0U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[0U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[1U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[1U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[2U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[2U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[3U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[3U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[4U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[4U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[5U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[5U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[6U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[6U];
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index 
        = (3U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_ff 
                 >> 0x16U));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_hcbf4d47b__0 
        = (1U & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_ff 
                  >> 6U) & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_ff 
                             >> 1U) | ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_ff 
                                        >> 3U) & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr2lsu_data 
                                                  >> 2U)))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgTmp_hd5ca5221__0 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT____VdfgTmp_h1ec46b79__0) 
           & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr2lsu_data 
              >> 3U));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U] 
        = ((7U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U]) 
           | ((IData)((((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U])) 
                        << 1U) | (QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT____VdfgTmp_h1ec46b79__0)))) 
              << 3U));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[2U] 
        = (0x3fU & (((IData)((((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U])) 
                               << 1U) | (QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT____VdfgTmp_h1ec46b79__0)))) 
                     >> 0x1dU) | ((IData)(((((QData)((IData)(
                                                             vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U])) 
                                             << 1U) 
                                            | (QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT____VdfgTmp_h1ec46b79__0))) 
                                           >> 0x20U)) 
                                  << 3U)));
    if ((8U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr2lsu_data)) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U] 
            = ((7U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U]) 
               | ((IData)((((QData)((IData)((0x3fffffU 
                                             & (IData)(
                                                       (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb2mmu 
                                                        >> 0xcU))))) 
                            << 0xdU) | (QData)((IData)(
                                                       ((0x1ffeU 
                                                         & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                            << 1U)) 
                                                        | (1U 
                                                           & (IData)(
                                                                     (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb2mmu 
                                                                      >> 1U)))))))) 
                  << 3U));
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[2U] 
            = (0x3fU & (((IData)((((QData)((IData)(
                                                   (0x3fffffU 
                                                    & (IData)(
                                                              (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb2mmu 
                                                               >> 0xcU))))) 
                                   << 0xdU) | (QData)((IData)(
                                                              ((0x1ffeU 
                                                                & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                                   << 1U)) 
                                                               | (1U 
                                                                  & (IData)(
                                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb2mmu 
                                                                             >> 1U)))))))) 
                         >> 0x1dU) | ((IData)(((((QData)((IData)(
                                                                 (0x3fffffU 
                                                                  & (IData)(
                                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb2mmu 
                                                                             >> 0xcU))))) 
                                                 << 0xdU) 
                                                | (QData)((IData)(
                                                                  ((0x1ffeU 
                                                                    & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                                       << 1U)) 
                                                                   | (1U 
                                                                      & (IData)(
                                                                                (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb2mmu 
                                                                                >> 1U))))))) 
                                               >> 0x20U)) 
                                      << 3U)));
        if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb2mmu))) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U] 
                = ((0xfc00ffffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U]) 
                   | (0x3ff0000U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                    << 4U)));
        }
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__dtlb_update = 0U;
    if ((1U & (~ ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff))) {
            if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff)))) {
                if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_valid_ff) {
                    if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_h23a25fc1__0)))) {
                        if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_haf4fd536__0) {
                            if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__iwalk_active_ff)))) {
                                if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_hcbf4d47b__0) {
                                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__dtlb_update = 1U;
                                }
                                if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_he4191b8e__0) {
                                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__dtlb_update = 0U;
                                }
                            }
                            if (((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_ff)) 
                                 & (0U != (0x3ffU & 
                                           (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_ff 
                                            >> 0xaU))))) {
                                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__dtlb_update = 0U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__dtlb_miss 
        = ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr2lsu_data 
            >> 3U) & ((~ (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb2mmu 
                                  >> 1U))) & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgTmp_hd5ca5221__0)));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_code = 0xaU;
    if ((4U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff))) {
        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_code 
            = (0xfU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[0U] 
                       >> 1U));
    } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_exc_req) {
        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_code = 2U;
    } else if ((4U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U])) {
        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_code = 0xdU;
    } else if ((2U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U])) {
        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_code = 0xfU;
    } else if ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U])) {
        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_code = 0xcU;
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__pf_exc_req 
        = (IData)((0U != (7U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U])));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U] 
        = ((0xfU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U]) 
           | (0xfffffff0U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U]));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[2U] 
        = (0xfU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[2U]);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
        = ((0xfffffff0U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U]) 
           | ((0xcU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                       >> 5U)) | ((0x3ffffffeU & (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__ld_req) 
                                                   << 1U) 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U] 
                                                     >> 2U))) 
                                  | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__st_req) 
                                     & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U] 
                                        >> 3U)))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[1U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[1U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[2U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[2U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[3U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[3U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[4U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[4U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[5U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[5U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[6U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[6U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[7U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[7U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[8U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[8U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[9U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[9U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xaU] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xaU];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xbU] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xbU];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xcU] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xcU];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xdU] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xdU];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xeU] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xeU];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xfU] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xfU];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x10U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x10U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x11U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x11U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x12U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x12U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x13U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x13U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x14U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x14U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x15U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x15U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x16U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x16U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x17U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x17U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x18U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x18U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x19U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x19U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x1aU] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x1aU];
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index 
        = (0xfU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_ff 
                   >> 0x16U));
    if ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr2lsu_data)) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[1U] 
            = (0xfffffffdU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[1U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[2U] 
            = (0xff7fffffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[2U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[4U] 
            = (0xffffdfffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[4U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[6U] 
            = (0xfffff7U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[6U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[1U] 
            = (0xfffffffdU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[1U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[2U] 
            = (0xff7fffffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[2U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[4U] 
            = (0xffffdfffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[4U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[6U] 
            = (0xfffffff7U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[6U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[7U] 
            = (0xfdffffffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[7U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[9U] 
            = (0xffff7fffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[9U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xbU] 
            = (0xffffffdfU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xbU]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xcU] 
            = (0xf7ffffffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xcU]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xeU] 
            = (0xfffdffffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xeU]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x10U] 
            = (0xffffff7fU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x10U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x11U] 
            = (0xdfffffffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x11U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x13U] 
            = (0xfff7ffffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x13U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x15U] 
            = (0xfffffdffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x15U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x16U] 
            = (0x7fffffffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x16U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x18U] 
            = (0xffdfffffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x18U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x1aU] 
            = (0xfffff7ffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x1aU]);
    } else {
        if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__itlb_update) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT____Vlvbound_hd6fcc4ae__0 
                = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____VdfgExtracted_h1a7370a5__0;
            if ((0xd7U >= (0xffU & ((IData)(0x36U) 
                                    * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index))))) {
                VL_ASSIGNSEL_WI(216,32,(0xffU & ((IData)(0x36U) 
                                                 * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index))), vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT____Vlvbound_hd6fcc4ae__0);
            }
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT____Vlvbound_h130160c9__0 
                = (1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_ff)));
            if ((0xd7U >= ((IData)(0x20U) + (0xffU 
                                             & ((IData)(0x36U) 
                                                * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index)))))) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[(
                                                                                ((IData)(0x20U) 
                                                                                + 
                                                                                (0xffU 
                                                                                & ((IData)(0x36U) 
                                                                                * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index)))) 
                                                                                >> 5U)] 
                    = (((~ ((IData)(1U) << (0x1fU & 
                                            ((IData)(0x20U) 
                                             + (0xffU 
                                                & ((IData)(0x36U) 
                                                   * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index))))))) 
                        & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[
                        (((IData)(0x20U) + (0xffU & 
                                            ((IData)(0x36U) 
                                             * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index)))) 
                         >> 5U)]) | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT____Vlvbound_h130160c9__0) 
                                     << (0x1fU & ((IData)(0x20U) 
                                                  + 
                                                  (0xffU 
                                                   & ((IData)(0x36U) 
                                                      * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index)))))));
            }
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT____Vlvbound_haa3579db__0 
                = (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_ff 
                   >> 0x16U);
            if ((0xd7U >= ((IData)(0x2cU) + (0xffU 
                                             & ((IData)(0x36U) 
                                                * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index)))))) {
                VL_ASSIGNSEL_WI(216,10,((IData)(0x2cU) 
                                        + (0xffU & 
                                           ((IData)(0x36U) 
                                            * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index)))), vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT____Vlvbound_haa3579db__0);
            }
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT____Vlvbound_ha9c1d2a1__0 
                = (0x3ffU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_ff 
                             >> 0xcU));
            if ((0xd7U >= ((IData)(0x22U) + (0xffU 
                                             & ((IData)(0x36U) 
                                                * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index)))))) {
                VL_ASSIGNSEL_WI(216,10,((IData)(0x22U) 
                                        + (0xffU & 
                                           ((IData)(0x36U) 
                                            * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index)))), vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT____Vlvbound_ha9c1d2a1__0);
            }
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT____Vlvbound_h12c5995c__0 = 1U;
            if ((0xd7U >= ((IData)(0x21U) + (0xffU 
                                             & ((IData)(0x36U) 
                                                * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index)))))) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[(
                                                                                ((IData)(0x21U) 
                                                                                + 
                                                                                (0xffU 
                                                                                & ((IData)(0x36U) 
                                                                                * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index)))) 
                                                                                >> 5U)] 
                    = (((~ ((IData)(1U) << (0x1fU & 
                                            ((IData)(0x21U) 
                                             + (0xffU 
                                                & ((IData)(0x36U) 
                                                   * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index))))))) 
                        & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[
                        (((IData)(0x21U) + (0xffU & 
                                            ((IData)(0x36U) 
                                             * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index)))) 
                         >> 5U)]) | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT____Vlvbound_h12c5995c__0) 
                                     << (0x1fU & ((IData)(0x21U) 
                                                  + 
                                                  (0xffU 
                                                   & ((IData)(0x36U) 
                                                      * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__w_index)))))));
            }
        }
        if (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__dtlb_update) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____Vlvbound_hf69d70be__0 
                = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____VdfgExtracted_h1a7370a5__0;
            if ((0x35fU >= (0x3ffU & ((IData)(0x36U) 
                                      * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index))))) {
                VL_ASSIGNSEL_WI(864,32,(0x3ffU & ((IData)(0x36U) 
                                                  * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index))), vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____Vlvbound_hf69d70be__0);
            }
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____Vlvbound_h22748b0f__0 
                = (1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_ff)));
            if ((0x35fU >= ((IData)(0x20U) + (0x3ffU 
                                              & ((IData)(0x36U) 
                                                 * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index)))))) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[(
                                                                                ((IData)(0x20U) 
                                                                                + 
                                                                                (0x3ffU 
                                                                                & ((IData)(0x36U) 
                                                                                * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index)))) 
                                                                                >> 5U)] 
                    = (((~ ((IData)(1U) << (0x1fU & 
                                            ((IData)(0x20U) 
                                             + (0x3ffU 
                                                & ((IData)(0x36U) 
                                                   * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index))))))) 
                        & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[
                        (((IData)(0x20U) + (0x3ffU 
                                            & ((IData)(0x36U) 
                                               * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index)))) 
                         >> 5U)]) | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____Vlvbound_h22748b0f__0) 
                                     << (0x1fU & ((IData)(0x20U) 
                                                  + 
                                                  (0x3ffU 
                                                   & ((IData)(0x36U) 
                                                      * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index)))))));
            }
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____Vlvbound_hfc7452ca__0 
                = (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_ff 
                   >> 0x16U);
            if ((0x35fU >= ((IData)(0x2cU) + (0x3ffU 
                                              & ((IData)(0x36U) 
                                                 * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index)))))) {
                VL_ASSIGNSEL_WI(864,10,((IData)(0x2cU) 
                                        + (0x3ffU & 
                                           ((IData)(0x36U) 
                                            * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index)))), vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____Vlvbound_hfc7452ca__0);
            }
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____Vlvbound_hfc512a83__0 
                = (0x3ffU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_ff 
                             >> 0xcU));
            if ((0x35fU >= ((IData)(0x22U) + (0x3ffU 
                                              & ((IData)(0x36U) 
                                                 * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index)))))) {
                VL_ASSIGNSEL_WI(864,10,((IData)(0x22U) 
                                        + (0x3ffU & 
                                           ((IData)(0x36U) 
                                            * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index)))), vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____Vlvbound_hfc512a83__0);
            }
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____Vlvbound_h22bca24b__0 = 1U;
            if ((0x35fU >= ((IData)(0x21U) + (0x3ffU 
                                              & ((IData)(0x36U) 
                                                 * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index)))))) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[(
                                                                                ((IData)(0x21U) 
                                                                                + 
                                                                                (0x3ffU 
                                                                                & ((IData)(0x36U) 
                                                                                * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index)))) 
                                                                                >> 5U)] 
                    = (((~ ((IData)(1U) << (0x1fU & 
                                            ((IData)(0x21U) 
                                             + (0x3ffU 
                                                & ((IData)(0x36U) 
                                                   * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index))))))) 
                        & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[
                        (((IData)(0x21U) + (0x3ffU 
                                            & ((IData)(0x36U) 
                                               * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index)))) 
                         >> 5U)]) | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____Vlvbound_h22bca24b__0) 
                                     << (0x1fU & ((IData)(0x21U) 
                                                  + 
                                                  (0x3ffU 
                                                   & ((IData)(0x36U) 
                                                      * (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__w_index)))))));
            }
        }
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__ms_mode_ecall_req 
        = ((9U == (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_code)) 
           | (0xbU == (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_code)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_exc_req 
        = (((3U == (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_code)) 
            | ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__pf_exc_req) 
               | (8U == (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_code)))) 
           & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_delegated_req));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_req 
        = (1U & (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                  >> 2U) | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_exc_req) 
                            | (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__pf_exc_req))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_scause_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_exc_req)
            ? (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_code)
            : ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_irq_req)
                ? (0x80000000U | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_code))
                : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_scause_ff));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stval_next 
        = (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_exc_req) 
            & (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__pf_exc_req))
            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[0U]
            : ((((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_exc_req) 
                 & ((8U == (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_code)) 
                    | (3U == (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_code)))) 
                | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_irq_req))
                ? 0U : ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stval_wr_flag)
                         ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata
                         : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stval_ff)));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_new_pc 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sret_pc_req)
            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sepc_ff
            : ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_ff)
                ? ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_exc_req)
                    ? (0xfffffffcU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_ff)
                    : ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_irq_req)
                        ? ((0xffffffc0U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_ff) 
                           | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_code) 
                              << 2U)) : (0xfffffffcU 
                                         & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_ff)))
                : (0xfffffffcU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_ff)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_delegated_req 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_req) 
           & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_medeleg_ff 
              >> (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_code)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_exc_req 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_req) 
           & ((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_delegated_req)) 
              & (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__ms_mode_ecall_req)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtval_next 
        = (((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_delegated_req)) 
            & (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__pf_exc_req))
            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[0U]
            : (((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__ms_mode_ecall_req) 
                | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_irq_req))
                ? 0U : ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtval_wr_flag)
                         ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata
                         : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtval_ff)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcause_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_exc_req)
            ? (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_code)
            : ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_irq_req)
                ? (0x80000000U | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_code))
                : ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcause_wr_flag)
                    ? (0x8000000fU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata)
                    : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcause_ff)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff;
    if (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_exc_req) 
         | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_irq_req))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next 
            = (0xfffffffdU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next 
            = ((0xffffffdfU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next) 
               | (0x20U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff 
                           << 4U)));
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next 
            = ((0xfffffeffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next) 
               | (0x100U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff) 
                            << 8U)));
    } else if (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_exc_req) 
                | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_irq_req))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next 
            = (0xfffffff7U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next 
            = ((0xffffff7fU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next) 
               | (0x80U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff 
                           << 4U)));
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next 
            = ((0xffffe7ffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next) 
               | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff) 
                  << 0xbU));
    } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sret_req) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next 
            = ((0xfffffffdU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next) 
               | (2U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff 
                        >> 4U)));
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next 
            = (0x20U | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next 
            = (0xfffffeffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next);
    } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mret_req) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next 
            = ((0xfffffff7U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next) 
               | (8U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff 
                        >> 4U)));
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next 
            = (0x80U | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next 
            = (0xffffe7ffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next);
    } else {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next 
            = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_wr_flag)
                ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata
                : ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sstatus_wr_flag)
                    ? ((0xfff39eddU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff) 
                       | (0xc6122U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata))
                    : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff));
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_pc_next 
        = ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
            << 0x1bU) | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[2U] 
                         >> 5U));
    if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mret_pc_req) {
        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_new_pc 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mepc_ff;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_pc_next 
            = core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_new_pc;
    } else {
        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_new_pc 
            = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_ff)
                ? ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_exc_req)
                    ? (0xfffffffcU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_ff)
                    : ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_irq_req)
                        ? ((0xffffffc0U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_ff) 
                           | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_code) 
                              << 2U)) : (0xfffffffcU 
                                         & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_ff)))
                : (0xfffffffcU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_ff));
        if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sret_pc_req) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_pc_next 
                = core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_new_pc;
        } else if ((1U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[0U] 
                          | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu_mul_stall_ff)))) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_pc_next 
                = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_pc_ff;
        } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_req) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_pc_next 
                = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[1U];
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mepc_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_irq_req)
            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_pc_next
            : ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_exc_req)
                ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_pc_next
                : ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mepc_wr_flag)
                    ? (0xfffffffcU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata)
                    : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mepc_ff)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sepc_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_irq_req)
            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_pc_next
            : ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_exc_req)
                ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_pc_next
                : ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sepc_wr_flag)
                    ? (0xfffffffcU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata)
                    : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sepc_ff)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__csr2if_fb 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_pc_req)
            ? core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_new_pc
            : ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_pc_req)
                ? core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_new_pc
                : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_pc_next));
}

extern const VlUnpacked<CData/*0:0*/, 64> Vcore_tb__ConstPool__TABLE_h70294115_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vcore_tb__ConstPool__TABLE_h89f87c1c_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vcore_tb__ConstPool__TABLE_h7c6c7419_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vcore_tb__ConstPool__TABLE_h512e92e8_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vcore_tb__ConstPool__TABLE_h50d6939b_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vcore_tb__ConstPool__TABLE_h0c0271a0_0;

VL_INLINE_OPT void Vcore_tb___024root___act_comb__TOP__4(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___act_comb__TOP__4\n"); );
    // Init
    CData/*3:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__fwd2if;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__fwd2if = 0;
    IData/*31:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_word;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_word = 0;
    SData/*15:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_hword;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_hword = 0;
    CData/*7:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_byte;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_byte = 0;
    IData/*31:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__a_slt_b;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__a_slt_b = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__a_uslt_b;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__a_uslt_b = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT____VdfgTmp_h005662fe__0;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT____VdfgTmp_h005662fe__0 = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_inc;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_inc = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_inc;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_inc = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__is_not_ebreak;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__is_not_ebreak = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__is_not_ecall;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__is_not_ecall = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_use_hazard;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_use_hazard = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__if_id_exe_stall;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__if_id_exe_stall = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__id_exe_flush;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__id_exe_flush = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__exe_new_pc_req;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__exe_new_pc_req = 0;
    QData/*33:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb2mmu;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb2mmu = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__itlb_miss;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__itlb_miss = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus_req;
    core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus_req = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__uart_sel;
    core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__uart_sel = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__clint_sel;
    core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__clint_sel = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__plic_sel;
    core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__plic_sel = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__bmem_sel;
    core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__bmem_sel = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__uart_ns_sel;
    core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__uart_ns_sel = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__uart_module__DOT__rx_empty;
    core_tb__DOT__dut__DOT__uart_module__DOT__rx_empty = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__uart_module__DOT__tx_reg_wr_flag;
    core_tb__DOT__dut__DOT__uart_module__DOT__tx_reg_wr_flag = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__uart_module__DOT__baud_reg_wr_flag;
    core_tb__DOT__dut__DOT__uart_module__DOT__baud_reg_wr_flag = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__uart_module__DOT__txctrl_reg_wr_flag;
    core_tb__DOT__dut__DOT__uart_module__DOT__txctrl_reg_wr_flag = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__uart_module__DOT__rxctrl_reg_wr_flag;
    core_tb__DOT__dut__DOT__uart_module__DOT__rxctrl_reg_wr_flag = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__uart_module__DOT__int_mask_reg_wr_flag;
    core_tb__DOT__dut__DOT__uart_module__DOT__int_mask_reg_wr_flag = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__uart_module__DOT____VdfgTmp_ha680e920__0;
    core_tb__DOT__dut__DOT__uart_module__DOT____VdfgTmp_ha680e920__0 = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__uart_ns_module__DOT__tx_reg_wr_flag;
    core_tb__DOT__dut__DOT__uart_ns_module__DOT__tx_reg_wr_flag = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__uart_ns_module__DOT__ie_reg_wr_flag;
    core_tb__DOT__dut__DOT__uart_ns_module__DOT__ie_reg_wr_flag = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__uart_ns_module__DOT__lctrl_reg_wr_flag;
    core_tb__DOT__dut__DOT__uart_ns_module__DOT__lctrl_reg_wr_flag = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__uart_ns_module__DOT__scratch_reg_wr_flag;
    core_tb__DOT__dut__DOT__uart_ns_module__DOT__scratch_reg_wr_flag = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__uart_ns_module__DOT____VdfgTmp_h1ea301df__0;
    core_tb__DOT__dut__DOT__uart_ns_module__DOT____VdfgTmp_h1ea301df__0 = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__clint_module__DOT__mtime_lo_wr_flag;
    core_tb__DOT__dut__DOT__clint_module__DOT__mtime_lo_wr_flag = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__clint_module__DOT__mtime_hi_wr_flag;
    core_tb__DOT__dut__DOT__clint_module__DOT__mtime_hi_wr_flag = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_lo_wr_flag;
    core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_lo_wr_flag = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_hi_wr_flag;
    core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_hi_wr_flag = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__clint_module__DOT____VdfgTmp_h7b251b97__0;
    core_tb__DOT__dut__DOT__clint_module__DOT____VdfgTmp_h7b251b97__0 = 0;
    CData/*7:0*/ core_tb__DOT__dut__DOT__plic_module__DOT__regs2gateway;
    core_tb__DOT__dut__DOT__plic_module__DOT__regs2gateway = 0;
    CData/*1:0*/ core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_set_pending;
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_set_pending = 0;
    CData/*1:0*/ core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_set_active;
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_set_active = 0;
    CData/*1:0*/ core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__claim;
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__claim = 0;
    CData/*1:0*/ core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__complete;
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__complete = 0;
    CData/*1:0*/ core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__claim_req;
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__claim_req = 0;
    CData/*1:0*/ core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_req;
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_req = 0;
    CData/*3:0*/ core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_idx;
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_idx = 0;
    CData/*1:0*/ core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_th_reg_wr_flag;
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_th_reg_wr_flag = 0;
    CData/*1:0*/ core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_reg_wr_flag;
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_reg_wr_flag = 0;
    CData/*1:0*/ core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__ie_reg_wr_flag;
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__ie_reg_wr_flag = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____VdfgTmp_hf58aaa35__0;
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____VdfgTmp_hf58aaa35__0 = 0;
    QData/*32:0*/ core_tb__DOT__dut__DOT__mem_top_module__DOT__dmem2dbus;
    core_tb__DOT__dut__DOT__mem_top_module__DOT__dmem2dbus = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__mem_top_module__DOT____VdfgExtracted_h2d511444__0;
    core_tb__DOT__dut__DOT__mem_top_module__DOT____VdfgExtracted_h2d511444__0 = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem_i_sel;
    core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem_i_sel = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem_d_sel;
    core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem_d_sel = 0;
    QData/*32:0*/ core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT____VdfgExtracted_hf03fca7c__0;
    core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT____VdfgExtracted_hf03fca7c__0 = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__cache_hit;
    core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__cache_hit = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT____Vcellout__ram__read_valid_o;
    core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT____Vcellout__ram__read_valid_o = 0;
    IData/*17:0*/ core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT____Vcellout__ram__read_tag_o;
    core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT____Vcellout__ram__read_tag_o = 0;
    CData/*5:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    // Body
    vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
        = (7U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U]);
    vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
        = (0xffffff80U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U]);
    if ((1U == (3U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                      >> 2U)))) {
        if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U])) {
            if ((0x10U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U])) {
                vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                    = ((0x7fffffffU & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U]) 
                       | (0x80000000U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                                         << 0x1bU)));
                vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                    = ((0xffffff80U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U]) 
                       | (0x7fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                                   >> 5U)));
                vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                    = (0x40U | (0xffffff87U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U]));
            } else {
                vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                    = ((0x807fffffU & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U]) 
                       | (0x7f800000U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                                         << 0x13U)));
                vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                    = (0x20U | (0xffffff87U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U]));
            }
        } else if ((0x10U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U])) {
            vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                = ((0xff807fffU & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U]) 
                   | (0x7f8000U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                                   << 0xbU)));
            vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                = (0x10U | (0xffffff87U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U]));
        } else {
            vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                = ((0xffff8007U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U]) 
                   | (0xfffffff8U & (8U | (0x7f80U 
                                           & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                                              << 3U)))));
        }
    } else if ((2U == (3U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                             >> 2U)))) {
        if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U])) {
            if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U])) {
                vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                    = ((0x7fffffU & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U]) 
                       | (0xff800000U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                                         << 0x13U)));
                vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                    = ((0xffffff80U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U]) 
                       | (0x7fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                                   >> 0xdU)));
                vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                    = (0x60U | (0xffffff87U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U]));
            }
        } else {
            vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                = ((0xff800007U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U]) 
                   | (0xfffffff8U & (0x18U | (0x7fff80U 
                                              & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                                                 << 3U)))));
        }
    } else {
        vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
            = ((7U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U]) 
               | ((IData)(((3U == (3U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                                         >> 2U))) ? 
                           (0xfULL | ((QData)((IData)(
                                                      ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U] 
                                                        << 0x1cU) 
                                                       | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                                                          >> 4U)))) 
                                      << 4U)) : 0ULL)) 
                  << 3U));
        vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
            = ((0xffffff80U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U]) 
               | (((IData)(((3U == (3U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                                          >> 2U))) ? 
                            (0xfULL | ((QData)((IData)(
                                                       ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U] 
                                                         << 0x1cU) 
                                                        | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                                                           >> 4U)))) 
                                       << 4U)) : 0ULL)) 
                   >> 0x1dU) | ((IData)((((3U == (3U 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                                                     >> 2U)))
                                           ? (0xfULL 
                                              | ((QData)((IData)(
                                                                 ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U] 
                                                                   << 0x1cU) 
                                                                  | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                                                                     >> 4U)))) 
                                                 << 4U))
                                           : 0ULL) 
                                         >> 0x20U)) 
                                << 3U)));
    }
    vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
        = ((0x7fU & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U]) 
           | (0xffffff80U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U] 
                             << 3U)));
    vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[2U] 
        = (0x7fU & ((0x78U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[2U] 
                              << 3U)) | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U] 
                                         >> 0x1dU)));
    core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus_req 
        = (IData)((0U != (3U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U])));
    __Vtableidx3 = ((((1U == (0xffffU & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[2U] 
                                          << 0xcU) 
                                         | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U] 
                                            >> 0x14U)))) 
                      & (IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus_req)) 
                     << 5U) | ((((0x98U == (0xffU & 
                                            ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[2U] 
                                              << 4U) 
                                             | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U] 
                                                >> 0x1cU)))) 
                                 & (IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus_req)) 
                                << 4U) | ((((0x90U 
                                             == (0xffU 
                                                 & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[2U] 
                                                     << 4U) 
                                                    | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U] 
                                                       >> 0x1cU)))) 
                                            & (IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus_req)) 
                                           << 3U) | 
                                          ((((0x94U 
                                              == (0xffU 
                                                  & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[2U] 
                                                      << 4U) 
                                                     | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U] 
                                                        >> 0x1cU)))) 
                                             & (IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus_req)) 
                                            << 2U) 
                                           | ((((2U 
                                                 == 
                                                 (0xffU 
                                                  & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[2U] 
                                                      << 4U) 
                                                     | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U] 
                                                        >> 0x1cU)))) 
                                                & (IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus_req)) 
                                               << 1U) 
                                              | (IData)(
                                                        ((8U 
                                                          == 
                                                          vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[2U]) 
                                                         & (IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus_req))))))));
    vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dmem_sel 
        = Vcore_tb__ConstPool__TABLE_h70294115_0[__Vtableidx3];
    core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__clint_sel 
        = Vcore_tb__ConstPool__TABLE_h89f87c1c_0[__Vtableidx3];
    core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__plic_sel 
        = Vcore_tb__ConstPool__TABLE_h7c6c7419_0[__Vtableidx3];
    core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__uart_sel 
        = Vcore_tb__ConstPool__TABLE_h512e92e8_0[__Vtableidx3];
    core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__bmem_sel 
        = Vcore_tb__ConstPool__TABLE_h50d6939b_0[__Vtableidx3];
    core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__uart_ns_sel 
        = Vcore_tb__ConstPool__TABLE_h0c0271a0_0[__Vtableidx3];
    core_tb__DOT__dut__DOT__mem_top_module__DOT____VdfgExtracted_h2d511444__0 
        = ((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dmem_sel)) 
           & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_req_ff));
    vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
        = ((0xfffffff8U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U]) 
           | ((4U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[0U] 
                     << 2U)) | ((((IData)(vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dmem_sel) 
                                  | ((IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__uart_sel) 
                                     | ((IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__clint_sel) 
                                        | ((IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__plic_sel) 
                                           | ((IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__bmem_sel) 
                                              | (IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__uart_ns_sel)))))) 
                                 << 1U) | (IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus_req))));
    core_tb__DOT__dut__DOT__mem_top_module__DOT__dmem2dbus = 0ULL;
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dmem2mmu = 0ULL;
    if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dmem_sel)))) {
        if (core_tb__DOT__dut__DOT__mem_top_module__DOT____VdfgExtracted_h2d511444__0) {
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dmem2mmu 
                = vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem2dbus_ff;
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__lsummu2dmem[0U] = 0U;
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__lsummu2dmem[1U] = 0U;
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__lsummu2dmem[2U] = 0U;
    if (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dmem_sel) {
        core_tb__DOT__dut__DOT__mem_top_module__DOT__dmem2dbus 
            = vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem2dbus_ff;
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__lsummu2dmem[0U] 
            = vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U];
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__lsummu2dmem[1U] 
            = vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U];
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__lsummu2dmem[2U] 
            = vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[2U];
        vlSelf->core_tb__DOT__dut__DOT__dbus2lsu = core_tb__DOT__dut__DOT__mem_top_module__DOT__dmem2dbus;
    } else {
        if (core_tb__DOT__dut__DOT__mem_top_module__DOT____VdfgExtracted_h2d511444__0) {
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__lsummu2dmem[0U] = 3U;
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__lsummu2dmem[1U] 
                = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_paddr_ff) 
                   << 7U);
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__lsummu2dmem[2U] 
                = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_paddr_ff) 
                   >> 0x19U);
        }
        vlSelf->core_tb__DOT__dut__DOT__dbus2lsu = 
            ((IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__clint_sel)
              ? vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__clint2dbus_ff
              : ((IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__plic_sel)
                  ? vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic2dbus_ff
                  : ((IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__uart_sel)
                      ? vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart2dbus_ff
                      : ((IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__uart_ns_sel)
                          ? vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart2dbus_ff
                          : ((IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__bmem_sel)
                              ? vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2dbus_ff
                              : 0ULL)))));
    }
    core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem_d_sel 
        = (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
           & (IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__bmem_sel));
    core_tb__DOT__dut__DOT__clint_module__DOT____VdfgTmp_h7b251b97__0 
        = (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
           & (IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__clint_sel));
    core_tb__DOT__dut__DOT__uart_ns_module__DOT____VdfgTmp_h1ea301df__0 
        = (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
           & (IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__uart_ns_sel));
    core_tb__DOT__dut__DOT__uart_module__DOT____VdfgTmp_ha680e920__0 
        = (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
           & (IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__uart_sel));
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____VdfgTmp_hf58aaa35__0 
        = (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
           & (IData)(core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__plic_sel));
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__r_req 
        = ((~ (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
               >> 2U)) & (IData)(core_tb__DOT__dut__DOT__clint_module__DOT____VdfgTmp_h7b251b97__0));
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__w_req 
        = ((vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
            >> 2U) & (IData)(core_tb__DOT__dut__DOT__clint_module__DOT____VdfgTmp_h7b251b97__0));
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__reg_rd_req 
        = ((~ (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
               >> 2U)) & (IData)(core_tb__DOT__dut__DOT__uart_ns_module__DOT____VdfgTmp_h1ea301df__0));
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__reg_wr_req 
        = ((vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
            >> 2U) & (IData)(core_tb__DOT__dut__DOT__uart_ns_module__DOT____VdfgTmp_h1ea301df__0));
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__reg_rd_req 
        = ((~ (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
               >> 2U)) & (IData)(core_tb__DOT__dut__DOT__uart_module__DOT____VdfgTmp_ha680e920__0));
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__reg_wr_req 
        = ((vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
            >> 2U) & (IData)(core_tb__DOT__dut__DOT__uart_module__DOT____VdfgTmp_ha680e920__0));
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_rd_req 
        = ((~ (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
               >> 2U)) & (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____VdfgTmp_hf58aaa35__0));
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_wr_req 
        = ((vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
            >> 2U) & (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____VdfgTmp_hf58aaa35__0));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_save = 0U;
    if ((1U & (~ ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))) {
                if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__dbus2lsu))) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_save 
                        = (1U == (0xfU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                          >> 3U)));
                }
            }
        }
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_word = 0U;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_hword = 0U;
    if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)) {
        if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                      >> 0xaU)))) {
            if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)) {
                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_word 
                    = (IData)((vlSelf->core_tb__DOT__dut__DOT__dbus2lsu 
                               >> 1U));
            }
            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                          >> 9U)))) {
                if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U])) {
                    if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_hword 
                            = (0xffffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__dbus2lsu 
                                                  >> 0x11U)));
                    }
                } else {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_hword 
                        = (0xffffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__dbus2lsu 
                                              >> 1U)));
                }
            }
        }
    } else if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)) {
        if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)) {
            if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U])) {
                if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_hword 
                        = (0xffffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__dbus2lsu 
                                              >> 0x11U)));
                }
            } else {
                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_hword 
                    = (0xffffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__dbus2lsu 
                                          >> 1U)));
            }
        }
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_byte = 0U;
    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                  >> 0xbU)))) {
        if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)) {
            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                          >> 9U)))) {
                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_byte 
                    = (0xffU & ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U])
                                 ? ((0x10U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U])
                                     ? (IData)((vlSelf->core_tb__DOT__dut__DOT__dbus2lsu 
                                                >> 0x19U))
                                     : (IData)((vlSelf->core_tb__DOT__dut__DOT__dbus2lsu 
                                                >> 0x11U)))
                                 : ((0x10U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U])
                                     ? (IData)((vlSelf->core_tb__DOT__dut__DOT__dbus2lsu 
                                                >> 9U))
                                     : (IData)((vlSelf->core_tb__DOT__dut__DOT__dbus2lsu 
                                                >> 1U)))));
            }
        } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)) {
            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_byte 
                = (0xffU & ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U])
                             ? ((0x10U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U])
                                 ? (IData)((vlSelf->core_tb__DOT__dut__DOT__dbus2lsu 
                                            >> 0x19U))
                                 : (IData)((vlSelf->core_tb__DOT__dut__DOT__dbus2lsu 
                                            >> 0x11U)))
                             : ((0x10U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus[1U])
                                 ? (IData)((vlSelf->core_tb__DOT__dut__DOT__dbus2lsu 
                                            >> 9U))
                                 : (IData)((vlSelf->core_tb__DOT__dut__DOT__dbus2lsu 
                                            >> 1U)))));
        }
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a 
        = (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__ld_req) 
            & (IData)(vlSelf->core_tb__DOT__dut__DOT__dbus2lsu))
            ? (IData)((vlSelf->core_tb__DOT__dut__DOT__dbus2lsu 
                       >> 1U)) : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a_ff);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_stall_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_stall_ff;
    if ((1U & ((0U != (0xfU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                               >> 3U))) ? (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_done)
                : (IData)(vlSelf->core_tb__DOT__dut__DOT__dbus2lsu)))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_stall_next = 0U;
    } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgExtracted_h09503d11__0) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_stall_next = 1U;
    }
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__r_data = 0U;
    if (vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__r_req) {
        vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__r_data 
            = ((0xbff8U == (0xffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                       >> 7U))) ? (IData)(vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtime_ff)
                : ((0xbffcU == (0xffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                           >> 7U)))
                    ? (IData)((vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtime_ff 
                               >> 0x20U)) : ((0x4000U 
                                              == (0xffffU 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                     >> 7U)))
                                              ? (IData)(vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_ff)
                                              : ((0x4004U 
                                                  == 
                                                  (0xffffU 
                                                   & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                      >> 7U)))
                                                  ? (IData)(
                                                            (vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_ff 
                                                             >> 0x20U))
                                                  : 0U))));
    }
    core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_hi_wr_flag = 0U;
    core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_lo_wr_flag = 0U;
    core_tb__DOT__dut__DOT__clint_module__DOT__mtime_lo_wr_flag = 0U;
    core_tb__DOT__dut__DOT__clint_module__DOT__mtime_hi_wr_flag = 0U;
    if (((IData)(vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__w_req) 
         & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__clint2dbus_ff)))) {
        if ((0xbff8U != (0xffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                    >> 7U)))) {
            if ((0xbffcU != (0xffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                        >> 7U)))) {
                if ((0x4000U != (0xffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                            >> 7U)))) {
                    if ((0x4004U == (0xffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                >> 7U)))) {
                        core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_hi_wr_flag = 1U;
                    }
                }
                if ((0x4000U == (0xffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                            >> 7U)))) {
                    core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_lo_wr_flag = 1U;
                }
            }
            if ((0xbffcU == (0xffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                        >> 7U)))) {
                core_tb__DOT__dut__DOT__clint_module__DOT__mtime_hi_wr_flag = 1U;
            }
        }
        if ((0xbff8U == (0xffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                    >> 7U)))) {
            core_tb__DOT__dut__DOT__clint_module__DOT__mtime_lo_wr_flag = 1U;
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__reg_r_data = 0U;
    if (vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__reg_rd_req) {
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__reg_r_data 
            = ((0x800U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])
                ? ((0x400U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])
                    ? ((0x200U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])
                        ? (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_scratch_ff)
                        : 0U) : ((0x200U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])
                                  ? (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lstatus_ff)
                                  : 0U)) : ((0x400U 
                                             & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])
                                             ? ((0x200U 
                                                 & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])
                                                 ? (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lctrl_ff)
                                                 : 0U)
                                             : ((0x200U 
                                                 & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])
                                                 ? (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_ie_ff)
                                                 : (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_rx_ff))));
    }
    core_tb__DOT__dut__DOT__uart_ns_module__DOT__scratch_reg_wr_flag = 0U;
    core_tb__DOT__dut__DOT__uart_ns_module__DOT__ie_reg_wr_flag = 0U;
    core_tb__DOT__dut__DOT__uart_ns_module__DOT__lctrl_reg_wr_flag = 0U;
    core_tb__DOT__dut__DOT__uart_ns_module__DOT__tx_reg_wr_flag = 0U;
    if (((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__reg_wr_req) 
         & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart2dbus_ff)))) {
        if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])) {
            if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])) {
                if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])) {
                    core_tb__DOT__dut__DOT__uart_ns_module__DOT__scratch_reg_wr_flag = 1U;
                }
            }
        }
        if ((1U & (~ (1U & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                            >> 0xbU))))) {
            if ((1U & (~ (3U & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                >> 0xaU))))) {
                if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])) {
                    core_tb__DOT__dut__DOT__uart_ns_module__DOT__ie_reg_wr_flag = 1U;
                }
                if ((1U & (~ (7U & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                    >> 9U))))) {
                    core_tb__DOT__dut__DOT__uart_ns_module__DOT__tx_reg_wr_flag = 1U;
                }
            }
            if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])) {
                if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])) {
                    core_tb__DOT__dut__DOT__uart_ns_module__DOT__lctrl_reg_wr_flag = 1U;
                }
            }
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__reg_r_data = 0U;
    core_tb__DOT__dut__DOT__uart_module__DOT__rx_empty = 0U;
    if (vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__reg_rd_req) {
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__reg_r_data 
            = ((0x1000U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])
                ? 0U : ((0x800U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])
                         ? ((0x400U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])
                             ? ((0x200U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])
                                 ? 0U : (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_baud_ff))
                             : ((0x200U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])
                                 ? (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_status_ff)
                                 : (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_int_mask_ff)))
                         : ((0x400U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])
                             ? ((0x200U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])
                                 ? vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rxctrl_ff
                                 : vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_txctrl_ff)
                             : ((0x200U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])
                                 ? (((~ ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_status_ff) 
                                         >> 1U)) << 0x1fU) 
                                    | (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rx_ff))
                                 : ((0U != (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_ff)) 
                                    << 0x1fU)))));
        if ((1U & (~ (1U & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                            >> 0xcU))))) {
            if ((1U & (~ (3U & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                >> 0xbU))))) {
                if ((1U & (~ (7U & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                    >> 0xaU))))) {
                    if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])) {
                        core_tb__DOT__dut__DOT__uart_module__DOT__rx_empty = 1U;
                    }
                }
            }
        }
    }
    core_tb__DOT__dut__DOT__uart_module__DOT__int_mask_reg_wr_flag = 0U;
    core_tb__DOT__dut__DOT__uart_module__DOT__baud_reg_wr_flag = 0U;
    core_tb__DOT__dut__DOT__uart_module__DOT__txctrl_reg_wr_flag = 0U;
    core_tb__DOT__dut__DOT__uart_module__DOT__rxctrl_reg_wr_flag = 0U;
    core_tb__DOT__dut__DOT__uart_module__DOT__tx_reg_wr_flag = 0U;
    if (((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__reg_wr_req) 
         & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart2dbus_ff)))) {
        if ((1U & (~ (1U & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                            >> 0xcU))))) {
            if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])) {
                if ((1U & (~ (7U & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                    >> 0xaU))))) {
                    if ((1U & (~ (0xfU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                          >> 9U))))) {
                        core_tb__DOT__dut__DOT__uart_module__DOT__int_mask_reg_wr_flag = 1U;
                    }
                }
                if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])) {
                    if ((1U & (~ (0xfU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                          >> 9U))))) {
                        core_tb__DOT__dut__DOT__uart_module__DOT__baud_reg_wr_flag = 1U;
                    }
                }
            }
            if ((1U & (~ (3U & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                >> 0xbU))))) {
                if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])) {
                    if ((1U & (~ (0xfU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                          >> 9U))))) {
                        core_tb__DOT__dut__DOT__uart_module__DOT__txctrl_reg_wr_flag = 1U;
                    }
                    if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U])) {
                        core_tb__DOT__dut__DOT__uart_module__DOT__rxctrl_reg_wr_flag = 1U;
                    }
                }
                if ((1U & (~ (7U & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                    >> 0xaU))))) {
                    if ((1U & (~ (0xfU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                          >> 9U))))) {
                        core_tb__DOT__dut__DOT__uart_module__DOT__tx_reg_wr_flag = 1U;
                    }
                }
            }
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_r_data = 0U;
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__claim_req = 0U;
    if (vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_rd_req) {
        if (((((((((0U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                        >> 7U))) | 
                   (4U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                        >> 7U)))) | 
                  (8U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                       >> 7U)))) | 
                 (0x1000U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                           >> 7U)))) 
                | (0x2000U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                            >> 7U)))) 
               | (0x2080U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                           >> 7U)))) 
              | (0x200000U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                            >> 7U)))) 
             | (0x201000U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                           >> 7U))))) {
            vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_r_data 
                = ((0xfffffff8U & vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_r_data) 
                   | ((0U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                           >> 7U)))
                       ? 0U : (7U & ((4U == (0xffffffU 
                                             & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                >> 7U)))
                                      ? (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_ff)
                                      : ((8U == (0xffffffU 
                                                 & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                    >> 7U)))
                                          ? ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_ff) 
                                             >> 3U)
                                          : ((0x1000U 
                                              == (0xffffffU 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                     >> 7U)))
                                              ? ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_pending_ff) 
                                                 << 1U)
                                              : ((0x2000U 
                                                  == 
                                                  (0xffffffU 
                                                   & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                      >> 7U)))
                                                  ? 
                                                 (6U 
                                                  & ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_ie_ff) 
                                                     << 1U))
                                                  : 
                                                 ((0x2080U 
                                                   == 
                                                   (0xffffffU 
                                                    & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                       >> 7U)))
                                                   ? 
                                                  (6U 
                                                   & ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_ie_ff) 
                                                      >> 1U))
                                                   : 
                                                  ((0x200000U 
                                                    == 
                                                    (0xffffffU 
                                                     & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                        >> 7U)))
                                                    ? (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_ff)
                                                    : 
                                                   ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_ff) 
                                                    >> 3U))))))))));
        } else if ((0x200004U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                               >> 7U)))) {
            vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_r_data 
                = ((0xfffffffcU & vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_r_data) 
                   | (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_idx_ff));
        } else if ((0x201004U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                               >> 7U)))) {
            vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_r_data 
                = ((0xfffffffcU & vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_r_data) 
                   | (3U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT____Vcellinp__plic_regs_module__claim_idx_i) 
                            >> 2U)));
        }
        if ((1U & (~ ((((((((0U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                 >> 7U))) 
                            | (4U == (0xffffffU & (
                                                   vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                   >> 7U)))) 
                           | (8U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                  >> 7U)))) 
                          | (0x1000U == (0xffffffU 
                                         & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                            >> 7U)))) 
                         | (0x2000U == (0xffffffU & 
                                        (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                         >> 7U)))) 
                        | (0x2080U == (0xffffffU & 
                                       (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                        >> 7U)))) | 
                       (0x200000U == (0xffffffU & (
                                                   vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                   >> 7U)))) 
                      | (0x201000U == (0xffffffU & 
                                       (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                        >> 7U))))))) {
            if ((0x200004U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                            >> 7U)))) {
                core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__claim_req 
                    = (1U | (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__claim_req));
            } else if ((0x201004U == (0xffffffU & (
                                                   vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                   >> 7U)))) {
                core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__claim_req 
                    = (2U | (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__claim_req));
            }
        }
    }
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__ie_reg_wr_flag = 0U;
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_reg_wr_flag = 0U;
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_th_reg_wr_flag = 0U;
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_req = 0U;
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_idx = 0U;
    if (((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_wr_req) 
         & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic2dbus_ff)))) {
        if (((((((((0U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                        >> 7U))) | 
                   (4U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                        >> 7U)))) | 
                  (8U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                       >> 7U)))) | 
                 (0x2000U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                           >> 7U)))) 
                | (0x2080U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                            >> 7U)))) 
               | (0x200000U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                             >> 7U)))) 
              | (0x201000U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                            >> 7U)))) 
             | (0x200004U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                           >> 7U))))) {
            if ((0U != (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                     >> 7U)))) {
                if ((4U != (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                         >> 7U)))) {
                    if ((8U != (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                             >> 7U)))) {
                        if ((0x2000U == (0xffffffU 
                                         & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                            >> 7U)))) {
                            core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__ie_reg_wr_flag 
                                = (1U | (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__ie_reg_wr_flag));
                        } else if ((0x2080U == (0xffffffU 
                                                & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                   >> 7U)))) {
                            core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__ie_reg_wr_flag 
                                = (2U | (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__ie_reg_wr_flag));
                        }
                        if ((0x2000U != (0xffffffU 
                                         & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                            >> 7U)))) {
                            if ((0x2080U != (0xffffffU 
                                             & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                >> 7U)))) {
                                if ((0x200000U == (0xffffffU 
                                                   & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                      >> 7U)))) {
                                    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_th_reg_wr_flag 
                                        = (1U | (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_th_reg_wr_flag));
                                } else if ((0x201000U 
                                            == (0xffffffU 
                                                & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                   >> 7U)))) {
                                    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_th_reg_wr_flag 
                                        = (2U | (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_th_reg_wr_flag));
                                }
                                if ((0x200000U != (0xffffffU 
                                                   & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                      >> 7U)))) {
                                    if ((0x201000U 
                                         != (0xffffffU 
                                             & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                >> 7U)))) {
                                        core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_req 
                                            = (1U | (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_req));
                                        core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_idx 
                                            = ((0xcU 
                                                & (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_idx)) 
                                               | (3U 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                                                     >> 7U)));
                                    }
                                }
                            }
                        }
                    }
                }
                if ((4U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                         >> 7U)))) {
                    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_reg_wr_flag 
                        = (1U | (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_reg_wr_flag));
                } else if ((8U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                >> 7U)))) {
                    core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_reg_wr_flag 
                        = (2U | (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_reg_wr_flag));
                }
            }
        } else if ((0x201004U == (0xffffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                               >> 7U)))) {
            core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_req 
                = (2U | (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_req));
            core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_idx 
                = ((3U & (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_idx)) 
                   | (0xcU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                              >> 5U)));
        }
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__a_slt_b 
        = VL_LTS_III(32, core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a, 
                     vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U]);
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__a_uslt_b 
        = (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a 
           < vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U]);
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT____VdfgTmp_h005662fe__0 
        = (1U & (~ (IData)(((0x10U == (0x78U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)) 
                            & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_buffer_addr_ff 
                                == vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U]) 
                               & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_buffer_data_ff 
                                  == core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a))))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu_mul_stall 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_stall_next) 
           | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__mul_stall_next));
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_next 
        = vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_ff;
    if (core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_lo_wr_flag) {
        vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_next 
            = ((0xffffffff00000000ULL & vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_next) 
               | (IData)((IData)(((vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                   << 0x19U) | (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                                                >> 7U)))));
    } else if (core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_hi_wr_flag) {
        vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_next 
            = ((0xffffffffULL & vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_next) 
               | ((QData)((IData)(((vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                    << 0x19U) | (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                                                 >> 7U)))) 
                  << 0x20U));
    }
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtime_next 
        = ((IData)(core_tb__DOT__dut__DOT__clint_module__DOT__mtime_lo_wr_flag)
            ? ((0xffffffff00000000ULL & vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtime_next) 
               | (IData)((IData)(((vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                   << 0x19U) | (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                                                >> 7U)))))
            : ((IData)(core_tb__DOT__dut__DOT__clint_module__DOT__mtime_hi_wr_flag)
                ? ((0xffffffffULL & vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtime_next) 
                   | ((QData)((IData)(((vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                        << 0x19U) | 
                                       (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                                        >> 7U)))) << 0x20U))
                : (1ULL + vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtime_ff)));
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_scratch_next 
        = (0xffU & ((IData)(core_tb__DOT__dut__DOT__uart_ns_module__DOT__scratch_reg_wr_flag)
                     ? ((vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                         << 0x19U) | (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                                      >> 7U)) : (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_scratch_ff)));
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_ie_next 
        = (0xffU & ((IData)(core_tb__DOT__dut__DOT__uart_ns_module__DOT__ie_reg_wr_flag)
                     ? ((vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                         << 0x19U) | (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                                      >> 7U)) : (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_ie_ff)));
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lctrl_next 
        = (0xffU & ((IData)(core_tb__DOT__dut__DOT__uart_ns_module__DOT__lctrl_reg_wr_flag)
                     ? ((vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                         << 0x19U) | (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                                      >> 7U)) : (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lctrl_ff)));
    if (core_tb__DOT__dut__DOT__uart_ns_module__DOT__tx_reg_wr_flag) {
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__tx_valid_next = 1U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_tx_next 
            = (0xffU & ((vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                         << 0x19U) | (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                                      >> 7U)));
    } else {
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__tx_valid_next = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_tx_next 
            = (0xffU & (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_tx_ff));
    }
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_status_next 
        = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_status_ff;
    if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__frame_err_ff)))) {
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_status_next 
            = ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__valid_ff)
                ? (2U | (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_status_next))
                : ((IData)(core_tb__DOT__dut__DOT__uart_module__DOT__rx_empty)
                    ? (0xfdU & (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_status_next))
                    : ((0xfeU & (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_status_next)) 
                       | (0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_ff)))));
    }
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_int_mask_next 
        = (0xffU & ((IData)(core_tb__DOT__dut__DOT__uart_module__DOT__int_mask_reg_wr_flag)
                     ? ((vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                         << 0x19U) | (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                                      >> 7U)) : (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_int_mask_ff)));
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_baud_next 
        = (0xfU & ((IData)(core_tb__DOT__dut__DOT__uart_module__DOT__baud_reg_wr_flag)
                    ? ((vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                        << 0x19U) | (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                                     >> 7U)) : (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_baud_ff)));
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_txctrl_next 
        = ((IData)(core_tb__DOT__dut__DOT__uart_module__DOT__txctrl_reg_wr_flag)
            ? (0xffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                          >> 7U)) : vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_txctrl_ff);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rxctrl_next 
        = ((IData)(core_tb__DOT__dut__DOT__uart_module__DOT__rxctrl_reg_wr_flag)
            ? (0xffffU & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                          >> 7U)) : vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rxctrl_ff);
    if (core_tb__DOT__dut__DOT__uart_module__DOT__tx_reg_wr_flag) {
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__tx_valid_next = 1U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_tx_next 
            = (0xffU & ((vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                         << 0x19U) | (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                                      >> 7U)));
    } else {
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__tx_valid_next = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_tx_next 
            = (0xffU & (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_tx_ff));
    }
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_ie_next 
        = ((0xcU & (((2U & (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__ie_reg_wr_flag))
                      ? ((vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                          << 0x18U) | (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                                       >> 8U)) : ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_ie_ff) 
                                                  >> 2U)) 
                    << 2U)) | (3U & ((1U & (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__ie_reg_wr_flag))
                                      ? ((vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                                          << 0x18U) 
                                         | (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                                            >> 8U))
                                      : (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_ie_ff))));
    if ((1U & (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_reg_wr_flag))) {
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_h06702582__0 
            = (7U & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                     >> 7U));
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_next 
            = ((0x38U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_next)) 
               | (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_h06702582__0));
    } else {
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_h06702582__1 
            = (7U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_ff));
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_next 
            = ((0x38U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_next)) 
               | (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_h06702582__1));
    }
    if ((2U & (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_reg_wr_flag))) {
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_h06702582__0 
            = (7U & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                     >> 7U));
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_next 
            = ((7U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_next)) 
               | ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_h06702582__0) 
                  << 3U));
    } else {
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_h06702582__1 
            = (7U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_ff) 
                     >> 3U));
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_next 
            = ((7U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_next)) 
               | ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_h06702582__1) 
                  << 3U));
    }
    if ((1U & (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_th_reg_wr_flag))) {
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_hbb644852__0 
            = (7U & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                     >> 7U));
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_next 
            = ((0x38U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_next)) 
               | (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_hbb644852__0));
    } else {
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_hbb644852__1 
            = (7U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_ff));
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_next 
            = ((0x38U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_next)) 
               | (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_hbb644852__1));
    }
    if ((2U & (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__prio_th_reg_wr_flag))) {
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_hbb644852__0 
            = (7U & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[0U] 
                     >> 7U));
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_next 
            = ((7U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_next)) 
               | ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_hbb644852__0) 
                  << 3U));
    } else {
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_hbb644852__1 
            = (7U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_ff) 
                     >> 3U));
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_next 
            = ((7U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_next)) 
               | ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_hbb644852__1) 
                  << 3U));
    }
    core_tb__DOT__dut__DOT__plic_module__DOT__regs2gateway 
        = (((IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__claim_req) 
            << 6U) | (((IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_req) 
                       << 4U) | (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_idx)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_result_o 
        = ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
            ? ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U]
                : ((0x10U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                    ? ((8U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                        ? ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__a_uslt_b)
                            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U]
                            : core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a)
                        : ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__a_uslt_b)
                            ? core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a
                            : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U]))
                    : ((8U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                        ? ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__a_slt_b)
                            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U]
                            : core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a)
                        : ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__a_slt_b)
                            ? core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a
                            : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U]))))
            : ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                ? ((0x10U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                    ? ((8U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                        ? (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a 
                           | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U])
                        : (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a 
                           & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U]))
                    : ((8U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                        ? (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a 
                           ^ vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U])
                        : (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a 
                           + vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U])))
                : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U]));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state_next 
        = ((4U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))
            ? 0U : ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))
                     ? ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))
                         ? ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__dbus2lsu))
                             ? 4U : 3U) : (((1U == 
                                             (0xfU 
                                              & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                                 >> 3U))) 
                                            | ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT____VdfgTmp_h005662fe__0) 
                                               & (0x10U 
                                                  == 
                                                  (0x78U 
                                                   & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff))))
                                            ? 4U : 3U))
                     : ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))
                         ? ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__dbus2lsu))
                             ? 2U : 1U) : ((0U != (0xfU 
                                                   & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                                      >> 3U)))
                                            ? 1U : 0U))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[1U] 
        = (0x1fU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[1U]);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[2U] 
        = (0xffffffe0U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[2U]);
    if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_done) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[1U] 
            = ((0x1fU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[1U]) 
               | (((2U == (0xfU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                   >> 3U))) ? (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT____VdfgTmp_h005662fe__0)
                    : core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a) 
                  << 5U));
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[2U] 
            = ((0xffffffe0U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[2U]) 
               | (((2U == (0xfU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                   >> 3U))) ? (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT____VdfgTmp_h005662fe__0)
                    : core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a) 
                  >> 0x1bU));
    } else if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__dbus2lsu))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[1U] 
            = ((0x1fU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[1U]) 
               | (((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                    ? ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                        ? 0U : ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                                 ? core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_word
                                 : (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_hword)))
                    : ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                        ? ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                            ? (((- (IData)((1U & ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_hword) 
                                                  >> 0xfU)))) 
                                << 0x10U) | (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_hword))
                            : (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_byte))
                        : ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                            ? (((- (IData)((1U & ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_byte) 
                                                  >> 7U)))) 
                                << 8U) | (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_byte))
                            : 0U))) << 5U));
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[2U] 
            = ((0xffffffe0U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[2U]) 
               | (((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                    ? ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                        ? 0U : ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                                 ? core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_word
                                 : (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_hword)))
                    : ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                        ? ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                            ? (((- (IData)((1U & ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_hword) 
                                                  >> 0xfU)))) 
                                << 0x10U) | (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_hword))
                            : (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_byte))
                        : ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)
                            ? (((- (IData)((1U & ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_byte) 
                                                  >> 7U)))) 
                                << 8U) | (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__rdata_byte))
                            : 0U))) >> 0x1bU));
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__fwd2csr 
        = (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu_mul_stall_ff) 
            << 1U) | (1U & ((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__icache2if)) 
                            | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu_mul_stall))));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_use_hazard 
        = ((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu_mul_stall)) 
           & (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu2rs1_hazard) 
               & ((IData)((0ULL != (0x8002ULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff))) 
                  & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_csr_mul_read_req))) 
              | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu2rs2_hazard) 
                 & ((IData)((0ULL != (0x30004002ULL 
                                      & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff))) 
                    & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_csr_mul_read_req)))));
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__complete = 0U;
    if ((((IData)(core_tb__DOT__dut__DOT__plic_module__DOT__regs2gateway) 
          >> 4U) & (0U != (3U & (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_idx))))) {
        core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__complete 
            = ((IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__complete) 
               | (3U & ((IData)(1U) << (1U & ((3U & (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_idx)) 
                                              - (IData)(1U))))));
    }
    if ((((IData)(core_tb__DOT__dut__DOT__plic_module__DOT__regs2gateway) 
          >> 5U) & (0U != (3U & ((IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_idx) 
                                 >> 2U))))) {
        core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__complete 
            = ((IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__complete) 
               | (3U & ((IData)(1U) << (1U & ((3U & 
                                               ((IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__complete_idx) 
                                                >> 2U)) 
                                              - (IData)(1U))))));
    }
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__claim = 0U;
    if ((((IData)(core_tb__DOT__dut__DOT__plic_module__DOT__regs2gateway) 
          >> 6U) & (0U != (3U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT____Vcellinp__plic_regs_module__claim_idx_i))))) {
        core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__claim 
            = ((IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__claim) 
               | (3U & ((IData)(1U) << (1U & ((3U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT____Vcellinp__plic_regs_module__claim_idx_i)) 
                                              - (IData)(1U))))));
    }
    if ((((IData)(core_tb__DOT__dut__DOT__plic_module__DOT__regs2gateway) 
          >> 7U) & (0U != (3U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT____Vcellinp__plic_regs_module__claim_idx_i) 
                                 >> 2U))))) {
        core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__claim 
            = ((IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__claim) 
               | (3U & ((IData)(1U) << (1U & ((3U & 
                                               ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT____Vcellinp__plic_regs_module__claim_idx_i) 
                                                >> 2U)) 
                                              - (IData)(1U))))));
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__is_not_ecall 
        = (1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[0U] 
                    >> 4U)));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__is_not_ebreak 
        = (3U != (0xfU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[0U] 
                          >> 1U)));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_inc 
        = (1U & ((~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcountinhibit_ff 
                     >> 2U)) & (~ ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[0U] 
                                    | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__fwd2csr) 
                                       >> 1U)) | (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_req) 
                                                   & (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__is_not_ecall)) 
                                                  & (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__is_not_ebreak))))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_wr_flag)
            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata
            : ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_inc)
                ? ((IData)(1U) + vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_ff)
                : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_ff));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT____Vcellinp__muldiv_module__fwd2mul_flush_i 
        = (1U & ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_use_hazard) 
                 | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2lsu) 
                    | ((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu_mul_stall)) 
                       & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__icache2if))))));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__if_id_exe_stall 
        = (1U & ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_use_hazard) 
                 | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_stall_next) 
                    | ((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__icache2if)) 
                       | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__mul_stall_next)))));
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_set_active 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_req) 
           & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_active_ff)));
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_active_next 
        = (((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_active_ff) 
            | (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_set_active)) 
           & (~ (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__complete)));
    core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_set_pending 
        = (((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_req) 
            & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_active_ff))) 
           & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_pending_ff)));
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_pending_next 
        = (((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_pending_ff) 
            | (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_set_pending)) 
           & (~ (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__claim)));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_inc 
        = ((0xffffffffU == vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_ff) 
           & (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_inc));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_wr_flag)
            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata
            : ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_inc)
                ? ((IData)(1U) + vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_ff)
                : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_ff));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__exe_new_pc_req 
        = (1U & ((~ (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__if_id_exe_stall)) 
                 & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff) 
                    | ((IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                >> 2U)) | ((IData)(
                                                   (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                    >> 1U)) 
                                           & ((1U & (IData)(
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                             >> 0x1bU)))
                                               ? ((1U 
                                                   & (IData)(
                                                             (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                              >> 0x1aU)))
                                                   ? 
                                                  ((~ (IData)(
                                                              (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                               >> 0x19U))) 
                                                   & (IData)(
                                                             (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_output 
                                                              >> 0x20U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(
                                                              (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                               >> 0x19U)))
                                                    ? (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT____VdfgExtracted_h0362d37b__0)
                                                    : 
                                                   (~ (IData)(
                                                              (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_output 
                                                               >> 0x20U)))))
                                               : ((1U 
                                                   & (IData)(
                                                             (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                              >> 0x1aU)))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(
                                                              (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                               >> 0x19U)))
                                                    ? 
                                                   (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT____VdfgExtracted_h0362d37b__0))
                                                    : 
                                                   (0U 
                                                    != (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_output)))
                                                   : 
                                                  ((IData)(
                                                           (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                            >> 0x19U)) 
                                                   & (~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_output))))))))))));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__id_exe_flush 
        = ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__exe_new_pc_req) 
           | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2lsu));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__fwd2if 
        = ((((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgTmp_h4675c004__0)) 
             & (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__exe_new_pc_req)) 
            << 3U) | (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgTmp_h4675c004__0) 
                       << 2U) | (((IData)(vlSelf->__VdfgTmp_h7bbdf8ad__0) 
                                  << 1U) | (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__if_id_exe_stall))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2ptop 
        = (((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__id_exe_flush) 
            << 7U) | (((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__if_id_exe_stall) 
                       << 6U) | (((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__id_exe_flush) 
                                  << 5U) | (((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__if_id_exe_stall) 
                                             << 4U) 
                                            | (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu_mul_stall) 
                                                << 3U) 
                                               | (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT____Vcellinp__muldiv_module__fwd2mul_flush_i) 
                                                   << 2U) 
                                                  | (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgTmp_h140467bf__0) 
                                                      << 1U) 
                                                     | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgTmp_hb3ea78f5__0))))))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
        = ((4U & (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__fwd2if))
            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__csr2if_fb
            : ((2U & (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__fwd2if))
                ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__csr2if_fb
                : ((8U & (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__fwd2if))
                    ? ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff))
                        ? ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[2U] 
                            << 0x1fU) | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[1U] 
                                         >> 1U)) : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_result)
                    : ((1U & ((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__icache2if)) 
                              | (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__if_id_exe_stall)))
                        ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_ff
                        : ((IData)(4U) + vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_ff)))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_ctrl;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_next[0U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[0U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_next[1U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[1U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_next[2U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[2U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_next[3U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[3U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_next[4U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[4U];
    if ((8U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2ptop))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_next = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_next[0U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_next[1U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_next[2U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_next[3U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_next[4U] = 0U;
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__exe2csr_ctrl;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_ctrl_next 
        = (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__exc_code) 
            << 1U) | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__exc_req));
    if ((1U & (~ ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2ptop) 
                  >> 7U)))) {
        if ((0x40U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2ptop))) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_ctrl_next 
                = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_ctrl_pipe_ff;
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[0U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[1U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[2U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[2U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[3U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[3U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[4U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[4U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[5U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[5U];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[6U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[6U];
    if ((0x20U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2ptop))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_next = 0ULL;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[0U] 
            = (1U | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[0U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[1U] 
            = (1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[1U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[2U] 
            = (0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[2U]);
    } else if ((0x10U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2ptop))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_next 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[0U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[0U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[1U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[1U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[2U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[2U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[3U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[4U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[4U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[5U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[5U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[6U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[6U];
        if ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2ptop))) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[5U] 
                = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[5U]) 
                   | ((IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__wrb2id_fb 
                               >> 6U)) << 1U));
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[6U] 
                = ((IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__wrb2id_fb 
                            >> 6U)) >> 0x1fU);
        }
        if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2ptop))) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[4U] 
                = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[4U]) 
                   | ((IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__wrb2id_fb 
                               >> 6U)) << 1U));
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[5U] 
                = ((0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[5U]) 
                   | ((IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__wrb2id_fb 
                               >> 6U)) >> 0x1fU));
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_next[0U] 
        = ((((1U & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                            >> 0xcU))) ? (0x1fU & (
                                                   vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                                                   >> 0x10U))
              : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__operand_rs1_data) 
            << 5U) | ((0x1eU & ((IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                         >> 5U)) << 1U)) 
                      | (1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[0U])));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_next[1U] 
        = ((((1U & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                            >> 0xcU))) ? (0x1fU & (
                                                   vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                                                   >> 0x10U))
              : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__operand_rs1_data) 
            >> 0x1bU) | ((IData)((((QData)((IData)(
                                                   ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                                                     << 0x1fU) 
                                                    | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[2U] 
                                                       >> 1U)))) 
                                   << 0x20U) | (QData)((IData)(
                                                               ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[4U] 
                                                                 << 0x1fU) 
                                                                | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                                                                   >> 1U)))))) 
                         << 5U));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_next[2U] 
        = (((IData)((((QData)((IData)(((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                                        << 0x1fU) | 
                                       (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[2U] 
                                        >> 1U)))) << 0x20U) 
                     | (QData)((IData)(((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[4U] 
                                         << 0x1fU) 
                                        | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                                           >> 1U)))))) 
            >> 0x1bU) | ((IData)(((((QData)((IData)(
                                                    ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                                                      << 0x1fU) 
                                                     | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[2U] 
                                                        >> 1U)))) 
                                    << 0x20U) | (QData)((IData)(
                                                                ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[4U] 
                                                                  << 0x1fU) 
                                                                 | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                                                                    >> 1U))))) 
                                  >> 0x20U)) << 5U));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_next[3U] 
        = ((0x1ffe0U & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[4U] 
                         << 0x10U) | (0xffe0U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                                                 >> 0x10U)))) 
           | ((IData)(((((QData)((IData)(((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                                           << 0x1fU) 
                                          | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[2U] 
                                             >> 1U)))) 
                         << 0x20U) | (QData)((IData)(
                                                     ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[4U] 
                                                       << 0x1fU) 
                                                      | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                                                         >> 1U))))) 
                       >> 0x20U)) >> 0x1bU));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_next[0U] 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__operand_rs2_data;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_next[1U] 
        = (IData)((((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_result)) 
                    << 0x20U) | (QData)((IData)(((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[2U] 
                                                  << 0x1fU) 
                                                 | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[1U] 
                                                    >> 1U))))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_next[2U] 
        = (IData)(((((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_result)) 
                     << 0x20U) | (QData)((IData)(((
                                                   vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[2U] 
                                                   << 0x1fU) 
                                                  | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[1U] 
                                                     >> 1U))))) 
                   >> 0x20U));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_next 
        = ((0xf8000U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                        << 7U)) | ((0x7000U & ((IData)(
                                                       (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                        >> 9U)) 
                                               << 0xcU)) 
                                   | ((0xf80U & ((IData)(
                                                         (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                          >> 0x1cU)) 
                                                 << 7U)) 
                                      | ((0x78U & ((IData)(
                                                           (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                            >> 0x13U)) 
                                                   << 3U)) 
                                         | ((4U & (
                                                   ((0U 
                                                     != 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                                 >> 0x17U))))
                                                     ? 
                                                    ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__exe2csr_ctrl) 
                                                     >> 1U)
                                                     : (IData)(
                                                               (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                                >> 3U))) 
                                                   << 2U)) 
                                            | (3U & (IData)(
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                             >> 1U))))))));
    if ((4U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2ptop))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_next = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_next[0U] 
            = (1U | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_next[0U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_next[2U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_next = 0U;
    } else if ((8U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2ptop))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_next 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_next[0U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_next[1U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[1U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_next[2U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_next 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff;
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next[0U] 
        = (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
           << 1U);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next[1U] 
        = ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
            >> 0x1fU) | ((IData)((((QData)((IData)(
                                                   ((1U 
                                                     & (IData)(vlSelf->core_tb__DOT__dut__DOT__icache2if))
                                                     ? (IData)(
                                                               (vlSelf->core_tb__DOT__dut__DOT__icache2if 
                                                                >> 1U))
                                                     : 0x13U))) 
                                   << 0x20U) | (QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_ff)))) 
                         << 1U));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next[2U] 
        = (((IData)((((QData)((IData)(((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__icache2if))
                                        ? (IData)((vlSelf->core_tb__DOT__dut__DOT__icache2if 
                                                   >> 1U))
                                        : 0x13U))) 
                      << 0x20U) | (QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_ff)))) 
            >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                    ((1U 
                                                      & (IData)(vlSelf->core_tb__DOT__dut__DOT__icache2if))
                                                      ? (IData)(
                                                                (vlSelf->core_tb__DOT__dut__DOT__icache2if 
                                                                 >> 1U))
                                                      : 0x13U))) 
                                    << 0x20U) | (QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_ff))) 
                                  >> 0x20U)) << 1U));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next[3U] 
        = ((IData)(((((QData)((IData)(((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__icache2if))
                                        ? (IData)((vlSelf->core_tb__DOT__dut__DOT__icache2if 
                                                   >> 1U))
                                        : 0x13U))) 
                      << 0x20U) | (QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_ff))) 
                    >> 0x20U)) >> 0x1fU);
    if ((0x80U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2ptop))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next[2U] 
            = (0x26U | (1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next[2U]));
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next[3U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next[0U] 
            = (1U | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next[0U]);
    } else if ((0x40U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2ptop))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next[0U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[0U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next[1U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[1U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next[2U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next[3U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U];
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb2mmu = 0ULL;
    if (((((0xd7U >= ((IData)(0x2cU) + (0xffU & ((IData)(0x36U) 
                                                 * 
                                                 (3U 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                     >> 0x16U))))))
            ? (0x3ffU & (((0U == (0x1fU & ((IData)(0x2cU) 
                                           + (0xffU 
                                              & ((IData)(0x36U) 
                                                 * 
                                                 (3U 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                     >> 0x16U)))))))
                           ? 0U : (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[
                                   (((IData)(0x35U) 
                                     + (0xffU & ((IData)(0x36U) 
                                                 * 
                                                 (3U 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                     >> 0x16U))))) 
                                    >> 5U)] << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & ((IData)(0x2cU) 
                                                      + 
                                                      (0xffU 
                                                       & ((IData)(0x36U) 
                                                          * 
                                                          (3U 
                                                           & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                              >> 0x16U))))))))) 
                         | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[
                            (((IData)(0x2cU) + (0xffU 
                                                & ((IData)(0x36U) 
                                                   * 
                                                   (3U 
                                                    & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                       >> 0x16U))))) 
                             >> 5U)] >> (0x1fU & ((IData)(0x2cU) 
                                                  + 
                                                  (0xffU 
                                                   & ((IData)(0x36U) 
                                                      * 
                                                      (3U 
                                                       & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                          >> 0x16U)))))))))
            : 0U) == (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                      >> 0x16U)) & ((0xd7U >= ((IData)(0x21U) 
                                               + (0xffU 
                                                  & ((IData)(0x36U) 
                                                     * 
                                                     (3U 
                                                      & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                         >> 0x16U)))))) 
                                    & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[
                                       (((IData)(0x21U) 
                                         + (0xffU & 
                                            ((IData)(0x36U) 
                                             * (3U 
                                                & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                   >> 0x16U))))) 
                                        >> 5U)] >> 
                                       (0x1fU & ((IData)(0x21U) 
                                                 + 
                                                 (0xffU 
                                                  & ((IData)(0x36U) 
                                                     * 
                                                     (3U 
                                                      & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                         >> 0x16U)))))))))) {
        if (((((0xd7U >= ((IData)(0x22U) + (0xffU & 
                                            ((IData)(0x36U) 
                                             * (3U 
                                                & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                   >> 0x16U))))))
                ? (0x3ffU & (((0U == (0x1fU & ((IData)(0x22U) 
                                               + (0xffU 
                                                  & ((IData)(0x36U) 
                                                     * 
                                                     (3U 
                                                      & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                         >> 0x16U)))))))
                               ? 0U : (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[
                                       (((IData)(0x2bU) 
                                         + (0xffU & 
                                            ((IData)(0x36U) 
                                             * (3U 
                                                & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                   >> 0x16U))))) 
                                        >> 5U)] << 
                                       ((IData)(0x20U) 
                                        - (0x1fU & 
                                           ((IData)(0x22U) 
                                            + (0xffU 
                                               & ((IData)(0x36U) 
                                                  * 
                                                  (3U 
                                                   & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                      >> 0x16U))))))))) 
                             | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[
                                (((IData)(0x22U) + 
                                  (0xffU & ((IData)(0x36U) 
                                            * (3U & 
                                               (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                >> 0x16U))))) 
                                 >> 5U)] >> (0x1fU 
                                             & ((IData)(0x22U) 
                                                + (0xffU 
                                                   & ((IData)(0x36U) 
                                                      * 
                                                      (3U 
                                                       & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                          >> 0x16U)))))))))
                : 0U) == (0x3ffU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                    >> 0xcU))) | ((0xd7U 
                                                   >= 
                                                   ((IData)(0x20U) 
                                                    + 
                                                    (0xffU 
                                                     & ((IData)(0x36U) 
                                                        * 
                                                        (3U 
                                                         & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                            >> 0x16U)))))) 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[
                                                     (((IData)(0x20U) 
                                                       + 
                                                       (0xffU 
                                                        & ((IData)(0x36U) 
                                                           * 
                                                           (3U 
                                                            & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                               >> 0x16U))))) 
                                                      >> 5U)] 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(0x20U) 
                                                         + 
                                                         (0xffU 
                                                          & ((IData)(0x36U) 
                                                             * 
                                                             (3U 
                                                              & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                                 >> 0x16U)))))))))) {
            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb2mmu 
                = ((3ULL & core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb2mmu) 
                   | ((QData)((IData)(((0xd7U >= (0xffU 
                                                  & ((IData)(0x36U) 
                                                     * 
                                                     (3U 
                                                      & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                         >> 0x16U)))))
                                        ? (((0U == 
                                             (0x1fU 
                                              & ((IData)(0x36U) 
                                                 * 
                                                 (3U 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                     >> 0x16U)))))
                                             ? 0U : 
                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[
                                             (((IData)(0x1fU) 
                                               + (0xffU 
                                                  & ((IData)(0x36U) 
                                                     * 
                                                     (3U 
                                                      & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                         >> 0x16U))))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & ((IData)(0x36U) 
                                                     * 
                                                     (3U 
                                                      & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                         >> 0x16U))))))) 
                                           | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[
                                              (7U & 
                                               (((IData)(0x36U) 
                                                 * 
                                                 (3U 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                     >> 0x16U))) 
                                                >> 5U))] 
                                              >> (0x1fU 
                                                  & ((IData)(0x36U) 
                                                     * 
                                                     (3U 
                                                      & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                         >> 0x16U))))))
                                        : 0U))) << 2U));
            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb2mmu 
                = (2ULL | core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb2mmu);
            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb2mmu 
                = ((0x3fffffffeULL & core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb2mmu) 
                   | (IData)((IData)(((0xd7U >= ((IData)(0x20U) 
                                                 + 
                                                 (0xffU 
                                                  & ((IData)(0x36U) 
                                                     * 
                                                     (3U 
                                                      & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                         >> 0x16U)))))) 
                                      & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[
                                         (((IData)(0x20U) 
                                           + (0xffU 
                                              & ((IData)(0x36U) 
                                                 * 
                                                 (3U 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                     >> 0x16U))))) 
                                          >> 5U)] >> 
                                         (0x1fU & ((IData)(0x20U) 
                                                   + 
                                                   (0xffU 
                                                    & ((IData)(0x36U) 
                                                       * 
                                                       (3U 
                                                        & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                           >> 0x16U)))))))))));
        }
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__itlb_miss 
        = (1U & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr2lsu_data 
                  >> 4U) & (~ ((IData)((core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb2mmu 
                                        >> 1U)) | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgTmp_hd5ca5221__0)))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2if 
        = (1ULL | ((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next)) 
                   << 1U));
    if ((0x10U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr2lsu_data)) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2if 
            = (((QData)((IData)((0x3fffffU & (IData)(
                                                     (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb2mmu 
                                                      >> 0xcU))))) 
                << 0xdU) | (QData)((IData)(((0x1ffeU 
                                             & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                << 1U)) 
                                            | (1U & (IData)(
                                                            (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb2mmu 
                                                             >> 1U)))))));
        if ((1U & (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb2mmu))) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2if 
                = ((0x7ff801fffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2if) 
                   | ((QData)((IData)((0x3ffU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                                 >> 0xcU)))) 
                      << 0xdU));
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__iwalk_active_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__iwalk_active_ff;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_ff;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_req_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_req_ff;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_paddr_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_paddr_ff;
    if ((1U & (~ ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff)))) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__iwalk_active_next = 0U;
                if (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__itlb_miss) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__iwalk_active_next = 1U;
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_next 
                        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next;
                } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__dtlb_miss) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_next 
                        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U];
                }
            }
        }
        if ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff))) {
            if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff))) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_req_next 
                    = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_req_ff;
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_paddr_next 
                    = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_paddr_ff;
            } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_valid_ff) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_req_next = 0U;
                if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_h23a25fc1__0)))) {
                    if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_haf4fd536__0)))) {
                        if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_ff)))) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_req_next = 1U;
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_paddr_next 
                                = ((QData)((IData)(
                                                   ((0xfffffc00U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_ff) 
                                                    | (0x3ffU 
                                                       & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_ff 
                                                          >> 0xcU))))) 
                                   << 2U);
                        }
                    }
                }
            }
        } else if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff)))) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_req_next = 0U;
            if (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__itlb_miss) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_req_next = 1U;
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_paddr_next 
                    = ((QData)((IData)(((0xfffffc00U 
                                         & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr2lsu_data 
                                            << 5U)) 
                                        | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next 
                                           >> 0x16U)))) 
                       << 2U);
            } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__dtlb_miss) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_req_next = 1U;
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_paddr_next 
                    = ((QData)((IData)(((0xfffffc00U 
                                         & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr2lsu_data 
                                            << 5U)) 
                                        | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                           >> 0x16U)))) 
                       << 2U);
            }
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff;
    if ((4U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_next = 0U;
    } else if ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff))) {
        if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff))) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_next = 2U;
        } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_valid_ff) {
            if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_h23a25fc1__0) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_next = 4U;
            } else {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_next = 0U;
                if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_haf4fd536__0) {
                    if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__iwalk_active_ff) {
                        if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_h35f41773__0) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_next = 4U;
                        }
                    } else {
                        if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_hcbf4d47b__0)))) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_next = 4U;
                        }
                        if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_he4191b8e__0) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_next = 4U;
                        }
                    }
                    if (((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_ff)) 
                         & (0U != (0x3ffU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_ff 
                                             >> 0xaU))))) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_next = 4U;
                    }
                } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_ff) {
                    if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_ff) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_next = 4U;
                    }
                } else {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_next = 3U;
                }
            }
        }
    } else if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff))) {
        if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_valid_ff) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_next = 0U;
        }
    } else if (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__itlb_miss) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_next = 2U;
    } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__dtlb_miss) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_next = 2U;
    }
    if ((2U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr2lsu_data)) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_next = 0U;
    }
    core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem_i_sel 
        = (IData)((0x20001ULL == (0x1fffe0001ULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2if)));
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
        = ((1ULL & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache) 
           | (0x3fffffffeULL & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2if 
                                << 1U)));
    core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT____VdfgExtracted_hf03fca7c__0 
        = (1ULL | ((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem
                                   [(0xfffU & ((IData)(core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem_d_sel)
                                                ? (0x3fffU 
                                                   & (vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri[1U] 
                                                      >> 9U))
                                                : ((IData)(core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem_i_sel)
                                                    ? 
                                                   (0x3fffU 
                                                    & (IData)(
                                                              (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2if 
                                                               >> 3U)))
                                                    : 0U)))])) 
                   << 1U));
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellinp__icache_datapath__icache_flush 
        = (1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache));
    core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT____Vcellout__ram__read_tag_o 
        = vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM
        [(0x3ffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                            >> 6U)))];
    core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT____Vcellout__ram__read_valid_o 
        = vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__VALID_RAM
        [(0x3ffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                            >> 6U)))];
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2if_next = 0ULL;
    if (((~ (IData)(core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem_d_sel)) 
         & (IData)(core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem_i_sel))) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2if_next 
            = core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT____VdfgExtracted_hf03fca7c__0;
    }
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2dbus_next = 0ULL;
    if (((IData)(core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem_d_sel) 
         & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2dbus_ff)))) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2dbus_next 
            = core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT____VdfgExtracted_hf03fca7c__0;
    }
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__cache_ram_read[0U] 
        = vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM
        [(0x3ffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                            >> 6U)))][0U];
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__cache_ram_read[1U] 
        = vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM
        [(0x3ffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                            >> 6U)))][1U];
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__cache_ram_read[2U] 
        = vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM
        [(0x3ffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                            >> 6U)))][2U];
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__cache_ram_read[3U] 
        = vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM
        [(0x3ffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                            >> 6U)))][3U];
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__cache_ram_read[4U] 
        = ((core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT____Vcellout__ram__read_tag_o 
            << 1U) | (IData)(core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT____Vcellout__ram__read_valid_o));
    core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__cache_hit 
        = (((0x3ffffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                                 >> 0x10U))) == core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT____Vcellout__ram__read_tag_o) 
           & (IData)(core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT____Vcellout__ram__read_valid_o));
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_q 
        = vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_d;
    if ((0U == vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_d)) {
        if ((1U & (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                           >> 1U)))) {
            if (core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__cache_hit) {
                vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__icache2if_ack_ff = 1U;
                vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_q = 0U;
            } else {
                vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__icache2if_ack_ff = 0U;
                vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_q = 1U;
            }
        } else {
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_q = 0U;
        }
    } else if ((1U == vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_d)) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__icache2if_ack_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_q = 2U;
    } else if ((2U == vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_d)) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__icache2if_ack_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_q 
            = ((1U & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[0U])
                ? 3U : 2U);
    } else if ((3U == vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_d)) {
        if (core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__cache_hit) {
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__icache2if_ack_ff = 1U;
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_q = 0U;
        } else {
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_q = 3U;
        }
    }
}

void Vcore_tb___024root___eval_act(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___eval_act\n"); );
    // Body
    if (vlSelf->__VactTriggered.at(0U)) {
        Vcore_tb___024root___act_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        Vcore_tb___024root___act_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VactTriggered.at(3U)) {
        Vcore_tb___024root___act_sequent__TOP__2(vlSelf);
    }
    if (vlSelf->__VactTriggered.at(4U)) {
        Vcore_tb___024root___act_sequent__TOP__3(vlSelf);
    }
    if ((vlSelf->__VactTriggered.at(4U) | vlSelf->__VactTriggered.at(5U))) {
        Vcore_tb___024root___act_comb__TOP__0(vlSelf);
    }
    if ((vlSelf->__VactTriggered.at(3U) | vlSelf->__VactTriggered.at(4U))) {
        Vcore_tb___024root___act_comb__TOP__1(vlSelf);
    }
    if (((vlSelf->__VactTriggered.at(2U) | vlSelf->__VactTriggered.at(4U)) 
         | vlSelf->__VactTriggered.at(5U))) {
        Vcore_tb___024root___act_comb__TOP__2(vlSelf);
    }
    if (((((vlSelf->__VactTriggered.at(2U) | vlSelf->__VactTriggered.at(3U)) 
           | vlSelf->__VactTriggered.at(4U)) | vlSelf->__VactTriggered.at(5U)) 
         | vlSelf->__VactTriggered.at(6U))) {
        Vcore_tb___024root___act_comb__TOP__3(vlSelf);
    }
    if ((((((vlSelf->__VactTriggered.at(1U) | vlSelf->__VactTriggered.at(2U)) 
            | vlSelf->__VactTriggered.at(3U)) | vlSelf->__VactTriggered.at(4U)) 
          | vlSelf->__VactTriggered.at(5U)) | vlSelf->__VactTriggered.at(6U))) {
        Vcore_tb___024root___act_comb__TOP__4(vlSelf);
    }
}

VL_INLINE_OPT void Vcore_tb___024root___nba_sequent__TOP__0(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*9:0*/ __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM__v0;
    __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM__v0 = 0;
    IData/*17:0*/ __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM__v0;
    __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM__v0 = 0;
    CData/*0:0*/ __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM__v0;
    __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__VALID_RAM__v0;
    __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__VALID_RAM__v0 = 0;
    CData/*0:0*/ __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__VALID_RAM__v0;
    __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__VALID_RAM__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0;
    __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0 = 0;
    VlWide<4>/*127:0*/ __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0;
    VL_ZERO_W(128, __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0);
    CData/*0:0*/ __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0;
    __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0 = 0;
    // Body
    __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__VALID_RAM__v0 = 0U;
    __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM__v0 = 0U;
    __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0 = 0U;
    if ((1U & (~ (IData)(vlSelf->core_tb__DOT__reset)))) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(32, 0x3ffU, vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__unnamedblk1__DOT__i)) {
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM[(0x3ffU 
                                                                                & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__unnamedblk1__DOT__i)][0U] = 0U;
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM[(0x3ffU 
                                                                                & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__unnamedblk1__DOT__i)][1U] = 0U;
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM[(0x3ffU 
                                                                                & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__unnamedblk1__DOT__i)][2U] = 0U;
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM[(0x3ffU 
                                                                                & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__unnamedblk1__DOT__i)][3U] = 0U;
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__unnamedblk1__DOT__i);
        }
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(32, 0x3ffU, vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__unnamedblk1__DOT__i)) {
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM[(0x3ffU 
                                                                                & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__unnamedblk1__DOT__i)] = 0U;
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__unnamedblk1__DOT__i);
        }
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(32, 0x3ffU, vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__unnamedblk1__DOT__i)) {
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__VALID_RAM[(0x3ffU 
                                                                                & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__unnamedblk1__DOT__i)] = 0U;
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__unnamedblk1__DOT__i);
        }
    }
    if (vlSelf->core_tb__DOT__reset) {
        if (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__cache_rw) {
            __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__VALID_RAM__v0 = 1U;
            __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__VALID_RAM__v0 
                = (0x3ffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                                     >> 6U)));
            __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM__v0 
                = (0x3ffffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                                       >> 0x10U)));
            __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM__v0 = 1U;
            __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM__v0 
                = (0x3ffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                                     >> 6U)));
            __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0[0U] 
                = ((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[1U] 
                    << 0x1fU) | (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[0U] 
                                 >> 1U));
            __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0[1U] 
                = ((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[2U] 
                    << 0x1fU) | (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[1U] 
                                 >> 1U));
            __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0[2U] 
                = ((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[3U] 
                    << 0x1fU) | (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[2U] 
                                 >> 1U));
            __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0[3U] 
                = ((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[4U] 
                    << 0x1fU) | (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[3U] 
                                 >> 1U));
            __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0 = 1U;
            __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0 
                = (0x3ffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                                     >> 6U)));
        }
    }
    if (__Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__VALID_RAM__v0) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__VALID_RAM[__Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__VALID_RAM__v0] = 1U;
    }
    if (__Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM__v0) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM[__Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM__v0] 
            = __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM__v0;
    }
    if (__Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM[__Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0][0U] 
            = __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0[0U];
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM[__Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0][1U] 
            = __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0[1U];
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM[__Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0][2U] 
            = __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0[2U];
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM[__Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0][3U] 
            = __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM__v0[3U];
    }
}

extern const VlWide<27>/*863:0*/ Vcore_tb__ConstPool__CONST_h5c45ccc9_0;
extern const VlUnpacked<CData/*3:0*/, 64> Vcore_tb__ConstPool__TABLE_h5ad03769_0;

VL_INLINE_OPT void Vcore_tb___024root___nba_sequent__TOP__1(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_irq_req;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_irq_req = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__meip_irq_req;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__meip_irq_req = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mtip_irq_req;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mtip_irq_req = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__msip_irq_req;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__msip_irq_req = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__seip_irq_req;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__seip_irq_req = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__stip_irq_req;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__stip_irq_req = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__ssip_irq_req;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__ssip_irq_req = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sbit_mid_point;
    core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sbit_mid_point = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sbit_mid_point;
    core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sbit_mid_point = 0;
    CData/*2:0*/ core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__prio_th;
    core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__prio_th = 0;
    CData/*2:0*/ core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__1__KET____DOT__plic_target_module__DOT__prio_th;
    core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__1__KET____DOT__plic_target_module__DOT__prio_th = 0;
    CData/*5:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_result_ff 
        = ((1U & ((~ (IData)(vlSelf->core_tb__DOT__reset)) 
                  | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT____Vcellinp__muldiv_module__fwd2mul_flush_i)))
            ? 0U : ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu_mul_stall)
                     ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_result_ff
                     : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_result_next));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_req_ff 
        = ((~ ((~ (IData)(vlSelf->core_tb__DOT__reset)) 
               | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT____Vcellinp__muldiv_module__fwd2mul_flush_i))) 
           & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu_mul_stall)
               ? (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_req_ff)
               : (0U != (0xfU & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                         >> 0x21U))))));
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_clk_ff 
        = ((IData)(vlSelf->core_tb__DOT__reset) & (IData)(vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_clk_next));
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__frame_err_ff 
        = ((IData)(vlSelf->core_tb__DOT__reset) & (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__frame_err_next));
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__frame_err_ff 
        = ((IData)(vlSelf->core_tb__DOT__reset) & (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__frame_err_next));
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_req_ff 
        = ((IData)(vlSelf->core_tb__DOT__reset) & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_req_next));
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__valid_ff 
        = ((IData)(vlSelf->core_tb__DOT__reset) & (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__valid_next));
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__valid_ff 
        = ((IData)(vlSelf->core_tb__DOT__reset) & (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__valid_next));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__timer_irq_ff 
        = ((IData)(vlSelf->core_tb__DOT__reset) & ((IData)(
                                                           (vlSelf->core_tb__DOT__dut__DOT__core2pipe 
                                                            >> 2U)) 
                                                   & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__fwd2csr))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__ext_irq_ff 
        = ((IData)(vlSelf->core_tb__DOT__reset) & ((IData)(
                                                           (vlSelf->core_tb__DOT__dut__DOT__core2pipe 
                                                            >> 3U)) 
                                                   & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__fwd2csr))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__gmap_bit_ff 
        = ((IData)(vlSelf->core_tb__DOT__reset) & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__gmap_bit_next));
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_d 
        = ((1U & ((~ (IData)(vlSelf->core_tb__DOT__reset)) 
                  | (1U == (0xffffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2if 
                                               >> 0x11U))))))
            ? 0U : vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_q);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_valid_ff 
        = ((IData)(vlSelf->core_tb__DOT__reset) & (IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dmem2mmu));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_ff 
        = ((IData)(vlSelf->core_tb__DOT__reset) & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_next));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__mul_stall_ff 
        = ((~ ((~ (IData)(vlSelf->core_tb__DOT__reset)) 
               | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2lsu))) 
           & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__mul_stall_next));
    if (vlSelf->core_tb__DOT__reset) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_ack_ff_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_ack_ff;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__iwalk_active_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__iwalk_active_next;
        vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_overflow_ff 
            = (vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtime_ff 
               >= vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_ff);
        vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_prescaler_ff 
            = vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_prescaler_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__sample_count_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__sample_count_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__sample_count_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__sample_count_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__shifter_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__shifter_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__shifter_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__shifter_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lctrl_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lctrl_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_scratch_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_scratch_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_rx_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_rx_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state 
            = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state 
            = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state_next;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_active_ff 
            = vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_active_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rxctrl_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rxctrl_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_txctrl_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_txctrl_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rx_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rx_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_paddr_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_paddr_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__bit_count_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__bit_count_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__bit_count_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__bit_count_next;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__1__KET____DOT__plic_target_module__DOT__irq_idx_ff 
            = vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__1__KET____DOT__plic_target_module__DOT__irq_idx_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_next;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_src_ff 
            = vlSelf->core_tb__DOT__dut__DOT____Vcellinp__plic_module__irq_src_i;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sbit_sample_count_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sbit_sample_count_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sbit_sample_count_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sbit_sample_count_next;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_ie_ff 
            = vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_ie_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_baud_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_baud_next;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_pending_ff 
            = vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_pending_next;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_idx_ff 
            = vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_idx_next;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_ff 
            = vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_next;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_ff 
            = vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_ie_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_ie_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lstatus_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lstatus_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_int_mask_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_int_mask_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sample_count_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sample_count_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sample_count_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sample_count_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__state 
            = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__state_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__state 
            = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__state_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_status_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_status_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_baud_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_baud_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[0U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[0U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[1U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[1U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[2U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[2U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[3U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[3U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[4U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[4U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[5U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[5U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[6U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next[6U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_ff 
            = (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dmem2mmu 
                       >> 1U));
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_pc_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_pc_next;
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2if_ff 
            = vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2if_next;
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2dbus_ff 
            = vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2dbus_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[1U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[1U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[2U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[2U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[3U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[3U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[4U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[4U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[5U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[5U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[6U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[6U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[7U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[7U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[8U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[8U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[9U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[9U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xaU] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xaU];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xbU] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xbU];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xcU] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xcU];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xdU] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xdU];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xeU] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xeU];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xfU] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0xfU];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x10U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x10U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x11U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x11U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x12U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x12U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x13U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x13U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x14U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x14U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x15U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x15U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x16U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x16U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x17U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x17U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x18U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x18U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x19U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x19U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x1aU] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next[0x1aU];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sscratch_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sscratch_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mscratch_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mscratch_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcounteren_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcounteren_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_scause_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_scause_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcause_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcause_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stval_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stval_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtval_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtval_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_medeleg_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_medeleg_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcountinhibit_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcountinhibit_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sepc_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sepc_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mepc_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mepc_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_next;
        vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_ff 
            = vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_next;
    } else {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_ack_ff_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__iwalk_active_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_overflow_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_prescaler_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__sample_count_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__sample_count_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__shifter_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__shifter_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lctrl_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_scratch_ff = 8U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_rx_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state = 0U;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_active_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rxctrl_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_txctrl_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rx_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_paddr_ff = 0ULL;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__bit_count_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__bit_count_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__1__KET____DOT__plic_target_module__DOT__irq_idx_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_src_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sbit_sample_count_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sbit_sample_count_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_ie_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_baud_ff = 8U;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_pending_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_idx_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_ie_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lstatus_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_int_mask_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sample_count_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sample_count_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__state = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__state = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_status_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_baud_ff = 8U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[0U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[1U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[2U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[3U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[4U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[5U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff[6U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_pc_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2if_ff = 0x26ULL;
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2dbus_ff = 0x26ULL;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[1U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[1U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[2U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[2U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[3U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[3U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[4U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[4U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[5U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[5U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[6U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[6U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[7U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[7U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[8U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[8U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[9U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[9U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xaU] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0xaU];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xbU] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0xbU];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xcU] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0xcU];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xdU] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0xdU];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xeU] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0xeU];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0xfU] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0xfU];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x10U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0x10U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x11U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0x11U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x12U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0x12U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x13U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0x13U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x14U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0x14U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x15U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0x15U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x16U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0x16U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x17U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0x17U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x18U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0x18U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x19U] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0x19U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[0x1aU] 
            = Vcore_tb__ConstPool__CONST_h5c45ccc9_0[0x1aU];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sscratch_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mscratch_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcounteren_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_scause_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcause_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stval_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtval_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_medeleg_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcountinhibit_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sepc_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mepc_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff = 3U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_ff = 0ULL;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_ff = 0U;
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state 
        = ((1U & ((~ (IData)(vlSelf->core_tb__DOT__reset)) 
                  | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2lsu)))
            ? 0U : (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state_next));
    if ((1U & ((~ (IData)(vlSelf->core_tb__DOT__reset)) 
               | (IData)(((0x10U == (0x78U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)) 
                          & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_done)))))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_buffer_data_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_buffer_addr_ff = 0U;
    } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_save) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_buffer_data_ff 
            = ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[2U] 
                << 0x1bU) | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[1U] 
                             >> 5U));
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_buffer_addr_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U];
    }
    if ((0x50U == (IData)(vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_prescaler_ff))) {
        vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_prescaler_next = 0U;
        vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_clk_next 
            = (1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_clk_ff)));
    } else {
        vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_prescaler_next 
            = (0x7fU & ((IData)(1U) + (IData)(vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_prescaler_ff)));
        vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_clk_next 
            = (1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_clk_ff));
    }
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_rx_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__valid_ff)
            ? (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__shifter_ff)
            : (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_rx_ff));
    if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state))) {
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_next = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__sample_count_next = 0U;
    } else {
        if ((1U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_next = 0xbU;
        } else if ((2U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state))) {
            if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__sample_count_ff))) {
                vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_next 
                    = (0xfU & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_ff) 
                               - (IData)(1U)));
            }
        } else {
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_next = 0U;
        }
        if ((1U != (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__sample_count_next 
                = ((2U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state))
                    ? (0xffU & ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__sample_count_ff))
                                 ? ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_baud_ff) 
                                    - (IData)(1U)) : 
                                ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__sample_count_ff) 
                                 - (IData)(1U)))) : 0U);
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rx_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__valid_ff)
            ? (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__shifter_ff)
            : (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rx_ff));
    if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state))) {
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_next = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__sample_count_next = 0U;
    } else {
        if ((1U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_next = 0xbU;
        } else if ((2U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state))) {
            if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__sample_count_ff))) {
                vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_next 
                    = (0xfU & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_ff) 
                               - (IData)(1U)));
            }
        } else {
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_next = 0U;
        }
        if ((1U != (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__sample_count_next 
                = ((2U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state))
                    ? (0xfU & ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__sample_count_ff))
                                ? ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_baud_ff) 
                                   - (IData)(1U)) : 
                               ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__sample_count_ff) 
                                - (IData)(1U)))) : 0U);
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_baud_next 
        = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_baud_ff;
    core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sbit_mid_point 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sbit_sample_count_ff) 
           == (7U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_baud_ff) 
                     >> 1U)));
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT____Vcellinp__plic_regs_module__claim_idx_i 
        = (((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__1__KET____DOT__plic_target_module__DOT__irq_idx_ff) 
            << 2U) | (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_idx_ff));
    core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__1__KET____DOT__plic_target_module__DOT__prio_th 
        = (7U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_ff) 
                 >> 3U));
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__1__KET____DOT__plic_target_module__DOT__irq_idx_next = 0U;
    if (((((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_pending_ff) 
           >> 1U) & ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_ie_ff) 
                     >> 3U)) & ((7U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_ff) 
                                       >> 3U)) > (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__1__KET____DOT__plic_target_module__DOT__prio_th)))) {
        core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__1__KET____DOT__plic_target_module__DOT__prio_th 
            = (7U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_ff) 
                     >> 3U));
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__1__KET____DOT__plic_target_module__DOT__irq_idx_next = 2U;
    }
    if ((((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_pending_ff) 
          & ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_ie_ff) 
             >> 2U)) & ((7U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_ff)) 
                        > (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__1__KET____DOT__plic_target_module__DOT__prio_th)))) {
        core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__1__KET____DOT__plic_target_module__DOT__prio_th 
            = (7U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_ff));
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__1__KET____DOT__plic_target_module__DOT__irq_idx_next = 1U;
    }
    core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__prio_th 
        = (7U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_ff));
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_idx_next = 0U;
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_req_next = 0U;
    if (((((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_pending_ff) 
           >> 1U) & ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_ie_ff) 
                     >> 1U)) & ((7U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_ff) 
                                       >> 3U)) > (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__prio_th)))) {
        core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__prio_th 
            = (7U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_ff) 
                     >> 3U));
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_idx_next = 2U;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_req_next = 1U;
    }
    if ((((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_pending_ff) 
          & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_ie_ff)) 
         & ((7U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_ff)) 
            > (IData)(core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__prio_th)))) {
        core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__prio_th 
            = (7U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_ff));
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_idx_next = 1U;
        vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_req_next = 1U;
    }
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lstatus_next 
        = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lstatus_ff;
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lstatus_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__frame_err_ff)
            ? (0xf7U & (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lstatus_next))
            : ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__valid_ff)
                ? (1U | (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lstatus_next))
                : ((0x9fU & (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lstatus_next)) 
                   | (0x60U & ((- (IData)((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_ff)))) 
                               << 5U)))));
    if ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__state))) {
        if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__state))) {
            if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sample_count_ff))) {
                if (vlSelf->core_tb__DOT__dut__DOT__uart_ns_rxd_i) {
                    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__valid_next = 1U;
                }
                if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_rxd_i)))) {
                    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__frame_err_next = 1U;
                }
                vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__state_next = 0U;
            }
            if ((0U != (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sample_count_ff))) {
                vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sample_count_next 
                    = (0xffU & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sample_count_ff) 
                                - (IData)(1U)));
            }
        } else if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sample_count_ff))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sample_count_next 
                = (0xffU & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_baud_ff) 
                            - (IData)(1U)));
            if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__bit_count_ff))) {
                vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__state_next = 3U;
            }
        } else {
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sample_count_next 
                = (0xffU & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sample_count_ff) 
                            - (IData)(1U)));
        }
        if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__state)))) {
            if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sample_count_ff))) {
                if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__bit_count_ff))) {
                    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sbit_sample_count_next = 0U;
                }
                if ((0U != (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__bit_count_ff))) {
                    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__shifter_next 
                        = (((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_rxd_i) 
                            << 7U) | (0x7fU & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__shifter_ff) 
                                               >> 1U)));
                    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__bit_count_next 
                        = (0xfU & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__bit_count_ff) 
                                   - (IData)(1U)));
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__state)))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__valid_next = 0U;
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__frame_err_next = 0U;
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__shifter_next = 0U;
        }
        if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__state))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sbit_sample_count_next 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sbit_sample_count_ff)));
            if (core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sbit_mid_point) {
                vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sample_count_next 
                    = (0xffU & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_baud_ff) 
                                - (IData)(1U)));
                vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__bit_count_next = 8U;
                vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__state_next = 2U;
            }
        } else {
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sbit_sample_count_next = 0U;
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sample_count_next = 0U;
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__bit_count_next = 0U;
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__state_next = 0U;
            if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_rxd_i)))) {
                vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__state_next = 1U;
            }
        }
    }
    vlSelf->core_tb__DOT__dut__DOT____Vcellinp__plic_module__irq_src_i 
        = ((((0U != (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_status_ff)) 
             & (0U != (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_int_mask_ff))) 
            << 1U) | ((0U != (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lstatus_ff)) 
                      & (0U != (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_ie_ff))));
    core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sbit_mid_point 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sbit_sample_count_ff) 
           == (0xfU & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_baud_ff) 
                       >> 1U)));
    if ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__state))) {
        if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__state))) {
            if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sample_count_ff))) {
                if (vlSelf->core_tb__DOT__uart_rx) {
                    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__valid_next = 1U;
                }
                if ((1U & (~ (IData)(vlSelf->core_tb__DOT__uart_rx)))) {
                    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__frame_err_next = 1U;
                }
                vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__state_next = 0U;
            }
            if ((0U != (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sample_count_ff))) {
                vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sample_count_next 
                    = (0xfU & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sample_count_ff) 
                               - (IData)(1U)));
            }
        } else if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sample_count_ff))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sample_count_next 
                = (0xfU & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_baud_ff) 
                           - (IData)(1U)));
            if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__bit_count_ff))) {
                vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__state_next = 3U;
            }
        } else {
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sample_count_next 
                = (0xfU & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sample_count_ff) 
                           - (IData)(1U)));
        }
        if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__state)))) {
            if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sample_count_ff))) {
                if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__bit_count_ff))) {
                    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sbit_sample_count_next = 0U;
                }
                if ((0U != (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__bit_count_ff))) {
                    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__shifter_next 
                        = (((IData)(vlSelf->core_tb__DOT__uart_rx) 
                            << 7U) | (0x7fU & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__shifter_ff) 
                                               >> 1U)));
                    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__bit_count_next 
                        = (0xfU & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__bit_count_ff) 
                                   - (IData)(1U)));
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__state)))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__valid_next = 0U;
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__frame_err_next = 0U;
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__shifter_next = 0U;
        }
        if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__state))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sbit_sample_count_next 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sbit_sample_count_ff)));
            if (core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sbit_mid_point) {
                vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sample_count_next 
                    = (0xfU & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_baud_ff) 
                               - (IData)(1U)));
                vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__bit_count_next = 8U;
                vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__state_next = 2U;
            }
        } else {
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sbit_sample_count_next = 0U;
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sample_count_next = 0U;
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__bit_count_next = 0U;
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__state_next = 0U;
            if ((1U & (~ (IData)(vlSelf->core_tb__DOT__uart_rx)))) {
                vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__state_next = 1U;
            }
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____VdfgExtracted_h1a7370a5__0 
        = (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_ff 
           | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__gmap_bit_ff) 
              << 5U));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_h35f41773__0 
        = (1U & (~ (IData)((0x48U == (0x48U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_ff)))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_h23a25fc1__0 
        = (1U & ((~ vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_ff) 
                 | (IData)((4U == (6U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_ff)))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_haf4fd536__0 
        = (IData)((0U != (0xaU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_ff)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__mul_stall_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__mul_stall_ff;
    if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_ack_ff_ff) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__mul_stall_next = 0U;
    } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_req_ff) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__mul_stall_next = 1U;
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_ack_ff 
        = ((IData)(vlSelf->core_tb__DOT__reset) & (0U 
                                                   != 
                                                   (0xfU 
                                                    & (IData)(
                                                              (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                               >> 0x21U)))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw2mmu 
        = ((0xf00000000ULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw2mmu) 
           | (IData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_ff)));
    vlSelf->core_tb__DOT__dut__DOT__core2pipe = (QData)((IData)(
                                                                (((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_req_ff) 
                                                                  << 3U) 
                                                                 | (((IData)(vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_overflow_ff) 
                                                                     << 2U) 
                                                                    | ((IData)(vlSelf->core_tb__DOT__irq_soft) 
                                                                       << 1U)))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__gmap_bit_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__gmap_bit_ff;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw2mmu 
        = (0xcffffffffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw2mmu);
    if ((4U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff))) {
        if ((1U & (~ ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff) 
                      >> 1U)))) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw2mmu 
                = ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff))
                    ? (0x100000000ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw2mmu)
                    : (0x200000000ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw2mmu));
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw2mmu 
        = ((0x3ffffffffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw2mmu) 
           | ((QData)((IData)((((0U != (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff)) 
                                << 1U) | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__iwalk_active_ff)))) 
              << 0x22U));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_done = 0U;
    if ((4U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))) {
        if ((1U & (~ ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state)))) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_done = 1U;
            }
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_exc_req = 0U;
    if (((1U == (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff)) 
         & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff 
            >> 0x14U))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_exc_req = 1U;
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__meip_irq_req 
        = (1U & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_ff 
                  & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_ff) 
                 >> 0xbU));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__msip_irq_req 
        = (1U & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_ff 
                  & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_ff) 
                 >> 3U));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mtip_irq_req 
        = (1U & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_ff 
                  & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_ff) 
                 >> 7U));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__seip_irq_req 
        = (1U & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_ff 
                  & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_ff) 
                 >> 9U));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__ssip_irq_req 
        = (1U & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_ff 
                  & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_ff) 
                 >> 1U));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__stip_irq_req 
        = (1U & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_ff 
                  & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_ff) 
                 >> 5U));
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_req 
        = ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_req)) 
           | (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT____Vcellinp__plic_module__irq_src_i) 
                    & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_src_ff)))));
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_req 
        = ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_req)) 
           | ((IData)((((IData)(vlSelf->core_tb__DOT__dut__DOT____Vcellinp__plic_module__irq_src_i) 
                        >> 1U) & (~ ((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_src_ff) 
                                     >> 1U)))) << 1U));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_ff;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__itlb_update = 0U;
    if ((1U & (~ ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff))) {
            if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff)))) {
                if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_valid_ff) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__gmap_bit_next 
                        = (1U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_ff 
                                 >> 5U));
                    if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_h23a25fc1__0)))) {
                        if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_haf4fd536__0) {
                            if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__iwalk_active_ff) {
                                if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_h35f41773__0)))) {
                                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__itlb_update = 1U;
                                }
                            }
                            if (((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_ff)) 
                                 & (0U != (0x3ffU & 
                                           (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_ff 
                                            >> 0xaU))))) {
                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__itlb_update = 0U;
                            }
                        }
                    }
                }
            }
            if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff))) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_next = 1U;
            } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_valid_ff) {
                if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_h23a25fc1__0)))) {
                    if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_haf4fd536__0)))) {
                        if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_ff) {
                            if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_ff) {
                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_next = 1U;
                            }
                        } else {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_next = 1U;
                        }
                    }
                }
            }
        } else if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff)))) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__gmap_bit_next = 0U;
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_next = 0U;
        }
    }
    __Vtableidx2 = (((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__stip_irq_req) 
                     << 5U) | (((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__ssip_irq_req) 
                                << 4U) | (((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__seip_irq_req) 
                                           << 3U) | 
                                          (((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mtip_irq_req) 
                                            << 2U) 
                                           | (((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__msip_irq_req) 
                                               << 1U) 
                                              | (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__meip_irq_req))))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_code 
        = Vcore_tb__ConstPool__TABLE_h5ad03769_0[__Vtableidx2];
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_irq_req 
        = ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__seip_irq_req) 
           | ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__stip_irq_req) 
              | (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__ssip_irq_req)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_req 
        = ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__meip_irq_req) 
           | ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mtip_irq_req) 
              | ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__msip_irq_req) 
                 | (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_irq_req))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_delegated_req 
        = ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_irq_req) 
           & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_ff 
              >> (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_code)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_irq_req 
        = ((((1U == (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff)) 
             & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff 
                >> 1U)) | (0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff))) 
           & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_delegated_req));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_irq_req 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_req) 
           & ((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_delegated_req)) 
              & (((3U == (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff)) 
                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff 
                     >> 3U)) | (3U != (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff)))));
}

extern const VlUnpacked<CData/*0:0*/, 256> Vcore_tb__ConstPool__TABLE_h6ea4d6b0_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vcore_tb__ConstPool__TABLE_h04823f0d_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vcore_tb__ConstPool__TABLE_h23aae2ab_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vcore_tb__ConstPool__TABLE_hafc97858_0;

VL_INLINE_OPT void Vcore_tb___024root___nba_sequent__TOP__2(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_sequent__TOP__2\n"); );
    // Init
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_misaligned;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_misaligned = 0;
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    QData/*32:0*/ __Vdly__core_tb__DOT__dut__DOT__uart_module__DOT__uart2dbus_ff;
    __Vdly__core_tb__DOT__dut__DOT__uart_module__DOT__uart2dbus_ff = 0;
    QData/*32:0*/ __Vdly__core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart2dbus_ff;
    __Vdly__core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart2dbus_ff = 0;
    QData/*32:0*/ __Vdly__core_tb__DOT__dut__DOT__clint_module__DOT__clint2dbus_ff;
    __Vdly__core_tb__DOT__dut__DOT__clint_module__DOT__clint2dbus_ff = 0;
    QData/*32:0*/ __Vdly__core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic2dbus_ff;
    __Vdly__core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic2dbus_ff = 0;
    IData/*24:0*/ __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0;
    __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0 = 0;
    CData/*4:0*/ __Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0;
    __Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0 = 0;
    CData/*7:0*/ __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0;
    __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0 = 0;
    CData/*0:0*/ __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0;
    __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0 = 0;
    IData/*24:0*/ __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1;
    __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1 = 0;
    CData/*4:0*/ __Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1;
    __Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1 = 0;
    CData/*7:0*/ __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1;
    __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1 = 0;
    CData/*0:0*/ __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1;
    __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1 = 0;
    IData/*24:0*/ __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2;
    __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2 = 0;
    CData/*4:0*/ __Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2;
    __Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2 = 0;
    CData/*7:0*/ __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2;
    __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2 = 0;
    CData/*0:0*/ __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2;
    __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2 = 0;
    IData/*24:0*/ __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3;
    __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3 = 0;
    CData/*4:0*/ __Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3;
    __Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3 = 0;
    CData/*7:0*/ __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3;
    __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3 = 0;
    CData/*0:0*/ __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3;
    __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3 = 0;
    // Body
    __Vdly__core_tb__DOT__dut__DOT__clint_module__DOT__clint2dbus_ff 
        = vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__clint2dbus_ff;
    __Vdly__core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart2dbus_ff 
        = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart2dbus_ff;
    __Vdly__core_tb__DOT__dut__DOT__uart_module__DOT__uart2dbus_ff 
        = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart2dbus_ff;
    __Vdly__core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic2dbus_ff 
        = vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic2dbus_ff;
    __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0 = 0U;
    __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1 = 0U;
    __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2 = 0U;
    __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3 = 0U;
    vlSelf->core_tb__DOT__loop_count = (0xfffffffffULL 
                                        & (1ULL + vlSelf->core_tb__DOT__loop_count));
    if (VL_UNLIKELY(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__tx_valid_ff)) {
        VL_FWRITEF(vlSelf->core_tb__DOT__uartlog_filepointer,"%c",
                   8,vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_tx_ff);
    }
    if (VL_UNLIKELY(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__tx_valid_ff)) {
        VL_FWRITEF(vlSelf->core_tb__DOT__uartlog_filepointer,"%c",
                   8,vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_tx_ff);
    }
    if (VL_UNLIKELY((((~ vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[0U]) 
                      & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu_mul_stall_ff))) 
                     & (IData)(vlSelf->core_tb__DOT__flag)))) {
        VL_FWRITEF(vlSelf->core_tb__DOT__tracelog_filepointer,"%11# \t %x \n",
                   36,vlSelf->core_tb__DOT__loop_count,
                   32,((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                        << 0x1bU) | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[2U] 
                                     >> 5U)));
    }
    if ((0xc003ffa8U == ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                          << 0x1bU) | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[2U] 
                                       >> 5U)))) {
        vlSelf->core_tb__DOT__flag = 1U;
    }
    if (VL_UNLIKELY((0x8000000ULL == vlSelf->core_tb__DOT__loop_count))) {
        VL_WRITEF("End of simulation\n");
        VL_FCLOSE_I(vlSelf->core_tb__DOT__tracelog_filepointer); vlSelf->core_tb__DOT__tracelog_filepointer = 0;
        VL_FCLOSE_I(vlSelf->core_tb__DOT__uartlog_filepointer); vlSelf->core_tb__DOT__uartlog_filepointer = 0;
        VL_FINISH_MT("../rtl/tb/core_tb.sv", 210, "");
    }
    __Vdly__core_tb__DOT__dut__DOT__clint_module__DOT__clint2dbus_ff = 0ULL;
    if ((((IData)(vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__r_req) 
          | (IData)(vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__w_req)) 
         & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__clint2dbus_ff)))) {
        __Vdly__core_tb__DOT__dut__DOT__clint_module__DOT__clint2dbus_ff 
            = (1ULL | __Vdly__core_tb__DOT__dut__DOT__clint_module__DOT__clint2dbus_ff);
        if (vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__r_req) {
            __Vdly__core_tb__DOT__dut__DOT__clint_module__DOT__clint2dbus_ff 
                = ((1ULL & __Vdly__core_tb__DOT__dut__DOT__clint_module__DOT__clint2dbus_ff) 
                   | ((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__r_data)) 
                      << 1U));
        }
    }
    __Vdly__core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart2dbus_ff = 0ULL;
    if ((((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__reg_wr_req) 
          | (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__reg_rd_req)) 
         & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart2dbus_ff)))) {
        __Vdly__core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart2dbus_ff 
            = (1ULL | __Vdly__core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart2dbus_ff);
        if (vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__reg_rd_req) {
            __Vdly__core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart2dbus_ff 
                = ((1ULL & __Vdly__core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart2dbus_ff) 
                   | ((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__reg_r_data)) 
                      << 1U));
        }
    }
    __Vdly__core_tb__DOT__dut__DOT__uart_module__DOT__uart2dbus_ff = 0ULL;
    if ((((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__reg_wr_req) 
          | (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__reg_rd_req)) 
         & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart2dbus_ff)))) {
        __Vdly__core_tb__DOT__dut__DOT__uart_module__DOT__uart2dbus_ff 
            = (1ULL | __Vdly__core_tb__DOT__dut__DOT__uart_module__DOT__uart2dbus_ff);
        if (vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__reg_rd_req) {
            __Vdly__core_tb__DOT__dut__DOT__uart_module__DOT__uart2dbus_ff 
                = ((1ULL & __Vdly__core_tb__DOT__dut__DOT__uart_module__DOT__uart2dbus_ff) 
                   | ((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__reg_r_data)) 
                      << 1U));
        }
    }
    __Vdly__core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic2dbus_ff = 0ULL;
    if ((((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_wr_req) 
          | (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_rd_req)) 
         & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic2dbus_ff)))) {
        __Vdly__core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic2dbus_ff 
            = (1ULL | __Vdly__core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic2dbus_ff);
        if (vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_rd_req) {
            __Vdly__core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic2dbus_ff 
                = ((1ULL & __Vdly__core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic2dbus_ff) 
                   | ((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_r_data)) 
                      << 1U));
        }
    }
    if (((IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_sel_ff) 
         & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem2dbus_ff)))) {
        if (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_wen_ff) {
            if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_selbyte_ff))) {
                __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0 
                    = (0xffU & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_wdata_ff);
                __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0 = 1U;
                __Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0 = 0U;
                __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0 
                    = (0x1ffffffU & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_addr_ff);
            }
            if ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_selbyte_ff))) {
                __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1 
                    = (0xffU & (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_wdata_ff 
                                >> 8U));
                __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1 = 1U;
                __Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1 = 8U;
                __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1 
                    = (0x1ffffffU & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_addr_ff);
            }
            if ((4U & (IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_selbyte_ff))) {
                __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2 
                    = (0xffU & (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_wdata_ff 
                                >> 0x10U));
                __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2 = 1U;
                __Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2 = 0x10U;
                __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2 
                    = (0x1ffffffU & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_addr_ff);
            }
            if ((8U & (IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_selbyte_ff))) {
                __Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3 
                    = (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_wdata_ff 
                       >> 0x18U);
                __Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3 = 1U;
                __Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3 = 0x18U;
                __Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3 
                    = (0x1ffffffU & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_addr_ff);
            }
        } else {
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem2dbus_ff 
                = ((1ULL & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem2dbus_ff) 
                   | ((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory
                                      [(0x1ffffffU 
                                        & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_addr_ff)])) 
                      << 1U));
        }
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem2dbus_ff 
            = (1ULL | vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem2dbus_ff);
    } else {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem2dbus_ff = 0ULL;
    }
    if (vlSelf->core_tb__DOT__reset) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a_ff 
            = (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__ld_req) 
                & (IData)(vlSelf->core_tb__DOT__dut__DOT__dbus2lsu))
                ? (IData)((vlSelf->core_tb__DOT__dut__DOT__dbus2lsu 
                           >> 1U)) : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a_ff);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_ctrl_pipe_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_ctrl_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[0U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next[0U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[1U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next[1U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next[2U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next[3U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next;
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellout__icache_datapath__icache2if_data_o 
            = ((1U & (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                              >> 5U))) ? ((1U & (IData)(
                                                        (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                                                         >> 4U)))
                                           ? vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__cache_ram_read[3U]
                                           : vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__cache_ram_read[2U])
                : ((1U & (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                                  >> 4U))) ? vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__cache_ram_read[1U]
                    : vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__cache_ram_read[0U]));
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[0U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[0U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[1U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[1U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[2U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[2U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[3U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[4U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[4U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[5U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[5U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[6U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[6U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr2wrb_data_pipe_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_pipe_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[0U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_next[0U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[1U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_next[1U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[2U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_next[2U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[3U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_next[3U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[4U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_next[4U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_next[0U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[1U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_next[1U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_next[2U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_next;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[0U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_next[0U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[1U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_next[1U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[2U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_next[2U];
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_next[3U];
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellout__icache_controller_module__icache2if_ack_o 
            = vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__icache2if_ack_ff;
    } else {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_ctrl_pipe_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[0U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[1U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] = 0x26U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_ff = 0x10000U;
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellout__icache_datapath__icache2if_data_o = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[0U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[1U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[2U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[4U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[5U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[6U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr2wrb_data_pipe_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_pipe_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[0U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[1U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[2U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[3U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[4U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[0U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[1U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff = 0ULL;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[0U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[1U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[2U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellout__icache_controller_module__icache2if_ack_o = 0U;
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_stall_ff 
        = ((~ ((~ (IData)(vlSelf->core_tb__DOT__reset)) 
               | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2lsu))) 
           & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_stall_next));
    if (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem_rd_req_ff) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[0U] 
            = (1U | vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[0U]);
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[0U] 
            = ((1U & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[0U]) 
               | (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory
                  [(0x1fffffcU & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem_addr_ff)] 
                  << 1U));
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[1U] 
            = ((0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[1U]) 
               | (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory
                  [(0x1fffffcU & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem_addr_ff)] 
                  >> 0x1fU));
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[1U] 
            = ((1U & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[1U]) 
               | (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory
                  [(0x1ffffffU & ((IData)(1U) + (0xffffffcU 
                                                 & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem_addr_ff)))] 
                  << 1U));
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[2U] 
            = ((0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[2U]) 
               | (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory
                  [(0x1ffffffU & ((IData)(1U) + (0xffffffcU 
                                                 & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem_addr_ff)))] 
                  >> 0x1fU));
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[2U] 
            = ((1U & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[2U]) 
               | (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory
                  [(0x1ffffffU & ((IData)(2U) + (0xffffffcU 
                                                 & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem_addr_ff)))] 
                  << 1U));
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[3U] 
            = ((0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[3U]) 
               | (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory
                  [(0x1ffffffU & ((IData)(2U) + (0xffffffcU 
                                                 & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem_addr_ff)))] 
                  >> 0x1fU));
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[3U] 
            = ((1U & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[3U]) 
               | (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory
                  [(0x1ffffffU & ((IData)(3U) + (0xffffffcU 
                                                 & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem_addr_ff)))] 
                  << 1U));
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[4U] 
            = (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory
               [(0x1ffffffU & ((IData)(3U) + (0xffffffcU 
                                              & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem_addr_ff)))] 
               >> 0x1fU);
    } else {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[0U] 
            = (0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[0U]);
    }
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__clint2dbus_ff 
        = __Vdly__core_tb__DOT__dut__DOT__clint_module__DOT__clint2dbus_ff;
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart2dbus_ff 
        = __Vdly__core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart2dbus_ff;
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart2dbus_ff 
        = __Vdly__core_tb__DOT__dut__DOT__uart_module__DOT__uart2dbus_ff;
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic2dbus_ff 
        = __Vdly__core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic2dbus_ff;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu_mul_stall_ff 
        = ((IData)(vlSelf->core_tb__DOT__reset) & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu_mul_stall));
    if (__Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory[__Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0))) 
                & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory
                [__Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0) 
                                   << (IData)(__Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v0))));
    }
    if (__Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory[__Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1))) 
                & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory
                [__Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1) 
                                   << (IData)(__Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v1))));
    }
    if (__Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory[__Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2))) 
                & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory
                [__Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2) 
                                   << (IData)(__Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v2))));
    }
    if (__Vdlyvset__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory[__Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3))) 
                & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory
                [__Vdlyvdim0__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3) 
                                   << (IData)(__Vdlyvlsb__core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory__v3))));
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_misaligned 
        = (IData)((0U != (3U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_ff)));
    __Vtableidx1 = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sret_req 
        = Vcore_tb__ConstPool__TABLE_h6ea4d6b0_0[__Vtableidx1];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mret_req 
        = Vcore_tb__ConstPool__TABLE_h04823f0d_0[__Vtableidx1];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_req 
        = Vcore_tb__ConstPool__TABLE_h23aae2ab_0[__Vtableidx1];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sfence_vma_req 
        = Vcore_tb__ConstPool__TABLE_hafc97858_0[__Vtableidx1];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__writeback_module__DOT__wrb_rd_data 
        = ((8U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_pipe_ff))
            ? ((4U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_pipe_ff))
                ? 0U : ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_pipe_ff))
                         ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[0U]
                         : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr2wrb_data_pipe_ff))
            : ((4U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_pipe_ff))
                ? ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_pipe_ff))
                    ? ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[2U] 
                        << 0x1bU) | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[1U] 
                                     >> 5U)) : ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[3U] 
                                                 << 0x1bU) 
                                                | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[2U] 
                                                   >> 5U)))
                : ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_pipe_ff))
                    ? ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[4U] 
                        << 0x1bU) | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[3U] 
                                     >> 5U)) : 0U)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgTmp_h140467bf__0 
        = (((0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                      >> 0x10U)) == (0x1fU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[1U])) 
           & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_pipe_ff) 
              & (0U != (0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                                 >> 0x10U)))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgTmp_hb3ea78f5__0 
        = (((0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                      >> 0x15U)) == (0x1fU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[1U])) 
           & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_pipe_ff) 
              & (0U != (0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                                 >> 0x15U)))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[2U] 
        = ((0x1fU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[2U]) 
           | ((IData)((((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[1U])))) 
              << 5U));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[3U] 
        = (((IData)((((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U])) 
                      << 0x20U) | (QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[1U])))) 
            >> 0x1bU) | ((IData)(((((QData)((IData)(
                                                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[1U]))) 
                                  >> 0x20U)) << 5U));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[4U] 
        = ((IData)(((((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U])) 
                      << 0x20U) | (QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[1U]))) 
                    >> 0x20U)) >> 0x1bU);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_ctrl 
        = ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_ctrl)) 
           | (0xeU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                      >> 0xbU)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu2rs1_hazard 
        = (((0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                      >> 0x10U)) == (0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                              >> 0xfU))) 
           & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
               >> 2U) & (0U != (0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                                         >> 0x10U)))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu2rs2_hazard 
        = (((0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                      >> 0x15U)) == (0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                              >> 0xfU))) 
           & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
               >> 2U) & (0U != (0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                                         >> 0x15U)))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__exe2csr_ctrl 
        = ((3U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__exe2csr_ctrl)) 
           | ((0xc0U & ((IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                 >> 0x17U)) << 6U)) 
              | ((0x38U & ((IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                    >> 0x10U)) << 3U)) 
                 | (4U & ((IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                   >> 4U)) << 2U)))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__exe2csr_ctrl 
        = ((0xfcU & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__exe2csr_ctrl)) 
           | ((1U == (3U & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                    >> 0x17U)))) ? 
              (1U | ((IData)((0U != (0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                                              >> 8U)))) 
                     << 1U)) : (((2U == (3U & (IData)(
                                                      (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                       >> 0x17U)))) 
                                 | (3U == (3U & (IData)(
                                                        (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                         >> 0x17U)))))
                                 ? (2U | (0U != (0x1fU 
                                                 & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                                                    >> 0x10U))))
                                 : 0U)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__exc_code = 0xaU;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__exc_req = 0U;
    if (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_misaligned) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__exc_code = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__exc_req = 1U;
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sscratch_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mscratch_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcounteren_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcountinhibit_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_medeleg_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sie_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sepc_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mepc_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcause_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtval_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stval_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sip_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sstatus_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_wr_flag = 0U;
    if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff))) {
        if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                      >> 0x10U)))) {
            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                          >> 0xfU)))) {
                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                              >> 0xeU)))) {
                    if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                      >> 0xcU)))) {
                            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                          >> 0xbU)))) {
                                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                              >> 0xaU)))) {
                                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                  >> 9U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                    >> 8U)))) {
                                            if ((0x80U 
                                                 & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                         >> 6U)))) {
                                                    if (
                                                        (0x20U 
                                                         & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_wr_flag = 1U;
                                                    }
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sie_wr_flag = 1U;
                                                    }
                                                }
                                            }
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                     >> 7U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                         >> 6U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sstatus_wr_flag = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                              >> 0xaU)))) {
                                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                  >> 9U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                    >> 8U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                     >> 7U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                         >> 6U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sscratch_wr_flag = 1U;
                                                    }
                                                    if (
                                                        (0x20U 
                                                         & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sepc_wr_flag = 1U;
                                                    }
                                                }
                                                if (
                                                    (0x40U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                    if (
                                                        (0x20U 
                                                         & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stval_wr_flag = 1U;
                                                    }
                                                }
                                            }
                                            if ((0x80U 
                                                 & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                         >> 6U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sip_wr_flag = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if ((0x1000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                          >> 0xbU)))) {
                                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                              >> 0xaU)))) {
                                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                  >> 9U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                    >> 8U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                     >> 7U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                         >> 6U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_wr_flag = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if ((0x4000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                      >> 0xcU)))) {
                            if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                              >> 0xaU)))) {
                                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                  >> 9U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                    >> 8U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                     >> 7U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                         >> 6U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mscratch_wr_flag = 1U;
                                                    }
                                                    if (
                                                        (0x20U 
                                                         & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mepc_wr_flag = 1U;
                                                    }
                                                }
                                                if (
                                                    (0x40U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcause_wr_flag = 1U;
                                                    }
                                                    if (
                                                        (0x20U 
                                                         & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtval_wr_flag = 1U;
                                                    }
                                                }
                                            }
                                            if ((0x80U 
                                                 & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                         >> 6U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_wr_flag = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                          >> 0xbU)))) {
                                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                              >> 0xaU)))) {
                                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                  >> 9U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                    >> 8U)))) {
                                            if ((0x80U 
                                                 & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                         >> 6U)))) {
                                                    if (
                                                        (0x20U 
                                                         & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_wr_flag = 1U;
                                                    }
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_wr_flag = 1U;
                                                    }
                                                }
                                                if (
                                                    (0x40U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcounteren_wr_flag = 1U;
                                                    }
                                                }
                                            }
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                     >> 7U)))) {
                                                if (
                                                    (0x40U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_medeleg_wr_flag = 1U;
                                                    }
                                                    if (
                                                        (0x20U 
                                                         & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_wr_flag = 1U;
                                                    }
                                                }
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                         >> 6U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_wr_flag = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                  >> 9U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                    >> 8U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                     >> 7U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                         >> 6U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcountinhibit_wr_flag = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((0x10000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                          >> 0xfU)))) {
                if ((0x4000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        if ((0x1000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                          >> 0xbU)))) {
                                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                              >> 0xaU)))) {
                                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                  >> 9U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                    >> 8U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                     >> 7U)))) {
                                                if (
                                                    (0x40U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_wr_flag = 1U;
                                                    }
                                                }
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                         >> 6U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_wr_flag = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                      >> 0xcU)))) {
                            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                          >> 0xbU)))) {
                                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                              >> 0xaU)))) {
                                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                  >> 9U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                    >> 8U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                     >> 7U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                         >> 6U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_wr_flag = 1U;
                                                    }
                                                }
                                                if (
                                                    (0x40U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_wr_flag = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if ((0x8000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                if ((0x4000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        if ((0x1000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                        } else if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                        } else if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                        } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                            } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                                } else if ((0x20U & 
                                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                                }
                            } else {
                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                            }
                        } else {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                        }
                    } else {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    }
                } else {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                }
            } else if ((0x4000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x1000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                        } else if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                        } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                        } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                        } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                        } else if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                            }
                        } else if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                        }
                    } else if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    } else if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    } else if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                        }
                    } else if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    }
                } else {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                }
            } else {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
            }
        } else if ((0x8000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
        } else if ((0x4000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
            if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                if ((0x1000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                } else if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                        } else if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                        }
                    }
                } else if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    } else if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    } else if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    }
                } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                        }
                    }
                }
            } else {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
            }
        } else if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
            if ((0x1000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                } else if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                } else if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                } else if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                }
            } else if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    } else if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    }
                } else if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                  >> 5U)))) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                    }
                }
            } else if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
            } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
            } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
            } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
                }
            } else if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
            } else if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
            }
        } else {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 1U;
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__wrb2id_fb 
        = (((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__writeback_module__DOT__wrb_rd_data)) 
            << 6U) | (QData)((IData)(((0x3eU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[1U] 
                                                << 1U)) 
                                      | (1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_pipe_ff))))));
}

VL_INLINE_OPT void Vcore_tb___024root___nba_sequent__TOP__3(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_sequent__TOP__3\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v0;
    __Vdlyvdim0__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v0 = 0;
    IData/*31:0*/ __Vdlyvval__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v0;
    __Vdlyvval__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v0 = 0;
    CData/*0:0*/ __Vdlyvset__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v0;
    __Vdlyvset__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v0 = 0;
    CData/*0:0*/ __Vdlyvset__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v1;
    __Vdlyvset__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v1 = 0;
    // Body
    __Vdlyvset__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v0 = 0U;
    __Vdlyvset__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v1 = 0U;
    if (vlSelf->core_tb__DOT__reset) {
        if (((0U != (0x1fU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[1U])) 
             & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_pipe_ff))) {
            __Vdlyvval__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v0 
                = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__writeback_module__DOT__wrb_rd_data;
            __Vdlyvset__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v0 = 1U;
            __Vdlyvdim0__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v0 
                = (0x1fU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[1U]);
        }
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem_addr_ff 
            = (0x3ffffffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                                     >> 4U)));
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem_rd_req_ff 
            = ((1U != (0xffffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2if 
                                          >> 0x11U)))) 
               & (IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellout__icache_controller_module__icache2imem_request_o));
    } else {
        __Vdlyvset__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v1 = 1U;
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem_addr_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem_rd_req_ff = 0U;
    }
    if (__Vdlyvset__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v0) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[__Vdlyvdim0__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v0] 
            = __Vdlyvval__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v0;
    }
    if (__Vdlyvset__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file__v1) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[1U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[2U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[3U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[4U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[5U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[6U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[7U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[8U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[9U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0xaU] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0xbU] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0xcU] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0xdU] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0xeU] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0xfU] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0x10U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0x11U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0x12U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0x13U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0x14U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0x15U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0x16U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0x17U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0x18U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0x19U] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0x1aU] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0x1bU] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0x1cU] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0x1dU] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0x1eU] = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[0x1fU] = 0U;
    }
}

VL_INLINE_OPT void Vcore_tb___024root___nba_sequent__TOP__4(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_sequent__TOP__4\n"); );
    // Body
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtime_ff 
        = ((IData)(vlSelf->core_tb__DOT__reset) ? vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtime_next
            : 0ULL);
    vlSelf->core_tb__DOT__dut__DOT__clint2csr = (((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtime_ff)) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   (vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtime_ff 
                                                                    >> 0x20U))));
}

VL_INLINE_OPT void Vcore_tb___024root___nba_comb__TOP__0(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT____VdfgTmp_h21021b6f__0 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_exc_req) 
           | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_irq_req));
}

VL_INLINE_OPT void Vcore_tb___024root___nba_comb__TOP__1(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_comb__TOP__1\n"); );
    // Body
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT____VdfgTmp_he5991c42__0 
        = (1U & ((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_exc_req)) 
                 & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_irq_req))));
}

VL_INLINE_OPT void Vcore_tb___024root___nba_sequent__TOP__5(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_sequent__TOP__5\n"); );
    // Body
    if ((0U != vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_d)) {
        if ((1U == vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_d)) {
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellout__icache_controller_module__icache2imem_request_o = 1U;
        }
    }
    if (vlSelf->core_tb__DOT__reset) {
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__tx_valid_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__tx_valid_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__tx_valid_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__tx_valid_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_tx_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_tx_next;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_tx_ff 
            = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_tx_next;
    } else {
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__tx_valid_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__tx_valid_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_tx_ff = 0x4aU;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_tx_ff = 0x4aU;
    }
    if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state))) {
        if (((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__tx_valid_ff) 
             & (0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_ff)))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state_next = 1U;
        }
    } else if ((1U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state))) {
        if ((0U != (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_ff))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state_next = 2U;
        }
    } else if ((2U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state))) {
        if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_ff))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state_next = 0U;
        }
    } else {
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state_next = 0U;
    }
    if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state))) {
        if (((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__tx_valid_ff) 
             & (0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_ff)))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state_next = 1U;
        }
    } else if ((1U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state))) {
        if ((0U != (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_ff))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state_next = 2U;
        }
    } else if ((2U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state))) {
        if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_ff))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state_next = 0U;
        }
    } else {
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state_next = 0U;
    }
}

VL_INLINE_OPT void Vcore_tb___024root___nba_sequent__TOP__6(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_sequent__TOP__6\n"); );
    // Body
    if (vlSelf->core_tb__DOT__reset) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_wen_ff 
            = (1U & (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__lsummu2dmem[0U] 
                     >> 2U));
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_selbyte_ff 
            = (0xfU & (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__lsummu2dmem[0U] 
                       >> 3U));
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_wdata_ff 
            = ((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__lsummu2dmem[1U] 
                << 0x19U) | (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__lsummu2dmem[0U] 
                             >> 7U));
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_addr_ff 
            = (0x3ffffffU & ((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__lsummu2dmem[2U] 
                              << 0x17U) | (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__lsummu2dmem[1U] 
                                           >> 9U)));
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_sel_ff 
            = (vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__lsummu2dmem[0U] 
               & ((IData)(vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dmem_sel) 
                  | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_req_ff)));
    } else {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_wen_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_selbyte_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_wdata_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_addr_ff = 0U;
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_sel_ff = 0U;
    }
}

VL_INLINE_OPT void Vcore_tb___024root___nba_comb__TOP__2(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_comb__TOP__2\n"); );
    // Init
    CData/*3:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2exe;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2exe = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 0;
    IData/*31:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_adder_output;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_adder_output = 0;
    IData/*31:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1 = 0;
    IData/*31:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2 = 0;
    IData/*31:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_operand_2;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_operand_2 = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_overflow;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_overflow = 0;
    QData/*63:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT____VdfgExtracted_h5df1bfaf__0;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT____VdfgExtracted_h5df1bfaf__0 = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req = 0;
    // Body
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl = 0x2140ULL;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 0U;
    if ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_ctrl_pipe_ff))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
            = ((0x1fffffffe0fULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl) 
               | ((QData)((IData)((1U | (0x1eU & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_ctrl_pipe_ff))))) 
                  << 4U));
    } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
        if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
            if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                if ((0x10U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                } else if ((8U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                } else if ((0x8000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                    if ((0x4000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                        if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                                = (0x800ULL | (0x1fffffff1ffULL 
                                               & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                                = (0x1800000ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                                = (0x1000ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                        } else {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                                = (0x800ULL | (0x1fffffff1ffULL 
                                               & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                                = (0x1000000ULL | (0x1fffe7fffffULL 
                                                   & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                                = (0x1000ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                        }
                    } else if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x800ULL | (0x1fffffff1ffULL 
                                           & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x800000ULL | (0x1fffe7fffffULL 
                                              & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x1000ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                    } else {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                    }
                } else if ((0x4000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                    if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x8000ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x800ULL | (0x1fffffff1ffULL 
                                           & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x1800000ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x1ffffffefffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                    } else {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x8000ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x800ULL | (0x1fffffff1ffULL 
                                           & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x1000000ULL | (0x1fffe7fffffULL 
                                               & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x1ffffffefffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                    }
                } else if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = (0x8000ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = (0x800ULL | (0x1fffffff1ffULL 
                                       & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = (0x800000ULL | (0x1fffe7fffffULL 
                                          & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = (0x1ffffffefffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                } else if ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                } else if ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                            >> 0x1fU)) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                } else if ((0x40000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                    if ((0x20000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                        if ((0x10000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                        } else if ((0x8000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                        } else if ((0x4000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                        } else {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                                = (0x30000ULL | (0x1fffff8ffffULL 
                                                 & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                        }
                    } else {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                    }
                } else if ((0x20000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                    if ((0x10000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                    } else if ((0x8000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                    } else if ((0x4000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x10000ULL | (0x1fffff8ffffULL 
                                             & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                    } else if ((2U == (0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                >> 0x15U)))) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x20000ULL | (0x1fffff8ffffULL 
                                             & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                    } else if ((5U == (0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                >> 0x15U)))) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x40000ULL | (0x1fffff8ffffULL 
                                             & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                    } else {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                    }
                } else if ((0x10000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                } else if ((0x8000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                } else if ((0x4000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                } else if ((0U == (0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                            >> 0x15U)))) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = (0x170ULL | (0x1fffffffe0fULL 
                                       & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                    if ((3U == (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff))) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x160ULL | (0x1fffffffe1fULL 
                                           & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                    } else if ((1U == (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff))) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x120ULL | (0x1fffffffe1fULL 
                                           & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                    } else if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff))) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x100ULL | (0x1fffffffe1fULL 
                                           & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                    }
                } else if ((1U == (0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                            >> 0x15U)))) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = (0x70ULL | (0x1fffffffe0fULL 
                                      & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                } else {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                }
            } else if ((0x10U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                if ((8U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = (0x400ULL | (0x1fffffff1ffULL 
                                       & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = (0x1ffffff3fffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = (0x2000000000ULL | (0x1fffffffffULL 
                                              & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = (0xcULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                } else {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                }
            } else if ((8U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0x400ULL | (0x1fffffff1ffULL 
                                   & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0x8000ULL | (0x1ffffff3fffULL 
                                    & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0x2000000000ULL | (0x1fffffffffULL 
                                          & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0xcULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
            } else {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0x2000ULL | (0x1ffffff1fffULL 
                                    & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0x2000000000ULL | (0x1fffffffffULL 
                                          & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (2ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                if ((0x8000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = ((0x1fff1ffffffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl) 
                           | ((QData)((IData)(((0x4000U 
                                                & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                ? (
                                                   (0x2000U 
                                                    & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                    ? 4U
                                                    : 6U)
                                                : (
                                                   (0x2000U 
                                                    & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                    ? 3U
                                                    : 5U)))) 
                              << 0x19U));
                } else if ((0x4000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = (0x1fffffffffdULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                } else {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = ((0x1fff1ffffffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl) 
                           | ((QData)((IData)(((0x2000U 
                                                & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                ? 2U
                                                : 1U))) 
                              << 0x19U));
                }
            }
        } else {
            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
        }
    } else if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
        if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
            if ((0x10U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
            } else if ((8U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0x200ULL | (0x1fffffff1ffULL 
                                   & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0x1ffffffbfffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0x18000000000ULL | (0x1fffffffffULL 
                                           & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (8ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
            } else {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0x200ULL | (0x1fffffff1ffULL 
                                   & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0xe000ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (8ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                if ((0U == (0x7fU & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U] 
                                      << 6U) | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                >> 0x1aU))))) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = ((0x1fffffffffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl) 
                           | ((QData)((IData)(((0x8000U 
                                                & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                ? (
                                                   (0x4000U 
                                                    & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                    ? 
                                                   ((0x2000U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                     ? 3U
                                                     : 4U)
                                                    : 
                                                   ((0x2000U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                     ? 9U
                                                     : 5U))
                                                : (
                                                   (0x4000U 
                                                    & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                    ? 
                                                   ((0x2000U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                     ? 7U
                                                     : 6U)
                                                    : 
                                                   ((0x2000U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                     ? 8U
                                                     : 1U))))) 
                              << 0x25U));
                } else if ((0x20U == (0x7fU & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U] 
                                                << 6U) 
                                               | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                  >> 0x1aU))))) {
                    if ((0U == (7U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                      >> 0xdU)))) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x4000000000ULL | (0x1fffffffffULL 
                                                  & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                    } else if ((5U == (7U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                             >> 0xdU)))) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x14000000000ULL | (0x1fffffffffULL 
                                                   & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                    } else {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                    }
                } else if ((1U == (0x7fU & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U] 
                                             << 6U) 
                                            | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                               >> 0x1aU))))) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = (0xa00ULL | (0x1fffffff1ffULL 
                                       & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = ((0x1e1ffffffffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl) 
                           | ((QData)((IData)(((0x8000U 
                                                & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                ? (
                                                   (0x4000U 
                                                    & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                    ? 
                                                   ((0x2000U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                     ? 8U
                                                     : 7U)
                                                    : 
                                                   ((0x2000U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                     ? 6U
                                                     : 5U))
                                                : (
                                                   (0x4000U 
                                                    & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                    ? 
                                                   ((0x2000U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                     ? 4U
                                                     : 3U)
                                                    : 
                                                   ((0x2000U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                     ? 2U
                                                     : 1U))))) 
                              << 0x21U));
                } else {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                }
            }
        } else if ((0x10U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
            if ((8U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0x600ULL | (0x1fffffff1ffULL 
                                   & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0xc000ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0x170000000ULL | (0x1fe0fffffffULL 
                                         & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0x16000000000ULL | (0x1fffffffffULL 
                                           & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (8ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                if ((2U == (7U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                  >> 0xdU)))) {
                    if ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U])) {
                        if ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                             >> 0x1fU)) {
                            if ((0x40000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                                if ((0x20000000U & 
                                     vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                                } else if ((0x10000000U 
                                            & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                                } else {
                                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                                        = (0x580000ULL 
                                           | (0x1ffff87ffffULL 
                                              & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                                }
                            } else if ((0x20000000U 
                                        & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                            } else if ((0x10000000U 
                                        & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                            } else {
                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                                    = (0x500000ULL 
                                       | (0x1ffff87ffffULL 
                                          & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                            }
                        } else if ((0x40000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                            if ((0x20000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                            } else if ((0x10000000U 
                                        & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                            } else {
                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                                    = (0x480000ULL 
                                       | (0x1ffff87ffffULL 
                                          & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                            }
                        } else if ((0x20000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                        } else if ((0x10000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                        } else {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                                = (0x400000ULL | (0x1ffff87ffffULL 
                                                  & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                        }
                    } else if ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                >> 0x1fU)) {
                        if ((0x40000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                            if ((0x20000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                            } else if ((0x10000000U 
                                        & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                            } else {
                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                                    = (0x300000ULL 
                                       | (0x1ffff87ffffULL 
                                          & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                            }
                        } else if ((0x20000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                        } else if ((0x10000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                        } else {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                                = (0x380000ULL | (0x1ffff87ffffULL 
                                                  & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                        }
                    } else if ((0x40000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                        if ((0x20000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                        } else if ((0x10000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                        } else {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                                = (0x280000ULL | (0x1ffff87ffffULL 
                                                  & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                        }
                    } else if ((0x20000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                        if ((0x10000000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                                = (0x100000ULL | (0x1ffff87ffffULL 
                                                  & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                        } else {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                                = (0x80000ULL | (0x1ffff87ffffULL 
                                                 & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                            if ((0U != (0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                 >> 0x15U)))) {
                                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                            }
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                                = (0x1ffcfffffffULL 
                                   & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                        }
                    } else {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = ((0x1ffff87ffffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl) 
                               | ((QData)((IData)((
                                                   (0x10000000U 
                                                    & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                    ? 3U
                                                    : 4U))) 
                                  << 0x13U));
                    }
                } else {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                }
            } else {
                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
            }
        } else if ((8U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
        } else {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                = (0x8000ULL | (0x1ffffff3fffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                = (0x2000000000ULL | (0x1fffffffffULL 
                                      & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
            if ((0U == (7U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                              >> 0xdU)))) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0x10000000ULL | (0x1ffcfffffffULL 
                                        & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
            } else if ((1U == (7U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                     >> 0xdU)))) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0x20000000ULL | (0x1ffcfffffffULL 
                                        & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
            } else if ((2U == (7U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                     >> 0xdU)))) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0x30000000ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
            } else {
                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
            }
        }
    } else if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
        if ((0x10U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
        } else if ((8U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                = (0x200ULL | (0x1fffffff1ffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                = (0x1ffffff3fffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                = (0x2000000000ULL | (0x1fffffffffULL 
                                      & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                = (8ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
        } else {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                = (0x200ULL | (0x1fffffff1ffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                = (0x8000ULL | (0x1ffffff1fffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                = (8ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
            if ((0x8000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                if ((0x4000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = ((0x1fffffffffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl) 
                           | ((QData)((IData)(((0x2000U 
                                                & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                ? 3U
                                                : 4U))) 
                              << 0x25U));
                } else if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                    if ((0U == (0x7fU & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U] 
                                          << 6U) | 
                                         (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                          >> 0x1aU))))) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x12000000000ULL | (0x1fffffffffULL 
                                                   & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                    } else if ((0x20U == (0x7fU & (
                                                   (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U] 
                                                    << 6U) 
                                                   | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                      >> 0x1aU))))) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                            = (0x14000000000ULL | (0x1fffffffffULL 
                                                   & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                    } else {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                    }
                } else {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = (0xa000000000ULL | (0x1fffffffffULL 
                                              & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
                }
            } else {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = ((0x1fffffffffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl) 
                       | ((QData)((IData)(((0x4000U 
                                            & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                            ? ((0x2000U 
                                                & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                ? 7U
                                                : 6U)
                                            : ((0x2000U 
                                                & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                                ? 8U
                                                : 1U)))) 
                          << 0x25U));
            }
        }
    } else if ((0x10U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
        if ((8U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
            if ((0U != (7U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                              >> 0xdU)))) {
                if ((1U == (7U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                  >> 0xdU)))) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                        = (1ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
                } else {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
                }
            }
        } else {
            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
        }
    } else if ((8U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
    } else {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
            = (0x600ULL | (0x1fffffff1ffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
            = (0x8000ULL | (0x1ffffff3fffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
            = (0x2000000000ULL | (0x1fffffffffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
            = (8ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
        if ((0x8000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
            if ((0x4000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
            } else {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = ((0x1fe3fffffffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl) 
                       | ((QData)((IData)(((0x2000U 
                                            & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                            ? 4U : 2U))) 
                          << 0x1eU));
            }
        } else if ((0x4000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
            if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr = 1U;
            } else {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                    = (0x140000000ULL | (0x1fe3fffffffULL 
                                         & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
            }
        } else {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
                = ((0x1fe3fffffffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl) 
                   | ((QData)((IData)(((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])
                                        ? 3U : 1U))) 
                      << 0x1eU));
        }
    }
    if (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__illegal_instr) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
            = (0xffffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl 
            = (0x50ULL | (0x1fffffff000ULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl));
    }
    vlSelf->core_tb__DOT__dut__DOT__icache2if = ((1U 
                                                  & (IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2if_ff))
                                                  ? vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2if_ff
                                                  : 
                                                 (((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellout__icache_datapath__icache2if_data_o)) 
                                                   << 1U) 
                                                  | (QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellout__icache_controller_module__icache2if_ack_o))));
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__cache_rw = 0U;
    if ((0U != vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_d)) {
        if ((1U != vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_d)) {
            if ((2U == vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_d)) {
                if ((1U & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[0U])) {
                    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__cache_rw = 1U;
                }
            }
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_ctrl 
        = ((0xeU & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_ctrl)) 
           | (1U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                    >> 2U)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_ctrl 
        = ((0xeU & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_ctrl)) 
           | (1U & ((4U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))
                     ? ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))
                         ? (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                            >> 2U) : ((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state)) 
                                      | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                         >> 2U))) : (IData)(
                                                            (((0U 
                                                               == 
                                                               (3U 
                                                                & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))) 
                                                              & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                                                 >> 2U)) 
                                                             & (~ (IData)(
                                                                          (0U 
                                                                           != 
                                                                           (0xfU 
                                                                            & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                                                               >> 3U))))))))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[0U] 
        = (IData)((((QData)((IData)((0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                              >> 0xfU)))) 
                    << 0x20U) | (QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_result_ff))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[1U] 
        = ((0xffffffe0U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data[1U]) 
           | (IData)(((((QData)((IData)((0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                                  >> 0xfU)))) 
                        << 0x20U) | (QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_result_ff))) 
                      >> 0x20U)));
    if ((4U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))) {
        if ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__ld_req 
                = (1U & (0U != (7U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                      >> 9U))));
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__st_req 
                = (1U & (0U != (3U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                      >> 7U))));
        } else {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__ld_req 
                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state) 
                         & (0U != (7U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                         >> 9U)))));
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__st_req 
                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state) 
                         & (0U != (3U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                         >> 7U)))));
        }
    } else {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__ld_req 
            = (1U & ((~ ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state) 
                         >> 1U)) & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state) 
                                    | (IData)((0U != 
                                               (0xe78U 
                                                & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff))))));
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__st_req 
            = (1U & ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))
                      ? (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state)
                      : ((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state)) 
                         & ((~ (IData)((0U != (0xfU 
                                               & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                                  >> 3U))))) 
                            & (0U != (3U & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                                            >> 7U)))))));
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req = 0U;
    if ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff))) {
        if ((0x10000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
            if ((0x8000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                if ((0x4000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        if ((0x1000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                         >> 1U));
                        } else if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                         >> 1U));
                        } else if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                         >> 1U));
                        } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                    = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                             >> 1U));
                            } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                                 >> 1U));
                                } else if ((0x20U & 
                                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                                 >> 1U));
                                }
                            } else if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                    = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                             >> 1U));
                            } else if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                 >> 5U)))) {
                                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                    = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                             >> 1U));
                            }
                        } else {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                         >> 1U));
                        }
                    } else {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    }
                } else if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x1000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    }
                } else if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    }
                }
            } else if ((0x4000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x1000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                         >> 1U));
                        } else if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                         >> 1U));
                        } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                         >> 1U));
                        } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                         >> 1U));
                        } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                         >> 1U));
                        } else if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                    = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                             >> 1U));
                            }
                        } else if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                         >> 1U));
                        }
                    } else if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                         >> 1U));
                        }
                    } else if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    }
                } else {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                }
            } else {
                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                    = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                             >> 1U));
            }
        } else if ((0x8000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                         >> 1U));
        } else if ((0x4000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
            if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                if ((0x1000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                         >> 1U));
                        } else if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                         >> 1U));
                        }
                    }
                } else if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    }
                } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                         >> 1U));
                        }
                    }
                }
            } else {
                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                    = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                             >> 1U));
            }
        } else if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
            if ((0x1000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if (((1U == (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff)) 
                            & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff 
                               >> 0x14U))) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req = 1U;
                }
            } else if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    } else if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                            = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                     >> 1U));
                    }
                }
            } else if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                    = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                             >> 1U));
            } else if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                    = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                             >> 1U));
            } else if ((0x100U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                    = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                             >> 1U));
            } else if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 1U));
                }
            } else if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                    = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                             >> 1U));
            } else if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                    = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                             >> 1U));
            }
        } else {
            core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req 
                = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                         >> 1U));
        }
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_ff;
    if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_req) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_next = 0U;
    } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_req) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_next = 1U;
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_he4191b8e__0 
        = ((~ (IData)((0x84U == (0x84U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_ff)))) 
           & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__st_req));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgExtracted_h09503d11__0 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__ld_req) 
           | (IData)(((0U != (0x78U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff)) 
                      | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__st_req))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT____VdfgTmp_h1ec46b79__0 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__ld_req) 
           | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__st_req));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_exc_req 
        = ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req) 
           | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_exc_req) 
              | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_csr_mul_read_req 
        = (1U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgExtracted_h09503d11__0) 
                 | (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                     >> 1U) | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_req_ff))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U] 
        = (0xfffffff9U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U]);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[0U] 
        = (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw2mmu);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U] 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__st_req)
            ? ((0xfffffffdU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U]) 
               | (2U & ((IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw2mmu 
                                 >> 0x21U)) << 1U)))
            : (((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__st_req)) 
                & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT____VdfgTmp_h1ec46b79__0))
                ? ((0xfffffffbU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U]) 
                   | (4U & ((IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw2mmu 
                                     >> 0x21U)) << 2U)))
                : ((0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu[1U]) 
                   | (1U & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw2mmu 
                                    >> 0x21U))))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb2mmu = 0ULL;
    if ((((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT____VdfgTmp_h1ec46b79__0) 
          & (((0x35fU >= ((IData)(0x2cU) + (0x3ffU 
                                            & ((IData)(0x36U) 
                                               * (0xfU 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                     >> 0x16U))))))
               ? (0x3ffU & (((0U == (0x1fU & ((IData)(0x2cU) 
                                              + (0x3ffU 
                                                 & ((IData)(0x36U) 
                                                    * 
                                                    (0xfU 
                                                     & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                        >> 0x16U)))))))
                              ? 0U : (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[
                                      (((IData)(0x35U) 
                                        + (0x3ffU & 
                                           ((IData)(0x36U) 
                                            * (0xfU 
                                               & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                  >> 0x16U))))) 
                                       >> 5U)] << ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x2cU) 
                                                       + 
                                                       (0x3ffU 
                                                        & ((IData)(0x36U) 
                                                           * 
                                                           (0xfU 
                                                            & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                               >> 0x16U))))))))) 
                            | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[
                               (((IData)(0x2cU) + (0x3ffU 
                                                   & ((IData)(0x36U) 
                                                      * 
                                                      (0xfU 
                                                       & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                          >> 0x16U))))) 
                                >> 5U)] >> (0x1fU & 
                                            ((IData)(0x2cU) 
                                             + (0x3ffU 
                                                & ((IData)(0x36U) 
                                                   * 
                                                   (0xfU 
                                                    & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                       >> 0x16U)))))))))
               : 0U) == (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                         >> 0x16U))) & ((0x35fU >= 
                                         ((IData)(0x21U) 
                                          + (0x3ffU 
                                             & ((IData)(0x36U) 
                                                * (0xfU 
                                                   & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                      >> 0x16U)))))) 
                                        & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[
                                           (((IData)(0x21U) 
                                             + (0x3ffU 
                                                & ((IData)(0x36U) 
                                                   * 
                                                   (0xfU 
                                                    & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                       >> 0x16U))))) 
                                            >> 5U)] 
                                           >> (0x1fU 
                                               & ((IData)(0x21U) 
                                                  + 
                                                  (0x3ffU 
                                                   & ((IData)(0x36U) 
                                                      * 
                                                      (0xfU 
                                                       & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                          >> 0x16U)))))))))) {
        if (((((0x35fU >= ((IData)(0x22U) + (0x3ffU 
                                             & ((IData)(0x36U) 
                                                * (0xfU 
                                                   & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                      >> 0x16U))))))
                ? (0x3ffU & (((0U == (0x1fU & ((IData)(0x22U) 
                                               + (0x3ffU 
                                                  & ((IData)(0x36U) 
                                                     * 
                                                     (0xfU 
                                                      & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                         >> 0x16U)))))))
                               ? 0U : (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[
                                       (((IData)(0x2bU) 
                                         + (0x3ffU 
                                            & ((IData)(0x36U) 
                                               * (0xfU 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                     >> 0x16U))))) 
                                        >> 5U)] << 
                                       ((IData)(0x20U) 
                                        - (0x1fU & 
                                           ((IData)(0x22U) 
                                            + (0x3ffU 
                                               & ((IData)(0x36U) 
                                                  * 
                                                  (0xfU 
                                                   & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                      >> 0x16U))))))))) 
                             | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[
                                (((IData)(0x22U) + 
                                  (0x3ffU & ((IData)(0x36U) 
                                             * (0xfU 
                                                & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                   >> 0x16U))))) 
                                 >> 5U)] >> (0x1fU 
                                             & ((IData)(0x22U) 
                                                + (0x3ffU 
                                                   & ((IData)(0x36U) 
                                                      * 
                                                      (0xfU 
                                                       & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                          >> 0x16U)))))))))
                : 0U) == (0x3ffU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                    >> 0xcU))) | ((0x35fU 
                                                   >= 
                                                   ((IData)(0x20U) 
                                                    + 
                                                    (0x3ffU 
                                                     & ((IData)(0x36U) 
                                                        * 
                                                        (0xfU 
                                                         & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                            >> 0x16U)))))) 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[
                                                     (((IData)(0x20U) 
                                                       + 
                                                       (0x3ffU 
                                                        & ((IData)(0x36U) 
                                                           * 
                                                           (0xfU 
                                                            & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                               >> 0x16U))))) 
                                                      >> 5U)] 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(0x20U) 
                                                         + 
                                                         (0x3ffU 
                                                          & ((IData)(0x36U) 
                                                             * 
                                                             (0xfU 
                                                              & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                                 >> 0x16U)))))))))) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb2mmu 
                = ((3ULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb2mmu) 
                   | ((QData)((IData)(((0x35fU >= (0x3ffU 
                                                   & ((IData)(0x36U) 
                                                      * 
                                                      (0xfU 
                                                       & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                          >> 0x16U)))))
                                        ? (((0U == 
                                             (0x1fU 
                                              & ((IData)(0x36U) 
                                                 * 
                                                 (0xfU 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                     >> 0x16U)))))
                                             ? 0U : 
                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[
                                             (((IData)(0x1fU) 
                                               + (0x3ffU 
                                                  & ((IData)(0x36U) 
                                                     * 
                                                     (0xfU 
                                                      & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                         >> 0x16U))))) 
                                              >> 5U)] 
                                             << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & ((IData)(0x36U) 
                                                     * 
                                                     (0xfU 
                                                      & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                         >> 0x16U))))))) 
                                           | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[
                                              (0x1fU 
                                               & (((IData)(0x36U) 
                                                   * 
                                                   (0xfU 
                                                    & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                       >> 0x16U))) 
                                                  >> 5U))] 
                                              >> (0x1fU 
                                                  & ((IData)(0x36U) 
                                                     * 
                                                     (0xfU 
                                                      & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                         >> 0x16U))))))
                                        : 0U))) << 2U));
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb2mmu 
                = (2ULL | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb2mmu);
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb2mmu 
                = ((0x3fffffffeULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb2mmu) 
                   | (IData)((IData)(((0x35fU >= ((IData)(0x20U) 
                                                  + 
                                                  (0x3ffU 
                                                   & ((IData)(0x36U) 
                                                      * 
                                                      (0xfU 
                                                       & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                          >> 0x16U)))))) 
                                      & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff[
                                         (((IData)(0x20U) 
                                           + (0x3ffU 
                                              & ((IData)(0x36U) 
                                                 * 
                                                 (0xfU 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                     >> 0x16U))))) 
                                          >> 5U)] >> 
                                         (0x1fU & ((IData)(0x20U) 
                                                   + 
                                                   (0x3ffU 
                                                    & ((IData)(0x36U) 
                                                       * 
                                                       (0xfU 
                                                        & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U] 
                                                           >> 0x16U)))))))))));
        }
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2exe 
        = (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgTmp_h140467bf__0) 
            << 3U) | (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgTmp_hb3ea78f5__0) 
                       << 2U) | ((((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_csr_mul_read_req)) 
                                   & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu2rs1_hazard)) 
                                  << 1U) | ((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_csr_mul_read_req)) 
                                            & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu2rs2_hazard)))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__operand_rs1_data 
        = ((2U & (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2exe))
            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U]
            : ((8U & (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2exe))
                ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__writeback_module__DOT__wrb_rd_data
                : ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[6U] 
                    << 0x1fU) | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[5U] 
                                 >> 1U))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__operand_rs2_data 
        = ((1U & (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2exe))
            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff[2U]
            : ((4U & (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2exe))
                ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__writeback_module__DOT__wrb_rd_data
                : ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[5U] 
                    << 0x1fU) | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[4U] 
                                 >> 1U))));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1 
        = ((1U & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                          >> 0xfU))) ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__operand_rs1_data
            : ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[3U] 
                << 0x1fU) | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[2U] 
                             >> 1U)));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2 
        = ((1U & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                          >> 0xeU))) ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__operand_rs2_data
            : ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[1U] 
                << 0x1fU) | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[0U] 
                             >> 1U)));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_operand_2 
        = ((1U & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                          >> 0xdU))) ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__operand_rs2_data
            : ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[1U] 
                << 0x1fU) | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff[0U] 
                             >> 1U)));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT____VdfgExtracted_h5df1bfaf__0 
        = ((QData)((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1)) 
           * (QData)((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2)));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_adder_output 
        = ((1U == (0xfU & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                   >> 0x25U)))) ? (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1 
                                                   + core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2)
            : (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1 
               - core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_output 
        = (0x1ffffffffULL & ((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__operand_rs1_data)) 
                             - (QData)((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_operand_2))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_result_next 
        = ((1U & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                          >> 0x24U))) ? ((1U & (IData)(
                                                       (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                        >> 0x23U)))
                                          ? 0U : ((1U 
                                                   & (IData)(
                                                             (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                              >> 0x22U)))
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & (IData)(
                                                              (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                               >> 0x21U)))
                                                    ? 0U
                                                    : 
                                                   VL_MODDIV_III(32, core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1, core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2))))
            : ((1U & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                              >> 0x23U))) ? ((1U & (IData)(
                                                           (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                            >> 0x22U)))
                                              ? ((1U 
                                                  & (IData)(
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                             >> 0x21U)))
                                                  ? 
                                                 VL_MODDIVS_III(32, core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1, core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2)
                                                  : 
                                                 VL_DIV_III(32, core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1, core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2))
                                              : ((1U 
                                                  & (IData)(
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                             >> 0x21U)))
                                                  ? 
                                                 VL_DIVS_III(32, core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1, core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2)
                                                  : (IData)(
                                                            (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT____VdfgExtracted_h5df1bfaf__0 
                                                             >> 0x20U))))
                : ((1U & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                  >> 0x22U))) ? ((1U 
                                                  & (IData)(
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                             >> 0x21U)))
                                                  ? (IData)(
                                                            (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT____VdfgExtracted_h5df1bfaf__0 
                                                             >> 0x20U))
                                                  : (IData)(
                                                            (VL_MULS_QQQ(64, 
                                                                         VL_EXTENDS_QI(64,32, core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1), 
                                                                         VL_EXTENDS_QI(64,32, core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2)) 
                                                             >> 0x20U)))
                    : ((1U & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                      >> 0x21U))) ? (IData)(
                                                            VL_MULS_QQQ(64, 
                                                                        VL_EXTENDS_QI(64,32, core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1), 
                                                                        VL_EXTENDS_QI(64,32, core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2)))
                        : 0U))));
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_overflow 
        = (1U & (((IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_output 
                           >> 0x1fU)) & ((~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__operand_rs1_data 
                                             >> 0x1fU)) 
                                         & (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_operand_2 
                                            >> 0x1fU))) 
                 | ((~ (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_output 
                                >> 0x1fU))) & ((~ (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_operand_2 
                                                   >> 0x1fU)) 
                                               & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__operand_rs1_data 
                                                  >> 0x1fU)))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_result 
        = ((1U & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                          >> 0x28U))) ? ((1U & (IData)(
                                                       (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                        >> 0x27U)))
                                          ? ((1U & (IData)(
                                                           (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                            >> 0x26U)))
                                              ? 0U : 
                                             ((1U & (IData)(
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                             >> 0x25U)))
                                               ? 0U
                                               : core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2))
                                          : ((1U & (IData)(
                                                           (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                            >> 0x26U)))
                                              ? ((1U 
                                                  & (IData)(
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                             >> 0x25U)))
                                                  ? core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1
                                                  : 
                                                 VL_SHIFTRS_III(32,32,5, core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1, 
                                                                (0x1fU 
                                                                 & core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2)))
                                              : ((1U 
                                                  & (IData)(
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                             >> 0x25U)))
                                                  ? 
                                                 (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1 
                                                  >> 
                                                  (0x1fU 
                                                   & core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2))
                                                  : 
                                                 (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1 
                                                  << 
                                                  (0x1fU 
                                                   & core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2)))))
            : ((1U & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                              >> 0x27U))) ? ((1U & (IData)(
                                                           (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                            >> 0x26U)))
                                              ? ((1U 
                                                  & (IData)(
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                             >> 0x25U)))
                                                  ? 
                                                 (1U 
                                                  & (IData)(
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_output 
                                                             >> 0x20U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(
                                                             (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_output 
                                                              >> 0x1fU))) 
                                                  ^ (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_overflow)))
                                              : ((1U 
                                                  & (IData)(
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                             >> 0x25U)))
                                                  ? 
                                                 (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1 
                                                  ^ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2)
                                                  : 
                                                 (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1 
                                                  | core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2)))
                : ((1U & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                  >> 0x26U))) ? ((1U 
                                                  & (IData)(
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                                             >> 0x25U)))
                                                  ? 
                                                 (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_1 
                                                  & core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_operand_2)
                                                  : core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_adder_output)
                    : ((1U & (IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff 
                                      >> 0x25U))) ? core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_adder_output
                        : 0U))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT____VdfgExtracted_h0362d37b__0 
        = (1U & ((IData)((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_output 
                          >> 0x1fU)) ^ (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_overflow)));
}

VL_INLINE_OPT void Vcore_tb___024root___nba_comb__TOP__4(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_comb__TOP__4\n"); );
    // Body
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U] 
        = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U]) 
           | (0xfffffffeU & (((- (IData)((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U]))) 
                              << 0xcU) | (0xffeU & 
                                          (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                           >> 0x14U)))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U] 
        = ((0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U]) 
           | (1U & ((- (IData)((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U]))) 
                    >> 0x14U)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[2U] 
        = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[2U]) 
           | (0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[1U]));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[3U] 
        = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U]) 
           | (0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U]));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[4U] 
        = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U]) 
           | ((IData)((((QData)((IData)(((0U != (0x1fU 
                                                 & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                    >> 0x10U)))
                                          ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file
                                         [(0x1fU & 
                                           (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                            >> 0x10U))]
                                          : 0U))) << 0x20U) 
                       | (QData)((IData)(((0U != (0x1fU 
                                                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                     >> 0x15U)))
                                           ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file
                                          [(0x1fU & 
                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                             >> 0x15U))]
                                           : 0U))))) 
              << 1U));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[5U] 
        = (((IData)((((QData)((IData)(((0U != (0x1fU 
                                               & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                  >> 0x10U)))
                                        ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file
                                       [(0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                  >> 0x10U))]
                                        : 0U))) << 0x20U) 
                     | (QData)((IData)(((0U != (0x1fU 
                                                & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                   >> 0x15U)))
                                         ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file
                                        [(0x1fU & (
                                                   vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                   >> 0x15U))]
                                         : 0U))))) 
            >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                    ((0U 
                                                      != 
                                                      (0x1fU 
                                                       & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                          >> 0x10U)))
                                                      ? 
                                                     vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file
                                                     [
                                                     (0x1fU 
                                                      & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                         >> 0x10U))]
                                                      : 0U))) 
                                    << 0x20U) | (QData)((IData)(
                                                                ((0U 
                                                                  != 
                                                                  (0x1fU 
                                                                   & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                                      >> 0x15U)))
                                                                  ? 
                                                                 vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file
                                                                 [
                                                                 (0x1fU 
                                                                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                                     >> 0x15U))]
                                                                  : 0U)))) 
                                  >> 0x20U)) << 1U));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[6U] 
        = ((IData)(((((QData)((IData)(((0U != (0x1fU 
                                               & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                  >> 0x10U)))
                                        ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file
                                       [(0x1fU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                  >> 0x10U))]
                                        : 0U))) << 0x20U) 
                     | (QData)((IData)(((0U != (0x1fU 
                                                & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                   >> 0x15U)))
                                         ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file
                                        [(0x1fU & (
                                                   vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                   >> 0x15U))]
                                         : 0U)))) >> 0x20U)) 
           >> 0x1fU);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U] 
        = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U]) 
           | (0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[0U]));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[2U] 
        = ((0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[2U]) 
           | (1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[1U]));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U] 
        = ((0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U]) 
           | (1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[0U]));
    if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_ctrl_pipe_ff)))) {
        if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
            if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                              >> 5U)))) {
                    if ((0x10U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                        if ((8U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U] 
                                = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U]) 
                                   | (0xfffffffeU & 
                                      (((- (IData)(
                                                   (1U 
                                                    & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U]))) 
                                        << 0x15U) | 
                                       ((0x1fe000U 
                                         & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U]) 
                                        | ((0x1000U 
                                            & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                               >> 9U)) 
                                           | (0xffcU 
                                              & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                 >> 0x14U)))))));
                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U] 
                                = ((0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U]) 
                                   | (1U & ((- (IData)(
                                                       (1U 
                                                        & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U]))) 
                                            >> 0xbU)));
                        }
                    } else if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                         >> 3U)))) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U] 
                            = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U]) 
                               | (0xfffffffeU & (((- (IData)(
                                                             (1U 
                                                              & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U]))) 
                                                  << 0xdU) 
                                                 | ((0x1000U 
                                                     & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                        << 4U)) 
                                                    | ((0xfc0U 
                                                        & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                           >> 0x14U)) 
                                                       | (0x3cU 
                                                          & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                             >> 7U)))))));
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U] 
                            = ((0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U]) 
                               | (1U & ((- (IData)(
                                                   (1U 
                                                    & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U]))) 
                                        >> 0x13U)));
                    }
                }
            }
        } else if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
            if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                              >> 4U)))) {
                    if ((8U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U] 
                            = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U]) 
                               | (0xffffe000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U]));
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U] 
                            = ((0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U]) 
                               | (1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U]));
                    }
                }
            } else if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                 >> 4U)))) {
                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                              >> 3U)))) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U] 
                        = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U]) 
                           | (0xfffffffeU & (((- (IData)(
                                                         (1U 
                                                          & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U]))) 
                                              << 0xcU) 
                                             | ((0xfc0U 
                                                 & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                    >> 0x14U)) 
                                                | (0x3eU 
                                                   & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                      >> 7U))))));
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U] 
                        = ((0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U]) 
                           | (1U & ((- (IData)((1U 
                                                & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U]))) 
                                    >> 0x14U)));
                }
            }
        } else if ((0x20U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                          >> 4U)))) {
                if ((8U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U] 
                        = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U]) 
                           | (0xffffe000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U]));
                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U] 
                        = ((0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U]) 
                           | (1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U]));
                } else if ((0x8000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                  >> 0xeU)))) {
                        if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                            if ((0U == (0x7fU & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U] 
                                                  << 6U) 
                                                 | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                    >> 0x1aU))))) {
                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U] 
                                    = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U]) 
                                       | (0x3eU & (
                                                   vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                   >> 0x14U)));
                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U] 
                                    = (0xfffffffeU 
                                       & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U]);
                            } else if ((0x20U == (0x7fU 
                                                  & ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[3U] 
                                                      << 6U) 
                                                     | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                        >> 0x1aU))))) {
                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U] 
                                    = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U]) 
                                       | (0x3eU & (
                                                   vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                                   >> 0x14U)));
                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U] 
                                    = (0xfffffffeU 
                                       & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U]);
                            }
                        }
                    }
                } else if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                     >> 0xeU)))) {
                    if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U])) {
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U] 
                            = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[0U]) 
                               | (0x3eU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff[2U] 
                                           >> 0x14U)));
                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U] 
                            = (0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data[1U]);
                    }
                }
            }
        }
    }
}
