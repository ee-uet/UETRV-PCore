## Opening project in Vivado 2022
Type in the following command to open the project in Vivado 2022
```
vivado fpga-nexys-a7/fpga-nexys-a7.xpr
```

## Generate bitstream
New bitstream can be generated with the exisitng project or you may find old bitstreams in folder ``old_bits``

## Booting Linux Image
* Load the bitstream on the FPGA, your serial monitor is show message `Load File`
* Type in the following commands to load the prebuilt Linux image
  ```
  cd sdk/load_uart
  python3 serial_sendfile.py <baud_rate in MHz> <path/to/image/file>
  ```
* Baud rate of existing bitstream is ``1250000``. Sample images are saved in ``sdk/load_uart`` folder.
* If using default baud rate and default bitstream, the following command can be run
  ```
  python3 serial_sendfile.py 1.25 imem12.bin
  ```
