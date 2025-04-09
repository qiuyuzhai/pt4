#include "pt4.h"
using namespace std;

void swap(double&a,double&b)
{
    double t=a;
    a=b;
    b=t;
}
void Solve()
{
    Task("ZMatrix98");
    int m;
    pt>>m;
    double a[m][m];
    for(int i=0;i<m;i++)
       for(int j=0;j<m;j++)
           pt>>a[i][j];

    for(int i=0;i<m/2;i++)
       for(int j=0;j<m-i;j++)
           swap(a[i][j],a[m-1-i][m-1-j]);
    for(int i=m/2;i<m;i++)
       for(int j=0;j<m-1-i;j++)
          swap(a[i][j],a[m-1-i][m-1-j]);
    for(int i=0;i<m;i++)
       for(int j=0;j<m;j++)
           pt<<a[i][j];

}
