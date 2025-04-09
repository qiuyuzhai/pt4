#include "pt4.h"
#include <float.h>
// Two real numbers B, C (0 < B < C) and a sequence of 10 real numbers are given.
// Find the maximum最大 among elements that are in the interval (B, C) and output its value and its index.
// If the sequence does not contain elements in the interval (B, C), then output −1 twice (the first −1 as a real number, the second −1 as an integer).
void Solve(void)
{
    Task("ZMinmax15");
    double b, c;
    GetD(&b);
    GetD(&c);
    double max = -DBL_MAX;
    int imax = -1;
    for (int i = 0; i < 10; i++)
    {
        double a;
        GetD(&a);
        if (a > max && a >b&&a<c)
        {
                max = a;
                imax = i;
         }
    }
    if (max==-DBL_MAX)
       max=-1;
    PutD(max);
    PutN(imax);
}
