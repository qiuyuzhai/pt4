#include "pt4.h"
//A real-valued square matrix A of order M is given. 
//Reflect its elements about the main diagonal
// (that is, exchange values of matrix elements A0,1 and A1,0, A0,2 and A2,0, and so on).
// Do not use an additional matrix.

void Solve(void)
{
    Task("ZMatrix96");
    int m;
    GetN(&m);
    double a[m][m];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
        GetD(&a[i][j]);
    for (int i = 0; i < m; i++)
    {
        double p;
        for (int j=i;  j<m; j++)
        {
            p=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=p;
        }   
    }
    for (int i = 0; i < m; i++)
     for (int j = 0; j < m; j++)
       PutD(a[i][j]);
    
    

}
