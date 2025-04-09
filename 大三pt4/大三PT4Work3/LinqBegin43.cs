// File: "LinqBegin43"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/*给定一个整数K(> 0)和一个非空字符串序列A.
得到一个字符序列，其定义如下：对于序列A的前K个元素，此字符串奇数位置的字符(1，3，。..）被输入到新的序列中，对于a的剩余元素，字符在偶数位置（2，4，）。..）被输入。 
在得到的序列中，反转元素的顺序。*/


namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin43");
            int k = GetInt();
            GetEnumerableString()
                .SelectMany((e,n)=>
                   e.Where((c, i) => i % 2 == (n < k ? 0 : 1)).Show())
            .Reverse().Put();

        }
    }
}
