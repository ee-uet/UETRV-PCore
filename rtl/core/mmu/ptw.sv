
`include "../../defines/MMU_defs.svh"

module ptw (

    input   logic                                  rst_n,              // reset
    input   logic                                  clk,                // clock
    
    // MMU <---> PTW interface
    input  wire type_mmu2ptw_s                     mmu2ptw_i,
    output type_ptw2mmu_s                          ptw2mmu_o,

    // PTW <---> TLB interface
    output type_ptw2tlb_s                          ptw2tlb_o,
    output logic                                   itlb_update_o,
    output logic                                   dtlb_update_o,

   // MMU <---> Data memory interface
    input wire type_dmem2mmu_s                     dmem2ptw_i,   
    output type_mmu2dmem_s                         ptw2dmem_o       

);

// Local signals
type_mmu2ptw_s                       mmu2ptw;
type_ptw2mmu_s                       ptw2mmu;

type_ptw2tlb_s                       ptw2tlb;
type_dmem2mmu_s                      dmem2ptw;
type_mmu2dmem_s                      ptw2dmem;

//logic [9:0]                         vpn_0, vpn_1;
//logic [1:0]                         index;

type_ptw_state_e                     ptw_state_ff, ptw_state_next;
type_ptw_levels_e                    ptw_lvl_ff, ptw_lvl_next;
type_pte_sv32_s                      pte;

logic [`XLEN-1:0]                    r_data_ff;
logic                                r_data_valid_ff;

logic                                itlb_update;
logic                                dtlb_update;
logic                                itlb_miss;
logic                                dtlb_miss;


// Is this page table walk for Instruction memory address?
logic iwalk_active_ff, iwalk_active_next;

// Global mapping configuration bit
logic gmap_bit_ff, gmap_bit_next;

// Virtual address that needs page walk
logic [`VALEN-1:0] vaddr_ff,   vaddr_next;

// Data memory request signals
logic [`PALEN-1:0] ptw_paddr_ff, ptw_paddr_next;  
logic r_req_ff, r_req_next; 

// Read the inputs
assign mmu2ptw  = mmu2ptw_i;
assign dmem2ptw = dmem2ptw_i;

assign pte = type_pte_sv32_s'(r_data_ff);

// Output the physical address directly from PTW 
assign ptw2dmem.paddr = ptw_paddr_ff[`PALEN-1:0];
assign ptw2dmem.r_req = r_req_ff;
    
// Configure the signals for respective TLB entry update
assign ptw2tlb.vpn     = vaddr_ff[`VALEN-1:12];
assign ptw2tlb.page_4M = (ptw_lvl_ff == LEVEL_1);
assign ptw2tlb.pte     = pte | (gmap_bit_ff << 5);
assign itlb_miss       = mmu2ptw.en_vaddr & mmu2ptw.itlb_req 
                       & ~mmu2ptw.itlb_hit & ~mmu2ptw.dtlb_req;

assign dtlb_miss       = mmu2ptw.en_ld_st_vaddr & mmu2ptw.dtlb_req 
                       & ~mmu2ptw.dtlb_hit;

