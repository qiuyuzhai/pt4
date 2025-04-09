from pt4 import *
#A pointer P1 to the root of a nonempty tree is given. Output the sum of values of all tree leaves.
def LeafSum(p):
    if p==None:
        return 0
    if p.Left==None and p.Right==None:
        return p.Data
    return LeafSum(p.Left)+LeafSum(p.Right)
def solve():
    task("Tree7")
    put(LeafSum(get()))









start(solve)
