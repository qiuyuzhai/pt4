#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI6File23");

    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;

    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size); 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 

    char name[12];
    if (rank == 0)
        pt >> name; 

    // 广播文件名
    MPI_Bcast(name, 12, MPI_CHAR, 0, MPI_COMM_WORLD); 

    MPI_File f;
    MPI_File_open(MPI_COMM_WORLD, name, MPI_MODE_RDONLY, MPI_INFO_NULL, &f);

    // 获取 MPI_DOUBLE 的 extent
    MPI_Aint lb, extent;
    MPI_Type_get_extent(MPI_DOUBLE, &lb, &extent);

    // 定义文件视图
    MPI_Datatype filetype;
    MPI_Aint displacements[6]; // 每个块的偏移
    int blocklengths[6];       // 每个块的长度
    MPI_Datatype types[6];     // 每个块的数据类型

    // 设置6个块分别对应A, B, C, D, E, F
    for (int i = 0; i < 3; ++i)
    {
        displacements[i] = rank * 3 * extent + i * extent;           // A, B, C 部分
        displacements[i + 3] = (size * 3 + rank * 3 + i) * extent;  // D, E, F 部分
        blocklengths[i] = 1;  // 每块一个元素
        blocklengths[i + 3] = 1;
        types[i] = MPI_DOUBLE;      // 数据类型为 MPI_DOUBLE
        types[i + 3] = MPI_DOUBLE; // 数据类型为 MPI_DOUBLE
    }

    // 使用 MPI_Type_create_struct 创建文件视图
    MPI_Type_create_struct(6, blocklengths, displacements, types, &filetype);
    MPI_Type_commit(&filetype);

    // 设置文件视图
    MPI_File_set_view(f, 0, MPI_DOUBLE, filetype, "native", MPI_INFO_NULL);

    // 读取数据
    double buf[6];
    MPI_File_read_all(f, buf, 6, MPI_DOUBLE, MPI_STATUS_IGNORE);

    // 输出数据
    for (int i = 0; i < 6; ++i)
        pt << buf[i]; 

    // 清理资源
    MPI_Type_free(&filetype); 
    MPI_File_close(&f); 
}
