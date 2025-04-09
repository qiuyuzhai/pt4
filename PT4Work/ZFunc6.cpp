#include "pt4.h"
using namespace std;
    // alt +shift+F
int SumRange(int A, int B)
{
    auto m = 0;
    for (int i = A; i <= B; i++)
    {
        m += i;
    }
    return m;
}

void Solve()
{
    Task("ZFunc6");
    int a, b, c;
    pt >> a >> b >> c;
    pt << SumRange(a, b) << SumRange(b, c);
}
