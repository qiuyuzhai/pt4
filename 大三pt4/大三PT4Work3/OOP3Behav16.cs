// File: "OOP3Behav16"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public class Context
        {
            // Add the constructor, required fields and methods
            public List<string> names = new List<string>();
            public List<double> values = new List<double>();
            public Context()
            {
                for (char c = 'a'; c <= 'j'; c++)
                {
                    names.Add(c.ToString());
                    values.Add(1.0);
                }
            }
            public void SetVar(int ind, string name, double value)
            {
                names[ind] = name;
                values[ind] = value;
            }
            public string GetName(int ind)
            {
                return names[ind];
            }
            public double GetValue(int ind)
            {
                return values[ind];
            }
        }

        public abstract class AbstractExpression
        {
            public abstract string InterpretA(Context ct);
            public abstract string InterpretB(Context ct);
            public abstract double InterpretC(Context ct);
        }

        // Implement the TermConst, TermVar
        //   and NontermMath descendant classes
        public class TermConst:AbstractExpression
        {
            public double value;
            public TermConst(double value)
            {
                this.value = value;
            }
            public override string InterpretA(Context ct)
            {
                return value.ToString("F2");
            }
            public override string InterpretB(Context ct)
            {
                return value.ToString("F2");
            }
            public override double InterpretC(Context ct)
            {
                return value;
            }
        }
        public class TermVar : AbstractExpression 
        {
            public int ind;
            public TermVar(int ind)
            {
                this.ind = ind;
            }
            public override string InterpretA(Context ct)
            {
                return ct.GetName(ind);
            }
            public override string InterpretB(Context ct)
            {
                return ct.GetName(ind);
            }
            public override double InterpretC(Context ct)
            {
                return ct.GetValue(ind);
            }
        }
        class NontermMath:AbstractExpression
        {
            public AbstractExpression expr1;
            public AbstractExpression expr2;
            public char op;
            public NontermMath(AbstractExpression expr1, AbstractExpression expr2, char op)
            {
                this.expr1 = expr1;
                this.expr2 = expr2;
                this.op = op;
            }
            public override string InterpretA(Context ct)
            {
               string result="("+expr1.InterpretA(ct)+op+expr2.InterpretA(ct)+")";
                return result;
            }
            public override string InterpretB(Context ct)
            {
                return expr1.InterpretB(ct)+" "+expr2.InterpretB(ct)+" "+op;
            }
            public override double InterpretC(Context ct)
            {
                double val1=expr1.InterpretC(ct);
                double val2=expr2.InterpretC(ct);
                switch (op)
                {
                    case '+': return val1 + val2; 
                    case '-': return val1 - val2; 
                    case '*': return val1 * val2; 
                    case '/': return val1 / val2;
                    default:throw new ArgumentException("Invalid operator");
                }
            }
        }

        public class Client
        {
            AbstractExpression expr;
            Context ct;
            public Client(AbstractExpression expr, Context ct)
            {
                this.expr = expr;
                this.ct = ct;
            }
            public string InterpretA()
            {
                return expr.InterpretA(ct);
            }
            public string InterpretB()
            {
                return expr.InterpretB(ct);
            }
            public double InterpretC()
            {
                return expr.InterpretC(ct);
            }
        }

        public static void Solve()
        {
            Task("OOP3Behav16");
            Context ct=new Context();
            List<AbstractExpression>list= new List<AbstractExpression>();
            int n = GetInt();
            for(int i = 0; i < n; i++)
            {
                char c = GetChar();
                if(c=='M')
                {
                    int k1 = GetInt();
                    int k2 = GetInt();
                    char op = GetChar();
                    list.Add(new NontermMath(list[k1], list[k2],op));
                }
                else if(c=='C')
                {
                    double p = GetDouble();
                    list.Add(new TermConst(p));
                }
                else if(c=='V')
                {
                    int k = GetInt();
                    list.Add(new TermVar(k));
                }
            }
            int m = GetInt();
            for(int i=0;i<m; i++)
            {
                int ind=GetInt();
                string name = GetString();
                double val = GetDouble();
                ct.SetVar(ind, name, val); 
            }
            Client cli=new Client(list[list.Count-1],ct);
            Put(cli.InterpretA());
            Put(cli.InterpretB());
            Put(cli.InterpretC());
        }
    }
}
