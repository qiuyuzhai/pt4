#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI6File16");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    char name[12];
    if (rank == 0)
        pt >> name;
    MPI_Bcast(name, 12, MPI_CHAR, 0, MPI_COMM_WORLD);

    int n;
    pt >> n;
    double *data = new double[n];
    for (int i = 0; i < n; i++)
        pt >> data[i];

    MPI_Comm new_comm; // create new Communicator
    int right = (n > 0) ? 1 : MPI_UNDEFINED;
    MPI_Comm_split(MPI_COMM_WORLD, right, size-rank, &new_comm);

    if (right == 1)
    {
        int new_rank, new_size;
        MPI_Comm_rank(new_comm, &new_rank);
        MPI_Comm_size(new_comm, &new_size);

        double *rev_data = new double[n];
        for (int i = 0; i < n; ++i)
            rev_data[i] = data[n - 1 - i]; 

        MPI_File f;
        MPI_File_open(new_comm, name, MPI_MODE_CREATE | MPI_MODE_WRONLY, MPI_INFO_NULL, &f);
        MPI_File_write_ordered(f, rev_data, n, MPI_DOUBLE, MPI_STATUS_IGNORE);
        MPI_File_close(&f);
    }
    delete[] data;
}
