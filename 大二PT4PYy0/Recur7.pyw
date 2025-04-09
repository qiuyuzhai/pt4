from pt4 import *

def combin2(n,k):
    return 1 if k==0 or k==n else combin2(n-1,k)+combin2(n-1,k-1)
    
def solve():
    task("Recur7")
    n=get()
    show(n)
    for i in get5():
        put(combin2(n,i))








start(solve)
