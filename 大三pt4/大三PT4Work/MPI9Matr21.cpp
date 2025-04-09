#include "pt4.h"
#include "mpi.h"
#include <cmath>
/*
每个进程中给定两个整数M和P，在主进程中还给定一个大小为M*P的矩阵A
进程数量K是个平方数，K=K0*K0,且M和P是K0的整数
主进程中将矩阵A作为大小为M*P的一维数组输入 MPI_BLOCK_A that contains a M0 × P0 block of the matrix A, where M0 = M/K0, P0 = P/K0
When defining the MPI_BLOCK_A type, use the MPI_Type_vector and MPI_Type_commit functions
Include this definition in a Matr3CreateTypeBlock(m0, p0, p, t) function with the input integer parameters m0, p0, p and the output parameter t of the MPI_Datatype type
the parameters m0 and p0 determine the size of the block, and the parameter p determines the number of columns of the matrix from which this block is extracted
Using the MPI_BLOCK_A datatype, send to each process (in ascending order of ranks of processes, including the master process) the corresponding block of the matrix A in a row-major order of blocks (that is, the first block should be sent to the process 0, the next block in the same row of blocks should be sent to the process 1, and so on).
Sending should be performed using the MPI_Send and MPI_Recv functions; the blocks should be stored in one-dimensional arrays of the size M0·P0. Output the received block in each process.
In the MPICH2 version 1.3, the MPI_Send function call is erroneous if the sending and receiving processes are the same. You may use the MPI_Sendrecv function to send a block to the master process. You may also fill a block in the master process without using tools of the MPI library.
*/
int k; // 总的进程数量
int r; // 当前进程的 rank

int m, p, q;    // 矩阵 A 的大小 (m x p)
int m0, p0, q0; // 块的大小 (m0 x p0)
int k0;         // K0 = sqrt(K)

int *a_, *b_, *c_; // arrays to store matrices in the master process
int *a, *b, *c;    // arrays to store matrix blocks in each process

MPI_Datatype MPI_BLOCK_A; // datatype for the block of the matrix A
MPI_Datatype MPI_BLOCK_B; // datatype for the block of the matrix B
MPI_Datatype MPI_BLOCK_C; // datatype for the block of the matrix C

MPI_Comm MPI_COMM_GRID = MPI_COMM_NULL;
// communicator associated with a two-dimensional Cartesian grid

void Matr3CreateTypeBlock(int m0, int p0, int p, MPI_Datatype *t)
{
    MPI_Type_vector(m0, p0, p, MPI_INT, t);
    MPI_Type_commit(t);
}

void Solve()
{
    Task("MPI9Matr21");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    k = size;
    r = rank;
    k0 = (int)floor(sqrt((double)k) + 0.1);

    // input
    pt >> m >> p;
    Show(m);
    Show(p);

    m0 = m / k0;
    p0 = p / k0;
    a = new int[m0 * p0];

    if (rank == 0)
    {
        a_ = new int[m * p];
        for (int i = 0; i < m * p; ++i)
            pt >> a_[i];
        Matr3CreateTypeBlock(m0, p0, p, &MPI_BLOCK_A);

        int c = 0; // 提前声明 c
        for (int i = 1; i < k; ++i)
        {
            MPI_Send(&a_[c + p0 * (i % k0)], 1, MPI_BLOCK_A, i, 0, MPI_COMM_WORLD);
            if ((i + 1) % k0 == 0)
                c += p * m0;
        }

        // 自发送的部分使用 MPI_Sendrecv
        MPI_Sendrecv(a_, 1, MPI_BLOCK_A, 0, 0, a, m0 * p0, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);

        for (int i = 0; i < m0 * p0; ++i)
            pt << a[i];
    }
    else
    {
        MPI_Recv(a, m0 * p0, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
        for (int i = 0; i < m0 * p0; ++i)
            pt << a[i];
    }

    delete[] a;
}

