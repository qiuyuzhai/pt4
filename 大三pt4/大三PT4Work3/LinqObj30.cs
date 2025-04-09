// File: "LinqObj30"
/*��ʼ���а�����ס��һ�� 9 ��¥ 144 ����Ԣ�Ĺ�����ҵծ���˵���Ϣ��
< ����> < ծ��> < Ƿ��> < ��Ԣ���>��
ծ����С����ʾ���������� - ¬����С������ - ��ȣ���ÿ����ڵ�ÿ���� 4 ����Ԫ��
���ⶰ¥�� 9 ��¥�У��ҳ�ծ����͵��⻧��������������Ϣ����Ԫ�š�¥��š��⻧���ϡ�ծ���������С�����ţ���
���ǵ���ʼ���ݼ��е�����ծ���в�ͬ��ֵ��ÿ��ծ���˵���Ϣ��Ӧ��ʾ�ڵ���һ���У�������Ԫ�ŵ����������ĳ��û��ծ���ˣ���Ӧ����ò�����ݡ�*/

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
            Task("LinqObj30");
            var r =
            (from line in File.ReadLines(GetString(), Encoding.Default)
             let parts = line.Split()
             select new
             {
                 LastName = parts[0],                     // ����
                 Debt = decimal.Parse(parts[1]),          // ծ��¬���͸�ȣ�
                 ApartmentNumber = int.Parse(parts[2])    // ��Ԣ���
             }
            into x
             group x by (x.ApartmentNumber - 1) % 36 / 4 + 1 into g   // ����¥��ŷ��飬ÿ���� 4 ����Ԣ��ÿ������� 36 ����Ԣ
             let minDebtTenant = g.OrderBy(x => x.Debt).First()       // �ҳ�ÿ����ծ����͵��⻧
             orderby minDebtTenant.ApartmentNumber                    // ����Ԣ�����������
             select $"{minDebtTenant.ApartmentNumber} {g.Key} {minDebtTenant.LastName} {minDebtTenant.Debt:F2}")
            .DefaultIfEmpty("���֧�");

            // �����д���ļ�
            File.WriteAllLines(GetString(), r.ToArray(), Encoding.Default);

        }
    }
    }

