// File: "LinqBegin50"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqBegin50");
            var A = GetEnumerableString(); // ����÷����������� A
            var B = GetEnumerableString(); // ����÷����������� B

            var result = A.GroupJoin(B,
                                     a => a[0],
                                     b => b[0],
                                     (a, bGroup) => $"{a}:{bGroup.Count()}")
                          .ToList();

            result.Put();

        }
    }
}
