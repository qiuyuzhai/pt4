from pt4 import *
def DigitCount (k) :
    a=0
    while k>0:
        k=k/10
        a+=1
    return a    
    


def solve():
    task("ZFunc14")
    m=get()
    put (DigitCount(m))
start(solve)
