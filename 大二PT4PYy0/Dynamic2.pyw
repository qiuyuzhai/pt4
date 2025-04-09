from pt4 import *
def solve():
    task("Dynamic2")
    p1,p2=get(),None
    cnt=0
    while p1:
        put(p1.Data)
        cnt+=1##python 没有cnt++这个操作
        p2=p1
        p1=p1.Next
    put(cnt,p2)

start(solve)
