#include "pt4.h"
// An integer N (> 1) is given. An integer-valued sequence of the Fibonacci numbers FK is defined as:

//F1 = 1,        F2 = 1,        FK = FK−2 + FK−1,    K = 3, 4, … .

//Determine whether N is a Fibonacci number or not, and output True or False respectively.

void Solve(void)
{
    Task("While24");
    int n;
    GetN(&n);
    int a=1,b=1,c;
    while (b<n)
    {
        int c=a+b;
        a=b;
        b=c;
    }
    if (b==n)
         PutB(1);
        else
         PutB(0);

    

    

}
