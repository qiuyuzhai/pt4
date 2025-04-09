from pt4 import *
def solve():
    task("ZArray109")
    n=get()
    a=get_list(n)
    for i in range(len(a)-1,-1,-1):
        if a[i]<0:
            a.insert(i+1,0.0)
    put(a)
    show(a)








start(solve)
