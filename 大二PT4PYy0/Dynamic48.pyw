from pt4 import *
#Pointers PX and PY to different components of a doubly linked list are given. 
#The component with the address PX precedes the component with the address PY in the list
# but need not be adjacent with it. 
# Exchange the given components in the list and output the address of the first component of the resulting list. 
# Do not use operations of allocating and freeing memory; do not change the Data fields.
#两个指针互变位置，还是双链表，前端和后端都要交给对方
def solve():
    task("Dynamic48")
    px,py=get2()
    p1=px.Prev
    p2=px.Next
    p3=py.Prev
    p4=py.Next
    p5=px.Prev
    
    p2.Prev=py
    p3.Next=px
    if p1:
       p1.Next=py
    if p4:
       p4.Prev=px
    while p5:
        p5 = p5.Prev
    put(p5)
start(solve)
