#include "pt4.h"

#include "mpi.h"
/*
    int dims[] = {k0, k0}, 
        periods[] = {1, 1}; 
    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, 0, &comm); 

    int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int *coords);
    //Used to obtain the coordinates of a process in the Cartesian topology

     An integer N (> 1) is given in the master process; the number of processes K is assumed to be a multiple of N. 
     Send the integer N to all processes and define a Cartesian topology for all processes as a (N ? K/N) 
     Find the process coordinates in the created topology using the MPI_Cart_coords function and output the process coordinates in each process. 

*/
void Solve()
{
    Task("MPI5Comm13");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int n;
    if(rank==0){
          pt>>n;
    }
     MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD); //Broadcast N to all processes
    if(size%n!=0)
      return;
    int dims[2] = {n, size / n}; 
    int periods[2] = {0, 0}; 
    MPI_Comm cart_comm; 
    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, 0, &cart_comm); 

    // receive the coodinate
    int coords[2];
    MPI_Cart_coords(cart_comm, rank, 2, coords); 

    pt<<coords[0]<<coords[1];

    
    


}
