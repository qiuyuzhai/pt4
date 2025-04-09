#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Text4");
    ifstream f(GetString());
    int nc=0,cs=0;
    while (f.peek()!=EOF)
    {
        string s;
        getline(f,s);
        nc+=s.length();
        ns++;
    }
    f.close();
    pt<<nc<<ns;
    
}
