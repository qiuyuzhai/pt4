//1.Aggregate(抽象方法CreateIterator)+ConcreteAggregateA(整数类型）、ConcreteAggregateB(字符串类)和ConcreteAggregateC（包含整数元素的数据结构）。数据字段在类的构造函数中使用同类型的参数data进行初始化。
//1.2具体聚合类A,B,C实现了CreateIterator方法，返回的迭代器类型由聚合类的类型确定（对于聚合A，它是ConcreteIteratorA，对于聚合B，它是ConcreteIteratorB，对于聚合C，它是ConcreteIteratorC）
//1.3在CreateIterator方法中创建迭代器时，将调用CreateIterator方法的聚合对象的引用作为参数传递给迭代器的构造函数。聚合类还具有一个名为GetData的无参数方法，返回data字段的值。

//2.Iterator(抽象方法：First和Next（不返回值），IsDone（返回布尔值），CurrentItem（返回整数值）)和类ConcreteIteratorA、ConcreteIteratorB和ConcreteIteratorC
//2.1方法First将迭代器设置为可迭代数据集的第一个元素,方法Next将迭代器移动到下一个元素（或末尾）,方法IsDone在迭代器指向数据集末尾时返回true，否则返回false,方法CurrentItem返回迭代器指向的数据集元素，如果迭代器位于数据集末尾，则返回-1,•	对于空数据集，First方法立即将迭代器置于数据集末尾；当迭代器位于数据集末尾时，Next方法不执行任何操作
//2.3具体的迭代器类A、B、C与前面描述的聚合类A、B、C相关联，并提供了它们所包含数据的特殊遍历方式
//2.4迭代器A以逆序方式遍历聚合A的整数字段data中的所有数字（忽略数字的符号）；对于数字0，返回0（这是唯一一种情况，其中最后一个元素是数字0）。迭代器B以逆序方式遍历聚合B的字符串字段data中的所有数字字符。•	迭代器C以逆序方式遍历聚合C的数据结构data中所有元素的所有数字，包括元素本身和它们的数字。


