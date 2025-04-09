
int IsSquare(int k)
{
 int n = 1;
 while (n * n < k)
 ++n;
 return n * n == k;
}
void Solve(void)
{

 int n = 0;
 for (int i = 1; i <= 10; ++i)
 {
    int k;
    GetN(&k);
    if (IsSquare(k))
 ++n;
 }
    PutN(n);
}