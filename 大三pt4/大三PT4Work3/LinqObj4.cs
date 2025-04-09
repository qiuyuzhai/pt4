// File: "LinqObj4"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
/*��ʼ���а����йؽ������Ŀͻ�����Ϣ:
< �� >< �º� >< �Ͽ�ʱ��(Сʱ) >< �ͻ����� >
����Դ�����д��ڵ�ÿ���ͻ��ˣ�ȷ��������ݵ�����ܳ���ʱ��(����Խ��ݣ� ����������ܳ���ʱ�䣬Ȼ������ͻ��˴��룩�� 
�й�ÿ���ͻ��˵���ϢӦ��ʾ�������ϣ������ܳ���ʱ��Ľ������У����������ȣ��򰴿ͻ��˴�����������С�*/
namespace PT4Tasks
{
    public class MyTask : PT
    {
        // To read strings from the source text file intoҪ��Դ�ı��ļ��е��ַ��������ַ������У������飩s����ʹ��������䣺s = File.ReadLines(GetString())��
        // a string sequence (or array) s, use the statement:�� IEnumerable<string> ���͵����� s // д�����ɵ��ı��ļ�����ʹ����䣺File.WriteAllLines(GetString(), s)��
        //   s = File.ReadLines(GetString());
        // To write the sequence s of IEnumerable<string> type
        // into the resulting text file, use the statement:
        //   File.WriteAllLines(GetString(), s);
        // When solving tasks of the LinqObj group, the following
        // additional methods defined in the taskbook are available:   (
        // (*) Show() and Show(cmt) (extension methods) - debug output of a sequence, cmt - string comment;
        // (*) Show(e => r) and Show(cmt, e => r) (extension methods)  - // debug output of r values.
        // debug output of r values, obtained from elements e
        // of a sequence, cmt - string comment.

        /*public static void Solve()
        {
            Task("LinqObj4");
            File.ReadLines(GetString(), Encoding.Default)
                .Select(e => hours: int.Parse(e.Split()[2]),
                    code: int.Parse(e.Split()[3])
                ))
                .Show();
        }*/
        public static void Solve()
        {
            Task("LinqObj4");
            var res = File.ReadLines(GetString(), Encoding.Default)//���ж�ȡ����,ÿ������Ϊһ���ַ���
                .Select(e => new//��ÿһ�н��д��������ֳ��ַ�������
                {
                    hours = int.Parse(e.Split()[2]),//�����3��Ԫ��ת��Ϊhours��Сʱ����
                    code = int.Parse(e.Split()[3])
                })
                .GroupBy(e => e.code)//����code�ֶζ����ݽ��з���
                .OrderByDescending(e => e.Sum(c => c.hours))// ��ÿ��������hours�ֶε��ܺͽ�������
                .ThenBy(e => e.Key)//���ܺ���ȵ�����£���code��ֵ��������(���Key�Ƿ��������˼��
                .Select(e => e.Sum(c => c.hours) + " " + e.Key)//��ÿ���������Сʱ����code��ϳ�һ���ַ�����
                .Show();
            File.WriteAllLines(GetString(), res);//�������Ľ��resд�뵽�ļ���
        }
    }
}

