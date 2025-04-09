#include "pt4.h"
using namespace std;
void Solve()
{
    Task("Dynamic6");
    PNode a, b;
    pt >> a;
    for (int i = 0; i < 9; ++i) 
    {
        pt << a->Data;
        b = a;
        a = a->Next;
        delete b;
    }
    pt << a;
    delete a;
}

