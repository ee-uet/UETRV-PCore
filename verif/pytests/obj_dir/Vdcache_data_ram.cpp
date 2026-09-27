// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdcache_data_ram__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vdcache_data_ram::Vdcache_data_ram(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdcache_data_ram__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , dmem_sel_i{vlSymsp->TOP.dmem_sel_i}
    , dcache_flush_i{vlSymsp->TOP.dcache_flush_i}
    , dcache_kill_i{vlSymsp->TOP.dcache_kill_i}
    , dcache2mem_kill_o{vlSymsp->TOP.dcache2mem_kill_o}
    , lsummu2dcache_i{vlSymsp->TOP.lsummu2dcache_i}
    , dcache2lsummu_o{vlSymsp->TOP.dcache2lsummu_o}
    , mem2dcache_i{vlSymsp->TOP.mem2dcache_i}
    , dcache2mem_o{vlSymsp->TOP.dcache2mem_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vdcache_data_ram::Vdcache_data_ram(const char* _vcname__)
    : Vdcache_data_ram(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdcache_data_ram::~Vdcache_data_ram() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdcache_data_ram___024root___eval_debug_assertions(Vdcache_data_ram___024root* vlSelf);
#endif  // VL_DEBUG
void Vdcache_data_ram___024root___eval_static(Vdcache_data_ram___024root* vlSelf);
void Vdcache_data_ram___024root___eval_initial(Vdcache_data_ram___024root* vlSelf);
void Vdcache_data_ram___024root___eval_settle(Vdcache_data_ram___024root* vlSelf);
void Vdcache_data_ram___024root___eval(Vdcache_data_ram___024root* vlSelf);

void Vdcache_data_ram::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdcache_data_ram::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdcache_data_ram___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdcache_data_ram___024root___eval_static(&(vlSymsp->TOP));
        Vdcache_data_ram___024root___eval_initial(&(vlSymsp->TOP));
        Vdcache_data_ram___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdcache_data_ram___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vdcache_data_ram::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vdcache_data_ram::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vdcache_data_ram::eventsPending() { return false; }

uint64_t Vdcache_data_ram::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vdcache_data_ram::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdcache_data_ram___024root___eval_final(Vdcache_data_ram___024root* vlSelf);

VL_ATTR_COLD void Vdcache_data_ram::final() {
    Vdcache_data_ram___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdcache_data_ram::hierName() const { return vlSymsp->name(); }
const char* Vdcache_data_ram::modelName() const { return "Vdcache_data_ram"; }
unsigned Vdcache_data_ram::threads() const { return 1; }
void Vdcache_data_ram::prepareClone() const { contextp()->prepareClone(); }
void Vdcache_data_ram::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vdcache_data_ram::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vdcache_data_ram___024root__trace_decl_types(VerilatedVcd* tracep);

void Vdcache_data_ram___024root__trace_init_top(Vdcache_data_ram___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdcache_data_ram___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdcache_data_ram___024root*>(voidSelf);
    Vdcache_data_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vdcache_data_ram___024root__trace_decl_types(tracep);
    Vdcache_data_ram___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vdcache_data_ram___024root__trace_register(Vdcache_data_ram___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vdcache_data_ram::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vdcache_data_ram::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vdcache_data_ram___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
