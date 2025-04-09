from pt4 import *

a = [1, 1] + [0] * 20

def fib2(n):
    if n == 1 or n == 2:
        return 1
    else:
        if a[n - 2] == 0:
            a[n -2] = fib2(n - 1)
        return a[n - 2] + a[n - 3]


def solve():
    task("Recur5")
    for i in range(5):
        put(fib2(get()))
        print(a)


start(solve)
