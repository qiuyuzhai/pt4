from pt4 import *
def solve():
    task("ZMatrix43")
    m,n=get2()
    a=m*[0]
    b=n
    for i in range(m):
        a[i]=n*[0]
        for j in range(n):
            a[i][j]=get()
    for j in range(n):
        for i in range(m-1):
            if a[i][j]< a[i+1][j]:
                b-=1
                break
    put(b)
    
        







start(solve)
