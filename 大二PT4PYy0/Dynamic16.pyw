from pt4 import *##齐心那个有15
#A sequence of 10 integers is given.
# Create two queues; 
# the first one must contain the given integers with odd values (in the same order), the second one must contain the given integers with even values (in the same order). 
# Output references to the head and tail of the first queue and then output references to the head and tail of the second one (if one of the queues will be empty then output null twice for this queue).
def solve():
    task("Dynamic16")##
    x=None
    y=x
    z=None
    a=z
    for i in range(10):
        e=get()
        if e%2==0:
          z=Node(e,z)
        else:
           x=Node(e,x)
    p2=None
    q=None
    o=q
    t=p2
    if x:
      while x:
        r=x
        x=x.Next
        r.Next=q
        q=r
        o=q
        while o.Next:
         o=o.Next
    if z:
       while z:
           p = z 
           z = z.Next
           p.Next = p2
           p2 = p
       t=p2
       while t.Next:
           t=t.Next 
    put(q,o,p2,t)



start(solve)

        

        
   




