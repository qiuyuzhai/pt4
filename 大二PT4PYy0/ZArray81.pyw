from pt4 import *
def solve():
    task("ZArray81")
    n=get()
    a=get_list(n)
    k=get()
    show(k)
    for i in range(k):
        a.insert(i,0.0)
        a.pop()
    put(a)
    show(a)





start(solve)
