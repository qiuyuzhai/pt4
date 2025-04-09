from pt4 import *

def RingS(r1,r2):
    res=0
    res=3.14*(r1*r1-r2*r2)
    return res
    
def solve():
    task("ZFunc4")
    for i in range(3):
        r1,r2=get2()
        put(RingS(r1,r2))
        r1=0
        r2=0








start(solve)
