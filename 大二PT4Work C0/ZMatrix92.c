#include "pt4.h"
//A real-valued square matrix of order M is given. 
//Assign zero value to the matrix elements that lie above the main diagonal and above the secondary diagonal simultaneously. 
//Do not use conditional statements.
//给定一个 M 阶的实值方阵。将同时位于主对角线以上和副对角线以上的矩阵元素赋值为零。不使用条件语句

void Solve(void)
{
    Task("ZMatrix92");
    int m;
    GetN(&m);
    int n=m;
    double a[10][10];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j<=m; j++)
        GetD(&a[i][j]);
    int t=2;
    for (int i = 1; i<= n; i++)
    {
        for (int j = t; j <m; j++)
        {
            a[i][j]=0;
        }
        t++;
        m--;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j<=n; j++)
        PutD(a[i][j]);

    
    

}
