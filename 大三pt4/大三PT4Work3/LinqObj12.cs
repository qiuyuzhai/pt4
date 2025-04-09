// File: "LinqObj12"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
/*����һ������ P��10 < P < 50������ʼ���а����������Ŀͻ�����Ϣ��
����ԭʼ�����е�ÿһ�꣬ȷ�����пͻ����ܳ���ʱ�䳬�������ܳ���ʱ�� P% ���·�������������·�����Ȼ�������ݣ���
    ���ĳ����κ��·ݶ�������Ҫ������� 0�� ÿһ�����ϢӦ����������������������ݼ����򣬶�����ͬ��������������������*/
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
                .Select(e => //��ÿһ�н��д��������ֳ��ַ�������
                {
                    var parts = e.Split();
                    return new
                    {
                        DurationHours = int.Parse(parts[0]), // ��1��Ԫ��ת��ΪDurationHours��ʱ����
                        ClientCode = int.Parse(parts[1]),   // ��2��Ԫ��ת��ΪClientCode���ͻ����룩
                        Month = int.Parse(parts[2]),        // ��3��Ԫ��ת��ΪMonth���·ݣ�
                        Year = int.Parse(parts[3])          // ��4��Ԫ��ת��ΪYear����ݣ�
                    };
                })
                .GroupBy(e => new { e.Year, e.Month })// ����Year��Month�ֶζ����ݽ��з���
                .Select(e =>
                     new
                     {
                         e.Key.Year,
                         e.Key.Month,
                         TotalDuration = e.Sum(c => c.DurationHours)
                     })
                .GroupBy(e => e.Year)                     // �ٴΰ���Year�ֶζ����ݽ��з���                
                .Select(e =>
                {
                    var totalYearDuration = e.Sum(c => c.TotalDuration);
                    var threshold = (p / 100.0) * totalYearDuration;
                    var monthsExceedingThreshold = e.Count(c => c.TotalDuration > threshold);
                    return $"{monthsExceedingThreshold} {e.Key}";
                
                })
                .OrderByDescending(e => e.Split()[0])// ���·����ݼ�����
                .ThenBy(e => e.Split()[1]);// ����ݵ�������

            // �����д���ļ�
            File.WriteAllLines(GetString(), res);
        }
    }
}

