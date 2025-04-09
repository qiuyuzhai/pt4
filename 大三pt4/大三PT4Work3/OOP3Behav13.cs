// File: "OOP3Behav13"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        //实现处理程序类层次结构，包括抽象类Handler和两个具体类ConcreteHandler1和ConcreteHandler2。
        //Handler类包含抽象方法HandleRequest(req)（不返回任何值，具有类型为整数的req参数，用于定义请求号）。
        public abstract class Handler
        {
            public abstract void HandleRequest(int req);
        }

        // Implement the ConcreteHandler1
        //ConcreteHandler1类具有一个successor字段 - 指向Handler对象的引用，以及三个整数字段：
        //id（处理程序的整数标识符）、req1和req2（确定处理程序可以处理的请求编号范围）。
        //所有这些字段都在构造函数中使用构造函数参数successor、id、req1、req2进行初始化。
        class ConcreteHandler1 : Handler
        {
            private Handler successor;
            private int id;
            private int reqest1;
            private int reqest2;
            public ConcreteHandler1(Handler successor, int id, int req1, int req2)
            {
                this.successor = successor;
                this.id = id;
                this.reqest1 = req1;
                this.reqest2 = req2;
            }
            public override void HandleRequest(int req)
            {
                if (req >= reqest1 && req <= reqest2)
                {
                    Put("Request " + req + " processed by handler " + id);
                }
                else if (successor != null)
                {
                    successor.HandleRequest(req);
                }
            }

        }
        //   and ConcreteHandler2 descendant classes
        //类ConcreteHandler2是一种特殊的终端处理程序，应位于处理程序链的末尾。因此，所有未处理的请求将传递给它。
        //它没有字段，其构造函数不执行任何额外操作，
        //而HandleRequest(req)方法打印出“请求<req>未被处理”的文本，其中<req>是req参数的值。
        public class ConcreteHandler2 : Handler
        {
            public override void HandleRequest(int req)
            {
                Put(("Request " + req + " not processed"));
            }
        }
        //辅助类Client包含一个字段h，类型为Handler
        public class Client
        {
            Handler h;
            //指向早前形成的处理程序链中的第一个处理程序,字段h在构造函数中通过同名参数初始化。
            public Client(Handler h)
            {
                this.h = h;
            }
            //Client类还包含一个名为SendRequest(req)的方法，该方法接受一个整数参数req并且不返回任何值；
            //在此方法中，会调用h对象的HandleRequest(req)方法
            public void SendRequest(int req)
            {
                h.HandleRequest(req);
            }
        }

        public static void Solve()
        {
            Task("OOP3Behav13");
            int N = GetInt();
            int[,] pairs = new int[20, 20];

            for (int i = 0; i < N; i++)
            {
                int r1 = GetInt();
                int r2 = GetInt();
                pairs[i, 0] = r1;
                pairs[i, 1] = r2;
            }
            //使用变量h引用Handler对象，依次创建一个ConcreteHandler2类型的对象和N个ConcreteHandler1类型的对象。
            //所创建对象的引用都存储在同一个变量h中；对于ConcreteHandler1对象的构造函数参数应为h、i、r1、r2，
            //其中i是原始集合中一对的索引（对索引从0开始），r1和r2分别为这对的第一个和第二个元素。
            //结果将创建一个由N + 1个处理程序组成的链，其中该链的第一个元素（其引用将存储在变量h中）
            //将是具有标识符N − 1的ConcreteHandler1处理程序，倒数第二个是具有标识符0的ConcreteHandler1处理程序，
            //最后一个是ConcreteHandler2类型的处理程序。
            Handler h = new ConcreteHandler2();
            for (int i = N - 1; i >= 0; i--)
            {
                h = new ConcreteHandler1(h, i, pairs[i, 0], pairs[i, 1]);
            }
            //创建一个名为cli的Client对象，将其构造函数的参数设置为引用h的值。
            Client cli = new Client(h);
            int K = GetInt();
            int[] requests = new int[K];
            for (int i = 0; i < K; i++)
            {
                int num = GetInt();
                requests[i] = num;
            }
            //对于给定集合中的每个请求req，执行cli对象的SendRequest(req)方法调用.
            //不需要输出任何结果，因为输出是在处理程序对象的HandleRequest方法中执行的。
            foreach (int req in requests)
            {
                cli.SendRequest(req);
            }
        }
    }
}