#include "pt4.h"
#include<math.h>
//Given an integer N (> 0), find the amount and the sum of its digits. 数字的字符个数和他们相加的和
//Use the operators of integer division and taking the remainder after integer division.
//5213
//521
//52
//5
//取整了三次
//每次都取余数；1,2，5
void Solve(void)
{
    Task("While18");
    int n,a=0,s=0;
    GetN(&n);
    
    while (n>0)
    {
        s+=n%10; //3 1 2 5
        n/=10;  //521 52 5 0.5
        ++a;
     }
       
    
    PutN(a);
    PutN(s);
    }

    
    
    
    

