// File: "LinqObj80"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

/*���� D �� E ���������ֶΣ�
D��<�۸�¬����> <�̵�����> <��Ʒ��Ŀ
E: < ��Ʒ��Ŀ > < �̵����� > < �ͻ�����
���е������ڱ������Ӽ���������������
���� D ���г���ÿһ���̵�-��Ʒ��ȷ������Ʒ�ڸ��̵��������ֵ���������̵����ƣ�Ȼ������Ʒ��Ŀ��Ȼ����������ֵ����
�������Ʒ��δ��ĳ���̵���۹�������Ӧ�� "�̵�-��Ʒ "�Ե��ܼ�ֵΪ 0��
ÿ�� "�̵�-��Ʒ "����ϢӦ��ʾ���µ�һ���ϣ������̵����Ƶ���ĸ˳�����У���� ������ͬ������Ʒ���ࣨҲ����ĸ˳�����У����С�*/

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqObj80");
            var D = File.ReadLines(GetString(), Encoding.Default)
                .Select(e =>
                {
                    string []s = e.Split(' ');
                    return new
                    {
                        Price = int.Parse(s[0]),
                        ShopName = s[1],
                        Article = s[2]
                    };
                })
                .ToList();

            var E = File.ReadLines(GetString(), Encoding.Default)
                .Select(e =>
                {
                    string []s = e.Split(' ');
                    return new
                    {
                        Article = s[0],
                        ShopName = s[1],
                        ConsumerCode = s[2]
                    };
                })
                .ToList();

            var result = D.GroupJoin(
                E,
                d => new { d.Article, d.ShopName },
                e => new { e.Article, e.ShopName },
                (d, es) => new
                {
                    d.ShopName,
                    d.Article,
                    TotalSales = es.Count() * d.Price
                })
                .OrderBy(x => x.ShopName)
                .ThenBy(x => x.Article)
                .Select(x => $"{x.ShopName} {x.Article} {x.TotalSales}");

            File.WriteAllLines(GetString(), result.ToArray(), Encoding.Default);


        }
    }
}
