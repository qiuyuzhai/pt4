#include "pt4.h"
#include "mpi.h"
#include <vector>
#include <algorithm>

void Solve() {
    Task("MPI3Coll26");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // ???????????
    int n = size * (size + 3) / 2; 

    // ????
    std::vector<int> sendbuf(n);
    for (int i = 0; i < n; i++) {
        pt >> sendbuf[i];
    }

    // ?????????
    std::vector<int> all_data(size * n);
    MPI_Gather(sendbuf.data(), n, MPI_INT, all_data.data(), n, MPI_INT, 0, MPI_COMM_WORLD);

    // ????0????????
    std::vector<int> all_mins(size * (size + 3) / 2);
    if (rank == 0) {
        std::vector<int> combined_data;
        for (int i = 0; i < size; ++i) {
            combined_data.insert(combined_data.end(), all_data.begin() + i * n, all_data.begin() + (i + 1) * n);
        }
        std::sort(combined_data.begin(), combined_data.end());
        
        int index = 0;
        for (int i = 0; i < size; ++i) {
            int count = i + 2; // ??0??2????1??3?
            for (int j = 0; j < count; ++j) {
                all_mins[index++] = combined_data[i + j];
            }
        }
    }

    // ??????????
    std::vector<int> recv_mins(size + 2);
    MPI_Scatter(all_mins.data(), rank + 2, MPI_INT, recv_mins.data(), rank + 2, MPI_INT, 0, MPI_COMM_WORLD);

    // ????????
    for (int i = 0; i < rank + 2; i++) {
        pt << recv_mins[i];
    }
}
