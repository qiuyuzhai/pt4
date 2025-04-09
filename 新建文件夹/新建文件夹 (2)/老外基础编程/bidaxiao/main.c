#include <stdio.h>
#include <stdlib.h>

int main()
{   int a,b,c;
    int max;
    printf("input number:\n");
    scanf("%d%d%d",&a,&b,&c);
    if(a>b&a>c){printf("max=%d",a);
    }
    else {if(b>c){printf("max=%d",b);
    }
    else {printf("max=%d",c);}
    }
    return 0;
}
