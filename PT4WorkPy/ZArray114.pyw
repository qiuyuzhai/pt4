from pt4 import *
def solve():
    task("ZArray114")
    N=get()
    a=[0.0]*N
    for i in range(N):
        a[i]=get()
    
    for i in range(1,N):
        k=a[i]
        j=i-1
        while((j>=0) and (a[j]>k)):
            a[j+1] = a[j]
            j=j-1
        
        a[j+1]=k
        for i in range(N):
            put(a[i])

start(solve)
