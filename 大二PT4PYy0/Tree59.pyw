from pt4 import *
def search(p,d):
    global cnt;
    if p==None:
        return None
    cnt+=1
    if p.Data==d:
        return p
    if p.Data>d:
        return search(p.Left,d)
    return search(p.Right,d)

def solve():
    global cnt
    task("Tree59")
    cnt=0
    put(search((get(),get()),cnt))








start(solve)
