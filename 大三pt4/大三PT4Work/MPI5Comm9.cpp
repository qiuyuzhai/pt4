#include "pt4.h"
#include "mpi.h"
#include <vector>
#include <algorithm>
/*An integer N is given in each process; 
the value of N is equal to 1 for at least one process and is equal to 0 for others. 
Also a real number A is given in each process with N = 1. 
Send all numbers A to each process with N = 1 using the MPI_Comm_split function and one collective operation. 
Output received numbers in these processes in ascending order of ranks of sending processes 
(including the number received from itself).*/ 

//example:comm3:MPI_Comm_split(MPI_COMM_WORLD, color, rank, &comm); 
void Solve()
{
    Task("MPI5Comm9");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;

    int rank, size, n;
    double a;
    pt>>n;
    if(n==1)
      pt>>a;
    
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    int color = (n == 1) ? 1 : MPI_UNDEFINED;
    MPI_Comm comm;
    MPI_Comm_split(MPI_COMM_WORLD, color, rank, &comm);

    if (comm == MPI_COMM_NULL)
        return;

    MPI_Comm_size(comm, &size);
    MPI_Comm_rank(comm, &rank);

    std::vector<double> res(size), data(1, a);

    MPI_Allgather(&data[0], 1, MPI_DOUBLE, &res[0], 1, MPI_DOUBLE, comm);

    copy(res.begin(), res.end(), ptout_iterator<double>());
}
