#include "pt4.h"
using namespace std;

struct TList
{
    PNode first,last,current;
};

void InsertLast(TList&L,int D)
{
    PNode p=new TNode;
    p->Data=D;
    p->Next=NULL;
    p->Prev=L.last;
    if (L.last)
       L.last->Next=p;
    else
       L.first=p;
    L.last=p;
    L.current=p;
}

void Solve()
{
    Task("Dynamic59");
    TList L;
    pt>>L.first>>L.last>>L.current;
    int n=GetInt();
    for (int i = 0; i < n; i++)
        InsertLast(L,GetInt());
    pt<<L.first<<L.last<<L.current;
};
