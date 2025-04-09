#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI7Win21");

    int flag;
    MPI_Initialized(&flag); 
    if (flag == 0)
        return;

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size); 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 

    const int n = size / 2; // 数组大小为总进程数的一半
    double a[n];            // 主进程存储的数据
    int b[n];               // 主进程存储的目标进程的 rank
    double win_buffer = 0.0; // 每个进程的接收缓冲区
    MPI_Win win;             // 定义窗口
    MPI_Group g, g_0;        // 定义进程组

    MPI_Comm_group(MPI_COMM_WORLD, &g); // 获取 MPI_COMM_WORLD 的进程组
    MPI_Win_create(&win_buffer, sizeof(double), sizeof(double), MPI_INFO_NULL, MPI_COMM_WORLD, &win); // 创建窗口

    if (rank == 0) // 主进程
    {
        // 从输入中读取数据和目标进程
        for (int i = 0; i < n; i++)
            pt >> a[i]; // 读取数据到数组 a
        for (int i = 0; i < n; i++)
            pt >> b[i]; // 读取目标进程 rank 到数组 b

        int exclude[1] = { 0 }; // 主进程的 rank 为 0
        MPI_Group_excl(g, 1, exclude, &g_0); // 创建一个新组，排除主进程

        MPI_Win_start(g_0, 0, win); // 开启主动进程组的窗口通信
        for (int i = 0; i < n; i++)
        {
            MPI_Put(&a[i], 1, MPI_DOUBLE, b[i], 0, 1, MPI_DOUBLE, win); // 向目标进程发送数据
        }
        MPI_Win_complete(win); // 完成窗口操作
    }
    else 
    {
        int include[1] = { 0 }; // 主进程的 rank 为 0
        MPI_Group_incl(g, 1, include, &g_0); // 创建一个组，包含主进程

        MPI_Win_post(g_0, 0, win); // 开启被动进程组的窗口通信
        MPI_Win_wait(win);         // 等待数据传输完成
        pt << win_buffer;          // 输出接收到的数据
    }

    // 释放窗口资源
    MPI_Win_free(&win);
}
