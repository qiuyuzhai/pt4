#include "pt4.h"
//References A1 and A2 to the head and tail of a queue are given 
//(if the queue is empty then the references equal null).
// Also an integer N (> 0) and a sequence of N integers are given.
// Define a class called IntQueue that contains the following members:
//• two private fields, head and tail, of Node type (these fields refer to the head and tail of the queue respectively);
//• a constructor with the parameters aHead and aTail of Node type (these parameters refer to the head and tail of some existing queue);
//• a procedure Enqueue(D) that adds a new component with the value D to the end of the queue (an integer D is an input parameter);
//• a procedure Put that output references to the head and tail fields by means of the Put method of the PT class (this procedure has no parameters).
//Using the Enqueue method, add all elements of the given sequence to the end of the given queue. 
//Using the Put method of the IntQueue class, output references to the head and tail of the resulting queue.
using namespace std;
struct TntQueue
{
	PNode p1,p2;//原来这就是私人领域
};

void Enqueue(TntQueue &q, int d)//不用再PNode p=new TNode这样一下，好像运行不了。本想抄python的dynamic18
{
	q.p2->Next = new TNode;
	q.p2->Next->Data = d;
	q.p2->Next->Next = nullptr;
	q.p2 = q.p2->Next;
};

void Solve()
{
	Task("Dynamic26");
	TntQueue q;
	pt >> q.p1 >> q.p2;
	int n;
	pt >> n;
	for (int m = 0; m < n; m++)
	{
		int b;
		pt >> b;
		if (q.p1)
		{
			Enqueue(q, b);
		}
		else
		{
			q.p1 = new TNode;
			q.p1->Data = b;
			q.p1->Next = nullptr;
			q.p2 = q.p1;
		}
	}
	pt << q.p1 << q.p2;
}
