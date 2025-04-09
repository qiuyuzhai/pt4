from pt4 import *
def swaptree(p):
    if not p:
        return
    if p.Left==None and p.Right==None:
        return
    tmp=p.Right
    p.Right=p.Left
    p.Left=tmp
    swaptree(p.Left)
    swaptree(p.Right)
def solve():
    task("Tree39")
    p1=get()
    swaptree(p1)
start(solve)
