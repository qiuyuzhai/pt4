#include "pt4.h"

#include "mpi.h"
//The name of file is given in the master process; 
//a sequence of R real numbers is given in each slave process, where R is the process rank. 
//Create a new file of real numbers with the given name and write the given data to this file in ascending order of ranks of processes containing these data. 
//Use one call of the MPI_File_write_at local function in each slave process.
void Solve()
{
    Task("MPI6File4");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    char name[12];
    if(rank==0)
       pt>>name;
    MPI_Bcast(name, 12, MPI_CHAR, 0, MPI_COMM_WORLD);

    double* data=new double[rank];
    for(int i=0;i<rank;++i)
        pt>>data[i];

    MPI_File f;
    MPI_File_open(MPI_COMM_WORLD,name,MPI_MODE_CREATE|MPI_MODE_WRONLY,MPI_INFO_NULL,&f);

    int sz;
    MPI_Type_size(MPI_DOUBLE,&sz);

    MPI_Offset offset=0;
    for(int i=0;i<rank;++i)
        offset+=i*sz;
    
    if(rank!=0)
      MPI_File_write_at(f, offset, data, rank, MPI_DOUBLE, MPI_STATUS_IGNORE);
    
    MPI_File_close(&f);

    
    

}
