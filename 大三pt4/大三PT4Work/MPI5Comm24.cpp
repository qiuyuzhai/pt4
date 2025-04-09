#include "pt4.h"
#include "mpi.h"
/*
integers M and N are given in the master process; 
the product of the numbers M and N is less than or equal to the number of processes. 
Also integers X and Y are given in each process whose rank is in the range 0 to M·N ? 1. 
Send the numbers M and N to all processes and define a Cartesian topology for initial M·N processes as a two-dimensional (M ? N) grid, 
which is periodic in the second dimension (ranks of processes should not be reordered). 
Using the MPI_Cart_rank function, output the rank of process with the coordinates X, Y (taking into account periodicity) in each process included in the Cartesian topology. 
Output ?1 in the case of erroneous coordinates.
*/
void Solve()
{
    Task("MPI5Comm24");
    int flag;
    MPI_Initialized(&flag);
    if (!flag) return;

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int M, N;

    // ?????? M ? N
    if (rank == 0) {
        pt >> M >> N;
    }

    // ? M ? N ???????
    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // ?? M * N ???????
    if (rank >= M * N) return;

    // ?? (M ? N) ??????
    int dims[2] = { M, N };
    int periodic[2] = { 0, 1 }; // ??????????
    int reorder = 0;

    MPI_Comm cart_comm;
    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periodic, reorder, &cart_comm);

    int X, Y;

    // ????????? X ? Y
    pt >> X >> Y;

    // ??????????
    if (X < 0 || X >= M || Y < -N || Y >= 2 * N) {
        pt << -1;
    } else {
        // ?????
        if (Y < 0) Y += N;
        else if (Y >= N) Y -= N;

        int target_rank;
        int target_coords[2] = { X, Y };
        
        // ??????? rank
        MPI_Cart_rank(cart_comm, target_coords, &target_rank);
        
        pt << target_rank;
    }

    MPI_Comm_free(&cart_comm);
}