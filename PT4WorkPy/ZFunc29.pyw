from pt4 import *
def AddRightDigit(d,k):
        return k*10+d
def solve():
    task("ZFunc29")
    k=get()
    for d in get2():
        k=AddRightDigit(d,k)
        put (k)








start(solve)
