// File: "LinqBegin7"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//An integer sequence is given. Find the number of its negative elements, as well as their sum. If there are no negative elements, then print 0 twice.
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
            Task("LinqBegin7");
            var a = GetEnumerableInt();//注意是int这个类型//返回一个整数类型的可枚举对象（数组，列表等）
            int n = 0;
            int sum = 0;
            n = a.Count(e => e < 0);
            sum=a.Where(e => e < 0).Sum();
            Put(n);
            Put(sum);

            


        }
    }
}
