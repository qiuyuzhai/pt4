#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI6File26");
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

    double a[4];
    for (int i = 0; i < 4; ++i)
        pt >> a[i];

    MPI_File f;
    MPI_File_open(MPI_COMM_WORLD, name,MPI_MODE_CREATE | MPI_MODE_WRONLY, MPI_INFO_NULL, &f);

    int dbl_sz;
    MPI_Type_size(MPI_DOUBLE, &dbl_sz);

    MPI_Datatype t0, t;
    MPI_Type_create_resized(t0, 0, 2 * size * dbl_sz, &t);
    //changed the extent to 2*size of double(dbl_sz)
    //chang the extent of data in the file
    //for example:You have a book with content on every page.Now it needs to be rearranged: blank pages are inserted after each page to make the content of each page more spaced.

    MPI_File_set_view(f, rank * dbl_sz, MPI_DOUBLE, t, "native",MPI_INFO_NULL);
    //Each process starts from rank * dbl_sz in the file and writes data according to the definition of type T.
    //Set the access method of the process in the file: where to start reading/writing
    //for example:If a book is distributed to multiple people, each person is responsible for copying certain paragraphs: everyone starts from different pages.

    MPI_File_write_all(f, a, 4, MPI_DOUBLE, MPI_STATUS_IGNORE);
    //Each process writes its own data (4 MPI_DOUBLES in array a) to the file and ensures that the collective write is complete.

    
    MPI_File_close(&f);
}
