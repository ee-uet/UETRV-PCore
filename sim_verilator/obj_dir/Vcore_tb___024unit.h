// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcore_tb.h for the primary calling header

#ifndef VERILATED_VCORE_TB___024UNIT_H_
#define VERILATED_VCORE_TB___024UNIT_H_  // guard

#include "verilated.h"

class Vcore_tb__Syms;

class Vcore_tb___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vcore_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcore_tb___024unit(Vcore_tb__Syms* symsp, const char* v__name);
    ~Vcore_tb___024unit();
    VL_UNCOPYABLE(Vcore_tb___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
