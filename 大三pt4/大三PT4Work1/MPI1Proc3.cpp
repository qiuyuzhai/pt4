#include "pt4.h"

#include "mpi.h"
/*Input a real number X and output its opposite value in the master process. 
Also output the rank of slave processes (which are processes whose rank is greater than 0); 
the rank of each process should be output in the process of this rank. 
In addition, duplicate the data output in the debug section by displaying the value of −X with the "-X=" comment and the rank values with the "rank=" comments (use the Show function calls with two parameters).*/
void Solve()
{
    Task("MPI1Proc3");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    double x;
    if(rank==0)
    {
        pt>>x;
        pt<<-x;
    }
    else
    {
        pt<<rank;
    }
    //    
    // ShowLine("-x=",-x);
    

}
