from pt4 import *
def Create(p):
    if not p:
        return None
    data=p.Data
    left=p.Left
    n=Node(data)
    n.Left=Create(left)
    n.Right=Create(left.Right) if left else None
    return n

def solve():
    task("Tree87")
    a1=get()
    put(Create(a1))








start(solve)
