#include "pt4.h"

#include "mpi.h"

void Solve()
{
    Task("MPI6File11");
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

    int data;
    pt >> data;

    MPI_Comm new_comm;
    int right = (data != 0) ? 1 : MPI_UNDEFINED;
    MPI_Comm_split(MPI_COMM_WORLD, right, rank, &new_comm);

    if (right == 1)
    {
        int new_rank, new_size;
        MPI_Comm_rank(new_comm, &new_rank); // ???????? rank
        MPI_Comm_size(new_comm, &new_size); // ???????????

        MPI_File f;
        MPI_File_open(new_comm, name, MPI_MODE_RDONLY, MPI_INFO_NULL, &f); // ?????????

        double value;
        MPI_Offset offset = (data - 1) * sizeof(double);                           // ???????????
        MPI_File_read_at_all(f, offset, &value, 1, MPI_DOUBLE, MPI_STATUS_IGNORE); // ?????????

        pt << value;        // ????????
        MPI_File_close(&f); // ????
    }
}
