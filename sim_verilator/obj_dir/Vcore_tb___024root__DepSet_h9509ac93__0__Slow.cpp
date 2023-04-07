// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcore_tb.h for the primary calling header

#include "verilated.h"

#include "Vcore_tb___024root.h"

VL_ATTR_COLD void Vcore_tb___024root___eval_static__TOP(Vcore_tb___024root* vlSelf);

VL_ATTR_COLD void Vcore_tb___024root___eval_static(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___eval_static\n"); );
    // Body
    Vcore_tb___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vcore_tb___024root___eval_static__TOP(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->core_tb__DOT__flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__sample_count_next = 0U;
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_next = 0U;
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__sample_count_next = 0U;
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_next = 0U;
}

VL_ATTR_COLD void Vcore_tb___024root___eval_initial__TOP(Vcore_tb___024root* vlSelf);

VL_ATTR_COLD void Vcore_tb___024root___eval_initial(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___eval_initial\n"); );
    // Body
    Vcore_tb___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigrprev__TOP__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_result_o 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_result_o;
    vlSelf->__Vtrigrprev__TOP__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_exc_req 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_exc_req;
    vlSelf->__Vtrigrprev__TOP__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_exc_req 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_exc_req;
    vlSelf->__Vtrigrprev__TOP__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_delegated_req 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_delegated_req;
    vlSelf->__Vtrigrprev__TOP__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__en_ld_st_vaddr_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__en_ld_st_vaddr_next;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__core_tb__DOT__reset 
        = vlSelf->core_tb__DOT__reset;
    vlSelf->__Vtrigrprev__TOP__core_tb__DOT__dut__DOT__clint_module__DOT__timer_clk_ff 
        = vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_clk_ff;
    vlSelf->__Vtrigrprev__TOP__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellinp__icache_datapath__icache_flush 
        = vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellinp__icache_datapath__icache_flush;
}

VL_ATTR_COLD void Vcore_tb___024root___eval_initial__TOP(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_h21e0221c__0;
    VlWide<4>/*127:0*/ __Vtemp_h6ad9d9f9__0;
    // Body
    vlSelf->core_tb__DOT__irq_soft = 0U;
    vlSelf->core_tb__DOT__uart_rx = 1U;
    VL_WRITEF("Start of simulation\n");
    vlSelf->core_tb__DOT__loop_count = 0ULL;
    __Vtemp_h21e0221c__0[0U] = 0x2e747874U;
    __Vtemp_h21e0221c__0[1U] = 0x64617461U;
    __Vtemp_h21e0221c__0[2U] = 0x5f6c6f67U;
    __Vtemp_h21e0221c__0[3U] = 0x72616365U;
    __Vtemp_h21e0221c__0[4U] = 0x74U;
    vlSelf->core_tb__DOT__tracelog_filepointer = VL_FOPEN_NN(
                                                             VL_CVT_PACK_STR_NW(5, __Vtemp_h21e0221c__0)
                                                             , 
                                                             std::string{"w"});
    ;
    __Vtemp_h6ad9d9f9__0[0U] = 0x2e747874U;
    __Vtemp_h6ad9d9f9__0[1U] = 0x64617461U;
    __Vtemp_h6ad9d9f9__0[2U] = 0x5f6c6f67U;
    __Vtemp_h6ad9d9f9__0[3U] = 0x75617274U;
    vlSelf->core_tb__DOT__uartlog_filepointer = VL_FOPEN_NN(
                                                            VL_CVT_PACK_STR_NW(4, __Vtemp_h6ad9d9f9__0)
                                                            , 
                                                            std::string{"w"});
    ;
    VL_READMEM_N(true, 32, 4096, 0, std::string{"bmem.txt"}
                 ,  &(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 32, 33554432, 0, std::string{"imem.txt"}
                 ,  &(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vcore_tb___024root___eval_final(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vcore_tb___024root___eval_triggers__stl(Vcore_tb___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcore_tb___024root___dump_triggers__stl(Vcore_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vcore_tb___024root___eval_stl(Vcore_tb___024root* vlSelf);

VL_ATTR_COLD void Vcore_tb___024root___eval_settle(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vcore_tb___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vcore_tb___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("../rtl/tb/core_tb.sv", 12, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vcore_tb___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcore_tb___024root___dump_triggers__stl(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
    if (vlSelf->__VstlTriggered.at(1U)) {
        VL_DBG_MSGF("         'stl' region trigger index 1 is active: @([hybrid] core_tb.dut.pipeline_top_module.lsu_module.amo_result_o)\n");
    }
    if (vlSelf->__VstlTriggered.at(2U)) {
        VL_DBG_MSGF("         'stl' region trigger index 2 is active: @([hybrid] core_tb.dut.pipeline_top_module.csr_module.s_mode_exc_req or [hybrid] core_tb.dut.pipeline_top_module.csr_module.m_mode_exc_req)\n");
    }
    if (vlSelf->__VstlTriggered.at(3U)) {
        VL_DBG_MSGF("         'stl' region trigger index 3 is active: @([hybrid] core_tb.dut.pipeline_top_module.csr_module.s_mode_exc_req)\n");
    }
    if (vlSelf->__VstlTriggered.at(4U)) {
        VL_DBG_MSGF("         'stl' region trigger index 4 is active: @([hybrid] core_tb.dut.pipeline_top_module.csr_module.m_mode_exc_req)\n");
    }
    if (vlSelf->__VstlTriggered.at(5U)) {
        VL_DBG_MSGF("         'stl' region trigger index 5 is active: @([hybrid] core_tb.dut.pipeline_top_module.csr_module.exc_delegated_req)\n");
    }
    if (vlSelf->__VstlTriggered.at(6U)) {
        VL_DBG_MSGF("         'stl' region trigger index 6 is active: @([hybrid] core_tb.dut.pipeline_top_module.csr_module.en_ld_st_vaddr_next)\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*0:0*/, 256> Vcore_tb__ConstPool__TABLE_h6ea4d6b0_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vcore_tb__ConstPool__TABLE_h04823f0d_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vcore_tb__ConstPool__TABLE_h23aae2ab_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vcore_tb__ConstPool__TABLE_hafc97858_0;
extern const VlUnpacked<CData/*3:0*/, 64> Vcore_tb__ConstPool__TABLE_h5ad03769_0;

VL_ATTR_COLD void Vcore_tb___024root___stl_sequent__TOP__0(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2exe;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2exe = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_misaligned;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_misaligned = 0;
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
    IData/*31:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sip_mask;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sip_mask = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_irq_req;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_irq_req = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__meip_irq_req;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__meip_irq_req = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mtip_irq_req;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mtip_irq_req = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__msip_irq_req;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__msip_irq_req = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_inc;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_inc = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_inc;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_inc = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__satp_mode;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__satp_mode = 0;
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
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*5:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
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
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_baud_next 
        = vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_baud_ff;
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__cache_rw = 0U;
    if ((0U != vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_d)) {
        if ((1U == vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_d)) {
            vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellout__icache_controller_module__icache2imem_request_o = 1U;
        }
        if ((1U != vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_d)) {
            if ((2U == vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_d)) {
                if ((1U & vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff[0U])) {
                    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__cache_rw = 1U;
                }
            }
        }
    }
    if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state))) {
        if (((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__tx_valid_ff) 
             & (0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_ff)))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state_next = 1U;
        }
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__sample_count_next = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_next = 0U;
    } else {
        if ((1U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state))) {
            if ((0U != (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_ff))) {
                vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state_next = 2U;
            }
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_next = 0xbU;
        } else if ((2U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state))) {
            if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_ff))) {
                vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state_next = 0U;
            }
            if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__sample_count_ff))) {
                vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_next 
                    = (0xfU & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_ff) 
                               - (IData)(1U)));
            }
        } else {
            vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state_next = 0U;
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
    if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state))) {
        if (((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__tx_valid_ff) 
             & (0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_ff)))) {
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state_next = 1U;
        }
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__sample_count_next = 0U;
        vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_next = 0U;
    } else {
        if ((1U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state))) {
            if ((0U != (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_ff))) {
                vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state_next = 2U;
            }
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_next = 0xbU;
        } else if ((2U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state))) {
            if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_ff))) {
                vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state_next = 0U;
            }
            if ((0U == (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__sample_count_ff))) {
                vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_next 
                    = (0xfU & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_ff) 
                               - (IData)(1U)));
            }
        } else {
            vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state_next = 0U;
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
    vlSelf->core_tb__DOT__dut__DOT__core2pipe = (QData)((IData)(
                                                                (((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_req_ff) 
                                                                  << 3U) 
                                                                 | (((IData)(vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_overflow_ff) 
                                                                     << 2U) 
                                                                    | ((IData)(vlSelf->core_tb__DOT__irq_soft) 
                                                                       << 1U)))));
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rx_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__valid_ff)
            ? (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__shifter_ff)
            : (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rx_ff));
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_rx_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__valid_ff)
            ? (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__shifter_ff)
            : (IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_rx_ff));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__gmap_bit_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__gmap_bit_ff;
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
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_ctrl 
        = ((1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_ctrl)) 
           | (0xeU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff 
                      >> 0xbU)));
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
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sscratch_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mscratch_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcounteren_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcountinhibit_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_medeleg_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_wr_flag = 0U;
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
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sie_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_wr_flag = 0U;
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
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sepc_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mepc_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcause_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtval_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stval_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_wr_flag = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sip_wr_flag = 0U;
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
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_wr_flag = 0U;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_misaligned 
        = (IData)((0U != (3U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_ff)));
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
    core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sbit_mid_point 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sbit_sample_count_ff) 
           == (7U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_baud_ff) 
                     >> 1U)));
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
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT____Vcellinp__plic_regs_module__claim_idx_i 
        = (((IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__1__KET____DOT__plic_target_module__DOT__irq_idx_ff) 
            << 2U) | (IData)(vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_idx_ff));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_wr_flag = 0U;
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
    vlSelf->core_tb__DOT__dut__DOT__icache2if = ((1U 
                                                  & (IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2if_ff))
                                                  ? vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2if_ff
                                                  : 
                                                 (((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellout__icache_datapath__icache2if_data_o)) 
                                                   << 1U) 
                                                  | (QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellout__icache_controller_module__icache2if_ack_o))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_exc_req = 0U;
    if (((1U == (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff)) 
         & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff 
            >> 0x14U))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_exc_req = 1U;
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__mul_stall_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__mul_stall_ff;
    if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_ack_ff_ff) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__mul_stall_next = 0U;
    } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_req_ff) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__mul_stall_next = 1U;
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_done = 0U;
    if ((4U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state))) {
        if ((1U & (~ ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state)))) {
                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_done = 1U;
            }
        }
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
        = ((0xf00000000ULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw2mmu) 
           | (IData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_ff)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw2mmu 
        = ((0x3ffffffffULL & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw2mmu) 
           | ((QData)((IData)((((0U != (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff)) 
                                << 1U) | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__iwalk_active_ff)))) 
              << 0x22U));
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
    vlSelf->core_tb__DOT__dut__DOT__clint2csr = (((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtime_ff)) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   (vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtime_ff 
                                                                    >> 0x20U))));
    __Vtableidx1 = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sret_req 
        = Vcore_tb__ConstPool__TABLE_h6ea4d6b0_0[__Vtableidx1];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mret_req 
        = Vcore_tb__ConstPool__TABLE_h04823f0d_0[__Vtableidx1];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_req 
        = Vcore_tb__ConstPool__TABLE_h23aae2ab_0[__Vtableidx1];
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sfence_vma_req 
        = Vcore_tb__ConstPool__TABLE_hafc97858_0[__Vtableidx1];
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
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__exc_code = 0xaU;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__exc_req = 0U;
    if (core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_misaligned) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__exc_code = 0U;
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__exc_req = 1U;
    }
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
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_exc_req 
        = ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rd_exc_req) 
           | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_exc_req) 
              | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__wrb2id_fb 
        = (((QData)((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__writeback_module__DOT__wrb_rd_data)) 
            << 6U) | (QData)((IData)(((0x3eU & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff[1U] 
                                                << 1U)) 
                                      | (1U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_pipe_ff))))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata = 0U;
    if ((2U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff))) {
        if ((0x10000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
            if ((0x8000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                if ((0x4000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                      >> 0xcU)))) {
                            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                          >> 0xbU)))) {
                                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                              >> 0xaU)))) {
                                    if ((0x200U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
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
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                             >> 5U)))) {
                                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata = 0U;
                                                    }
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                            >> 6U)))) {
                                                if (
                                                    (0x20U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata = 0U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                     >> 0xdU)))) {
                    if ((0x1000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                      >> 0xbU)))) {
                            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                          >> 0xaU)))) {
                                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                              >> 9U)))) {
                                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                  >> 8U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                    >> 7U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                     >> 6U)))) {
                                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                                    = 
                                                    ((0x20U 
                                                      & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])
                                                      ? (IData)(vlSelf->core_tb__DOT__dut__DOT__clint2csr)
                                                      : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_ff);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                         >> 0xbU)))) {
                        if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                      >> 0xaU)))) {
                            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                          >> 9U)))) {
                                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                              >> 8U)))) {
                                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                  >> 7U)))) {
                                        if ((0x40U 
                                             & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                     >> 5U)))) {
                                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                                    = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_ff;
                                            }
                                        } else {
                                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                                = (
                                                   (0x20U 
                                                    & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])
                                                    ? (IData)(
                                                              (vlSelf->core_tb__DOT__dut__DOT__clint2csr 
                                                               >> 0x20U))
                                                    : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_ff);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else if ((0x4000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((0x1000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                        if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                      >> 0xbU)))) {
                            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                          >> 0xaU)))) {
                                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                              >> 9U)))) {
                                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                  >> 8U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                    >> 7U)))) {
                                            if ((0x40U 
                                                 & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                         >> 5U)))) {
                                                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                                        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_ff;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                            >> 5U)))) {
                                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                                    = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_ff;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                         >> 0xbU)))) {
                        if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                      >> 0xaU)))) {
                            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                          >> 9U)))) {
                                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                              >> 8U)))) {
                                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                  >> 7U)))) {
                                        if ((0x40U 
                                             & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                     >> 5U)))) {
                                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                                    = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_ff;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                        >> 5U)))) {
                                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                                = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_ff;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                             >> 0xfU)))) {
            if ((0x4000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                  >> 0xcU)))) {
                        if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                          >> 0xaU)))) {
                                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                              >> 9U)))) {
                                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                  >> 8U)))) {
                                        if ((0x80U 
                                             & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                     >> 6U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                         >> 5U)))) {
                                                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                                        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_ff;
                                                }
                                            }
                                        } else {
                                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                                = (
                                                   (0x40U 
                                                    & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])
                                                    ? 
                                                   ((0x20U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])
                                                     ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtval_ff
                                                     : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcause_ff)
                                                    : 
                                                   ((0x20U 
                                                     & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])
                                                     ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mepc_ff
                                                     : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mscratch_ff));
                                        }
                                    }
                                }
                            }
                        } else if ((0x400U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                          >> 9U)))) {
                                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                              >> 8U)))) {
                                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                  >> 7U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                    >> 6U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                     >> 5U)))) {
                                                vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                                    = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcountinhibit_ff;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                             >> 9U)))) {
                            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                          >> 8U)))) {
                                if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                    if ((0x40U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                        if ((1U & (~ 
                                                   (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                    >> 5U)))) {
                                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                                = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcounteren_ff;
                                        }
                                    } else {
                                        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                            = ((0x20U 
                                                & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])
                                                ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_ff
                                                : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_ff);
                                    }
                                } else {
                                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                        = ((0x40U & 
                                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])
                                            ? ((0x20U 
                                                & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])
                                                ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_ff
                                                : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_medeleg_ff)
                                            : ((0x20U 
                                                & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])
                                                ? 0x40141101U
                                                : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff));
                                }
                            }
                        }
                    }
                }
            } else if ((0x2000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                if ((0x1000U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                  >> 0xbU)))) {
                        if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                      >> 0xaU)))) {
                            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                          >> 9U)))) {
                                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                              >> 8U)))) {
                                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                  >> 7U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                    >> 6U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                     >> 5U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((1U 
                                                          == (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff)) 
                                                         & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff 
                                                            >> 0x14U))))) {
                                                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                                        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_ff;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x800U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                  >> 0xaU)))) {
                        if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                      >> 9U)))) {
                            if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                          >> 8U)))) {
                                if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                  >> 6U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                    >> 5U)))) {
                                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                                = (0x222U 
                                                   & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_ff);
                                        }
                                    }
                                } else {
                                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                        = ((0x40U & 
                                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])
                                            ? ((0x20U 
                                                & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])
                                                ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stval_ff
                                                : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_scause_ff)
                                            : ((0x20U 
                                                & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])
                                                ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sepc_ff
                                                : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sscratch_ff));
                                }
                            }
                        }
                    }
                } else if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                     >> 0xaU)))) {
                    if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                  >> 9U)))) {
                        if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                      >> 8U)))) {
                            if ((0x80U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])) {
                                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                              >> 6U)))) {
                                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                        = ((0x20U & 
                                            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U])
                                            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_ff
                                            : (0x222U 
                                               & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_ff));
                                }
                            } else if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                                 >> 6U)))) {
                                if ((1U & (~ (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[3U] 
                                              >> 5U)))) {
                                    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata 
                                        = (0x800de762U 
                                           & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff);
                                }
                            }
                        }
                    }
                }
            }
        }
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
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata 
        = ((1U == (3U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                         >> 6U))) ? ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[1U] 
                                      << 0x1bU) | (
                                                   vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[0U] 
                                                   >> 5U))
            : ((2U == (3U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                             >> 6U))) ? (((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[1U] 
                                           << 0x1bU) 
                                          | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[0U] 
                                             >> 5U)) 
                                         | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata)
                : ((3U == (3U & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff) 
                                 >> 6U))) ? ((~ ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[1U] 
                                                  << 0x1bU) 
                                                 | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff[0U] 
                                                    >> 5U))) 
                                             & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata)
                    : 0U)));
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
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_req 
        = ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__meip_irq_req) 
           | ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mtip_irq_req) 
              | ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__msip_irq_req) 
                 | (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_irq_req))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_delegated_req 
        = ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_irq_req) 
           & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_ff 
              >> (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_code)));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_medeleg_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_medeleg_ff;
    if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_medeleg_wr_flag) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_medeleg_next 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata;
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_ff;
    if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_wr_flag) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_next 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata;
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_ff;
    if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_wr_flag) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_next 
            = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata)
                ? (0xffffffc1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata)
                : (0xfffffffdU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata));
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_ff;
    if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_wr_flag) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_next 
            = ((1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata)
                ? (0xffffffc1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata)
                : (0xfffffffdU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata));
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcounteren_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcounteren_wr_flag)
            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata
            : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcounteren_ff);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcountinhibit_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcountinhibit_wr_flag)
            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata
            : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcountinhibit_ff);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mscratch_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mscratch_wr_flag)
            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata
            : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mscratch_ff);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sscratch_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sscratch_wr_flag)
            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata
            : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sscratch_ff);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_ff;
    if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_wr_flag) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_next 
            = (0xaaaU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata);
    } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sie_wr_flag) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_next 
            = ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata 
                & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_ff) 
               | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_ff 
                  & (~ vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_ff)));
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sip_mask = 0U;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_ff;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_next 
        = ((0xfffff7ffU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_next) 
           | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__ext_irq_ff) 
              << 0xbU));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_next 
        = ((0xffffff7fU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_next) 
           | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__timer_irq_ff) 
              << 7U));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_next 
        = (0xfffffff7U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_next);
    if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_wr_flag) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_next 
            = ((0x222U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata) 
               | (0xfffffdddU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_ff));
    } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sip_wr_flag) {
        core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sip_mask 
            = (0x222U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_ff);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_next 
            = ((vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata 
                & core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sip_mask) 
               | (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_ff 
                  & (~ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sip_mask)));
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_inc 
        = (1U & (~ vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcountinhibit_ff));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_wr_flag)
            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata
            : ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_inc)
                ? ((IData)(1U) + vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_ff)
                : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_ff));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_ff;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__satp_mode 
        = (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata 
           >> 0x1fU);
    if ((1U & (~ ((1U == (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff)) 
                  & (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff 
                     >> 0x14U))))) {
        if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_wr_flag) {
            vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_next 
                = ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__satp_mode)
                    ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata
                    : 0U);
        }
    }
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2exe 
        = (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgTmp_h140467bf__0) 
            << 3U) | (((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgTmp_hb3ea78f5__0) 
                       << 2U) | ((((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_csr_mul_read_req)) 
                                   & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu2rs1_hazard)) 
                                  << 1U) | ((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_csr_mul_read_req)) 
                                            & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu2rs2_hazard)))));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_next 
        = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_ff;
    if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_req) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_next = 0U;
    } else if (vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_req) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_next = 1U;
    }
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
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_inc 
        = ((0xffffffffU == vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_ff) 
           & (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_inc));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_wr_flag)
            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata
            : ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_inc)
                ? ((IData)(1U) + vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_ff)
                : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_ff));
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

void Vcore_tb___024root___act_sequent__TOP__1(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___act_sequent__TOP__2(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___act_sequent__TOP__3(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___act_comb__TOP__0(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___act_comb__TOP__1(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___act_comb__TOP__2(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___act_comb__TOP__3(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___act_comb__TOP__4(Vcore_tb___024root* vlSelf);

VL_ATTR_COLD void Vcore_tb___024root___eval_stl(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vcore_tb___024root___stl_sequent__TOP__0(vlSelf);
    }
    if ((vlSelf->__VstlTriggered.at(0U) | vlSelf->__VstlTriggered.at(1U))) {
        Vcore_tb___024root___act_sequent__TOP__1(vlSelf);
    }
    if ((vlSelf->__VstlTriggered.at(0U) | vlSelf->__VstlTriggered.at(3U))) {
        Vcore_tb___024root___act_sequent__TOP__2(vlSelf);
    }
    if ((vlSelf->__VstlTriggered.at(0U) | vlSelf->__VstlTriggered.at(4U))) {
        Vcore_tb___024root___act_sequent__TOP__3(vlSelf);
    }
    if (((vlSelf->__VstlTriggered.at(0U) | vlSelf->__VstlTriggered.at(4U)) 
         | vlSelf->__VstlTriggered.at(5U))) {
        Vcore_tb___024root___act_comb__TOP__0(vlSelf);
    }
    if (((vlSelf->__VstlTriggered.at(0U) | vlSelf->__VstlTriggered.at(3U)) 
         | vlSelf->__VstlTriggered.at(4U))) {
        Vcore_tb___024root___act_comb__TOP__1(vlSelf);
    }
    if ((((vlSelf->__VstlTriggered.at(0U) | vlSelf->__VstlTriggered.at(2U)) 
          | vlSelf->__VstlTriggered.at(4U)) | vlSelf->__VstlTriggered.at(5U))) {
        Vcore_tb___024root___act_comb__TOP__2(vlSelf);
    }
    if ((((((vlSelf->__VstlTriggered.at(0U) | vlSelf->__VstlTriggered.at(2U)) 
            | vlSelf->__VstlTriggered.at(3U)) | vlSelf->__VstlTriggered.at(4U)) 
          | vlSelf->__VstlTriggered.at(5U)) | vlSelf->__VstlTriggered.at(6U))) {
        Vcore_tb___024root___act_comb__TOP__3(vlSelf);
    }
    if (((((((vlSelf->__VstlTriggered.at(0U) | vlSelf->__VstlTriggered.at(1U)) 
             | vlSelf->__VstlTriggered.at(2U)) | vlSelf->__VstlTriggered.at(3U)) 
           | vlSelf->__VstlTriggered.at(4U)) | vlSelf->__VstlTriggered.at(5U)) 
         | vlSelf->__VstlTriggered.at(6U))) {
        Vcore_tb___024root___act_comb__TOP__4(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcore_tb___024root___dump_triggers__act(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([hybrid] core_tb.dut.pipeline_top_module.lsu_module.amo_result_o)\n");
    }
    if (vlSelf->__VactTriggered.at(2U)) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([hybrid] core_tb.dut.pipeline_top_module.csr_module.s_mode_exc_req or [hybrid] core_tb.dut.pipeline_top_module.csr_module.m_mode_exc_req)\n");
    }
    if (vlSelf->__VactTriggered.at(3U)) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([hybrid] core_tb.dut.pipeline_top_module.csr_module.s_mode_exc_req)\n");
    }
    if (vlSelf->__VactTriggered.at(4U)) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @([hybrid] core_tb.dut.pipeline_top_module.csr_module.m_mode_exc_req)\n");
    }
    if (vlSelf->__VactTriggered.at(5U)) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @([hybrid] core_tb.dut.pipeline_top_module.csr_module.exc_delegated_req)\n");
    }
    if (vlSelf->__VactTriggered.at(6U)) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @([hybrid] core_tb.dut.pipeline_top_module.csr_module.en_ld_st_vaddr_next)\n");
    }
    if (vlSelf->__VactTriggered.at(7U)) {
        VL_DBG_MSGF("         'act' region trigger index 7 is active: @(negedge clk)\n");
    }
    if (vlSelf->__VactTriggered.at(8U)) {
        VL_DBG_MSGF("         'act' region trigger index 8 is active: @(posedge clk or negedge core_tb.reset)\n");
    }
    if (vlSelf->__VactTriggered.at(9U)) {
        VL_DBG_MSGF("         'act' region trigger index 9 is active: @(posedge core_tb.dut.clint_module.timer_clk_ff or negedge core_tb.reset)\n");
    }
    if (vlSelf->__VactTriggered.at(0xaU)) {
        VL_DBG_MSGF("         'act' region trigger index 10 is active: @(negedge clk or negedge core_tb.reset)\n");
    }
    if (vlSelf->__VactTriggered.at(0xbU)) {
        VL_DBG_MSGF("         'act' region trigger index 11 is active: @(posedge clk or posedge core_tb.dut.mem_top_module.icache_module.__Vcellinp__icache_datapath__icache_flush or negedge core_tb.reset)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcore_tb___024root___dump_triggers__nba(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([hybrid] core_tb.dut.pipeline_top_module.lsu_module.amo_result_o)\n");
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([hybrid] core_tb.dut.pipeline_top_module.csr_module.s_mode_exc_req or [hybrid] core_tb.dut.pipeline_top_module.csr_module.m_mode_exc_req)\n");
    }
    if (vlSelf->__VnbaTriggered.at(3U)) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([hybrid] core_tb.dut.pipeline_top_module.csr_module.s_mode_exc_req)\n");
    }
    if (vlSelf->__VnbaTriggered.at(4U)) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @([hybrid] core_tb.dut.pipeline_top_module.csr_module.m_mode_exc_req)\n");
    }
    if (vlSelf->__VnbaTriggered.at(5U)) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @([hybrid] core_tb.dut.pipeline_top_module.csr_module.exc_delegated_req)\n");
    }
    if (vlSelf->__VnbaTriggered.at(6U)) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @([hybrid] core_tb.dut.pipeline_top_module.csr_module.en_ld_st_vaddr_next)\n");
    }
    if (vlSelf->__VnbaTriggered.at(7U)) {
        VL_DBG_MSGF("         'nba' region trigger index 7 is active: @(negedge clk)\n");
    }
    if (vlSelf->__VnbaTriggered.at(8U)) {
        VL_DBG_MSGF("         'nba' region trigger index 8 is active: @(posedge clk or negedge core_tb.reset)\n");
    }
    if (vlSelf->__VnbaTriggered.at(9U)) {
        VL_DBG_MSGF("         'nba' region trigger index 9 is active: @(posedge core_tb.dut.clint_module.timer_clk_ff or negedge core_tb.reset)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0xaU)) {
        VL_DBG_MSGF("         'nba' region trigger index 10 is active: @(negedge clk or negedge core_tb.reset)\n");
    }
    if (vlSelf->__VnbaTriggered.at(0xbU)) {
        VL_DBG_MSGF("         'nba' region trigger index 11 is active: @(posedge clk or posedge core_tb.dut.mem_top_module.icache_module.__Vcellinp__icache_datapath__icache_flush or negedge core_tb.reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vcore_tb___024root___ctor_var_reset(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = 0;
    vlSelf->core_tb__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__loop_count = VL_RAND_RESET_Q(36);
    vlSelf->core_tb__DOT__irq_soft = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__uart_rx = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__tracelog_filepointer = 0;
    vlSelf->core_tb__DOT__uartlog_filepointer = 0;
    vlSelf->core_tb__DOT__flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__icache2if = VL_RAND_RESET_Q(33);
    vlSelf->core_tb__DOT__dut__DOT__dbus2lsu = VL_RAND_RESET_Q(33);
    vlSelf->core_tb__DOT__dut__DOT__core2pipe = VL_RAND_RESET_Q(36);
    vlSelf->core_tb__DOT__dut__DOT__clint2csr = VL_RAND_RESET_Q(64);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_rxd_i = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT____Vcellinp__plic_module__irq_src_i = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(97, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_next);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_ctrl_next = VL_RAND_RESET_I(5);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_next = VL_RAND_RESET_Q(41);
    VL_RAND_RESET_W(193, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_next = VL_RAND_RESET_I(20);
    VL_RAND_RESET_W(96, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_next);
    VL_RAND_RESET_W(113, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_next);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_next = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(133, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_next);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_next = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__wrb2id_fb = VL_RAND_RESET_Q(38);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr2fwd = VL_RAND_RESET_I(3);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2lsu = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2ptop = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(97, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_data_pipe_ff);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__if2id_ctrl_pipe_ff = VL_RAND_RESET_I(5);
    VL_RAND_RESET_W(193, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_pipe_ff);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff = VL_RAND_RESET_Q(41);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT____Vcellinp__muldiv_module__fwd2mul_flush_i = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(96, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_data_pipe_ff);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2lsu_ctrl_pipe_ff = VL_RAND_RESET_I(20);
    VL_RAND_RESET_W(113, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_data_pipe_ff);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__exe2csr_ctrl_pipe_ff = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(133, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_data_pipe_ff);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu2wrb_ctrl_pipe_ff = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr2wrb_data_pipe_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__csr2if_fb = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__exc_code = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__exc_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fetch_module__DOT__pc_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_ctrl = VL_RAND_RESET_Q(41);
    VL_RAND_RESET_W(193, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__id2exe_data);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__decode_module__DOT__rf_module__DOT__register_file[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__exe2csr_ctrl = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__operand_rs1_data = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__operand_rs2_data = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__alu_result = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT__cmp_output = VL_RAND_RESET_Q(33);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__execute_module__DOT____VdfgExtracted_h0362d37b__0 = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_req_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_ack_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_ack_ff_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_result_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__muldiv_module__DOT__alu_m_result_ff = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(133, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_data);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2wrb_ctrl = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(68, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__lsu2dbus);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__ld_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__st_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_buffer_data_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_buffer_addr_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_operand_a_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_result_o = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_done = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_save = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__state_next = VL_RAND_RESET_I(3);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr2lsu_data = VL_RAND_RESET_I(27);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__fwd2csr = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_rdata = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wr_exc_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_exc_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_exc_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_pc_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_pc_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcounteren_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcounteren_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcountinhibit_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcountinhibit_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_medeleg_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_medeleg_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mscratch_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mscratch_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mepc_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mepc_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcause_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcause_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtval_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtval_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sscratch_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sscratch_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sepc_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sepc_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_scause_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_scause_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stval_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stval_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstret_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_minstreth_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcounteren_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcountinhibit_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mstatus_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_medeleg_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mideleg_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mie_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtvec_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mscratch_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mepc_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcause_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mtval_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mip_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sstatus_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sscratch_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sie_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stvec_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sepc_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_stval_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_sip_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_satp_wr_flag = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_ff = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__priv_mode_next = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__trap_priv_mode = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_delegated_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_delegated_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_code = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__irq_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__timer_irq_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__ext_irq_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_exc_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_irq_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_pc_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mret_pc_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_exc_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_irq_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_pc_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sret_pc_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sret_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mret_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sfence_vma_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__wfi_next = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__en_ld_st_vaddr_next = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT____VdfgTmp_he5991c42__0 = 0;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT____VdfgTmp_h21021b6f__0 = 0;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__writeback_module__DOT__wrb_rd_data = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu2rs1_hazard = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu2rs2_hazard = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_csr_mul_read_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu_mul_stall = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_stall_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__ld_stall_next = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__mul_stall_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__mul_stall_next = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT__lsu_mul_stall_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgExtracted_h09503d11__0 = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgTmp_h4675c004__0 = 0;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgTmp_h140467bf__0 = 0;
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__forward_stall_module__DOT____VdfgTmp_hb3ea78f5__0 = 0;
    VL_RAND_RESET_W(70, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2lsu);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__mmu2if = VL_RAND_RESET_Q(35);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT____VdfgTmp_h1ec46b79__0 = 0;
    VL_RAND_RESET_W(216, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_ff);
    VL_RAND_RESET_W(216, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT__tlb_array_next);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT____Vlvbound_hd6fcc4ae__0 = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT____Vlvbound_h130160c9__0 = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT____Vlvbound_haa3579db__0 = VL_RAND_RESET_I(10);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT____Vlvbound_ha9c1d2a1__0 = VL_RAND_RESET_I(10);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__itlb_module__DOT____Vlvbound_h12c5995c__0 = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb2mmu = VL_RAND_RESET_Q(34);
    VL_RAND_RESET_W(864, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_ff);
    VL_RAND_RESET_W(864, vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT__tlb_array_next);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____Vlvbound_hf69d70be__0 = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____Vlvbound_h22748b0f__0 = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____Vlvbound_hfc7452ca__0 = VL_RAND_RESET_I(10);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____Vlvbound_hfc512a83__0 = VL_RAND_RESET_I(10);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____Vlvbound_h22bca24b__0 = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__dtlb_module__DOT____VdfgExtracted_h1a7370a5__0 = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw2mmu = VL_RAND_RESET_Q(36);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_ff = VL_RAND_RESET_I(3);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_state_next = VL_RAND_RESET_I(3);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_lvl_next = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_data_valid_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__itlb_update = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__dtlb_miss = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__iwalk_active_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__iwalk_active_next = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__gmap_bit_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__gmap_bit_next = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__vaddr_next = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_paddr_ff = VL_RAND_RESET_Q(34);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__ptw_paddr_next = VL_RAND_RESET_Q(34);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_req_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_req_next = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_h23a25fc1__0 = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_haf4fd536__0 = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_h35f41773__0 = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_hcbf4d47b__0 = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgExtracted_he4191b8e__0 = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT____VdfgTmp_hd5ca5221__0 = 0;
    VL_RAND_RESET_W(71, vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dbus2peri);
    vlSelf->core_tb__DOT__dut__DOT__dbus_interconnect_module__DOT__dmem_sel = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__reg_rd_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__reg_wr_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__tx_valid_next = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__tx_valid_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rx_ff = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rx_next = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_tx_ff = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_tx_next = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_baud_ff = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_baud_next = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_txctrl_ff = VL_RAND_RESET_I(20);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_txctrl_next = VL_RAND_RESET_I(20);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rxctrl_ff = VL_RAND_RESET_I(20);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_rxctrl_next = VL_RAND_RESET_I(20);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_status_ff = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_status_next = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_int_mask_ff = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_reg_int_mask_next = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__reg_r_data = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart2dbus_ff = VL_RAND_RESET_Q(33);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__sample_count_ff = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__sample_count_next = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_ff = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__bit_count_next = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_tx_module__DOT__state_next = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__bit_count_ff = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__bit_count_next = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sample_count_ff = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sample_count_next = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sbit_sample_count_ff = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__sbit_sample_count_next = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__shifter_ff = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__shifter_next = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__valid_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__valid_next = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__frame_err_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__frame_err_next = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__uart_module__DOT__uart_rx_module__DOT__state_next = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__reg_rd_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__reg_wr_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__tx_valid_next = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__tx_valid_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_rx_ff = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_rx_next = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_tx_ff = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_tx_next = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_baud_ff = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_baud_next = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lctrl_ff = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lctrl_next = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_ie_ff = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_ie_next = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lstatus_ff = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_lstatus_next = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_scratch_ff = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_reg_scratch_next = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__reg_r_data = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart2dbus_ff = VL_RAND_RESET_Q(33);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__sample_count_ff = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__sample_count_next = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_ff = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__bit_count_next = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_tx_module__DOT__state_next = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__bit_count_ff = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__bit_count_next = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sample_count_ff = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sample_count_next = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sbit_sample_count_ff = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__sbit_sample_count_next = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__shifter_ff = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__shifter_next = VL_RAND_RESET_I(8);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__valid_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__valid_next = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__frame_err_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__frame_err_next = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__uart_ns_module__DOT__uart_ns_rx_module__DOT__state_next = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__r_data = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__r_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__w_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtime_ff = VL_RAND_RESET_Q(64);
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtime_next = VL_RAND_RESET_Q(64);
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_ff = VL_RAND_RESET_Q(64);
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__mtimecmp_next = VL_RAND_RESET_Q(64);
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_overflow_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_clk_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_clk_next = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_prescaler_ff = VL_RAND_RESET_I(7);
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__timer_prescaler_next = VL_RAND_RESET_I(7);
    vlSelf->core_tb__DOT__dut__DOT__clint_module__DOT__clint2dbus_ff = VL_RAND_RESET_Q(33);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT____Vcellinp__plic_regs_module__claim_idx_i = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_pending_ff = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_pending_next = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_active_ff = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_active_next = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_req = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_gateway_module__DOT__irq_src_ff = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_rd_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_wr_req = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__reg_r_data = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_ff = VL_RAND_RESET_I(6);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_th_next = VL_RAND_RESET_I(6);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_ff = VL_RAND_RESET_I(6);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_prio_next = VL_RAND_RESET_I(6);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_ie_ff = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic_reg_ie_next = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT__plic2dbus_ff = VL_RAND_RESET_Q(33);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_h06702582__0 = VL_RAND_RESET_I(3);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_h06702582__1 = VL_RAND_RESET_I(3);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_hbb644852__0 = VL_RAND_RESET_I(3);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__plic_regs_module__DOT____Vlvbound_hbb644852__1 = VL_RAND_RESET_I(3);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_req_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_req_next = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_idx_ff = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__0__KET____DOT__plic_target_module__DOT__irq_idx_next = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__1__KET____DOT__plic_target_module__DOT__irq_idx_ff = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__plic_module__DOT__genblk1__BRA__1__KET____DOT__plic_target_module__DOT__irq_idx_next = VL_RAND_RESET_I(2);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dmem2mmu = VL_RAND_RESET_Q(33);
    VL_RAND_RESET_W(71, vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__lsummu2dmem);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2if_ff = VL_RAND_RESET_Q(33);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2if_next = VL_RAND_RESET_Q(33);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2dbus_ff = VL_RAND_RESET_Q(33);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__bmem_interface_module__DOT__bmem2dbus_next = VL_RAND_RESET_Q(33);
    for (int __Vi0 = 0; __Vi0 < 33554432; ++__Vi0) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dualport_memory[__Vi0] = VL_RAND_RESET_I(32);
    }
    VL_RAND_RESET_W(129, vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem2icache_ff);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem_addr_ff = VL_RAND_RESET_I(28);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__imem_rd_req_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem2dbus_ff = VL_RAND_RESET_Q(33);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_wdata_ff = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_addr_ff = VL_RAND_RESET_I(28);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_selbyte_ff = VL_RAND_RESET_I(4);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_wen_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dualport_mem_module__DOT__dmem_sel_ff = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__cache_rw = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache = VL_RAND_RESET_Q(34);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellout__icache_controller_module__icache2imem_request_o = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellout__icache_controller_module__icache2if_ack_o = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellout__icache_datapath__icache2if_data_o = VL_RAND_RESET_I(32);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellinp__icache_datapath__icache_flush = VL_RAND_RESET_I(1);
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_d = 0;
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__state_q = 0;
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_controller_module__DOT__icache2if_ack_ff = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(147, vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__cache_ram_read);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM[__Vi0] = VL_RAND_RESET_I(18);
    }
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__unnamedblk1__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__VALID_RAM[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__unnamedblk1__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        VL_RAND_RESET_W(128, vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__DATA_RAM[__Vi0]);
    }
    vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cdata__DOT__unnamedblk1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__VdfgTmp_h7bbdf8ad__0 = 0;
    vlSelf->__Vtrigrprev__TOP__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__lsu_module__DOT__amo_result_o = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigrprev__TOP__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_exc_req = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_exc_req = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__exc_delegated_req = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__en_ld_st_vaddr_next = VL_RAND_RESET_I(1);
    vlSelf->__VstlDidInit = 0;
    vlSelf->__Vtrigrprev__TOP__clk = 0;
    vlSelf->__Vtrigrprev__TOP__core_tb__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__core_tb__DOT__dut__DOT__clint_module__DOT__timer_clk_ff = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT____Vcellinp__icache_datapath__icache_flush = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
}
