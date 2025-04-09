#include "pt4.h"
#include "mpi.h"
/*A sequence of real numbers is given in the master process; 
the size of sequence is equal to the number of slave processes. 
Send each element of given sequence to corresponding slave process using the MPI_Send function: 
the first number should be sent to the process 1, the second number should be sent to the process 2, 
and so on. Output received numbers in the slave processes.*/


void Solve()
{
    Task("MPI2Send5");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    double a; // ???????????
    MPI_Status s; // ??????????????????

    if (rank > 0) // ????????????rank 0?
    {
        MPI_Recv(&a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &s); //????????
        pt << a; // ?????????
    }
    else // ???????????rank 0?
    {

        
        for (int i = 1; i < size; ++i) // ????????
    {
          pt >> a; // ??????????? a
            MPI_Send(&a, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD); // ??????? a?????
         }
       
    }

}
