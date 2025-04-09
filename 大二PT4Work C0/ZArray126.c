#include "pt4.h"
// An integer L (> 0) and an array of N integers are given.
// Replace each series, whose length is equal to L, by one element with zero value

void Solve(void)
{
  Task("ZArray126");
  int l, n, k = 1;
  GetN(&l);
  GetN(&n);
  int a[20], b[20], c[20];
  for (int i = 0; i < n; i++)
  {
    GetN(&a[i]);
  }
  b[0] = 1;
  c[0] = a[0];
  for (int i = 1; i < n; ++i)
    if (a[i - 1] == a[i])
      ++b[k - 1];
    else
    {
      b[k] = 1;
      c[k] = a[i];
      ++k;
    }
  for (int i = 0; i < k; ++i)
  {
    if (b[i]==l)
    {
      b[i]=1;
      c[i]=0;
    }
  }
  for (int i = 0; i < k; i++)
  {
    int h=b[i];
    for (int w = 0; w < h; w++)
    {
      PutN(c[i]);
    }
    
  }
  
 
  

  
}
