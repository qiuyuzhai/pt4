// File: "LinqBegin39"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/*给定字符串序列 A。
  获取一个新的数字字符序列，该序列中的字符是从字符串序列 A 中提取的（字符可以重复出现）。
    字符的顺序应与字符串 A 的顺序以及每个字符串中字符的顺序一致。*/
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin39");
            var A = GetEnumerableString();
            A.SelectMany(str => str.Where(char.IsDigit))
             .Put();
        }
    }
}
