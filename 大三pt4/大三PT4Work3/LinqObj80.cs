// File: "LinqObj80"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

/*序列 D 和 E 包括以下字段：
D：<价格（卢布）> <商店名称> <商品项目
E: < 商品项目 > < 商店名称 > < 客户代码
序列的属性在本任务子集的序言中描述。
对于 D 中列出的每一对商店-商品，确定该商品在该商店的销售总值（首先是商店名称，然后是商品条目，然后是销售总值）。
如果该商品从未在某个商店出售过，则相应的 "商店-商品 "对的总价值为 0。
每对 "商店-商品 "的信息应显示在新的一行上，并按商店名称的字母顺序排列，如果 名称相同，则按商品种类（也按字母顺序排列）排列。*/

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqObj80");
            var D = File.ReadLines(GetString(), Encoding.Default)
                .Select(e =>
                {
                    string []s = e.Split(' ');
                    return new
                    {
                        Price = int.Parse(s[0]),
                        ShopName = s[1],
                        Article = s[2]
                    };
                })
                .ToList();

            var E = File.ReadLines(GetString(), Encoding.Default)
                .Select(e =>
                {
                    string []s = e.Split(' ');
                    return new
                    {
                        Article = s[0],
                        ShopName = s[1],
                        ConsumerCode = s[2]
                    };
                })
                .ToList();

            var result = D.GroupJoin(
                E,
                d => new { d.Article, d.ShopName },
                e => new { e.Article, e.ShopName },
                (d, es) => new
                {
                    d.ShopName,
                    d.Article,
                    TotalSales = es.Count() * d.Price
                })
                .OrderBy(x => x.ShopName)
                .ThenBy(x => x.Article)
                .Select(x => $"{x.ShopName} {x.Article} {x.TotalSales}");

            File.WriteAllLines(GetString(), result.ToArray(), Encoding.Default);


        }
    }
}
