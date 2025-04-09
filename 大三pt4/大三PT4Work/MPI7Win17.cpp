#include "pt4.h"
#include "mpi.h"
/*
每个进程给定了一个矩阵 A 的一行和一个实数 B。假设矩阵 A 是一个 K 阶矩阵（K 是进程数），
每个进程包含矩阵 A 中的第 r 行。我们在所有进程中创建一个包含矩阵 A 的访问窗口。
在每个进程中，我们需要进行以下操作：
1. 根据给定的 B，将上一行中大于 B 的元素替换为 B（按进程顺序进行）。
2. 使用 MPI_Accumulate 函数，将每个进程的第一列元素加到所有行的第 r 列中（第0列不参与）。
3. 输出变换后的矩阵行。
注意：每个进程需要调用 MPI_Win_fence 三次进行同步。
*/

void Solve()
{
    Task("MPI7Win17");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int k = size; // k 为进程数，即矩阵的阶数

    // 创建矩阵 A 的一行
    double a[k];
    for (int i = 0; i < k; i++)
        pt >> a[i]; // 输入第 r 行的矩阵元素

    double b;
    pt >> b; // 输入 b 实数

    // 获取每个元素的大小
    int dbl_sz;
    MPI_Type_size(MPI_DOUBLE, &dbl_sz); // 获取 double 类型的大小

    // 创建窗口
    MPI_Win win;
    MPI_Win_create(a, k * dbl_sz, dbl_sz, MPI_INFO_NULL, MPI_COMM_WORLD, &win); // 创建包含矩阵行的窗口

    // 第一阶段：修改行元素大于 b 的元素为 b，使用上一行的数据
    MPI_Win_fence(0, win); // 第一次同步

    double prev_row[k];                 // 用于存储前一个进程的行数据
    int prev_rank = (rank - 1 + k) % k; // 环形顺序
    MPI_Get(prev_row, k, MPI_DOUBLE, prev_rank, 0, k, MPI_DOUBLE, win);

    MPI_Win_fence(0, win); // 第二次同步

    // 替换当前行中大于 b 的元素
    for (int i = 0; i < k; i++)
    {
        if (prev_row[i] > b)
        {
            prev_row[i] = b;
        }
    }
    // 将修改后的 `prev_row` 写回上一行所在的进程
    MPI_Put(prev_row, k, MPI_DOUBLE, prev_rank, 0, k, MPI_DOUBLE, win);

    MPI_Win_fence(0, win); // 第三次同步

    // for(int i=0;i<k;i++)已经验证过行变化是对的
    //    Show(a[i]);

    // 第二阶段：在每个从属进程中使用 MPI_Accumulate 函数的 K 次调用

    // 用于存储每个进程的第一个元素
    double first_elements[k];
    // 每个进程将自己的第一个元素（a[0]）存入 first_elements 数组
    MPI_Gather(&a[0], 1, MPI_DOUBLE, first_elements, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    MPI_Win_fence(0, win); // 第四次同步

    // 如果是进程0，则进行累加操作，否则直接跳过
    if (rank == 0)
    {
        for (int i = 1; i < k; i++) // 从进程1到k-1
        {
            for (int j = 0; j < k; j++) // 对每个目标进程
            {
                // 将 first_elements[i] 累加到第 i 列
                MPI_Accumulate(&first_elements[i], 1, MPI_DOUBLE, j, i, 1, MPI_DOUBLE, MPI_SUM, win);
            }
        }
    }

    MPI_Win_fence(0, win); // 第五次同步
    // 输出当前进程行
    for (int i = 0; i < k; i++)
        pt << a[i];
    MPI_Win_free(&win);
}
