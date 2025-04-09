#include "pt4.h"

void Solve(void)
{
    Task("ZMatrix57");
    int m,n;
    GetN(&m);
    GetN(&n);
    double a[10][10];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        GetD(&a[i][j]);
    for(int i=0;i<m/2;i++)
    {
        for(int j=0;j<n/2;j++)
     {
        double p;
        p=a[i][j];
        a[i][j]=a[m/2+i][n/2+j];
        a[m/2+i][n/2+j]=p;

    }
     }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        PutD(a[i][j]);
}

