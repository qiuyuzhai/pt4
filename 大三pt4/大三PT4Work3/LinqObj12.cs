// File: "LinqObj12"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
/*给定一个整数 P（10 < P < 50）。初始序列包含健身中心客户的信息：
对于原始数据中的每一年，确定所有客户的总持续时间超过当年总持续时间 P% 的月份数（首先输出月份数，然后输出年份）。
    如果某年的任何月份都不符合要求，则输出 0。 每一年的信息应在新行中输出，并按月数递减排序，对于相同月数，则按年数递增排序。*/
namespace PT4Tasks
{
    public class MyTask : PT
    {
        // To read strings from the source text file into
        // a string sequence (or array) s, use the statement:
        //   s = File.ReadLines(GetString());
        // To write the sequence s of IEnumerable<string> type
        // into the resulting text file, use the statement:
        //   File.WriteAllLines(GetString(), s);
        // When solving tasks of the LinqObj group, the following
        // additional methods defined in the taskbook are available:
        // (*) Show() and Show(cmt) (extension methods) - debug output
        //       of a sequence, cmt - string comment;
        // (*) Show(e => r) and Show(cmt, e => r) (extension methods) -
        //       debug output of r values, obtained from elements e
        //       of a sequence, cmt - string comment.

        public static void Solve()
        {
            Task("LinqObj12");
            int p = GetInt();
            var res = File.ReadLines(GetString(), Encoding.Default)
                .Select(e => //对每一行进行处理，将其拆分成字符串数组
                {
                    var parts = e.Split();
                    return new
                    {
                        DurationHours = int.Parse(parts[0]), // 第1个元素转换为DurationHours（时长）
                        ClientCode = int.Parse(parts[1]),   // 第2个元素转换为ClientCode（客户代码）
                        Month = int.Parse(parts[2]),        // 第3个元素转换为Month（月份）
                        Year = int.Parse(parts[3])          // 第4个元素转换为Year（年份）
                    };
                })
                .GroupBy(e => new { e.Year, e.Month })// 根据Year和Month字段对数据进行分组
                .Select(e =>
                     new
                     {
                         e.Key.Year,
                         e.Key.Month,
                         TotalDuration = e.Sum(c => c.DurationHours)
                     })
                .GroupBy(e => e.Year)                     // 再次按照Year字段对数据进行分组                
                .Select(e =>
                {
                    var totalYearDuration = e.Sum(c => c.TotalDuration);
                    var threshold = (p / 100.0) * totalYearDuration;
                    var monthsExceedingThreshold = e.Count(c => c.TotalDuration > threshold);
                    return $"{monthsExceedingThreshold} {e.Key}";
                
                })
                .OrderByDescending(e => e.Split()[0])// 按月份数递减排序
                .ThenBy(e => e.Split()[1]);// 按年份递增排序

            // 将结果写入文件
            File.WriteAllLines(GetString(), res);
        }
    }
}

