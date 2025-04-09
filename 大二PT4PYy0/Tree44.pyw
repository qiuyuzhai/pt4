from pt4 import *
#给出指向非空树的根的指针P1。 向每个树叶添加两个子节点;左和右子节点的值应分别等于10和11。
def addnode(p):
    if p.Right == None and p.Left == None:
        p1 = Node(10)
        p.Left = p1
        p2 = Node(11)
        p.Right = p2
    else:
        if p.Left:
            addnode(p.Left)
        if p.Right:
            addnode(p.Right)

def solve():
    task("Tree44")
    p = get()
    addnode(p)









start(solve)
