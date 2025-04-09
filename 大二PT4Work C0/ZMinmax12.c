#include "pt4.h"
#include <float.h>
void Solve(void)
{
    Task("ZMinmax12");
    int n;
    GetN(&n);
    double min=DBL_MAX;
    for (int i = 0; i < n; i++)
    {
        double a;
        GetD(&a);
        if (a>0&&a<min)
        {
            min=a;
        }
        
    }
    if (min==DBL_MAX)
    {
        min=0;
    }
    PutD(min);
    
    

}
