from pt4 import *
def solve():
    task("String46")
    s=get()
    k=0
    max=0
    #a=s.split()
    #show(a)
    for c in s:
        if c!=" ":
           k += 1
           show(k)
        else:
          if k>max:
            max=k 
          k=0 
    if k>max:
        max=k 
    put(max)
        
                







start(solve)
