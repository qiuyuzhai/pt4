// File: "LinqBegin39"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/*�����ַ������� A��
  ��ȡһ���µ������ַ����У��������е��ַ��Ǵ��ַ������� A ����ȡ�ģ��ַ������ظ����֣���
    �ַ���˳��Ӧ���ַ��� A ��˳���Լ�ÿ���ַ������ַ���˳��һ�¡�*/
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin39");
            var A = GetEnumerableString();
            A.SelectMany(str => str.Where(char.IsDigit))
             .Put();
        }
    }
}
