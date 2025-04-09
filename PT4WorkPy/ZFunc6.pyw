from pt4 import *

def SumRange(a,b):
    res=0
    for i in range(a,b+1):
        res+=i
    return res


def solve():
    task("ZFunc6")
    a=get()
    b=get()
    c=get()
    put(SumRange(a,b),SumRange(b,c))







start(solve)
