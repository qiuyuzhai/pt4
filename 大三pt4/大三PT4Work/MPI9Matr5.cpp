#include "pt4.h"
#include "mpi.h"
#include <cmath>

/*
在每个进程中给定整数 NA、P、NB、Q 以及填充了矩阵 A、B、C 对应带数据的一维数组
（因此，给定的数据与在 MPI9Matr2 任务中获得的结果相同）。
此外，每个进程中还给定一个相同的数字 L。L 的值在 3 到 K 之间，其中 K 是进程数，表示带算法的步骤数。
在一个循环中，使用参数 I（I = 0, …, L − 1）调用函数 Matr1Calc(I)（参见上一任务），执行带算法的前 L 步，并输出每个进程中带 CR 和 BR 的新内容。在 Solve 函数中执行数据的输入和输出。

备注：如果 L 的值等于 K，则带 CR 将包含矩阵 AB 最终乘积的相应部分。
*/

int k; // number of processes
int r; // rank of the current process

int m, p, q; // sizes of the given matrices
int na, nb;  // sizes of the matrix bands

int *a_, *b_, *c_; // arrays to store matrices in the master process
int *a, *b, *c;    // arrays to store matrix bands in each process

int LineCalc(int a_idx, int b_idx, int step)
{
    int n = 0;
    int st = (step + r) * nb;
    if (st >= nb * k)
    {
        st = st - (nb * k);
        st = (st / nb) * nb;
    }
    for (int i = 0; i < nb; i++)
    {
        if (st + i >= p)
        {
            break;
        }
        n = n + a[p * a_idx + st + i] * b[q * i + b_idx];
    }
    return n;
}

//执行带算法的计算
void Matr1Calc(int step)
{
    MPI_Status st;
    int dest;
    int sz_a = na * p,
        sz_b = nb * q,
        sz_c = na * q;
    for (int i = 0; i < na; i++)
    {
        for (int j = 0; j < q; j++)
        {
            c[q * i + j] = c[q * i + j] + LineCalc(i, j, step);
        }
    }
    if (r == 0)
        dest = k - 1;
    else
        dest = (r - 1) % k;
    MPI_Sendrecv_replace(b, sz_b, MPI_INT, dest, 0, (r + 1) % k, 0, MPI_COMM_WORLD, &st);
}

void Solve()
{
    Task("MPI9Matr5");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    k = size;
    r = rank;
    int m;
    pt >> na >> p >> nb >> q;
    a = new int[na * p];
    b = new int[nb * q];
    c = new int[na * q];
    for (int i = 0; i < na * p; i++)
        pt >> a[i];

    for (int i = 0; i < nb * q; i++)

        pt >> b[i];

    for (int i = 0; i < na * q; i++)

        pt >> c[i];

    pt >> m;
    for (int i = 0; i < m; i++)

        Matr1Calc(i);

    int i = 0;
    int j = 0;
    while (j < na * q)
    {
        pt << c[j];
        j++;
    }
    while (i < nb * q)
    {
        pt << b[i];
        i++;
    }
    delete[] a;
    delete[] b;
    delete[] c;
}
