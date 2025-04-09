from pt4 import *
def solve():
    task("ZMatrix57")##
    m,n=get2()
    a=m*[0]
    for i in range(m):
        a[i]=get_list(n)
    h=int(m/2)
    w=int(n/2)
    for i in range(h):
        for j in range(w):
            a[i][j],a[i+h][j+w]=a[i+h][j+w],a[i][j]
    put(a)


start(solve)
