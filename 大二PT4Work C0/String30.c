#include "pt4.h"

void Solve(void)
{
 
{
    Task("String30");
    int i ,j=0 , m;
    char s[80]，s0[80];
    char c;
    GetC(&c);
    GetS(s);
    GetS(s0);
    int n=strlen(s);//8
    for ( i =n-1; i >=0; i--)
    {
        if (s[i]==c)
        {
            for ( m = n-i-1+strlen(s0)*j; m >0 ; m--)
            {
                s[i+strlen(s0)+m]=s[i+m];
            }
            
            strncpy( s+i+1 , s0 , strlen(s0));
            j++;
        }
    }
    s[n+j*strlen(s0)]='\0';
    PutS(s);
    ShowN(j);
}

}
