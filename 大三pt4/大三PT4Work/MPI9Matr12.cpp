#include "pt4.h"
#include "mpi.h"
#include <cmath>
/*
输入：主进程中给定整数M, P, Q, a matrix A of the size M × P, and a matrix B of the size P × Q
算法要求：使用带状矩阵乘法:将矩阵 A 分为 K 个水平带，将矩阵 B 分为 K 个垂直带（K 为进程数）。
NA = ceil(M / K)，表示 A 每个带的行数。
NB = ceil(Q / K)，表示 B 每个带的列数。
若矩阵行数或列数不足以填充最后一带，需补充零值行或列。
将补零后的 A 和 B 存储为一维数组。
带索引 R 发送至进程 R
矩阵 A 的每个带尺寸为 NA × P
矩阵 B 的每个带尺寸为 P × NB
在每个进程中创建结果矩阵 C 的带，尺寸为 (NA·K) × NB，并用零值初始化。
将所有矩阵带存储为行优先顺序的一维数组。
使用 MPI_Bcast 广播矩阵尺寸，MPI_Scatter 分发 A 的矩阵带
使用 MPI_Send 和 MPI_Recv 分发 B 的矩阵带
*/
int k; 
int r;

int m, p, q;
int na, nb;

int *a_, *b_, *c_;
int *a, *b, *c;

MPI_Datatype MPI_COLS;
MPI_Datatype MPI_BAND_B;

void Matr2ScatterData()
{
    int n = 3;
    int *band = new int[n];

    if (r == 0)
    {
        pt >> m >> p >> q;

        a_ = new int[m * p];
        b_ = new int[p * q];

        for (int i = 0; i < m * p; ++i)
            pt >> a_[i];
        for (int i = 0; i < p * q; ++i)
            pt >> b_[i];

        //计算带宽na和nb
        na = (int)ceil((double(m) / k));
        nb = (int)ceil((double(q) / k));
        
        band[0] = na;
        band[1] = nb;
        band[2] = p;
    }

    MPI_Bcast(band, n, MPI_INT, 0, MPI_COMM_WORLD);
    na = band[0];
    nb = band[1];
    p = band[2];
    delete[] band;

    a = new int[na * p];
    b = new int[p * nb];
    c = new int[na * k * nb];

    for (int i = 0; i < na * p; ++i)
        a[i] = 0;
    for (int i = 0; i < p * nb; ++i)
        b[i] = 0;
    for (int i = 0; i < na * k * nb; ++i)
        c[i] = 0;

    int *t_a = new int[na * p * k];
    for (int i = 0; i < na * p * k; ++i)
        t_a[i] = 0;

    int *t_b = new int[p * nb * k];
    for (int i = 0; i < p * nb * k; ++i)
        t_b[i] = 0;

    if (r == 0)
    {
        int max_a = m * p;
        int total_a = na * p * k;
        for (int i = 0; i < total_a; ++i)
        {
            if (i < max_a)
                t_a[i] = a_[i];
            else
                t_a[i] = 0;
        }

        int idx = 0;
        for (int row = 0; row < p; ++row)
        {
            for (int block = 0; block < k; ++block)
            {
                for (int local_col = 0; local_col < nb; ++local_col)
                {
                    int block_col = block * nb + local_col;
                    if (block_col < q)
                        t_b[idx] = b_[row * q + block_col];
                    else
                        t_b[idx] = 0;
                    idx++;
                }
            }
        }
    }

    MPI_Scatter(
        t_a,
        na * p,
        MPI_INT,
        a,
        na * p,
        MPI_INT,
        0,
        MPI_COMM_WORLD);

    MPI_Type_vector(
        p,
        nb,
        nb * k,
        MPI_INT,
        &MPI_BAND_B);
    MPI_Type_commit(&MPI_BAND_B);

    if (r == 0)
    {
        MPI_Sendrecv(
            t_b,
            1,
            MPI_BAND_B,
            0, 0,
            b,
            p * nb,
            MPI_INT,
            0, 0,
            MPI_COMM_WORLD,
            MPI_STATUSES_IGNORE);

        for (int i_proc = 1; i_proc < k; ++i_proc)
        {
            MPI_Send(
                t_b + (i_proc * nb),
                1,
                MPI_BAND_B,
                i_proc,
                0,
                MPI_COMM_WORLD);
        }
    }
    else
    {
        MPI_Recv(
            b,
            p * nb,
            MPI_INT,
            0, 0,
            MPI_COMM_WORLD,
            MPI_STATUSES_IGNORE);
    }

    delete[] t_a;
    delete[] t_b;
}

void Solve()
{
    Task("MPI9Matr12");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;

    MPI_Comm_size(MPI_COMM_WORLD, &k);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);

    Matr2ScatterData();

    pt << na << p << nb;

    for (int a_idx = 0; a_idx < na * p; ++a_idx)
    {
        pt << a[a_idx];
        Show("a=", a[a_idx]);
    }

    for (int b_idx = 0; b_idx < p * nb; ++b_idx)
    {
        pt << b[b_idx];
    }

    for (int c_idx = 0; c_idx < na * k * nb; ++c_idx)
    {
        pt << c[c_idx];
    }

    // Optionally:
    delete[] a; delete[] b; delete[] c;
}
