#include "pt4.h"
#include "mpi.h"
/*
进程数 K 是 3 的倍数。
在秩为 3N （N = 0， ...， K/3 − 1） 的过程中给出了一个 3 个实数的数组 A。
在给定此数组的所有进程中创建一个包含数组 A 的访问窗口。
在秩 3N + 1 和 3N + 2 （N = 0， ...， K/3 − 1） 的进程中，使用 MPI_Get 函数的一次调用，
分别从进程 3N 接收并输出一个元素 A0 和两个元素 A1、A2
（即进程 1 应输出从进程 0 接收的元素 A0， 进程 2 应输出从进程 0 接收的元素 A1 和 A2，进程 4 应输出从进程 3 接收的元素 A0，依此类推）。
在 rank 3N 的进程中使用 MPI_Win_post 和 MPI_Win_wait 同步函数，在其他进程中使用 MPI_Win_start 和 MPI_Win_complete 同步函数。
*/
void Solve()
{
    Task("MPI7Win20");
    int flag;
    MPI_Initialized(&flag); 
    if (flag == 0)
        return;

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size); 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 

    double a[3];
    if (rank % 3 == 0) 
    {
        for (int i = 0; i < 3; i++)
            pt >> a[i]; 
    }

    int dbl_sz;
    MPI_Type_size(MPI_DOUBLE, &dbl_sz); // 获取 double 类型的大小
    int win_sz = rank % 3 == 0 ? 3 * dbl_sz : 0; // 计算窗口大小，如果是 3 的倍数则为 3 * dbl_sz，否则为 0

    MPI_Win win;
    MPI_Win_create(a, win_sz, dbl_sz, MPI_INFO_NULL, MPI_COMM_WORLD, &win); // 创建窗口

    int n = size / 3; // 多少组
    int len = rank % 3; // 当前进程在组中的位置
    int ranks[n]; // 存储组内 rank 的数组
    for (int i = 0; i < n; i++)
        ranks[i] = 3 * i; // 仅选择 3 的倍数的进程

    double b[len]; // 动态分配数组，用于存储获取的值

    MPI_Group g0, g;
    MPI_Comm_group(MPI_COMM_WORLD, &g0); // 获取全体进程的组 g0

    if (rank % 3 == 1 || rank % 3 == 2) // 如果进程 rank 是 1 或 2
    {
        MPI_Group_incl(g0, n, ranks, &g); // 创建子组 g，包含 3 的倍数的进程
        MPI_Win_start(g, 0, win); // 开始访问窗口
        MPI_Get(b, len, MPI_DOUBLE, rank - len, len - 1, len, MPI_DOUBLE, win); // 从目标进程中获取数据
        MPI_Win_complete(win); // 结束访问窗口
        for (int i = 0; i < len; i++)
            pt << b[i]; // 输出获取的值
    }
    else // 如果进程 rank 是 3 的倍数
    {
        MPI_Group_excl(g0, n, ranks, &g); // 创建子组 g，排除 3 的倍数的进程
        MPI_Win_post(g, 0, win); // 开始提供数据
        MPI_Win_wait(win); // 等待完成
    }

    
}
