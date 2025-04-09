#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI4Type13");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    int R = rank; // R ?????
    int data_size = sizeof(double) + R * sizeof(int); // ????????

    if (rank != 0) {
        double real_num;
        // ??????????? R ???
        pt >> real_num;
        int integers[R]; // ?????????
        for (int i = 0; i < R; ++i) {
            pt >> integers[i]; // ?? R ???
        }

        char buf[data_size];
        int position = 0;
        MPI_Pack(&real_num, 1, MPI_DOUBLE, buf, data_size, &position, MPI_COMM_WORLD);
        MPI_Pack(integers, R, MPI_INT, buf, data_size, &position, MPI_COMM_WORLD); // ??????
        
        MPI_Send(buf, data_size, MPI_PACKED, 0, 0, MPI_COMM_WORLD);
    } else {
        char recv_buf[(size - 1) * (sizeof(double) + (size - 1) * sizeof(int))]; // ????????

        // ???????????
        for (int i = 1; i < size; ++i) {
            MPI_Recv(&recv_buf[(i - 1) * (sizeof(double) + (i) * sizeof(int))], sizeof(double) + (i) * sizeof(int), MPI_PACKED, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        // ??????????
        for (int i = 1; i < size; ++i) {
            double real_num;
            int integers[i]; // ????????? R ???
            int position = 0;

            MPI_Unpack(&recv_buf[(i - 1) * (sizeof(double) + (i) * sizeof(int))], sizeof(double) + (i) * sizeof(int), &position, &real_num, 1, MPI_DOUBLE, MPI_COMM_WORLD);           
            MPI_Unpack(&recv_buf[(i - 1) * (sizeof(double) + (i) * sizeof(int))], sizeof(double) + (i) * sizeof(int), &position, integers, i, MPI_INT, MPI_COMM_WORLD);
            
            pt << real_num; // ????
            ShowD(real_num);
            for (int j = 0; j < i; j++) {
                pt << integers[j]; // ?? R ???
            }
        }
    }
}
