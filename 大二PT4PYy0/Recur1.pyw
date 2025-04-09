from pt4 import *
def Fact(n):
        if n<=1:
            return 1.0
        return Fact(n-1)*n
def solve():
    task("Recur1")
    for i in get5():
         put(float(Fact(i)))##注意题目要求的是实数








start(solve)
