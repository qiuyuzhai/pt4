from pt4 import *
def solve():
    task("ZArray65")
    n=get()
    a=get_list(n)
    k=get()
    show(k)
    b=a[k]
    for i in range(n):
        a[i]=a[i]+b
    put(a)
   








start(solve)
