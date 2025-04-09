#include "pt4.h"

#include "mpi.h"

#include <cmath>

int k;              // number of processes
int r;              // rank of the current process

int m, p, q;        // sizes of the given matrices
int m0, p0, q0;     // sizes of the matrix blocks
int k0;             // order of the Cartesian grid (equal to sqrt(k))

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

// Matr4Calc1 implementation with the step parameter
// void Matr4Calc1(int step) {
//     int coords[2], I0, J0;
//     MPI_Cart_coords(MPI_COMM_GRID, r, 2, coords); // Get the grid coordinates of the process
//     I0 = coords[0];
//     J0 = coords[1];

//     int source = (I0 + step) % k0; // Compute the source column for the AR block
//     if (J0 == source) {
//         // Broadcast the AR block from the source process to all processes in the row
//         MPI_Bcast(a, m0 * p0, MPI_INT, J0, MPI_COMM_ROW);
//     } else {
//         // Receive the AR block
//         MPI_Bcast(a, m0 * p0, MPI_INT, source, MPI_COMM_ROW);
//     }

//     // Compute the block CR using the received AR and BR blocks
//     for (int i = 0; i < m0; ++i) {
//         for (int j = 0; j < q0; ++j) {
//             int sum = 0;
//             for (int k = 0; k < p0; ++k) {
//                 sum += a[i * p0 + k] * b[k * q0 + j];
//             }
//             c[i * q0 + j] += sum;
//         }
//     }
// }

// // Matr4Calc2 implementation for the second stage of Fox's algorithm
// void Matr4Calc2() {
//     // Rotate BR blocks cyclically within each column
//     MPI_Sendrecv_replace(b, p0 * q0, MPI_INT,
//                          (r + k0 - 1) % k0, 0,
//                          (r + 1) % k0, 0,
//                          MPI_COMM_COL, MPI_STATUS_IGNORE);
// }

void Solve()
{
    Task("MPI9Matr38");
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
    // Create the Cartesian grid communicator
    int dims[2] = {k0, k0};
    int periods[2] = {0, 0};
    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, 1, &MPI_COMM_GRID);

    // Create row and column communicators
    int coords[2];
    MPI_Cart_coords(MPI_COMM_GRID, r, 2, coords);
    MPI_Comm_split(MPI_COMM_GRID, coords[0], coords[1], &MPI_COMM_ROW);
    MPI_Comm_split(MPI_COMM_GRID, coords[1], coords[0], &MPI_COMM_COL);

    // Read the sizes of the blocks
    pt >> m0 >> p0 >> q0;

    // // Allocate memory for blocks
    a = new int[m0 * p0];
    b = new int[p0 * q0];
    c = new int[m0 * q0];
    t = new int[m0 * p0];

    // // Initialize the blocks with input data
    for (int i = 0; i < m0 * p0; ++i) pt >> a[i];
    for (int i = 0; i < p0 * q0; ++i) pt >> b[i];
    for (int i = 0; i < m0 * q0; ++i) pt >> c[i];
    for (int i = 0; i < m0 * p0; ++i) pt >> t[i];

    // Execute two initial steps of Fox's algorithm
    // Matr4Calc1(0);
    // Matr4Calc2();
    // Matr4Calc1(1);

    // // Output the new contents of blocks TR, BR, and CR
    // for (int i = 0; i < m0 * p0; ++i) pt << t[i];
    // for (int i = 0; i < p0 * q0; ++i) pt << b[i];
    // for (int i = 0; i < m0 * q0; ++i) pt << c[i];

    // Clean up
    delete[] a;
    delete[] b;
    delete[] c;
    delete[] t;

}
