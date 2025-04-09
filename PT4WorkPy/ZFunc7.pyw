from pt4 import *
def Calc(A, B, Op):
    if Op<1:
        return A+B
    if(1<=Op<2):
        return A-B
    if (2<=Op<3):
        return A*B
    if(3<=Op<4):
        return A/B
    if Op>=4:
        return A+B
def solve():
    task("ZFunc7")
    a,b=get2()
    N1,N2,N3=get3()
    Op1=abs(N1)
    Op2=abs(N2)
    Op3=abs(N3)
    put(Calc(a, b, Op1))
    put(Calc(a, b, Op2))
    put(Calc(a, b, Op3))
start(solve)
