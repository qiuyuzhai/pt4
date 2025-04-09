from pt4 import *
def solve():
    task("ZMatrix59")
    M = get()
    N = get()
    a = [[i for j in range(N)]for i in range(M)]
    for i in range(M):
        for j in range(N):
            a[i][j] = get()
    for i in range(M - 1, -1, -1):
        for j in range(N):
            put(a[i][j])
start(solve)


