#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI4Type19");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int K = size - 1;
    int N;
    pt >> N;

    if (rank != 0)
    {
        int P;  // ???????? P
        pt >> P;
        int *B = new int[3 * N - 2];
        
        for (int i = 0; i < 3 * N - 2; ++i)  // ??“Z”??????
        {
            pt >> B[i];
        }
        
        // ??“Z”????
        MPI_Send(B, 3 * N - 2, MPI_INT, 0, P, MPI_COMM_WORLD);
        delete[] B;
    }
    else
    {
        // ????????? A
        int *A = new int[N * (K / 3) * 3 * N]();  // ????????

        // ????????? z_block_type
        MPI_Datatype z_block_type;
        int blocklengths[N];
        int displacements[N];
        
        for (int i = 0; i < N; ++i)
        {
            if (i == 0) {
                blocklengths[i] = N;               // ?????
                displacements[i] = 0;              // ????
            } 
            else if (i == N - 1) {
                blocklengths[i] = N;               // ?????
                displacements[i] = i * 3 * N;      // ????
            } 
            else {
                blocklengths[i] = 1;               // ??????
                displacements[i] = i * 3 * N + (N - i - 1);  // ????????
            }
        }

        MPI_Type_indexed(N, blocklengths, displacements, MPI_INT, &z_block_type);
        MPI_Type_commit(&z_block_type);

        // ?????????“Z”???
        for (int m = 1; m <= K; ++m)
        {
            MPI_Status status;
            MPI_Probe(m, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            int P = status.MPI_TAG;  // ?????? P

            MPI_Recv(A + P, 1, z_block_type, m, P, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        // ???? A ?????
        for (int i = 0; i < N * (K / 3) * 3 * N; ++i)
        {
            pt << A[i];
        }

        // ????????????
        MPI_Type_free(&z_block_type);
        delete[] A;
    }
}
