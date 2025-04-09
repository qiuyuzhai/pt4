// File: "LinqObj13"
/*初始序列包含申请人的信息。序列的每个元素都包括以下字段：

<学校编号> <入学年份> <姓名>。

对于源数据中的每一年，在当年入学的申请人毕业的学校中找出编号最高的学校，并输出年份和找到的学校编号。每一年的信息应显示在新行中，并按年号升序排列。*/
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
        public static void Solve()
        {
            Task("LinqObj13");
            var data =
            (from line in File.ReadLines(GetString())
             let parts = line.Split()
             select new
             {
                 SchoolId = int.Parse(parts[0]),       // 学校编号
                 EnrollmentYear = int.Parse(parts[1]), // 入学年份
                 Name = parts[2]                       // 姓名
             }
            into x
             group x by x.EnrollmentYear              // 按照入学年份分组
             into g
             orderby g.Key                           // 按年份升序排列
             select $"{g.Key} {g.Max(e => e.SchoolId)}"); // 返回年份和找到的最高学校编号

            // 将结果写入文件
            File.WriteAllLines(GetString(), data.ToArray());

        }



    }
    }

