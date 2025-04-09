#include "pt4.h"

#include "mpi.h"

// Process 1: 3.14 (1 time)
// Process 2: 2.71 (2 times)
// Process 3: 1.41 (3 times)
// The file content is [1.41, 1.41, 1.41, 2.71, 2.71, 3.14].

void Solve()
{
    Task("MPI6File8");
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

    double data;
    if (rank > 0)
        pt >> data;

    MPI_File f;
    MPI_File_open(MPI_COMM_WORLD, name, MPI_MODE_CREATE | MPI_MODE_WRONLY, MPI_INFO_NULL, &f);

    int sz;
    MPI_Type_size(MPI_DOUBLE,&sz);

        // ??????????????
    MPI_Offset offset = 0;
    for (int i = size - 1; i > rank; --i) // ????????
        offset += i * sz;

    if(rank>0)
    {
        MPI_File_seek(f, offset, MPI_SEEK_SET);

        std::vector<double> buf(rank,data);
        MPI_File_write(f, buf.data(), rank, MPI_DOUBLE, MPI_STATUS_IGNORE); 

    }

    MPI_File_close(&f);


}
