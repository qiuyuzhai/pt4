from pt4 import *
def solve():
    task("ZMatrix77")
    M = get()
    N = get()
    a = []
    last = []
    
    for i in range(M):
        a.append([])
        for j in range(N):
            a[i].append(get())
    for i in range(N):
        last.append(i)
    
    Ni = N
    for i in range(1, N):
        for j in range(1, Ni):
            if a[M - 1][last[j]] > a[M - 1][last[j - 1]]:
                c = last[j]
                last[j] = last[j - 1]
                last[j - 1] = c
        Ni -=1
        
    for i in range(M):
        for j in range(N):
            put(a[i][last[j]])








start(solve)
