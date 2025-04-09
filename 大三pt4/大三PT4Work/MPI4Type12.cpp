#include "pt4.h" // ??pt4.h???
#include "mpi.h" // ??MPI???

void Solve()
{
    Task("MPI4Type12"); // ??????
    int flag;
    MPI_Initialized(&flag); // ??MPI?????
    if (flag == 0)
        return; // ??????????

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size); // ??????
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // ?????????

    int k = size - 1; // ???????
    int triple_size = 2 * sizeof(int) + sizeof(double); // ???????????

    if (rank != 0) // ???????
    {
        int n1, n2;
        double dou;
        pt >> n1 >> n2 >> dou; // ?pt???n1, n2?dou

        char buf[triple_size]; // ?????
        int position = 0; // ???????

        // ?????????
        MPI_Pack(&n1, 1, MPI_INT, buf, triple_size, &position, MPI_COMM_WORLD);
        MPI_Pack(&n2, 1, MPI_INT, buf, triple_size, &position, MPI_COMM_WORLD);
        MPI_Pack(&dou, 1, MPI_DOUBLE, buf, triple_size, &position, MPI_COMM_WORLD);

        // ???????????
        MPI_Send(buf, triple_size, MPI_PACKED, 0, 0, MPI_COMM_WORLD);
    }
    else // ??????
    {
        char recv_buf[k * triple_size]; // ???????

        // ?????????????
        for (int i = 1; i <= k; ++i)
        {
            MPI_Recv(&recv_buf[(i - 1) * triple_size], triple_size, MPI_PACKED, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        // ???????????
        for (int i = 1; i <= k; ++i)
        {
            int n1, n2;
            double dou;
            int position = 0; // ???????

            // ????????
            MPI_Unpack(&recv_buf[(i - 1) * triple_size], triple_size, &position, &n1, 1, MPI_INT, MPI_COMM_WORLD);
            MPI_Unpack(&recv_buf[(i - 1) * triple_size], triple_size, &position, &n2, 1, MPI_INT, MPI_COMM_WORLD);
            MPI_Unpack(&recv_buf[(i - 1) * triple_size], triple_size, &position, &dou, 1, MPI_DOUBLE, MPI_COMM_WORLD);
            
            pt << n1 << n2 << dou; // ???????
        }
    }
}
