#include "pt4.h"
//An array A of N real numbers is given.
// Without changing the array A, 
//output indices that correspond to array elements in ascending order of their values. 
//For solving the task create an additional index array I, which contains indices in the range 0 to N−1,
// and use the bubble sorting (see ZArray112) as follows: 
//compare elements of array A (with indices I0 and I1, I1 and I2, and so on) and exchange, 
//if necessary, values of corresponding elements of index array I.
// After repeating N − 1 times of such array pass, the required sequence of indices will be contained in the array I.
void Swap(double *a,double*b)//它这个应该是不会交换位置，只是交换位置里的内容
{
    double x=*a;
    *a=*b;
    *b=x;
}
void Solve(void)
{
    Task("ZArray115");
    int n,j;
    GetN(&n);
    double a[80],b[80];
    for(int i=0;i<n;++i)
   {
     GetD(&a[i]);
     b[i]=a[i];//b组和原来的a组完全一样
   }
    for(int h=0;h<n-1;h++)//题目也告诉你了，要比较n-1次,其实是每一排的两两比较共进行n-1次
   {
       for(j=0;j<n-h;++j)//他这个冒泡排序的思路，和许阳讲的一样，就是进行了一次后，有一个元素是到了自己最终该到的位置了，比较的元素就少了一个
       {
         if(a[j]>a[j+1])//如果后面的比前面的小，就把后面的往前面移（冒泡排序的原理）
          {
            Swap(&a[j],&a[j+1]);
          }
        }
   }//这里循环出来的是升序的a[j]组，j是从小到大的那种
    for(int j=0;j<=n;++j)//这里为什么是等于号？我也不知道为啥，但运行出来发现少一个，前面几个数都对，那就这里多循环一次
    {
       for(int i=0;i<n;++i)
       { 
          if(a[j]==b[i])
         { 
           PutN(i); 
         }
       }
   }
}