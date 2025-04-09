#include "pt4.h"
using namespace std;

void Solve()
{
    Task("TimD2");
    int N;
    pt>>N;
    vector<vector<int>> matrix(N, vector<int>(N));
    // 填充矩阵
    int num = 1;
    for (int col = N - 1; col >= 0; col--) {  // 从右上角开始
        int x = 0; // 行索引
        int y = col; // 列索引
        while (x < N && y < N) {
            matrix[x][y] = num++;
            x++;
            y++;
        }
    }    
    for (int row = 1; row < N; row++) {  // 从第二行开始，左下角
        int x = row; // 行索引
        int y = 0; // 列索引
        while (x < N && y < N) {
            matrix[x][y] = num++;
            x++;
            y++;
        }
    }

    // 输出矩阵
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            pt << matrix[i][j] ;
        }
    }

}

