#include "pt4.h"
using namespace std;

int LeafSum(PNode p)
{
    if (p==NULL)
       return 0;
    if (p->Left==NULL&&p->Right==NULL)
       return p->Data;
    return LeafSum(p->Left)+LeafSum(p->Right);
    
    
}
    

void Solve()
{
    Task("Tree7");
    PNode p1=GetNode();
    pt<<LeafSum(p1);

}
