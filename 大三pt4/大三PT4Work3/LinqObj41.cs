// File: "LinqObj41"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
/*整数 M 是一个汽油品牌的值。初始序列包含加油站（汽油站）的信息。序列中的每个元素都包括以下字段：

<汽油等级> <街道> <公司> <每升价格（戈比）>。

公司和街道名称不包含空格。数字 92、95 或 98 表示汽油等级。每家公司在每条街道上的加油站不超过一个；
同一家公司不同加油站的价格可能不同。
在每条街道上有 M 牌汽油加油站的地方，确定该品牌汽油的最高价格（先输出最高价 格，再输出街道名称）。
每条街道的信息都应显示在新的一行上，并按最高价格的递增顺序排列，对于相同价格的信息，则按街道名称的字母顺序排列。如果没有找到提供 M 级汽油的加油站，则在生成的文件中写入 "无 "一行。*/


namespace PT4Tasks
{
    public class MyTask : PT
    {
        public static void Solve()
        {
            Task("LinqObj41");
            int m = GetInt();
            var r =
            (from e in File.ReadLines(GetString(), Encoding.Default)
             let s = e.Split(' ')
             select new
             {
                 brand = int.Parse(s[0]),
                 street = s[1],
                 price = int.Parse(s[3])
             }
            into e//筛选与指定品牌相符的记录：
             where e.brand == m
             group e.price by e.street//按街道分组并找出每个街道价格最高的记录：
            into e
             let max = e.Max()
             orderby max, e.Key//排序
             select max + " " + e.Key)
            .DefaultIfEmpty("Нет");
            File.WriteAllLines(GetString(), r.ToArray(), Encoding.Default);


        }
    }
}
