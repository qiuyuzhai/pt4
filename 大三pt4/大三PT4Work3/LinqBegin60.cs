// File: "LinqBegin60"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*�����˽�����������ĸ�Ĵ�д��ĸ�ķǿ��ַ���a�����С� 
������ͬһ����ĸ��ͷ�������У�ȷ�����ǵ��ܳ��Ȳ��õ�һ����ʽΪ"S-C"�������У�����S�Ǵ�A��ʼ����������ĸC��ͷ���е��ܳ��ȡ�*/
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin60");
            GetEnumerableString()
                .GroupBy(e => e[0])//�������е��ַ����������ǵĵ�һ���ַ����з��顣ÿ����ļ����ַ����ĵ�һ���ַ������ڰ�������������ַ���ͷ���ַ�����
                .OrderByDescending(e => e.Sum(s => s.Length))//����ÿ�����������ַ������ܳ���//�Է����Ľ���������������������ÿ�����������ַ������ܳ��ȣ����ս������С�
                .ThenBy(e => e.Key)//���ܳ�����ͬ������£�����ļ������ַ����ĵ�һ���ַ��������������С�
                .Select(e => e.Sum(s => s.Length) + "-" + e.Key).Put();//������������ÿ���������ͶӰ����ÿ���������Ϣת��Ϊһ���ַ�������ʽΪ "�ܳ���-��

        }
    }
}
