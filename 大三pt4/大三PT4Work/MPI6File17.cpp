#include "pt4.h"

#include "mpi.h"

void Solve()
{
    Task("MPI6File17");
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

    MPI_File file;
    MPI_File_open(MPI_COMM_WORLD, name, MPI_MODE_RDONLY, MPI_INFO_NULL, &file); // ?????????

    // ???????????????
    int displacement = 2 * rank * sizeof(int); // ???????????????
    MPI_File_set_view(file, displacement, MPI_INT, MPI_INT, "native", MPI_INFO_NULL); // ??????

    // ?????????
    int data[2]; // ?????????
    MPI_File_read_all(file, data, 2, MPI_INT, MPI_STATUS_IGNORE); // ?? MPI_File_read_all ??????
    pt << data[0] << data[1]; // ?????????

    MPI_File_close(&file); // ????

}
