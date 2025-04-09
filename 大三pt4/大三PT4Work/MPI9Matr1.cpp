#include "pt4.h"
#include "mpi.h"
#include <cmath>
//就是求两个矩阵的乘积矩阵c_

//全局变量
int k;             // 当前进程的总数
int r;             // rank 
int m, p, q;       // 矩阵 A 和 B 的维度，分别为 M × P 和 P × Q
int *a_, *b_, *c_; // 用于存储矩阵 A、B 和结果矩阵 C 的数组，按照行优先顺序存储


void Solve()
{
    Task("MPI9Matr1");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);// 获取总进程数
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);// 获取当前进程的秩
    k = size;// 总进程数赋值给全局变量 k
    r = rank;// 当前进程秩赋值给全局变量 r

    // input
    if (r != 0)// 只让主进程执行后续逻辑，其他进程直接返回
        return;
    pt >> m >> p >> q;
    a_ = new int[m * p];//矩阵 A
    b_ = new int[p * q];//矩阵 B
    GetArrN(a_, m * p);//pt4工具读取矩阵A和B
    GetArrN(b_, p * q);
    // for (int i = 0; i < m * p; ++i)
    // pt >> a_[i];
    // for (int i = 0; i < p * q; ++i)
    // pt >> b_[i];
    c_ = new int[m * q];//动态分配用于存储结果
    for (int i = 0; i < m * q; ++i)
        c_[i] = 0;//初始化为0
    for (int i = 0; i < m; ++i)//遍历矩阵 A 的每一行
        for (int j = 0; j < q; ++j)//遍历矩阵 B 的每一列
            for (int n = 0; n < p; ++n)//计算点积
                c_[i * q + j] += a_[i * p + n] * b_[n * q + j];

    //输出结果
    PutArrN(c_, m * q);
    // for (int i = 0; i < m * q; ++i)
    //    pt<< c_[i];

    //释放动态分配的内存
    delete[] a_;
    delete[] b_;
    delete[] c_;
}
