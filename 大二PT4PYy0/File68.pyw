from pt4 import *
from struct import unpack
from struct import pack

def solve():##
    task("File68")
    f = open(get(), "rb")
    f1 = open(get(), "wb")
    f2 = open(get(), "wb")
    f.seek(0, 2)
    n = f.tell() // 80
    for i in range(n-1, -1, -1):
        f.seek(i*80)
        s = f.read(80).decode().rstrip()
        a = int(s[3:5])
        b = int(s[6:])
        f1.write(pack("i",a))
        f2.write(pack("i",b))
    f.close()
    f1.close()
    f2.close()


start(solve)







