#include "pt4.h"
using namespace std;
struct TQ
{
	PNode h;
	PNode t;
};
void Enqueue(TQ &tq, int a)
{
	tq.t->Next = new TNode;
	tq.t->Next->Data = a;
	tq.t->Next->Next = nullptr;
	tq.t = tq.t->Next;
}

void Solve()
{
    Task("Dynamic26");
    TQ tq;
	pt >> tq.h >> tq.t;
	int n;
	pt >> n;
	for (int m = 0; m < n; m++)
	{
		int b;
		pt >> b;
		if (tq.h)
		{
			Enqueue(tq, b);
		}
		else
		{
			tq.h = new TNode;
			tq.h->Data = b;
			tq.h->Next = nullptr;
			tq.t = tq.h;
		}
	}
	pt << tq.h << tq.t;

}
