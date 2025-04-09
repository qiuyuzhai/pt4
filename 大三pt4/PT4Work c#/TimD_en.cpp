#include "pt4taskmakerX.h"

DefineGroupName;

void __stdcall inittaskgroup()
{
  pt::NewGroup("TimD", "", "qwqfsdf13dfttd");
}

DefineTask(Task1)
{
  //description of the task
  pt::NewTask(R"(\S1313.\s Input an integer N(1 <= N <= 100)
  to form an N-dimensional square matrix.Number the matrices 
  diagonally from left to right and bottom to top, starting 
  from the top left corner, and finally output the matrix.  
)");

  //input 
  int n = pt::Random(1, 9);
    vector<vector<int>> matrix(n, vector<int>(n)); 
    int number = 1; 

    for (int sum = 0; sum < 2 * n - 1; sum++) {
        for (int row = 0; row <= sum; row++) {
            int col = sum - row;
            if (row < n && col < n) {
                matrix[row][col] = number++; 
            }
        }
    }

    pt::Data("N = ",n); 

    for (int i = 0; i < n; i++) {
        string line;
        for (int j = 0; j < n; j++) {
            line += to_string(matrix[i][j]) + " "; 
        }
        pt::Data("",line); 
    }


    //output
    string line; 
    for (int i = 1; i <= n*n; i++) {
        line += to_string(i) + " "; 
    }

    pt::Res("",line ); 

  pt::SetTestCount(5);
}

