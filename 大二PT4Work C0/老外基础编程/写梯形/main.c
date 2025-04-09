#include <stdio.h>
#include <stdlib.h>

int main()
{   int a,b,c,d,e;
    float f;
    printf("input three numbers");
    scanf("%d%d%d",&a,&b,&c);
    d=a+b+c;
    e=a*b*c;
    f=(a+b+c)/3.000000;
    printf("the sum is %d\n",d);
    printf("the product is %d\n",e);
    printf("the mean number is %f\n",f);

    return 0;
}
