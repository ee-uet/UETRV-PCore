// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdcache_data_ram.h for the primary calling header

#include "Vdcache_data_ram__pch.h"
#include "Vdcache_data_ram__Syms.h"
#include "Vdcache_data_ram___024root.h"

VL_ATTR_COLD void Vdcache_data_ram___024root___eval_initial__TOP(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval_initial__TOP\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile(std::string{"dump.vcd"});
    vlSymsp->_traceDumpOpen();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdcache_data_ram___024root___dump_triggers__stl(Vdcache_data_ram___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdcache_data_ram___024root___eval_triggers__stl(Vdcache_data_ram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root___eval_triggers__stl\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdcache_data_ram___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
