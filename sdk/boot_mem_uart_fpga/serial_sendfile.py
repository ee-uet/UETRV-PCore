import sys
import serial
import time

port = "/dev/ttyUSB1"

num = int(float(sys.argv[1]) * 1000000)
name = sys.argv[2]

with serial.Serial(port=port, baudrate=num, bytesize=serial.EIGHTBITS, parity=serial.PARITY_NONE, stopbits=serial.STOPBITS_ONE, timeout=10) as ser:
    print("serial baud rate : "+str(num))
    print("send file : "+name);
    with open(name, mode="rb") as fin:
        content = fin.read()
        #ser.write(content)
        for k in range(len(content)):
            d = int.to_bytes(content[k], length=1, byteorder='little')
            print(f"Sending {d}")
            ser.write(d)
            s = ser.read(1)
            print(f"Received {s}")
#        l = len(content)
#        count = 0
#        #ser.write(int.to_bytes(l, length=4, byteorder='little'))
#        r = b'r'
#        kk = 1024
#        k = kk + 4
#        while (count < l):
#            while r != b'r':
#                r = ser.read(1)
#            r = 1
#            d = content[count:count + kk]
#            if count + kk - 1 <= l:
#                d = count[count:count + kk]
#                ser.write(d)
#                count += kk
#            for x in range(k):
#                #print('Transmitting')
#                d = int.to_bytes(content[count], length=1, byteorder='little')
#                #print(count)
#                ser.write(d)
#                if count % 100000 == 0:
#                    print(f'{count} bytes transferred')
#                count += 1
#                if count >= l:
#                    break
#            k = kk
#            if count & 0xF0 == 0:
#                print(f'{count} bytes transferred')
                
            #print(ser.read(1))
            #time.sleep(0.0002)
            #time.sleep(0.00017)
    #print("finished transmission!")
    print(ser.read(4))
    #with serial.Serial(port=port, baudrate=num/4, bytesize=serial.EIGHTBITS, parity=serial.PARITY_NONE, stopbits=serial.STOPBITS_ONE, timeout=10) as ser:
    output = ser.read(5000000)
    with open("uart_output.bin", 'wb') as output_file:
        print(output)
        output_file.write(output)
