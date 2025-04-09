#include "pt4taskmakerX.h"
#include<math.h>

DefineGroupName;

void __stdcall inittaskgroup()
{
  pt::NewGroup("TimD", "", "qwqfsdf13dfttd");
}

DefineTask(Task1)
{
  // description of the task
  pt::NewTask(R"(\S1313.\s The first input line contains the single integer 
  N (1 <= N <= 15).It is followed by N lines,each containing N positive 
  integers not exceeding 15 divided by spaces. It is the image outputting 
  by the usual video card.You are to write the program that outputs the 
  sequence for input into the new monitor.  Pixels are numbered from the 
  upper-left corner of the screen diagonally from left ot right and bottom-up. 
)");

  // input
  int n = pt::Random(1, 15);
  vector<vector<int>> matrix(n, vector<int>(n));
  int number = 1;
  pt::Data("N = ", n);
  pt::SetWidth(3);
  for (int sum = 0; sum < 2 * n - 1; sum++)
  {
    for (int row = sum < n ? sum : n - 1; row >= 0; row--)
    {
      int col = sum - row;
      if (row < n && col < n)
      {
        matrix[row][col] = number++;
      }
    }
  }
  // for (int row = 0; row < n; row++)
  //   pt::Data(matrix[row]);
  for(const auto&row:matrix)
    pt::Data(row);

  // solve the problem,go through the matrix
  vector<int> result;
  for (int d = 0; d < 2 * n - 1; d++)
  {
    int row, col;
    if (d < n)
    {
      row = d;
      col = 0;
    }
    else
    {
      row = n - 1;
      col = d - n + 1;
    }

    // output
    while (row >= 0 && col < n)
    {
      result.push_back(matrix[row][col]);
      row--;
      col++;
    }
  }
  pt::SetWidth(2);
  pt::Res(result);
  pt::SetTestCount(5);
}

DefineTask(Task2)
{
  // description of the task
  pt::NewTask(R"(\S1319.\s The input consists of the only one integer N (1 <= N <= 15),
  which is the size of the square.You are to write a program that 
  the label with number 1 should be in the upper right corner
  and other numbers should be arranged along the diagonals from the top to
  the bottom. The label with the last number (N*N) should be in the lower 
  left corner.
 
)");

  // input
  int n = pt::Random(1, 15);
  pt::Data("N = ", n);
  vector<vector<int>> matrix(n, vector<int>(n));
  int num = 1;
  for (int col = n - 1; col >= 0; col--)
  {
    int x = 0;
    int y = col;
    while (x < n && y < n)
    {
      matrix[x][y] = num++;
      x++;
      y++;
    }
  }

  for (int row = 1; row < n; row++)
  {
    int x = row;
    int y = 0;
    while (x < n && y < n)
    {
      matrix[x][y] = num++;
      x++;
      y++;
    }
  }
  pt::SetTestCount(5);
  for (int row = 0; row < n; row++)
    pt::Res(matrix[row]);
}

DefineTask(Task3)
{
  // description of the task
  pt::NewTask(R"(\S1327.\s The first line contains an integer A. The second 
  line contains an integer B.The output should contain one number - the amount
   of fuses that will be blown by Janus in the interval  from day A until day B
   (Janus only burns out wires on odd-numbered days)(1<=A,B<=1000).
)");

  // input
  int a = pt::Random(1, 1000);
  int b = pt::Random(a, 1000);
  pt::Data("A = ", a);
  pt::Data("B = ", b);

  pt::SetTestCount(5);
  pt::Res("", (b + 1) / 2 - a / 2);
}

DefineTask(Task4)
{
  // description of the task
  pt::NewTask(R"(\S1349.\s Input an integer n(0 <= n <= 100),find three 
  different integers (a, b and c) such that a^n + b^n = c^n, 1 <= a, b, c <= 100. 
  If there are several solutions you should output the one where a is minimal. 
  If there are several solutions with the minimal a you should output the one 
  with minimal b, and so on. Output -1 if there is no solution.

)");

  // input
  int n = pt::Random(1, 100);
  int a = -1, b = -1, c = -1;

  pt::Data("N = ", n);

  // ??????? a, b, c
  for (int i = 1; i <= 100; ++i)
  {
    for (int j = i + 1; j <= 100; ++j)
    { // j ???? i???? a ? b ??
      for (int k = 1; k <= 100; ++k)
      {
        // ?? c ??? a ? b
        if (k != i && k != j)
        {
          // ?? a^n + b^n = c^n
          if (pow(i, n) + pow(j, n) == pow(k, n))
          {
            // ???????????
            a = i;
            b = j;
            c = k;
          }
        }
      }
    }
  }

  pt::SetTestCount(5);
  pt::Res("", a);
  pt::Res("", b);
  pt::Res("", c);


}