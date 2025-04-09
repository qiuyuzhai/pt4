#include "pt4.h"
using namespace std;
void Swap(double &a,double &b)
{
    double x=a;
    a=b;
    b=x;
}

void Solve()
{
    Task("ZFunc31");
    double a,b,c,d;
    pt>>a>>b>>c>>d;
    Swap(a,b);
    Swap(c,d);
    Swap(b,c);
    pt <<a<<b<<c<<d;


}
