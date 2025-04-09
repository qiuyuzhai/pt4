#include "pt4.h"
#include<string.h>
//A string with at least one blank character is given. 
//Output the substring of S that contains all characters between the first and the second blank character. 
//If the string S contains only one blank character then output an empty string.

void Solve(void)
{
    Task("String39");
    char s[80];
    GetS(s);
    char h[80]={0};
    char d;
    int a,b,c,j=0;
    for (int i = 0; i < strlen(s); ++i)
    {
        a=s[i];
        if (a==32||a==127)//说明它是ASCALL里的首尾符号
        {
            j+=1;
            if (j==1)
            {
                b=i;
            }
            else if(j==2)
            {
                c=i;
                break;
            }
            
        }
        a=0;   
    }
    if (j==1)
    {
        PutS("");
    }
    else 
    {
    
        for (int i = b+1; i< c; i++)
        {
            d=s[i];
            h[i-(b+1)]=d;
        }
        PutS(h);
        
    }
    

}
