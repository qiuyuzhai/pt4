from pt4 import *

def Add(p):
    root1 = Node()
    root1.Data = 10
    root1.Left = None
    root1.Right = None
    p.Left = root1
    root2 = Node()
    root2.Data = 11
    root2.Left = None
    root2.Right = None
    p.Right = root2

def addnode(p):
    if p.Right == None and p.Left == None:
        Add(p)
    else:
        if p.Left != None:
            addnode(p.Left)
        if p.Right != None:
            addnode(p.Right)

def solve():
    task("Tree44")
    p = get()
    addnode(p)

start(solve)
