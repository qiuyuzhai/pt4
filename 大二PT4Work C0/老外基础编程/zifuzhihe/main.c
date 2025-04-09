#include <stdio.h>
#include <stdlib.h>

int main()
{   int a,b,c,max;
    printf("shuru:\n");
    scanf ("%d%d%%d",&a,&b,&c);
    max=a;
    if(b>max){
            max=b;
    }
    if(c>max){
        max=c;
    }
    printf("maximum is:%d",max);
    return 0;
}
