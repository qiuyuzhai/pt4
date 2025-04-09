from pt4 import *
import math 
def solve():
    task("Text42")
    a,b,n=get3()
    f=open(get(),"w")
    h=(b-a)/n
    for i in range(n+1):
        x=a+i*h
        f.write(f"{x:10.4f}{math.sqrt(x):15.8f}\n")







start(solve)
