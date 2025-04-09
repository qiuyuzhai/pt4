// File: "LinqBegin52"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*给出了字符串序列A和B; 每个序列中的所有字符串都是不同的，具有非零长度并且仅包含拉丁字母的数字和大写字母。 
    获取形式"EA=EB"的所有可能组合的序列，其中EA是来自A的一些元素，EB是来自B的一些元素，并且两个元素都以数字结尾（例如，"AF3=D78"）。 
    以EA元素的字典序升序排列结果序列，对于相同的EA元素—以EB元素的字典序降序排列。*/
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve1()
        {
            Task("LinqBegin52");
            var a = GetEnumerableString()
.Where(e => char.IsDigit(e[e.Length - 1]))
.OrderBy(e => e).Show("A");
            var b = GetEnumerableString()
            .Where(e => char.IsDigit(e[e.Length - 1]))
            .OrderByDescending(e => e).Show("B");
            a.SelectMany(e1 => b.Select(e2 => e1 + "=" + e2)).Put();

        }
        public static void Solve()
        {
            Task("LinqBegin52");
            var a = GetEnumerableString().Where(e => char.IsDigit(e[e.Length - 1]));
            var b = GetEnumerableString().Where(e => char.IsDigit(e[e.Length - 1]));
            (from e1 in a
            from e2 in b
            orderby e1, e2 descending
            select e1 + "=" + e2).Put();
        }
    }
}
