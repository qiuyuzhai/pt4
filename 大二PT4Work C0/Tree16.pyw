from pt4 import *

def output(p, n):
    if p == None:
        return
    
    output(p.Left, n)
    output(p.Right, n)
    n -= 1
    if n <= 0:
        put(p.Data)


def solve():
    task("Tree16")
    p, n = get2()
    output(p, n)









start(solve)
