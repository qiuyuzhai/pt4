#include "pt4.h"
#include <stdio.h>

void Solve(void)
{
    Task("File36");
    char name[13];
    GetS(name);
    char*name2="a.tmp";
    FILE*f=fopen(name ,"rb");
    FILE*f2=fopen(name2 ,"wb");
    int a;
    int sz=sizeof(int);
    while (fread(&a,sz,1,f))
       fwrite(&a,sz,1,f2);
    fseek(f,0,SEEK_SET);
    while (fread(&a,sz,1,f))
       fwrite(&a,sz,1,f2);
    fclose(f);
    fclose(f2);
    remove(name);
    rename(name2,name);
    
    

}
