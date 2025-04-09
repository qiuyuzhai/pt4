#include "pt4.h"       
#include "mpi.h"      
//A sequence of R real numbers is given in each slave process, where R is the process rank (1, 2, …). 
//Create an access window of the appropriate size in the master process. 
//Using the MPI_Put function call in the slave processes, send all the given real numbers to the master process and output received numbers in the ascending order of ranks of sending processes.
//????????????? MPI ???Window???????????????????
//?????????????????????
void Solve()
{
    Task("MPI7Win2"); 
    int flag;
    MPI_Initialized(&flag); 
    if (flag == 0)          
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size); 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 

    double *a = nullptr; 
    double *local_data = nullptr; 

    if (rank == 0)
    {
        // create a new array
        int total_size = (size * (size - 1)) / 2; // 1 + 2 + ... + (size-1)
        a = new double[total_size]; 
    }
    else 
    {
        local_data = new double[rank];
        for (int i = 0; i < rank; ++i)
            pt >> local_data[i]; 
    }

    MPI_Win win;
    if (rank == 0)
    {
        //create a new window
        MPI_Win_create(a, sizeof(double) * (size * (size - 1)) / 2, sizeof(double),
                       MPI_INFO_NULL, MPI_COMM_WORLD, &win);
    }
    else
    {
        
        MPI_Win_create(nullptr, 0, sizeof(double), MPI_INFO_NULL, MPI_COMM_WORLD, &win);
    }

    //MPI_Win_fence ?????????????????????????????????????
    MPI_Win_fence(0, win);

    if (rank > 0) 
    {
        // ??????????????????????
        int start_idx = (rank - 1) * rank / 2;
        //?? MPI_Put ???? local_data???? rank ??????????????? start_idx ???
        MPI_Put(local_data, rank, MPI_DOUBLE, 0, start_idx, rank, MPI_DOUBLE, win);
    }

    
    MPI_Win_fence(0, win);//????????? MPI_Put ???????
    
    //?????? a ????????????????
    if (rank == 0) 
    {
        int current_idx = 0;
        for (int i = 1; i < size; ++i)
        {
            for (int j = 0; j < i; ++j)
                pt << a[current_idx++]; 
        }
    }

    //  ????????
    MPI_Win_free(&win);
    if (rank == 0)
        delete[] a; 
    else
        delete[] local_data; 
}
