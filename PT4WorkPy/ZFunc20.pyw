from pt4 import *
def factorial(N):
    if N%2==1:
        res=1
        for i in range(1,N+2,2):
            res*=i
    elif N%2==0:
        res=1
        for i in range(2,N+2,2):
           res*=i
    return res
        
def solve():
    task("ZFunc20")
    n1=get_int()
    n2=get_int()
    n3=get_int()
    n4=get_int()
    n5=get_int()
    factorial(n1)
    factorial(n2)
    factorial(n3)
    factorial(n4)
    factorial(n5)
    put(float((factorial(n1))))
    put(float((factorial(n2)))) 
    put(float((factorial(n3))))
    put(float((factorial(n4))))
    put(float((factorial(n5))))
start(solve)
