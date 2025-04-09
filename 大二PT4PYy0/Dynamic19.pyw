from pt4 import *
#An integer N (> 0) and references A1 and A2 to the head and tail of a nonempty queue are given. 
# Remove N initial components from the queue and output their values
#  (if the queue contains less than N components then remove all its components).
#  Also output references to the head and tail of the resulting queue 
# (if the queue will be empty then output null twice). 
# After removing components call the Dispose method for each of them.
def solve():
    task("Dynamic19")
    n,p1,p2=get3()
    for_in range(n):
        if p1==None:
           break
        put(p1.Data)
        p=p1
        p1=p1.Next
        p.dispose()
    if p1==None:
        p2=None
    put(p1,p2)








start(solve)
