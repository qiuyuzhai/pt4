// File: "LinqBegin25"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//The integers K1 and K2 and the integer sequence A are given; 1 ≤ K1 < K2 ≤ N, where N is the size of the sequence A.
//Find the sum of the positive elements of the sequence with ordinal numbers from K1 to K2 inclusive.
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin25");
            int K1 = GetInt(); 
            int K2= GetInt();
            var a = GetEnumerableInt();//用于获取一个可枚举的整数序列
            Put(a.Skip(K1 - 1).Take(K2 - K1 + 1).Where(x => x > 0).Sum());


        }
    }
}
