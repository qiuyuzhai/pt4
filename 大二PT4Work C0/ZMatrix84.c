#include "pt4.h"

void Solve(void)
{
    Task("ZMatrix84");
    int m;
    GetN(&m);
    double a[10][10],b[10]={0},c[10]={0};
    for (int i = 0; i < m; i++)
       for (int j= 0; j < m; j++)
        GetD(&a[i][j]);
    for (int h = 1; h <= m; h++)
    {
        for (int i = 0; i< h; i++)
        {
            for (int j = m-h+i; j<=m-h+i; j++)
            {
                b[h]+=a[i][j];
                c[h]+=a[j][i];
            }
        }
        PutD(b[h]/h);
        
    }
    for (int h = m-1; h>=1; h--)
    {
        PutD(c[h]/h);
    }
    
    
       
    

}
