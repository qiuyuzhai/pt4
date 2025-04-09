#include "pt4.h"
using namespace std;
void fun(PNode &p1,int m,int n){
    if(m==0){
        return;
    }
    p1 = new TNode;
    p1->Data = n;
    p1->Left = nullptr;
    p1->Right = nullptr;
    fun(p1->Right,(m-1)/2,n+1);
    fun(p1->Left,m/2,n+1);
}

void Solve()
{
    Task("Tree33");
    int m;
    pt >> m;
    PNode p1;
    fun(p1,m,0);
    pt << p1;

}
