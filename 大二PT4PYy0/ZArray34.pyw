from pt4 import *
def solve():
    task("ZArray34")
    n=get()
    a=get_list(n)
    b=[]
    if a[0]<a[1]:
        b.append(a[0])
    for i in range(1,n-1):
        if a[i]<a[i-1] and a[i]<a[i+1]:
            b.append(a[i])
    if a[n-2]>a[n-1]:
        b.append(a[n-1])
    put(max(b))
    show(b)
   
start(solve)
