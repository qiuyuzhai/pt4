#include "pt4.h"
//Two positive real numbers A and B (A > B) are given.
// A segment of length A contains the greatest possible amount of segments of length B (without overlaps). 
//Not using multiplication and division乘法和除法, find the amount of segments B, which are placed on the segment A.

void Solve(void)
{
    Task("While2");
    double a,b,c;
    int s;
    GetD(&a);
    GetD(&b);
    c=a;//ShowD(c);  
    while(a>=b)//不能写等号， 
    {
        a-=b;
        
    }
    ShowD(a);
    s=(c-a)/b;
    PutN(s);



}
