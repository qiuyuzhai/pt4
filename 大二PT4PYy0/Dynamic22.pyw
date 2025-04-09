from pt4 import *
#An integer N (> 0) and two nonempty queues are given;
# references A1 and A2 refer to the head and tail of the first one, 
# references A3 and A4 refer to the head and tail of the second one. 
# Move N initial components of the first queue to the end of the second one
# (if the first queue contains less than N components then move all its components).
# Output references to the head and tail of the first queue 
# and then output references to the head and tail of the second one 
# (if the first queue will be empty then output null twice for this queue). 
# Do not create new instances of the Node class.

def solve():
   task("Dynamic22")
   n,p1,p2,p3,p4=get5()
  
   for _ in range(n):
      if p1 == None:
          break
      else:
          p=p1
          p1=p1.Next
          p4.Next=p
          p4=p
   if p1==None:
         p2=None
   put(p1,p2,p3,p4)


start(solve)
