from pt4 import *
def GCD(a,b):
    r=a%b
    while r!=0:
        a=b 
        b=r
        r=a%b
    return b

def solve():
    task("ZFunc49")
    a,b,c,d=get4()
    m=GCD(a,b)
    n=GCD(a,c)
    t=GCD(b,c)
    put (GCD(m,c))
    put (GCD(n,d))
    put (GCD(t,d))








start(solve)
