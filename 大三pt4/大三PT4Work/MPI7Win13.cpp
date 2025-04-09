#include "pt4.h"
#include "mpi.h"

/*
每个进程给出三个整数 N1、N2、N3;
每个给定的整数都在 0 到 K − 1 的范围内，其中 K 是进程数（每个进程中某些整数的值可能重合）。
此外，在每个进程中都给出了 R + 1 个实数的数组 A，其中 R 是进程的秩 （0，...，K − 1）。
创建一个包含所有进程中数组 A 的访问窗口。
在每个进程中使用 MPI_Accumulate 函数的三次调用，
将整数 R + 1 添加到进程 N1、N2、N3 中给定的数组 A 的所有元素中，
其中 R 是调用 MPI_Accumulate 函数的进程的秩。
如果某些整数 N1、N2、N3 在进程 R 中重合，则应将数字 R + 1 添加到相应数组的元素中多次。
在每个进程中输出更改的数组 A。
*/

void Solve()
{
    Task("MPI7Win13"); 
    int flag;
    MPI_Initialized(&flag); 
    if (flag == 0)
        return; 
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size); 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 

    int n[3];
    for (int i = 0; i < 3; ++i)
        pt >> n[i]; // 从输入中读取三个整数 N1、N2、N3
    double a[rank + 1];
    for (int i = 0; i < rank + 1; ++i)
        pt >> a[i]; // 从输入中读取 R + 1 个实数，存入数组 A
    double b[size];
    for (int i = 0; i < size; ++i)
        b[i] = rank + 1; // 初始化数组 B，每个元素为 R + 1，其中 R 是当前进程的秩

    int dbl_sz;
    MPI_Type_size(MPI_DOUBLE, &dbl_sz); // 获取数据类型 MPI_DOUBLE 的字节大小
    MPI_Win win;
    MPI_Win_create(a, (rank + 1) * dbl_sz, dbl_sz, MPI_INFO_NULL, MPI_COMM_WORLD, &win);
    // 创建 MPI 窗口，允许进程访问数组 A

    MPI_Win_fence(0, win); // 设置同步点，开始窗口访问
    for (int i = 0; i < 3; ++i)
        MPI_Accumulate(b, n[i] + 1, MPI_DOUBLE, n[i], 0, n[i] + 1,
                       MPI_DOUBLE, MPI_SUM, win);
    // 使用 MPI_Accumulate 函数向目标进程的数组 A 添加数值：
    // - b 是要添加的值
    // - n[i] 是目标进程的秩
    // - 0 是目标进程内的起始偏移
    // - n[i] + 1 是数据块的大小

    MPI_Win_fence(0, win); // 设置同步点，结束窗口访问
    for (int i = 0; i < rank + 1; ++i)
        pt << a[i]; 

    MPI_Win_free(&win); 
}
