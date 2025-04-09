from pt4 import *
def solve():
    task("ZMatrix93")
    m = get()
    mat = get_matr(m , m)
    if m < 3:
        put(mat)
    else:
        iseven = m % 2 == 0
        begin = (m + m % 2) // 2 + iseven
        for i in range(begin, m):
            cnt = 2 * (i - begin + iseven) + m % 2
            bound = m // (cnt + 1)
            for j in range(bound, m - bound):
                mat[j][i] = 0.00
        put(mat)
