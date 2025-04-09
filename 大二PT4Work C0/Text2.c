#include "pt4.h"
#include<stdio.h>

void Solve(void)
{
    Task("Text2");
    char name[13];
    GetS(name);
    int n;
    GetN(&n);
    char a=97;
    FILE*f1=fopen(name,"w");
    int k=1;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            fputc(a+j,f1);
        }
        fputc('\n',f1);
        
    }
    fclose(f1);
}
