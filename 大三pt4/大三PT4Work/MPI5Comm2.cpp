#include "pt4.h"
#include "mpi.h"
#include <vector>
#include <algorithm>
// use  MPI_Comm_group, MPI_Group_excl, and MPI_Comm_create
// 1.MPI_Comm_group(MPI_Comm comm, MPI_Group *group);
// 2.MPI_Group_excl(MPI_Group group, int n, const int *ranks, MPI_Group *newgroup);
// 3.MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm);

/*Two real numbers are given in each process whose rank is an odd number (1, 3, …).
Create a new communicator that contains all odd-rank processes using the MPI_Comm_group, MPI_Group_excl, and MPI_Comm_create functions. 
Send all given numbers to each odd-rank process using one collective operation with the created communicator. Output received numbers in each odd-rank process in ascending order of ranks of sending processes (including numbers received from itself).

*/

void Solve()
{
    Task("MPI5Comm2");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // 1: receive the whole group
    MPI_Group world_group;
    MPI_Comm_group(MPI_COMM_WORLD, &world_group);

    // 2: creat a new group
    std::vector<int> even_ranks;
    for (int i = 0; i < size; i += 2) 
        even_ranks.push_back(i);
    MPI_Group odd_group;
    MPI_Group_excl(world_group, even_ranks.size(), even_ranks.data(), &odd_group);

    // 3: new communicator
    MPI_Comm odd_comm;
    MPI_Comm_create(MPI_COMM_WORLD, odd_group, &odd_comm);

    // 4: 
    if (odd_comm != MPI_COMM_NULL)
    {
        std::vector<double> data(ptin_iterator<double>(2), ptin_iterator<double>());

        int odd_size;
        MPI_Comm_size(odd_comm, &odd_size);    
        std::vector<double> res(2 * odd_size); 

        MPI_Allgather(data.data(), 2, MPI_DOUBLE, res.data(), 2, MPI_DOUBLE, odd_comm);

        copy(res.begin(), res.end(), ptout_iterator<double>());
    }
}
