from pt4 import *
def solve():
    task("ZMatrix85")
    m=get()
    s=get_matr(m,m)
    a=[]
    for i in range(m):
        b=0
        l=i
        j=0
        while l+1>0:
            b+=s[l][j]/(i+1)
            l-=1
            j+=1
        a.append(b)
    p=m
    for i in range(m-1):
        d=0
        p-=1
        e=m-1
        u=1+i
        for j in range(p):
            b+=s[u][e]/p
            u+=1
            e-=1
        a.append(b)
    put(a)
   
start(solve)
