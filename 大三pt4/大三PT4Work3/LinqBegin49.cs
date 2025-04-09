// File: "LinqBegin49"
/*�����ַ������� A��B �� C��ÿ�������е������ַ������ǲ�ͬ�ģ����ȷ��㣬����ֻ�������ֺ�������ĸ�Ĵ�д��ĸ��
�ҵ� A��B �� C �����������ӣ�����һ����ĸ��ͬ��������ÿ����Ԫ��Ӧ�ð�������ͬ�ַ���ͷ���ַ�����
���ҵ������ӱ�ʾΪ��ʽΪ "EA=EB=EC" ���ַ������У����� EA��EB��EC �ֱ��� A��B��C �е�Ԫ�ء�
���ڲ�ͬ�� EA Ԫ�أ�������ԭʼ˳�򣻶�����ͬ�� EA Ԫ�أ���Ԫ���˳����� EB Ԫ�ص��ֵ�˳���������У���������ͬ�� EA �� EB Ԫ�أ���Ԫ���˳����� EC Ԫ�ص��ֵ�˳�򣨽������С�*/
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin49");
            var a = GetEnumerableString().Where(e => e.Length > 0); // ����������� A ����
            var b = GetEnumerableString().Where(e => e.Length > 0).OrderBy(e => e).Show("b"); 
            var c = GetEnumerableString().Where(e => e.Length > 0).OrderByDescending(e => e).Show("c"); // ����������� C ����
            (from e1 in a
             from e2 in b
             from e3 in c
             where e1[0] == e2[0] && e2[0] == e3[0]
             select e1 + "=" + e2 + "=" + e3).Put();




        }
    }
}
