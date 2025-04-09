// File: "LinqObj42"
/*初始序列包含有关加油站（汽油站）的信息。序列中的每个元素都包括以下字段：

<汽油品牌> <公司> <街道> <1升汽油价格（戈比）>。

公司和街道名称不包含空格。数字 92、95 或 98 表示汽油牌号。每家公司在每条街道上的加油站不超过一个；同一家公司不同加油站的价格可能不同。
为每条街道确定各品牌汽油的最低价格（首先输出街道名称，然后输出三个数字 - 92、95 和 98 号汽油的最低价格）。
如果没有所需品牌的汽油，则应显示数字 0。 每条街道的信息应显示在新的一行中，并按街道名称的字母顺序排列。*/
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqObj42");
            var res = File.ReadLines(GetString(), Encoding.Default)
                .Select(e => {
                    var s = e.Split(' ');
                    return new
                    {
                        Brand = int.Parse(s[0]),
                        Company = s[1],
                        Street = s[2],
                        Price = int.Parse(s[3])
                    };
                })
                .GroupBy(e => e.Street)
                .Select(g => new
                {
                    Street = g.Key,
                    Min92 = g.Where(x => x.Brand == 92).Select(x => x.Price).DefaultIfEmpty(0).Min(),
                    Min95 = g.Where(x => x.Brand == 95).Select(x => x.Price).DefaultIfEmpty(0).Min(),
                    Min98 = g.Where(x => x.Brand == 98).Select(x => x.Price).DefaultIfEmpty(0).Min()
                })
                .OrderBy(x => x.Street)
                .Select(x => $"{x.Street} {x.Min92} {x.Min95} {x.Min98}");

            File.WriteAllLines(GetString(), res.ToArray(), Encoding.Default);




        }
    }
}
