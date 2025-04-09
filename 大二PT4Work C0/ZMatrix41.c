#include "pt4.h"

void Solve(void)
{
    Task("ZMatrix41");
    int m,n;
    int a[10][10];
    GetN(&m);
    GetN(&n);
    int b[n];
    for(int i=0;i<m;++i)
      for(int j=0;j<n;++j)
       GetN(&a[i][j]);
    for(int j=0;j<n;++j)
    {
        int p=0;
        for(int i=0;i<m;++i)
        {
          if(a[i][j]==a[i+1][j]||a[i][j]==a[i+2][j]||a[i][j]==a[i+3][j])
             ++p;
        }
            b[j]=p;
    }
            int max=DBL_MIN;
            for(int j=0;j<n;++j)
            {
               if(b[j]>max)
                  max=b[j]; 
            }
            for(int i=0;i<n;++i)
            {
              if(b[i]==max)
              {
              PutN(i);
              break;
              }
            }
             
          
        
    
}

}