//3测试代码：给定一个整数N(<10)和N组元素。每组元素的第一个元素是字符"A"、"B"或"C"，用于确定要创建的聚合对象的类型（A、B或C）
//3.1每组元素的后续元素确定要创建的聚合对象的data字段：对于聚合A，这是一个整数；对于聚合B，这是一个字符串；对于聚合C，这是一个整数K（≤10），用于确定数据结构data的大小，并且该数据结构有K个元素（K可以为0）。
//3.2创建一个包含N个指向Aggregate类型的引用的集合（例如数组），在其中保存原始的聚合对象，然后以逆序方式处理这些对象。对每个聚合对象的处理包括两个阶段，使用相应的迭代器执行：首先需要输出迭代器返回的数字的和（如果迭代器没有返回任何内容，则输出0），然后是迭代器返回的数字本身。
// File: "OOP3Behav7"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        //1.1
        public abstract class Aggregate
        {
            public abstract Iterator CreateIterator();
        }

        // Implement the ConcreteAggregateA, ConcreteAggregateB
        //   and ConcreteAggregateC descendant classes

        public class ConcreteAggregateA : Aggregate
        {
            private int data;//1.(1)整数类型
            public ConcreteAggregateA(int data)
            {
                this.data = data;
            }
            public override Iterator CreateIterator()//1.2
            {
                return new ConcreteIteratorA(this);
            }
            public int GetData()//1.3
            {
                return data;
            }
        }

        public class ConcreteAggregateB : Aggregate
        {
            private string data;//1.(1)字符串类
            public ConcreteAggregateB(string data)
            {
                this.data = data;
            }
            public override Iterator CreateIterator()//1.2
            {
                return new ConcreteIteratorB(this);
            }
            public string GetData()//1.3
            {
                return data;
            }
        }

        public class ConcreteAggregateC : Aggregate
        {
            private int[] data;//1.(1)包含整数元素的数据结构//？
            public ConcreteAggregateC(int[] data)
            {
                this.data = data;
            }
            public override Iterator CreateIterator()//1.2
            {
                return new ConcreteIteratorC(this);
            }
            public int[] GetData()//1.3
            {
                return data;
            }
        }
        //------------------------------------------------------------------------------------------
        //2
        public abstract class Iterator
        {
            public abstract void First();
            public abstract void Next();
            public abstract bool IsDone();
            public abstract int CurrentItem();
        }

        // Implement the ConcreteIteratorA, ConcreteIteratorB
        //   and ConcreteIteratorC descendant classes
        // 2
        public class ConcreteIteratorA : Iterator
        {
            private ConcreteAggregateA aggregate;
            private int index = -1;
            public ConcreteIteratorA(ConcreteAggregateA aggregate)
            {
                this.aggregate = aggregate;
            }
            public override void First()
            {
                if (aggregate == null)
                    this.index = -1;
                else
                    this.index = 0;
            }

            public override void Next()
            {
                if (this.index < Math.Abs(this.aggregate.GetData()).ToString().Length - 1)
                    this.index++;
                else
                    this.index = -1;
            }

            public override bool IsDone()
            {
                return index < 0;
            }

            public override int CurrentItem()
            {
                if (this.index == -1)
                    return -1;
                string elem = Math.Abs(this.aggregate.GetData()).ToString().Reverse().ToArray()[index].ToString();
                int result = -100;
                int.TryParse(elem, out result);
                return result;
            }
        }
        public class ConcreteIteratorB : Iterator
        {
            private ConcreteAggregateB aggregate;
            private int index = -1;
            public ConcreteIteratorB(ConcreteAggregateB aggregate)
            {
                this.aggregate = aggregate;
            }
            public override void First()
            {
                if (aggregate == null )
                    this.index = -1;
                else
                    this.index = 0;
            }

            public override void Next()
            {
                if (this.index < this.aggregate.GetData().Length - 1)
                    this.index++;
                else
                    this.index = -1;
            }

            public override bool IsDone()
            {
                return index < 0;
            }

            public override int CurrentItem()
            {
                if (this.index == -1)
                    return -1;
                string elem = this.aggregate.GetData().Reverse().ToArray()[index].ToString();
                int result = -100;
                if (!int.TryParse(elem, out result))
                    result = -100;
                return result;
            }
        }
        public class ConcreteIteratorC : Iterator
        {
            private ConcreteAggregateC aggregate;
            private int index = -1;
            public ConcreteIteratorC(ConcreteAggregateC aggregate)
            {
                this.aggregate = aggregate;
            }
            public override void First()
            {
                if (this.aggregate.GetData() == null )
                    this.index = -1;
                else
                    this.index = 0;
            }

            public override void Next()
            {
                if (this.index < this.aggregate.GetData().Length - 1)
                    this.index++;
                else
                    this.index = -1;
            }

            public override bool IsDone()
            {
                return index < 0;
            }

            public override int CurrentItem()
            {
                if (this.index == -1)
                    return -1;
                int elem = this.aggregate.GetData().Reverse().ElementAt(index);

                return Math.Abs(elem);
            }
        }

        public static void Solve()
        {
            Task("OOP3Behav7");
            List<Aggregate> aggregates = new List<Aggregate>();
            int N = GetInt();

            for (int i = 0; i < N; i++)
            {
                char c = GetChar();
                Show(c);
                if (c == 'A')
                {
                    int num = GetInt();
                    aggregates.Add(new ConcreteAggregateA(num));
                    Show(num);
                }
                if (c == 'B')
                {
                    string str = GetString();
                    aggregates.Add(new ConcreteAggregateB(str));
                    Show(str);
                }
                if (c == 'C')
                {
                    int K = GetInt();
                    if (K != 0)
                    {
                        int[] n = new int[K];
                        for (int j = 0; j < K; j++)
                        {
                            n[j] = GetInt();
                            Show(n[j]);
                        }
                        aggregates.Add(new ConcreteAggregateC(n));
                    }
                    else
                        aggregates.Add(new ConcreteAggregateC(null));
                }
            }
            aggregates.Reverse();
            foreach (var aggr in aggregates)
            {

                Iterator iterators = aggr.CreateIterator();
                int sum = 0;
                List<int> result = new List<int>();
                for (iterators.First(); !iterators.IsDone(); iterators.Next())
                {
                    int r = iterators.CurrentItem();
                    if (r != -1 &&r != -100)
                    {
                        if (aggr is ConcreteAggregateC)
                        {
                            string sc = string.Join("", r.ToString().Reverse());
                            if (sc.Length > 1)
                            {
                                for (int i = 0; i < sc.Length; i++)
                                {
                                    result.Add(Convert.ToInt32(sc[i].ToString()));
                                    sum = sum + Convert.ToInt32(sc[i].ToString());
                                }
                            }
                            else
                            {
                                result.Add(r);
                                sum = sum + r;
                            }
                        }
                        else
                        {
                            result.Add(r);
                            sum = sum + r;
                        }
                    }
                }
                Put(sum);
                foreach (var n in result)
                    Put(n);

            }
        }
    }
}