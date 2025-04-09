from pt4 import *
def solve():
    task("ZArray34")
    m=get_list()
    n=len(m)
    a=[]
    if m[0]<m[1]:
        a.append(m[0])
    if m[n-1]<m[n-2]:
        a.append(m[n-1])
    for i in range(1,len(m)-1):
        if m[i]<m[i+1] and m[i]<m[i-1]:
            a.append(m[i])
    put(max(a))

