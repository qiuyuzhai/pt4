#include "pt4.h"
#include<stdio.h>
#include<math.h>
#include<stdio.h>

void Solve(void)
{
    Task("Text42");
    double a,b;
    int n;
    char name[80];
    GetD(&a);
    GetD(&b);
    GetN(&n);
    GetS(name);
    FILE*f=fopen(name,"w");
    double h=(b-a)/n;
    for (int i = 0; i <=n; i++)
    {
        double x=a+i*h;
        fprintf(f,"%10.4f%15.8f\n",x,sqrt(x));
        char s[80];
        printf(s,"%10.4f%15.8f\n",x,sqrt(x));
    }
    fclose(f);
}
