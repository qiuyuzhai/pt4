#include "pt4.h"
using namespace std;
int gcd(int a, int b) 
{
    if (b == 0) 
        return a;
    else
        return gcd(b, a % b);
}

void Solve()
{
    Task("Recur9");
    int A, B, C, D;
    pt >> A >> B >> C >> D;
    pt << gcd(A, B);
    pt << gcd(A, C);
    pt << gcd(A, D);

}
