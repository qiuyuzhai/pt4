#include "pt4.h" 
#include "mpi.h"

void Solve()
{
    Task("MPI8Inter10");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return; 
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    //input
    int c;
    pt >> c;

    MPI_Comm p;
    // 复制全局通信器 MPI_COMM_WORLD，创建一个新的通信器 p
    MPI_Comm_dup(MPI_COMM_WORLD, &p);



    MPI_Comm comm;
    if (c == 0)
    {
        // 如果 c 为 0，则当前进程不参与任何子通信器的创建
        MPI_Comm_split(MPI_COMM_WORLD, MPI_UNDEFINED, rank, &comm);
        pt << -1; // 输出 -1 表示未加入任何通信器
        return;
    }
    else
    {
        // 按照 c 的值将进程划分为两个子通信器
        MPI_Comm_split(MPI_COMM_WORLD, c, rank, &comm);
    }

    int r;
    // 获取当前进程在新子通信器 comm 中的 rank
    MPI_Comm_rank(comm, &r);
    pt << r; // 输出该 rank 值

    MPI_Comm t;
    int lead = 0;
    if (rank == 0)
    {
        // 在 rank 为 0 的进程中设置第二组的领导者进程
        lead = size / 2; // 领导者是全局通信器中 rank 为 size/2 的进程
    }

    // 创建一个互通信器 t，将两个子通信器连接起来
    MPI_Intercomm_create(comm, 0, p, lead, 100, &t);

    int r1, r2;
    pt >> r1 >> r2;

    int x[3];
    if (c == 1)
    {
        // 如果当前进程属于第一组（c == 1）
        if (r == r1)
        {
            // 如果当前进程是第一组的选定进程 r1，则从输入读取数据
            pt >> x[0] >> x[1] >> x[2];
            // 将读取的数组 x 广播给第二组的所有进程
            MPI_Bcast(x, 3, MPI_INT, MPI_ROOT, t);
        }
        // 广播空消息到第二组
        MPI_Bcast(x, 3, MPI_INT, MPI_PROC_NULL, t);
        // 接收来自第二组选定进程 r2 的数据
        MPI_Bcast(x, 3, MPI_INT, r2, t);
    }
    else
    {
        // 如果当前进程属于第二组（c == 2）
        if (r == r2)
        {
            // 如果当前进程是第二组的选定进程 r2，则从输入读取数据
            pt >> x[0] >> x[1] >> x[2];
            // 将读取的数组 x 广播给第一组的所有进程
            MPI_Bcast(x, 3, MPI_INT, MPI_ROOT, t);
        }
        // 广播空消息到第一组
        MPI_Bcast(x, 3, MPI_INT, MPI_PROC_NULL, t);
        // 接收来自第一组选定进程 r1 的数据
        MPI_Bcast(x, 3, MPI_INT, r1, t);
    }

    // 输出接收到的数组 x 的内容
    pt << x[0] << x[1] << x[2];
}
