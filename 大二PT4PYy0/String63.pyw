from pt4 import *
def solve():
    task("String63")##
    s=get()
    k=get()
    a = list(s)
    for i in range (len(s)):
        show(a[i])
        if 64<ord(a[i])<91 or 96<ord(a[i])<123 :
            if ord(a[i])+k>90 and ord(a[i])+k<96:
              a[i]=chr(ord(a[i])+k-90+96)
            elif ord(a[i])+k>122:
              a[i]=chr(ord(a[i])+k-122+96)
            else:
              a[i]=chr(ord(a[i])+k)
        else:
            continue 
    put("".join(a))
    

start(solve)
