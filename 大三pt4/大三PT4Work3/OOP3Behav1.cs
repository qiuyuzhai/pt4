// File: "OOP3Behav1"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static PT4Tasks.MyTask;
//Observerģʽ:һ�ֶ��������֮���������ϵ��ʹ�õ�һ�������״̬�����仯ʱ���������Ķ��󶼻��յ�֪ͨ���Զ�����
//�����������νṹ
//1.Subject+ConcreteSubject(�����ConcreteObserver����Ȥ��״̬;�ڷ����仯ʱ�����Ĺ۲����Ƿ�����Ϣ)
//2.Observer+ConcreteObserver(�����ConcreteSubject���������ã�������Ҫ��Subject����Э�������ݡ�)
//1.1��Subject����,��������һ��observers�ֶΡ�����ֶ���һ�����ݽṹ�����д洢�˵�ǰ���ӵ���������й۲��ߵ�Observer��������Ԫ�ء�����ʹ�ö�̬���ݽṹ��Ϊ���������ݽṹ����������Ӻ�ɾ��Ԫ�ص����
//1.2subject:Attach(observ���Ͳ�������(����ֵ)Attach(observ)������observ������ӵ�observers���ݽṹ��)��Detach(observ���Ͳ�������(����ֵ)��observers���ݽṹ��ɾ��observ����)��Notify(û���ͷ�ֵ���ܱ���)
//1.3(����)Notify������,��observers���ݽṹ��Ԫ�ؽ��е���:�������ݽṹ��ÿ��Ԫ��,������Update��������ʵ��Notify����ʱ,��Ҫ�����������:��ִ��Update����ʱ,һЩ�۲��߻���������,����observers���ݽṹ�ĸ��ġ�

//2.Observer:Update(û�����Ҳ���ֵ).
//2.1ConcreteObserver:�������һ���ַ����ֶ�log,һ���ַ��ֶ�detachInfo,һ��subj�ֶΡ���ָ��ConcreteSubject���Ͷ��������,�Լ�Attach��Detach��GetLog������
//2.2ConcreteObserver:subj��detachInfo����,���ڳ�ʼ����Ӧ���ֶ�;log�ֶγ�ʼ��Ϊ���ַ�����Attach��Detach(û���Ҳ���ֵ)����Attach�����У�����subj�����Attach��������Detach�����У�����subj�����Detach�����������ڵ��õ����������У���������������Щ������ConcreteObserver�����������Ϊ������GetLog����û�в���������log�ֶε�ֵ��
//2.2�ڱ������У���Update��������Ҫִ�����¶����������ͨ��GetState������õ��ַ���ӵ�����Update������ConcreteObserver�����log�ֶ�ĩβ�����⣬�����ȡ���ַ���detachInfo�ֶε�ֵ��ƥ�䣬��������subj�����з���ConcreteObserver�۲��ߣ����ù۲��ߵ�Detach������

namespace PT4Tasks
{
    public class MyTask : PT
    //�۲���ģʽ��ʾ��
    {
        public class Subject//1.Subject��
        {
            // Add the required field
            List<Observer> observers = new List<Observer>();//1.1List<Observer>���͵��ֶΣ����ڴ洢�۲���
            //1.2 Attach,Detach,Notify
            public virtual void Attach(Observer observ)//��ӹ۲���
            {
                // Implement the method
                observers.Add(observ);

            }
            public virtual void Detach(Observer observ)//ɾ���۲���
            {
                // Implement the method
                observers.Remove(observ);
            }
            //1.3(����)Notify
            protected virtual void Notify()//֪ͨ�۲���
            {
                // Implement the method
                for (int i = observers.Count - 1; i >= 0; i--)
                    observers[i].Update();
            }
        }

��        //1.(1)Implement the ConcreteSubject descendant class
        public class ConcreteSubject : Subject//ConcreteSubject����Subject��ľ���ʵ��
        {
            char state = ' ';//char���͵��ֶ�state�����ڴ洢��ǰ״̬
            public void SetState(char st)//SetState������������״̬
            {
                if (state != st)
                {
                    state = st;
                    Notify();//��״̬�����仯ʱ�������Notify����֪ͨ�۲���
                }
            }
            public char GetState()//GetState�������ڻ�ȡ��ǰ״̬
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
        public class ConcreteObserver : Observer//Observer��ľ���ʵ��
        {
            string log = "";//���ڴ洢�۲��ߵ���־
            char detachInfo;
            ConcreteSubject subj;

            public ConcreteObserver(ConcreteSubject subj, char detachInfo)
            {
                this.subj = subj;
                this.detachInfo = detachInfo;
            }
            public void Attach()//��ӹ۲���
            {
                subj.Attach(this);
            }
            public void Detach()//ɾ���۲���
            {
                subj.Detach(this);
            }
            public string GetLog()
            {
                return log;
            }
            //2.2
            public override void Update()//״̬�����仯ʱ�����ã����µ�״̬��ӵ���־��
            {
                char c = subj.GetState();
                log += c;
                if (c == detachInfo)//״̬����detachInfo�������Detach����ɾ���۲���
                    Detach();
            }
        }

        public static void Solve()
        {
            Task("OOP3Behav1");
            ConcreteSubject subj = new ConcreteSubject();//����һ��ConcreteSubjectʵ��
            ConcreteObserver[] observers = new ConcreteObserver[GetInt()];//���飬���ڴ洢�۲���
            for (int i = 0; i < observers.Length; i++)//�����۲������飬��ÿ���۲�����ӵ�Subjectʵ����
            {
                observers[i] = new ConcreteObserver(subj, (char)(65 + i));
                observers[i].Attach();
            }
            string s = GetString();//��ȡһ���ַ���s
            //�����ַ����е�ÿ���ַ������ַ�����ΪSubjectʵ����״̬����֪ͨ�۲���
            foreach (var c in s)
                subj.SetState(c);
            //�����۲������飬���ÿ���۲��ߵ���־
            foreach (var e in observers)
                Put(e.GetLog());

        }
    }
}
