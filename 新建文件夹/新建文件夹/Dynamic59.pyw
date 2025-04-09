from pt4 import *
#抄c的这道题
class TNode:
    def __init__(self):
        self.Data = None
        self.Next = None
        self.Prev = None

class TList:
    def __init__(self):
        self.first = None
        self.last = None
        self.current = None

def InsertLast(L, D):
    p = TNode()
    p.Data = D
    p.Next = None
    p.Prev = L.last
    if L.last:
        L.last.Next = p
    else:
        L.first = p
    L.last = p
    L.current = p

def solve():
    task("Dynamic59")
    L = TList()
    L.first, L.last , L.current = get3()
    n = int(get())
    for i in range(n):
        InsertLast(L, int(get()))
    put(L.first, L.last, L.current)

start(solve)