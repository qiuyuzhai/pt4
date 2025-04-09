#include "pt4.h"
#include "mpi.h"
/*A sequence of K + 5 real numbers is given in each process;
K is the number of processes.
Using the MPI_Allreduce function with the MPI_MINLOC operation,
find the minimal value among the elements of all given sequences with the same order number and also the rank of process that contains this minimal value.
Output received minimal values in the master process and output corresponding ranks in each slave process.*/
struct MINLOC_Data
{
    double a;
    int n;
};

void Solve()
{
    Task("MPI3Coll23");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MINLOC_Data d[10], res[10];
    for (int i = 0; i < size + 5; ++i)
    {
        pt >> d[i].a;
        d[i].n = rank;
    }
    MPI_Allreduce(d, res, size + 5, MPI_DOUBLE_INT, MPI_MINLOC,//
                  MPI_COMM_WORLD);
    for (int i = 0; i < size + 5; ++i)
        if (rank == 0)
            pt << res[i].a;
        else
            pt << res[i].n;
}
