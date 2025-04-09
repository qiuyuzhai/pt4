from pt4 import *
def solve():
    task("ZArray79")
    a=get_list()
    a.pop()
    a.insert(0,0.0)
    put(a)

def solve2():
    task("ZArray79")
    a=get_list()
    for i in range(len(a)-2,-1,-1):
        a[i+1]=a[i]
    a[0]=0.0
    









start(solve)
