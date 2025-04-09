#include "pt4.h"

void Solve(void)
{
    Task("String43");
    char s[80];
    GetS(s);
    strcat(s," ");
    int k=0;
    while (*s!='\0')
    {
        char*p=strchr(s,' ');
        if(*s=='E')
        k++;
        while(*p==' ')
        ++p;
        strcpy(s,p);

    }
    PutN(k);
    

}
