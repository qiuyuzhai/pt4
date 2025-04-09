from pt4 import *
def Op(k):
    if k==-1:
        return'+'
    if k==-2:
        return'-'
    return'*'
def Pref(p):
    if p.Data>=0:
        return str(p.Data)
    return Op(p.Data)+' '+Pref(p.Left)+' '+Pref(p.Right)
def solve():
    task("Tree81")
    put(Pref(get()))








start(solve)
