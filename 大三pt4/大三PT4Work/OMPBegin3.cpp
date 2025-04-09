#include "pt4.h"
#include <cmath>
#include <omp.h>
using namespace std;

double F0(double x, int i)
{
    double f0 = 0;
    for (int j = 1; j <= i; j++)
        f0 += (j + cos(x + j)) / (2 * i * j - 1);
    return f0;
}

double Fnp(double x, int n)
{
    double f = 0;
    for (int i = 1; i <= n; i++)
        f += 1 / F0(x, i);
    return f;
}

const int nthreads = 2;

double time[nthreads];
int cnt[nthreads];

double Fp(double x, int n)
{
    double f = 0;
#pragma omp parallel reduction(+: f) 
    {  
        double t = omp_get_wtime();
        int c = 0;
#pragma omp for schedule(static, 1)   
        for (int i = 1; i <= n; i++)
        {
            f += 1 / F0(x, i);
            c += i;
        }    
        time[omp_get_thread_num()] = omp_get_wtime() - t;
        cnt[omp_get_thread_num()] = c;
    }        
    return f;
}


void Solve()
{
    Task("OMPBegin3");
    double x, fnp, fp, t1, t2;
    int n;
    pt >> x >> n;
    t1 = omp_get_wtime();
    fnp = Fnp(x, n);
    t1 = omp_get_wtime() - t1;
    pt << fnp;
    ShowLine("Non-parallel time:", t1 * 1000);

    omp_set_num_threads(nthreads);
    ShowLine("num_procs:", omp_get_num_procs());
    ShowLine("num_threads:", omp_get_max_threads());

    pt >> x >> n;
    t2 = omp_get_wtime();
    fp = Fp(x, n);
    t2 = omp_get_wtime() - t2;
    pt << fp;
    for (int i = 0; i < nthreads; i++)
    {
        Show("thread_num:", i);
        Show("Count:", cnt[i]);
        ShowLine("Thread time:", time[i] * 1000);
    }
    ShowLine("Total parallel time:", t2 * 1000);
    ShowLine("Rate:", t1 / t2);
}
