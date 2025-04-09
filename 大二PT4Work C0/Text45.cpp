#include "pt4.h"
#include<fstream>
#include<string>
using namespace std;
void Solve()
{
    Task("Text45");
    ifstream f(GetString());
    int cnt=0;
    double sum=0;
    double a;
    f>>a;
    while(f)
    {
        int k=(int)a;
        double h=(double)a;
        if (k!=a)
        {
            cnt++;
            sum+=h;
        }
        f>>a;
    }
    f.close();
    pt<<cnt<<sum;
}
