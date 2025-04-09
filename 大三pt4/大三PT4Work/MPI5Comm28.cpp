#include "pt4.h"
#include "mpi.h"
#include <vector>

void Solve()
{
    Task("MPI5Comm28");
    int rank, size, flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int a;
    pt >> a;
    int half_count = size / 2;
    int n = (size - 1) / 2;

    MPI_Comm graph_comm;

    std::vector<int> arr(size, half_count);
    int edges_size = arr[size - 1];
    int edges[edges_size];

    for (int i = 1; i < size; ++i)
    {
        int step = (i % 2 == 1) ? 2 : 1;
        arr[i] = arr[i - 1] + step;
    }
    
    for (int i = 0; i < half_count; ++i)
    {
        edges[i] = 2 * i + 1;
    }

    int index = 1, odd_counter = 0;
    for (int i = half_count; i < edges_size; ++i)
    {
        if (odd_counter == 0)
        {
            edges[i] = 0;
            odd_counter++;
        }
        else if (odd_counter == 1)
        {
            index++;
            edges[i] = index;
            odd_counter++;
        }
        else
        {
            edges[i] = index - 1;
            index++;
            odd_counter = 0;
        }
    }

    MPI_Graph_create(MPI_COMM_WORLD, size, arr.data(), edges, 0, &graph_comm);

    int neighbor_count;
    MPI_Graph_neighbors_count(graph_comm, rank, &neighbor_count);
    int neighbors[neighbor_count];
    MPI_Graph_neighbors(graph_comm, rank, neighbor_count, neighbors);

    for (const auto &neighbor : neighbors)
    {
        int received_value;
        MPI_Send(&a, 1, MPI_INT, neighbor, 0, graph_comm);
        MPI_Status status;
        MPI_Recv(&received_value, 1, MPI_INT, neighbor, 0, graph_comm, &status);
        pt << received_value;
    }
}
