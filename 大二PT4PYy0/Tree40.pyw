from pt4 import *
#给出指向非空树的根的指针P1。 从树中移除所有节点（除了根），释放为移除的节点分配的内存，并为根的左右字段分配nil。
def DeleteTree(p):
    if p==None:
        return
    DeleteTree(p.Left)
    DeleteTree(p.Right)
    p.dispose()
def solve():
    task("Tree40")
    p=get()
    DeleteTree(p.Left)
    DeleteTree(p.Right)
    p.Left,p.Right=None,None








start(solve)
