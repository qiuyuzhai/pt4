#include "pt4.h"
#include "mpi.h"
/*Input an integer A in each process of the MPI_COMM_WORLD communicator and output doubled value of A.
Also output the total number of processes in the master process主进程 (that is, a rank-zero process). 
For data input and output use the input-output stream pt. 
In the master process, duplicate重复 the data output in the debug section by displaying on separate lines the doubled value of A and the total number of processes 
(use two calls of the ShowLine function, which is defined in the taskbook along with the Show function).*/


void Solve()
{
    Task("MPI1Proc2");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int n;
    pt>>n;
    pt<<2*n;
    if(rank==0)//Pay attention to the topic,the title says that it is to output the rank of the main function
       pt<<size;
    ShowLine(2*n);
    ShowLine(size);



}
