#include "pt4.h"
using namespace std;

void Solve()
{
    Task("String34");
    string s,s0;
    pt>>s>>s0;
    size_t k=s.rfind(s0);
    if (k!=s.npos)
        s.erase(k,s0.length());
    pt<<s;
    




}
