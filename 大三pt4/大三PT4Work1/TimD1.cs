// File: "TimD1"
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
            Task("TimD1");
            int N = GetInt();  // 读取矩阵的大小

            // 创建N x N矩阵
            int[,] matrix = new int[N, N];

            // 输入矩阵元素
            for (int i = 0; i < N; i++)
            {
                //string[] input = GetString().Split();
                for (int j = 0; j < N; j++)
                {
                    matrix[i, j] = GetInt();
                }
            }
            List<int> result = new List<int>();
            // 遍历对角线
            for (int d = 0; d < 2 * N - 1; d++)
            {
                int row, col;
                if (d < N)
                {
                    row = d;
                    col = 0;
                }
                else
                {
                    row = N - 1;
                    col = d - N + 1;
                }

                // 输出当前对角线上的所有元素
                while (row >= 0 && col < N)
                {
                    result.Add(matrix[row, col]);
                    row--;
                    col++;
                }
            }
            Put(string.Join(" ", result));  // 输出结果换行


        }
    }
}
