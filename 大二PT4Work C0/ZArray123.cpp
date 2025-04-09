#include "pt4.h"
using namespace std;

void Solve()
{
    Task("ZArray123");//
    int k,n,t=1,j=0,s=0;
    pt>>k; 
    pt>>n;
    int a[10],b[10],c[10],d[10];
    for(int i = 0;i<n;i++)
       pt>>a[i];
    for(int i=0;i<n;i++)
       d[i]=a[i];
    b[0]=1;
    c[0]=a[0];
    for(int i =1; i<n;i++)
    {
            if (a[i-1]==a[i])
                b[t-1]++;
            else
            {
               b[t]=1;
               c[t]=a[i];
               t++;
            }
    }
    for(int q=0;q<k;q++)
        s+=b[q];
    if(t>=k)
    {
        for(int i = 0; i < b[k]; i++)
        a[i]=c[k];
        for(int i=b[k];i<b[k]+s-b[0];i++)
        {
            a[i]=d[b[0]+j];
            j++;
        }
        for (int i = b[k]+s-b[0]; i < b[k]+s; i++)
           a[i]=c[0];
        for (int i = 0; i < n; i++)
          PutN(a[i]);
    }
 
}
