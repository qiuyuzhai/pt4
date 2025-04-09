#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI4Type17");
    int flag;
    MPI_Initialized(&flag);
    if (!flag)
        return;
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int K = size - 1;
    int N;
    pt >> N;
    int block_size = N * N;
    if (rank != 0)
    {
        int *B = new int[block_size];
        for (int i = 0; i < block_size; ++i)
        {
            pt >> B[i];
        }
        MPI_Send(B, block_size, MPI_INT, 0, 0, MPI_COMM_WORLD);
        delete[] B;
    }
    else
    {
        // to hold all blocks 
        int *A = new int[K * block_size]; 
        // ?????????????? block_type????????
        
        MPI_Datatype block_type;
        MPI_Type_vector(N, N, N * 3, MPI_INT, &block_type);
        MPI_Type_commit(&block_type);


        // ????????????? A ?
        for (int m = 1; m <= K; ++m)
        {
            int row = (m - 1) / 3; // ?????????
            int col = (m - 1) % 3; // ?????????
            int offset = row * 3 * block_size + col * N;

            // ?????????????
            MPI_Recv(A + offset, 1, block_type, m, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        // Output the final matrix A in row-major order
        for (int i = 0; i < K * block_size; ++i)
        {
            pt << A[i]; // Output matrix elements
        }
        // ????????????
        MPI_Type_free(&block_type);
        delete[] A;
    }
}
