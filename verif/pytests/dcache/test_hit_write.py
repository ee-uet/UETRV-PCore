import cocotb
from cocotb.regression import TestFactory
from cocotb.triggers import RisingEdge, Timer
from cocotb.binary import BinaryValue
import random
import os
import logging

# Setup logging to show logs on terminal
logger = logging.getLogger()
logger.setLevel(logging.INFO)

# Create console handler and set level to INFO
ch = logging.StreamHandler()
ch.setLevel(logging.INFO)

# Create formatter and add it to the handler
formatter = logging.Formatter('%(asctime)s - %(levelname)s - %(message)s')
ch.setFormatter(formatter)

# Add the handler to the logger
logger.addHandler(ch)

# Configuration
DATA_DIR = "test_data"
FILES = {
    "address": os.path.join(DATA_DIR, "address.txt"),
    "data": os.path.join(DATA_DIR, "data.txt"),
    "expected": os.path.join(DATA_DIR, "expected.txt"),
    "sel_byte": os.path.join(DATA_DIR, "sel_byte.txt"),
    "wr_data": os.path.join(DATA_DIR, "wr_data.txt")
}
GEN = 0  # Set 1 for generating data, 0 for testing

# Utility Functions
def generate_random_address():
    return random.randint(0x80000000, 0x8007FFFF)

def generate_random_data():
    # Generate a random 128-bit number
    random_number = random.getrandbits(128)

    # Convert to hex, remove the '0x' prefix, and zero-fill to ensure 32 hex digits
    hex_string = hex(random_number)[2:]
    if (hex_string != 32):
        hex_string = hex_string + "0"*(32-len(hex_string))

    # Convert back to an integer
    return int(hex_string, 16)
def generate_random_sel_byte():
    return random.randint(0x0,0xf)

def generate_random_wr_data():
    # Generate a random 128-bit number
    random_number = random.getrandbits(32)
    # Convert to hex, remove the '0x' prefix, and zero-fill to ensure 32 hex digits
    hex_string = hex(random_number)[2:]
    if (hex_string != 8):
        hex_string = hex_string + "0"*(8-len(hex_string))

    # Convert back to an integer
    return int(hex_string, 16)
def save_to_file(filename, data_list):
    os.makedirs(DATA_DIR, exist_ok=True)
    with open(filename, 'w') as f:
        for item in data_list:
            f.write(f"{item}\n")

def load_from_file(filename):
    with open(filename, 'r') as f:
        return [line.strip() for line in f]


