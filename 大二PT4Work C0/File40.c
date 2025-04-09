#include "pt4.h"
#include<stdio.h>
void Solve(void)
{
    Task("File40");
    char name[13];
    GetS(name);
    char*name2="a.tmp";
    FILE*f=fopen(name ,"rb");
    FILE*f2=fopen(name2 ,"wb");
    int a;
    int sz=sizeof(int);
    int k=1;
    int z[2]={};
    while (fread(&a,sz,1,f))
     if (k++%2!=0)
       fwrite (&a,sz,1,f2);
    else 
       fwrite(z,sz,2,f2);
    fclose(f);
    fclose(f2);
    remove(name);
    rename(name2,name);
     
    

}
