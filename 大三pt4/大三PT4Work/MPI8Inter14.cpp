#include "pt4.h"

#include "mpi.h"

void Solve()
{
    Task("MPI8Inter14");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Comm comm, peer, t;
    MPI_Comm_dup(MPI_COMM_WORLD, &peer); // 复制通信器MPI_COMM_WORLD到peer

    int c;
    pt >> c; 
    if (c == 0)
        c = MPI_UNDEFINED; // 设为MPI_UNDEFINED，表示当前进程不参与分组

    if (c == 1)
        MPI_Comm_split(MPI_COMM_WORLD, c, rank, &comm); // 使用rank顺序分组
    else
        MPI_Comm_split(MPI_COMM_WORLD, c, size - rank, &comm); // 使用逆序分组
    if (comm == MPI_COMM_NULL)                                 // 如果进程不在任何新通信器中，则直接输出-1并退出
    {
        pt << -1;
        return;
    }

    int r, lead = 0;
    MPI_Comm_rank(comm, &r); // 获取当前进程在新通信器中的秩
    pt << r;                 // 输出新秩

    if (c == 1)
        lead = size - 1; // 如果分组标志为1，设置leader为最后一个进程

    // 创建互通信器，用于连接两个独立的通信组
    MPI_Intercomm_create(comm, 0, peer, lead, 100, &t);

    int rs;
    MPI_Comm_remote_size(t, &rs); // 获取互通信器中远程组的进程数

    int *a = new int[rs]; // 创建数组a，用于存储从PT4输入读取的数据
    int *b = new int[rs]; // 创建数组b，用于存储通过互通信器接收的数据
    for (int i = 0; i < rs; i++)
        pt >> a[i]; // 从PT4输入读取rs个整数到数组a中

    // 通过互通信器进行全对全数据交换
    MPI_Alltoall(a, 1, MPI_INT, b, 1, MPI_INT, t);

    for (int i = 0; i < rs; i++)
        pt << b[i]; // 将接收到的数据通过PT4输出

    delete[] a; // 释放动态分配的内存
    delete[] b;
}
