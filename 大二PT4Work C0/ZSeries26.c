#include "pt4.h"
//Positive integers K, N and a sequence of N real numbers A0, A1, …, AN−1 are given.
// For each element of the sequence find its value raised to the power of K:

void Solve(void)
{
    Task("ZSeries26");
    int k,n;
    double a,r=1;
    GetN(&k);
    GetN(&n);
    for (int i = 0; i < n; i++){
        GetD(&a);
    for(int i=0;i<k;i++)
         r*=a;//r=r*a r=1*a,r=a*a...//a=a*a,a=a*a,a=a*a*a...你这个第一循环就有两个a相乘了
        PutD(r);
        r=1;
        
        

    }
        
}
    


