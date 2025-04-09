#include "pt4.h"
#include <math.h>
// An integer N and a sequence of N integers are given. 
//Output the maximal amount of successive elements whose values are even numbers. 
//If the sequence does not contain even numbers, then output 0.

void Solve(void)
{
    Task("ZMinmax26");
    int n;
    GetN(&n);
    int index=0;
    int x=0;
    int arr[n];
    for ( int i = 0; i < n; i++)
    {
        GetN(&arr[i]);
    }
    for ( int i = 0; i < n; i++)
    {
        if(arr[i]%2==0)
        {
        index++;
        if(arr[i+1]%2!=0)//当且仅当满足这种情况时才能结束该循环
        break;
        }
    }
    for ( int i = n-1; i>0; i--)
    {
        if(arr[i]%2==0)
        {
        x++;
        if(arr[i-1]%2!=0)//哦哦，数组里的东西得是循环那里的变量
        break;
        }
    }
    if(index>x)
    PutN(index);
    else
    PutN(x);
    
}
