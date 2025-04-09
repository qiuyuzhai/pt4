#include <stdio.h>
#include <stdlib.h>

int main()
{ 
    int a = 0;
    printf("month\n");
    scanf("%d",&a);
    if(a>=3&a<=5){printf("spring");}
    else if(a>=6&a<=8){printf("summer");
    }else if(a>=9&a<=11){printf("antumn");
    }else {printf("winter");}

    return 0;
}
