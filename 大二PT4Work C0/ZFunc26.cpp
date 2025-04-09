#include "pt4.h"
#include<math.h>
using namespace std;

void RectPs(double x1,double y1,double x2,double y2,double &P,double &S)
{
    P=2*fabs(x1-x2)+2*fabs(y1-y2);
    S=fabs(x1-x2)*fabs(y1-y2);
}
void Solve()
{
    Task("ZFunc26");
    for(int i=0;i<3;i++)
    {
        double x1,y1,x2,y2,S,P;
        GetD(&x1);
        GetD(&y1);
        GetD(&x2);
        GetD(&y2);
        RectPs(x1,y1,x2,y2,P,S);
        PutD(P);
        PutD(S);
    }

}
