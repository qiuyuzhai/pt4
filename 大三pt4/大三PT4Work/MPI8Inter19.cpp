#include "pt4.h"
#include "mpi.h"
/*在主进程中给出一个 2K 个整数的数组 A，其中 K 是进程数。
使用带有第一个参数 “ptprj.exe” 的 MPI_Comm_spawn 函数的一次调用，创建 K 个新流程。
使用与新进程连接的 inter-communicator 的 MPI_Intercomm_merge 功能，创建一个包含初始进程和新进程的新 intra-communicator。
新 intra-communicator 中的进程顺序应如下：
初始进程，然后是新进程（要指定此顺序，请使用 MPI_Intercomm_merge 函数的参数 high 的适当值）。
使用新内部通信器的 MPI_Scatter 集合函数，将数组 A 的元素 A[R] 发送到此内部通信器中的 rank R 进程 （R = 0， ...， 2K − 1）。
在结果部分输出初始进程中收到的数字，使用 Show 函数在调试部分输出新进程中收到的数字。
然后，使用这个 intra-communicator 中的 MPI_Reduce 集合函数，找到并输出这个 inter-communicator 中 rank 1 过程中所有数字的和。
*/
void Solve()
{
    Task("MPI8Inter19");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // 定义并初始化需要的变量
    int A[2 * size], a, root, h, r, sum;
    MPI_Comm t0, t;
    MPI_Comm_get_parent(&t0); // 获取父进程的通信器

    // for(int i=0;i<size;i++)
    //    MPI_Comm_spawn("ptprj.exe", NULL, size, MPI_INFO_NULL, 0, MPI_COMM_WORLD, &t0, MPI_ERRCODES_IGNORE);

    // 如果当前进程是根进程
    if (t0 == MPI_COMM_NULL)
    {

        // 根进程读取 2 * size 个整数并存入数组 A
        if (rank == 0)
        {
            for (int i = 0; i < 2 * size; i++)
                pt >> A[i];
            // Show(A[i]);
        }

        // 使用 MPI_Comm_spawn 创建 size 个新的进程
        MPI_Comm_spawn("ptprj.exe", NULL, size, MPI_INFO_NULL, 0, MPI_COMM_WORLD, &t0, MPI_ERRCODES_IGNORE);

        // 设置根进程标记
        root = 0;
        h = 0; // 设定合并通信器时的标志值（0表示父进程组）
    }
    else
    {
        root = MPI_ROOT; // 非根进程的标记
        Show(root);

        h = 6; // 设定合并通信器时的标志值
    }

    // 合并父进程和子进程的通信器，得到新的通信器 new_t0
    MPI_Intercomm_merge(t0, h, &t);
    MPI_Comm_rank(t, &r); // 获取当前进程在新通信器中的 rank

    // 使用 MPI_Scatter 将数组 A 中的数据分发给新进程
    MPI_Scatter(A, 1, MPI_INT, &a, 1, MPI_INT, 0, t);

    // 根据进程的 rank 判断输出的方式
    if (r < size) // 如果是前 half 的进程，输出数据
        pt << a;

    // 使用 MPI_Reduce 进行归约操作，将所有进程的数据相加（计算 sum）
    MPI_Reduce(&a, &sum, 1, MPI_INT, MPI_SUM, 1, t);
    Show(sum);

    // 如果当前进程是 rank 1，输出归约后的结果
    if (rank == 1)
        pt << sum;
}
