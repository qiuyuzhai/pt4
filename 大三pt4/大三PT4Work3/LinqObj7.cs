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

            // ����ÿһ�����ݣ������ֳɶ���
            var data = s.Select(line =>
            {
                var parts = line.Split();
                return new
                {
                    duration = int.Parse(parts[0]),  // ��һ��Ԫ��ת��ΪСʱ��
                    year = int.Parse(parts[1]),      // �ڶ���Ԫ��ת��Ϊ���
                    month = int.Parse(parts[2]),     // ������Ԫ��ת��Ϊ�·�
                    clientCode = int.Parse(parts[3]) // ���ĸ�Ԫ��ת��Ϊ�ͻ�����
                };
            });

            // ָ���Ŀͻ�����

            // ���˳��ͻ�����ΪK������
            var clientData = data.Where(d => d.clientCode == K);

            // ���û�����ݣ�д�� "No data"
            if (!clientData.Any())
            {
                File.WriteAllLines(GetString(), new[] { "No data" });
                return;
            }

            // ������ݽ��з���
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

            // ��ʽ��������
            var result = groupedData.Select(g => $"{g.year} {g.monthData.month} {g.monthData.totalDuration}");

            // �������Ľ��д�뵽�ļ���
            File.WriteAllLines(GetString(), result);



        }
    }
}

