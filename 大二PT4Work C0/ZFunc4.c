#include "pt4.h"
//Write a real-valued function RingS(R1, R2) that returns the area of a ring bounded by a concentric circles of radiuses R1 and R2 (R1 and R2 are real numbers, R1 > R2).
// Using this function, find the areas of three rings with given outer and inner radiuses.
// Note that the area of a circle of radius R can be found by formula S = π·R2. 
//Use 3.14 for a value of π.
double RingS(double R1,double R2 )
{
    double s=0;
    s=3.14*(R1*R1-R2*R2);
    return s;
}
void Solve(void)
{
    Task("ZFunc4");
    
    for(int i=0;i<3;i++)
    {
    double a,b;
    GetD(&a);
    GetD(&b);
    PutD(RingS(a,b));
	}

}
