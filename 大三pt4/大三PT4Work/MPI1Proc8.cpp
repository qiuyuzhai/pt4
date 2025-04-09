#include "pt4.h"
#include "mpi.h"
/*An integer N (> 0) and a sequence of N real numbers are given in each process. 
Output the sum of given numbers in each process with even rank (including the master process), 
output the average of given numbers in each process with odd rank.*/

void Solve()
{
    Task("MPI1Proc8");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int N;
    double a,ave=0,sum=0;
    pt>>N;
    for(int i=0;i<N;i++)
    {
        pt>>a;
        sum+=a;
        ave=sum/N;
    }
        
    if(rank%2==0)
    {
        
           pt<<sum;
    }
    else
    {
        pt<<ave;
    }

}
