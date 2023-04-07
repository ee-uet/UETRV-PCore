// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcore_tb.h for the primary calling header

#include "verilated.h"

#include "Vcore_tb___024root.h"

VL_INLINE_OPT void Vcore_tb___024root___nba_comb__TOP__5(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_comb__TOP__5\n"); );
    // Init
    IData/*31:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sip_mask;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sip_mask = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_inc;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_inc = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_inc;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_inc = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__satp_mode;
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__satp_mode = 0;
    // Body
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
    core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_inc 
        = ((0xffffffffU == vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_ff) 
           & (IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycle_inc));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_next 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_wr_flag)
            ? vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_wdata
            : ((IData)(core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_inc)
                ? ((IData)(1U) + vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_ff)
                : vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__csr_mcycleh_ff));
}

VL_INLINE_OPT void Vcore_tb___024root___nba_comb__TOP__6(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_comb__TOP__6\n"); );
    // Body
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sret_pc_req 
        = ((~ (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT____VdfgTmp_h21021b6f__0)) 
           & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sret_req));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__s_mode_pc_req 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__sret_pc_req) 
           | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT____VdfgTmp_h21021b6f__0));
}

VL_INLINE_OPT void Vcore_tb___024root___nba_comb__TOP__8(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_comb__TOP__8\n"); );
    // Body
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mret_pc_req 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mret_req) 
           & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT____VdfgTmp_he5991c42__0));
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_pc_req 
        = ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__mret_pc_req) 
           | ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_exc_req) 
              | (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__csr_module__DOT__m_mode_irq_req)));
}

VL_INLINE_OPT void Vcore_tb___024root___nba_sequent__TOP__7(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_sequent__TOP__7\n"); );
    // Body
    vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_req_ff 
        = ((IData)(vlSelf->core_tb__DOT__reset) & ((IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__mmu_module__DOT__ptw_module__DOT__r_req_next) 
                                                   & (~ (IData)(vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__dmem2mmu))));
}

extern const VlUnpacked<CData/*0:0*/, 64> Vcore_tb__ConstPool__TABLE_h70294115_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vcore_tb__ConstPool__TABLE_h89f87c1c_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vcore_tb__ConstPool__TABLE_h7c6c7419_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vcore_tb__ConstPool__TABLE_h512e92e8_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vcore_tb__ConstPool__TABLE_h50d6939b_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vcore_tb__ConstPool__TABLE_h0c0271a0_0;

VL_INLINE_OPT void Vcore_tb___024root___nba_comb__TOP__12(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_comb__TOP__12\n"); );
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
    if ((0x20U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2ptop))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_next = 0ULL;
    } else if ((0x10U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2ptop))) {
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_next 
            = vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_ctrl_pipe_ff;
    }
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
}

