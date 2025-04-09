#include "pt4.h"
#include <string.h>
//Given an integer,它哪里错了
// output its description string as: 
//"negative even number", "zero number", "positive odd number", etc.

void Solve(void)
{
    Task("If29");
    int n;
    GetN(&n);
    char s[80];
    if(n==0)
      strcpy(s,"zero");
    else
    { if(n<0)
        strcpy(s,"negative");
      else
        strcpy(s,"positive");
      if(n % 2 != 0)
        strcat(s," odd");
      else
        strcat(s," even");

    }
    strcat(s," number");
    PutS(s);


}
