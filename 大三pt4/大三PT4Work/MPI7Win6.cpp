#include "pt4.h"       
#include "mpi.h"       

void Solve()
{
    Task("MPI7Win6"); 
    int flag;
    MPI_Initialized(&flag); 
    if (flag == 0)          
        return;

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size); 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 

    double *a = nullptr; 
    int k = size - 1;    
    if (rank == 0)      
    {
        a = new double[2 * k - 1]; 
        for (int i = 0; i < 2 * k - 1; ++i)
            pt >> a[i]; 
    }

    double *b = nullptr;
    if (rank > 0) 
    {
        b = new double[rank];
        for (int i = 0; i < rank; ++i)
            pt >> b[i]; 
    }

    int dbl_sz;
    MPI_Type_size(MPI_DOUBLE, &dbl_sz); 

    MPI_Win win;
    //如果 rank == 0，则 a 指向一个大小为 (2 * k - 1) 的数组；如果 rank != 0，没有分配内存（即从进程不需要存储数据）
    MPI_Win_create(a, (rank == 0 ? (2 * k - 1) * dbl_sz : 0), dbl_sz,
                   MPI_INFO_NULL, MPI_COMM_WORLD, &win);

    MPI_Win_fence(0, win);

    if (rank > 0) 
    {
        //每个从进程（rank > 0）将其本地数组 b 的 rank 个元素累加到主进程窗口 a 中，从偏移位置 rank - 1 开始。
        MPI_Accumulate(b, rank, MPI_DOUBLE, 0, rank - 1, rank, MPI_DOUBLE,
                       MPI_SUM, win);
    }

    MPI_Win_fence(0, win);

    if (rank == 0)
    {
        for (int i = 0; i < 2 * k - 1; ++i)
            pt << a[i];
    }

    MPI_Win_free(&win);
    if (rank == 0)
        delete[] a; 
    if (rank > 0)
        delete[] b; 
}
