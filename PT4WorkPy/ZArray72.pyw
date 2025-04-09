from pt4 import *
def solve():
    task("ZArray72")
    a=get_list()
    k,l=get2()
    b=a[k:l+1]
    b.reverse()
    a[k:l+1]=b[::1]
    put (a)
     







start(solve)
