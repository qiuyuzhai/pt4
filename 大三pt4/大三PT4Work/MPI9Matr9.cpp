#include "pt4.h"

#include "mpi.h"

#include <cmath>
#include <cstring>

int k;              // number of processes
int r;              // rank of the current process

int m, p, q;        // sizes of the given matrices
int na, nb;         // sizes of the matrix bands

int *a_, *b_, *c_;  // arrays to store matrices in the master process
int *a, *b, *c;     // arrays to store matrix bands in each process


void Matr1GatherFile(int m, char filename[12], int na, int q, int* c)
{
    // Broadcast the number of rows (M) and the file name to all processes
    MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(filename, 12, MPI_CHAR, 0, MPI_COMM_WORLD);

    // Open the file for collective writing
    MPI_File file;
    MPI_File_open(MPI_COMM_WORLD, filename, MPI_MODE_CREATE | MPI_MODE_WRONLY, MPI_INFO_NULL, &file);

    // Write each process's band to the correct position in the file
    for (int i = 0; i < na; i++) {
        if (r * na + i < m) { // Only write rows within the matrix size
            MPI_Offset offset = (r * na + i) * q * sizeof(int);
            MPI_File_seek(file, offset, MPI_SEEK_SET);
            MPI_File_write_all(file, &c[i * q], q, MPI_INT, MPI_STATUS_IGNORE);
        }
    }

    // Close the file
    MPI_File_close(&file);
}

void Solve()
{
    Task("MPI9Matr9");

    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    k = size;
    r = rank;

    // Step 1: Input data in each process
    int na, q;
    pt >> na >> q;

    int* c = new int[na * q];
    for (int i = 0; i < na * q; i++) {
        pt >> c[i];
    }

    // Step 2: Input M and file name in the master process
    int m;
    char filename[12] = {0};
    if (r == 0) {
        pt >> m;
        pt >> filename;
    }

    // Step 3: Call Matr1GatherFile to perform broadcasting and file writing
    Matr1GatherFile(m, filename, na, q, c);

    // Clean up
    delete[] c;
}
