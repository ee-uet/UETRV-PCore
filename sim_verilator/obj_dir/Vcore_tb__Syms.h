// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCORE_TB__SYMS_H_
#define VERILATED_VCORE_TB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vcore_tb.h"

// INCLUDE MODULE CLASSES
#include "Vcore_tb___024root.h"
#include "Vcore_tb___024unit.h"

// SYMS CLASS (contains all model state)
class Vcore_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vcore_tb* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vcore_tb___024root             TOP;

    // CONSTRUCTORS
    Vcore_tb__Syms(VerilatedContext* contextp, const char* namep, Vcore_tb* modelp);
    ~Vcore_tb__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
