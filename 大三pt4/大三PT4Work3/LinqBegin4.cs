// File: "LinqBegin4"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//�������ַ�C���ַ�������A�� ���A�������ַ�C��β�ĵ���Ԫ�أ��������Ԫ�أ����A��û�������У���������ַ���������ж�������У�������ַ���"Error"��
//ָʾ��ʹ��try�����ؿ��ܵ��쳣��

namespace PT4Tasks
{
    public class MyTask : PT
    {
        // When solving tasks of the LinqBegin group, the following
        // additional methods defined in the taskbook are available:
        // (*) GetEnumerableInt() - input of a numeric sequence;
        // (*) GetEnumerableString() - input of a string sequence;
        // (*) Put() (extension method) - output of a sequence;
        // (*) Show() and Show(cmt) (extension methods) - debug output
        //       of a sequence, cmt - string comment;
        // (*) Show(e => r) and Show(cmt, e => r) (extension methods) -
        //       debug output of r values, obtained from elements e
        //       of a sequence, cmt - string comment.

        public static void Solve1()
        {
            Task("LinqBegin4");
            char c = GetChar();
            var a = GetEnumerableString();//GetEnumerableString()������ȡһ����ö�ٵ��ַ���a��������ѭ������������
            try
            {
                string r = a.SingleOrDefault(e => e.Length != 0 &&e[e.Length - 1] == c);//SingleOrDefault()������LINQ��Language Integrated Query���е�һ����չ���������ڲ�ѯ�����ض������ĵ�һ��Ԫ�ء�����ҵ�������������Ԫ�أ��򷵻ظ�Ԫ�أ����򷵻�Ĭ��ֵ��
                Put(r != null ? r : "");
            }
            catch
            {
                Put("Error");
            }
        }
        public static void Solve()
        {
            Task("LinqBegin4");
            char c = GetChar();
            var a = GetEnumerableString();
            try
            {
                Put(a.Single(e => e.Length != 0 && e[e.Length - 1] == c));//Single()������SingleOrDefault()�������ƣ���֮ͬ������Single()����������Ҳ�������������Ԫ��ʱ���׳��쳣����SingleOrDefault()������᷵��Ĭ��ֵ��
            }
            catch (InvalidOperationException ex)//����InvalidOperationException�쳣
            {
                if (ex.Message.Contains("more"))//�쳣��Ϣ�а���"more"
                    Put("Error");
                else
                    Put("");
            }
        }

        public static void Solve2()
        {


            Task("LinqBegin4");
            char c = GetChar();
            var a = GetEnumerableString();
            try
            {
                Put(a.SingleOrDefault(e => e.Length != 0 && e[e.Length - 1] == c) ?? "");
            }
            catch
            {
                Put("Error");
            }
        }
       
    }
}
