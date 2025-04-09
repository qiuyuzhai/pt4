// File: "LinqObj42"
/*��ʼ���а����йؼ���վ������վ������Ϣ�������е�ÿ��Ԫ�ض����������ֶΣ�

<����Ʒ��> <��˾> <�ֵ�> <1�����ͼ۸񣨸�ȣ�>��

��˾�ͽֵ����Ʋ������ո����� 92��95 �� 98 ��ʾ�����ƺš�ÿ�ҹ�˾��ÿ���ֵ��ϵļ���վ������һ����ͬһ�ҹ�˾��ͬ����վ�ļ۸���ܲ�ͬ��
Ϊÿ���ֵ�ȷ����Ʒ�����͵���ͼ۸���������ֵ����ƣ�Ȼ������������� - 92��95 �� 98 �����͵���ͼ۸񣩡�
���û������Ʒ�Ƶ����ͣ���Ӧ��ʾ���� 0�� ÿ���ֵ�����ϢӦ��ʾ���µ�һ���У������ֵ����Ƶ���ĸ˳�����С�*/
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
            Task("LinqObj42");
            var res = File.ReadLines(GetString(), Encoding.Default)
                .Select(e => {
                    var s = e.Split(' ');
                    return new
                    {
                        Brand = int.Parse(s[0]),
                        Company = s[1],
                        Street = s[2],
                        Price = int.Parse(s[3])
                    };
                })
                .GroupBy(e => e.Street)
                .Select(g => new
                {
                    Street = g.Key,
                    Min92 = g.Where(x => x.Brand == 92).Select(x => x.Price).DefaultIfEmpty(0).Min(),
                    Min95 = g.Where(x => x.Brand == 95).Select(x => x.Price).DefaultIfEmpty(0).Min(),
                    Min98 = g.Where(x => x.Brand == 98).Select(x => x.Price).DefaultIfEmpty(0).Min()
                })
                .OrderBy(x => x.Street)
                .Select(x => $"{x.Street} {x.Min92} {x.Min95} {x.Min98}");

            File.WriteAllLines(GetString(), res.ToArray(), Encoding.Default);




        }
    }
}
