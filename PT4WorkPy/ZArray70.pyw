from pt4 import *
def exchange_halves(abc):
    n=len(abc)
    mid=n//2
    abc[:mid],abc[mid:]=abc[mid:],abc[:mid]
    return abc
def solve():
    task("ZArray70")
    n=get()
    abc=get_list(n)
    put(exchange_halves(abc))
start(solve)