# Clock generator coroutine
async def clk_gen(dut, period=10):
    while True:
        dut.clk.value = 0
        await Timer(period // 2, units='ns')  # Half clock period
        dut.clk.value = 1
        await Timer(period // 2, units='ns')  # Half clock period


# Cocotb Test

async def reset_and_read(dut):
    # Start clock generator

    cocotb.fork(clk_gen(dut))

    # Set reset low
    dut.rst_n.value = 0
    await Timer(1, units="ns")  # small delay after setting reset if needed

    # Wait for 10 rising edges of clk
    for _ in range(10):
        await RisingEdge(dut.clk)

    # Release reset
    dut.rst_n.value = 1

    # Wait for 1 clock cycle after reset release
    await RisingEdge(dut.clk)

    # Now you can continue with your test
    logger.info("Reset sequence done. Ready for test operations.")

@cocotb.test()
async def memory_operations_test(dut):
    """Test DUT memory operations based on random/generated data"""
    logger.info(dut)
    await reset_and_read(dut)

    if GEN == 1:
        # Generate test data
        logger.info("Generating test data...")
        addresses = [hex(generate_random_address()) for _ in range(100)]
        data_values = [hex(generate_random_data()) for _ in range(100)]
        sel_byte    = [hex(generate_random_sel_byte()) for _ in range(100)]
        wr_data     = [hex(generate_random_wr_data()) for _ in range(100)]

        save_to_file(FILES["address"], addresses)
        save_to_file(FILES["data"], data_values)
        save_to_file(FILES["expected"], data_values)
        save_to_file(FILES["sel_byte"], sel_byte)
        save_to_file(FILES["wr_data"], wr_data)

        logger.info("Test data generation completed.")
        return  # Exit test after generation

    # Otherwise, perform testing
    logger.info("Running tests using loaded data...")

    addresses = load_from_file(FILES["address"])
    data_values = load_from_file(FILES["data"])
    wr_data = load_from_file(FILES["wr_data"])
    expected = load_from_file(FILES["wr_data"])
    sel_byte = load_from_file(FILES["sel_byte"])
    # ----------- NEW: Filter to keep only latest [14:4] address entries -------------

    # Step 1: Build latest index for each address[14:4]
    latest_entries = {}
    for idx, addr in enumerate(addresses):
        addr_int = int(addr, 16)
        addr_key = (addr_int >> 4) & 0x7FF  # 11 bits
        latest_entries[addr_key] = idx  # always overwrite to keep latest

    # Step 2: Build filtered lists
    final_indices = sorted(latest_entries.values())

    addresses = [addresses[i] for i in final_indices]
    data_values = [data_values[i] for i in final_indices]
    expected = [expected[i] for i in final_indices]
    wr_data = [wr_data[i] for i in final_indices]
    sel_byte = [sel_byte[i] for i in final_indices]

    logger.info(f"After filtering, {len(addresses)} unique addresses kept.")

    # ----------------------------------------------------------------------

    for idx, (addr, data, exp, sel, wr_dt) in enumerate(zip(addresses, data_values, expected, sel_byte, wr_data)):
        # Drive values to DUT
        await RisingEdge(dut.clk) 
         # Get the current value as integer
        dut.dmem_sel_i.value=1
        await RisingEdge(dut.clk)  # let DUT latch it
        #logger.info(dut.dmem_sel_i.value)
        dut.lsummu2dcache_i.value = 0
        current_value = dut.lsummu2dcache_i.value.integer
        #logger.info(wr_dt)

        # Increment the value by 1
        current_value = current_value + 1

        # Set the new value back to the signal
        dut.lsummu2dcache_i.value = current_value

        # Log the updated value in hexadecimal format
        await RisingEdge(dut.clk)  # let DUT latch it
        #logger.info(hex(dut.lsummu2dcache_i.value))



        addr_new = addr + wr_dt[2:]

        current_value=str(bin(int(addr_new,16))[2:] + str(bin(int(sel, 16))[2:].zfill(4)) + "11")
        dut.lsummu2dcache_i.value = int(current_value,2)
        await RisingEdge(dut.clk)  # let DUT latch it
        #logger.info(hex(dut.lsummu2dcache_i.value))

        read_data = str(bin(int(data,16))[2:]+"0")
        dut.mem2dcache_i.value= int(read_data,2)
        await RisingEdge(dut.clk)  # let DUT latch it
        #logger.info(bin(dut.mem2dcache_i.value))

        for _ in range(10):
            await RisingEdge(dut.clk)
        dut.mem2dcache_i.value = dut.mem2dcache_i.value | 0x1
        await RisingEdge(dut.clk)  # let DUT latch it
        dcache_miss = dut.wb_dcache_controller_module.dcache_miss.value.integer
        
        #logger.info(dcache_miss)
        
        for _ in range(2):
            await RisingEdge(dut.clk) 
        addr_new = addr + wr_dt[2:]

        current_value=str(bin(int(addr_new,16))[2:] + str(bin(int(sel, 16))[2:].zfill(4)) + "00")
        
        #logger.info(hex(int(current_value,2)))

        # Write back
        dut.lsummu2dcache_i.value = int(current_value,2)
        await RisingEdge(dut.clk)  # let DUT latch it
    for idx, (addr, data, exp, sel, wr_dt) in enumerate(zip(addresses, data_values, expected, sel_byte, wr_data)):
        # Drive values to DUT
        await RisingEdge(dut.clk) 
         # Get the current value as integer
        dut.dmem_sel_i.value=1
        await RisingEdge(dut.clk)  # let DUT latch it
        #logger.info(dut.dmem_sel_i.value)
        dut.lsummu2dcache_i.value = 0
        current_value = dut.lsummu2dcache_i.value.integer
        #logger.info(wr_dt)

        # Increment the value by 1
        current_value = current_value + 1

        # Set the new value back to the signal
        dut.lsummu2dcache_i.value = current_value

        # Log the updated value in hexadecimal format
        await RisingEdge(dut.clk)  # let DUT latch it
        #logger.info(hex(dut.lsummu2dcache_i.value))



        addr_new = addr + wr_dt[2:]

        current_value=str(bin(int(addr_new,16))[2:] + str(bin(int(sel, 16))[2:].zfill(4)) + "11")
        dut.lsummu2dcache_i.value = int(current_value,2)
        await RisingEdge(dut.clk)  # let DUT latch it
        #logger.info(hex(dut.lsummu2dcache_i.value))

        dcache_hit = dut.wb_dcache_controller_module.dcache_hit.value.integer
        
        #logger.info(dcache_miss)
        
        for _ in range(2):
            await RisingEdge(dut.clk) 
        addr_new = addr + wr_dt[2:]

        current_value=str(bin(int(addr_new,16))[2:] + str(bin(int(sel, 16))[2:].zfill(4)) + "00")
        
        #logger.info(hex(int(current_value,2)))

        # Write back
        write_check = dut.wb_dcache_datapath_module.cache_wr_i.value.integer
        dut.lsummu2dcache_i.value = int(current_value,2)
        await RisingEdge(dut.clk)  # let DUT latch it
        #write_check = dut.wb_dcache_datapath_module.cache_wr_i.value.integer
        #logger.info(bin(dut.lsummu2dcache_i.value))
        
        addr_int = int(addr,16)
        index = (addr_int >> 4) & 0x7FF 
        #logger.info(hex(index))
        


        offset = (addr_int >> 2) & 0x3
        #logger.info(hex(offset))
        expected_result = 0
        sel_bin=str(bin(int(sel, 16))[2:].zfill(4)) 
        for i in range(4):
            if sel_bin[3 - i] == '1':  
                byte = (int(exp,16) >> (i * 8)) & 0xFF
                expected_result |= (byte << (i * 8))
            actual_result = dut.wb_dcache_datapath_module.cache_word_write.value.integer
        
        #logger.info(expected_result)
        if (dcache_hit==1) and (expected_result == actual_result):
            logger.info(f"Test {idx}: PASS - Actual: {hex(actual_result)}, Expected: {hex(expected_result)} with dcache_hit={dcache_hit} and write check={write_check}")
        else:
            logger.error(f"Test {idx}: FAIL - Actual: {hex(int(actual_result))}, Expected: {hex(expected_result)}")
            assert False, f"Mismatch at Test {idx}"

