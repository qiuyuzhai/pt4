// File: "OOP3Behav15"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*
����
ʵ���������νṹ���ֱ���Ԫ�����νṹ�ͷ��������νṹ��

Ԫ�����νṹ��

1.������ Element��

����һ�����󷽷� Accept(Visitor v)�������ؽ����
������ ConcreteElementA, ConcreteElementB, ConcreteElementC��

ÿ�������඼��һ��data�ֶΣ�
ConcreteElementA������
ConcreteElementB���ַ���
ConcreteElementC��������
�ڹ��캯���г�ʼ��data�ֶΡ�
ʵ��Accept(Visitor v)���������÷������еĶ�ӦVisit������
����GetData��SetData���������ڷ��ʺ��޸�data�ֶΡ�


2.ObjectStructure���ͣ�

����һ��struc�ֶΣ�����һ�����飩����Ԫ��ΪElement���͵Ķ���
���캯���ò�����ʼ��struc�ֶΡ�
����Accept(Visitor v)����������struc�е�Ԫ�ز��������ǵ�Accept������
���������νṹ��

3.������ Visitor��

�����������󷽷���
VisitConcreteElementA(ConcreteElementA e)
VisitConcreteElementB(ConcreteElementB e)
VisitConcreteElementC(ConcreteElementC e)
������ ConcreteVisitor1, ConcreteVisitor2, ConcreteVisitor3��

ConcreteVisitor1�����Ԫ�ص�data�ֶΡ�
ConcreteVisitor2��ת��Ԫ�ص�data�ֶΣ�
����ConcreteElementA��ȡ������
����ConcreteElementB����ת�ַ���
����ConcreteElementC��ȡ������1/data��
ConcreteVisitor3����������ͬ����Ԫ�ص��ۺ�������
����ConcreteElementA�����������ֶ�data���ܺ�
����ConcreteElementB�����������ַ����ֶ�data
����ConcreteElementC�����㸡���ֶ�data�ĳ˻�

