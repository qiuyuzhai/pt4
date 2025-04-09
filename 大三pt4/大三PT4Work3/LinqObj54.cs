// File: "LinqObj54"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics.CodeAnalysis;

/*��ʼ���а�����ѧ������ͼ������ѧ���Գɼ�����ָ��˳�򣩡����е�ÿ��Ԫ�ض����������ֶΣ�

<Scores> <School number> <Family name> <Initials>����������

������ 0 �� 100 ֮�������������֮����һ���ո������
Ϊÿ��ѧУ�ҳ���Уѧ���ֵܷ�ƽ��ֵ��ƽ��ֵΪ������������ѧ������֮�ͳ���ѧ�������Ľ������
ÿ��ѧУ����ϢӦ��ʾ�ڵ���һ���У�ע��ƽ���ֺܷ�ѧУ��š�
����Ӧ��ƽ���ֵݼ��������ƽ������ͬ����ѧУ��ŵ�������*/

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
