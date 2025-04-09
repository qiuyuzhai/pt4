#include "pt4.h"
using namespace std;

void Solve()
{
    Task("TimD1");
    int N;
    pt >> N;  // 读取矩阵的大小

    // 创建N x N矩阵
    vector<vector<int>> matrix(N, vector<int>(N));

    // 输入矩阵元素
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            pt >> matrix[i][j];
        }
    }

    // 遍历对角线
  vector<int> result;
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

    // output
    while (row >= 0 && col < N)
    {
      result.push_back(matrix[row][col]);
      row--;
      col++;
    }
  }
  pt<<result;

}
