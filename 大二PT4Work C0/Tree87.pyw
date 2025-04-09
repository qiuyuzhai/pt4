from pt4 import *

def fun(node):
    if node == None:
        return
    if node.Left is not None and node.Left.Right is not None:
        node.Right = node.Left.Right
        node.Left.Right = None
    if Node.Left != None:
        fun(node.Left)
    if Node.Right != None:
        fun(node.Right)

def solve():
    task("Tree87")
    a1 = get()
    show(a1.Left.Data)
    fun(a1)
    put(a1)






start(solve)

