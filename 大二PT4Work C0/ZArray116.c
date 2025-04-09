#include "pt4.h"

void Solve(void)
{
    Task("ZArray116");
    int n, k = 1;
    GetN(&n);
    int a[10], b[10], c[10];
    for (int i = 0; i < n; ++i)
          GetN(&a[i]);
    b[0] = 1;//b0=1
    c[0] = a[0];//c数组里第一个元素和a数组里第一个元素一样
    for (int i = 1; i < n; ++i)
        if (a[i - 1] == a[i])//若a0=a1的话，b0就加一变成2
         ++b[k - 1];
        else
       {
        b[k] = 1;//a0不等于a1的话，b1=1
        c[k] = a[i];//c1=a0
        ++k;//k+1=2;
       }
     for (int i = 0; i < k; ++i)
           PutN(b[i]);//这里输出的是原数组中相同元素连续出现的个数
     for (int i = 0; i < k; ++i)
          PutN(c[i]);//这里输出的是原数组中的内容

}
