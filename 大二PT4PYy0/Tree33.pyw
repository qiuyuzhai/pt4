from pt4 import *
k = 0
f = 0
a = 0

def CreateTree(n, d):
    global k
    global f
    global a
    if n == 0:
        return None
    p = Node()
    p.Data = d
    p.Left = CreateTree(n / 2, d + 1)
    p.Right = CreateTree(n - 1 - n / 2, d + 1)
    return p

def solve():
    task("Tree33")
    put(CreateTree(get(), 0))








start(solve)
