#include "pt4.h"

#include "mpi.h"

#include <cmath>

int k; // number of processes
int r; // rank of the current process

int m, p, q;    // sizes of the given matrices
int m0, p0, q0; // sizes of the matrix blocks
int k0;         // order of the Cartesian grid (equal to sqrt(k))

int *a_, *b_, *c_;  // arrays to store matrices in the master process
int *a, *b, *c, *t; // arrays to store matrix blocks in each process

MPI_Datatype MPI_BLOCK_A; // datatype for the block of the matrix A
MPI_Datatype MPI_BLOCK_B; // datatype for the block of the matrix B
MPI_Datatype MPI_BLOCK_C; // datatype for the block of the matrix C

MPI_Comm MPI_COMM_GRID = MPI_COMM_NULL;
// communicator associated with a two-dimensional Cartesian grid
MPI_Comm MPI_COMM_ROW = MPI_COMM_NULL;
// communicator associated with rows of a two-dimensional grid
MPI_Comm MPI_COMM_COL = MPI_COMM_NULL;
// communicator associated with columns of a two-dimensional grid

// Function to create MPI_COMM_GRID
void Matr4CreateCommGrid(MPI_Comm &comm)
{
    int dims[2] = {k0, k0};
    int periods[2] = {1, 1}; // Periodic in both dimensions
    int reorder = 0;
    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, reorder, &comm);

    // Output the Cartesian coordinates of each process
    int coords[2];
    MPI_Cart_coords(comm, r, 2, coords);
    pt << coords[0] << coords[1];
}

// Function to create MPI_COMM_ROW
void Matr4CreateCommRow(MPI_Comm grid, MPI_Comm &row)
{
    int remain_dims[2] = {0, 1}; // Keep only the second dimension (row communicator)
    MPI_Cart_sub(grid, remain_dims, &row);

    // Output the rank within the row communicator
    int rank_in_row;
    MPI_Comm_rank(row, &rank_in_row);
    pt << rank_in_row;
}

void Solve()
{
    Task("MPI9Matr33");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    k = size;
    r = rank;
    k0 = (int)floor(sqrt((double)k) + 0.1);

    // Input the local matrix dimensions and matrix A
    pt >> m0 >> p0;
    a = new int[m0 * p0]; // Use the variable "a" as required in the problem statement
    for (int i = 0; i < m0 * p0; ++i)
        pt >> a[i];

    // Create MPI_COMM_GRID
    Matr4CreateCommGrid(MPI_COMM_GRID);

    // Create MPI_COMM_ROW
    Matr4CreateCommRow(MPI_COMM_GRID, MPI_COMM_ROW);

    // Get the Cartesian coordinates of the current process
    int coords[2];
    MPI_Cart_coords(MPI_COMM_GRID, r, 2, coords);

    // Create auxiliary matrix T
    t = new int[m0 * p0];

    // Broadcast the matrix A within the same row
    if (coords[1] == coords[0]) // Only the diagonal process sends the matrix
        for (int i = 0; i < m0 * p0; ++i)
            t[i] = a[i];

    MPI_Bcast(t, m0 * p0, MPI_INT, coords[0], MPI_COMM_ROW);

    // Output the received matrix T
    for (int i = 0; i < m0 * p0; ++i)
        pt << t[i];

    delete[] a;
    delete[] t;
}
