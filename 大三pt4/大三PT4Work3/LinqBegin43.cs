// File: "LinqBegin43"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/*����һ������K(> 0)��һ���ǿ��ַ�������A.
�õ�һ���ַ����У��䶨�����£���������A��ǰK��Ԫ�أ����ַ�������λ�õ��ַ�(1��3����..�������뵽�µ������У�����a��ʣ��Ԫ�أ��ַ���ż��λ�ã�2��4������..�������롣 
�ڵõ��������У���תԪ�ص�˳��*/


namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin43");
            int k = GetInt();
            GetEnumerableString()
                .SelectMany((e,n)=>
                   e.Where((c, i) => i % 2 == (n < k ? 0 : 1)).Show())
            .Reverse().Put();

        }
    }
}
