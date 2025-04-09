// File: "LinqBegin31"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*Given an integer K (> 0) and a sequence of non-empty strings A.
The sequence lines contain only numbers and capital letters of the Latin alphabet. Find the set-theoretic intersection of two fragments A: 
the first contains K initial elements, and the second contains all the elements located after the last element ending in a digit. 
The resulting sequence (which does not contain the same elements) should be sorted in ascending order of string lengths, and strings of the same length should be sorted in lexicographic ascending order.

 */
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin31");
            int k = GetInt();
            var a = GetEnumerableString();
            a.Take(k).Show("B")// a ��ȡǰ k ��Ԫ�أ���ʾΪ "B"��
            .Intersect(a.Reverse()//�Ƚ�a��ת
            .TakeWhile(e => !char.IsDigit(e[e.Length - 1]))//�ӷ�ת������� a ��ѡȡ�������ֽ�β��Ԫ�ء�����ʹ���� TakeWhile ����������һֱѡȡ����������Ԫ�أ�ֱ������һ��������������Ԫ�ء�
            .Show("C"))//��ɸѡ����Ԫ����ʾΪ "C"
            .Show("D")//D��B��C�Ľ�������Intersect��
            .OrderBy(e => e.Length).ThenBy(e => e)//����Ԫ�صĳ��ȶԽ�������������������ͬ������Ԫ�ص���Ȼ˳���������
            .Put();

/*��ȡһ������ k ��һ���ַ������� a��
��ʾ���� a ��ǰ k ��Ԫ�أ���ǩ "B"����
ȡ���� a �ĵ��򼯺��У����һ���ַ��������ֵ�Ԫ�أ�����ʾ����ǩ "C"����
ȡ���� 2 �Ͳ��� 3 ����Ľ���������ʾ����ǩ "D"����
�Խ�����������Ⱥ��ֵ�˳������
��������Ľ��*/
        }
    }
}

/*.Intersect(a.Reverse()
ȡ���� a �е�ǰ k ��Ԫ�غ� a �ĵ��򼯺�֮��Ľ�����

.TakeWhile(e => !char.IsDigit(e[e.Length - 1]))
�ӵ��򼯺���ȡԪ�أ�ֱ��Ԫ�ص����һ���ַ���������Ϊֹ��

.OrderBy(e => e.Length).ThenBy(e => e)
�Ȱ��ַ������������ٰ��ֵ�˳������*/