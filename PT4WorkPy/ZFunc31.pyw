from pt4 import *
def Swap (x1,i,j):
    z=x1[i]
    x1[i]=x1[j]
    x1[j]=z

def solve():
    task("ZFunc31")
    x=[0,0,0,0]
    for i in range(4):
        x[i]=get()
        show(x[i])
    Swap(x,0,1)
    Swap(x,2,3)
    Swap(x,1,2)
    for i in range (4):
        put (x[i])










start(solve)
