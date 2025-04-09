#include "pt4.h"

#include "mpi.h"

void Solve()
{
    Task("MPI6File28");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    char filename[12];
    if (rank == 0)
        pt >> filename;
    MPI_Bcast(filename, 12, MPI_CHAR, 0, MPI_COMM_WORLD);

    // 每个进程读取整数 N 和 K/2 个实数
    int n;
    pt >> n;
    int c = size / 2;
    double data[c];
    for (int i = 0; i < c; ++i)
        pt >> data[i];

    // 打开文件
    MPI_File file;
    MPI_File_open(MPI_COMM_WORLD, filename, MPI_MODE_CREATE | MPI_MODE_WRONLY, MPI_INFO_NULL, &file);

    // 计算每个进程的偏移量
    int dbl_sz;
    MPI_Type_size(MPI_DOUBLE, &dbl_sz);

    // 创建文件视图
    MPI_Datatype t0, t;
    MPI_Type_vector(c, 1, size, MPI_DOUBLE, &t0);
    MPI_Type_create_resized(t0, 0, dbl_sz, &t);
    MPI_Type_commit(&t);

    // 设置文件视图
    MPI_File_set_view(file, (n - 1) * dbl_sz, MPI_DOUBLE, t, "native", MPI_INFO_NULL);

    // 写入数据
    MPI_File_write_all(file, data, c, MPI_DOUBLE, MPI_STATUS_IGNORE);

    // 关闭文件
    MPI_File_close(&file);

    // 释放 MPI 数据类型
    MPI_Type_free(&t);
}
