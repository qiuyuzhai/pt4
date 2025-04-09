from pt4 import *
def cen(m):
    if m==None:
        return
    cen(m.Left)
    put(m.Data)
    p=m.Left
    while p!=None:
        cen(p.Right)
        p=p.Right
def solve():
    task("Tree92")
    m=get()
    cen(m)

