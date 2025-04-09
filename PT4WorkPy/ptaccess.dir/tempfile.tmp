from pt4 import *

def insert(node,val):
    a = node
    while True:
        if a.Data <= val:
            if a.Right == None:
                break
            else:
                a=a.Right
        else:
            if a.Left == None:
                break
            else:
                a = a.Left
    if a.Data <= val:
        newNode = Node(val)
        a.Right = newNode
    else:
        newNode = Node(val)
        a.Left = newNode
    
def solve():
    task("Tree63")
    w = get()
    y = []
    for m in range(w):
        y.append(get())
    x = get()
    if x == None:
        x = Node(y[0])
        for m in range(1,len(y)):
            show(x)
            insert(x,y[m])
    else:
        for i in range(len(y)):
            insert(x,y[i])
    put(x)

start(solve)
