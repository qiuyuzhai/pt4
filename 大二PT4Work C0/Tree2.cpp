#include "pt4.h"
using namespace std;

int NodeCount(PNode p)
{
    if (p==NULL)
        return 0;
    return 1+NodeCount(p->Left)+NodeCount(p->Right);
    
    
}

void Solve()
{
    Task("Tree2");
    pt<<NodeCount(GetNode());

}
