from pt4 import *
    
def solve():
    task("ZArray113")
    n=get()
    a=get_list(n)
    for i in range(n-1,0,-1):
        max_index=i
        for j in range(i):
            if a[j]>a[max_index]:
                max_index=j
        a[i],a[max_index]=a[max_index],a[i]
        put(a)

start(solve)
