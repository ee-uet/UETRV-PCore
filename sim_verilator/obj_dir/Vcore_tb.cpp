// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcore_tb.h"
#include "Vcore_tb__Syms.h"

//============================================================
// Constructors

Vcore_tb::Vcore_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcore_tb__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vcore_tb::Vcore_tb(const char* _vcname__)
    : Vcore_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcore_tb::~Vcore_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vcore_tb___024root___eval_debug_assertions(Vcore_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vcore_tb___024root___eval_static(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___eval_initial(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___eval_settle(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___eval(Vcore_tb___024root* vlSelf);

void Vcore_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcore_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcore_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vcore_tb___024root___eval_static(&(vlSymsp->TOP));
        Vcore_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vcore_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vcore_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vcore_tb::eventsPending() { return false; }

uint64_t Vcore_tb::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vcore_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vcore_tb___024root___eval_final(Vcore_tb___024root* vlSelf);

VL_ATTR_COLD void Vcore_tb::final() {
    Vcore_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcore_tb::hierName() const { return vlSymsp->name(); }
const char* Vcore_tb::modelName() const { return "Vcore_tb"; }
unsigned Vcore_tb::threads() const { return 1; }
