#include "pt4.h"
// Given an array of N integers
//  whose values are in ascending or in descending order,
// find the amount of its elements with distinct values.
void Solve(void)
{
  Task("ZArray43");
  int n,a[10],k=1;
  GetN(&n);
  for (int i = 0; i < n; i++)
      GetN(&a[i]);
  for (int i = 0; i < n-1; i++)//对哦，数字间两两比较的次数是元素个数减一
    {
      if (a[i+1]!=a[i])
      {
        k++;
      }
    }
    PutN(k);
  }
    
  

