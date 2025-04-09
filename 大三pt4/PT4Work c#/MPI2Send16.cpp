#include "pt4.h"
#include "mpi.h"
/*
An integer N is given in each process; 
the value of N is equal to 1 for one process and is equal to 0 for others. 
Also a sequence of K ? 1 real numbers is given in the process with nonzero integer N; 
K is the number of processes. 
Send each number from the given sequence to one of other processes 
in ascending order of ranks of receiving processes. 
Output the received number in each process.
*/
void Solve()
{
    Task("MPI2Send16");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status s;
    int n;
    double c;
    pt>>n;
    if(n==1)
    {
        
        for(int i=0;i<size;i++)
        {
            if (i == rank)
                continue;
            pt>>c;
            MPI_Ssend(&c, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
        }  
        
    }
    else
    {
        MPI_Recv(&c, 1, MPI_DOUBLE, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &s); //don't know the rank,so use the MPI_ANY_SOURCE
        pt<<c;

    }

}
