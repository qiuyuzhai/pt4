// File: "LinqObj13"
/*��ʼ���а��������˵���Ϣ�����е�ÿ��Ԫ�ض����������ֶΣ�

<ѧУ���> <��ѧ���> <����>��

����Դ�����е�ÿһ�꣬�ڵ�����ѧ�������˱�ҵ��ѧУ���ҳ������ߵ�ѧУ���������ݺ��ҵ���ѧУ��š�ÿһ�����ϢӦ��ʾ�������У���������������С�*/
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
            Task("LinqObj13");
            var data =
            (from line in File.ReadLines(GetString())
             let parts = line.Split()
             select new
             {
                 SchoolId = int.Parse(parts[0]),       // ѧУ���
                 EnrollmentYear = int.Parse(parts[1]), // ��ѧ���
                 Name = parts[2]                       // ����
             }
            into x
             group x by x.EnrollmentYear              // ������ѧ��ݷ���
             into g
             orderby g.Key                           // �������������
             select $"{g.Key} {g.Max(e => e.SchoolId)}"); // ������ݺ��ҵ������ѧУ���

            // �����д���ļ�
            File.WriteAllLines(GetString(), data.ToArray());

        }



    }
    }

