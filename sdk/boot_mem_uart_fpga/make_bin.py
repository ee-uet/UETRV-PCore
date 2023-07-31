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
outfile = sys.argv[-2]

with open(binfile, "rb") as bfr:
    bindata = bfr.read()

bfr.close()

size = len(bindata)
bytes = size.to_bytes(4, 'little')
with open(outfile, "wb") as bfw:
    bfw.write(bytes)
    bfw.write(bindata)

bfw.close()
