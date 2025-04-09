from pt4 import *
from struct import*
def solve():
    task("File12")
    f0=open(get(),"rb")
    f1=open(get(),"wb")
    f2=open(get(),"wb")
    f0.seek(0,2)
    n=f0.tell()//4
    for i in range(n):
        f0.seek(4*i)
        str=f0.read(4)
        a=unpack("i",str)[0]
        if (a%2)==0:
            b=pack("i",a)
            f1.write(b)
        else:
            b=pack("i",a)
            f2.write(b)
        
    f0.close()
    f1.close()
    f2.close()




start(solve)
