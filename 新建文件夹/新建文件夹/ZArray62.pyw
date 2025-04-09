from pt4 import *
def solve():
    task("ZArray62")
    n=get()
    a=get_list(n)
    b=[]
    c=[]
    for i in range(n):
        if a[i]>0:
            b.append(a[i])
        if a[i]<0:
            c.append(a[i])
    put(len(b),b)
    put(len(c),c)







start(solve)
