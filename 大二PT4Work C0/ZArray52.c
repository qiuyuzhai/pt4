#include "pt4.h"
//Given an array A of N real numbers, create a new array B of the same size with elements defined as:
//BK	 = 	2·AK,	if AK < 5,
 //	 	AK/2	otherwise.
void Solve(void)
{
    Task("ZArray52");
    int n;
    GetN(&n);
    ShowN(n);
    double a[10];
  for (int i = 0; i < n; i++)
{
	GetD(&a[i]);
	ShowD(a[i]);
	ShowLine();
}
   double m=0;
 for (int i = 0; i < n; i++)
 {
 	//GetD(&a[i]);
  if (a[i]<5)
  {
    m=2*a[i];
    ShowD(m);
  }
  else if (a[i]>=5)
  {
    m=a[i]/2;
    ShowD(m);
  }
	PutD(m);
 }
}
