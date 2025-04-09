// File: "OOP1Creat1"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//c++��c#��һ�������ǣ�c++����͹������ڲ�ͬ�εĴ��룬c#��һ�δ�����
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class Product
        {//public��ָ�����Է���
            public abstract string GetInfo();//get-infomation ���ؽ�� //abstract--virtual
            public abstract void Transform();//Transform û�����ֻ����
        }

        // Implement the ConcreteProduct1
        // and ConcreteProduct2 descendant classes

        public class ConcreteProduct1 : Product
        {
            string info; //����������(Ĭ���Ƿ�յģ�������д��public��ǰ��)
            public override string GetInfo() //һ��Ҫдoverride
            {
                return info; //�õ�����info������ݣ�null)
            }
            public ConcreteProduct1(string info) //�ܧ�ߧ����ܧ���
            {
                this.info = info.ToLower();
            }
            public override void Transform()
            {
                StringBuilder s = new StringBuilder(info);
                for (int i = s.Length - 2; i >= 0; i--)
                    if (s[i] != ' ')
                        s.Insert(i + 1, " ");
                info = s.ToString();
            }
        }
        public class ConcreteProduct2 : Product
        {
            string info;
            public override string GetInfo()
            {
                return info;
            }
            public ConcreteProduct2(string info)
            {
                this.info = info.ToUpper();
            }
            public override void Transform()
            {
                StringBuilder s = new StringBuilder(info);
                for (int i = s.Length - 2; i >= 0; i--)
                    if (s[i] != '*')
                        s.Insert(i + 1, "**");
                info = s.ToString();
            }
        }


        public abstract class Creator
        {
            protected abstract Product FactoryMethod(string info);
            public string AnOperation(string info)//������һ������ķ�����AnOperation��
            {
                Product p = FactoryMethod(info);//��FactoryMethod������ͬ����
                p.Transform();//�������һЩ������
                p.Transform();
                return p.GetInfo();
            }
        }

        // Implement the ConcreteCreator1
        //   and ConcreteCreator2 descendant classes;
        //   the AnOperation method should not be
        //   overridden in these classes
        public class ConcreteCreator1 : Creator
        {
            protected override Product FactoryMethod(string info)
            {
                return new ConcreteProduct1(info);
            }
        }

        public class ConcreteCreator2 : Creator
        {
            protected override Product FactoryMethod(string info)
            {
                return new ConcreteProduct2(info);
            }
        }
        public static void Solve()
        {
            Task("OOP1Creat1");
            //������������
            var c1 = new ConcreteCreator1();
            var c2 = new ConcreteCreator2();
            for (int i = 0; i < 5; i++)
            {
                string s = GetString();
                Put(c1.AnOperation(s), c2.AnOperation(s));

            }
        }
    }
}
