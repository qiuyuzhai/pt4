#include "pt4.h"

#include "mpi.h"

void Solve()
{
    Task("MPI8Inter3");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    double a, b;
    MPI_Comm comm, comm_1, comm_2, n_comm;// ???? MPI ???
    MPI_Comm_dup(MPI_COMM_WORLD, &n_comm);// ??????? MPI_COMM_WORLD ? n_comm
    int r;
    int d = size - rank;// ??????? "??" ???
    int c = 1;// ???
    if (rank % 3 != 1 && rank % 3 != 2)
    {
        pt >> a;
        MPI_Comm_split(MPI_COMM_WORLD, rank % 3, rank, &comm);// ?? rank%3 ??????
        MPI_Comm_rank(comm, &r);// ???????????????
        pt << r;
        MPI_Intercomm_create(comm, 0, n_comm, size - 2, 1, &comm_1);// ????????
        MPI_Send(&a, 1, MPI_DOUBLE, d - 2, 0, n_comm);
        double m;
        MPI_Recv(&m, c, MPI_DOUBLE, MPI_ANY_SOURCE, 0, n_comm, MPI_STATUSES_IGNORE);// ?????????
        pt << m;
    }
    else if (rank % 3 == 1)
    {
        pt >> a;
        pt >> b;
        int key = d;
        MPI_Comm_split(MPI_COMM_WORLD, rank % 3, key, &comm);
        MPI_Comm_rank(comm, &r);
        pt << r;
        MPI_Intercomm_create(comm, 0, n_comm, 0, 1, &comm_1);// ???????????
        MPI_Intercomm_create(comm, 0, MPI_COMM_WORLD, 2, 2, &comm_2);// ???????????
        double m, n;
        MPI_Recv(&m, c, MPI_DOUBLE, MPI_ANY_SOURCE, 0, n_comm, MPI_STATUSES_IGNORE);// ???????
        MPI_Recv(&n, c, MPI_DOUBLE, MPI_ANY_SOURCE, 0, n_comm, MPI_STATUSES_IGNORE);// ???????
        MPI_Send(&a, c, MPI_DOUBLE, d - 2, 0, n_comm);
        MPI_Send(&b, c, MPI_DOUBLE, d, 0, n_comm);
        Show(m);
        Show(n);
        pt << m << n;
    }
    else if (rank % 3 == 2)
    {
        pt >> b;
        double n;
        MPI_Comm_split(MPI_COMM_WORLD, rank % 3, rank, &comm);
        MPI_Comm_rank(comm, &r);
        pt << r;
        MPI_Intercomm_create(comm, 0, MPI_COMM_WORLD, size - 2, 2, &comm_2);
        MPI_Send(&b, 1, MPI_DOUBLE, d, 0, n_comm);
        MPI_Recv(&n, 1, MPI_DOUBLE, MPI_ANY_SOURCE, 0, n_comm, MPI_STATUSES_IGNORE);
        pt << n;
    }
}
