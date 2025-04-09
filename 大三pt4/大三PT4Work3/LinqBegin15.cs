// File: "LinqBegin15"
using PT4;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//Given an integer, output its factorial
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

        public static void Solve()
        {
            Task("LinqBegin15");
            Put(Enumerable.Range(1, GetInt()).Aggregate(1.0, (a, e) => a * e));
            //ʹ��Enumerable.Range(1, GetInt())����һ����1��ʼ����Ȼ�����С�
           //ʹ��Aggregate()������������н����ۻ���������ʼֵΪ1.0��ÿ���ۻ������������е���һ������(��ʼֵָ�������е�һ������˵�����
           //���ۻ���������


        }
    }
    
}
