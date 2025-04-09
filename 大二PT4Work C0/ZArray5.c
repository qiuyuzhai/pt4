#include "pt4.h"
//Given an integer N (> 2), 
//create and output an array of N integers that are the initial terms of a sequence {FK} of the Fibonacci numbers:

void Solve(void)
{
    Task("ZArray5");
    int n;
    GetN(&n);
    int a[n];
    a[0]=1;
    a[1]=1;
    for (int i = 2; i < n; i++)
        a[i]=a[i-2]+a[i-1];
    for (int i = 0; i < n; i++)
        PutN(a[i]);
    
    
    
    

}
