#include "pt4.h"
//Given an array of N integers, double occurrences of all elements whose values are even numbers.
//给定一个由N个整数组成的数组，所有值为偶数的元素都出现两次。

void Solve(void)
{
    Task("ZArray110");
    int n,a[10];
    GetN(&n);
    for (int i = 0; i < n; i++)
    {
        GetN(&a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i]%2==0)
        {
            PutN(a[i]);
            PutN(a[i]);
        }
        else if (a[i]%2!=0)
        {
            PutN(a[i]);
        }
        
        
    }
    
    

}
