from pt4 import *
import math

def solve():
    task("TimD4")
    n = get()  # ?? n
    a, b, c = -1, -1, -1  # ??? a, b, c

    # ??????????? i, j, k
    for i in range(1, 101):
        for j in range(i + 1, 101):
            for k in range(1, 101):
                if k != i and k != j:
                    if math.pow(i, n) + math.pow(j, n) == math.pow(k, n):
                        a, b, c = i, j, k
    
    # ????
    put(a)
    put(b)
    put(c)

start(solve)

