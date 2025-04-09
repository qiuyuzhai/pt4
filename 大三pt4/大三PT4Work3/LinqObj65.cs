// File: "LinqObj65"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
/*�ַ��� S �Ǵ��������λ�����������Ŀ������֮һ����ʼ���а���ѧ������������Ŀ�еĳɼ���Ϣ�����е�ÿ��Ԫ�ض�����һ���꼶�����ݣ������������ֶΣ�
<First name> <Initials> <Subject name> <Grade> <Class>.
ѧ����û��������������ͬ�����Ϻ�����ĸ�����༶Ϊ�������꼶Ϊ 2-5 ֮���������
ѧ�������ô�д��ĸ��ʾ�����ڳ�ʼ���ݼ��е�ÿ���༶��ȷ�� S ��ƽ���ɼ��� 3.5 �����»�ÿ�û�гɼ���ѧ��������
�ڵ���һ�������ÿ���༶��ע���ҵ���ѧ����������������Ϊ 0���Ͱ༶��š�����Ӧ��ѧ�������������У��������ƥ�䣬�򰴰༶��Ž������С�*/
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
