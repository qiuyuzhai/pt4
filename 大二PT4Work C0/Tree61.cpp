#include "pt4.h"
using namespace std;

PNode AddNode(PNode p,int d)
{
    if (p==NULL)
    {
        PNode p1=new TNode;
        p1->Data=d;
        p1->Left=p1->Right=NULL;
        return p1;
    }
    if(p->Data>d)
       p->Left=AddNode(p->Left,d);
    else
       p->Right=AddNode(p->Right,d);
    return p;
}

void Solve()
{
    Task("Tree61");
    PNode p;
    int d;
    pt>>p>>d;
    pt<<AddNode(p,d);
}
