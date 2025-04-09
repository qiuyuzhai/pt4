#include "pt4.h"
// Write a real-valued function Fact(N) that returns a factorial of a positive integer N: N! = 1·2·…·N
// Using this function, find the factorials of five given integers.
double Fact(int N)
{
   double s = 1;

  for (int i = 1; i <= N; i++)
  {
    s *= i;
  }
  return s;
}
void Solve(void)
{
  Task("ZFunc19");

  for (int i = 0; i < 5; i++)
  {
    int k;
    GetN(&k);
    ShowN(k);
    PutD(Fact(k));
    ShowD(Fact(k));
    ShowLine();
  }
}
