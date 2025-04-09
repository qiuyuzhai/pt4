#include "pt4.h"
//Given an array of N real numbers,
// find the index of its first local minimum找第一个极小值的下标
// (an array element is called the local minimum if it is smaller than its neighbors).
void Solve(void)
{
    Task("ZArray32");
    int n;
    GetN(&n);
    double a[80];
    for(int i=0;i<n;i++)
        GetD(&a[i]);
    for(int i=0;i<n;i++)
    {
        if(a[0]<a[1])
        {
        PutN(a[0]);
        break;
        }
        else if(a[i]<a[i+1]&&a[i]<a[i-1])
        {
        PutN(i);
        break;
        }
        else if (a[n-1]<a[n-2])
        {
            PutN(a[n-1]);
            break;
        }  
    }

}
