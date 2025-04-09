#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Tree50");
    PNode p = GetNode();
    while (p->Parent != NULL)
        p = p->Parent;
    pt << p;

}
