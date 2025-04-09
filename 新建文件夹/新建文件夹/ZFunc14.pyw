from pt4 import *
def DigitCount(a):##
    s=0
    s=len(str(a))
    return s
def solve():
    task("ZFunc14")
    for i in range(5):
       put(DigitCount(get()))
start(solve)
