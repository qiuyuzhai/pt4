from pt4 import *
def solve():
    task("Tree28")
    n = get()
    p = Node()
    put(p)
    while n > 0:
        pl = Node()
        p.Data, pl.Data = get2()
        p.Left = pl
        if n != 2:
            pr = Node()
            p.Right = pr
            p = pr
        n -= 2







start(solve)
