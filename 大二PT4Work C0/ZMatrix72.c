#include "pt4.h"
//An M × N matrix of real numbers is given. 
//Insert a new column of elements with the value 1 before the first matrix column that contains positive numbers only. 
//If the matrix does not contain the required columns, then do not change it.
    void Solve(void)
{
    Task("ZMatrix72");
     int m,n;
     double a[10][10],b[10][10];
     GetN(&m);
     GetN(&n);
    for(int i=1;i<=m;++i)
      for(int j=1;j<=n;++j)
         GetD(&a[i][j]);//输入
    int k=0,p=0,c=1;
    for(int j=1;j<=n;++j)//一列列展开了
    {
     for(int i=1;i<=m;++i)
      {
        if(a[i][j]>0)//一列中0的个数
       {
          k++;
         }
      }
     if(k==m&&p==0)
    {
       for(int i=1;i<=m;++i)
    {
      b[i][c]=1.00;
      b[i][c+1]=a[i][j];
     }
      c+=2;
       ++p;
     }
    else { 
     for(int i=1;i<=m;++i)
    {
    b[i][c]=a[i][j];
    }
       c++;
     }
      k=0;
    }
    for(int i=1;i<=m;++i)
    for(int j=1;j<=n+p;++j)
     PutD(b[i][j]);

}
