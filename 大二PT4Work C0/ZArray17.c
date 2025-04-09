#include "pt4.h"
// An array A of N real numbers is given. Output array elements as follows:
// A0,    A1,    AN−1,    AN−2,    A2,    A3,    AN−3,    AN−4,    … .

void Solve(void)
{
    Task("ZArray17");
    int n;
    GetN(&n);
    double a[10];
    for (int i = 0; i < n; i++)
        GetD(&a[i]);
    for (int i = 0; i < n / 2; i += 2)//假设有6个数，你这会输出8个数
    {
        PutD(a[i]);
        PutD(a[i + 1]);
        if (n/2>=i+2)
        {
            PutD(a[n - 1 - i]);
            PutD(a[n - 2 - i]);
        }   
    }
    if (n%4==3)
    {
        PutD(a[n/2+1]);
    }
    if (n%4==1)
    {
        PutD(a[n/2]);
    }
   
}
