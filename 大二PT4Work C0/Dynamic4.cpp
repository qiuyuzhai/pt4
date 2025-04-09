#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Dynamic4");
    int n;
    pt>>n;
    
    PNode p1 = NULL;
    for (int i = 0; i < n; i++)
    {
        PNode p=new TNode;//你就想象一个瓶子，从上往下放方块p,瓶子底部本来是方块p1
        p->Data=GetInt();
        p->Next=p1;//从右到左翻译，p1是p的next的指针
        p1=p;//p这个方块现在是p1
    }
    pt<<p1;
    


}
