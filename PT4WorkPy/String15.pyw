from pt4 import *
def solve():
    task("String15")
    s=get()
    a=0
    for i in range(len(s)):
        if(65<=ord(s[i])<=90 or 97<=ord(s[i])<=122):
           a+=1
    put(a)
start (solve)

