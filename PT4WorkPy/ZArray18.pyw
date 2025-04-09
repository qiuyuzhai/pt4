from pt4 import *
def solve():
    task("ZArray18")
    b=[get()for i in range(10)]
    for i in b:
        if i<b[9]:
            put(i)
            break

    else:
        put(0)

start(solve)
