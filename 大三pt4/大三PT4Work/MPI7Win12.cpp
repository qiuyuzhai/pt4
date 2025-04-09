#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI7Win12");
    int flag;
    MPI_Initialized(&flag);
    if (!flag)
        return;

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int K = size;
    int N = K / 2; // 偶数数量=奇数数量

    //输入
    int a[10];//最好用常数（10）定义数组
    for (int i = 0; i < N; ++i)
        pt >> a[i];

    MPI_Win win;
    //偶数编号的进程（例如进程 0, 2, 4 等）会创建一个访问窗口，窗口大小为 N * sizeof(int)，这表示该进程将自己的数组 a 中的 N 个整数公开，其他进程可以访问这个数组中的数据。
    MPI_Win_create(rank % 2 == 0 ? a : nullptr,
                   N * sizeof(int),
                   sizeof(int),
                   MPI_INFO_NULL,
                   MPI_COMM_WORLD,
                   &win);

    int b[10];
    MPI_Win_fence(0, win); // 第一次同步

    if (rank % 2 != 0)
    {
        //从偶数编号进程获取数据
        for (int i = 0; i < N; ++i)
        {
            MPI_Get(&b[i], 1, MPI_INT, i*2, (rank-1)/2, 1, MPI_INT, win);//从第i*2进程的第(rank-1)/2的起始读取一个数
        }
    }

    MPI_Win_fence(0, win);

    //奇数编号进程将获取的数据加到自己的数组a中
    if (rank % 2 != 0)
    {
        for (int i = 0; i < N; i++)
        {
            Show(b[i]);
            a[i] += b[i];
            pt<<a[i];
        }

        //输出奇数编号进程修改后的数组a
        // for (int i = 0; i < N; i++)
        //     pt << a[i];
    }

    MPI_Win_free(&win);
    
}
