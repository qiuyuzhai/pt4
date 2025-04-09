#include "pt4.h"
#include <cmath>
#include <omp.h>
using namespace std;

// ?? omp_get_thread_num?? ??????? 2?????????? F?X? N? ????????????
// F ????f?X? N? = ?NI=1 1/??IJ=1 ?J + ?X + J?1/3?/?2IJ ? 1??
// ? debug ???????????????????????????????????????????
// ???????????????????? I ????????????????? I ?????????

double Fnp(double x, int n) // ???????F???????
{
    double res = 0.0;
    for (int i = 1; i <= n; i++)
    {
        double tmp = 0.0;
        for (int j = 1; j <= i; j++)
            tmp += (j + pow((x + j), 1.0 / 3.0)) / (2 * i * j - 1);
        res += 1.0 / tmp;
    }
    return res;
}

double Fp(double x, int n) // ??????F?????????
{
    double res = 0.0;
#pragma omp parallel num_threads(2) reduction(+ : res) // OpenMP???????2????????res????
    {
        int num = omp_get_thread_num(); // ????????
        int cnt = 0;
        double time = omp_get_wtime(); // ?????????????????
        for (int i = num + 1; i <= n; i += 2)
        {
            double tmp = 0.0;
            for (int j = 1; j <= i; j++)
            {
                tmp += (j + pow((x + j), 1.0 / 3.0)) / (2 * i * j - 1);
                cnt++;
            }
            res += 1.0 / tmp;
        }
        double ptime = omp_get_wtime() - time; // ??????????
        Show("thread_num: ", num);
        Show("Cnt: ", cnt);
        ShowLine("Thread time: ", ptime);
    }
    return res;
}

void Solve()
{
    Task("OMPBegin1");
    double x;
    int n;
    // ?????
    pt >> x >> n;
    double t = omp_get_wtime();
    double res = Fnp(x, n);
    double nptm = omp_get_wtime() - t;
    ShowLine("Non-parallel time: ", nptm);
    pt << res;
    // ????
    pt >> x >> n;
    t = omp_get_wtime();
    res = Fp(x, n);
    double ptm = omp_get_wtime() - t;
    ShowLine("Total parallel time: ", ptm);
    ShowLine("Rate: ", nptm / ptm);
    pt << res;
}
