from pt4 import *
def IsSquare(k):
    i=1
    while i*i<k:
        i+=1
    return i*i==k
def solve():
    task("ZFunc10")
    cnt=0
    for _ in range(10):
        if IsSquare(get()):
            cnt+=1
    put(cnt)

start(solve)
