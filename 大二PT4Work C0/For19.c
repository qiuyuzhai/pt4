#include "pt4.h"
#include<math.h>
// Given an integer N (> 0), find the value of a following product:
//N! = 1·2·…·N (N–factorial). 
//To avoid the integer overflow, 
//compute the product using a real variable and output the result as a real number.

void Solve(void)
{
    Task("For19");
    int N;
    GetN(&N);
    double p=1.0;
    for(int k=1;k<=N;k++)
    {
        p*=k;
        
    }
    PutD(p);
}
