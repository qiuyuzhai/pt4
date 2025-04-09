#include "pt4.h"

#include "mpi.h"

void Solve()
{
    Task("MPI7Win23");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
     int win_sz = 5; 
    int n[5], m[5]; 
    double a[5]; 
    for (int i = 0; i < 5; ++i) 
        pt >> a[i]; 
    if (rank == 0) 
    { 
        win_sz = 0; 
        for (int i = 0; i < 5; ++i) 
            pt >> n[i]; 
        for (int i = 0; i < 5; ++i) 
            pt >> m[i]; 
    } 
    int dbl_sz; 
    MPI_Type_size(MPI_DOUBLE, &dbl_sz); 
    MPI_Win win; 
    MPI_Win_create(&a, win_sz * dbl_sz, dbl_sz, MPI_INFO_NULL,  MPI_COMM_WORLD, &win); 
    MPI_Group g0, g; 
    MPI_Comm_group(MPI_COMM_WORLD, &g0); 
    int b = 0; 
    if (rank == 0) 
    { 
        MPI_Group_excl(g0, 1, &b, &g); 
        MPI_Win_start(g, 0, win); 
        double a0[5];
        for (int i = 0; i < 5; ++i) 
            MPI_Get(&a0[i], 1, MPI_DOUBLE, n[i], m[i], 1,MPI_DOUBLE, win); 
        MPI_Win_complete(win); 
        for (int i = 0; i < 5; ++i) 
            a[i] += a0[i]; 
        MPI_Win_start(g, 0, win); 
        for (int i = 1; i < size; ++i) 
            MPI_Accumulate(a, 5, MPI_DOUBLE, i, 0, 5, MPI_DOUBLE,MPI_MIN, win); 
        MPI_Win_complete(win); 
    } 
    else 
    { 
        MPI_Group_incl(g0, 1, &b, &g); 
        MPI_Win_post(g, 0, win); 
        MPI_Win_wait(win); 
        MPI_Win_post(g, 0, win); 
        MPI_Win_wait(win); 
    } 
    for (int i = 0; i < 5; ++i) 
        pt << a[i]; 
    MPI_Win_free(&win);
}
