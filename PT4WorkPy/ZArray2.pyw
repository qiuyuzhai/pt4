from pt4 import *
def solve():
    task("ZArray2")
    n=get()
    a=n*[0]
    a[0]=2
    for i in range (1,n):
        a[i]=a[i-1]*2
    show(a)
    put (a)










start(solve)
