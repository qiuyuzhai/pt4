from pt4 import *
## An integer D and references A1 and A2 to the head and tail of a queue are given; 
# the queue contains at least two components. 
# Add a component with the value D to the end of the queue and remove the first component from the front of the queue.
# Output the value of the component being removed and also output references to the head and tail of the resulting queue
#  After removing the component call its Dispose method.
def solve():
    task("Dynamic18")
    d,p1,p2=get3()
    p=Node(d)
    p2.Next=p
    p2=p
    d=p1.Data
    p=p1
    p1=p1.Next
    p.dispose()
    put(d,p1,p2)

    q.p2->Next = new TNode;
	q.p2->Next->Data = d;
	q.p2->Next->Next = nullptr;
	q.p2 = q.p2->Next;

PNode p=new TNode;
	p->Data=d;
	q.p2->Next=p;
	q.p2->Next=nullptr;#这个不能漏掉欸
	q.p2=p;





start(solve)
