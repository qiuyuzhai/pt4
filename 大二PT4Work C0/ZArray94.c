#include "pt4.h"
//Given an array of N (> 2) integers, remove all elements with even indices (0, 2, …) from the array.
// Do not use conditional statements.为什么会多输出

void Solve(void)
{
    Task("ZArray94");
    int n,a[10];
    GetN(&n);
    for (int i = 0; i < n; i++)
        GetN(&a[i]);
    for (int i = 0; i < n; i++)
    {
        if (i%2!=0)//i是JI数时
        {
            a[i-1]=a[i];
        }
       
    }
    for (int i= 0; i <n; i++)
   {
    if (a[i]==a[i+1])
    {
        PutN(a[i]);
    }
    
   }
    
    
}
    
    
    

