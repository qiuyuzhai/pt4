// File: "LinqObj65"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
/*字符串 S 是代数、几何或物理三个科目的名称之一。初始序列包含学生在这三个科目中的成绩信息。序列的每个元素都包含一个年级的数据，并包括以下字段：
<First name> <Initials> <Subject name> <Grade> <Class>.
学生中没有重名（具有相同的姓氏和首字母）。班级为整数，年级为 2-5 之间的整数。
学科名称用大写字母表示。对于初始数据集中的每个班级，确定 S 科平均成绩在 3.5 或以下或该科没有成绩的学生人数。
在单独一行中输出每个班级，注明找到的学生人数（人数可以为 0）和班级编号。数据应按学生人数升序排列，如果数字匹配，则按班级编号降序排列。*/
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqObj65");
            string subjectName = GetString();

            var res = File.ReadLines(GetString(), Encoding.Default)
                .Select(e =>
                {
                    string[] s = e.Split(' ');
                    return new
                    {
                        LastName = s[0],
                        Initials = s[1],
                        Subject = s[2],
                        Grade = int.Parse(s[3]),
                        Class = int.Parse(s[4])
                    };
                })
                .GroupBy(e => e.Class)
                .Select(g =>
                {
                    var studentsCount = g.GroupBy(s => s.LastName + " " + s.Initials)
                                         .Count(student =>
                                         {
                                             var subjectGrades = student.Where(s => s.Subject == subjectName).Select(s => s.Grade);
                                             return !subjectGrades.Any() || subjectGrades.Average() <= 3.5;
                                         });

                    return new
                    {
                        Class = g.Key,
                        StudentsCount = studentsCount
                    };
                })
                .OrderBy(x => x.StudentsCount)
                .ThenByDescending(x => x.Class)
                .Select(x => $"{x.StudentsCount} {x.Class}");

            File.WriteAllLines(GetString(), res.ToArray(), Encoding.Default);




        }
    }
}
