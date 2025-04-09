from pt4 import *
def solve():
    def gcd2(a,b):
      t=0
      while b!=0:
            t=b
            b=a%b
            a=t
      return a
    
    task("ZFunc46")
    a,b,c,d=get4()
    put(gcd2(a,b))
    put(gcd2(a,c))
    put(gcd2(a,d))







start(solve)
