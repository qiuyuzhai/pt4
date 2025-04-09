#include "pt4.h"
#include <cstdlib>
using namespace std;
int DigitSum(int num)
{
	int a=0,sum=0;
	if (num!=0)
	{
		a=num % 10;
		num=num / 10;
		sum=a+ DigitSum(num);
	}
	return sum;
}
void Solve()
{
    Task("String22");
    string m;
    pt>>m;
    int n=atof(m.c_str());
    pt<<(DigitSum(n));
}

