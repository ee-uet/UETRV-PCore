// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdcache_data_ram.h for the primary calling header

#include "Vdcache_data_ram__pch.h"
#include "Vdcache_data_ram__Syms.h"
#include "Vdcache_data_ram___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdcache_data_ram___024root___dump_triggers__ico(Vdcache_data_ram___024root* vlSelf);
#endif  // VL_DEBUG

void Vdcache_data_ram___024root___eval_triggers__ico(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval_triggers__ico\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdcache_data_ram___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdcache_data_ram___024root___dump_triggers__act(Vdcache_data_ram___024root* vlSelf);
#endif  // VL_DEBUG

void Vdcache_data_ram___024root___eval_triggers__act(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval_triggers__act\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdcache_data_ram___024root___dump_triggers__act(vlSelf);
    }
#endif
}
