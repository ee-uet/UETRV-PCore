// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdcache_data_ram.h for the primary calling header

#ifndef VERILATED_VDCACHE_DATA_RAM___024UNIT_H_
#define VERILATED_VDCACHE_DATA_RAM___024UNIT_H_  // guard

#include "verilated.h"


class Vdcache_data_ram__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdcache_data_ram___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vdcache_data_ram__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdcache_data_ram___024unit(Vdcache_data_ram__Syms* symsp, const char* v__name);
    ~Vdcache_data_ram___024unit();
    VL_UNCOPYABLE(Vdcache_data_ram___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
