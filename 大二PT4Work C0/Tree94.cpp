#include "pt4.h"
// A pointer P1 to the root of a nonempty general tree and an integer N (≥ 0) are given. 
//Output the amount of nodes that have exactly N child nodes (this amount may be equal to 0).
using namespace std;

int n;
int k;
int ReturnN(PNode p,int n)
{
    if(!p)
        return n;
    return ReturnN(p->Right,n+1);
}

void fun(PNode p)
{
    if(!p)
        return;
    if(ReturnN(p->Left,0)==n)
        k++;
    fun(p->Left);
    fun(p->Right);
}



void Solve()
{
    Task("Tree94");
    PNode p;
    pt >> p;
    pt >> n;
    fun(p);
    pt << k;
}
