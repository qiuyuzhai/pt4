#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Dynamic2");
    PNode p1=GetNode(),p2=NULL;
    int cnt=0;
    while (p1)//就是p1存在就输出p1
    {
        pt<<p1->Data;
        cnt++;
        p2=p1;//先把p1的内容先给p2
        p1=p1->Next;//再把p1的地址给到新的p2（原来的p1)
    }
    pt<<cnt<<p2;//p2是最后的元素的地址
    

}
