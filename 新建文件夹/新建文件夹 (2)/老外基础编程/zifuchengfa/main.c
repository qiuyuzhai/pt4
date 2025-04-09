#include <stdio.h>
#include <stdlib.h>

int main()
{   int m;
    int a,b,c;
    printf("into number:\n");
    scanf("%d",&m);
    a=m/100;
    b=(m/10)%10;
    c=m%10;
    printf("%d",a*b*c);
    return 0;
}
