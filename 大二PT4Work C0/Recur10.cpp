#include "pt4.h"
using namespace std;

int digitsum(int k)
{
   int b=0;
   if (k<0)
      k=-k;
   while(k>0)
   {
      b+=k%10;
      k/=10;
   }
   return b;
}

void Solve()
{
    Task("Recur10");
    for (int i = 0; i < 5; i++)
    {
        pt<<digitsum(GetInt());
    }

}
