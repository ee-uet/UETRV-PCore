import sys
import serial
import time

port = "/dev/ttyUSB1"

kk = 4
read = 0
print_log = 0

num = int(float(sys.argv[1]) * 1000000)
name = sys.argv[2]

with serial.Serial(port=port, baudrate=num, bytesize=serial.EIGHTBITS, parity=serial.PARITY_NONE, stopbits=serial.STOPBITS_TWO, timeout=2) as ser:
    print("serial baud rate : "+str(num))
    print("send file : "+name);
    with open(name, mode="rb") as fin:
        content = fin.read()
        
        l = len(content)
        count = 0

        while (count < l):
 
            d = content[count:count + kk]
            if count + kk <= l:
                d = content[count:count + kk]
                if print_log == 1:
                    print(f"Sending  {len(d)} bytes: {d}")
                ser.write(d)
                if read == 1:
                    s = ser.read(kk)
                    #n = ser.in_waiting
                    #s = ser.read(n)
                    if print_log == 1:
                        print(f"Received {len(s)} bytes: {s}")
                count += kk   
            if count & 0xFFFFF == 0:
                print(f'{count} bytes transferred')
                
            #time.sleep(0.00017)
        if count < l:
            for x in range(l - count):
                #print('Transmitting')
                d = int.to_bytes(content[count], length=1, byteorder='little')
                if print_log == 1:
                    print(f"Sending {d}")
                ser.write(d)
                if read == 1:
                    s = ser.read(1)
                    if print_log == 1:
                        print(f"Received {s}")
                count += 1
                if count >= l:
                    break
    print("finished transmission!")
 #   print(ser.read(4))
 
 #   output = ser.read(5000000)
 #   with open("uart_output.bin", 'wb') as output_file:
 #       print(output)
 #       output_file.write(output)
