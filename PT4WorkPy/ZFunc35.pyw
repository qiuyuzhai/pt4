from pt4 import *
def ShiftRight3(X):
    X[0],X[1],X[2] = X[2],X[0],X[1]
def solve():
    task("ZFunc35")
    x=get3()
    y=get3()
    put(ShiftRight3(x))
    put(ShiftRight3(y))
start(solve)

