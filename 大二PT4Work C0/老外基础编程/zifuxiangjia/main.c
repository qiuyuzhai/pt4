#include <stdio.h>
#include <stdlib.h>

int main()
{   int m;
    int a,b,c;
    printf("shurushuzi:");
    scanf("%d", &m);
    a=m/100;
    b=(m/10)%10;
    c=m%10;
    if(a>b&a>c){printf("%d",a);
    }
    else{if(b>c){printf("%d",b);}
    else{printf("%d",c);}}

    return 0;
}