//============================= Page table walker to update TLB entry =============================//
always_comb begin : ptw_walker
        // Default assignments
        ptw_paddr_next      = ptw_paddr_ff;
        ptw_state_next      = ptw_state_ff;
        r_req_next          = r_req_ff;

        ptw2mmu.access_exc  = 1'b0;
        ptw2mmu.pte_error   = 1'b0;

        itlb_update         = 1'b0;
        dtlb_update         = 1'b0;

        gmap_bit_next       = gmap_bit_ff; 
        iwalk_active_next   = iwalk_active_ff;
        ptw_lvl_next        = ptw_lvl_ff;   
        vaddr_next          = vaddr_ff;

        case (ptw_state_ff)

            PTW_IDLE: begin
                // By default start with the top level page table
                ptw_lvl_next  = LEVEL_1;
                gmap_bit_next = 1'b0;
                iwalk_active_next   = 1'b0;

                // Handle the ITLB miss
                if (itlb_miss) begin
                    // SV32 physical address is 34-bit
                    ptw_paddr_next    = {mmu2ptw.satp_ppn, mmu2ptw.itlb_vaddr[`VALEN-1:22], 2'b0}; 
                    iwalk_active_next = 1'b1;
                    r_req_next        = 1'b1;
                    vaddr_next        = mmu2ptw.itlb_vaddr;
                    ptw_state_next    = PTW_PROCESS_PTE;
                 
                end else if (dtlb_miss) begin
                    ptw_paddr_next    = {mmu2ptw.satp_ppn, mmu2ptw.dtlb_vaddr[`VALEN-1:22], 2'b0}; 
                    r_req_next        = 1'b1;
                    vaddr_next        = mmu2ptw.dtlb_vaddr;
                    ptw_state_next    = PTW_PROCESS_PTE;              
                end
            end

            PTW_PROCESS_PTE: begin

                // Wait for the read valid signal from data memory
                if (r_data_valid_ff) begin

                    // Latch the global mapping bit
                    gmap_bit_next = pte.g;
               
                    // Validate the PTE for page fault
                    if (!pte.v || (!pte.r && pte.w))
                        ptw_state_next = PTW_PAGE_ERR;
                    
                    // This is a valid PTE, process it
                    else begin
                        ptw_state_next = PTW_IDLE;
                        
                        // Valid PTE, check for read/execute flag bits 
                        if (pte.r || pte.x) begin
                                                        
                            if (iwalk_active_ff) begin
                                // If PTE is not configured for executable, report the error                                
                                if (!pte.x || !pte.a)
                                  ptw_state_next = PTW_PAGE_ERR;
                                // Otherwise update ITLB
                                else
                                  itlb_update = 1'b1;

                            end else begin
                                // For valid PTE, update DTLB
                                if (pte.a && (pte.r || (pte.x && mmu2ptw.mxr))) begin
                                  dtlb_update = 1'b1;
                                end else begin
                                  ptw_state_next = PTW_PAGE_ERR;
                                end
                                // Check for writeable page in case of store operation
                                if (mmu2ptw.is_store && (!pte.w || !pte.d)) begin
                                    dtlb_update = 1'b0;
                                    ptw_state_next   = PTW_PAGE_ERR;
                                end
                            end
                            // Check for ppn alignment in case of super page 
                            if ((ptw_lvl_ff == LEVEL_1) && (pte.ppn[9:0] != '0)) begin
                                ptw_state_next = PTW_PAGE_ERR;
                                dtlb_update = 1'b0;
                                itlb_update = 1'b0;
                            end
                        
                        // This PTE is a pointer to the next level page table
                        end else begin
                            
                            if (ptw_lvl_ff == LEVEL_1) begin
                                // Move to next level page table, 
                                // and initiate next PTE read request
                                ptw_lvl_next   = LEVEL_2;
                                ptw_paddr_next = {pte.ppn, vaddr_ff[21:12], 2'b0};  
                                r_req_next     = 1'b1;  
                                ptw_state_next = PTW_PROCESS_PTE;                               
                            end else if (ptw_lvl_ff == LEVEL_2) begin
                              // Should not have ended up here,
                              // must have been the last level page table
                                ptw_lvl_next   = LEVEL_2;
                                ptw_state_next = PTW_PAGE_ERR;
                            end
                        end
                    end

                    // PMP check to verify the access permission
//                    if (!pmp2ptw.allow_access) begin
//                        itlb_update = 1'b0;
//                        dtlb_update = 1'b0;
//                        // Return page access error with faulting address
//                        ptw_paddr_next = ptw_paddr_ff;
//                        ptw_state_next = PTW_PAGE_ACCESS_ERR;
//                    end
                end
                
            end
            
            // Report error to MMU
            PTW_PAGE_ERR: begin
                ptw_state_next = PTW_IDLE;
                ptw2mmu.pte_error = 1'b1;
            end
            PTW_PAGE_ACCESS_ERR: begin
                ptw_state_next     = PTW_IDLE;
                ptw2mmu.access_exc = 1'b1;
            end
            // Wait for the read valid before going back to IDLE
            PTW_WAIT_R_VALID: begin
                if (r_data_valid_ff) ptw_state_next = PTW_IDLE;
            end
            default: begin
                ptw_state_next = PTW_IDLE;
            end
        endcase
        
        if (mmu2ptw.flush_req) begin
            // Before flushing check if PTE is being looked up 
            if ((ptw_state_ff == PTW_PROCESS_PTE) && (!r_data_valid_ff))
                ptw_state_next = PTW_WAIT_R_VALID;
            else
                ptw_state_next = PTW_IDLE;
        end
end : ptw_walker

always_ff @(posedge clk, negedge rst_n) begin
    if (~rst_n) begin
        ptw_state_ff    <= PTW_IDLE;
        ptw_paddr_ff    <= '0;
        r_req_ff        <= 1'b0;
        iwalk_active_ff <= 1'b0;
        ptw_lvl_ff      <= LEVEL_1;
        vaddr_ff        <= '0;      
        gmap_bit_ff     <= 1'b0;
        r_data_ff       <= '0;
        r_data_valid_ff <= 1'b0;
    end else begin
        ptw_state_ff    <= ptw_state_next;
        ptw_paddr_ff    <= ptw_paddr_next;
        r_req_ff        <= r_req_next;
        iwalk_active_ff <= iwalk_active_next;
        ptw_lvl_ff      <= ptw_lvl_next; 
        vaddr_ff        <= vaddr_next;
        gmap_bit_ff     <= gmap_bit_next;
        r_data_valid_ff <= dmem2ptw.r_valid;
        r_data_ff       <= dmem2ptw.r_data;
    end
end

// Update the outputs
assign ptw2mmu.ptw_active   = (ptw_state_ff != PTW_IDLE); 
assign ptw2mmu.iwalk_active = iwalk_active_ff;
// assign update_vaddr_o = vaddr_ff;

assign itlb_update_o = itlb_update;
assign dtlb_update_o = dtlb_update;
assign ptw2tlb_o     = ptw2tlb;

assign ptw2dmem_o    = ptw2dmem;
assign ptw2mmu_o     = ptw2mmu;

endmodule // ptw

