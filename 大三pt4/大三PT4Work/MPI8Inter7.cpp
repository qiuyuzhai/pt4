#include "pt4.h"

#include "mpi.h"

void Solve()
{
    Task("MPI8Inter7");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Comm comm, n, n1, p;          // 定义MPI通信器
    MPI_Status s;                     // 定义MPI状态对象
    MPI_Comm_dup(MPI_COMM_WORLD, &p); // 复制全局通信器MPI_COMM_WORLD，存储到p
    int c, color, a, lead = 0;        // 定义一些变量：c为分类变量，color为颜色变量，a为数据变量，lead为通信组首进程标志
    pt >> c;                          

    // 根据进程排名将全局进程划分为两个颜色组
    if (rank < size / 2)
        color = 0; // 前半部分进程划分为颜色组0
    else
        color = 1; // 后半部分进程划分为颜色组1

    MPI_Comm_split(MPI_COMM_WORLD, color, rank, &comm); // 按颜色将全局通信器拆分为两个子通信器

    int r;
    MPI_Comm_rank(comm, &r); 
    pt << r;                 
    if (rank < size / 2)
        lead = size / 2; // 设定lead为另一通信组的起始进程
    // Show(lead);                     

    MPI_Intercomm_create(comm, 0, p, lead, 100, &n); // 创建两个通信组之间的互通信器
    int size2;
    MPI_Comm_remote_size(n, &size2); // 获取互通信器中远程组的大小

    // 根据分类变量c再次划分通信器
    MPI_Comm_split(n, c, size - rank - 1, &n1);
    int r2, s2, rs;
    MPI_Comm_rank(n1, &r2);        // 获取当前进程在新子通信器中的排名
    MPI_Comm_size(n1, &s2);        // 获取新子通信器中本地组的大小
    MPI_Comm_remote_size(n1, &rs); // 获取新子通信器中远程组的大小
    int b[rs];                     // 定义用于存储远程组数据的数组

    // 如果本地组大小大于1且分类变量c为1，进行点对点通信
    if (s2 > 1 && c == 1)
    {
        pt << r2;                               
        pt >> a;                                
        MPI_Send(&a, 1, MPI_INT, 0, 0, n1);     // 将数据发送到远程组的进程0
        MPI_Recv(&a, 1, MPI_INT, 0, 0, n1, &s); // 接收从远程组的进程0发送的数据
        // Show(a);                   
        pt << a; 
    }

    // 如果本地组大小为1且分类变量c为1，进行循环点对点通信
    if (s2 == 1 && c == 1)
    {
        for (int i = 0; i < rs; i++) // 遍历远程组所有进程
        {
            pt >> b[i];                             
            MPI_Recv(&a, 1, MPI_INT, i, 0, n1, &s); // 接收从远程组进程i发送的数据
            pt << a;                                
            // Show(a);                
            MPI_Send(&b[i], 1, MPI_INT, i, 0, n1); // 将读取的初始数据发送到远程组进程i
        }
    }
}
