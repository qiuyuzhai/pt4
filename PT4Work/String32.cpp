#include "pt4.h"
using namespace std;

void Solve()
{
    Task("String32");
    string m,n;
    pt>>m>>n;
    int count=0,i=0;
    while(m.find(n,i)!=-1)
    {
        count++;
        i=m.find(n,i)+1;
    }
    pt<<count;
}

