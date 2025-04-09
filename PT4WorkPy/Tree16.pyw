from pt4 import *


cnt = 1

def PrintTree(p, n):
    global cnt
    if p == None:
        return
    else:
        PrintTree(p.Left, n)
        PrintTree(p.Right, n)
        if cnt >= n:
            put(p.Data)
        print(p.Data, cnt)
    cnt += 1



def solve():
    task("Tree16")
    PrintTree(get(), get())
    global cnt
    cnt = 1

start(solve)
