from pt4 import *
def solve():
    task("Dynamic31")
    n = 1
    p0 = get()
    p1 = p0
    p2 = p0
    while p1.Prev != None:
        p1 = p1.Prev
        n+=1
    while p2.Next != None:
        p2 = p2.Next
        n+=1
    put(n, p1, p2)










start(solve)
