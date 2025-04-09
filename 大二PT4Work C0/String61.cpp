#include "pt4.h"
#include<string>
#include<fstream>
using namespace std;

void Solve()
{
    Task("String61");
    string s,s0;
    pt>>s;
    int n=s.length();
    int k;
    for (int i = 0; i < n; i++)
    {
        if (s[i]==92)
            k=i;
    }
    int k1=0;
    for (int i = 0; i < k; i++)
    {
        if (s[i]==92)
          k1=i;
    }
    if (k1==0)
       s0[0] = 92;
    else
       s0=s.substr(k1+1,k-k1-1);
    pt<<s0;
    
}
    


