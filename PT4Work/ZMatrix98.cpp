#include "pt4.h"
using namespace std;

void Solve()
{
    Task("ZMatrix98");
    int n;
    pt >> n;
    double a[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pt >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pt << a[n-1-i][n-1-j];
        }
    }

}
