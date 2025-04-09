#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI5Comm22");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (size != 8 && size != 12)
        return;

    double value;
    pt >> value;

    int dims[3] = { 2, 2, size / 4 };
    int periods[3] = { 0, 0, 0 };
    int reorder = 0;

    MPI_Comm cart_comm;
    MPI_Cart_create(MPI_COMM_WORLD, 3, dims, periods, reorder, &cart_comm);

    int coords[3];
    MPI_Cart_coords(cart_comm, rank, 3, coords);

    MPI_Comm matrix_comm;
    MPI_Comm_split(cart_comm, coords[2], rank, &matrix_comm);

    double matrix_sum = 0.0;
    MPI_Allreduce(&value, &matrix_sum, 1, MPI_DOUBLE, MPI_SUM, matrix_comm);

    int matrix_master;
    int subgrid_coords[3] = { 0, 0, coords[2] };  
    MPI_Cart_rank(cart_comm, subgrid_coords, &matrix_master);

    pt << matrix_sum;
    


}
