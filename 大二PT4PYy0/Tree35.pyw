from pt4 import *
#A pointer P1 to the root of a nonempty tree is given. Double the value of each tree node.
def CNodeOutput(p):##直接从tree13照搬过来
    if p==None:
        return
    p.Data=p.Data+p.Data
    CNodeOutput(p.Left)
    CNodeOutput(p.Right)
def solve():
    task("Tree35")
    CNodeOutput(get())









start(solve)
