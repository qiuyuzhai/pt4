#include "pt4.h"
using namespace std;

double fact(int n)
{
    if (n<=1)
      return 1.0;
    return fact(n-1)*n;
}

void Solve()
{
    Task("Recur1");
    for (int i = 0; i < 5; i++)
    {
        pt<<fact(GetInt());
    }
    

    
    

}
