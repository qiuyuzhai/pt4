#include "pt4.h"
using namespace std;
int ioint(char c)
{
    return c-'0';
}
int expr(string s,int k)
{
   if (k==0)
      return ioint(s[0])+expr(s,1);
   if (k<s.length())
      switch (s[k])
      {
        case '+':
           return ioint(s[k+1])+expr(s,k+2);
        break;
      
      default:
        break;
      }
   {
    
   }
   
   
}
void Solve()
{
    Task("Recur14");

}
