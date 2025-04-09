#include "pt4.h"
#include "mpi.h"
/*
The number of processes K is an even number: K = 2N, N > 1.
A real number A is given in each process. 
Define a Cartesian topology for all processes as a two-dimensional (2 ? N) grid (namely, matrix); 
ranks of processes should not be reordered. 
Using the MPI_Sendrecv function, perform a cyclic shift of data given in all processes of each row of the matrix by step 1 
(that is, the number A should be sent from each process in the row, except the last process, to the next process in the same row and from the last process in the row to the first process in the same row).
Ranks of source and destination process should be determined by means of the MPI_Cart_shift function. 
Output received data in each process.

*/
//according to the title, the number of rows is acyclic and the number of columns is cyclic

void Solve()
{
    Task("MPI5Comm26");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    double a,a1;
    pt>>a;

    int n=size/2;
    int dims[2] = { 2, n };
    int periodic[2] = { 0,1 }; 
    int reorder = 0;
    MPI_Comm cart_comm;
    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periodic, reorder, &cart_comm);
    
    int left,right;
    MPI_Cart_shift(cart_comm, 1, 1, &left, &right);


    MPI_Sendrecv(&a, 1, MPI_DOUBLE, right, 0, 
                 &a1, 1, MPI_DOUBLE, left, 0, 
                 cart_comm, MPI_STATUS_IGNORE);

    pt<<a1 ;

}
