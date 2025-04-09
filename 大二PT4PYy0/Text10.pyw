from pt4 import *
import os
def solve():
    task("Text10")##
    k=get()
    f=open(get(),"r")
    f1=open("$$.tmp","w")
    n=0
    s="\n"
    h=f.readline()
    while h:
        n += 1
        f1.write(h)
        if n==k:
            f1.write(s)
        h=f.readline()
    f.close()
    f1.close()
    os.remove(f.name)
    os.rename('$$.tmp',f.name)

    
start(solve)
