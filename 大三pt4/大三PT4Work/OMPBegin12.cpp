#include "pt4.h"
#include <cmath>
#include <omp.h>
using namespace std;

double F0(double x, int i, int n)
{
    double f0 = 0;
    for (int j = i; j <= 2 * n; j++)
        f0 += (j + log(1 + x + j)) / (2 * i * j - 1);
    return f0;
}

double Fnp(double x, int n)
{
    double fnp = 0;
    for (int i = 1; i <= n; i++)
        fnp += 1 / F0(x, i, n);
    return fnp;
}

// const int nthreads=2;
double time[2]; // 记录每个线程的运行时间
int cnt[2];     // 记录每个线程的循环计数

double Fp(double x, int n, int K)
{
    double f1 = 0, f2 = 0;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            double t = omp_get_wtime(); // 开始计时
            cnt[0] = 0; // 初始化计数
            for (int i = 1; i <= K; i++)
            {
                f1 += 1 / F0(x, i, n);
                cnt[0]+=i; // 记录循环次数
            }
            time[0] = omp_get_wtime() - t; // 计算线程运行时间
        }

        #pragma omp section
        {
            double t = omp_get_wtime(); // 开始计时
            cnt[1] = 0; // 初始化计数
            for (int i = K + 1; i <= n; i++)
            {
                f2 += 1 / F0(x, i, n);
                cnt[1]+=i; // 记录循环次数
            }
            time[1] = omp_get_wtime() - t; // 计算线程运行时间
        }
    }

    return f1 + f2; // 返回并行部分计算结果
}

void Solve()
{
    Task("OMPBegin12");
    double x, fnp, fp, t1, t2;
    int n;

    // 输入 x 和 n
    pt >> x >> n;
    // 非并行部分
    t1 = omp_get_wtime();
    fnp = Fnp(x, n);
    t1 = omp_get_wtime() - t1;
    pt << fnp;
    ShowLine("Non-parallel time:", t1 * 1000); // 显示非并行时间
    
    omp_set_num_threads(2);
    // 系统信息
    ShowLine("num_procs:", omp_get_num_procs()); // 显示可用处理器数量
    ShowLine("num_threads:", omp_get_max_threads()); // 显示最大线程数量

    // 重新输入数据
    pt >> x >> n;

    // 设置线程数量
    // omp_set_num_threads(2); // 设置为两个线程并行

    // 分段点
    int K = n / 2;

    // 并行部分
    t2 = omp_get_wtime();
    fp = Fp(x, n, K);
    t2 = omp_get_wtime() - t2;
    pt << fp;

    // 显示每个线程的信息
    for (int i = 0; i < 2; i++)
    {
        Show("thread_num:", i); // 显示线程编号
        Show("Count:", cnt[i]); // 显示线程循环计数
        ShowLine("Thread time:", time[i] * 1000); // 显示线程运行时间（毫秒）
    }

    ShowLine("Total parallel time:", t2 * 1000); // 显示总并行时间

    // 加速比
    ShowLine("Rate:", t1 / t2); // 计算加速比
}
