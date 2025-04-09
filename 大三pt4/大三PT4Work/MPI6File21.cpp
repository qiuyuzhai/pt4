#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI6File21");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int k = size;

    char name[12];
    if (rank == 0)
        pt >> name;
    MPI_Bcast(name, 12, MPI_CHAR, 0, MPI_COMM_WORLD);

    // open the file for reading
    MPI_File f;
    MPI_File_open(MPI_COMM_WORLD, name, MPI_MODE_RDONLY, MPI_INFO_NULL, &f);

    // get the size of int
    int int_sz;
    MPI_Type_size(MPI_INT, &int_sz);

    MPI_Datatype t0, t;
    // create a new type of file with the size of (k-1)
    MPI_Type_contiguous(1, MPI_INT, &t0);           // ??????
    MPI_Type_create_resized(t0, 0, k * int_sz, &t); // ??????? K ???
    MPI_Type_commit(&t);

    // ?????
    MPI_Offset offset = rank * int_sz; // ?????????

    // ??????
    MPI_File_set_view(f, offset, MPI_INT, t, "native", MPI_INFO_NULL);

    // ??????????? 3 ????
    int buffer[3];
    MPI_File_read_all(f, buffer, 3, MPI_INT, MPI_STATUS_IGNORE);

    // ????????
    for (int i = 0; i < 3; ++i)
    {
        pt << buffer[i];
    }

    // ?????????
    MPI_File_close(&f);
    MPI_Type_free(&t);
    MPI_Type_free(&t0);
}
