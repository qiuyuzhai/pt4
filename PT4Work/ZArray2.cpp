#include "pt4.h"
using namespace std;

void Solve()
{
    Task("ZArray2");
    int n;
    pt>>n;
    int a[20];
    a[0]=2;
    for (int i=1;i<n;i++)
    {
        a[i]=a[i-1]*2;
    }
    for(int i=0;i<n;i++)
    {
        pt<<a[i];
    }


}
