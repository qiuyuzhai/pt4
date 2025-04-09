#include "pt4.h"
#include<float.h>
//An array of N real numbers is given.
// The values of all array elements, except the first one, 
//are in ascending order. 
//Arrange all array elements in ascending order
// by moving the first element to a new position.有什么缺点
void Solve(void)
{
    Task("ZArray87");
    int n;
    GetN(&n);
    double a[10];
    for (int i = 0; i < n; i++)
    GetD(&a[i]);
    for (int i = 0; i <n ; i++)
    {
          
       if (a[i]>a[i+1])
       {
        int x=a[i];
        a[i]=a[i+1];
        a[i+1]=x;
       }
       if (i==n-1)
       {
        a[i]=a[n-1];
       }
    }
     for (int i = 0; i < n; i++)
      PutD(a[i]);
}
