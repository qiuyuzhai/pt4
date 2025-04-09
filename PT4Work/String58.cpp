#include "pt4.h"
using namespace std;

void Solve()
{
    Task("String58");
    string m;
    pt>>m;
    string f=m.substr(m.find_last_of("\\/")+1);
    f=f.substr(0,f.find_last_of("."));
    pt<<f;
}