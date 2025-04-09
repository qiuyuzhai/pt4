from pt4 import *
def AddNode(p, d):
    if p == None:
        p1 = Node()
        p1.Data = d
        p1.Left = p1.Right = None
        return p1
    if p.Data > d:
        p.Left = AddNode(p.Left, d)
    else:
        p.Right = AddNode(p.Right, d)
    return p
def solve():
    task("Tree61")
    p,d= get2()
    put(AddNode(p, d))









start(solve)
