#include "pt4.h"
using namespace std;
void Solve()
{
    Task("Dynamic56");
    PNode m1,m2,m3,m4;
    pt>>m1>>m2;
    m3=m1;
    m4=m2;
    while(not(m1->Next==m2 and m2->Prev==m1))
    {
    	m1=m1->Next;
    	m2=m2->Prev;
	}
	m3->Prev=m1;
	m1->Next=m3;
	m4->Next=m2;
	m2->Prev=m4;
	pt<<m1<<m2;
}
