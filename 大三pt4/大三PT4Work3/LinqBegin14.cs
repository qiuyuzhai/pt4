// File: "LinqBegin14"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//The integers A and B (A < B) are given. Using the Range and Average methods,
//find the arithmetic mean of the squares of all integers from A to B inclusive: (A2 + (A+1)2 + ... + B2) /(B − A + 1) (as a real number).
namespace PT4Tasks
{
    public class MyTask : PT
    {
        // When solving tasks of the LinqBegin group, the following
        // additional methods defined in the taskbook are available:
        // (*) GetEnumerableInt() - input of a numeric sequence;
        // (*) GetEnumerableString() - input of a string sequence;
        // (*) Put() (extension method) - output of a sequence;
        // (*) Show() and Show(cmt) (extension methods) - debug output
        //       of a sequence, cmt - string comment;
        // (*) Show(e => r) and Show(cmt, e => r) (extension methods) -
        //       debug output of r values, obtained from elements e
        //       of a sequence, cmt - string comment.

        public static void Solve()
        {
            Task("LinqBegin14");
            int A = GetInt(); // 你可以根据需要更改这两个变量的值
            int B = GetInt();
            double mean = Enumerable.Range(A, B - A + 1).Select(x => x * x).Average();
            Put(mean);


        }
    }
}
