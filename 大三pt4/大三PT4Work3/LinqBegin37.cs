// File: "LinqBegin37"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/*给定字符串序列 A。序列中的字符串只包含拉丁字母的大写字母。
获得一个新的字符串序列，其中的元素根据序列 A 中的相应元素确定：空字符串不包括在新序列中，而非空字符串则附加上该字符串在原始序列中的序号
例如，如果序列 A 的第五个元素是 "ABC"，那么在得到的序列中它将是 "ABC5"）。编号时应考虑序列 A 中的空字符串。将得到的序列按字母顺序升序排序。*/
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin37");
            var a = GetEnumerableString();
            a.Select((str, index) => new { str, index })//将每个字符串与其索引配对，生成一个匿名对象序列，匿名对象包含 str（字符串）和 index（索引）
             .Where(item => !string.IsNullOrEmpty(item.str))//过滤掉空字符串
             .Select(item => $"{item.str}{item.index + 1}")//将非空字符串与其在原始序列中的序号组合起来，生成新的字符串，序号从1开始。
             .OrderBy(item => item)
             .Put();

        }
    }
}
/*Select 方法将每个字符串与其索引配对，生成一个匿名对象序列
Where 方法过滤掉空字符串
Select 方法将非空字符串与其在原始序列中的序号组合起来，生成新的字符串
OrderBy 方法按字母顺序对新的字符串序列进行排序
ToList 和 ForEach 方法将排序后的字符串序列输出到控制台*/