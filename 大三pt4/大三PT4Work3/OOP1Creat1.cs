// File: "OOP1Creat1"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//c++和c#的一个区别是，c++的类和功能是在不同段的代码，c#在一段代码中
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class Product
        {//public是指外界可以访问
            public abstract string GetInfo();//get-infomation 返回结果 //abstract--virtual
            public abstract void Transform();//Transform 没结果，只操作
        }

        // Implement the ConcreteProduct1
        // and ConcreteProduct2 descendant classes

        public class ConcreteProduct1 : Product
        {
            string info; //这个类的区域(默认是封闭的，除非你写了public在前面)
            public override string GetInfo() //一定要写override
            {
                return info; //得到区域info里的内容（null)
            }
            public ConcreteProduct1(string info) //конструктор
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
            public string AnOperation(string info)//定义了一个具体的方法“AnOperation”
            {
                Product p = FactoryMethod(info);//用FactoryMethod创建不同对象
                p.Transform();//对象里的一些操作们
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
            //创建两个对象
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
