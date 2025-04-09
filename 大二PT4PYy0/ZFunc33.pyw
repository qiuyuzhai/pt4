from pt4 import *
def SortInc3(s):
     n=3
     for i in range(n):
            for j in range(1,n-i):
                 if s[j-1]>s[j]:
                        s[j-1],s[j]=s[j],s[j-1]
     return s

def solve():
    task("ZFunc33")##
    x0=get()
    y0=get()
    z0=get()
    a=[x0,y0,z0]
    show(a)
    x1=get()
    y1=get()
    z1=get()
    b=[x1,y1,z1]
    show(b)
    put(SortInc3(a))
    put(SortInc3(b))

start(solve)
