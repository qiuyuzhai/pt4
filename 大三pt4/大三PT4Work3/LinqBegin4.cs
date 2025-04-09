// File: "LinqBegin4"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//给出了字符C和字符串序列A。 如果A包含以字符C结尾的单个元素，则输出此元素；如果A中没有所需行，则输出空字符串；如果有多个所需行，则输出字符串"Error"。
//指示：使用try块拦截可能的异常。

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

        public static void Solve1()
        {
            Task("LinqBegin4");
            char c = GetChar();
            var a = GetEnumerableString();//GetEnumerableString()函数获取一个可枚举的字符串a（即可用循环来返回它）
            try
            {
                string r = a.SingleOrDefault(e => e.Length != 0 &&e[e.Length - 1] == c);//SingleOrDefault()方法是LINQ（Language Integrated Query）中的一种扩展方法，用于查询满足特定条件的第一个元素。如果找到了满足条件的元素，则返回该元素；否则返回默认值。
                Put(r != null ? r : "");
            }
            catch
            {
                Put("Error");
            }
        }
        public static void Solve()
        {
            Task("LinqBegin4");
            char c = GetChar();
            var a = GetEnumerableString();
            try
            {
                Put(a.Single(e => e.Length != 0 && e[e.Length - 1] == c));//Single()方法和SingleOrDefault()方法类似，不同之处在于Single()方法如果在找不到满足条件的元素时会抛出异常，而SingleOrDefault()方法则会返回默认值。
            }
            catch (InvalidOperationException ex)//捕获到InvalidOperationException异常
            {
                if (ex.Message.Contains("more"))//异常信息中包含"more"
                    Put("Error");
                else
                    Put("");
            }
        }

        public static void Solve2()
        {


            Task("LinqBegin4");
            char c = GetChar();
            var a = GetEnumerableString();
            try
            {
                Put(a.SingleOrDefault(e => e.Length != 0 && e[e.Length - 1] == c) ?? "");
            }
            catch
            {
                Put("Error");
            }
        }
       
    }
}
