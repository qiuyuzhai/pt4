from pt4 import *
def solve():
    task("Dynamic70")
    a1, a2 = get2()
    tmp = Node()
    tmp.Data = 0
    if a1 is not None and a2 is not None:
        tmp.Next = a1
        tmp.Prev = a2
        a1.Prev = tmp
        a2.Next = tmp
    else:
        tmp.Prev = tmp
        tmp.Next = tmp
    put(tmp) 








start(solve)
