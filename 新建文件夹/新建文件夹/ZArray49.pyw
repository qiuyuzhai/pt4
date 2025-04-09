from pt4 import *
def solve():
    task("ZArray49")##
    n=get()
    a=get_list(n)
    k=-1
    for i in range(n):
        if a[i]>n:
            k=i
            break
        for i in range(1,n):
            if a[i] in a[:i]:
                k=i
                break
    put(k)








start(solve)
