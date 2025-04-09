#include "pt4.h"
#include "mpi.h"
/* A sequence of R + 2 integers is given in each process;
R is the rank of process (that is, two integers are given in the process 0, three integers are given in the process 1, and so on).
Send given integers to all processes using the MPI_Allgatherv function.
Output received data in each process in ascending order of ranks of sending processes (including the numbers received from itself).
*/
void Solve()
{
    Task("MPI3Coll13");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int num_ele = rank + 2;
    int sendbuf[num_ele];
    for (int i = 0; i < num_ele; i++)
    {
        pt >> sendbuf[i];
    }
    int recvcounts[size];
    int displs[size];
    for (int i = 0; i < size; i++)
    {
        recvcounts[i] = i + 2;
    }
    displs[0]=0;
    //the recursive method can be used here
    for (int i = 1; i < size; i++) {
        displs[i] = displs[i - 1] + recvcounts[i - 1];
    }    

    int total_revc_size=displs[size-1]+recvcounts[size - 1];
    int recvbuf[total_revc_size];

    MPI_Allgatherv(sendbuf, num_ele, MPI_INT,   // Sending data
                   recvbuf, recvcounts, displs, MPI_INT, // Receiving data
                   MPI_COMM_WORLD);
    for (int i = 0; i < total_revc_size; i++) {
        pt << recvbuf[i];
    }    
}
