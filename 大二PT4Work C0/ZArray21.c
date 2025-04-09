#include "pt4.h"
//An array of N real numbers and two integers K and L (0 ≤ K ≤ L ≤ N−1) are given.
// Find the average of array elements with indices in the range K to L inclusively.

void Solve(void)
{
    Task("ZArray21");
    int n,k,l;
    GetN(&n);
    double sum=0;
    double a[10];
    for (int i = 0; i < n; i++){
        GetD(&a[i]); }
        GetN(&k);
    GetN(&l);
    for (int i = k; i<=l; i++)
    {
        sum+=a[i];
    }
    PutD(sum/(l-k+1));

    

}
