from pt4 import *
#c++有这道题
def Walk(p):
    if p == None:
        return
    Walk(p.Left)
    put(p.Data)
    p1=p.Left
    while p1:
        Walk(p1.Right)
        p1=p1.Right
def solve():
    task("Tree92")
    #p=Node()
    p=get()
    Walk(p)

start(solve)
