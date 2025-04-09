from pt4 import *
def solve():
    task("ZMatrix73")
    M = get()
    N = get()
    a = [[i for j in range(N)]for i in range(M)]
    for i in range(M):
        for j in range(N):
            a[i][j] = get()
    count = 0
    addj = -1
    for j in range(N):
        for i in range(M):
            if a[i][j] < 0:
                count += 1
        if count == M:
            addj = j
        count = 0
    if addj >= 0:
        b = [[i for j in range(N + 1)]for i in range(M)]
        for i in range(M):
            for j in range(N + 1):
                if j > (addj + 1):
                    put(a[i][j - 1])
                elif j == (addj + 1):
                    tmp = 0.0
                    put(tmp)
                else:
                    put(a[i][j])
    else:
        for i in range(M):
            for j in range(N):
                put(a[i][j])
            





start(solve)
