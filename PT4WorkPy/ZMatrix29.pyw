from pt4 import *


def cntmin(arr, av):
    cnt = 0
    for i in range(len(arr)):
        if arr[i] < av:
            cnt += 1
    return cnt


def solve():
    task("ZMatrix29")
    m, n = get2()
    for i in range(m):
        a = get_list(n)
        aver = sum(a)/n
        put(cntmin(a, aver))


start(solve)