// File: "OOP3Behav15"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*
任务：
实现两个类层次结构，分别是元素类层次结构和访问者类层次结构。

元素类层次结构：

1.抽象类 Element：

包含一个抽象方法 Accept(Visitor v)，不返回结果。
具体类 ConcreteElementA, ConcreteElementB, ConcreteElementC：

每个具体类都有一个data字段：
ConcreteElementA：整型
ConcreteElementB：字符串
ConcreteElementC：浮点数
在构造函数中初始化data字段。
实现Accept(Visitor v)方法，调用访问者中的对应Visit方法。
具有GetData和SetData方法，用于访问和修改data字段。


2.ObjectStructure类型：

包含一个struc字段（例如一个数组），其元素为Element类型的对象。
构造函数用参数初始化struc字段。
包含Accept(Visitor v)方法，遍历struc中的元素并调用它们的Accept方法。
访问者类层次结构：

3.抽象类 Visitor：

包含三个抽象方法：
VisitConcreteElementA(ConcreteElementA e)
VisitConcreteElementB(ConcreteElementB e)
VisitConcreteElementC(ConcreteElementC e)
具体类 ConcreteVisitor1, ConcreteVisitor2, ConcreteVisitor3：

ConcreteVisitor1：输出元素的data字段。
ConcreteVisitor2：转换元素的data字段：
对于ConcreteElementA：取反整数
对于ConcreteElementB：反转字符串
对于ConcreteElementC：取倒数（1/data）
ConcreteVisitor3：计算所有同类型元素的综合特征：
对于ConcreteElementA：计算整型字段data的总和
对于ConcreteElementB：连接所有字符串字段data
对于ConcreteElementC：计算浮点字段data的乘积

测试部分代码：
给定一个整数N（≤10）和一组N对值。 每对的第一个字段是符号"A"，"B"或"C";它定义了要创建的元素对象的类型（A，B或C）。 每对的第二个字段定义正在创建的元素的数据字段的值：对于类型A的元素它是整数，对于类型B的元素它是字符串，对于类型C的元素它是实数。
创建ObjectStructure类型的对象，并将所有源元素放入其中。 还分别创建ConcreteVisitor1、ConcreteVisitor2、ConcreteVisitor3种类型的三个访问者对象v1、v2、v3。 使用对其Accept(v1)方法的调用输出结构对象s的内容，然后使用Accept(v2)调用转换此内容，并使用另一个Accept(v1)调用输出转换后的内容。 然后调用Accept（v3）方法，并使用v3对象的GetResultA，GetResultB和GetResultC方法输出在其中找到的s结构的元素的特征。
 
 
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
                // Implement the method//取反整数
                e.SetData(-e.GetData());
            }
            public override void VisitConcreteElementB(ConcreteElementB e)
            {
                // Implement the method//取反字符串
                string data = e.GetData();
                char[] charArray = data.ToCharArray();
                Array.Reverse(charArray);
                e.SetData(new string(charArray));
            }
            public override void VisitConcreteElementC(ConcreteElementC e)
            {
                // Implement the method//取倒数
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
                resultA += e.GetData();//data的总和
            }
            public override void VisitConcreteElementB(ConcreteElementB e)
            {
                //连接所有字符串字段data
                resultB += e.GetData();
            }
            public override void VisitConcreteElementC(ConcreteElementC e)
            {
                resultC *= e.GetData();//data的总积
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
