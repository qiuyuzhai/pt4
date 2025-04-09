#include "pt4.h"
#include<string.h>

void Solve(void)
{
    Task("String58");
     char s[80],s1[80];
     GetS(&s);
    int x=0,j,k;
    int len = strlen(s);
    for(int i=len-1; i>=0; i--)
       if(s[i] == '.')
       { 
         j=i;
        break;
        } 
    for(int i=len-1; i>=0; i--)
     if(s[i] == '\\')
     {
       k=i;
       break; 
     } 
    for(int i=k+1;i<j;i++)
    {
     s1[x]=s[i];
     x++;
     }
     s1[x]=0;
    PutS(s1);

}


