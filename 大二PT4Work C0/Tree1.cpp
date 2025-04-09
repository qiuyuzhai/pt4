#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Tree1");
    PNode p1=GetNode(),p2=p1->Left,p3=p1->Right;//node是节点的意思
    pt<<p1->Data<<p2->Data<<p3->Data<<p2<<p3;

}
