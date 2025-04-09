// File: "LinqBegin9"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//给出整数序列。 如果序列不包含正元素，则打印其最小正元素或数字0。
namespace PT4Tasks
{
    public class MyTask : PT
    {
        // When solving tasks of the LinqBegin group, the following
        // additional methods defined in the taskbook are available:
        // (*) GetEnumerableInt() - input of a numeric sequence;
        // (*) GetEnumerableString() - input of a string sequence;
        // (*) Put() (extension method) - output of a sequence;
        // (*) Show() and Show(cmt) (extension methods) - debug output
        //       of a sequence, cmt - string comment;
        // (*) Show(e => r) and Show(cmt, e => r) (extension methods) -
        //       debug output of r values, obtained from elements e
        //       of a sequence, cmt - string comment.

        public static void Solve()
        {
            Task("LinqBegin9");
            var a = GetEnumerableInt();

            // 查找序列中所有的正数
            var positiveNumbers = a.Where(x => x > 0);

            // 获取最小的正数，如果没有正数，则返回0
            int b = positiveNumbers.Any() ? positiveNumbers.Min() : 0;

            // 输出结果
            Put(b);

        }
    }
}
