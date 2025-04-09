// File: "LinqObj54"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics.CodeAnalysis;

/*初始序列包含数学、俄语和计算机科学考试成绩（按指定顺序）。序列的每个元素都包括以下字段：

<Scores> <School number> <Family name> <Initials>（分数）。

分数是 0 到 100 之间的三个整数，之间用一个空格隔开。
为每所学校找出该校学生总分的平均值（平均值为整数，即所有学生分数之和除以学生人数的结果）。
每所学校的信息应显示在单独一行中，注明平均总分和学校编号。
数据应按平均分递减排序，如果平均分相同，则按学校编号递增排序。*/

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqObj54");
            var res = File.ReadLines(GetString(), Encoding.Default)
                .Select(e => {
                    var s = e.Split(' ');
                    return new
                    {
                        Math = int.Parse(s[0]),
                        Russian = int.Parse(s[1]),
                        Info = int.Parse(s[2]),
                        School= int.Parse(s[3]),
                        Last= s[4],
                        Initials = s[5]
                    };
                })
                .GroupBy(e => e.School)
                .Select(g => new
                {
                    School = g.Key,
                    mean = g.Sum(e => e.Math + e.Russian + e.Info) / g.Count()
                })
                .OrderByDescending(x => x.mean)
                .ThenBy(x => x.School)
                .Select(x => $"{x.mean} {x.School}");

            File.WriteAllLines(GetString(), res.ToArray(), Encoding.Default);


        }
    }
}
