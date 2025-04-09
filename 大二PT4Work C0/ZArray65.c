#include "pt4.h"
//An array A of N real numbers and an integer K 
//(0 ≤ K ≤ N−1) are given.
// Increase the value of each element of A 
//by the initial value of AK.
void Solve(void)
{
    Task("ZArray65");
    int n,k;
    GetN(&n);
    double a[10];
    double b[10];
    for (int i = 0; i < n; i++){
      GetD(&a[i]);
    }
    GetN(&k);
    for (int i = 0; i < n; i++)
    {
       b[i]=a[i]+a[k];
       PutD(b[i]);
    }

    
    
    
    
    
    

}
