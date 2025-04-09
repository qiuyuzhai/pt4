#include "pt4.h"
#include "mpi.h"
//see the example
void Solve() {
    Task("MPI4Type14"); // Set the task name for MPI

    int flag;
    MPI_Initialized(&flag); // Check if MPI is initialized
    if (flag == 0)
        return; // If MPI is not initialized, exit the function

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Get the total number of processes
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Get the rank of the current process

    if (rank == 0) { // Master process
        int k = size - 1; // Number of slave processes
        int *a = new int[3 * k]; // Array to hold 3K integers
        int *n = new int[k]; // Array to hold K integers for counts

        // Read the array A (3K integers)
        for (int i = 0; i < 3 * k; ++i)
            pt >> a[i];

        // Read the array N (K integers)
        for (int i = 0; i < k; ++i)
            pt >> n[i];

        MPI_Datatype t; // Define a new MPI data type
        int int_sz;
        MPI_Type_size(MPI_INT, &int_sz); // Get the size of an integer type

        // Create a new datatype with a hole of size equal to an integer
        MPI_Type_create_resized(MPI_INT, 0, 2 * int_sz, &t);
        MPI_Type_commit(&t); // Commit the new datatype

        // Send NR elements of array A to each slave process
        for (int i = 1; i < size; ++i)
            MPI_Send(&a[i - 1], n[i - 1], t, i, 0, MPI_COMM_WORLD);

        delete[] a; // Free allocated memory for A
        delete[] n; // Free allocated memory for N
    } else { // Slave processes
        MPI_Status s; // Status object for receiving messages
        MPI_Probe(0, 0, MPI_COMM_WORLD, &s); // Probe to check the incoming message from process 0
        int n;
        MPI_Get_count(&s, MPI_INT, &n); // Get the count of integers being received

        int *a = new int[n]; // Allocate array for receiving data
        MPI_Recv(a, n, MPI_INT, 0, 0, MPI_COMM_WORLD, &s); // Receive data from the master process

        // Output received data
        for (int i = 0; i < n; ++i)
            pt << a[i];

        delete[] a; // Free allocated memory for received data
    }
}
