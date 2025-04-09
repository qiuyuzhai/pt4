from pt4 import *
def solve():
    task("ZArray59")
    N = get()
    lis = []
    for i in range(N):
        lis.append(get())
    he = 0
    
    for i in range(N):
        he += lis[i]
        put(he / (i + 1))








start(solve)
