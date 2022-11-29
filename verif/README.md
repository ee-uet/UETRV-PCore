# RISC-V Compatibilty Tests

Follow the following steps to run the Compatibility tests on PCORE


1. Make sure you have setup SPIKE (RISC-V ISS) on your system. Follow [these](https://riscof.readthedocs.io/en/stable/installation.html#install-plugin-models) instructions to install SPIKE.

2. Install the required tools by running the following command.

        sudo apt-get install -y python3-setuptools gcc-riscv64-unknown-elf
        pip3 install git+https://github.com/riscv/riscof.git

3. Clone the architecture compatibilty tests repository in `verif` directory.

        git clone https://github.com/riscv-non-isa/riscv-arch-test

4. Run the riscof from the `verif` directory
        
        riscof -v debug run --config=config.ini \
        --suite=./riscv-arch-test/riscv-test-suite/rv32i_m/I \
        --env=./riscv-arch-test/riscv-test-suite/env

