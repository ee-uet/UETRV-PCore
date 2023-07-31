Please edit main.c and run 

make.sh

to compile; this will copy bmem.sv to the FPGA sources folder. After programming the FPGA, change serial_sendfile_new.py to set the USB port being used by the UART receiver, and run the following command to transmit an executable over UART:

python3 serial_sendfile.py 1.152 <executable>

For example, to transmit the linux binary image, receive log and store log in the "uart_output.bin" file, run the following command:

python3 serial_sendfile.py 1.152 images/linux_image_5April.bin
