#include <stdlib.h>
#include <iostream>
#include <utility>
#include <string>
#include "Vcore_tb.h"
#include "verilated.h"
#include "verilated_vcd_c.h"


vluint64_t main_time = 0;

double sc_time_stamp () {
 return main_time;
}


int main(int argc, char** argv) {
  std::cout << "\nVerilator: Start of sim\n" << std::endl;

  Verilated::commandArgs(argc, argv);

  Vcore_tb* tb = new Vcore_tb;

  // init trace dump
  VerilatedVcdC* tfp = NULL;

#if VM_TRACE
  Verilated::traceEverOn(true);
  tfp = new VerilatedVcdC;
  tb->trace (tfp, 24);
  tfp->open ("sim.vcd");
#endif
  // Simulate
  while(!Verilated::gotFinish()){
#if VM_TRACE
      tfp->dump (main_time);
#endif
      main_time += 5;
      tb->clk = !tb->clk;
      tb->eval();
  }

#if VM_TRACE
  tfp->close();
#endif

  std::cout << "\nVerilator: End of sim" << std::endl;
  exit(EXIT_SUCCESS);

}