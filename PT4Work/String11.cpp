#include "pt4.h"
using namespace std;

void Solve()
{
    Task("String11");
    string s;
    pt >> s;
    string s1;
    s1 +=s[0];
    int n = s.length();
    for(int i=1; i < n; i++)
   { 
        s1+= ' ';
        s1+= s[i];
     }
    pt << s1;

}
