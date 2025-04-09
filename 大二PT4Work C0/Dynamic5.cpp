#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Dynamic5");
    PNode p1=GetNode();
    pt<<p1->Data<<p1->Next;
    delete p1;


}
