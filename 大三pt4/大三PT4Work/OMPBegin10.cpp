#include "pt4.h"
#include <cmath>
#include <omp.h>
using namespace std;

double F0(double x, int i, int n)
{
    double f0 = 0;
    for (int j = 1; j <= i + n; j++)
        f0 += (j + log(1 + x + j)) / (2 * i * j - 1);
    return f0;
}

double Fnp(double x, int n)
{
    double f = 0;
    for (int i = 1; i <= n; i++)
        f += 1 / F0(x, i, n);
    return f;
}

void Solve()
{
    Task("OMPBegin10");
    double x, fnp, fp, t1, t2;
    int n;
    pt >> x >> n;
    t1 = omp_get_wtime();
    fnp = Fnp(x, n);
    t1 = omp_get_wtime() - t1;
    pt << fnp;
    ShowLine("Non-parallel time:", t1 * 1000);

    omp_set_num_threads(2);
    ShowLine("num_procs:", omp_get_num_procs());
    ShowLine("num_threads:", omp_get_max_threads());

    pt >> x >> n;

    int K = (n - 1) / 2;  // Derived from balancing the summation work

    t2 = omp_get_wtime();
    double f1 = 0, f2 = 0;

#pragma omp parallel sections
    {
#pragma omp section
        {
            for (int i = 1; i <= K; i++)
                f1 += 1 / F0(x, i, n);
        }
#pragma omp section
        {
            for (int i = K + 1; i <= n; i++)
                f2 += 1 / F0(x, i, n);
        }
    }

    fp = f1 + f2;
    t2 = omp_get_wtime() - t2;
    pt << fp;
    ShowLine("Total parallel time:", t2 * 1000);
    ShowLine("Rate:", t1 / t2);
}
