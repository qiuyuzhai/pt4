from pt4 import *
def solve():
    task("ZMatrix91")
    m=get()
    a=get_matr(m)
    for j in range(m):
        for i in range(j):
            a[i][j]=0.0
    for i in range(m):
        for j in range(m):
            if j==i:
                a[i][j]=0.0
    put(a)






start(solve)
