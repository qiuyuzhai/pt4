#include "pt4.h"

#include "mpi.h"
/*每个进程中都给出了一个 K 个实数的数组 A，其中 K 是进程数。
使用带有第一个参数 “ptprj.exe” 的 MPI_Comm_spawn 函数的一次调用，创建 K 个新流程。
使用 MPI_Reduce_scatter_block 集合函数，将给定数组的元素 A[R] 的最大值发送到秩 R 的新进程 （R = 0， ...， K − 1）。
在每个新进程中使用 Show 函数在 debug 部分中输出收到的最大值。
然后，使用 MPI_Send 和 MPI_Recv 函数，
将 R 级新进程 （R = 0， ...， K − 1） 的最大值发送到相同等级的初始进程，并输出初始进程中接收到的数字。
*/
void Solve()
{
    Task("MPI8Inter16");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int root;
    double a[size], max;

    // 定义一个新的通信器 t
    MPI_Comm t;

    // 获取父进程的通信器
    MPI_Comm_get_parent(&t);

    // 如果当前进程是根进程（即没有父进程），则创建新的进程
    if (t != MPI_COMM_NULL)
    {
        // 如果当前进程是子进程，则根进程设置为 MPI_ROOT
        root = MPI_ROOT;
    }
    else
    {

        // 使用 MPI_Comm_spawn 创建新的进程，进程数为 size
        MPI_Comm_spawn("ptprj.exe", NULL, size, MPI_INFO_NULL, 0, MPI_COMM_WORLD, &t, MPI_ERRCODES_IGNORE);

        // 从输入流中读取每个进程的数组 A 的元素
        for (int i = 0; i < size; i++)
            pt >> a[i];

        // 设置根进程为当前进程
        root = rank;
    }

    // 使用 MPI_Reduce_scatter_block 进行归约和分发操作，将 A 中的最大值计算并发送到各进程
    MPI_Reduce_scatter_block(a, &max, 1, MPI_DOUBLE, MPI_MAX, t);

    // 如果当前进程是根进程
    if (root == MPI_ROOT)
    {
        // 调试输出根进程接收到的最大值
        // Show(max);

        // 根进程将最大值发送给每个子进程
        MPI_Send(&max, 1, MPI_DOUBLE, rank, 0, t);
    }
    else
    {
        // 如果是子进程，接收根进程发送的最大值
        MPI_Recv(&max, 1, MPI_DOUBLE, rank, 0, t, MPI_STATUS_IGNORE);

        // 将最大值输出到调试流中
        pt << max;
    }
}
