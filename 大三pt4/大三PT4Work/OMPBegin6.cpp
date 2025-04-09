#include "pt4.h"
#include <cmath>
#include <omp.h>
using namespace std;

// 内层和
double F0(double x, int i, int n)
{
    double f0 = 0;
    for (int j = 1; j <= i + n; j++)
        f0 += (j + sin(x + j)) / (2 * i * j - 1); // 分子分母要加括号
    return f0;
}

// 外层和（非并行版本）
double F(double x, int n)
{
    double f = 0;
    for (int i = 1; i <= n; i++) // 不要漏了等号
        f += 1 / F0(x, i, n);
    return f;
}

double time[4];
int cnt[4];

// 并行版本：使用反向带状算法
double Fp(double x, int n)
{
    double fp = 0;  // 存储最终结果

    // 开启一个并行区域，指定使用 4 个线程进行计算，并且对 fp 使用 "reduction" 操作，确保线程之间对 fp 的更新是安全的。
    #pragma omp parallel num_threads(4) reduction(+:fp)
    {
        int id = omp_get_thread_num();  // 获取当前线程的 ID
        int band_size = 8;  // 题目要求的带宽
        int total_bands = n / band_size;  // 带状数量，假设 n 是 8 的倍数

        double t=0;
        int c=0;

        t=omp_get_wtime();
        // 处理每个带状
        for (int b = 0; b < total_bands; b++)
        {
            int start_idx = b * band_size + 1;  // 计算当前带的起始索引
            int end_idx = start_idx + band_size - 1;  // 计算当前带的结束索引

            // 按照线程 id 分配任务，确保线程间均衡
            for (int i = start_idx + id; i <= end_idx; i += 4)
            {
                // 计算每个 i 对应的内层和 F0(x, i, n)
                double fp1 = F0(x, i, n);
                
                // 更新 fp，保证并行计算时对 fp 的累加是线程安全的
                fp += 1.0 / fp1;
                c+=i;
            }
            
        }
        t=omp_get_wtime()-t;
        time[id]=t;
        cnt[id]=c;
    }
    return fp;
}

void Solve()
{
    Task("OMPBegin6");
    double x, f, fp, t1, t2;
    int n;
    pt >> x >> n;

    // 非并行计算
    t1 = omp_get_wtime();
    f = F(x, n);
    t1 = omp_get_wtime() - t1;
    pt << f;
    ShowLine("Non-parallel time:", t1 * 1000);


    // 显示调试信息
    ShowLine("num_procs:", omp_get_num_procs());
    ShowLine("num_threads:", omp_get_max_threads());

    // 并行计算
    pt >> x >> n;
    omp_set_num_threads(4);  // 设置并行部分使用 4 个线程
    t2 = omp_get_wtime();
    fp = Fp(x, n);
    t2 = omp_get_wtime() - t2;
    pt << fp;

    // 输出调试信息：显示每个线程的计算时间和累加的计数
    for (int i = 0; i < 4; i++) {
        Show("thread_num:", i);
        Show("Count:",cnt[i]);
        ShowLine("Thread time:", t2 * 1000);
    }

    // 输出并行计算结果和加速比
    ShowLine("Total parallel time:", t2 * 1000);
    ShowLine("Rate:", t1 / t2);
}
