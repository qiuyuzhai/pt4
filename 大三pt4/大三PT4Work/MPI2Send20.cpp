#include "pt4.h"
#include "mpi.h"
#include <fstream>
#include <vector>
#include <algorithm>
/*A real number A and its order number N (as an integer) are given in each slave process; 
the set of integers N contains all values in the range 0 to K-1, K is the number of processes. 
Send all numbers A to the master process and output the received numbers in ascending order of their order numbers N. 
Do not use arrays. Use the order number N as a msgtag parameter of the MPI_Send function.*/
void Solve()
{
    Task("MPI2Send20");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    double a;
    int n;
    MPI_Status s;
    if(rank>0)
    {
      pt>>a;
      pt>>n;
      MPI_Send(&a, 1, MPI_DOUBLE, 0, n, MPI_COMM_WORLD);
    }
    else
    {
        std::vector<std::pair<int, double>> data;
        for (int i = 1; i < size; i++) {
            MPI_Recv(&a, 1, MPI_DOUBLE, i, MPI_ANY_TAG, MPI_COMM_WORLD, &s);
            data.emplace_back(s.MPI_TAG, a); // Store the pair (n, a) in the vector
        }
        std::sort(data.begin(), data.end());
        for (const auto& pair : data) {
            pt << pair.second ; // Write sorted a values to output
        }
    }
}
