// File: "LinqObj30"
/*初始序列包含居住在一栋 9 层楼 144 个公寓的公用事业债务人的信息：
< 名字> < 债务> < 欠款> < 公寓编号>。
债务以小数表示（整数部分 - 卢布，小数部分 - 戈比）。每个入口的每层有 4 个单元。
在这栋楼的 9 层楼中，找出债务最低的租户，并输出其相关信息：单元号、楼层号、租户姓氏、债务（输出两个小数符号）。
考虑到初始数据集中的所有债务都有不同的值。每个债务人的信息都应显示在单独一行中，并按单元号递增排序。如果某层没有债务人，则不应输出该层的数据。*/

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
            Task("LinqObj30");
            var r =
            (from line in File.ReadLines(GetString(), Encoding.Default)
             let parts = line.Split()
             select new
             {
                 LastName = parts[0],                     // 姓名
                 Debt = decimal.Parse(parts[1]),          // 债务（卢布和戈比）
                 ApartmentNumber = int.Parse(parts[2])    // 公寓编号
             }
            into x
             group x by (x.ApartmentNumber - 1) % 36 / 4 + 1 into g   // 按照楼层号分组，每层有 4 个公寓，每个入口有 36 个公寓
             let minDebtTenant = g.OrderBy(x => x.Debt).First()       // 找出每层中债务最低的租户
             orderby minDebtTenant.ApartmentNumber                    // 按公寓编号升序排序
             select $"{minDebtTenant.ApartmentNumber} {g.Key} {minDebtTenant.LastName} {minDebtTenant.Debt:F2}")
            .DefaultIfEmpty("Нет");

            // 将结果写入文件
            File.WriteAllLines(GetString(), r.ToArray(), Encoding.Default);

        }
    }
    }

