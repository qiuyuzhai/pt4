#include "pt4.h"
#include<stdio.h>
//Given a string with the decimal representation of a positive integer, 
//output a new string with the binary representation of this integer.

void Solve(void)
{
    Task("String25");
    char s[80],s1[80];
    GetS(s);
    int i=0;
   for (char *p = s; *p != 0; p++)
   {
      int a=*p;
      while(a>0)
      {
        s1[i]=a%2;
        i++;//是余数
         a=a/2;
      }
   }
   int k=0;
   for ( k = i-1; k >=0; k--)
   {
    PutS(s1[k]);
   }
   
   
   
        
            
    

}
