#include "pt4.h"

#include "mpi.h"
/*
问题背景：有K个进程，其中K是3的倍数。每个进程包含一个整数C，C的值为0、1、2，其中每个值的进程数量是K/3。具体来说，进程编号为0、1、2的进程分别包含C = 0、C = 1、C = 2。

步骤一：创建通信器：

使用MPI_Comm_split函数根据C的值（0、1、2）将进程分为三个组，每组的进程数相同。这个操作将原始的MPI_COMM_WORLD通信器分成三个新的通信器：
第一个通信器包含C = 0的进程；
第二个通信器包含C = 1的进程；
第三个通信器包含C = 2的进程。
每个进程输出它在新通信器中的rank（即在每个子组中的位置），并且特别指出，原始通信器（MPI_COMM_WORLD）中的进程0、1、2的rank应该为0。
步骤二：创建交互式通信器：

使用MPI_Intercomm_create函数将这些子通信器连接成交互式通信器，形成三个环形连接：
第一个交互式通信器连接C = 0和C = 1的进程；
第二个交互式通信器连接C = 1和C = 2的进程；
第三个交互式通信器连接C = 0和C = 2的进程。
通过这三个交互式通信器，进程间将形成一个环状连接。
步骤三：交换数据：

在这些通信器中，每个进程有两个给定的整数（X、Y、Z），并按特定方式通过MPI_Send和MPI_Recv函数交换数据：
进程0、1、2分别在各自的通信器中交换X、Y、Z值：
第一组（C = 0和C = 1的进程）交换X值；
第二组（C = 1和C = 2的进程）交换Y值；
第三组（C = 0和C = 2的进程）交换Z值。
每个进程输出接收到的数字（X、Y、Z）。
*/
void Solve()
{
    Task("MPI8Inter4");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

}
