import struct
from pt4 import *
def solve():
    task("Text41")
    f1=open(get(),"r+b")
    f2=open(get(),"r+b")
    f3=open(get(),"r+b")
    f4=open(get(),"w")
    temp="|"
    bs=f1.read(4)
    while bs:
        t=""
        t+=temp
        a=struct.unpack("i",bs)
        b=a[0]
        s=str(b)
        s=s.ljust(20)
        t+=s
        a=struct.unpack("i",f2.read(4))
        b=a[0]
        s=str(b)
        s=s.ljust(20)
        t+=s
        a=struct.unpack("i",f3.read(4))
        b=a[0]
        s=str(b)
        s=s.ljust(20)
        t+=s+temp+"\n"
        f4.write(t)
        bs=f1.read(4)
    f1.close()
    f2.close()
    f3.close()
    f4.close()
start(solve)









