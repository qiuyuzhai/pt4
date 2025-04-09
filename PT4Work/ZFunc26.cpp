#include "pt4.h"
#include<cmath>
using namespace std;
void RectPS(double x1,double y1,double x2,double y2,double& P,double& S)
{
    P=(fabs(x2-x1)+fabs(y2-y1))*2;
    S=fabs(x2-x1)*fabs(y2-y1);
}
void Solve()
{
    Task("ZFunc26");
    double a,b,c,d,p,s;
    int i=0;
    while(i<3)
    {
    pt >>a>>b>>c>>d ;
    RectPS(a,b,c,d,p,s);
    pt << p<< s;
    i++;
    }


}
