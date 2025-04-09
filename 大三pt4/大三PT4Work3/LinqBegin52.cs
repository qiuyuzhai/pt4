// File: "LinqBegin52"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*�������ַ�������A��B; ÿ�������е������ַ������ǲ�ͬ�ģ����з��㳤�Ȳ��ҽ�����������ĸ�����ֺʹ�д��ĸ�� 
    ��ȡ��ʽ"EA=EB"�����п�����ϵ����У�����EA������A��һЩԪ�أ�EB������B��һЩԪ�أ���������Ԫ�ض������ֽ�β�����磬"AF3=D78"���� 
    ��EAԪ�ص��ֵ����������н�����У�������ͬ��EAԪ�ء���EBԪ�ص��ֵ��������С�*/
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve1()
        {
            Task("LinqBegin52");
            var a = GetEnumerableString()
.Where(e => char.IsDigit(e[e.Length - 1]))
.OrderBy(e => e).Show("A");
            var b = GetEnumerableString()
            .Where(e => char.IsDigit(e[e.Length - 1]))
            .OrderByDescending(e => e).Show("B");
            a.SelectMany(e1 => b.Select(e2 => e1 + "=" + e2)).Put();

        }
        public static void Solve()
        {
            Task("LinqBegin52");
            var a = GetEnumerableString().Where(e => char.IsDigit(e[e.Length - 1]));
            var b = GetEnumerableString().Where(e => char.IsDigit(e[e.Length - 1]));
            (from e1 in a
            from e2 in b
            orderby e1, e2 descending
            select e1 + "=" + e2).Put();
        }
    }
}
