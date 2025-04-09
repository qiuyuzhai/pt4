#include "pt4.h"
using namespace std;

void Solve()
{
    Task("String9");
    int n;
    char c1,c2;
    pt>>n>>c1>>c2;
    string s;
    for(int i=0;i<n/2;i++)
        s=s+c1+c2;
    pt<<s;

}
