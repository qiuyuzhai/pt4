#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Dynamic1");
    PNode p1,p2;
    pt>>p1;
    p2=p1->Next;
    pt<<p1->Data<<p2->Data<<p2;


}
