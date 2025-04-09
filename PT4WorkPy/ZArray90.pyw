from pt4 import *


def solve():
    task("ZArray90")
    a = get_list()
    b = get()
    a = a[: b] + a[b+1:]
    put(a)


start(solve)

