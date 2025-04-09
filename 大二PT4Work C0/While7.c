#include "pt4.h"
//Given an integer N (> 0), 
//find the smallest positive integer K such that its square is greater than N: K2 > N.
// Do not use the operation of extracting a root.

void Solve(void)
{
    Task("While7");
    int n,k=1;
    GetN(&n);
    while (k*k<=n)
   { 
    k+=1;
    ShowN(k);
    }
    PutN(k);


}
