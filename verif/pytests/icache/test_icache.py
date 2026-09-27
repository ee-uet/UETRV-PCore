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
    return random.randint(0x80000000, 0x8001FFFF)

def generate_random_data():
    return random.getrandbits(128)

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

    # ----------- NEW: Filter to keep only latest [14:4] address entries -------------

    # Step 1: Build latest index for each address[14:4]
    latest_entries = {}
    for idx, addr in enumerate(addresses):
        addr_int = int(addr, 16)
        addr_key = (addr_int >> 4) & 0x1FF  # 11 bits
        latest_entries[addr_key] = idx  # always overwrite to keep latest

    # Step 2: Build filtered lists
    final_indices = sorted(latest_entries.values())

    addresses = [addresses[i] for i in final_indices]
    data_values = [data_values[i] for i in final_indices]
    expected = [expected[i] for i in final_indices]

    logger.info(f"After filtering, {len(addresses)} unique addresses kept.")

    # ----------------------------------------------------------------------

    # First phase
    for idx, (addr, data, exp) in enumerate(zip(addresses, data_values, expected)):
        await RisingEdge(dut.clk)
        dut.imem_sel_i.value = 1
        await RisingEdge(dut.clk)
        

        current_value = str(bin(int(addr,16))[2:] + "100")
        dut.if2icache_i.value = int(current_value,2)
        await RisingEdge(dut.clk)
        #logger.info(bin(dut.if2icache_i.value))
        for _ in range(10):
            await RisingEdge(dut.clk)

        read_data = str(bin(int(data,16))[2:] + "0")
        dut.mem2icache_i.value = int(read_data,2)
        await RisingEdge(dut.clk)

        for _ in range(10):
            await RisingEdge(dut.clk)

        dut.mem2icache_i.value = dut.mem2icache_i.value | 0x1
        for _ in range(10):
            await RisingEdge(dut.clk)
        dut.mem2icache_i.value = dut.mem2icache_i.value & 0x0

    # Second phase
    for idx, (addr, data, exp) in enumerate(zip(addresses, data_values, expected)):
        await RisingEdge(dut.clk)
        dut.imem_sel_i.value = 1
        await RisingEdge(dut.clk)


        current_value = str(bin(int(addr,16))[2:] + "100")
        dut.if2icache_i.value = int(current_value,2)
        await RisingEdge(dut.clk)
        logger.info(bin(dut.if2icache_i.value))
        for _ in range(10):
            await RisingEdge(dut.clk)

        icache_hit = dut.icache_hit.value.integer


        addr_int = int(addr,16)
        offset = (addr_int >> 2) & 0x3

        exp_padded = exp[2:].zfill(32)  # 128 bits / 4 = 32 hex digits
        expected_result = int(exp_padded[::-1][offset*8:(offset*8)+8][::-1],16)

        actual_result =dut.icache2if_data_next.value.integer

        if (icache_hit == 1) and (expected_result == actual_result):
            logger.info(f"Test {idx}: PASS - Actual: {hex(actual_result)}, Expected: {hex(expected_result)} with icache_hit={icache_hit}")
        else:
            logger.error(f"Test {idx}: FAIL - Actual: {hex(int(actual_result))}, Expected: {hex(expected_result)}")
            assert False, f"Mismatch at Test {idx}"
