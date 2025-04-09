#include "pt4.h"
#include "mpi.h"
// MPI_Comm_split
// global reduction operation
// int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm);
void Solve()
{
    Task("MPI5Comm12");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int n;
    pt >> n;
    double a;
    pt >> a;
    MPI_Comm comm;
    int color;
    if (n == 1)
    {
        color = 1;
    }
    else
    {
        color = 2;
    }
    MPI_Comm_split(MPI_COMM_WORLD, color, rank, &comm);
    int new_rank, new_size;
    MPI_Comm_rank(comm, &new_rank);
    MPI_Comm_size(comm, &new_size);
    if (color == 1)
    {
        double min_a;                                            // ?????
        MPI_Allreduce(&a, &min_a, 1, MPI_DOUBLE, MPI_MIN, comm); // ?????
        // ?????
        pt << min_a;
    }
    else
    {
        double max_a;                                            // ?????
        MPI_Allreduce(&a, &max_a, 1, MPI_DOUBLE, MPI_MAX, comm); // ?????
        // ?????
        pt << max_a;
    }
}
