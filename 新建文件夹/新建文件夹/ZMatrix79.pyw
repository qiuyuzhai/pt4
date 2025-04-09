from pt4 import *
def swap(arr, i):
    for j in range(i - 1, 0, -1):
        if arr[j] < arr[j - 1]:
            arr[j], arr[j - 1] = arr[j - 1], arr[j]
            max[j], max[j - 1] = max[j - 1], max[j]
        else:
            break
    return arr
def solve():
    task("ZMatrix79")
    m, n = get2()
    a=m*[0]
    for i in range(m):
         a[i]=get_list(n)
    b = [[0 for elem in range(n)] for j in range(m)]
    global max
    maxelem, max = [], []
    for i in range(n):
        mx = a[0][i]
        for j in range(1, m):
            if a[j][i] > mx:
                mx = a[j][i]
        maxelem.append(mx)
        max.append(i)
    for i in range(2, n + 1):
        maxelem = swap(maxelem, i)
    b = [[0 for elem in range(n)] for j in range(m)]
    for i in range(n):
        for j in range(m):
            b[j][i] = a[j][max[i]]
    put(b)


start(solve)