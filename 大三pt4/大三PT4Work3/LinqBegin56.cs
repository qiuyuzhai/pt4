// File: "LinqBegin56"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*给出了整数序列A。 将序列a的元素以相同的数字结尾分组，并根据该分组，得到一个形式为"D：S"的字符串序列，其中D是分组键（即序列A中至少一个数字结尾的某个数字），
    S是从A中以数字D结尾的所有数字的总和。
 使用GroupBy方法。*/
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin56");
            GetEnumerableInt()
               .GroupBy(e => Math.Abs(e) % 10)
               .OrderBy(g => g.Key)
               .Select(g => g.Key + ":" + g.Sum())
               .Put();




        }
    }
}
