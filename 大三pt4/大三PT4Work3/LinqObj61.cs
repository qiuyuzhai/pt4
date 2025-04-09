// File: "LinqObj61"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

/*��ʼ���а���ѧ���ڴ��������κ�����������Ŀ�еĳɼ���Ϣ�����е�ÿ��Ԫ�ض�����һ���꼶�����ݣ������������ֶΣ�

<����> <��������ĸ> <�༶> <��Ŀ����> <�꼶>��

ѧ����û��������������ͬ�����Ϻ�����ĸ�����༶Ϊ�������꼶Ϊ 2-5 ֮���������ѧ�������ô�д��ĸ��ʾ��
ȷ��ÿ��ѧ�����Ƶ�ƽ���ɼ�����������С��������������ѧ��û�����κο�Ŀ�л���κγɼ�����ÿ�Ŀ�ĳɼ����Ϊ 0.00����
�ڵ���һ�������ÿ��ѧ������Ϣ���������ϡ�������д�Լ����������κ������ƽ���ɼ���
����Ӧ�����Ϻ�����ĸ˳�����С�*/

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
