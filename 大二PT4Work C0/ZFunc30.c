#include "pt4.h"
// Write a procedure AddLeftDigit(D, K)
//  that adds a digit D to the left side of the decimal representation of a positive integer K
//  (D is an input integer parameter with the value in the range 0 to 9, K is an input and output integer parameter).
//  Having input an integer K and two one-digit numbers D1, D2 and using two calls of this procedure, sequentially add the given digits D1, D2 to the left side of the given K and output the result of each adding.

void AddLeftDigit(int d, int *k)
{

    int h = *k;
    int n = 1;
    while (h >= 1)
    {

        h = h / 10;
        n *= 10;
    }
    *k = d * n + *k;
}
void Solve(void)
{
    Task("ZFunc30");
    int k;
    GetN(&k);
    for (int i = 0; i < 2; ++i)
    {
        int d;
        GetN(&d);
        AddLeftDigit(d, &k);
        PutN(k);
    }
}
