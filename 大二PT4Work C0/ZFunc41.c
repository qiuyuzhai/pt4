#include "pt4.h"
#include<math.h>
//Write a real-valued function Sin1(x, ε) (x and ε are real numbers, ε > 0) 
//that returns an approximate value of the function sin(x) defined as follows:
double Sinl(double x,double y )
{
    double s=0,h=x;
    int i=1;
    while (fabs(h)>=y)
    {
        s+=h;
        h*=-x*x/((2*i)*(2*i+1));
        i++;
    }
    
    return s;
}
void Solve(void)
{
    Task("ZFunc41");
    double x,y;
    GetD(&x);
    for (int i = 0; i < 6; i++)
    {
        GetD(&y);
        PutD(Sinl(x,y));
    }
    
    
    
	}


