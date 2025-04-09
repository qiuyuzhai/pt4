// File: "LinqBegin60"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*给出了仅包含拉丁字母的大写字母的非空字符串a的序列。 
对于以同一个字母开头的所有行，确定它们的总长度并得到一个形式为"S-C"的行序列，其中S是从A开始的所有以字母C开头的行的总长度。*/
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin60");
            GetEnumerableString()
                .GroupBy(e => e[0])//将集合中的字符串按照它们的第一个字符进行分组。每个组的键是字符串的第一个字符，组内包含所有以这个字符开头的字符串。
                .OrderByDescending(e => e.Sum(s => s.Length))//计算每个组中所有字符串的总长度//对分组后的结果进行排序。排序的依据是每个组中所有字符串的总长度，按照降序排列。
                .ThenBy(e => e.Key)//在总长度相同的情况下，按组的键（即字符串的第一个字符）进行升序排列。
                .Select(e => e.Sum(s => s.Length) + "-" + e.Key).Put();//方法对排序后的每个分组进行投影。将每个分组的信息转换为一个字符串，格式为 "总长度-键

        }
    }
}
