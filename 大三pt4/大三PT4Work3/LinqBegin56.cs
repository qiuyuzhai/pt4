// File: "LinqBegin56"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*��������������A�� ������a��Ԫ������ͬ�����ֽ�β���飬�����ݸ÷��飬�õ�һ����ʽΪ"D��S"���ַ������У�����D�Ƿ������������A������һ�����ֽ�β��ĳ�����֣���
    S�Ǵ�A��������D��β���������ֵ��ܺ͡�
 ʹ��GroupBy������*/
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin56");
            GetEnumerableInt()
               .GroupBy(e => Math.Abs(e) % 10)
               .OrderBy(g => g.Key)
               .Select(g => g.Key + ":" + g.Sum())
               .Put();




        }
    }
}
