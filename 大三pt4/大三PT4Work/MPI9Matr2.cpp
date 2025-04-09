#include "pt4.h"
#include "mpi.h"
#include <cmath>
/*
主进程读取A和B的大小及数据内容

将矩阵分块，将计算任务划分到k个进程进行并行计算：
A被行带状分块，每个分块行数为na=m/k,最后不足的部分用0补全
B被行带状分块，每个分块行数为nb=p/k,最后不足的部分用0补全

使用MPI_Bcast将矩阵的维度和分块大小广播到所有进程，确保所有进程对计算范围达成一致。
使用 MPI_Scatter 将矩阵 A 和 B 的分块数据分发到各进程。

初始化结果矩阵：每个进程会为自己的结果矩阵C分配空间，C的分块大小为na✖q,在当前实现中C的值全是0。

输出分块结果：每个进程输出自己的分块信息，即A和B的分块数据，C的分块数据
*/

//全局变量
int k; // 进程数量
int r; // 当前进程的 rank（标识符）

int m, p, q; // 矩阵 A 和 B 的大小：A 是 m × p，B 是 p × q
int na, nb;  //矩阵 A 和 B 各自带状分块的行数（带宽）

int *a_, *b_, *c_; //主进程中存储完整矩阵 A、B 和结果矩阵 C 的数组
int *a, *b, *c;    //每个进程中存储分块矩阵 A、B 和对应结果矩阵 C 的数组

//矩阵带状分块及数据分发函数
void Matr1ScatterData()
{
    if (r == 0)//只有主进程负责输入和初始化完整矩阵
    {
        int m;
        pt >> m >> p >> q;//m-矩阵A总行数，p-矩阵B总行数

        //计算带宽na和nb
        na = (int)ceil(m / (k * 1.0));//矩阵A的每个带的行数
        nb = (int)ceil(p / (k * 1.0));

        //为矩阵A和B分配空间，大小为带宽拓展后的总行数
        a_ = new int[na * k * p];//拓展到na * k 行，然后还乘以矩阵A的列数
        b_ = new int[nb * k * q];//扩展到nb * k 行，然后还乘以矩阵B的列数

        //输入矩阵A，填充不足的部分补0
        for (int i = 0; i < m * p; ++i)
            pt >> a_[i];//原始数据
        for (int i = m * p; i < na * k * p; ++i)
            a_[i] = 0;//补0

        //输入矩阵B，填充不足的部分补0
        for (int i = 0; i < p * q; ++i)
            pt >> b_[i];//原始数据
        for (int i = p * q; i < nb * k * q; ++i)
            b_[i] = 0;//补0
    }
    //广播带宽na,nb和矩阵维度p,q到所有进程
    MPI_Bcast(&na, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&p, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&nb, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&q, 1, MPI_INT, 0, MPI_COMM_WORLD);

    //为每个进程的矩阵分块分配空间
    a = new int[na * p];
    b = new int[nb * q];
    c = new int[na * q];

    //// 使用 MPI_Scatter 分发矩阵 A 和 B 的分块到各进程
    MPI_Scatter(a_, p * na, MPI_INT, a, p * na, MPI_INT, 0, MPI_COMM_WORLD);
    //从主进程（rank=0）将大小为 p * na 的矩阵 A 的分块数据从 a_ 数组发送到所有进程，存储到各进程的 a 数组中
    MPI_Scatter(b_, q * nb, MPI_INT, b, q * nb, MPI_INT, 0, MPI_COMM_WORLD);

    //初始化结果矩阵 C 的分块为 0   
    for (int i = 0; i < na * q; ++i)
        c[i] = 0;
}

void Solve()
{
    Task("MPI9Matr2");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    k = size;
    r = rank;
    //调用矩阵分块及数据分发函数
    Matr1ScatterData();
    //输出结果：每个进程的带宽及分块数据
    pt << na << p << nb << q;
    PutArrN(a, na * p);// 输出 A 的分块
    PutArrN(b, nb * q);
    PutArrN(c, na * q);
}
