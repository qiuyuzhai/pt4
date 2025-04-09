#include "pt4.h"
using namespace std;
#include"sstream"
void Solve()
{
    Task("String5");
    int n;
    pt>>n;
    ostringstream os;
    os<<n;
    string s=os.str();
    Show(s);
}