���Բ��ִ��룺
����һ������N����10����һ��N��ֵ�� ÿ�Եĵ�һ���ֶ��Ƿ���"A"��"B"��"C";��������Ҫ������Ԫ�ض�������ͣ�A��B��C���� ÿ�Եĵڶ����ֶζ������ڴ�����Ԫ�ص������ֶε�ֵ����������A��Ԫ��������������������B��Ԫ�������ַ�������������C��Ԫ������ʵ����
����ObjectStructure���͵Ķ��󣬲�������ԴԪ�ط������С� ���ֱ𴴽�ConcreteVisitor1��ConcreteVisitor2��ConcreteVisitor3�����͵����������߶���v1��v2��v3�� ʹ�ö���Accept(v1)�����ĵ�������ṹ����s�����ݣ�Ȼ��ʹ��Accept(v2)����ת�������ݣ���ʹ����һ��Accept(v1)�������ת��������ݡ� Ȼ�����Accept��v3����������ʹ��v3�����GetResultA��GetResultB��GetResultC��������������ҵ���s�ṹ��Ԫ�ص�������
 
 
 */
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class Element
        {
            public abstract void Accept(Visitor v);
        }

        public class ConcreteElementA : Element
        {
            // Add required fields and methods
            private int data;
            public ConcreteElementA(int data)
            {
                this.data = data;
            }
            public int GetData()
            {
                return data;
            }
            public void SetData(int data)
            {
                this.data = data;
            }
            public override void Accept(Visitor v)
            {
                // Implement the method
                v.VisitConcreteElementA(this);
            }
        }

        public class ConcreteElementB : Element
        {
            // Add required fields and methods
            private string data;
            public ConcreteElementB(string data)
            {
                this.data = data;
            }
            public string GetData()
            {
                return data;
            }
            public void SetData(string data)
            {
                this.data = data;
            }
            public override void Accept(Visitor v)
            {
                // Implement the method
                v.VisitConcreteElementB(this);
            }
        }

        public class ConcreteElementC : Element
        {
            // Add required fields and method
            private double data;
            public ConcreteElementC(double data)
            {
                this.data = data;
            }
            public double GetData()
            {
                return data;
            }
            public void SetData(double data)
            {
                this.data = data;
            }
            public override void Accept(Visitor v)
            {
                // Implement the method
                v.VisitConcreteElementC(this);
            }
        }

        public class ObjectStructure
        {
            Element[] struc;
            public ObjectStructure(Element[] struc)
            {
                // Implement the constructor
                this.struc = struc;
            }
            public void Accept(Visitor v)
            {
                foreach (var e in struc)
                { e.Accept(v); }
            }
        }

        public abstract class Visitor
        {
            public abstract void VisitConcreteElementA(ConcreteElementA e);
            public abstract void VisitConcreteElementB(ConcreteElementB e);
            public abstract void VisitConcreteElementC(ConcreteElementC e);
        }

        // Implement the ConcreteVisitor1, ConcreteVisitor2
        //   and ConcreteVisitor3 descendant classes
        class ConcreteVisitor1 : Visitor
        {
            public override void VisitConcreteElementA(ConcreteElementA e)
            {
                // Implement the method
                Put(e.GetData());
            }
            public override void VisitConcreteElementB(ConcreteElementB e)
            {
                // Implement the method
                Put(e.GetData());
            }
            public override void VisitConcreteElementC(ConcreteElementC e)
            {
                // Implement the method
                Put(e.GetData());
            }
        }
        class ConcreteVisitor2 : Visitor
        {
            public override void VisitConcreteElementA(ConcreteElementA e)
            {
                // Implement the method//ȡ������
                e.SetData(-e.GetData());
            }
            public override void VisitConcreteElementB(ConcreteElementB e)
            {
                // Implement the method//ȡ���ַ���
                string data = e.GetData();
                char[] charArray = data.ToCharArray();
                Array.Reverse(charArray);
                e.SetData(new string(charArray));
            }
            public override void VisitConcreteElementC(ConcreteElementC e)
            {
                // Implement the method//ȡ����
                double data = e.GetData();
                if (data !=0)
                {
                    e.SetData(1 / data);
                }
            }
        }
        class ConcreteVisitor3 : Visitor
        {
            private int resultA=0;
            private string resultB=string.Empty;
            private double resultC=1.0;

            public int GetResultA() { return resultA; }
            public string GetResultB() { return resultB; }
            public double GetResultC() { return resultC; }

            public override void VisitConcreteElementA(ConcreteElementA e)
            {
                resultA += e.GetData();//data���ܺ�
            }
            public override void VisitConcreteElementB(ConcreteElementB e)
            {
                //���������ַ����ֶ�data
                resultB += e.GetData();
            }
            public override void VisitConcreteElementC(ConcreteElementC e)
            {
                resultC *= e.GetData();//data���ܻ�
            }
        }

        public static void Solve()
        {
            Task("OOP3Behav15");
            int n=GetInt();
            List<Tuple<char,object>>pairs= new List<Tuple<char,object>>();
            for (int i = 0; i < n; i++)
            {
                char a = ' ';
                a = GetChar();
                if(a=='A')
                { pairs.Add(new Tuple<char, object>('A', GetInt())); }    
                else if(a=='B')
                { pairs.Add(new Tuple<char, object>('B', GetString())); }
                else 
                { pairs.Add(new Tuple<char, object>('C', GetDouble())); }

            }
            Element[] elements= new Element[n];
            for(int i = 0; i < n; i++)
            {
                char type = pairs[i].Item1;
                object data = pairs[i].Item2;
                switch(type)
                {
                    case'A':
                        elements[i]=new ConcreteElementA((int)data);break;
                    case 'B':
                        elements[i] = new ConcreteElementB((string)data); break;
                    case 'C':
                        elements[i] = new ConcreteElementC((double)data); break;

                }
            }
            ObjectStructure structure= new ObjectStructure(elements);
            Visitor v1 = new ConcreteVisitor1();
            Visitor v2 = new ConcreteVisitor2();
            ConcreteVisitor3 v3=new ConcreteVisitor3();
            structure.Accept(v1);
            structure.Accept(v2);
            structure.Accept(v1);
            structure.Accept(v3);
            Put(v3.GetResultA());
            Put(v3.GetResultB());
            Put(v3.GetResultC());               
        }
    }
}
