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
            int N = GetInt();  

            int[,] matrix = new int[N, N];

            for (int i = 0; i < N; i++)
            {
                string[] input = GetString().Split();
                for (int j = 0; j < N; j++)
                {
                    matrix[i, j] = GetInt();
                }
            }
            List<int> result = new List<int>();
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

                while (row >= 0 && col < N)
                {
                    result.Add(matrix[row, col]);
                    row--;
                    col++;
                }
            }
            Put(string.Join(" ", result));  


        }
    }
}
