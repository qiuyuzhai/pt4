// File: "LinqObj61"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

/*初始序列包含学生在代数、几何和物理三个科目中的成绩信息。序列的每个元素都包含一个年级的数据，并包括以下字段：

<名字> <姓名首字母> <班级> <科目名称> <年级>。

学生中没有重名（具有相同的姓氏和首字母）。班级为整数，年级为 2-5 之间的整数。学科名称用大写字母表示。
确定每个学生各科的平均成绩，并用两个小数符号输出（如果学生没有在任何科目中获得任何成绩，则该科目的成绩输出为 0.00）。
在单独一行中输出每个学生的信息，包括姓氏、姓名缩写以及代数、几何和物理的平均成绩。
数据应按姓氏和首字母顺序排列。*/

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqObj61");
            string[] subjects = { "Algebra", "Geometry", "Physics" };
            var culture = new System.Globalization.CultureInfo("en-US");
            var r = File.ReadLines(GetString())
            .Select(e =>
            {
                string[] s = e.Split(' ');
                return new
                {
                    name = s[0] + " " + s[1],
                    subj = s[3],
                    mark = int.Parse(s[4])
                };
            })
            .GroupBy(e => e.name, (k, ee) => new
            {
                name = k,
                avrs = subjects
            .GroupJoin(ee, s => s, e => e.subj,
            (s1, ee1) => ee1.Select(e1 => e1.mark)
            .DefaultIfEmpty().Average())
            })
            .OrderBy(e => e.name)
            .Select(e => e.name + e.avrs.Aggregate("",
            (a, d) => $"{a} {d.ToString("f2", culture)}"));
            File.WriteAllLines(GetString(), r);




        }
    }
}
