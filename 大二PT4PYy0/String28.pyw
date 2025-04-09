from pt4 import *
def solve():
    task("String28")##
    c=get()
    s=get()
    for i in range(len(s)-1,-1,-1):
        if s[i]==c:
           s=s[:i]+c+s[i:]
    put(s)



start(solve)
