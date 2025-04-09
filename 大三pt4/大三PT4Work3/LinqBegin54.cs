// File: "LinqBegin54"
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
            Task("LinqBegin54");
            GetEnumerableString().GroupJoin(GetEnumerableString(), 
                e => e[0], e => e[0], 
                (el, ee2) => ee2.DefaultIfEmpty("").Select(e => el + "." + e))
                .SelectMany(e => e).OrderBy(e => e).Show().Put();

        }
    }
}
