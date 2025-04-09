#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Dynamic19");
    int n;
    PNode p1,p2,p=new TNode;
    pt>>n>>p1>>p2;
    for (int i = 0; i < n; i++)
    {
        if (p1)
        {
            p=p1;//原来的p1当成游离的p飞走了
            p1=p1->Next;
            pt<<p->Data;
            delete p;
        }
    }
    if (p1 == NULL)
      p2 = NULL;
    pt<<p1<<p2;
  
    
    


}
