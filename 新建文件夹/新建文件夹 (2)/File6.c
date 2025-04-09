#include "pt4.h"
//#include<string.h>
#include <stdio.h>

void Solve(void)
{
    Task("File6");
    int k;
    GetN(&k);
    char name[13];
    GetS(name);
    int sz=sizeof(int);
    FILE*f=fopen(name,"rb");
        fseek(f,0,SEEK_END);
    int n=ftell(f)/sz;
    int a=-1;
    if (k<=n&&k>=1)
    {
        fseek(f,(k-1)*sz,SEEK_SET);
        fread(&a,sz,1,f);
    }
        fclose(f);//这里最后不要忘了
        PutN(a);
    
    
    
    
    

}
