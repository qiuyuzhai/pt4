// File: "LinqBegin31"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*Given an integer K (> 0) and a sequence of non-empty strings A.
The sequence lines contain only numbers and capital letters of the Latin alphabet. Find the set-theoretic intersection of two fragments A: 
the first contains K initial elements, and the second contains all the elements located after the last element ending in a digit. 
The resulting sequence (which does not contain the same elements) should be sorted in ascending order of string lengths, and strings of the same length should be sorted in lexicographic ascending order.

 */
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin31");
            int k = GetInt();
            var a = GetEnumerableString();
            a.Take(k).Show("B")// a 中取前 k 个元素，显示为 "B"。
            .Intersect(a.Reverse()//先将a反转
            .TakeWhile(e => !char.IsDigit(e[e.Length - 1]))//从反转后的序列 a 中选取不以数字结尾的元素。这里使用了 TakeWhile 方法，它会一直选取满足条件的元素，直到遇到一个不满足条件的元素。
            .Show("C"))//将筛选出的元素显示为 "C"
            .Show("D")//D是B和C的交集（用Intersect）
            .OrderBy(e => e.Length).ThenBy(e => e)//根据元素的长度对结果进行排序，如果长度相同，则按照元素的自然顺序进行排序。
            .Put();

/*获取一个整数 k 和一个字符串集合 a。
显示集合 a 的前 k 个元素（标签 "B"）。
取集合 a 的倒序集合中，最后一个字符不是数字的元素，并显示（标签 "C"）。
取步骤 2 和步骤 3 结果的交集，并显示（标签 "D"）。
对交集结果按长度和字典顺序排序。
输出排序后的结果*/
        }
    }
}

/*.Intersect(a.Reverse()
取集合 a 中的前 k 个元素和 a 的倒序集合之间的交集。

.TakeWhile(e => !char.IsDigit(e[e.Length - 1]))
从倒序集合中取元素，直到元素的最后一个字符不是数字为止。

.OrderBy(e => e.Length).ThenBy(e => e)
先按字符串长度排序，再按字典顺序排序。*/