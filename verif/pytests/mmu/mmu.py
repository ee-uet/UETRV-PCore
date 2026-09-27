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
    "address_mmu": os.path.join(DATA_DIR, "address_mmu.txt"),
    "pte_1_data": os.path.join(DATA_DIR, "pte_1_data.txt"),
    "pte_2_data": os.path.join(DATA_DIR, "pte_2_data.txt"),
    "expected_PA": os.path.join(DATA_DIR, "expected_PA.txt"),
    "expected_4M": os.path.join(DATA_DIR, "expected_4M.txt")
}
GEN = 0 # Set 1 for generating data, 0 for testing
SUPERPAGE = 0
# Utility Functions
def generate_random_address():
    return random.randint(0x80000000, 0x8007FFFF)

def generate_random_data_1(SUPERPAGE=0):
    binary = bin(random.randint(0x08200000, 0x082000ff))[2:].zfill(32)

    if SUPERPAGE == 0:
        binary = binary[:28] + "0001"   # force last 4 bits, non-superpage case

    # SUPERPAGE == 1 skips the line above entirely, leaving the last 4 bits
    # as whatever the random value naturally produced

    binary_list = list(binary)

    binary_list[-7] = "1"

    if binary_list[-4] == "1" and binary_list[-2] == "0":
        binary_list[-2] = "1"

    binary = "".join(binary_list)
    return int(binary, 2)
def generate_random_data_2():
    binary = bin(random.randint(0x08300000, 0x083000ff))[2:].zfill(32)
    binary_list = list(binary)

    binary_list[-7] = "1"
    binary = "".join(binary_list)

    binary = binary[:30] + "11"   # first 30 bits (now correctly padded) + fixed "11" suffix = 32 bits

    return int(binary, 2)
def generate_expected_PA(pte_data, address, exp_4M):
    pte_bin  = bin(int(pte_data, 16))[2:].zfill(32)   # full pte word, MSB-first
    addr_bin = bin(int(address, 16))[2:].zfill(32)    # full vaddr, MSB-first

    # ppn = pte_bin[0:22]   -> bits [31:10] of pte_data (matches struct: ppn is top 22 bits)
    # vaddr[11:0] = addr_bin[20:32] -> page offset
    PA_addr = int(pte_bin[0:22] + addr_bin[20:32], 2)

    if int(exp_4M, 16) == 1:
        # Superpage: override paddr[21:0] with vaddr[21:0], keep top 12 bits (ppn[21:10]) of PA_addr
        pa_bin = bin(PA_addr)[2:].zfill(34)           # PA is 34 bits (22-bit ppn + 12-bit offset)
        PA_addr = int(pa_bin[0:12] + addr_bin[10:32], 2)

    return PA_addr

def generate_4M_signal(pte_data):
    if (bin(int(pte_data,16))[2:][-4:]=="0001"):
        return 0
    else:
        return 1

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
        await Timer(period // 2, units='ns')  
        dut.clk.value = 1
        await Timer(period // 2, units='ns')  


async def reset_and_read(dut):

    cocotb.fork(clk_gen(dut))

    # Set reset low
    dut.rst_n.value = 0
    await Timer(1, units="ns")  # small delay after setting reset if needed

    for _ in range(10):
        await RisingEdge(dut.clk)

    # Release reset
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)

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
        pte_1_data_values = [hex(generate_random_data_1()) for _ in range(100)]
        pte_2_data_values = [hex(generate_random_data_2()) for _ in range(100)]
        #logger.info(pte_2_data_values)
        pte_1=[pte_1_data_values[i][8:] for i in range(100)]
        #logger.info(pte_1)
        expected_4M_values = [hex(generate_4M_signal(pte_1_data_values[i])) for i in range(100)]
        for i in range(100):
            #logger.info(pte_1[i][8:])
            if (int(expected_4M_values[i],16)==1):
                expected_PA_addresses = [bin(generate_expected_PA(pte_1_data_values[i],addresses[i],expected_4M_values[i])) for i in range(100)]
            else:
                expected_PA_addresses = [bin(generate_expected_PA(pte_2_data_values[i],addresses[i],expected_4M_values[i])) for i in range(100)]



        

        save_to_file(FILES["address_mmu"], addresses)
        save_to_file(FILES["pte_1_data"], pte_1_data_values)
        save_to_file(FILES["pte_2_data"], pte_2_data_values)
        save_to_file(FILES["expected_PA"], expected_PA_addresses)
        save_to_file(FILES["expected_4M"], expected_4M_values)

        logger.info("Test data generation completed.")
        return  # Exit test after generation

    # Otherwise, perform testing
    logger.info("Running tests using loaded data...")

    addresses = load_from_file(FILES["address_mmu"])
    data_1_values = load_from_file(FILES["pte_1_data"])
    data_2_values = load_from_file(FILES["pte_2_data"])
    expected_PA = load_from_file(FILES["expected_PA"])
    expected_4M = load_from_file(FILES["expected_4M"])

    # ----------------------------------------------------------------------

    for idx, (addr, data1, data2, exp_PA, exp_4M) in enumerate(zip(addresses, data_1_values, data_2_values, expected_PA, expected_4M)):

        for _ in range(5):
            await RisingEdge(dut.clk)

        if (int(exp_4M,16)==1):
            dut.lsu2mmu_i.value = int(hex(int("1000110011111000011000",2)) + '64' + addr[2:],16)
            await RisingEdge(dut.clk)
            dut.dcache2mmu_i.value = int(bin(int(data1[2:],16)) + "1",2)
            await RisingEdge(dut.clk)
            dut.dcache2mmu_i.value = int(bin(int(data1[2:],16)) + "0",2)
            for _ in range(10):
                await RisingEdge(dut.clk)
        else:
            dut.lsu2mmu_i.value = int(hex(int("1000110011111000011000",2)) + '64' + addr[2:],16)
            await RisingEdge(dut.clk)
            dut.dcache2mmu_i.value = int(bin(int(data1[2:],16)) + "1",2)
            await RisingEdge(dut.clk)
            dut.dcache2mmu_i.value = int(bin(int(data2[2:],16)) + "1",2)
            await RisingEdge(dut.clk)
            
            for _ in range(10):
                await RisingEdge(dut.clk)
            dut.dcache2mmu_i.value = int(bin(int(data2[2:],16)) + "0",2)
        actual_result=bin(dut.mmu2lsu_o.value)[:-3]
        if (hex(int(exp_PA,2))==hex(int(actual_result,2))):
            print("PASS")
        else:
            print("FAIL")