VL_INLINE_OPT void Vcore_tb___024root___nba_comb__TOP__13(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_comb__TOP__13\n"); );
    // Body
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
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[0U] 
            = (1U | vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[0U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[1U] 
            = (1U & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[1U]);
        vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[2U] 
            = (0xfffffffeU & vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__id2exe_data_next[2U]);
    } else if ((0x10U & (IData)(vlSelf->core_tb__DOT__dut__DOT__pipeline_top_module__DOT__fwd2ptop))) {
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
}

VL_INLINE_OPT void Vcore_tb___024root___nba_comb__TOP__14(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___nba_comb__TOP__14\n"); );
    // Init
    CData/*0:0*/ core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__cache_hit;
    core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__cache_hit = 0;
    CData/*0:0*/ core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT____Vcellout__ram__read_valid_o;
    core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT____Vcellout__ram__read_valid_o = 0;
    IData/*17:0*/ core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT____Vcellout__ram__read_tag_o;
    core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT____Vcellout__ram__read_tag_o = 0;
    // Body
    core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT____Vcellout__ram__read_tag_o 
        = vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__ctag__DOT__TAG_RAM
        [(0x3ffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                            >> 6U)))];
    core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT____Vcellout__ram__read_valid_o 
        = vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__icache_datapath__DOT__ram__DOT__cvalid__DOT__VALID_RAM
        [(0x3ffU & (IData)((vlSelf->core_tb__DOT__dut__DOT__mem_top_module__DOT__icache_module__DOT__if2icache 
                            >> 6U)))];
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

void Vcore_tb___024root___nba_sequent__TOP__0(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___nba_sequent__TOP__1(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___nba_sequent__TOP__2(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___nba_sequent__TOP__3(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___nba_sequent__TOP__4(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___nba_comb__TOP__0(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___nba_comb__TOP__1(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___nba_sequent__TOP__5(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___nba_sequent__TOP__6(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___nba_comb__TOP__2(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___act_sequent__TOP__1(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___nba_comb__TOP__4(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___act_comb__TOP__0(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___act_comb__TOP__2(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___act_comb__TOP__1(Vcore_tb___024root* vlSelf);
void Vcore_tb___024root___act_comb__TOP__3(Vcore_tb___024root* vlSelf);

void Vcore_tb___024root___eval_nba(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0xbU)) {
        Vcore_tb___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(8U)) {
        Vcore_tb___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vcore_tb___024root___nba_sequent__TOP__2(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(7U)) {
        Vcore_tb___024root___nba_sequent__TOP__3(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(9U)) {
        Vcore_tb___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(3U) | vlSelf->__VnbaTriggered.at(8U))) {
        Vcore_tb___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(4U) | vlSelf->__VnbaTriggered.at(8U))) {
        Vcore_tb___024root___nba_comb__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(8U)) {
        Vcore_tb___024root___nba_sequent__TOP__5(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0xaU)) {
        Vcore_tb___024root___nba_sequent__TOP__6(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(8U))) {
        Vcore_tb___024root___nba_comb__TOP__2(vlSelf);
    }
    if (((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U)) 
         | vlSelf->__VnbaTriggered.at(8U))) {
        Vcore_tb___024root___act_sequent__TOP__1(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(7U))) {
        Vcore_tb___024root___nba_comb__TOP__4(vlSelf);
    }
    if (((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(8U)) 
         | vlSelf->__VnbaTriggered.at(9U))) {
        Vcore_tb___024root___nba_comb__TOP__5(vlSelf);
    }
    if (((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(3U)) 
         | vlSelf->__VnbaTriggered.at(8U))) {
        Vcore_tb___024root___nba_comb__TOP__6(vlSelf);
    }
    if (((vlSelf->__VnbaTriggered.at(4U) | vlSelf->__VnbaTriggered.at(5U)) 
         | vlSelf->__VnbaTriggered.at(8U))) {
        Vcore_tb___024root___act_comb__TOP__0(vlSelf);
    }
    if (((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(4U)) 
         | vlSelf->__VnbaTriggered.at(8U))) {
        Vcore_tb___024root___nba_comb__TOP__8(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(8U)) {
        Vcore_tb___024root___nba_sequent__TOP__7(vlSelf);
    }
    if (((((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(2U)) 
           | vlSelf->__VnbaTriggered.at(4U)) | vlSelf->__VnbaTriggered.at(5U)) 
         | vlSelf->__VnbaTriggered.at(8U))) {
        Vcore_tb___024root___act_comb__TOP__2(vlSelf);
    }
    if ((((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(3U)) 
          | vlSelf->__VnbaTriggered.at(4U)) | vlSelf->__VnbaTriggered.at(8U))) {
        Vcore_tb___024root___act_comb__TOP__1(vlSelf);
    }
    if ((((((((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(2U)) 
              | vlSelf->__VnbaTriggered.at(3U)) | vlSelf->__VnbaTriggered.at(4U)) 
            | vlSelf->__VnbaTriggered.at(5U)) | vlSelf->__VnbaTriggered.at(6U)) 
          | vlSelf->__VnbaTriggered.at(8U)) | vlSelf->__VnbaTriggered.at(9U))) {
        Vcore_tb___024root___act_comb__TOP__3(vlSelf);
    }
    if (((((((((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U)) 
               | vlSelf->__VnbaTriggered.at(2U)) | vlSelf->__VnbaTriggered.at(3U)) 
             | vlSelf->__VnbaTriggered.at(4U)) | vlSelf->__VnbaTriggered.at(5U)) 
           | vlSelf->__VnbaTriggered.at(6U)) | vlSelf->__VnbaTriggered.at(8U)) 
         | vlSelf->__VnbaTriggered.at(9U))) {
        Vcore_tb___024root___nba_comb__TOP__12(vlSelf);
    }
    if ((((((((((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U)) 
                | vlSelf->__VnbaTriggered.at(2U)) | vlSelf->__VnbaTriggered.at(3U)) 
              | vlSelf->__VnbaTriggered.at(4U)) | vlSelf->__VnbaTriggered.at(5U)) 
            | vlSelf->__VnbaTriggered.at(6U)) | vlSelf->__VnbaTriggered.at(7U)) 
          | vlSelf->__VnbaTriggered.at(8U)) | vlSelf->__VnbaTriggered.at(9U))) {
        Vcore_tb___024root___nba_comb__TOP__13(vlSelf);
    }
    if ((((((((((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U)) 
                | vlSelf->__VnbaTriggered.at(2U)) | vlSelf->__VnbaTriggered.at(3U)) 
              | vlSelf->__VnbaTriggered.at(4U)) | vlSelf->__VnbaTriggered.at(5U)) 
            | vlSelf->__VnbaTriggered.at(6U)) | vlSelf->__VnbaTriggered.at(8U)) 
          | vlSelf->__VnbaTriggered.at(9U)) | vlSelf->__VnbaTriggered.at(0xbU))) {
        Vcore_tb___024root___nba_comb__TOP__14(vlSelf);
    }
}

void Vcore_tb___024root___eval_triggers__act(Vcore_tb___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcore_tb___024root___dump_triggers__act(Vcore_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vcore_tb___024root___eval_act(Vcore_tb___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcore_tb___024root___dump_triggers__nba(Vcore_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vcore_tb___024root___eval(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___eval\n"); );
    // Init
    VlTriggerVec<12> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vcore_tb___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vcore_tb___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("../rtl/tb/core_tb.sv", 12, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vcore_tb___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vcore_tb___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("../rtl/tb/core_tb.sv", 12, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vcore_tb___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vcore_tb___024root___eval_debug_assertions(Vcore_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcore_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore_tb___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
