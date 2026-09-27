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

        save_to_file(FILES["address"], addresses)
        save_to_file(FILES["data"], data_values)
        save_to_file(FILES["expected"], data_values)

        logger.info("Test data generation completed.")
        return  # Exit test after generation

    # Otherwise, perform testing
    logger.info("Running tests using loaded data...")

    addresses = load_from_file(FILES["address"])
    data_values = load_from_file(FILES["data"])
    expected = load_from_file(FILES["expected"])
    
    for idx, (addr, data, exp) in enumerate(zip(addresses, data_values, expected)):
        # Drive values to DUT
        await RisingEdge(dut.clk) 
         # Get the current value as integer
        dut.dmem_sel_i.value=1
        await RisingEdge(dut.clk)  # let DUT latch it
        #logger.info(dut.dmem_sel_i.value)
        dut.lsummu2dcache_i.value = 0
        current_value = dut.lsummu2dcache_i.value.integer

        # Increment the value by 1
        current_value = current_value + 1

        # Set the new value back to the signal
        dut.lsummu2dcache_i.value = current_value

        # Log the updated value in hexadecimal format
        await RisingEdge(dut.clk)  # let DUT latch it
        #logger.info(hex(dut.lsummu2dcache_i.value))



        addr_new = addr + "00000000"

        current_value=str(bin(int(addr_new,16))[2:] + "00000" + "1")
        dut.lsummu2dcache_i.value = int(current_value,2)
        await RisingEdge(dut.clk)  # let DUT latch it
        #logger.info(bin(dut.lsummu2dcache_i.value))

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
        addr_new = addr + "00000000"

        current_value=str(bin(int(addr_new,16))[2:] + "00000" + "0")
        
        #logger.info(hex(int(current_value,2)))

        # Write back
        dut.lsummu2dcache_i.value = int(current_value,2)
        await RisingEdge(dut.clk)  # let DUT latch it
        
    dut.dcache_flush_i.value = 1
    await RisingEdge(dut.clk)    
    while((dut.dcache2lsummu_o.value.integer & 0x1)==0):
        await RisingEdge(dut.clk)
    dut.dcache_flush_i.value = 0
    await RisingEdge(dut.clk)

    for idx, (addr, data, exp) in enumerate(zip(addresses, data_values, expected)):
        # Drive values to DUT
        await RisingEdge(dut.clk) 
         # Get the current value as integer
        dut.dmem_sel_i.value=1
        await RisingEdge(dut.clk)  # let DUT latch it
        #logger.info(dut.dmem_sel_i.value)
        dut.lsummu2dcache_i.value = 0
        current_value = dut.lsummu2dcache_i.value.integer

        # Increment the value by 1
        current_value = current_value + 1

        # Set the new value back to the signal
        dut.lsummu2dcache_i.value = current_value

        # Log the updated value in hexadecimal format
        await RisingEdge(dut.clk)  # let DUT latch it
        #logger.info(hex(dut.lsummu2dcache_i.value))



        addr_new = addr + "00000000"

        current_value=str(bin(int(addr_new,16))[2:] + "00000" + "1")
        dut.lsummu2dcache_i.value = int(current_value,2)
        await RisingEdge(dut.clk)  # let DUT latch it
        #logger.info(bin(dut.lsummu2dcache_i.value))

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
        addr_new = addr + "00000000"

        current_value=str(bin(int(addr_new,16))[2:] + "00000" + "0")
        
        #logger.info(hex(int(current_value,2)))

        # Write back
        dut.lsummu2dcache_i.value = int(current_value,2)
        await RisingEdge(dut.clk)  # let DUT latch it
        #logger.info(bin(dut.lsummu2dcache_i.value))
        
        addr_int = int(addr,16)
        index = (addr_int >> 4) & 0x7FF 
        #logger.info(hex(index))
        


        offset = (addr_int >> 2) & 0x3
        #logger.info(hex(offset))
        actual_result_entire = dut.wb_dcache_datapath_module.dcache_data_ram_module.dcache_dataram[index].value.integer
         
        expected_result_entire = int(exp, 16)
        #logger.info(offset)
        expected_result = int(exp[::-1][offset*8:(offset*8)+8][::-1],16)
        actual_result = dut.wb_dcache_datapath_module.dcache2lsummu_data_ff.value.integer
        #logger.info(expected_result)
        if (actual_result_entire == expected_result_entire) and (dcache_miss==1) and (expected_result == actual_result):
            logger.info(f"Test {idx}: PASS - Actual: {hex(actual_result)}, Expected: {hex(expected_result)} with dcache_miss={dcache_miss}")
        else:
            logger.error(f"Test {idx}: FAIL - Actual: {hex(int(actual_result))}, Expected: {hex(expected_result)}")
            assert False, f"Mismatch at Test {idx}"
 
