#include "pt4.h"
#include "mpi.h"
/*The number of processes is an even number.
An integer N (0 < N < 5) and a sequence of N real numbers are given in each process.
Exchange given sequences of processes 0 and 1, 2 and 3, and so on, using the MPI_Sendrecv function.
 Output the received sequence of real numbers in each process.*/
void Solve()
{
    Task("MPI2Send18");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int n;
    double c[5], d[5]; 
    pt >> n;//????????????????? n ?
    for (int i = 0; i < n; i++)
    {
        pt >> c[i];
    }

    int recv_n; //???????//??&n??????????????&recv_n??????????????
    if (rank % 2 == 0 && rank + 1 < size)
    { // 0 -> 1
        MPI_Sendrecv(&n, 1, MPI_INT, rank + 1, 0,//???????????&n
                     &recv_n, 1, MPI_INT, rank + 1, 0,
                     MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Sendrecv(c, n, MPI_DOUBLE, rank + 1, 1,//??c?????????????
                     d, recv_n, MPI_DOUBLE, rank + 1, 1,
                     MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for (int i = 0; i < recv_n; i++)
        {
            pt << d[i];
        }
    }
    else if (rank % 2 == 1 && rank - 1 >= 0)
    {
        MPI_Sendrecv(&n, 1, MPI_INT, rank - 1, 0,
                     &recv_n, 1, MPI_INT, rank - 1, 0,
                     MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Sendrecv(c, n, MPI_DOUBLE, rank - 1, 1,
                     d, recv_n, MPI_DOUBLE, rank - 1, 1,
                     MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for (int i = 0; i < recv_n; i++)
        {
            pt << d[i];
        }
    }
}
