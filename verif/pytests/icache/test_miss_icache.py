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
    if len(hex_string) != 32:
        hex_string = hex_string.zfill(32)


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

    # First phase
    for idx, (addr, data, exp) in enumerate(zip(addresses, data_values, expected)):
        i = 0
        for addr2 in addresses:
            if str(addr) == str(addr2):
                continue  # Skip comparing addr with itself
            if str(addr)[:8] == str(addr2)[:8]:
                i = 1
                break
        if i == 1:
            continue
        await RisingEdge(dut.clk)
        dut.imem_sel_i.value = 1
        await RisingEdge(dut.clk)
        
        
        current_value = str(bin(int(addr,16))[2:] + "100")
        dut.if2icache_i.value = int(current_value,2)
        await RisingEdge(dut.clk)
        logger.info(bin(dut.if2icache_i.value))
        for _ in range(10):
            await RisingEdge(dut.clk)

        read_data = str(bin(int(data,16))[2:] + "0")
        dut.mem2icache_i.value = int(read_data,2)
        await RisingEdge(dut.clk)

        for _ in range(10):
            await RisingEdge(dut.clk)
        icache_miss = dut.icache_miss.value.integer

        dut.mem2icache_i.value = dut.mem2icache_i.value | 0x1
        for _ in range(10):
            await RisingEdge(dut.clk)
        dut.mem2icache_i.value = dut.mem2icache_i.value & 0x0
        addr_int = int(addr,16)
        offset = (addr_int >> 2) & 0x3

        exp_padded = exp[2:].zfill(32)  # 128 bits / 4 = 32 hex digits
        expected_result = int(exp_padded[::-1][offset*8:(offset*8)+8][::-1],16)

        actual_result =dut.icache2if_data_next.value.integer

        if (icache_miss == 1) and (expected_result == actual_result):
            logger.info(f"Test {idx}: PASS - Actual: {hex(actual_result)}, Expected: {hex(expected_result)} with icache_miss={icache_miss}")
        else:
            logger.error(f"Test {idx}: FAIL - Actual: {hex(int(actual_result))}, Expected: {hex(expected_result)}")
            assert False, f"Mismatch at Test {idx}"
        

 
