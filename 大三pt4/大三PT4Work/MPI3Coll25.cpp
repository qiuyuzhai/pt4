#include "pt4.h"
#include "mpi.h"
// find maximal values among elements of all given sequences with the same order number and send two maximal values to each process as follows:
// the initial two maximums should be sent to the process 0, the next two maximums should be sent to the process 1, and so on.
void Solve()
{
    Task("MPI3Coll25");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // input data
    double sendbuf[2 * size];
    for (int i = 0; i < 2 * size; i++)
    {
        pt >> sendbuf[i];
    }
    double revbuf[2];
    double values[2 * size];
    int revcounts[size];
    for (int i = 0; i < size; i++)
    {
        revcounts[i] = 2;
    }
    MPI_Reduce_scatter(
        sendbuf,       // Send buffer
        values,        // Receive buffer
        revcounts,     // Number of elements received by each process
        MPI_DOUBLE,    // Data type
        MPI_MAX,       // protocol operation
        MPI_COMM_WORLD // communication domain
    );
    // for(int i=0;i<2*size;i++)
    // {
    //     ShowD(values[i]);
    // }
    for (int i = 0; i < 2; i++)
    {
        revbuf[i] = values[i];
    }
    for (int i = 0; i < 2; i++)
    {
        pt << revbuf[i];
    }
}
