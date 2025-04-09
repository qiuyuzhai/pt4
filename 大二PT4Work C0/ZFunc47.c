#include "pt4.h"
int GCD2(int a,int b)
    {
        while (b!=0)
        {
            int x=a;
            a=b;
            b=x%b;
        }
        return a;
    }
    void Frac1(int a,int b,int*p,int*q)
    {
       *p=a/GCD2(a,b);
       *q=b/GCD2(a,b);
    }
void Solve(void)
{
    Task("ZFunc47");
    int a,b,c,d,p1,p2,q1,q2;
    GetN(&a);
    GetN(&b);
    for (int i = 0; i < 3; i++)
    {
        GetN(&c);
        GetN(&d);
        int p,q;
        p=a*d+b*c;
        q=b*d;
        if (q<0)
        {
            q=-1*q;
            p=-1*p;
        }
        PutN(p/abs(GCD2(p,q)));
        PutN(q/abs(GCD2(p,q)));
    }
}
