#include "pt4.h"
#include <math.h>
// Given two integers A and B (A < B),
// find the sum of squares of all integers in the range A to B inclusive.
void Solve(void)
{
  Task("For9");
  int A, B,  p = 0;
  GetN(&A);
  GetN(&B);
  for (int k = A; k <= B; k++)
  {

    p += k * k;
  }
  PutN(p);
}
