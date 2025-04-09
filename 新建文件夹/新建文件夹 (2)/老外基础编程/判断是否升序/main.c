#include <stdio.h>
#include <stdlib.h>

int main()
{   int a,b,c;
    printf("input three numbers:\n");
    scanf("%d%d%d",&a,&b,&c);
    if(c>b&b>a){printf("yes");}
    else{printf("no");}
    return 0;
}
