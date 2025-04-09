#include "pt4.h"
using namespace std;

void Solve()
{
    Task("String10");
    string s;
    pt>>s;
    int n=s.length();
    for (int i = 0; i < n/2; i++)
         swap(s[i],s[n-i-1]);
    pt<<s;
    
    string s,s1;
    pt>>s;
    int n=s.length();
    for (int i = 0; i < n; i++)
        s1=s1+s[i];
    pt<<s1;

    string s=GetString();
    reverse(s.begin(),s.end());
    pt<<s;

    char s[81], sl[81];
    pt>>s;
    int n=strlen(s);
    for(int i=0;i<n;i++)
        sl[i]=s[n-1-i];
    sl[n]='\0';
    pt<<sl;

    

}
