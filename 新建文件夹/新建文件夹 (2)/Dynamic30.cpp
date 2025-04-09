#include "pt4.h"
using namespace std;
//p1是第一个顶针，是一个TNode类型，连接了下一个领域。用TNode的Prev领域，把给定的单向链变成双向链。第一个链的其前端领域的内容是NULL。
//输出得到的链的最后的元素的地址指针

void Solve()
{
    Task("Dynamic30");
    PNode p1,p2=NULL;
    pt>>p1;//p1被给出
    while (p1!=NULL)
    {
        p1->Prev=p2;//形成了一个环，头尾相连了
        p2=p1;//不断地把原来的p1被p2代替
        p1=p1->Next;//原来p1的下一段确实现在的p1
    }
    pt<<p2;
    

}
