#include "pt4.h"
using namespace std;

void Solve()
{
    Task("String12");
    string s;
    int n;
    pt >> s>>n;
    Show(n);
    Show(s);
    string delim(n,'*');//这是创建了一个重复的小数列
    for (int i=s.length()-1;i>0;i--)
    { 
        s.insert(i,delim);
    }
        
    pt<<s;
    



}
