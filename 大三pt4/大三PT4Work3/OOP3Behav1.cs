// File: "OOP3Behav1"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static PT4Tasks.MyTask;
//Observer模式:一种对象与对象之间的依赖关系，使得当一个对象的状态发生变化时，其依赖的对象都会收到通知并自动更新
//创建两个类层次结构
//1.Subject+ConcreteSubject(保存对ConcreteObserver感兴趣的状态;在发生变化时向它的观察者们发送信息)
//2.Observer+ConcreteObserver(保存对ConcreteSubject类对象的引用；保存需要与Subject数据协调的数据。)
//1.1在Subject类中,额外描述一个observers字段。这个字段是一个数据结构，其中存储了当前连接到主题的所有观察者的Observer类型引用元素。可以使用动态数据结构作为这样的数据结构，并具有添加和删除元素的命令。
//1.2subject:Attach(observ类型参数引用(不返值)Attach(observ)方法将observ对象添加到observers数据结构中)、Detach(observ类型参数引用(不返值)从observers数据结构中删除observ对象)和Notify(没数和返值；受保的)
//1.3(续上)Notify方法中,对observers数据结构的元素进行迭代:对于数据结构的每个元素,调用其Update方法。在实现Notify方法时,需要考虑以下情况:在执行Update方法时,一些观察者会从主题分离,导致observers数据结构的更改。

//2.Observer:Update(没参数且不返值).
//2.1ConcreteObserver:该类具有一个字符串字段log,一个字符字段detachInfo,一个subj字段——指向ConcreteSubject类型对象的引用,以及Attach、Detach和GetLog方法。
//2.2ConcreteObserver:subj和detachInfo参数,用于初始化相应的字段;log字段初始化为空字符串。Attach和Detach(没参且不返值)。在Attach方法中，调用subj对象的Attach方法；在Detach方法中，调用subj对象的Detach方法，其中在调用的两个方法中，都将触发调用这些方法的ConcreteObserver对象的引用作为参数。GetLog方法没有参数并返回log字段的值。
//2.2在本任务中，在Update方法中需要执行以下额外操作：将通过GetState方法获得的字符添加到调用Update方法的ConcreteObserver对象的log字段末尾；另外，如果获取的字符与detachInfo字段的值相匹配，则立即从subj主题中分离ConcreteObserver观察者，调用观察者的Detach方法。

namespace PT4Tasks
{
    public class MyTask : PT
    //观察者模式的示例
    {
        public class Subject//1.Subject类
        {
            // Add the required field
            List<Observer> observers = new List<Observer>();//1.1List<Observer>类型的字段，用于存储观察者
            //1.2 Attach,Detach,Notify
            public virtual void Attach(Observer observ)//添加观察者
            {
                // Implement the method
                observers.Add(observ);

            }
            public virtual void Detach(Observer observ)//删除观察者
            {
                // Implement the method
                observers.Remove(observ);
            }
            //1.3(续上)Notify
            protected virtual void Notify()//通知观察者
            {
                // Implement the method
                for (int i = observers.Count - 1; i >= 0; i--)
                    observers[i].Update();
            }
        }

？        //1.(1)Implement the ConcreteSubject descendant class
        public class ConcreteSubject : Subject//ConcreteSubject类是Subject类的具体实现
        {
            char state = ' ';//char类型的字段state，用于存储当前状态
            public void SetState(char st)//SetState方法用于设置状态
            {
                if (state != st)
                {
                    state = st;
                    Notify();//当状态发生变化时，会调用Notify方法通知观察者
                }
            }
            public char GetState()//GetState方法用于获取当前状态
            {
                return state;
            }
        }

        //2.Observer
        public abstract class Observer
        {
            public abstract void Update();
        }

        //2.1 Implement the ConcreteObserver descendant class
        public class ConcreteObserver : Observer//Observer类的具体实现
        {
            string log = "";//用于存储观察者的日志
            char detachInfo;
            ConcreteSubject subj;

            public ConcreteObserver(ConcreteSubject subj, char detachInfo)
            {
                this.subj = subj;
                this.detachInfo = detachInfo;
            }
            public void Attach()//添加观察者
            {
                subj.Attach(this);
            }
            public void Detach()//删除观察者
            {
                subj.Detach(this);
            }
            public string GetLog()
            {
                return log;
            }
            //2.2
            public override void Update()//状态发生变化时被调用，将新的状态添加到日志中
            {
                char c = subj.GetState();
                log += c;
                if (c == detachInfo)//状态等于detachInfo，则调用Detach方法删除观察者
                    Detach();
            }
        }

        public static void Solve()
        {
            Task("OOP3Behav1");
            ConcreteSubject subj = new ConcreteSubject();//创建一个ConcreteSubject实例
            ConcreteObserver[] observers = new ConcreteObserver[GetInt()];//数组，用于存储观察者
            for (int i = 0; i < observers.Length; i++)//遍历观察者数组，将每个观察者添加到Subject实例中
            {
                observers[i] = new ConcreteObserver(subj, (char)(65 + i));
                observers[i].Attach();
            }
            string s = GetString();//获取一个字符串s
            //遍历字符串中的每个字符，将字符设置为Subject实例的状态，并通知观察者
            foreach (var c in s)
                subj.SetState(c);
            //遍历观察者数组，输出每个观察者的日志
            foreach (var e in observers)
                Put(e.GetLog());

        }
    }
}
