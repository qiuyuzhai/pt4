#include "pt4.h"
#include "mpi.h"
/* An integer is given in each slave process;
only one of given integers is nonzero-valued.
Send nonzero integer to the master process. 
Output the received number and the rank of sending process in the master process. 
Use the MPI_Recv function with the MPI_ANY_SOURCE parameter to receive data in the master process.*/


void Solve()
{
    Task("MPI2Send8");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int a; // ???????????
    MPI_Status s; // ??????????????????
    if (rank > 0) // ????????????rank 0?
    {
        pt >> a; // ??????????? a
        if(a>0)
        {
            MPI_Send(&a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD); //?a??????
        }
    }
    else // ???????????rank 0?
    {

        MPI_Recv(&a, 1, MPI_INT, MPI_ANY_SOURCE,0, MPI_COMM_WORLD, &s); // ?????????
        pt << a << s.MPI_SOURCE; // ?????????,??????????s.MPI_SOURCE?????
        
    }

}
