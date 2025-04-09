#include "pt4.h"       
#include "mpi.h"       

void Solve()
{
    Task("MPI7Win7"); 
    int flag;
    MPI_Initialized(&flag); 
    if (flag == 0)          
        return;

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size); 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
    
    int k = size - 1; 
    int *a = nullptr; 
    if (rank == 0)    
    {
        a = new int[2 * k]; 
        for (int i = 0; i < 2 * k; ++i)
            pt >> a[i]; 
    }

    int local_data[2] = {0, 0}; 
    MPI_Win win;

    MPI_Win_create(local_data, 2 * sizeof(int), sizeof(int),
                   MPI_INFO_NULL, MPI_COMM_WORLD, &win);

    MPI_Win_fence(0, win);

    if (rank == 0) 
    {
        for (int i = 1; i <= k; ++i) 
        {
            //将当前进程本地数组 a 的 两个整数 从位置 2 * (i - 1) 开始，
            //发送到 目标进程 i 的窗口中，并存储到窗口的偏移位置 0（窗口起始位置）开始。
            MPI_Put(a + 2 * (i - 1), 2, MPI_INT, i, 0, 2, MPI_INT, win);
        }
    }

    MPI_Win_fence(0, win);

    if (rank > 0) 
    {
        pt << local_data[0] << local_data[1];
    }

    MPI_Win_free(&win);
    if (rank == 0)
        delete[] a; 
}
