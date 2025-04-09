// File: "LinqObj41"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
/*���� M ��һ������Ʒ�Ƶ�ֵ����ʼ���а�������վ������վ������Ϣ�������е�ÿ��Ԫ�ض����������ֶΣ�

<���͵ȼ�> <�ֵ�> <��˾> <ÿ���۸񣨸�ȣ�>��

��˾�ͽֵ����Ʋ������ո����� 92��95 �� 98 ��ʾ���͵ȼ���ÿ�ҹ�˾��ÿ���ֵ��ϵļ���վ������һ����
ͬһ�ҹ�˾��ͬ����վ�ļ۸���ܲ�ͬ��
��ÿ���ֵ����� M �����ͼ���վ�ĵط���ȷ����Ʒ�����͵���߼۸��������߼� ��������ֵ����ƣ���
ÿ���ֵ�����Ϣ��Ӧ��ʾ���µ�һ���ϣ�������߼۸�ĵ���˳�����У�������ͬ�۸����Ϣ���򰴽ֵ����Ƶ���ĸ˳�����С����û���ҵ��ṩ M �����͵ļ���վ���������ɵ��ļ���д�� "�� "һ�С�*/


namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqObj41");
            int m = GetInt();
            var r =
            (from e in File.ReadLines(GetString(), Encoding.Default)
             let s = e.Split(' ')
             select new
             {
                 brand = int.Parse(s[0]),
                 street = s[1],
                 price = int.Parse(s[3])
             }
            into e//ɸѡ��ָ��Ʒ������ļ�¼��
             where e.brand == m
             group e.price by e.street//���ֵ����鲢�ҳ�ÿ���ֵ��۸���ߵļ�¼��
            into e
             let max = e.Max()
             orderby max, e.Key//����
             select max + " " + e.Key)
            .DefaultIfEmpty("���֧�");
            File.WriteAllLines(GetString(), r.ToArray(), Encoding.Default);


        }
    }
}
