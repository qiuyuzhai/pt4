#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Dynamic18");
    int d;
    PNode p1,p2,p=new TNode;
    pt>>d>>p1>>p2;
    p->Data=d;
    p->Next=NULL;//p被放在栈的最低端
    p2->Next=p;//p是原底端指针的下一位
    p2=p;//p是最低端的指针了，即p2
    p=p1;//原来的p1当成游离的p飞走了
    p1=p1->Next;//原来的p1的下一个数是现在的p1了 //好像每个指针的自己和它的下一项是两个东西
    pt<<p->Data<<p1<<p2;
    delete p;

}
