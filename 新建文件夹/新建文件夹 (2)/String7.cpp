#include "pt4.h"
using namespace std;

void Solve()
{
    Task("String7");
    string s;
    pt>>s;
    pt<<(int)s[0]<<(int)s[s.length()-1];
}
void Solve1()
{
    Task("String7");
    string s=GetString();
    pt<<(int)s.front()<<(int)s.back();
    
}