#include "pt4.h"
#include<math.h>
using namespace std;

void Solve()
{
    Task("TimD4");
    int n;
    pt>>n;
    int a = -1, b = -1, c = -1;
 // 遍历所有可能的 a, b, c
  for (int i = 1; i <= 100; ++i)
  {
    for (int j = i + 1; j <= 100; ++j)
    { // j 必须大于 i，以确保 a 和 b 不同
      for (int k = 1; k <= 100; ++k)
      {
        // 确保 c 不等于 a 或 b
        if (k != i && k != j)
        {
          // 检查 a^n + b^n = c^n
          if (pow(i, n) + pow(j, n) == pow(k, n))
          {
            // 找到第一个满足条件的解
            a = i;
            b = j;
            c = k;
          }
        }
      }
    }
  }    
  pt<<a;
  pt<<b;
  pt<<c;
}
