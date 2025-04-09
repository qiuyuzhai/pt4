#include "pt4.h"
#include <float.h>
//ZMinmax2. An integer N and a sequence of N rectangles are given.
// Each rectangle is defined by a pair of its sides (a, b). 
//Find the rectangle with the minimal area and output the value of its area

void Solve(void)
{
    Task("ZMinmax2");
    int n;
    GetN(&n);
    double a,b,h,s=DBL_MAX;
    //GetD(&a);
    //GetD(&b);
    //h=a*b;
    for (int i = 0; i < n; i++)
    {
        GetD(&a);
        GetD(&b);
        h=a*b;
        ShowD(a);
        ShowD(b);
        ShowD(h);
        ShowLine();
        if (h<s)
        {
            s=h;
            continue;
        } 
    }
    PutD(s);
    
    
    
    
    
    

    

}
