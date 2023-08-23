# aclk {FREQ_HZ 20000000 CLK_DOMAIN nexys_shell_clk PHASE 0.0} aclk1 {FREQ_HZ 50000000 CLK_DOMAIN nexys_shell_mig_7series_0_0_ui_clk PHASE 0}
# Clock Domain: nexys_shell_clk
create_clock -name aclk -period 50.000 [get_ports aclk]
# Clock Domain: nexys_shell_mig_7series_0_0_ui_clk
create_clock -name aclk1 -period 20.000 [get_ports aclk1]
# Generated clocks
