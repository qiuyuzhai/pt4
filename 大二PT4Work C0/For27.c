#include "pt4.h"
#include<math.h>

//A real number X (|X| < 1) and an integer N (> 0) are given. Compute the expression
//X + 1·X3/(2·3) + 1·3·X5/(2·4·5) + … +
//+ 1·3·…·(2·N−1)·X2·N+1/(2·4·…·(2·N)·(2·N+1)).
//The result is an approximate value of asin(X).

void Solve(void)
{
    Task("For27");
    double x;
    int k,s,n,z=1,m=2;
    GetD(&x);
    GetN(&n);
        for( k=1;k<=n;k++)
    {
        for (int i = 2; i < k; i++)//原来这个分子的变量是和整个式子的变量相关的
        {
            z*=(2i-1);
        }
        for (int j = 2; j < k; j++)
        {
            m*=(2*j);
        }
        m*=(2j+1);//对哦，每次这个东西都会出现，所以应该写在循环里面去
        s+=z*pow(x,2*n+1)/m;

        
    }
    s=x+z;
    PutD(s);
    
}
