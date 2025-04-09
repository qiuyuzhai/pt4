#include "pt4.h"
using namespace std;

string s;
int k;

char NextChar()
{
    k++;
    return s[k];
}
void SkipChar(int n)
{
    k+=n;
}
bool Calc()
{
    char c=NextChar();
    if (c=='T')
       return true;
    if (c=='F')
       return false;
    if (c=='O')
    {
        SkipChar(2);
        bool a=Calc();
        SkipChar(1);
        bool b=Calc();
        SkipChar(1);
        return a||b;
    }
    SkipChar(3);
    bool a=Calc();
    SkipChar(1);
    bool b=Calc();
    SkipChar(1);
    return a&&b;
    
}

void Solve()
{
    Task("Recur21");
    pt>>s;
    k=-1;
    pt<<Calc();

}
