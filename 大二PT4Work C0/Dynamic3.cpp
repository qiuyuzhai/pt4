#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Dynamic3");
    int d;
    PNode p1;//顶栈的指针是p1
    pt>>d>>p1;
    PNode p2=new TNode;//new 和delete 是成对出现的 创建了一个范式的指针p，指向所分配的内存的首地址
    p2->Data=d;
    p2->Next=p1;
    pt<<p2;

}
