from pt4 import *
from struct import unpack
from struct import pack

def solve():
    task("File68")
    f = open(get(), "rb")
    f1 = open(get(), "wb")
    f2 = open(get(), "wb")
    f.seek(0, 2)
    n = f.tell() // 80
    for i in range(n-1, -1, -1):
        f.seek(i*80)
        m = f.read(80).decode().rstrip()
        a1 = int(m[3:5])
        a2 = int(m[6:])
        f1.write(pack("i",a1))
        f2.write(pack("i",a2))
    f.close()
    f1.close()
    f2.close()
start(solve)
