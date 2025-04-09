from pt4 import *
def solve():
    task("File10")
    f1 = open(get(),"rb")
    f2 = open(get(),"wb")
    f1.seek(0,2)
    n = f1.tell() 
    for i in range(n):
        f1.seek((n -i -1)*4)
        f2.write(f1.read(4))
    f1.close()
    f2.close()
start(solve)
