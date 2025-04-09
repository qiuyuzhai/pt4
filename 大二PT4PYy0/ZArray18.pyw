from pt4 import *
def solve():
    task("ZArray18")##
    a=get_list(10)
    b=0
    for i in range(10):
        if a[i]<a[9]:
            b=a[i]
            break
    put(b)
    

start(solve)
