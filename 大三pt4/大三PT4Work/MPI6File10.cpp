#include "pt4.h"
#include "mpi.h"
#include <vector>

using namespace std;

void Solve()
{
    Task("MPI6File10");

    int flag;
    MPI_Initialized(&flag); 
    if (flag == 0)
        return; 

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size); 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
  
    char name[12]; 
    if(rank == 0)
        pt >> name; 
    MPI_Bcast(name, 12, MPI_CHAR, 0, MPI_COMM_WORLD); 

    MPI_File f; 
    MPI_File_open(MPI_COMM_WORLD, name, MPI_MODE_CREATE | MPI_MODE_RDWR, MPI_INFO_NULL, &f); 
  

    int A[rank]; 
    for(int i = 0; i < rank; i++)
        pt >> A[i]; 

    MPI_File_seek(f, (rank * (rank - 1)) / 2 * 4, MPI_SEEK_SET); 
    // ?????????????
    // ??????(rank * (rank - 1)) / 2 * 4??????4??

    MPI_File_write_all(f, &A[0], rank, MPI_INT, MPI_STATUSES_IGNORE); 

    MPI_File_close(&f); 
}
