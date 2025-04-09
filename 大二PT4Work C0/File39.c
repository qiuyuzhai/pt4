#include "pt4.h"
#include <stdio.h>

void Solve(void)
{
    Task("File39");
    char name[13];
    GetS(name);
    char*name2="a.tmp";
    FILE*f=fopen(name ,"rb");
    FILE*f2=fopen(name2 ,"wb");
    int a;
    int sz=sizeof(int);
    while (fread(&a,sz,1,f))
    {
        fwrite(&a,sz,1,f2);
        if (a>=5&&a<=10)
         fwrite(&a,sz,1,f2);
    }
    fclose(f);
    fclose(f2);
    remove(name);
    rename(name2,name);
    

}
