from pt4 import *##这个题主要的难点是变量cnt在两个函数（def）下一起变化，得在函数开头处表明cnt是global型
cnt=0
def fib(n):
    global cnt
    cnt+=1
    return 1 if n<=2 else fib(n-2)+fib(n-1)
def solve():
    global cnt
    task("Recur4")
    for i in get5():
        cnt=0
        put(fib(i),cnt)









start(solve)
