#include "pt4.h"
#include<math.h>
using namespace std;
void TrianglePS( double a , double &P,double &S)
{
    P=3*a;
    S=sqrt(3)*a*a/4;
}

void Solve()
{
    Task("ZFunc25");
    for(int i=0;i<3;++i)
    {
        double a,P,S;
        pt >> a;
        TrianglePS(a,P,S);
        pt << P <<S;
    }


}
