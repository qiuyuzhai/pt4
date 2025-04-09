from pt4 import *
from math import*
def solve():##
    task("ZArray9")
    n=get()
    a=get_list(n)
    a.reverse()
    k=0
    for i in range(n):
        if a[i]%2==0:
            b=a[i]
            put(b)
            k+=1
    put(k)
            
    
        
    








start(solve)
