from pt4 import *
import math
def solve():
    task("ZMatrix84")
    m=get()
    a=get_matr(m)
    b=(2*m-1)*[0]
    for i in range(m):
        for j in range(m):
            show(m-(j-i)-1)
        show_line()
    for i in range(m):
        for j in range(m):
            b[m-(j-i)-1]+=a[i][j]
    for i in range(m*2-1):
         if i<=(2*m-1)//2:
              b[i]/=(i+1)
         else:
             b[i]/=(2*m-1-i)
    put(b)






start(solve)
