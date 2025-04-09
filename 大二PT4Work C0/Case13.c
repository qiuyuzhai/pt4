#include "pt4.h"
#include <math.h>
//Elements of a right isosceles triangle are numbered as:
// 1 — leg a, 2 — hypotenuse 
//c = a·(2)1/2, 3 — altitude h drawn onto hypotenuse (h = c/2),
// 4 — area S = c·h/2. 
//The order number of one element and its value (as a real number) are given.
//Output values of other elements in the same order.



void Solve(void)
{
    Task("Case13");
    int m;
    double a,c,h,S;
    GetN(&m);
    
    switch (m)
    {
    case 1:
        GetD(&a);
        c=sqrt(2)*a;
        h = c/2;
        S= 0.5 * c * h;
        PutD(c);
        PutD(h);
        PutD(S);
        break;
    case 2:
        GetD(&c);
         a=1/sqrt(2)*c;
         h=c/2;
         S=c*h/2;
    PutD(a);
    PutD(h);
    PutD(S);
        break;
    case 3:
        GetD(&h);
        a=sqrt(2)*h;
        c=2*h;
        S=c*h/2;
    PutD(a);
    PutD(c);
    PutD(S);
    break;
    case 4:
        GetD(&S);
        a=sqrt(2*S);
        c=sqrt(2)*a;
        h=c/2;
    PutD(a);
    PutD(c);
    PutD(h);
    break;
    }
    
}
