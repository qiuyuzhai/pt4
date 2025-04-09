from pt4 import *


def Calc(p):
    if p.Data >= 0:
        return p.Data
    m = Calc(p.Left)
    n = Calc(p.Right)
    if p.Data == -1:
        return m + n
    if p.Data == -2:
        return m - n
    return m * n


def solve():
    task("Tree79")
    put(Calc(get()))
start(solve)

