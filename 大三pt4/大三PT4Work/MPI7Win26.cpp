#include "pt4.h"
#include "mpi.h"
//?????????????????????????????
//??????a[i]????????b[i]
//??????????????????? B ???????????? MPI_Get ????
//?? MPI_LOCK_SHARED ???? MPI_Win_lock ?????????
void Solve()
{
    Task("MPI7Win26");

    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int k = 5;

    // ????????? A
    double A[k];
    if (rank > 0)
    {
        for (int i = 0; i < k; i++)
            pt >> A[i]; // ?????????? A
    }

    // ?????? B ???????????????? 0?
    double B[k] = {0}; // ???? 0

    // ???????? MPI_Accumulate ? MPI_Get
    MPI_Win win;
    MPI_Win_create(B, k * sizeof(double), sizeof(double), MPI_INFO_NULL, MPI_COMM_WORLD, &win);

    // ???? i??????????? A[i]???? MPI_Accumulate ?? B[i]
    for (int i = 0; i < k; i++)
    {
        // ??????? A[i]
        double current_value = A[i];

        // ??????????
        MPI_Win_lock(MPI_LOCK_SHARED, 0, 0, win);

        // ?? MPI_Accumulate ?????? A[i] ??????? B[i] ????? B[i]
        MPI_Accumulate(&current_value, 1, MPI_DOUBLE, 0, i, 1, MPI_DOUBLE, MPI_MAX, win);

        // ????
        MPI_Win_unlock(0, win);
    }

    // ???????????????
    MPI_Barrier(MPI_COMM_WORLD);

    // for(int i=0;i<k;i++)???????????????
    //     Show(B[i]);

    // ??????rank == 0????????????????
    if (rank == 0)
    {
        // ????? B ?????????
        MPI_Get(B, k, MPI_DOUBLE, 0, 0, k, MPI_DOUBLE, win);
        // for(int i=0;i<k;i++)???
        //     Show(B[i]);
    }
    MPI_Bcast(B, k, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // ?????????????????
    // MPI_Barrier(MPI_COMM_WORLD);

    // ??????? B ??
    if (rank > 0)
    {
        for (int i = 0; i < 5; i++)
            pt << B[i];
    }

    // ????
    MPI_Win_free(&win);
}
