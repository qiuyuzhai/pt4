#include "pt4.h"
using namespace std;
PNode CreateNode(PNode p)
{
    if (p==NULL)
    return NULL;
    PNode p0=new TNode;
    p0->Data = p0->Data;
    p0->Right = NULL;
    PNode p1=p->Left,p2=p->Right;
    if(p1==NULL)
    {
        p1=p2;
        p2=NULL;
    }
    p0->Left=CreateNode(p1);
    if(p1==NULL)
        p0->Left->Right=CreateNode(p2);
    return 0;
}
void Solve()
{
    Task("Tree86");
    pt<<CreateNode(GetNode());

}
