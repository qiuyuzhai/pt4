#include "pt4.h"

void Solve(void)
{
    Task("ZArray118");
    int n;
GetN(&n);
int a[20],b[10],c[10];

for (int i = 0; i < n; i++)
{
    GetN(&a[i]);
}
a[n++]=0;
for (int i = n-2; i >0; --i)
   if(a[i]!=a[i-1])
   {
    for (int j = n-1; j >=i; --j)
        a[j+1]=a[j];
        a[i]=0;
        ++n;
     }
    for (int i = 0; i < n; i++)
    {
        PutN(a[i]);
    }
    

}
