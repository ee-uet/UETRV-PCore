#!/usr/bin/env python3

#
# This is free software released into the public domain.
#
# Anyone is free to copy, modify, publish, use, compile, sell, or
# distribute this software, either in source code form or as a compiled
# binary, for any purpose, commercial or non-commercial, and by any
# means.
# 
# Author:   Umer Shahid

import sys
binfile = sys.argv[-1]

with open(binfile, "rb") as f:
    bindata = f.read()

#assert len(bindata) < 4*nwords
#assert len(bindata) % 4 == 0
bytes = len(bindata)
nwords = len(bindata) // 4

#print("55aa33cc")
#print("%02x%02x%02x%02x" % (0, 0, ((bytes>>8) & 0xFF), (bytes & 0xFF)))

for i in range(nwords):
    w = bindata[4*i : 4*i+4]
    print("%02x%02x%02x%02x" % (w[3], w[2], w[1], w[0]))
   
print("00000000")
