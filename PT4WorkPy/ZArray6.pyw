from pt4 import *


def solve():
    task("ZArray6")
    n = get()
    arr = get_list(2)    
    for i in range(n - 2):
        arr.append(sum(arr))
    put(arr)


start(solve)