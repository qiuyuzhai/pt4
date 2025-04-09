#include "pt4.h"
#include "mpi.h"
/*
 An integer is given in each process.
 Using the MPI_Ssend and MPI_Recv functions,
 perform the left cyclic shift of given data by step ?1
 (that is, the given integer should be sent from the process 1 to the process 0,
 from the process 2 to the process 1, …, from the process 0 to the last process).
 Output the received number in each process.
*/
void Solve()
{
    Task("MPI2Send13");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status s; // 
    int a;
    int send_rank=(rank-1+size)%size;
    int recv_rank=(rank+1)%size;
    if(rank>0)
    {
        pt>>a;
        MPI_Ssend(&a, 1, MPI_INT, send_rank, 0, MPI_COMM_WORLD);
        MPI_Recv(&a, 1, MPI_INT, recv_rank, 0, MPI_COMM_WORLD, &s);
        pt<<a;


    }
    else
    {
        MPI_Recv(&a, 1, MPI_INT, recv_rank, 0, MPI_COMM_WORLD, &s);//????????MPI??????a?????????        
        pt<<a;
        pt>>a;
        MPI_Ssend(&a, 1, MPI_INT, send_rank, 0, MPI_COMM_WORLD);
    
    }

}
