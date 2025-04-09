// File: "OOP2Struc11"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.Remoting.Channels;
using System.Text;
using System.Threading;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class Flyweight
        {
            public abstract char Operation(bool state);
        }

        // Implement the ConcreteFlyweight
        public class ConcreteFlyweight:Flyweight
        {
            public override char Operation(bool state)
            {
                if(state)
                {
                    return 'A';
                }
                else
                {
                    return 'a';
                }
            }
        }
        //   and UnsharedConcreteFlyweight descendant classes
        public class UnsharedConcreteFlyweight : Flyweight
        {
            private char inf;
            public UnsharedConcreteFlyweight(char _inf)
            {
                inf = _inf;
            }
            public override char Operation(bool state)
            {
                if (state)
                {
                    return char.ToUpper(inf);
                }
                else
                {
                    return char.ToLower(inf);
                }
            }
        }

        // Implement the FlyweightFactory and Client classes
        public class FlyweightFactory
        {
            public ConcreteFlyweight cf;
            private int cnt;
            public FlyweightFactory()
            {
                cf = null;
                cnt = 0;
            }
            public Flyweight GetFlyweight(char inf)
            {
                if(inf=='A'||inf=='a')
                {
                    if(cf==null)
                    {
                        cf = new ConcreteFlyweight();
                        cnt++;
                    }
                    return cf;
                }
                else
                {
                    cnt++;
                    return new UnsharedConcreteFlyweight(inf);
                }
            }
            public int GetCount()
            {
                return cnt;
            }
        }
        public class Client
        {
            private FlyweightFactory f;
            private Flyweight[] fw;
            public Client()
            {
                f = new FlyweightFactory();
                fw= new Flyweight[30];
            }
            public void MakeFlyweights(string inf)
            {
                for(int i=0;i<inf.Length;i++)
                {
                    fw[i] = f.GetFlyweight(inf[i]);
                }
                for(int i=inf.Length;i<fw.Length;i++)
                {
                    fw[i] = null;
                }
            }
            public string ShowFlyweights(bool state)
            {
                List<char> list = new List<char>();
                foreach(var flyweight in fw)
                {
                    if(flyweight !=null)
                    {
                        list.Add(flyweight.Operation(state));
                    }
                }
                return new string(list.ToArray());
            }
            public int GetFlyweightCount()
            {
                return f.GetCount();
            }
        }

        public static void Solve()
        {
            Task("OOP2Struc11");
            Client cli = new Client();
            for(int i=0;i<5;i++)
            {
                string s = GetString();
                cli.MakeFlyweights(s);
                Put(cli.ShowFlyweights(true));
                Put(cli.ShowFlyweights(false));
                Put(cli.GetFlyweightCount());
            }
        }
    }
}
