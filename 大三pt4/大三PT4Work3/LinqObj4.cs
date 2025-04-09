// File: "LinqObj4"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
/*初始序列包含有关健身中心客户的信息:
< 年 >< 月号 >< 上课时间(小时) >< 客户代码 >
对于源数据中存在的每个客户端，确定所有年份的类的总持续时间(即跨越年份） （首先输出总持续时间，然后输出客户端代码）。 
有关每个客户端的信息应显示在新行上，并按总持续时间的降序排列，如果它们相等，则按客户端代码的升序排列。*/
namespace PT4Tasks
{
    public class MyTask : PT
    {
        // To read strings from the source text file into要将源文本文件中的字符串读入字符串序列（或数组）s，请使用以下语句：s = File.ReadLines(GetString())；
        // a string sequence (or array) s, use the statement:将 IEnumerable<string> 类型的序列 s // 写入生成的文本文件，请使用语句：File.WriteAllLines(GetString(), s)；
        //   s = File.ReadLines(GetString());
        // To write the sequence s of IEnumerable<string> type
        // into the resulting text file, use the statement:
        //   File.WriteAllLines(GetString(), s);
        // When solving tasks of the LinqObj group, the following
        // additional methods defined in the taskbook are available:   (
        // (*) Show() and Show(cmt) (extension methods) - debug output of a sequence, cmt - string comment;
        // (*) Show(e => r) and Show(cmt, e => r) (extension methods)  - // debug output of r values.
        // debug output of r values, obtained from elements e
        // of a sequence, cmt - string comment.

        /*public static void Solve()
        {
            Task("LinqObj4");
            File.ReadLines(GetString(), Encoding.Default)
                .Select(e => hours: int.Parse(e.Split()[2]),
                    code: int.Parse(e.Split()[3])
                ))
                .Show();
        }*/
        public static void Solve()
        {
            Task("LinqObj4");
            var res = File.ReadLines(GetString(), Encoding.Default)//逐行读取内容,每行内容为一个字符串
                .Select(e => new//对每一行进行处理，将其拆分成字符串数组
                {
                    hours = int.Parse(e.Split()[2]),//例如第3个元素转换为hours（小时数）
                    code = int.Parse(e.Split()[3])
                })
                .GroupBy(e => e.code)//根据code字段对数据进行分组
                .OrderByDescending(e => e.Sum(c => c.hours))// 按每个分组内hours字段的总和降序排序
                .ThenBy(e => e.Key)//在总和相等的情况下，按code的值升序排序(这个Key是分组键的意思）
                .Select(e => e.Sum(c => c.hours) + " " + e.Key)//将每个分组的总小时数和code组合成一个字符串。
                .Show();
            File.WriteAllLines(GetString(), res);//将处理后的结果res写入到文件中
        }
    }
}

