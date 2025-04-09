#include "pt4.h"

#include "mpi.h"

void Solve()
{
    Task("MPI8Inter18");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int *A = new int[size / 2], Amin, Amax, root, h, new_rank, final_min, final_max;
    MPI_Comm t, t1;
    MPI_Comm_get_parent(&t);

    // 如果当前进程是根进程（即没有父进程），则创建新的进程
    if (t == MPI_COMM_NULL)
    {
        // 使用 MPI_Comm_spawn 创建多个新的进程，进程数为 size
        MPI_Comm_spawn("ptprj.exe", NULL, size, MPI_INFO_NULL, 0, MPI_COMM_WORLD, &t, MPI_ERRCODES_IGNORE);

        // 根进程读取每个进程的数组 A 的元素
        if (rank == 0)
        {
            for (int i = 0; i < size / 2; i++)
                pt >> A[i];
        }

        root = 0;
        h = 0;
    }
    else
    {
        root = MPI_ROOT;
        h = 1;
    }

    // 合并父进程和子进程的通信器
    MPI_Intercomm_merge(t, h, &t1);
    MPI_Comm_rank(new_t, &new_rank);

    // 使用 MPI_Scatter 将 A 数组的数据分发给每个新进程
    MPI_Scatter(A, 1, MPI_INT, &Amin, 1, MPI_INT, 0, t1);

    // 对偶数组的进程，寻找最小值；对奇数组的进程，寻找最大值
    if (rank % 2 == 0)
    { // 偶数组进程
        MPI_Reduce_scatter_block(&Amin, &Amin, 1, MPI_INT, MPI_MIN, t1);
        if (new_rank < size / 2)
            Show(Amin);
        MPI_Send(&Amin, 1, MPI_INT, new_rank, 0, t1);
    }
    else
    { // 奇数组进程
        MPI_Reduce_scatter_block(&Amax, &Amax, 1, MPI_INT, MPI_MAX, t1);
        if (new_rank < size / 2)
            Show(Amax);
        MPI_Send(&Amax, 1, MPI_INT, new_rank, 0, t1);
    }

    // 计算最小值和最大值的汇总
    if (rank == 0)
    {
        MPI_Reduce(&Amin, &final_min, 1, MPI_INT, MPI_MIN, 0, t1);
        Show(final_min);
    }

    if (rank == 1)
    {
        MPI_Reduce(&Amax, &final_max, 1, MPI_INT, MPI_MAX, 1, t1);
        Show(final_max);
    }
}
