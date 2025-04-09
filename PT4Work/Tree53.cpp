#include "pt4.h"
using namespace std;
int level(PNode p)
{
	if (p==NULL)
	    return 0;
	return 1+level(p->Parent);
}


void Solve()
{
    Task("Tree53");
    PNode p,p1;
    pt>>p>>p1;
    int x,y;
    x=level(p);
    y=level(p1);
    if(x>y)
    {
    	for(int i=0;i<x-y;i++)
    	{
    		p=p->Parent;
		}
	}
	else
	{
		for(int i=0;i<y-x;i++)
		{
			p1=p1->Parent;
		}
	}
	while(p!=p1)
	{
		p=p->Parent;
		p1=p1->Parent;
	}
	pt<<p1;
	

}
