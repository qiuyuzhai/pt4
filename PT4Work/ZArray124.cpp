#include "pt4.h"
using namespace std;

void Solve()
{
    Task("ZArray124");
    int k,n,m;
    int a[20],b[20],c[20];
    pt >> k >>n;
    for(int i=0;i<n;i++)
    {
        pt >> a[i];
    }
   for(int i=0;k+i<n;i++)
   {
        b[i]=a[k+i];
   }

    for(int i=0;i<n;i++)
    {
        pt<<a[i];
    }
}
