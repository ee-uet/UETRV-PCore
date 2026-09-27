// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdcache_data_ram__Syms.h"


VL_ATTR_COLD void Vdcache_data_ram___024root__trace_init_sub__TOP____024unit__0(Vdcache_data_ram___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vdcache_data_ram___024root__trace_init_sub__TOP__0(Vdcache_data_ram___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root__trace_init_sub__TOP__0\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$unit", VerilatedTracePrefixType::SCOPE_MODULE);
    Vdcache_data_ram___024root__trace_init_sub__TOP____024unit__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBit(c+46,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"dmem_sel_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"dcache_flush_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"dcache_kill_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+51,0,"lsummu2dcache_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 69,0);
    tracep->declQuad(c+54,0,"dcache2lsummu_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declArray(c+56,0,"mem2dcache_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 128,0);
    tracep->declArray(c+61,0,"dcache2mem_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 161,0);
    tracep->declBit(c+67,0,"dcache2mem_kill_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("wb_dcache_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+46,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"dmem_sel_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"dcache_flush_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"dcache_kill_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+51,0,"lsummu2dcache_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 69,0);
    tracep->declQuad(c+54,0,"dcache2lsummu_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declArray(c+56,0,"mem2dcache_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 128,0);
    tracep->declArray(c+61,0,"dcache2mem_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 161,0);
    tracep->declBit(c+67,0,"dcache2mem_kill_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"cache_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"cache_evict_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"cache_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"cache_line_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"cache_line_clean",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"cache_wrb_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"evict_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declArray(c+51,0,"lsummu2dcache",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 69,0);
    tracep->declQuad(c+54,0,"dcache2lsummu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declArray(c+56,0,"mem2dcache",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 128,0);
    tracep->declArray(c+61,0,"dcache2mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 161,0);
    tracep->declBit(c+82,0,"collect_info_tag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("wb_dcache_controller_module", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+46,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"cache_hit_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"cache_evict_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"dcache_flush_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"cache_wr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"cache_line_wr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"cache_line_clean_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"cache_wrb_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"evict_index_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+68,0,"lsummu2dcache_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"lsummu2dcache_wr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"dcache2lsummu_ack_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"dcache_kill_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"mem2dcache_ack_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"dcache2mem_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"dcache2mem_wr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"dcache2mem_kill_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"dmem_sel_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+21,0,"dcache_state_ff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+7,0,"dcache_state_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+8,0,"evict_index_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+19,0,"evict_index_ff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+22,0,"lsummu2dcache_wr_ff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"dcache2lsummu_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"dcache_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"dcache_miss",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"dcache_evict",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"dcache2mem_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"dcache2mem_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"cache_wrb_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"cache_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"cache_line_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"cache_line_clean",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"dcache2mem_kill",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"lsummu2dcache_req_ff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"dmem_sel_ff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("wb_dcache_datapath_module", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+46,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"cache_wr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"cache_line_wr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"cache_line_clean_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"cache_wrb_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"evict_index_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+17,0,"cache_hit_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"cache_evict_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"dcache_flush_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"lsummu2dcache_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+72,0,"lsummu2dcache_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+73,0,"lsummu2dcache_wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"sel_byte_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+27,0,"dcache2lsummu_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+75,0,"mem2dcache_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+28,0,"dcache2mem_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+79,0,"dcache2mem_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+28,0,"cache_line_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 127,0);
    tracep->declArray(c+32,0,"cache_line_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 127,0);
    tracep->declArray(c+9,0,"cache_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1, 127,0);
    tracep->declBus(c+36,0,"cache_tag_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"cache_tag_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"cache_word_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"cache_word_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"lsummu2dcache_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+79,0,"dcache2mem_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"cache_line_sel_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+14,0,"cache_data_wr_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+40,0,"sel_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+15,0,"cache_tag_wr_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+41,0,"dcache2lsummu_data_ff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"dcache2lsummu_data_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+80,0,"addr_tag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+42,0,"addr_tag_ff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+81,0,"addr_offset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+43,0,"addr_offset_ff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+16,0,"addr_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+44,0,"addr_index_ff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+19,0,"evict_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+49,0,"dcache_flush",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("dcache_data_ram_module", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+83,0,"NUM_COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"COL_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+46,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+14,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+16,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declArray(c+9,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+28,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->popPrefix();
    tracep->pushPrefix("dcache_tag_ram_module", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+87,0,"NUM_COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"COL_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+46,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+16,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+13,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+49,0,"dcache_flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vdcache_data_ram___024root__trace_init_sub__TOP____024unit__0(Vdcache_data_ram___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root__trace_init_sub__TOP____024unit__0\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+88,0,"ICACHE_ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"ICACHE_DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"ICACHE_LINE_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+89,0,"ICACHE_NO_OF_SETS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"ICACHE_OFFSET_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,0,"ICACHE_IDX_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"ICACHE_TAG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"ICACHE_TAG_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"DCACHE_ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"DCACHE_DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"DCACHE_LINE_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"DCACHE_NO_OF_SETS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"DCACHE_OFFSET_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"DCACHE_IDX_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"DCACHE_TAG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"DCACHE_TAG_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+96,0,"DCACHE_MAX_IDX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+97,0,"CSR_MTVEC_BASE_ALIGN_VECTOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+98,0,"CSR_MTVEC_BASE_ALIGN_DIRECT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+99,0,"MODE_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+97,0,"CSR_STVEC_BASE_ALIGN_VECTOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+98,0,"CSR_STVEC_BASE_ALIGN_DIRECT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+100,0,"EXC_CODE_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+101,0,"S_SOFT_INT_IDX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+102,0,"M_SOFT_INT_IDX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+103,0,"S_TIMER_INT_IDX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+104,0,"M_TIMER_INT_IDX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+105,0,"S_EXT_INT_IDX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+106,0,"M_EXT_INT_IDX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+107,0,"MIE_SSIP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"MIE_MSIP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+109,0,"MIE_STIP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"MIE_MTIP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+111,0,"MIE_SEIP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+112,0,"MIE_MEIP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"MIE_MASK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"MIP_MASK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+114,0,"SIE_MASK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+114,0,"SIP_MASK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+107,0,"SIE_SSIP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+107,0,"SIP_SSIP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+100,0,"IRQ_CODE_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+107,0,"STATUS_SIE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+109,0,"STATUS_SPIE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+115,0,"STATUS_UBE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"STATUS_SPP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+117,0,"STATUS_VS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"STATUS_FS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+119,0,"STATUS_XS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+120,0,"STATUS_SUM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"STATUS_MXR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"STATUS_SD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+123,0,"SSTATUS_READ_MASK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+124,0,"SSTATUS_WRITE_MASK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+125,0,"SATP_ASID_MASK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+126,0,"SATP_MODE_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,0,"SATP_ASID_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"SATP_PPN_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+126,0,"MODE_SV32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+128,0,"TVEC_MODE_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+129,0,"TVEC_BASE_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+130,0,"TLB_ENTRIES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+131,0,"DTLB_ENTRIES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+102,0,"DTLB_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
}

VL_ATTR_COLD void Vdcache_data_ram___024root__trace_init_top(Vdcache_data_ram___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root__trace_init_top\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vdcache_data_ram___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vdcache_data_ram___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vdcache_data_ram___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdcache_data_ram___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdcache_data_ram___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vdcache_data_ram___024root__trace_register(Vdcache_data_ram___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root__trace_register\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vdcache_data_ram___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vdcache_data_ram___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vdcache_data_ram___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vdcache_data_ram___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vdcache_data_ram___024root__trace_const_0_sub_0(Vdcache_data_ram___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vdcache_data_ram___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root__trace_const_0\n"); );
    // Init
    Vdcache_data_ram___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdcache_data_ram___024root*>(voidSelf);
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vdcache_data_ram___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vdcache_data_ram___024root__trace_const_0_sub_0(Vdcache_data_ram___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root__trace_const_0_sub_0\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+82,(vlSelfRef.wb_dcache_top__DOT__collect_info_tag));
    bufp->fullIData(oldp+83,(0x10U),32);
    bufp->fullIData(oldp+84,(8U),32);
    bufp->fullIData(oldp+85,(0xbU),32);
    bufp->fullIData(oldp+86,(0x80U),32);
    bufp->fullIData(oldp+87,(4U),32);
    bufp->fullIData(oldp+88,(0x20U),32);
    bufp->fullIData(oldp+89,(0x200U),32);
    bufp->fullIData(oldp+90,(9U),32);
    bufp->fullIData(oldp+91,(0x13U),32);
    bufp->fullIData(oldp+92,(0xdU),32);
    bufp->fullIData(oldp+93,(0x800U),32);
    bufp->fullIData(oldp+94,(0x11U),32);
    bufp->fullIData(oldp+95,(0xfU),32);
    bufp->fullSData(oldp+96,(0x7ffU),11);
    bufp->fullIData(oldp+97,(6U),32);
    bufp->fullIData(oldp+98,(2U),32);
    bufp->fullIData(oldp+99,(0U),32);
    bufp->fullIData(oldp+100,(4U),32);
    bufp->fullIData(oldp+101,(1U),32);
    bufp->fullIData(oldp+102,(3U),32);
    bufp->fullIData(oldp+103,(5U),32);
    bufp->fullIData(oldp+104,(7U),32);
    bufp->fullIData(oldp+105,(9U),32);
    bufp->fullIData(oldp+106,(0xbU),32);
    bufp->fullIData(oldp+107,(2U),32);
    bufp->fullIData(oldp+108,(8U),32);
    bufp->fullIData(oldp+109,(0x20U),32);
    bufp->fullIData(oldp+110,(0x80U),32);
    bufp->fullIData(oldp+111,(0x200U),32);
    bufp->fullIData(oldp+112,(0x800U),32);
    bufp->fullIData(oldp+113,(0xaaaU),32);
    bufp->fullIData(oldp+114,(0x222U),32);
    bufp->fullIData(oldp+115,(0x40U),32);
    bufp->fullIData(oldp+116,(0x100U),32);
    bufp->fullIData(oldp+117,(0x600U),32);
    bufp->fullIData(oldp+118,(0x6000U),32);
    bufp->fullIData(oldp+119,(0x18000U),32);
    bufp->fullIData(oldp+120,(0x40000U),32);
    bufp->fullIData(oldp+121,(0x80000U),32);
    bufp->fullIData(oldp+122,(0x80000000U),32);
    bufp->fullIData(oldp+123,(0x800de762U),32);
    bufp->fullIData(oldp+124,(0xc6122U),32);
    bufp->fullIData(oldp+125,(0x803fffffU),32);
    bufp->fullIData(oldp+126,(1U),32);
    bufp->fullIData(oldp+127,(0x16U),32);
    bufp->fullIData(oldp+128,(2U),32);
    bufp->fullIData(oldp+129,(0x1eU),32);
    bufp->fullIData(oldp+130,(0x10U),32);
    bufp->fullIData(oldp+131,(8U),32);
}

VL_ATTR_COLD void Vdcache_data_ram___024root__trace_full_0_sub_0(Vdcache_data_ram___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vdcache_data_ram___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root__trace_full_0\n"); );
    // Init
    Vdcache_data_ram___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdcache_data_ram___024root*>(voidSelf);
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vdcache_data_ram___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vdcache_data_ram___024root__trace_full_0_sub_0(Vdcache_data_ram___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdcache_data_ram___024root__trace_full_0_sub_0\n"); );
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wr));
    bufp->fullBit(oldp+2,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_wr));
    bufp->fullBit(oldp+3,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_line_clean));
    bufp->fullBit(oldp+4,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req));
    bufp->fullBit(oldp+5,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_req));
    bufp->fullBit(oldp+6,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_wr));
    bufp->fullCData(oldp+7,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_next),3);
    bufp->fullSData(oldp+8,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_next),11);
    bufp->fullWData(oldp+9,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_wdata),128);
    bufp->fullIData(oldp+13,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_write),32);
    bufp->fullSData(oldp+14,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_data_wr_sel),16);
    bufp->fullCData(oldp+15,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_tag_wr_sel),4);
    bufp->fullSData(oldp+16,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index),11);
    bufp->fullBit(oldp+17,(vlSelfRef.wb_dcache_top__DOT__cache_hit));
    bufp->fullBit(oldp+18,((1U & (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
                                  >> 0x18U))));
    bufp->fullSData(oldp+19,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__evict_index_ff),11);
    bufp->fullBit(oldp+20,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2lsummu_ack));
    bufp->fullCData(oldp+21,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_state_ff),3);
    bufp->fullBit(oldp+22,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__lsummu2dcache_wr_ff));
    bufp->fullBit(oldp+23,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_hit));
    bufp->fullBit(oldp+24,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache_miss));
    bufp->fullBit(oldp+25,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__lsummu2dcache_req_ff));
    bufp->fullBit(oldp+26,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dmem_sel_ff));
    bufp->fullIData(oldp+27,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_read),32);
    bufp->fullWData(oldp+28,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_read),128);
    bufp->fullWData(oldp+32,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_write),128);
    bufp->fullIData(oldp+36,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata),32);
    bufp->fullIData(oldp+37,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_word_write),32);
    bufp->fullIData(oldp+38,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__lsummu2dcache_wdata),32);
    bufp->fullSData(oldp+39,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__cache_line_sel_byte),16);
    bufp->fullCData(oldp+40,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__sel_byte),4);
    bufp->fullIData(oldp+41,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__dcache2lsummu_data_ff),32);
    bufp->fullIData(oldp+42,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_tag_ff),17);
    bufp->fullCData(oldp+43,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_offset_ff),2);
    bufp->fullSData(oldp+44,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index_ff),11);
    bufp->fullBit(oldp+45,((1U & (vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
                                  >> 0x17U))));
    bufp->fullBit(oldp+46,(vlSelfRef.clk));
    bufp->fullBit(oldp+47,(vlSelfRef.rst_n));
    bufp->fullBit(oldp+48,(vlSelfRef.dmem_sel_i));
    bufp->fullBit(oldp+49,(vlSelfRef.dcache_flush_i));
    bufp->fullBit(oldp+50,(vlSelfRef.dcache_kill_i));
    bufp->fullWData(oldp+51,(vlSelfRef.lsummu2dcache_i),70);
    bufp->fullQData(oldp+54,(vlSelfRef.dcache2lsummu_o),33);
    bufp->fullWData(oldp+56,(vlSelfRef.mem2dcache_i),129);
    bufp->fullWData(oldp+61,(vlSelfRef.dcache2mem_o),162);
    bufp->fullBit(oldp+67,(vlSelfRef.dcache2mem_kill_o));
    bufp->fullBit(oldp+68,((1U & vlSelfRef.lsummu2dcache_i[0U])));
    bufp->fullBit(oldp+69,((1U & (vlSelfRef.lsummu2dcache_i[0U] 
                                  >> 1U))));
    bufp->fullBit(oldp+70,((1U & vlSelfRef.mem2dcache_i[0U])));
    bufp->fullBit(oldp+71,(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__dcache2mem_kill));
    bufp->fullIData(oldp+72,(((vlSelfRef.lsummu2dcache_i[2U] 
                               << 0x1aU) | (vlSelfRef.lsummu2dcache_i[1U] 
                                            >> 6U))),32);
    bufp->fullIData(oldp+73,(((vlSelfRef.lsummu2dcache_i[1U] 
                               << 0x1aU) | (vlSelfRef.lsummu2dcache_i[0U] 
                                            >> 6U))),32);
    bufp->fullCData(oldp+74,((0xfU & (vlSelfRef.lsummu2dcache_i[0U] 
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
    bufp->fullWData(oldp+75,(__Vtemp_1),128);
    bufp->fullIData(oldp+79,(((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_controller_module__DOT__cache_wrb_req)
                               ? ((vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT____Vcellout__dcache_tag_ram_module__rdata 
                                   << 0xfU) | ((IData)(vlSelfRef.wb_dcache_top__DOT__wb_dcache_datapath_module__DOT__addr_index) 
                                               << 4U))
                               : ((vlSelfRef.lsummu2dcache_i[2U] 
                                   << 0x1aU) | (vlSelfRef.lsummu2dcache_i[1U] 
                                                >> 6U)))),32);
    bufp->fullIData(oldp+80,((0x1ffffU & ((vlSelfRef.lsummu2dcache_i[2U] 
                                           << 0xbU) 
                                          | (vlSelfRef.lsummu2dcache_i[1U] 
                                             >> 0x15U)))),17);
    bufp->fullCData(oldp+81,((3U & (vlSelfRef.lsummu2dcache_i[1U] 
                                    >> 8U))),2);
}
