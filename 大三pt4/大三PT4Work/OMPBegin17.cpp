#include "pt4.h"
#include <cmath>
#include <omp.h>
using namespace std;
//在执行任务时，除了输出所需的结果外，还需要在任务书窗口的调试部分显示以下信息：
// 1> Non-parallel time: 288.85
// 2> num_procs: 2
// 3> num_threads: 2
// 4> thread_num: 1 Count: 2348556 Thread time: 134.81
// 5> thread_num: 0 Count: 2350089 Thread time: 132.73
// 6> Total parallel time: 138.80
// 7> Rate: 2.08
//实现计算函数 F(X, N) 的两个版本：非并行和并行版本，基于使用静态版本的 for 指令（线程数量为 2）。函数 F 的公式为：
// F(X, N) = ΣI=1..N 1/(ΣJ=1..I (J + cos(X + J))/(2IJ − 1))

double F0(double x, int i)//分母部分
{
    double f0 = 0;
    for (int j = 1; j <= i; j++)
        f0 += (j + cos(x + j)) / (2 * i * j - 1);
    return f0;
}

double Fnp(double x, int n)//整个函数
{
    double f = 0;
    for (int i = 1; i <= n; i++)
        f += 1 / F0(x, i);
    return f;
}

const int nthreads = 2;

double time[nthreads];
int cnt[nthreads]; //存储当前线程处理的求和项的数量

double Fp(double x, int n)
{
    double f = 0;
#pragma omp parallel reduction(+ \
                               : f)
    {
        double t = omp_get_wtime(); //当前线程执行任务时间开始
        int c = 0;                  //每个线程前把c清零
#pragma omp for schedule(static, 1)
        for (int i = 1; i <= n; i++)
        {
            f += 1 / F0(x, i);
            c += i; //当前线程处理的求和项的数量
        }
        time[omp_get_thread_num()] = omp_get_wtime() - t; //当前线程执行时间结束
        cnt[omp_get_thread_num()] = c;
    }
    return f;
}

void Solve()
{
    Task("OMPBegin17");
    double x, fnp, fp, t1, t2;
    int n;
    pt >> x >> n;
    t1 = omp_get_wtime(); //非并行版本时间开始
    fnp = Fnp(x, n);
    t1 = omp_get_wtime() - t1; //非并行版本时间结束
    pt << fnp;
    ShowLine("Non-parallel time:", t1 * 1000);

    omp_set_num_threads(nthreads);
    ShowLine("num_procs:", omp_get_num_procs());     //可用的处理器数量
    ShowLine("num_threads:", omp_get_max_threads()); //并行程序的线程数量

    pt >> x >> n;
    t2 = omp_get_wtime();
    fp = Fp(x, n);
    t2 = omp_get_wtime() - t2;
    pt << fp;
    for (int i = 0; i < nthreads; i++)
    {
        Show("thread_num:", i); //线程编号
        Show("Count:", cnt[i]);
        ShowLine("Thread time:", time[i] * 1000);
    }
    ShowLine("Total parallel time:", t2 * 1000);
    ShowLine("Rate:", t1 / t2);
}
