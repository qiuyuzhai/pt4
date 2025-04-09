from pt4 import *
def solve():
    task("ZArray95")
    m=get()
    a=get_list(m)
    b=a[0]
    for i in range(len(a)-1,0,-1):
        if a[i] == a[i-1]:
            a.pop(i)
    put(a)
    show(a)
        








start(solve)
