from pt4 import *
def solve():
    task("ZMatrix29")
    a=get_matr()
    n=len(a[0])
    for i in range(len(a)):
        k=0
        b=[a[i][j] for j in range(n)]
        h=sum(b)/n
        show(h)
        for j in range(n):
              if a[i][j]<h:
                    k+=1
        put(k)
          
    
         
         










start(solve)
