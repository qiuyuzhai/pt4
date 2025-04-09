#include "pt4.h"
//An M × N matrix of real numbers is given.
//For each matrix row find the amount of elements that are smaller than the average of all elements of this row.

void Solve(void)
{
    Task("ZMatrix29");
    int m,n,h=0;
    GetN(&m);
    GetN(&n);
    double a[10][10],z=0;
    for (int i = 0; i < m; i++)
   {
        for (int j = 0; j < n; j++)
        {
            GetD(&a[i][j]);
            z+=a[i][j];
        }
        double p=z/n;
        for (int j = 0; j< n; j++)
        {
           if(a[i][j]<p)
           h++;
            
        }   
         PutN(h);
         z=0;
         h=0;
    }
   
    
    


}
