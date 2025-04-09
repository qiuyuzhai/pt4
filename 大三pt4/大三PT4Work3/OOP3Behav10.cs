// File: "OOP3Behav10"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

//State -A pattern of behavior:让对象根据其内部状态变化而改变行为，这些状态由一些与具体状态有关且具有相同接口的对象决定
//Context-定义客户端感兴趣的接口；存储ConcreteState子类的实例，用于定义当前状态;
//State- 定义了封装与上下文Context的特定状态相关联的行为的接口
//ConcreteStateA，ConcreteStateB（特定状态）-实现了与上下文Context的某个状态相关联的行为。
//任务：基于状态模式实现一组与文本解析相关的类
//要处理的文本包括常规内容（Normal）、双引号括起来的字符串文字（String）和用大括号括起来的注释（Comm）。
//字符串文字中的大括号被视为普通字符，就像注释中的双引号一样。如果字符串文字中连续出现两个双引号，则它们被视为单个双引号字符，属于字符串文字的一部分。注释不是嵌套的；注释内部的左大括号被视为普通字符
//解析结束的标志是存在的句号，句号本身不计入文本内容
//在String令牌中，不包括引号。在Comm令牌中，不包括大括号。如果最后一个字符串文字或注释没有使用所需的字符（引号或大括号），那么该文本片段将被视为错误令牌ErrString或ErrComm，应包含从字符串文字或注释开始到结尾的所有字符，直到句号（但不包括该句号）。
//任何类型的令牌都可以是空的；在文本的开头和结尾以及特定令牌String和Comm之间，必须存在一个Normal令牌（可能为空）。唯一的例外是错误令牌ErrString和ErrComm，它们后面解析文本就结束了
//状态类层次结构包括一个抽象类State，其中包含一个抽象方法Handle（没有参数，返回描述正在解析的文本的下一个令牌的字符串），以及类ConcreteStateNormal、ConcreteStateString、ConcreteStateComm和ConcreteStateFinal。
//除了ConcreteStateFinal类之外，每个具体类都包含字段ct——对上下文对象的引用——和整数类型的字段ind，在构造函数中使用相应的参数进行初始化。
//字段ct用于确定包含要解析的文本的对象，字段ind用于确定从哪个索引位置开始继续解析文本。
//Handle方法返回一个包含获得的令牌的字符串（可能为空），在令牌前面指定其类型和冒号（例如"Normal:abc"，"ErrString:mn2"，"Comm:"）。ConcreteStateFinal类不包含字段，其构造函数不执行任何额外操作，而Handle方法始终返回空字符串。
//在确定当前令牌为Normal之后，ConcreteStateNormal类的Handle方法调用上下文ct的SetState方法，并将ConcreteStateString类的实例作为参数传递（如果检测到双引号字符），或者将ConcreteStateComm类的实例作为参数传递（如果检测到大括号字符），或者将ConcreteStateFinal类的实例作为参数传递（如果检测到点号字符）
//在确定当前正确的令牌为String或Comm之后，ConcreteStateString类和ConcreteStateComm类的Handle方法调用上下文ct的SetState方法，并将ConcreteStateNormal类的实例作为参数传递。
//在确定错误的令牌为ErrString或ErrComm之后，ConcreteStateString类和ConcreteStateComm类的Handle方法调用上下文ct的SetState方法，并将ConcreteStateFinal类的实例作为参数传递
//Context类包含一个字符串字段txt，用于存储被解析的文本，以及一个类型为State的字段st。类的构造函数带有一个名为txt的参数，用于初始化txt字段；st字段则初始化为ConcreteStateNormal类的实例。Context类具有GetCharAt(ind)、SetState(st)和Request方法。
//• GetCharAt方法返回txt字段中索引为ind的字符（假设索引在有效范围内）； • SetState方法通过将st字段赋值为参数st来改变st字段的值（这个方法和GetCharAt方法一起在状态类的方法中使用）； • Request方法通过调用st对象的Handle方法返回解析文本的下一个标记
//测试：
//给定一个以句点结尾的字符串。使用类型为Context的对象ct，解析给定的字符串，调用ct对象的Request方法并输出其返回结果，直到下一次调用不再返回空字符串（不要输出空字符串）。





namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class State
        {
            protected Context context;
            protected int index;

            public State(Context context, int index)
            {
                this.context = context;
                this.index = index;
            }

            public abstract string Handle();
        }

        // Implement the ConcreteStateNormal, ConcreteStateString,
        //   ConcreteStateComm and ConcreteStateFinal descendant classes
        public class ConcreteStateNormal : State
        {
            public ConcreteStateNormal(Context context, int index) : base(context, index) { }

            public override string Handle()
            {
                string s = "Normal:";
                while (index < context.txt.Length)
                {
                    char c = context.GetCharAt(index++);
                    if (c == '"')
                    {
                        context.SetState(new ConcreteStateString(context, index));
                        break;
                    }
                    else if (c == '{')
                    {
                        context.SetState(new ConcreteStateComm(context, index));
                        break;
                    }
                    else if (c == '.')
                    {
                        context.SetState(new ConcreteStateFinal(context, index));
                        break;
                    }
                    else
                    {
                        s += c;
                    }
                }
                return s;
            }
        }
        public class ConcreteStateString : State
        {
            public ConcreteStateString(Context context, int index) : base(context, index) { }

            public override string Handle()
            {
                string s = "";
                string title = "String:";
                while (index < context.txt.Length)
                {
                    char c1 = context.GetCharAt(index++);
                    char c2 = (index < context.txt.Length) ? context.GetCharAt(index) : '\0';
                    if (c1 == '"' && c2 == '"')
                    {
                        s += c1;
                        index++;
                    }
                    else if (c1 == '"')
                    {
                        context.SetState(new ConcreteStateNormal(context, index));
                        break;
                    }
                    else if (c1 == '.')
                    {
                        title = "ErrString:";
                        context.SetState(new ConcreteStateFinal(context, index));
                        break;
                    }
                    else
                    {
                        s += c1;
                    }
                }
                return title + s;
            }
        }
        public class ConcreteStateComm : State
        {
            public ConcreteStateComm(Context context, int index) : base(context, index) { }

            public override string Handle()
            {
                string s = "";
                string title = "Comm:";
                while (index < context.txt.Length)
                {
                    char c = context.GetCharAt(index++);
                    if (c == '}')
                    {
                        context.SetState(new ConcreteStateNormal(context, index));
                        break;
                    }
                    else if (c == '.')
                    {
                        title = "ErrComm:";
                        context.SetState(new ConcreteStateFinal(context, index));
                        break;
                    }
                    else
                    {
                        s += c;
                    }
                }
                return title + s;
            }
        }

        public class ConcreteStateFinal : State
        {
            public ConcreteStateFinal(Context context, int index) : base(context, index) { }

            public override string Handle()
            {
                return "";
            }
        }

        public class Context
        {
            public string txt;
            private State st;

            public Context(string text)
            {
                txt = text;
                st = new ConcreteStateNormal(this, 0);
            }

            public char GetCharAt(int index)
            {
                return txt[index];
            }

            public void SetState(State newState)
            {
                st = newState;
            }

            public string Request()
            {
                return st.Handle();
            }
        }


        // Implement the Context class
        public static void Solve()
        {
            Task("OOP3Behav10");
            string s = GetString();
            Context context = new Context(s);
            string token;
            while ((token = context.Request()) != "")
            {
                Put(token);

            }
        }
    }
}