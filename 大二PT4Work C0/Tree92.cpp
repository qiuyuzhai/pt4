#include "pt4.h"
using namespace std;
void Walk(PNode p)
{
    if (p==NULL)
       return;
    Walk(p->Left);
    pt<<p->Data;
    PNode p1=p->Left;
    while (p1)
    {
        Walk(p1->Right);
        p1=p1->Right;
    }
}
    
   

void Solve()
{
    Task("Tree92");
    Walk(GetNode());

}
