#include "pt4.h"
using namespace std;

int cnt;


int fib(int n)
{
    cnt++;
    return n<=2?1:fib(n-2)+fib(n-1);
}

void Solve()
{
    Task("Recur4");
    for (int i = 0; i < 5; i++)
    {
        cnt=0;
        pt<<fib(GetInt())<<cnt;//这题还要求输出使用fib的次数
    }
    
}
