// File: "LinqBegin37"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/*�����ַ������� A�������е��ַ���ֻ����������ĸ�Ĵ�д��ĸ��
���һ���µ��ַ������У����е�Ԫ�ظ������� A �е���ӦԪ��ȷ�������ַ������������������У����ǿ��ַ����򸽼��ϸ��ַ�����ԭʼ�����е����
���磬������� A �ĵ����Ԫ���� "ABC"����ô�ڵõ��������������� "ABC5"�������ʱӦ�������� A �еĿ��ַ��������õ������а���ĸ˳����������*/
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin37");
            var a = GetEnumerableString();
            a.Select((str, index) => new { str, index })//��ÿ���ַ�������������ԣ�����һ�������������У������������ str���ַ������� index��������
             .Where(item => !string.IsNullOrEmpty(item.str))//���˵����ַ���
             .Select(item => $"{item.str}{item.index + 1}")//���ǿ��ַ���������ԭʼ�����е������������������µ��ַ�������Ŵ�1��ʼ��
             .OrderBy(item => item)
             .Put();

        }
    }
}
/*Select ������ÿ���ַ�������������ԣ�����һ��������������
Where �������˵����ַ���
Select �������ǿ��ַ���������ԭʼ�����е������������������µ��ַ���
OrderBy ��������ĸ˳����µ��ַ������н�������
ToList �� ForEach �������������ַ����������������̨*/