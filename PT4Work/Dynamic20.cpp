#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Dynamic20");
    PNode p1 ,p2;
    pt>>p1>>p2;
    int n;
    if(p1==NULL&&p2==NULL){
        pt<<p1<<p2;
    }
    while(p1!=NULL){
        if(p1->Data%2!=0)
           n=p1->Data;
        if(p1->Data % 2 == 0)
         break;
        PNode p=new TNode;
        p=p1;
        p1=p1->Next;
        if(n!=0)
          pt<<n;
        delete p;
    }
    if (p1==NULL)
    p2=p1;
    pt<<p1<<p2;

}