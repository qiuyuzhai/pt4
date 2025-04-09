#include "pt4.h"
#include "mpi.h"
/*A real number is given in each slave process. 
Send all given numbers to the master process using the MPI_Bsend 
(the blocking function for buffered send) 
and MPI_Recv functions 
and output received numbers in the master process in descending order of ranks of sending processes. 
Use the MPI_Buffer_attach function for attaching a buffer to a process.*/

void Solve()
{
    Task("MPI2Send2");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    double a;// ???????????
    MPI_Status s; // ??????????????????.
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // ???????
    double send_buffer[1];
    MPI_Buffer_attach(send_buffer, sizeof(send_buffer));
    
    if(rank>0)
    {
        pt >> a; // ??????????? a
        send_buffer[0] = a;// ??????????
        MPI_Send(send_buffer, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD); //?a??????

    }
    else
    {
        for (int i = size-1; i > 0; --i) // ??????????
        {
            MPI_Recv(&a, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, &s); // ?????????
            pt << a; // ?????????
        }

    }

}
