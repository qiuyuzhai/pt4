from pt4 import *
from struct import *
def solve():
    task("Text51")
    f=open(get(),"r")
    f1 = 3*[0]
    f1[0]=open(get(),"wb")
    f1[1]=open(get(),"wb")
    f1[2]=open(get(),"wb")
    for s in f:
        a = s.split()
        for i in range(3):
            f1[i].write(pack("d",float(a[i])))
    f.close()
    f1[0].close()
    f1[1].close()
    f1[2].close()







start(solve)
