#include "pt4.h"
//ZSeries10. An integer N and a sequence of N integers are given. 
//Output the logical value True if the sequence contains positive-valued elements, otherwise output False.

void Solve(void)
{
    Task("ZSeries10");
    int n;
    GetN(&n);
    //ShowN(n);
    bool res=false;
    for (int i = 1; i <= n; i++)
    {
        int a;
        GetN(&a);
        ShowN(a);
        if (a>0)
        {
            res=true;
            ShowN(res);
            break;
        }
       
    }
     PutB(res);
    
    

}
