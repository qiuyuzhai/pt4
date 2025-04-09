from pt4 import *
def solve():
    task("ZMatrix73")##
    m,n=get2()
    a=m*[0]
    b=[0]*n
    for i in range(m):
         a[i]=get_list(n)
    x=0
    cnt=0
    for j in range(n-1,-1,-1):
        allNegative=True
        for i in range(m):
                if(a[i][j]>=0):
                     allNegative=False
                     cnt+=1
                     break
        if cnt==len(a[0]):
           x=1
        elif allNegative:
             t=j
             break
    if(x!=1):
         for j in range(n-1,-1,-1):
                for i in range(m):
                     a[i].insert(t+1,0.00)
                break
    put(a)



start(solve)
