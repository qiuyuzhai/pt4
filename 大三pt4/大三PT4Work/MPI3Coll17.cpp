#include "pt4.h"
#include "mpi.h"
// see the example
/*
int MPI_Alltoallv(const void *sendbuf, const int *sendcounts, const int *sdispls, MPI_Datatype sendtype,
                  void *recvbuf, const int *recvcounts, const int *rdispls, MPI_Datatype recvtype,
                  MPI_Comm comm);
*/

void Solve()
{
    Task("MPI3Coll17");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    //required area
    double sendbuf[size + 1];
    double recvbuf[size*2];
    int recvcounts[size];
    int rdispls[size];
    int sdispls[size];
    int sendcounts[size];
    // input data
    for (int i = 0; i < size + 1; i++)
    {
        pt >> sendbuf[i]; 
    }
    sdispls[0]=0;
    rdispls[0]=0;
    for (int i = 0; i < size; i++)
    {
        sendcounts[i]=2;
        recvcounts[i]=2;  
        sdispls[i]=i;//Error-prone
        rdispls[i]=i*2; 
    } 
    MPI_Alltoallv(sendbuf, sendcounts, sdispls, MPI_DOUBLE,
                  recvbuf, recvcounts, rdispls, MPI_DOUBLE,
                  MPI_COMM_WORLD);

    // output
    for (int i = 0; i < size * 2; i++)
    {
        pt<< recvbuf[i];
    }
}
