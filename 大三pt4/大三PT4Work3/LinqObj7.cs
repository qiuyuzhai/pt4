// File: "LinqObj7"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

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
            Task("LinqObj7");
            int K = GetInt();
            var s = File.ReadLines(GetString());

            // 处理每一行数据，将其拆分成对象
            var data = s.Select(line =>
            {
                var parts = line.Split();
                return new
                {
                    duration = int.Parse(parts[0]),  // 第一个元素转换为小时数
                    year = int.Parse(parts[1]),      // 第二个元素转换为年份
                    month = int.Parse(parts[2]),     // 第三个元素转换为月份
                    clientCode = int.Parse(parts[3]) // 第四个元素转换为客户代码
                };
            });

            // 指定的客户代码

            // 过滤出客户代码为K的数据
            var clientData = data.Where(d => d.clientCode == K);

            // 如果没有数据，写入 "No data"
            if (!clientData.Any())
            {
                File.WriteAllLines(GetString(), new[] { "No data" });
                return;
            }

            // 根据年份进行分组
            var groupedData = clientData.GroupBy(d => d.year)
                .Select(g => new
                {
                    year = g.Key,
                    monthData = g.GroupBy(m => m.month)
                                  .Select(mg => new { month = mg.Key, totalDuration = mg.Sum(m => m.duration) })
                                  .OrderByDescending(m => m.totalDuration)
                                  .ThenBy(m => m.month)
                                  .First()
                })
                .OrderByDescending(g => g.year);

            // 格式化输出结果
            var result = groupedData.Select(g => $"{g.year} {g.monthData.month} {g.monthData.totalDuration}");

            // 将处理后的结果写入到文件中
            File.WriteAllLines(GetString(), result);



        }
    }
}

