from pt4 import *
from math import *
def TrianglePS(a1):
    return 3*a1,sqrt(3)*a1*a1/4
def solve():
    task("ZFunc25")
    for a in get3():
        put (TrianglePS(a))








start(solve)
