// File: "LinqBegin49"
/*给定字符串序列 A、B 和 C；每个序列中的所有字符串都是不同的，长度非零，并且只包含数字和拉丁字母的大写字母。
找到 A、B 和 C 的所有内连接（即第一个字母相同），其中每个三元组应该包含以相同字符开头的字符串。
将找到的连接表示为形式为 "EA=EB=EC" 的字符串序列，其中 EA、EB、EC 分别是 A、B、C 中的元素。
对于不同的 EA 元素，保持其原始顺序；对于相同的 EA 元素，三元组的顺序根据 EB 元素的字典顺序（升序）排列，而对于相同的 EA 和 EB 元素，三元组的顺序根据 EC 元素的字典顺序（降序）排列。*/
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin49");
            var a = GetEnumerableString().Where(e => e.Length > 0); // 假设这个返回 A 序列
            var b = GetEnumerableString().Where(e => e.Length > 0).OrderBy(e => e).Show("b"); 
            var c = GetEnumerableString().Where(e => e.Length > 0).OrderByDescending(e => e).Show("c"); // 假设这个返回 C 序列
            (from e1 in a
             from e2 in b
             from e3 in c
             where e1[0] == e2[0] && e2[0] == e3[0]
             select e1 + "=" + e2 + "=" + e3).Put();




        }
    }
}
