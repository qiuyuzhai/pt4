#include "pt4.h"
#include <iostream>
using namespace std;
int maxs;
PNode maxp;

void FindMax(PNode p)
{
    if (p == NULL)
        return;
    int s = 0;
    PNode p1 = p->Left;
    while (p1 != NULL)
    {
        FindMax(p1);
        s += p1->Data;
        p1 = p1->Right;
    }
    if (s >= maxs)
    {
        maxs = s;
        maxp = p;
    }
}

void Solve()
{
    Task("Tree96");
    maxs = 0;
    maxp = NULL;
    FindMax(GetNode());
    pt << maxp;
}
